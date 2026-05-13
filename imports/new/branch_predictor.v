`include "defines.v"  // 引入全局宏定义，例如 INST_TYPE_B、INST_JAL、INST_JALR 等 opcode 定义。

// ============================================================================
// branch_predictor
// ----------------------------------------------------------------------------
// 这是 CPU 前端使用的分支预测器模块。
// 主要包含三部分：
// 1. BHT：Branch History Table，用 2-bit 饱和计数器预测条件分支是否 taken。
// 2. GHR：Global History Register，用全局历史和 PC 异或得到索引，降低简单 PC 索引冲突。
// 3. RAS：Return Address Stack，用于预测 ret 类 JALR 的返回地址。
//
// 支持的预测对象：
// - 条件分支 B-type：根据 BHT 或 BTFNT 静态策略预测 taken/not taken。
// - JAL：默认预测 taken，目标为 PC + J-type immediate。
// - JALR return：如果识别成 return 且 RAS 非空，则预测 taken，目标为 RAS 栈顶。
// ============================================================================
module branch_predictor #(
    parameter BHT_ADDR_WIDTH = 9,      // BHT 索引位宽；9 位表示 512 个索引。
    parameter BHT_SIZE = 512,          // BHT 表项数量；通常应等于 2^BHT_ADDR_WIDTH。
    parameter RAS_DEPTH = 32,          // RAS 返回地址栈深度。
    parameter RAS_PTR_WIDTH = 5        // RAS 指针位宽；5 位刚好能索引 32 项。
)(
    input  wire        clk,            // 时钟信号，驱动 BHT/GHR/RAS 等时序状态。
    input  wire        rst,            // 低有效复位；rst == 0 时初始化预测器。

    input  wire        if_valid_i,     // IF 阶段当前输入指令是否有效。
    input  wire [31:0] if_inst_i,      // IF 阶段当前指令，用于判断是否 branch/jal/jalr。
    input  wire [31:0] if_pc_i,        // IF 阶段当前指令 PC，用于生成索引和目标地址。
    input  wire        hold_flag_i,    // 流水线 hold 标志；hold 时不应推进新的预测 flush。
    input  wire        flush_flag_i,   // 外部 flush 标志；redirect 或前端冲刷时清理预测输出状态。

    output reg         pred_taken_o,   // 预测结果：1 表示预测跳转，0 表示预测不跳转。
    output reg  [31:0] pred_target_o,  // 预测目标地址；只有 pred_taken_o 为 1 时有意义。
    output wire [BHT_ADDR_WIDTH-1:0] pred_ghr_o, // 输出当前 GHR 快照，随指令向后传，供 EX 更新预测器。
    output reg         pred_flush_o,   // 预测跳转后给前端的 flush 提示；当前顶层可能没有直接使用。

    input  wire        update_en_i,    // EX 阶段反馈：是否需要更新 BHT/GHR/RAS。
    input  wire [31:0] update_pc_i,    // EX 阶段反馈：被更新的分支指令 PC。
    input  wire [BHT_ADDR_WIDTH-1:0] update_ghr_i, // EX 阶段反馈：该分支预测时保存的 GHR 快照。
    input  wire        ras_push_en_i,  // EX 阶段反馈：是否向 RAS 压入返回地址，通常来自 call 指令。
    input  wire        ras_pop_en_i,   // EX 阶段反馈：是否从 RAS 弹出返回地址，通常来自 ret 指令。
    input  wire [31:0] ras_push_addr_i,// EX 阶段反馈：需要压入 RAS 的返回地址。
    input  wire        actual_taken_i  // EX 阶段反馈：该分支真实是否 taken。
);

    // ------------------------------------------------------------------------
    // 2-bit 饱和计数器状态定义。
    // 高位 bht[x][1] 通常作为预测 taken/not-taken 的判断位。
    // 00/01 预测 not taken，10/11 预测 taken。
    // ------------------------------------------------------------------------
    localparam [1:0] STRONGLY_NOT_TAKEN = 2'b00; // 强不跳转。
    localparam [1:0] WEAKLY_NOT_TAKEN   = 2'b01; // 弱不跳转。
    localparam [1:0] WEAKLY_TAKEN       = 2'b10; // 弱跳转。
    localparam [1:0] STRONGLY_TAKEN     = 2'b11; // 强跳转。

    localparam [RAS_PTR_WIDTH-1:0] RAS_LAST_PTR = RAS_DEPTH - 1; // RAS 最后一项索引，用于栈指针回绕。
    localparam [RAS_PTR_WIDTH:0]   RAS_DEPTH_COUNT = RAS_DEPTH;  // RAS 满计数值；比指针多 1 位，用于表示 32。

    // ------------------------------------------------------------------------
    // 预测器内部状态寄存器。
    // ------------------------------------------------------------------------
    reg [1:0] bht [0:BHT_SIZE-1];                 // BHT 表，每项是一个 2-bit 饱和计数器。
    reg       bht_valid [0:BHT_SIZE-1];           // BHT 有效位；无效时使用静态预测策略。
    reg [BHT_ADDR_WIDTH-1:0] ghr_r;               // 全局历史寄存器，记录最近若干次分支 taken 情况。
    reg [31:0] ras [0:RAS_DEPTH-1];               // Return Address Stack，保存函数返回地址。
    reg [RAS_PTR_WIDTH-1:0] ras_sp_r;             // RAS 栈指针，指向下一次 push 的位置。
    reg [RAS_PTR_WIDTH:0] ras_count_r;            // RAS 当前有效元素个数，用于判断空/满。
    reg [RAS_PTR_WIDTH-1:0] ras_sp_next_r;        // RAS 下一状态栈指针，组合式临时变量。
    reg [RAS_PTR_WIDTH:0] ras_count_next_r;       // RAS 下一状态计数，组合式临时变量。

    // ------------------------------------------------------------------------
    // 从当前 IF 指令中拆 opcode/funct3/rd/rs1。
    // ------------------------------------------------------------------------
    wire [6:0] opcode = if_inst_i[6:0];           // RISC-V opcode 字段。
    wire [6:0] funct3  = if_inst_i[14:12];        // 注意：这里声明成 [6:0] 但只取 3 bit，会零扩展；更规范应写 wire [2:0] funct3。
    wire [4:0] rd     = if_inst_i[11:7];          // rd 字段。
    wire [4:0] rs1    = if_inst_i[19:15];         // rs1 字段。

    // ------------------------------------------------------------------------
    // BHT 索引生成。
    // RISC-V 指令按 4 字节对齐，所以 PC[1:0] 恒为 0，索引从 bit2 开始取。
    // pred_pc_idx/update_pc_idx 是纯 PC 索引；pred_idx/update_idx 再与 GHR 异或。
    // ------------------------------------------------------------------------
    wire [BHT_ADDR_WIDTH-1:0] pred_pc_idx   = if_pc_i[BHT_ADDR_WIDTH+1:2];     // 当前 IF PC 的索引。
    wire [BHT_ADDR_WIDTH-1:0] update_pc_idx = update_pc_i[BHT_ADDR_WIDTH+1:2]; // 更新分支 PC 的索引。
    wire [BHT_ADDR_WIDTH-1:0] pred_idx      = pred_pc_idx ^ ghr_r;             // 预测用索引：PC index XOR 当前 GHR。
    wire [BHT_ADDR_WIDTH-1:0] update_idx    = update_pc_idx ^ ghr_r;           // 更新用索引：注意这里用的是当前 ghr_r。
    // 注意：如果 EX 级反馈了 update_ghr_i，更严格的 gshare 更新通常应使用：update_pc_idx ^ update_ghr_i。
    // 否则当预测和更新之间 GHR 已经变化时，可能更新到和当初预测不同的 BHT 项。

    // ------------------------------------------------------------------------
    // B-type 立即数拼接。
    // B 指令立即数格式：imm[12|10:5|4:1|11] << 1。
    // 这里拼出来的是已带最低 0 bit 的 32 位符号扩展偏移。
    // ------------------------------------------------------------------------
    wire [31:0] b_imm =
        {{20{if_inst_i[31]}}, if_inst_i[7], if_inst_i[30:25], if_inst_i[11:8], 1'b0};

    // ------------------------------------------------------------------------
    // J-type 立即数拼接。
    // JAL 立即数格式：imm[20|10:1|11|19:12] << 1。
    // ------------------------------------------------------------------------
    wire [31:0] j_imm =
        {{12{if_inst_i[31]}}, if_inst_i[19:12], if_inst_i[20], if_inst_i[30:21], 1'b0};

    wire        btfnt_taken = b_imm[31];          // BTFNT 静态预测：Backward Taken, Forward Not Taken；负偏移认为是回跳循环，预测 taken。

    // ------------------------------------------------------------------------
    // RAS 相关判断。
    // RISC-V 约定 x1 是 ra，x5 也可作为 alternate link register。
    // rd 是 link 寄存器通常意味着 call；rs1 是 link 寄存器的 JALR 通常可能是 return。
    // ------------------------------------------------------------------------
    wire        rd_is_link = (rd == 5'b1) || (rd == 5'b101);   // rd 是否为 x1 或 x5。
    wire        rs1_is_link = (rs1 == 5'b1) || (rs1 == 5'b101); // rs1 是否为 x1 或 x5。

    wire        ras_nonempty = (ras_count_r != {RAS_PTR_WIDTH+1{1'b0}}); // RAS 是否非空。

    wire [RAS_PTR_WIDTH-1:0] ras_top_idx =
        (ras_sp_r == {RAS_PTR_WIDTH{1'b0}}) ? RAS_LAST_PTR : (ras_sp_r - 1'b1); // 栈顶地址 = sp - 1；sp 为 0 时回绕到最后一项。

    wire        is_jalr_hint = (opcode == `INST_JALR) && (funct3 == 3'b000); // 判断是否是合法 JALR 形式。

    wire        ras_pred_pop = is_jalr_hint && rs1_is_link && (!rd_is_link || (rd != rs1));
    // 判断当前 JALR 是否像 return：
    // - opcode 是 JALR；
    // - rs1 是 link 寄存器；
    // - rd 不是 link，或者 rd 和 rs1 不是同一个 link。
    // 这个条件用于避免把某些 coroutine/call-like JALR 误判为普通 return。

    wire        ras_pred_valid = ras_pred_pop && ras_nonempty; // 只有像 return 且 RAS 非空，才可以用 RAS 预测目标。

    integer i; // for 循环变量，用于复位时初始化 BHT。

    assign pred_ghr_o = ghr_r; // 把当前 GHR 输出给顶层，让预测信息随指令流向后级。

    // ========================================================================
    // 时序逻辑：负责更新 BHT、GHR、RAS 和 pred_flush_o。
    // ========================================================================
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            // ----------------------------------------------------------------
            // 低有效复位：初始化 BHT、valid、GHR、RAS 指针和预测 flush。
            // ----------------------------------------------------------------
            for (i = 0; i < BHT_SIZE; i = i + 1) begin
                bht[i] <= WEAKLY_NOT_TAKEN; // BHT 初始为弱不跳转，避免一开始过度预测 taken。
                bht_valid[i] <= 1'b0;       // 初始所有表项无效；第一次遇到该 index 时用静态 BTFNT。
            end
            ghr_r <= {BHT_ADDR_WIDTH{1'b0}};       // 清空全局历史。
            ras_sp_r <= {RAS_PTR_WIDTH{1'b0}};     // RAS 栈指针清零。
            ras_count_r <= {RAS_PTR_WIDTH+1{1'b0}};// RAS 有效项数清零。
            pred_flush_o <= 1'b0;                  // 清除预测 flush 输出。
        end else begin
            // ----------------------------------------------------------------
            // BHT/GHR 更新逻辑。
            // update_en_i 通常来自 EX 级：当一条分支真实结果出来后更新预测器。
            // ----------------------------------------------------------------
            if (update_en_i) begin
                bht_valid[update_idx] <= 1'b1; // 该 BHT 项被训练过，之后可优先用动态预测。

                case (bht[update_idx])
                    STRONGLY_NOT_TAKEN: bht[update_idx] <= actual_taken_i ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                    // 原状态 00：
                    // - 实际 taken，则向 taken 方向移动到 01。
                    // - 实际 not taken，则保持 00。

                    WEAKLY_NOT_TAKEN:   bht[update_idx] <= actual_taken_i ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
                    // 原状态 01：
                    // - 实际 taken，则变 10，预测方向翻到 taken。
                    // - 实际 not taken，则变 00。

                    WEAKLY_TAKEN:       bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
                    // 原状态 10：
                    // - 实际 taken，则变 11。
                    // - 实际 not taken，则变 01，预测方向翻到 not taken。

                    default:            bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
                    // default 对应 11 或异常状态：
                    // - 实际 taken，则保持/变为 11。
                    // - 实际 not taken，则向 not taken 方向移动到 10。
                endcase

                ghr_r <= {ghr_r[BHT_ADDR_WIDTH-2:0], actual_taken_i};
                // 更新 GHR：左移一位，把本次真实 taken 结果放到最低位。
                // 例如 BHT_ADDR_WIDTH=9 时，保留最近 9 次分支结果。
            end

            // ----------------------------------------------------------------
            // RAS 更新逻辑。
            // 这里允许一拍内同时 pop 和 push：先 pop，再 push。
            // 常见于一些 JALR coroutine 形式。
            // ----------------------------------------------------------------
            if (ras_pop_en_i || ras_push_en_i) begin
                ras_sp_next_r = ras_sp_r;       // 默认下一状态 sp 等于当前 sp。
                ras_count_next_r = ras_count_r; // 默认下一状态 count 等于当前 count。

                if (ras_pop_en_i && ras_nonempty) begin
                    ras_sp_next_r = ras_top_idx;              // pop：sp 回到当前栈顶位置。
                    ras_count_next_r = ras_count_r - 1'b1;    // 有效元素个数减一。
                end

                if (ras_push_en_i) begin
                    ras[ras_sp_next_r] <= ras_push_addr_i;    // push：把返回地址写入当前 sp 指向的位置。
                    ras_sp_next_r = ras_sp_next_r + 1'b1;     // sp 指向下一次 push 位置；位宽会自然回绕。
                    if (ras_count_next_r != RAS_DEPTH_COUNT) begin
                        ras_count_next_r = ras_count_next_r + 1'b1; // 未满时 count 加一。
                    end
                    // 如果已经满了，继续 push 会覆盖最老/某个位置，但 count 保持满值。
                end

                ras_sp_r <= ras_sp_next_r;             // 提交 RAS 栈指针下一状态。
                ras_count_r <= ras_count_next_r;       // 提交 RAS 有效计数下一状态。
            end

            // ----------------------------------------------------------------
            // pred_flush_o 产生逻辑。
            // 如果本拍预测 taken 且 IF 有效，并且没有 hold，则下一拍需要通知前端清掉顺序路径指令。
            // ----------------------------------------------------------------
            if (flush_flag_i) begin
                pred_flush_o <= 1'b0; // 外部已经 flush 时，清除本模块输出的 pred_flush。
            end else begin
                pred_flush_o <= if_valid_i && pred_taken_o && (hold_flag_i == 1'b0);
                // 注意 pred_taken_o 来自下面的组合 always @(*)。
                // 这表示“当前 IF 指令预测 taken，并且前端没有 hold”。
            end
        end
    end

    // ========================================================================
    // 组合逻辑：根据当前 IF 指令给出预测结果和预测目标。
    // ========================================================================
    always @(*) begin
        pred_taken_o  = 1'b0;  // 默认不预测跳转。
        pred_target_o = 32'b0; // 默认目标地址为 0；只有 taken 时有意义。

        if (if_valid_i) begin
            case (opcode)
                `INST_TYPE_B: begin
                    // --------------------------------------------------------
                    // 条件分支预测。
                    // 如果 BHT 表项有效，则使用 2-bit 计数器高位 bht[pred_idx][1]。
                    // 如果 BHT 表项无效，则使用 BTFNT 静态策略：负偏移预测 taken。
                    // --------------------------------------------------------
                    if (bht_valid[pred_idx] ? bht[pred_idx][1] : btfnt_taken) begin
                        pred_taken_o  = 1'b1;          // 预测条件分支 taken。
                        pred_target_o = if_pc_i + b_imm; // 目标地址 = 当前 PC + B-type offset。
                    end
                end

                `INST_JAL: begin
                    // --------------------------------------------------------
                    // JAL 是无条件直接跳转，所以默认预测 taken。
                    // --------------------------------------------------------
                    pred_taken_o  = 1'b1;              // JAL 必跳。
                    pred_target_o = if_pc_i + j_imm;   // JAL 目标 = PC + J-type offset。
                end

                `INST_JALR: begin
                    // --------------------------------------------------------
                    // JALR 是间接跳转，目标通常需要 rs1 + imm。
                    // IF 阶段没有寄存器值，所以普通 JALR 不能直接算目标。
                    // 只有当它看起来像 return，并且 RAS 非空时，才用 RAS 栈顶预测。
                    // --------------------------------------------------------
                    if (ras_pred_valid) begin
                        pred_taken_o  = 1'b1;          // 预测 return taken。
                        pred_target_o = ras[ras_top_idx]; // 目标取 RAS 栈顶保存的返回地址。
                    end
                end

                default: begin
                    // --------------------------------------------------------
                    // 其他普通指令默认不跳转。
                    // --------------------------------------------------------
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                end
            endcase
        end
    end

endmodule  // branch_predictor
