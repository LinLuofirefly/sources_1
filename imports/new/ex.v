// =============================================================================
// 文件名: ex.v
// 功  能: 执行模块 (Execution Unit / ALU)
// 说  明: 根据译码结果执行算术逻辑运算、地址计算、分支判定等。
//
//         主要职责:
//         1. 对 I/R 型指令执行 ALU 运算 (加减、移位、比较、逻辑)
//         2. 对 B 型指令进行条件比较，决定是否跳转
//         3. 对 L 型指令计算内存读地址
//         4. 对 S 型指令计算内存写地址，并根据 SB/SH/SW 生成写掩码和对齐数据
//         5. 对 JAL/JALR 指令计算跳转目标地址和返回地址 (PC+4)
//         6. 对 LUI/AUIPC 指令生成立即数结果
//
//         设计思想: "空间换时间"
//         所有可能的运算结果在组合逻辑中并行计算，然后通过多路选择器
//         根据 opcode 选择需要的结果。这是硬件设计的常见优化策略。
// =============================================================================

`include "defines.v"

module ex (
    // =================================================================
    // 输入: 从 ID/EX 流水线寄存器接收 (经前递修正后)
    // =================================================================
    input  wire [31:0] inst_i,             // 当前执行的 32 位指令
    input  wire [31:0] inst_addr_i,        // 当前指令的 PC 地址
    input  wire [31:0] op1_i,              // 操作数 1 (经前递修正)
    input  wire [31:0] op2_i,              // 操作数 2 (经前递修正)
    input  wire [4:0]  rd_addr_i,          // 目标寄存器地址
    input  wire        rd_wen_i,           // 寄存器写使能

    // =================================================================
    // 输出: 写回通道 (送往 EX/MEM1 流水线寄存器)
    // =================================================================
    output reg  [4:0]  rd_addr_o,          // 写回目标寄存器地址
    output reg  [31:0] rd_data_o,          // ALU 计算结果 (写回数据)
    output reg         rd_wen_o,           // 寄存器写使能

    // =================================================================
    // 输出: 跳转控制 (送往 CTRL 控制器)
    // =================================================================
    output reg  [31:0] jump_addr_o,        // 跳转目标地址
    output reg         jump_en_o,          // 跳转使能 (1: 需要跳转)

    // =================================================================
    // 输出: 指令透传
    // =================================================================
    output wire [31:0] inst_o,             // 透传指令码给 EX/MEM1

    // =================================================================
    // 访存接口
    // =================================================================
    input  wire [31:0] base_addr_i,        // 访存基地址 (经前递修正)
    input  wire [31:0] addr_offset_i,      // 访存地址偏移量
    output reg  [31:0] mem_rd_addr_o,      // 内存读地址 (Load 指令)
    output reg  [3:0]  mem_wd_reg_o,       // 内存写掩码 (Store: 控制写入哪些字节)
    output reg  [31:0] mem_wd_addr_o,      // 内存写地址 (Store 指令)
    output reg  [31:0] mem_wd_data_o,      // 内存写数据 (Store 指令)
    output reg         is_load_o           // Load 标记 (1: 当前为 Load 指令)
);

    // =================================================================
    // 指令字段提取
    // =================================================================
    wire [6:0]  opcode = inst_i[6:0];      // 操作码
    wire [2:0]  func3  = inst_i[14:12];    // 功能码 3
    wire [4:0]  rd     = inst_i[11:7];     // 目标寄存器索引
    wire [4:0]  rs1    = inst_i[19:15];    // 源寄存器 1 索引
    wire [4:0]  rs2    = inst_i[24:20];    // 源寄存器 2 索引
    wire [11:0] imm    = inst_i[31:20];    // 12 位立即数
    wire [6:0]  func7  = inst_i[31:25];    // 功能码 7
    wire [4:0]  shamt  = op2_i[4:0];       // 移位量: 取操作数 2 的低 5 位

    // =================================================================
    // ALU 预计算: 并行计算所有可能的运算结果
    // =================================================================

    // --- 比较器 ---
    wire op1_i_equal_op2_i         = (op1_i == op2_i);                    // 相等比较
    wire op1_i_less_op2_i_signed   = ($signed(op1_i) < $signed(op2_i));   // 有符号小于
    wire op1_i_less_op2_i_unsigned = (op1_i < op2_i);                     // 无符号小于

    // --- 算术逻辑运算 ---
    wire [31:0] op1_i_add_op2_i = op1_i + op2_i;      // 加法
    wire [31:0] op1_i_and_op2_i = op1_i & op2_i;      // 按位与
    wire [31:0] op1_i_xor_op2_i = op1_i ^ op2_i;      // 按位异或
    wire [31:0] op1_i_or_op2_i  = op1_i | op2_i;      // 按位或

    // --- 移位运算 ---
    wire [31:0] op1_i_shift_left_op2_i  = op1_i << op2_i[4:0];   // 逻辑左移
    wire [31:0] op1_i_shift_right_op2_i = op1_i >> op2_i[4:0];   // 逻辑右移

    // 算术右移 (SRA) 掩码: 用于高位补符号位
    // SRA_mask 的高位为 0，低位为 1，长度等于移位后保留的有效位
    wire [31:0] SRA_mask = (32'hffffffff >> shamt[4:0]);

    // --- 地址运算 ---
    wire [31:0] base_addr_add_addr_offset = base_addr_i + addr_offset_i;  // 目标地址

    // 指令码直接透传
    assign inst_o = inst_i;

    // =================================================================
    // 执行级主控逻辑 (组合逻辑)
    // =================================================================
    always @(*) begin
        // --- 默认赋值: 防止生成锁存器 ---
        rd_data_o     = 32'b0;
        rd_addr_o     = 5'b0;
        rd_wen_o      = 1'b0;
        jump_addr_o   = 32'b0;
        jump_en_o     = 1'b0;
        mem_wd_reg_o  = 4'b0000;
        mem_wd_addr_o = 32'b0;
        mem_wd_data_o = 32'b0;
        is_load_o     = 1'b0;
        mem_rd_addr_o = 32'b0;

        case (opcode)

            // =========================================================
            // I 型: 立即数运算
            // =========================================================
            `INST_TYPE_I: begin
                case (func3)
                    `INST_ADDI:  begin rd_data_o = op1_i_add_op2_i;                    rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // ADDI
                    `INST_SLTI:  begin rd_data_o = {31'b0, op1_i_less_op2_i_signed};   rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLTI
                    `INST_SLTIU: begin rd_data_o = {31'b0, op1_i_less_op2_i_unsigned}; rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLTIU
                    `INST_ANDI:  begin rd_data_o = op1_i_and_op2_i;                    rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // ANDI
                    `INST_ORI:   begin rd_data_o = op1_i_or_op2_i;                     rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // ORI
                    `INST_XORI:  begin rd_data_o = op1_i_xor_op2_i;                    rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // XORI
                    `INST_SLLI:  begin rd_data_o = op1_i_shift_left_op2_i;             rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLLI
                    `INST_SRI: begin
                        if (func7[5] == 1'b0) begin
                            // SRLI: 逻辑右移，高位补 0
                            rd_data_o = op1_i_shift_right_op2_i;
                        end else begin
                            // SRAI: 算术右移，高位补符号位
                            rd_data_o = (op1_i_shift_right_op2_i & SRA_mask) | ({32{op1_i[31]}} & ~SRA_mask);
                        end
                        rd_addr_o = rd_addr_i;
                        rd_wen_o  = 1'b1;
                    end
                    default: begin rd_data_o = 32'b0; rd_addr_o = 5'b0; rd_wen_o = 1'b0; end
                endcase
            end

            // =========================================================
            // R/M 型: 寄存器运算
            // =========================================================
            `INST_TYPE_R_M: begin
                case (func3)
                    `INST_ADD_SUB: begin
                        if (func7 == 7'b0000_000) begin
                            rd_data_o = op1_i_add_op2_i;              // ADD
                        end else begin
                            rd_data_o = op1_i - op2_i;                // SUB
                        end
                        rd_addr_o = rd_addr_i; rd_wen_o = 1'b1;
                    end
                    `INST_SLL:  begin rd_data_o = op1_i_shift_left_op2_i;              rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLL
                    `INST_SLT:  begin rd_data_o = {31'b0, op1_i_less_op2_i_signed};    rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLT
                    `INST_SLTU: begin rd_data_o = {31'b0, op1_i_less_op2_i_unsigned};  rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // SLTU
                    `INST_OR:   begin rd_data_o = op1_i_or_op2_i;                      rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // OR
                    `INST_XOR:  begin rd_data_o = op1_i_xor_op2_i;                     rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // XOR
                    `INST_AND:  begin rd_data_o = op1_i_and_op2_i;                     rd_addr_o = rd_addr_i; rd_wen_o = 1'b1; end  // AND
                    `INST_SR: begin
                        if (func7[5] == 1'b0) begin
                            rd_data_o = op1_i_shift_right_op2_i;      // SRL: 逻辑右移
                        end else begin
                            // SRA: 算术右移
                            rd_data_o = (op1_i_shift_right_op2_i & SRA_mask) | ({32{op1_i[31]}} & ~SRA_mask);
                        end
                        rd_addr_o = rd_addr_i; rd_wen_o = 1'b1;
                    end
                    default: begin rd_data_o = 32'b0; rd_addr_o = 5'b0; rd_wen_o = 1'b0; end
                endcase
            end

            // =========================================================
            // B 型: 条件分支
            // 跳转目标地址 = base_addr (PC) + addr_offset (立即数)
            // =========================================================
            `INST_TYPE_B: begin
                case (func3)
                    `INST_BNE:  begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = ~op1_i_equal_op2_i;         end  // BNE: 不等则跳
                    `INST_BEQ:  begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = op1_i_equal_op2_i;          end  // BEQ: 相等则跳
                    `INST_BLT:  begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = op1_i_less_op2_i_signed;    end  // BLT: 有符号小于则跳
                    `INST_BGE:  begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = ~op1_i_less_op2_i_signed;   end  // BGE: 有符号大于等于则跳
                    `INST_BLTU: begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = op1_i_less_op2_i_unsigned;  end  // BLTU: 无符号小于则跳
                    `INST_BGEU: begin jump_addr_o = base_addr_add_addr_offset; jump_en_o = ~op1_i_less_op2_i_unsigned; end  // BGEU: 无符号大于等于则跳
                    default:    begin jump_addr_o = 32'b0;                     jump_en_o = 1'b0;                       end
                endcase
            end

            // =========================================================
            // L 型: Load (计算内存读地址，标记为 Load 指令)
            // =========================================================
            `INST_TYPE_L: begin
                is_load_o     = 1'b1;                              // 标记: Load 指令
                rd_addr_o     = rd_addr_i;                         // 设置写回目标寄存器
                rd_wen_o      = 1'b1;                              // 使能写回
                mem_rd_addr_o = base_addr_add_addr_offset;         // 计算内存读地址 = rs1 + imm
            end

            // =========================================================
            // S 型: Store (计算内存写地址，生成写掩码和对齐数据)
            // =========================================================
            `INST_TYPE_S: begin
                mem_wd_addr_o = base_addr_add_addr_offset;         // 计算内存写地址 = rs1 + imm
                case (func3)
                    `INST_SB: begin
                        // 存储字节: 根据地址低 2 位确定写入哪个字节位置
                        case (base_addr_add_addr_offset[1:0])
                            2'b00: begin mem_wd_reg_o = 4'b0001; mem_wd_data_o = {24'b0, op2_i[7:0]};             end  // 写入字节 0
                            2'b01: begin mem_wd_reg_o = 4'b0010; mem_wd_data_o = {16'b0, op2_i[7:0], 8'b0};      end  // 写入字节 1
                            2'b10: begin mem_wd_reg_o = 4'b0100; mem_wd_data_o = {8'b0, op2_i[7:0], 16'b0};      end  // 写入字节 2
                            2'b11: begin mem_wd_reg_o = 4'b1000; mem_wd_data_o = {op2_i[7:0], 24'b0};             end  // 写入字节 3
                            default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                        endcase
                    end
                    `INST_SH: begin
                        // 存储半字: 根据地址 bit[1] 确定写入高半字还是低半字
                        case (base_addr_add_addr_offset[1])
                            1'b0: begin mem_wd_reg_o = 4'b0011; mem_wd_data_o = {16'b0, op2_i[15:0]};            end  // 写入低半字
                            1'b1: begin mem_wd_reg_o = 4'b1100; mem_wd_data_o = {op2_i[15:0], 16'b0};            end  // 写入高半字
                            default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                        endcase
                    end
                    `INST_SW: begin
                        // 存储字: 全部 4 字节写入
                        mem_wd_reg_o  = 4'b1111;
                        mem_wd_data_o = op2_i;
                    end
                    default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                endcase
            end

            // =========================================================
            // JAL: 无条件跳转并链接 (PC 相对)
            // =========================================================
            `INST_JAL: begin
                rd_data_o   = op1_i_add_op2_i;                    // rd = PC + 4 (返回地址)
                rd_addr_o   = rd_addr_i;                           // 写回 rd
                rd_wen_o    = 1'b1;                                // 使能写回
                jump_addr_o = base_addr_add_addr_offset;           // 跳转地址 = PC + imm
                jump_en_o   = 1'b1;                                // 触发跳转
            end

            // =========================================================
            // JALR: 寄存器间接跳转并链接
            // =========================================================
            `INST_JALR: begin
                rd_data_o   = inst_addr_i + 32'd4;                // rd = PC + 4 (返回地址)
                rd_addr_o   = rd_addr_i;                           // 写回 rd
                rd_wen_o    = 1'b1;                                // 使能写回
                jump_addr_o = base_addr_add_addr_offset & ~32'd1;  // 跳转地址 = (rs1+imm) & ~1
                jump_en_o   = 1'b1;                                // 触发跳转
            end

            // =========================================================
            // AUIPC: 高位立即数加 PC
            // =========================================================
            `INST_AUIPC: begin
                rd_data_o   = op1_i_add_op2_i;                    // rd = PC + (imm << 12)
                rd_addr_o   = rd_addr_i;                           // 写回 rd
                rd_wen_o    = 1'b1;                                // 使能写回
                jump_addr_o = 32'b0;                               // 不跳转
                jump_en_o   = 1'b0;
            end

            // =========================================================
            // LUI: 高位立即数加载
            // =========================================================
            `INST_LUI: begin
                rd_data_o   = op1_i;                               // rd = imm << 12 (由 ID 级组装)
                rd_addr_o   = rd_addr_i;                           // 写回 rd
                rd_wen_o    = 1'b1;                                // 使能写回
                jump_addr_o = 32'b0;                               // 不跳转
                jump_en_o   = 1'b0;
            end

            // =========================================================
            // 默认: 未知指令
            // =========================================================
            default: begin
                rd_data_o     = 32'b0;
                rd_addr_o     = 5'b0;
                rd_wen_o      = 1'b0;
                jump_en_o     = 1'b0;
                jump_addr_o   = 32'b0;
                mem_wd_addr_o = 32'b0;
                mem_wd_data_o = 32'b0;
                mem_wd_reg_o  = 4'b0000;
            end

        endcase
    end

endmodule