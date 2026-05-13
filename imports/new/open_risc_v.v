`include "defines.v"  // 引入全局宏定义：opcode、func3、指令类型、NOP 等常量通常都在这里定义。

// ============================================================================
// open_risc_v
// ----------------------------------------------------------------------------
// 这是 RISC-V CPU Core 的顶层模块。
// 它负责把 IF、ID、EX、MEM1、MEM2、WB 等流水级连接起来，
// 同时连接分支预测器、冒险检测单元、前递单元和外部 ROM/RAM 接口。
// ============================================================================
module open_risc_v (
    input  wire        clk,                // 全局时钟，上升沿驱动所有流水线寄存器。
    input  wire        rst_n,              // 低有效复位；注意后面 wire rst = rst_n，所以 rst==0 表示复位。
    input  wire [31:0] inst_i,             // 外部指令 ROM 返回的 32 位指令，一般对应当前取指 PC。
    input  wire [31:0] ram_data_i,         // 外部数据 RAM 返回的 32 位读数据，用于 load 指令。
    output wire [31:0] pc_reg_pc_o,        // 输出给外部指令 ROM 的取指地址 PC。
    output wire        mem_rd_reg_o,       // 输出给外部数据 RAM 的读使能，高电平表示本拍发起 load 读。
    output wire [31:0] mem_rd_addr_o,      // 输出给外部数据 RAM 的 load 读地址。
    output wire [3:0]  w_en,               // 输出给外部数据 RAM 的写字节使能；4 bit 分别对应 4 个 byte。
    output wire [31:0] w_addr_i,           // 输出给外部数据 RAM 的 store 写地址。
    output wire [31:0] w_data_i            // 输出给外部数据 RAM 的 store 写数据。
);

    // =================================================================
    // 0. 全局控制信号
    // =================================================================

    wire rst = rst_n;                      // 统一命名；这里没有取反，所以 rst 仍然是“低有效复位”。

    // -----------------------------------------------------------------
    // CTRL 输出：来自中央控制器，用于处理 EX 级发现的跳转/冲刷/kill。
    // -----------------------------------------------------------------

    wire [31:0] ctrl_jump_addr_o;          // CTRL 输出给 PC 的最终跳转目标地址。
    wire        ctrl_jump_en_o;            // CTRL 输出给 PC 的跳转使能；有效时 PC 改为 ctrl_jump_addr_o。
    wire        ctrl_kill_ex_o;            // CTRL 输出给 EX 的 kill 信号；用于杀掉同步 ROM redirect 后的幽灵指令。

    wire        ctrl_flush_ifid_o;         // CTRL 输出给 IF/ID 的冲刷信号；一般用于清掉错误路径指令。
    wire        ctrl_flush_idex_o;         // CTRL 输出给 ID/EX 的冲刷信号；一般用于清掉已进入执行前的错误指令。

    // -----------------------------------------------------------------
    // 分支预测相关线网。
    // -----------------------------------------------------------------

    wire        bp_pred_taken_o;           // 分支预测器原始预测结果：当前 IF 指令是否预测跳转。
    wire        bp_pred_taken_accepted_o;  // 顶层过滤后的预测采纳信号；只有前端有效且非 hold/flush 时才采纳。
    wire [31:0] bp_pred_target_o;          // 分支预测器给出的预测目标地址。
    wire [8:0]  bp_pred_ghr_o;             // 分支预测时对应的全局历史寄存器 GHR 快照，用于后续 EX 更新。
    wire        bp_pred_flush_o;           // 分支预测器内部输出的 flush 提示；当前顶层没有直接使用这个信号。
    reg         bp_pred_flush_d1_r;        // 预测跳转被采纳后的延迟 1 拍标记，用于处理同步 IROM 的 ghost 指令。
    wire [31:0] pc_jump_addr_o;            // 最终送给 PC 寄存器的跳转目标地址，来自 CTRL 或 BP。
    wire        pc_jump_en_o;              // 最终送给 PC 寄存器的跳转使能，来自 CTRL 或 BP。
    reg  [31:0] bp_fetch_pc_r;             // 与 inst_i 对齐的取指 PC；因为同步 ROM 返回指令通常晚一拍。
    reg         bp_fetch_valid_r;          // 当前 inst_i/bp_fetch_pc_r 是否有效。
    reg         bp_fetch_valid_pending_r;  // 取指有效的 pending 标志；复位后第一拍通常无有效指令。

    // -----------------------------------------------------------------
    // HDU 输出：冒险检测单元控制流水线停顿/插泡。
    // -----------------------------------------------------------------

    wire        hdu_hold_flag_o;           // HDU 冻结信号；用于冻结 PC 和 IF/ID，常见于 load-use 或多周期 EX busy。
    wire        hdu_flush_flag_o;          // HDU 冲刷信号；用于把 ID/EX 清成 NOP，相当于插入一个 bubble。

    // =================================================================
    // 1. IF -> ID 级间线网
    // =================================================================

    wire [31:0] if_id_inst_addr_o;         // IF/ID 输出的指令地址，也就是当前 ID 级指令的 PC。
    wire [31:0] if_id_inst_o;              // IF/ID 输出的指令，也就是送入 ID 译码的指令。
    wire        if_id_pred_taken_o;        // IF/ID 保存的“这条指令取指时是否预测跳转”。
    wire [31:0] if_id_pred_target_o;       // IF/ID 保存的预测目标地址，后续 EX 校验预测是否正确。
    wire [8:0]  if_id_pred_ghr_o;          // IF/ID 保存的 GHR 快照，后续用于更新预测器。
    wire        if_id_replaying_o;         // IF/ID skid buffer 正在 replay 的标记；避免 replay 指令再次触发预测采纳。

    // =================================================================
    // 2. ID 级输出线网
    // =================================================================

    wire [4:0]  id_rs1_addr_o;             // ID 解析出的 rs1 地址，送寄存器堆读端口 1。
    wire [4:0]  id_rs2_addr_o;             // ID 解析出的 rs2 地址，送寄存器堆读端口 2。
    wire [31:0] id_inst_o;                 // ID 透传出的原始指令，送 ID/EX。
    wire [31:0] id_inst_addr_o;            // ID 透传出的指令 PC，送 ID/EX。
    wire [31:0] id_op1_o;                  // ID 产生的操作数 1，可能来自 rs1、PC 或 0。
    wire [31:0] id_op2_o;                  // ID 产生的操作数 2，可能来自 rs2 或立即数。
    wire [4:0]  id_rd_addr_o;              // ID 解析出的 rd 目的寄存器地址。
    wire        id_reg_wen;                // ID 解析出的寄存器写使能，表示该指令后续是否写 rd。
    wire [31:0] id_base_addr_o;            // ID 产生的地址基址，常用于 load/store/jalr。
    wire [31:0] id_addr_offset_o;          // ID 产生的地址偏移量，通常是立即数扩展结果。
    wire        data_read_en;              // ID 阶段解析出的 load 读使能；这里主要是译码结果，外部 RAM 实际读使能在后面用 EX/MEM 信号。

    // =================================================================
    // 3. 寄存器堆读出数据，以及 WB 写回数据
    // =================================================================

    wire [31:0] regs_reg1_rdata_o;         // 寄存器堆读端口 1 数据，对应 rs1。
    wire [31:0] regs_reg2_rdata_o;         // 寄存器堆读端口 2 数据，对应 rs2。

    wire [4:0]  wb_rd_addr_o;              // WB 阶段最终写回的寄存器地址。
    wire [31:0] wb_rd_data_o;              // WB 阶段最终写回的寄存器数据。
    wire        wb_rd_wen_o;               // WB 阶段最终写回使能。

    // =================================================================
    // 4. ID/EX 级间线网
    // =================================================================

    wire [31:0] id_ex_inst_o;              // ID/EX 输出的指令，进入 EX 执行。
    wire [31:0] id_ex_inst_addr_o;         // ID/EX 输出的 PC，供分支/JAL/JALR 判断和预测器更新。
    wire [31:0] id_ex_op1_o;               // ID/EX 输出的操作数 1，之后还会经过 forwarding 修正。
    wire [31:0] id_ex_op2_o;               // ID/EX 输出的操作数 2，之后还会经过 forwarding 修正。
    wire        id_ex_pred_taken_o;        // ID/EX 保存的预测 taken 信息。
    wire [31:0] id_ex_pred_target_o;       // ID/EX 保存的预测目标地址。
    wire [8:0]  id_ex_pred_ghr_o;          // ID/EX 保存的 GHR 快照。
    wire [4:0]  id_ex_rd_addr_o;           // ID/EX 输出的目的寄存器地址。
    wire        id_ex_reg_wen;             // ID/EX 输出的寄存器写使能。
    wire [31:0] id_ex_base_addr_o;         // ID/EX 输出的访存/跳转基地址。
    wire [31:0] id_ex_addr_offset_o;       // ID/EX 输出的地址偏移。

    // =================================================================
    // 5. EX 级输出线网
    // =================================================================

    wire [4:0]  ex_rd_addr_o;              // EX 计算后透传/输出的目的寄存器地址。
    wire [31:0] ex_rd_data_o;              // EX 计算出的 ALU 结果，或者后续写回候选数据。
    wire        ex_rd_wen_o;               // EX 输出的写回使能。
    wire [3:0]  ex_wd_reg_o;               // EX 计算出的 store 写字节掩码。
    wire [31:0] ex_wd_addr_o;              // EX 计算出的 store 写地址。
    wire [31:0] ex_wd_data_o;              // EX 准备写入 RAM 的 store 数据。
    wire        ex_is_load_o;              // EX 判断当前指令是否为 load，用于后级控制。
    wire [31:0] ex_inst_o;                 // EX 透传出的指令。
    wire [31:0] ex_jump_addr_o;            // EX 实际计算出的跳转/重定向地址。
    wire        ex_jump_en_o;              // EX 判断出的实际跳转/纠错使能；送 CTRL 做重定向控制。
    wire [31:0] ex_rd_mem_addr_o;          // EX 计算出的 load 读地址。

    wire        bp_update_en_o;            // EX 输出给分支预测器的更新使能。
    wire [31:0] bp_update_pc_o;            // EX 输出给分支预测器的被更新指令 PC。
    wire [8:0]  bp_update_ghr_o;           // EX 输出给分支预测器的预测时 GHR 快照。
    wire        bp_ras_push_en_o;          // EX 输出给 RAS 的 push 使能，用于 call 类指令。
    wire        bp_ras_pop_en_o;           // EX 输出给 RAS 的 pop 使能，用于 return 类指令。
    wire [31:0] bp_ras_push_addr_o;        // EX 输出给 RAS 的返回地址。
    wire        bp_actual_taken_o;         // EX 计算出的真实 taken 结果，用于训练预测器。
    wire        ex_rv32m_busy_o;           // EX 中 RV32M 多周期单元忙标志；忙时 HDU 应保持流水线。
    wire        ex_rv32m_done_o;           // EX 中 RV32M 多周期单元完成标志；当前顶层只连接未继续使用。

    // =================================================================
    // 5b. 前递单元输出线网
    // =================================================================

    wire [31:0] fwd_op1_o;                 // 前递修正后的操作数 1。
    wire [31:0] fwd_op2_o;                 // 前递修正后的操作数 2。
    wire [31:0] fwd_base_addr_o;           // 前递修正后的访存基地址，避免 store/load/jalr 使用旧 rs1。
    wire [31:0] fwd_addr_offset_o;         // 地址偏移一般不需要前递，通常直接透传。

    // =================================================================
    // 6. EX/MEM1 级间线网
    // =================================================================

    wire [4:0]  ex_mem_pipe_rd_addr_o;     // EX/MEM1 寄存后的写回地址。
    wire [31:0] ex_mem_rd_data_o;          // EX/MEM1 寄存后的 ALU 结果。
    wire        ex_mem_rd_wen_o;           // EX/MEM1 寄存后的写回使能。
    wire [3:0]  ex_mem_wd_reg_o;           // EX/MEM1 寄存后的 store 写掩码。
    wire [31:0] ex_mem_wd_addr_o;          // EX/MEM1 寄存后的 store 写地址。
    wire [31:0] ex_mem_wd_data_o;          // EX/MEM1 寄存后的 store 写数据。
    wire        ex_mem_is_load_o;          // EX/MEM1 寄存后的 load 标记。
    wire [31:0] ex_mem_inst_o;             // EX/MEM1 寄存后的指令。
    wire [31:0] ex_mem_mem_rd_addr_o;      // EX/MEM1 寄存后的 load 读地址。

    // =================================================================
    // 7. MEM1 级输出线网
    // =================================================================

    wire [4:0]  mem_out_rd_addr_o;         // MEM1 输出的写回地址。
    wire [31:0] mem_out_rd_data_o;         // MEM1 输出的 ALU 结果/透传数据。
    wire        mem_out_rd_wen_o;          // MEM1 输出的写回使能。
    wire [31:0] mem_inst_o;                // MEM1 输出的指令。
    wire [31:0] mem_out_mem_rd_addr_o;     // MEM1 输出的 load 读地址。
    wire        mem_out_is_load_o;         // MEM1 输出的 load 标记。

    // =================================================================
    // 8. MEM1/MEM2 级间线网
    // =================================================================

    wire [4:0]  mem1_mem2_rd_addr_o;       // MEM1/MEM2 寄存后的写回地址。
    wire [31:0] mem1_mem2_rd_data_o;       // MEM1/MEM2 寄存后的 ALU 结果/透传数据。
    wire        mem1_mem2_rd_wen_o;        // MEM1/MEM2 寄存后的写回使能。
    wire [31:0] mem1_mem2_inst_o;          // MEM1/MEM2 寄存后的指令。
    wire [31:0] mem1_mem2_mem_rd_addr_o;   // MEM1/MEM2 寄存后的 load 地址。
    wire        mem1_mem2_is_load_o;       // MEM1/MEM2 寄存后的 load 标记。

    // =================================================================
    // 8b. MEM2 对齐级线网：比传统 MEM1/MEM2 后面又多打一拍
    // =================================================================

    wire [4:0]  mem2_align_rd_addr_o;      // 额外对齐级后的写回地址。
    wire [31:0] mem2_align_rd_data_o;      // 额外对齐级后的 ALU 结果/透传数据。
    wire        mem2_align_rd_wen_o;       // 额外对齐级后的写回使能。
    wire [31:0] mem2_align_inst_o;         // 额外对齐级后的指令。
    wire [31:0] mem2_align_mem_rd_addr_o;  // 额外对齐级后的 load 地址，用于 MEM2 做 LB/LH/LW 对齐。
    wire        mem2_align_is_load_o;      // 额外对齐级后的 load 标记。

    // =================================================================
    // 9. MEM2 级输出线网
    // =================================================================

    wire [31:0] mem2_inst_o;               // MEM2 输出的指令。
    wire [4:0]  mem2_rd_addr_o;            // MEM2 输出的写回地址。
    wire [31:0] mem2_rd_data_o;            // MEM2 输出的写回数据；load 会在这里完成字节/半字对齐与符号扩展。
    wire        mem2_rd_wen_o;             // MEM2 输出的写回使能。

    // =================================================================
    // 10. MEM2/WB 级间线网
    // =================================================================

    wire [4:0]  mem_wb_rd_addr_o;          // MEM2/WB 寄存后的写回地址。
    wire [31:0] mem_wb_rd_data_o;          // MEM2/WB 寄存后的写回数据。
    wire        mem_wb_rd_wen_o;           // MEM2/WB 寄存后的写回使能。
    wire [31:0] mem_wb_inst_o;             // MEM2/WB 寄存后的指令。

    // =================================================================
    // 顶层外部 RAM 接口连线
    // =================================================================

    assign mem_rd_reg_o   = ex_mem_is_load_o;       // 外部 RAM 读使能：EX 之后寄存到 EX/MEM1 的 load 标记。
    assign mem_rd_addr_o  = ex_mem_mem_rd_addr_o;   // 外部 RAM 读地址：EX 计算出的 load 地址打一拍后发给 RAM。

    wire bp_if_valid = bp_fetch_valid_r & ~bp_pred_flush_d1_r;  // 预测器当前输入是否有效；若上一拍刚采纳预测，则本拍同步 ROM ghost 无效。

    assign bp_pred_taken_accepted_o = bp_pred_taken_o           // 预测器认为 taken，才可能采纳。
                                    & bp_if_valid               // 当前 IF 指令必须有效。
                                    & ~hdu_hold_flag_o          // 流水线被 HDU hold 时不采纳新预测，避免重复跳。
                                    & ~ctrl_flush_ifid_o        // 当前正在被 CTRL flush 时不采纳预测。
                                    & ~if_id_replaying_o;       // IF/ID 正在 replay 旧指令时不采纳预测。

    assign pc_jump_en_o   = ctrl_jump_en_o | bp_pred_taken_accepted_o;  // PC 跳转来源有两个：EX/CTRL 纠错跳转，或 IF 阶段预测跳转。
    assign pc_jump_addr_o = ctrl_jump_en_o ? ctrl_jump_addr_o           // CTRL 跳转优先级更高，因为它代表实际执行结果纠错。
                                           : bp_pred_target_o;          // 没有 CTRL 跳转时，采用预测器目标地址。

    // -----------------------------------------------------------------
    // 取指有效位与预测 flush 延迟寄存器。
    // 作用：同步 ROM 通常取地址后一拍才返回 inst_i，所以需要保存与 inst_i 对齐的 PC。
    // -----------------------------------------------------------------
    always @(posedge clk) begin
        if (rst == 1'b0) begin                         // 低有效复位进入初始化状态。
            bp_fetch_pc_r            <= 32'h8000_0000; // 复位后默认取指 PC 初始化到程序入口。
            bp_fetch_valid_r         <= 1'b0;          // 复位刚结束时，ROM 返回的指令还不可认为有效。
            bp_fetch_valid_pending_r <= 1'b0;          // pending 也先清零。
            bp_pred_flush_d1_r       <= 1'b0;          // 没有待处理的预测 ghost flush。
        end else begin
            bp_fetch_pc_r            <= pc_reg_pc_o;             // 保存本拍送给 ROM 的 PC，下拍与 inst_i 对齐。
            bp_fetch_valid_r         <= bp_fetch_valid_pending_r; // pending 推进为真正 valid。
            bp_fetch_valid_pending_r <= 1'b1;                    // 复位结束后，后续取指默认有效。
            bp_pred_flush_d1_r       <= bp_pred_taken_accepted_o; // 预测跳转采纳后一拍，用于屏蔽同步 ROM 旧输出。
        end
    end

    // *************************************************************************************************
    // 模块例化：下面把各个流水级、预测器、控制器、前递和冒险检测单元接起来。
    // *************************************************************************************************

    // -----------------------------------------------------------------
    // 1. 分支预测器
    // -----------------------------------------------------------------
    branch_predictor branch_predictor_inst (
        .clk             (clk),                         // 时钟。
        .rst             (rst),                         // 低有效复位，传给预测器内部表项/RAS/GHR。
        .if_valid_i      (bp_if_valid),                 // 当前 IF 输入是否有效。
        .if_inst_i       (inst_i),                      // 当前 IF 指令，用于判断是否 branch/jal/jalr/ret。
        .if_pc_i         (bp_fetch_pc_r),               // 与 inst_i 对齐的 PC。
        .hold_flag_i     (hdu_hold_flag_o),             // hold 时预测器不要推进错误状态。
        .flush_flag_i    (ex_jump_en_o | ctrl_flush_ifid_o | bp_pred_flush_d1_r), // redirect/flush/ghost 时清理预测输出状态。
        .pred_taken_o    (bp_pred_taken_o),             // 输出原始 taken 预测。
        .pred_target_o   (bp_pred_target_o),            // 输出预测跳转目标。
        .pred_ghr_o      (bp_pred_ghr_o),               // 输出预测时的 GHR 快照。
        .pred_flush_o    (bp_pred_flush_o),             // 预测器内部 flush 输出；本顶层没有使用。
        .update_en_i     (bp_update_en_o),              // EX 级反馈：是否更新预测器。
        .update_pc_i     (bp_update_pc_o),              // EX 级反馈：更新哪条指令的预测项。
        .update_ghr_i    (bp_update_ghr_o),             // EX 级反馈：该指令预测时的 GHR。
        .ras_push_en_i   (bp_ras_push_en_o),            // EX 级反馈：RAS push。
        .ras_pop_en_i    (bp_ras_pop_en_o),             // EX 级反馈：RAS pop。
        .ras_push_addr_i (bp_ras_push_addr_o),          // EX 级反馈：压入 RAS 的返回地址。
        .actual_taken_i  (bp_actual_taken_o)            // EX 级反馈：真实 taken 结果。
    );

    // -----------------------------------------------------------------
    // 2. PC 寄存器
    // -----------------------------------------------------------------
    pc_reg pc_reg_inst (
        .clk         (clk),              // 时钟。
        .rst         (rst),              // 低有效复位。
        .jump_en     (pc_jump_en_o),     // 来自 CTRL 或分支预测的最终跳转使能。
        .jump_addr_i (pc_jump_addr_o),   // 来自 CTRL 或分支预测的最终跳转地址。
        .hold_flag_i (hdu_hold_flag_o),  // HDU hold 时 PC 保持不变。
        .pc_o        (pc_reg_pc_o)       // 当前 PC 输出给外部 ROM，也回送给顶层保存。
    );

    // -----------------------------------------------------------------
    // 3. IF/ID 流水线寄存器 / skid buffer
    // -----------------------------------------------------------------
    if_id if_id_inst (
        .clk           (clk),                            // 时钟。
        .rst           (rst),                            // 低有效复位。
        .inst_i        (inst_i),                         // 从外部 ROM 进入的指令。
        .inst_addr_i   (bp_fetch_pc_r),                  // 与 inst_i 对齐的 PC。
        .pred_taken_i  (bp_pred_taken_accepted_o),       // 这条指令是否采纳了预测跳转。
        .pred_target_i (bp_pred_target_o),               // 这条指令对应的预测目标。
        .pred_ghr_i    (bp_pred_ghr_o),                  // 这条指令预测时的 GHR。
        .inst_addr_o   (if_id_inst_addr_o),              // 输出给 ID 的 PC。
        .pred_taken_o  (if_id_pred_taken_o),             // 输出给后级的预测 taken 标记。
        .pred_target_o (if_id_pred_target_o),            // 输出给后级的预测目标。
        .pred_ghr_o    (if_id_pred_ghr_o),               // 输出给后级的 GHR 快照。
        .inst_o        (if_id_inst_o),                   // 输出给 ID 的指令。
        .replaying_o   (if_id_replaying_o),              // 当前是否在 replay 缓冲指令。
        .hold_flag_i   (hdu_hold_flag_o),                // hold 时 IF/ID 保持或进入 skid replay。
        .flush_flag_i  (ctrl_flush_ifid_o | bp_pred_flush_d1_r) // 控制器 flush 或预测 ghost flush 时清空 IF/ID。
    );

    // -----------------------------------------------------------------
    // 4. 通用寄存器堆
    // -----------------------------------------------------------------
    regs regs_inst (
        .clk          (clk),                 // 时钟；写回通常在时钟边沿发生。
        .reg1_raddr_i (id_rs1_addr_o),       // 读端口 1 地址来自 ID 的 rs1。
        .reg2_raddr_i (id_rs2_addr_o),       // 读端口 2 地址来自 ID 的 rs2。
        .reg1_rdata_o (regs_reg1_rdata_o),   // 读端口 1 数据送回 ID。
        .reg2_rdata_o (regs_reg2_rdata_o),   // 读端口 2 数据送回 ID。
        .reg_wen      (wb_rd_wen_o),         // 写使能来自 WB 阶段。
        .reg_waddr_i  (wb_rd_addr_o),        // 写地址来自 WB 阶段。
        .reg_wdata_i  (wb_rd_data_o)         // 写数据来自 WB 阶段。
    );

    // -----------------------------------------------------------------
    // 5. ID 译码模块
    // -----------------------------------------------------------------
    id id_inst (
        .inst_i        (if_id_inst_o),        // 输入待译码指令。
        .inst_addr_i   (if_id_inst_addr_o),   // 输入待译码指令 PC。
        .rs1_data_i    (regs_reg1_rdata_o),   // rs1 从寄存器堆读出的原始数据。
        .rs2_data_i    (regs_reg2_rdata_o),   // rs2 从寄存器堆读出的原始数据。
        .rs1_addr_o    (id_rs1_addr_o),       // 输出 rs1 地址给寄存器堆。
        .rs2_addr_o    (id_rs2_addr_o),       // 输出 rs2 地址给寄存器堆。
        .inst_o        (id_inst_o),           // 透传指令给 ID/EX。
        .inst_addr_o   (id_inst_addr_o),      // 透传 PC 给 ID/EX。
        .op1_o         (id_op1_o),            // 产生操作数 1。
        .op2_o         (id_op2_o),            // 产生操作数 2。
        .rd_addr_o     (id_rd_addr_o),        // 输出 rd 地址。
        .reg_wen       (id_reg_wen),          // 输出寄存器写使能。
        .base_addr_o   (id_base_addr_o),      // 输出地址基址。
        .addr_offset_o (id_addr_offset_o),    // 输出地址偏移。
        .mem_rd_reg_o  (data_read_en)         // 输出 load 类型读使能译码结果。
    );

    // -----------------------------------------------------------------
    // 6. ID/EX 流水线寄存器
    // -----------------------------------------------------------------
    id_ex id_ex_inst (
        .clk           (clk),                                // 时钟。
        .rst           (rst),                                // 低有效复位。
        .hold_flag_i   (hdu_hold_flag_o),                    // hold 时 ID/EX 是否保持，取决于 id_ex 模块内部设计。
        .flush_flag_i  (hdu_flush_flag_o | ctrl_flush_idex_o),// load-use 插泡或控制流 flush 时清空 ID/EX。
        .inst_i        (id_inst_o),                          // ID 输出指令进入 ID/EX。
        .inst_addr_i   (id_inst_addr_o),                     // ID 输出 PC 进入 ID/EX。
        .op1_i         (id_op1_o),                           // ID 操作数 1 进入 ID/EX。
        .op2_i         (id_op2_o),                           // ID 操作数 2 进入 ID/EX。
        .pred_taken_i  (if_id_pred_taken_o),                 // 预测 taken 信息随指令向后传。
        .pred_target_i (if_id_pred_target_o),                // 预测目标随指令向后传。
        .pred_ghr_i    (if_id_pred_ghr_o),                   // GHR 快照随指令向后传。
        .rd_addr_i     (id_rd_addr_o),                       // rd 地址进入 ID/EX。
        .reg_wen_i     (id_reg_wen),                         // 写使能进入 ID/EX。
        .base_addr_i   (id_base_addr_o),                     // 地址基址进入 ID/EX。
        .addr_offset_i (id_addr_offset_o),                   // 地址偏移进入 ID/EX。
        .inst_o        (id_ex_inst_o),                       // 输出给 EX 的指令。
        .inst_addr_o   (id_ex_inst_addr_o),                  // 输出给 EX 的 PC。
        .op1_o         (id_ex_op1_o),                        // 输出给前递单元/EX 的操作数 1。
        .op2_o         (id_ex_op2_o),                        // 输出给前递单元/EX 的操作数 2。
        .pred_taken_o  (id_ex_pred_taken_o),                 // 输出给 EX 的预测 taken。
        .pred_target_o (id_ex_pred_target_o),                // 输出给 EX 的预测目标。
        .pred_ghr_o    (id_ex_pred_ghr_o),                   // 输出给 EX 的 GHR 快照。
        .rd_addr_o     (id_ex_rd_addr_o),                    // 输出给 EX 的 rd 地址。
        .reg_wen_o     (id_ex_reg_wen),                      // 输出给 EX 的写使能。
        .base_addr_o   (id_ex_base_addr_o),                  // 输出给前递单元/EX 的基址。
        .addr_offset_o (id_ex_addr_offset_o)                 // 输出给前递单元/EX 的偏移。
    );

    // -----------------------------------------------------------------
    // 7. 前递单元：解决 RAW 数据冒险
    // -----------------------------------------------------------------
    forwarding forwarding_inst (
        .id_ex_inst_i        (id_ex_inst_o),             // 当前 EX 待执行指令，用于判断 rs1/rs2/base 是否需要前递。
        .id_ex_op1_i         (id_ex_op1_o),              // 原始操作数 1。
        .id_ex_op2_i         (id_ex_op2_o),              // 原始操作数 2。
        .id_ex_base_addr_i   (id_ex_base_addr_o),        // 原始基地址。
        .id_ex_addr_offset_i (id_ex_addr_offset_o),      // 原始地址偏移。
        .ex_mem_rd_addr_i    (ex_mem_pipe_rd_addr_o),    // EX/MEM1 阶段候选前递 rd。
        .ex_mem_rd_data_i    (ex_mem_rd_data_o),         // EX/MEM1 阶段候选前递数据。
        .ex_mem_rd_wen_i     (ex_mem_rd_wen_o),          // EX/MEM1 阶段候选前递写使能。
        .ex_mem_is_load_i    (ex_mem_is_load_o),         // EX/MEM1 若是 load，数据还没从 RAM 回来，通常不能直接前递 load 数据。
        .mem1_mem2_rd_addr_i (mem1_mem2_rd_addr_o),      // MEM1/MEM2 阶段候选前递 rd。
        .mem1_mem2_rd_data_i (mem1_mem2_rd_data_o),      // MEM1/MEM2 阶段候选前递数据。
        .mem1_mem2_rd_wen_i  (mem1_mem2_rd_wen_o),       // MEM1/MEM2 阶段候选前递写使能。
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),      // MEM1/MEM2 若是 load，仍要看 RAM 数据是否真正可用。
        .mem2a_rd_addr_i     (mem2_align_rd_addr_o),     // MEM2 对齐前一级候选前递 rd。
        .mem2a_rd_data_i     (mem2_align_rd_data_o),     // MEM2 对齐前一级候选前递数据。
        .mem2a_rd_wen_i      (mem2_align_rd_wen_o),      // MEM2 对齐前一级候选前递写使能。
        .mem2a_is_load_i     (mem2_align_is_load_o),     // MEM2 对齐前一级 load 标记。
        .mem2_rd_addr_i      (mem2_rd_addr_o),           // MEM2 阶段候选前递 rd。
        .mem2_rd_data_i      (mem2_rd_data_o),           // MEM2 阶段候选前递数据；load 对齐后数据在这里较可靠。
        .mem2_rd_wen_i       (mem2_rd_wen_o),            // MEM2 阶段候选前递写使能。
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),         // MEM2/WB 阶段候选前递 rd。
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),         // MEM2/WB 阶段候选前递数据。
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),          // MEM2/WB 阶段候选前递写使能。
        .fwd_op1_o           (fwd_op1_o),                // 输出修正后的操作数 1。
        .fwd_op2_o           (fwd_op2_o),                // 输出修正后的操作数 2。
        .fwd_base_addr_o     (fwd_base_addr_o),          // 输出修正后的基地址。
        .fwd_addr_offset_o   (fwd_addr_offset_o)         // 输出地址偏移，一般直接透传。
    );

    // -----------------------------------------------------------------
    // 8. 冒险检测单元：负责 hold 和 bubble
    // -----------------------------------------------------------------
    Hazard_detection_unit hdu_inst (
        .id_inst_i         (if_id_inst_o),      // 当前 ID/IFID 指令，作为消费者指令判断源寄存器相关。
        .ex_inst_i         (id_ex_inst_o),      // 当前 EX 指令，作为生产者之一。
        .mem1_inst_i       (mem_inst_o),        // 当前 MEM1 指令，作为生产者之一。
        .mem1_mem2_inst_i  (mem1_mem2_inst_o),  // 当前 MEM1/MEM2 指令，作为生产者之一。
        .mem2a_inst_i      (mem2_align_inst_o), // 当前额外 MEM2 对齐级指令，作为生产者之一。
        .mem2_inst_i       (mem2_inst_o),       // 当前 MEM2 指令，作为生产者之一。
        .ex_busy_i         (ex_rv32m_busy_o),   // 多周期乘除法忙时，需要 hold 前端/流水。
        .hold_flag_o       (hdu_hold_flag_o),   // 输出 hold：冻结 PC/IFID/必要流水寄存器。
        .flush_flag_o      (hdu_flush_flag_o)   // 输出 flush：通常用于 ID/EX 插 bubble。
    );

    // -----------------------------------------------------------------
    // 9. EX 执行模块
    // -----------------------------------------------------------------
    ex ex_inst (
        .clk                 (clk),                     // 时钟，供多周期 M 扩展等时序逻辑使用。
        .rst                 (rst),                     // 低有效复位。
        .inst_i              (id_ex_inst_o),            // EX 输入指令。
        .inst_addr_i         (id_ex_inst_addr_o),       // EX 输入 PC。
        .op1_i               (fwd_op1_o),               // 前递后的操作数 1。
        .op2_i               (fwd_op2_o),               // 前递后的操作数 2。
        .pred_taken_i        (id_ex_pred_taken_o),      // 该指令之前是否预测 taken。
        .pred_target_i       (id_ex_pred_target_o),     // 该指令之前的预测目标。
        .pred_ghr_i          (id_ex_pred_ghr_o),        // 该指令预测时的 GHR 快照。
        .rd_addr_i           (id_ex_rd_addr_o),         // 输入 rd 地址。
        .rd_wen_i            (id_ex_reg_wen),           // 输入 rd 写使能。
        .kill_i              (ctrl_kill_ex_o),          // CTRL kill，杀掉不该执行的 EX 指令。
        .base_addr_i         (fwd_base_addr_o),         // 前递后的基址。
        .addr_offset_i       (fwd_addr_offset_o),       // 地址偏移。
        .rd_addr_o           (ex_rd_addr_o),            // 输出 rd 地址。
        .rd_wen_o            (ex_rd_wen_o),             // 输出写使能。
        .rd_data_o           (ex_rd_data_o),            // 输出 ALU/执行结果。
        .jump_addr_o         (ex_jump_addr_o),          // 输出实际跳转地址。
        .jump_en_o           (ex_jump_en_o),            // 输出实际跳转/纠错使能。
        .mem_wd_reg_o        (ex_wd_reg_o),             // 输出 store 写掩码。
        .mem_wd_addr_o       (ex_wd_addr_o),            // 输出 store 写地址。
        .mem_wd_data_o       (ex_wd_data_o),            // 输出 store 写数据。
        .mem_rd_addr_o       (ex_rd_mem_addr_o),        // 输出 load 读地址。
        .is_load_o           (ex_is_load_o),            // 输出 load 标记。
        .inst_o              (ex_inst_o),               // 透传指令给 EX/MEM1。
        .bp_update_en_o      (bp_update_en_o),          // 输出预测器更新使能。
        .bp_update_pc_o      (bp_update_pc_o),          // 输出预测器更新 PC。
        .bp_update_ghr_o     (bp_update_ghr_o),         // 输出预测器更新 GHR 快照。
        .bp_ras_push_en_o    (bp_ras_push_en_o),        // 输出 RAS push 使能。
        .bp_ras_pop_en_o     (bp_ras_pop_en_o),         // 输出 RAS pop 使能。
        .bp_ras_push_addr_o  (bp_ras_push_addr_o),      // 输出 RAS push 地址。
        .bp_actual_taken_o   (bp_actual_taken_o),       // 输出真实 taken。
        .rv32m_busy_o        (ex_rv32m_busy_o),         // 输出 M 扩展忙标志。
        .rv32m_done_o        (ex_rv32m_done_o)          // 输出 M 扩展完成标志。
    );

    // -----------------------------------------------------------------
    // 10. 中央控制器 CTRL
    // -----------------------------------------------------------------
    ctrl ctrl_inst (
        .clk          (clk),              // 时钟。
        .rst          (rst),              // 低有效复位。
        .jump_addr_i  (ex_jump_addr_o),   // EX 给出的实际跳转地址。
        .jump_en_i    (ex_jump_en_o),     // EX 给出的实际跳转/纠错请求。
        .jump_en_o    (ctrl_jump_en_o),   // CTRL 延迟/整理后的 PC 跳转使能。
        .jump_addr_o  (ctrl_jump_addr_o), // CTRL 延迟/整理后的 PC 跳转地址。
        .kill_ex_o    (ctrl_kill_ex_o),   // CTRL 输出给 EX 的 kill。
        .flush_ifid_o (ctrl_flush_ifid_o),// CTRL 输出给 IF/ID 的 flush。
        .flush_idex_o (ctrl_flush_idex_o),// CTRL 输出给 ID/EX 的 flush。
        .flush_flag_o ()                  // 未使用输出；如果 ctrl 内部还有通用 flush，这里悬空。
    );

    // -----------------------------------------------------------------
    // 11. EX/MEM1 流水线寄存器
    // -----------------------------------------------------------------
    ex_mem1 ex_mem_inst (
        .clk           (clk),                 // 时钟。
        .rst           (rst),                 // 低有效复位。
        .hold_flag_i   (1'b0),                // 该级当前不支持 hold，恒为 0。
        .inst_i        (ex_inst_o),           // EX 指令进入 EX/MEM1。
        .rd_addr_i     (ex_rd_addr_o),        // EX rd 进入 EX/MEM1。
        .rd_data_i     (ex_rd_data_o),        // EX 结果进入 EX/MEM1。
        .rd_wen_i      (ex_rd_wen_o),         // EX 写使能进入 EX/MEM1。
        .mem_wd_reg_i  (ex_wd_reg_o),         // EX store 掩码进入 EX/MEM1。
        .mem_wd_addr_i (ex_wd_addr_o),        // EX store 地址进入 EX/MEM1。
        .mem_wd_data_i (ex_wd_data_o),        // EX store 数据进入 EX/MEM1。
        .mem_rd_addr_i (ex_rd_mem_addr_o),    // EX load 地址进入 EX/MEM1。
        .is_load_i     (ex_is_load_o),        // EX load 标记进入 EX/MEM1。
        .rd_addr_o     (ex_mem_pipe_rd_addr_o), // 输出寄存后的 rd。
        .rd_data_o     (ex_mem_rd_data_o),      // 输出寄存后的执行结果。
        .rd_wen_o      (ex_mem_rd_wen_o),       // 输出寄存后的写使能。
        .mem_wd_reg_o  (ex_mem_wd_reg_o),       // 输出寄存后的 store 掩码。
        .mem_wd_addr_o (ex_mem_wd_addr_o),      // 输出寄存后的 store 地址。
        .mem_wd_data_o (ex_mem_wd_data_o),      // 输出寄存后的 store 数据。
        .mem_rd_addr_o (ex_mem_mem_rd_addr_o),  // 输出寄存后的 load 地址。
        .is_load_o     (ex_mem_is_load_o),      // 输出寄存后的 load 标记。
        .inst_o        (ex_mem_inst_o)          // 输出寄存后的指令。
    );

    // -----------------------------------------------------------------
    // 12. MEM1 第一访存级
    // -----------------------------------------------------------------
    mem1 mem_inst (
        .inst_i        (ex_mem_inst_o),          // 输入 EX/MEM1 指令。
        .rd_addr_i     (ex_mem_pipe_rd_addr_o),  // 输入写回地址。
        .rd_data_i     (ex_mem_rd_data_o),       // 输入 ALU 结果。
        .rd_wen_i      (ex_mem_rd_wen_o),        // 输入写回使能。
        .mem_rd_addr_i (ex_mem_mem_rd_addr_o),   // 输入 load 读地址。
        .mem_wd_reg_i  (ex_mem_wd_reg_o),        // 输入 store 写掩码。
        .mem_wd_addr_i (ex_mem_wd_addr_o),       // 输入 store 写地址。
        .mem_wd_data_i (ex_mem_wd_data_o),       // 输入 store 写数据。
        .is_load_i     (ex_mem_is_load_o),       // 输入 load 标记。
        .rd_addr_o     (mem_out_rd_addr_o),      // 输出透传写回地址。
        .rd_data_o     (mem_out_rd_data_o),      // 输出透传 ALU 结果。
        .rd_wen_o      (mem_out_rd_wen_o),       // 输出透传写使能。
        .mem_rd_addr_o (mem_out_mem_rd_addr_o),  // 输出透传 load 地址。
        .mem_wd_reg_o  (w_en),                   // 输出到外部 RAM 的 store 写掩码。
        .mem_wd_addr_o (w_addr_i),               // 输出到外部 RAM 的 store 写地址。
        .mem_wd_data_o (w_data_i),               // 输出到外部 RAM 的 store 写数据。
        .inst_o        (mem_inst_o),             // 输出透传指令。
        .is_load_o     (mem_out_is_load_o)       // 输出透传 load 标记。
    );

    // -----------------------------------------------------------------
    // 13. MEM1/MEM2 流水线寄存器
    // -----------------------------------------------------------------
    mem1_mem2 mem1_mem2_inst (
        .clk           (clk),                    // 时钟。
        .rst           (rst),                    // 低有效复位。
        .hold_flag_i   (1'b0),                   // 该级不 hold。
        .flush_flag_i  (1'b0),                   // 该级不 flush。
        .inst_i        (mem_inst_o),             // MEM1 指令进入 MEM1/MEM2。
        .rd_addr_i     (mem_out_rd_addr_o),      // MEM1 写回地址进入寄存器。
        .rd_data_i     (mem_out_rd_data_o),      // MEM1 数据进入寄存器。
        .rd_wen_i      (mem_out_rd_wen_o),       // MEM1 写使能进入寄存器。
        .mem_rd_addr_i (mem_out_mem_rd_addr_o),  // MEM1 load 地址进入寄存器。
        .is_load_i     (mem_out_is_load_o),      // MEM1 load 标记进入寄存器。
        .rd_addr_o     (mem1_mem2_rd_addr_o),    // 输出寄存后的写回地址。
        .rd_data_o     (mem1_mem2_rd_data_o),    // 输出寄存后的 ALU/透传数据。
        .rd_wen_o      (mem1_mem2_rd_wen_o),     // 输出寄存后的写使能。
        .mem_rd_addr_o (mem1_mem2_mem_rd_addr_o),// 输出寄存后的 load 地址。
        .is_load_o     (mem1_mem2_is_load_o),    // 输出寄存后的 load 标记。
        .inst_o        (mem1_mem2_inst_o)        // 输出寄存后的指令。
    );

    // -----------------------------------------------------------------
    // 14. MEM2 对齐级寄存器
    // -----------------------------------------------------------------
    mem1_mem2 mem2_align_inst (
        .clk           (clk),                         // 时钟。
        .rst           (rst),                         // 低有效复位。
        .hold_flag_i   (1'b0),                        // 不 hold。
        .flush_flag_i  (1'b0),                        // 不 flush。
        .inst_i        (mem1_mem2_inst_o),            // MEM1/MEM2 指令再打一拍。
        .rd_addr_i     (mem1_mem2_rd_addr_o),         // 写回地址再打一拍。
        .rd_data_i     (mem1_mem2_rd_data_o),         // ALU/透传数据再打一拍。
        .rd_wen_i      (mem1_mem2_rd_wen_o),          // 写使能再打一拍。
        .mem_rd_addr_i (mem1_mem2_mem_rd_addr_o),     // load 地址再打一拍。
        .is_load_i     (mem1_mem2_is_load_o),         // load 标记再打一拍。
        .rd_addr_o     (mem2_align_rd_addr_o),        // 输出对齐后的写回地址。
        .rd_data_o     (mem2_align_rd_data_o),        // 输出对齐后的 ALU/透传数据。
        .rd_wen_o      (mem2_align_rd_wen_o),         // 输出对齐后的写使能。
        .mem_rd_addr_o (mem2_align_mem_rd_addr_o),    // 输出对齐后的 load 地址。
        .is_load_o     (mem2_align_is_load_o),        // 输出对齐后的 load 标记。
        .inst_o        (mem2_align_inst_o)            // 输出对齐后的指令。
    );

    // -----------------------------------------------------------------
    // 15. MEM2 第二访存级
    // -----------------------------------------------------------------
    mem2 mem2_inst (
        .inst_i        (mem2_align_inst_o),        // 输入对齐后的指令。
        .rd_addr_i     (mem2_align_rd_addr_o),     // 输入对齐后的写回地址。
        .rd_data_i     (mem2_align_rd_data_o),     // 输入 ALU/透传数据；非 load 指令一般直接走它。
        .rd_wen_i      (mem2_align_rd_wen_o),      // 输入写使能。
        .mem_rd_addr_i (mem2_align_mem_rd_addr_o), // 输入 load 地址，用于决定 byte/halfword 的选取位置。
        .is_load_i     (mem2_align_is_load_o),     // 输入 load 标记；决定是否使用 ram_data_i。
        .mem_rd_data_i (ram_data_i),               // 外部 RAM 返回的读数据。
        .rd_addr_o     (mem2_rd_addr_o),           // 输出最终写回地址。
        .rd_data_o     (mem2_rd_data_o),           // 输出最终写回数据；load 已完成对齐/扩展。
        .rd_wen_o      (mem2_rd_wen_o),            // 输出最终写使能。
        .inst_o        (mem2_inst_o)               // 输出透传指令。
    );

    // -----------------------------------------------------------------
    // 16. MEM2/WB 流水线寄存器
    // -----------------------------------------------------------------
    mem2_wb mem_wb_inst (
        .clk         (clk),               // 时钟。
        .rst         (rst),               // 低有效复位。
        .hold_flag_i (1'b0),              // WB 前一级不 hold。
        .inst_i      (mem2_inst_o),       // MEM2 指令进入 MEM2/WB。
        .rd_addr_i   (mem2_rd_addr_o),    // MEM2 写回地址进入 MEM2/WB。
        .rd_data_i   (mem2_rd_data_o),    // MEM2 写回数据进入 MEM2/WB。
        .rd_wen_i    (mem2_rd_wen_o),     // MEM2 写使能进入 MEM2/WB。
        .rd_addr_o   (mem_wb_rd_addr_o),  // 输出给 WB 的写回地址。
        .rd_data_o   (mem_wb_rd_data_o),  // 输出给 WB 的写回数据。
        .rd_wen_o    (mem_wb_rd_wen_o),   // 输出给 WB 的写使能。
        .inst_o      (mem_wb_inst_o)      // 输出给 WB 的指令。
    );

    // -----------------------------------------------------------------
    // 17. WB 写回模块
    // -----------------------------------------------------------------
    wb wb_inst (
        .inst_i    (mem_wb_inst_o),       // 输入 MEM2/WB 指令。
        .rd_addr_i (mem_wb_rd_addr_o),    // 输入写回地址。
        .rd_data_i (mem_wb_rd_data_o),    // 输入写回数据。
        .rd_wen_i  (mem_wb_rd_wen_o),     // 输入写回使能。
        .inst_o    (),                    // WB 之后没有下一级，所以指令输出悬空。
        .rd_data_o (wb_rd_data_o),        // 输出给寄存器堆的最终写回数据。
        .rd_wen_o  (wb_rd_wen_o),         // 输出给寄存器堆的最终写使能。
        .rd_addr_o (wb_rd_addr_o)         // 输出给寄存器堆的最终写地址。
    );

endmodule  // open_risc_v
