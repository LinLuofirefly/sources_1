// =============================================================================
// 文件名: id.v
// 功  能: 译码模块 (Instruction Decode)
// 说  明: 将 32 位 RISC-V 指令解码为各级流水线所需的控制信号和操作数。
//
//         主要职责:
//         1. 从指令中提取 opcode、funct3、funct7、rs1、rs2、rd、imm 等字段
//         2. 根据指令类型准备 ALU 操作数 (op1, op2)
//         3. 计算访存/跳转所需的基地址和偏移量
//         4. 生成寄存器写使能和 Load 标记等控制信号
//
//         支持的指令集: RV32I (I/R/B/L/S/J/U 型)
// =============================================================================

`include "defines.v"

module id (
    // =================================================================
    // 输入: 从 IF/ID 流水线寄存器接收
    // =================================================================
    input  wire [31:0] inst_i,             // 32 位机器指令
    input  wire [31:0] inst_addr_i,        // 指令对应的 PC 地址
    input  wire        pred_taken_i,       // 预测是否跳转

    // =================================================================
    // 与寄存器堆的接口
    // =================================================================
    output wire [4:0]  rs1_addr_o,         // 源寄存器 1 读地址 → Regfile
    output wire [4:0]  rs2_addr_o,         // 源寄存器 2 读地址 → Regfile
    input  wire [31:0] rs1_data_i,         // 源寄存器 1 读数据 ← Regfile
    input  wire [31:0] rs2_data_i,         // 源寄存器 2 读数据 ← Regfile

    // =================================================================
    // 输出: 传递给 ID/EX 流水线寄存器
    // =================================================================
    output reg  [31:0] inst_o,             // 透传的指令机器码 (供后续级使用)
    output reg  [31:0] inst_addr_o,        // 透传的指令 PC 地址
    output reg  [31:0] op1_o,              // ALU 操作数 1
    output reg  [31:0] op2_o,              // ALU 操作数 2
    output wire [4:0]  rd_addr_o,          // 目标寄存器地址 (结果写回目的地)
    output reg         reg_wen,            // 寄存器写使能 (1: 需要写回结果)
    output reg  [31:0] base_addr_o,        // 基地址 (用于访存/跳转地址计算)
    output reg  [31:0] addr_offset_o,      // 地址偏移量 (用于访存/跳转地址计算)
    output reg         mem_rd_reg_o,        // 内存读标记 (1: 这是一条 Load 指令)
    output reg         pred_taken_o       // 预测是否跳转
);

    // =================================================================
    // 指令字段提取 (组合逻辑，直接从指令位域截取)
    // =================================================================
    wire [6:0]  opcode = inst_i[6:0];      // 操作码: 决定指令大类
    wire [4:0]  rd     = inst_i[11:7];     // 目标寄存器索引
    wire [2:0]  func3  = inst_i[14:12];    // 功能码 3: 细分具体指令
    wire [4:0]  rs1    = inst_i[19:15];    // 源寄存器 1 索引
    wire [4:0]  rs2    = inst_i[24:20];    // 源寄存器 2 索引
    wire [6:0]  func7  = inst_i[31:25];    // 功能码 7: 进一步区分指令 (如 ADD/SUB)
    wire [11:0] imm    = inst_i[31:20];    // 12 位立即数 (I 型格式)
    wire [4:0]  shamt  = imm[4:0];         // 移位量: 立即数的低 5 位
    assign rs1_addr_o = rs1;
    assign rs2_addr_o = rs2;
    assign rd_addr_o = rd;

    // =================================================================
    // 译码主逻辑 (纯组合逻辑)
    // =================================================================
    always @(*) begin
        // -------------------------------------------------------------
        // 默认赋值: 所有输出都赋默认值，防止综合出锁存器 (Latch)
        // -------------------------------------------------------------
        inst_o        = inst_i;            // 直接透传指令
        inst_addr_o   = inst_addr_i;       // 直接透传 PC 地址
        mem_rd_reg_o  = 1'b0;              // 默认: 不是 Load 指令
        pred_taken_o  = pred_taken_i;      // 直接透传预测是否跳转

        // -------------------------------------------------------------
        // 按 Opcode 分支译码
        // -------------------------------------------------------------
        case (opcode)

            // =========================================================
            // I 型: 立即数算术逻辑运算 (ADDI, SLTI, ANDI, SLLI 等)
            // =========================================================
            `INST_TYPE_I: begin
                base_addr_o   = 32'b0;                         // I 型无访存，基地址清零
                addr_offset_o = 32'b0;                         // I 型无访存，偏移量清零
                case (func3)
                    // --- 常规算术逻辑运算 ---
                    `INST_ADDI, `INST_SLTI, `INST_SLTIU,
                    `INST_ORI, `INST_XORI, `INST_ANDI: begin
                        op1_o      = rs1_data_i;               // 操作数 1: rs1 的值
                        op2_o      = {{20{imm[11]}}, imm};     // 操作数 2: 12 位立即数符号扩展至 32 位
                        reg_wen    = 1'b1;                     // 使能寄存器写回
                    end
                    // --- 移位运算 ---
                    `INST_SLLI, `INST_SRI: begin
                        op1_o      = rs1_data_i;               // 操作数 1: rs1 的值
                        op2_o      = {27'b0, shamt};           // 操作数 2: 5 位移位量 (零扩展)
                        reg_wen    = 1'b1;                     // 使能寄存器写回
                    end
                    default: begin
                        op1_o = 32'b0; op2_o = 32'b0;
                        reg_wen = 1'b0;
                    end
                endcase
            end

            // =========================================================
            // R/M 型: 寄存器-寄存器运算 (ADD, SUB, AND, OR, SLL 等)
            // =========================================================
            `INST_TYPE_R_M: begin
                base_addr_o   = 32'b0;                         // R 型无访存
                addr_offset_o = 32'b0;                         // R 型无访存
                case (func3)
                    // --- 常规运算 ---
                    `INST_ADD_SUB, `INST_SLT, `INST_SLTU,
                    `INST_OR, `INST_XOR, `INST_AND: begin
                        op1_o      = rs1_data_i;               // 操作数 1: rs1 的值
                        op2_o      = rs2_data_i;               // 操作数 2: rs2 的值
                        reg_wen    = 1'b1;                     // 使能写回
                    end
                    // --- 移位运算 ---
                    `INST_SLL, `INST_SR: begin
                        op1_o      = rs1_data_i;               // 操作数 1: rs1 的值
                        op2_o      = {27'b0, rs2_data_i[4:0]}; // 操作数 2: rs2 低 5 位作为移位量
                        reg_wen    = 1'b1;                     // 使能写回
                    end
                    default: begin
                        op1_o = 32'b0; op2_o = 32'b0;
                        reg_wen = 1'b0;
                    end
                endcase
            end

            // =========================================================
            // B 型: 条件分支跳转 (BEQ, BNE, BLT, BGE, BLTU, BGEU)
            // =========================================================
            `INST_TYPE_B: begin
                case (func3)
                    `INST_BNE, `INST_BEQ, `INST_BLT,
                    `INST_BGE, `INST_BLTU, `INST_BGEU: begin
                        op1_o         = rs1_data_i;            // 操作数 1: rs1 的值
                        op2_o         = rs2_data_i;            // 操作数 2: rs2 的值
                        reg_wen       = 1'b0;                  // 禁止写回
                        base_addr_o   = inst_addr_i;           // 跳转基地址: 当前 PC
                        // B 型立即数拼接: {imm[12|10:5], imm[4:1|11]} → 符号扩展后左移 1 位
                        addr_offset_o = {{20{inst_i[31]}}, inst_i[7], inst_i[30:25], inst_i[11:8], 1'b0};
                    end
                    default: begin
                        op1_o = 32'b0; op2_o = 32'b0;
                        reg_wen = 1'b0;
                        base_addr_o = 32'b0; addr_offset_o = 32'b0;
                    end
                endcase
            end

            // =========================================================
            // L 型: 内存加载 (LB, LH, LW, LBU, LHU)
            // =========================================================
            `INST_TYPE_L: begin
                case (func3)
                    `INST_LB, `INST_LH, `INST_LW,
                    `INST_LBU, `INST_LHU: begin
                        op1_o         = 32'b0;                 // ALU 操作数清零 (Load 不需 ALU 计算)
                        op2_o         = 32'b0;                 // ALU 操作数清零
                        reg_wen       = 1'b1;                  // 使能写回
                        base_addr_o   = rs1_data_i;            // 访存基地址: rs1 的值
                        addr_offset_o = {{20{imm[11]}}, imm};  // 地址偏移: 12 位立即数符号扩展
                        mem_rd_reg_o  = 1'b1;                  // 标记: 这是一条 Load 指令
                    end
                    default: begin
                        op1_o = 32'b0; op2_o = 32'b0;
                        reg_wen = 1'b0;
                        base_addr_o = 32'b0; addr_offset_o = 32'b0;
                        mem_rd_reg_o = 1'b0;
                    end
                endcase
            end

            // =========================================================
            // S 型: 内存存储 (SB, SH, SW)
            // =========================================================
            `INST_TYPE_S: begin
                case (func3)
                    `INST_SB, `INST_SH, `INST_SW: begin
                        op1_o         = rs1_data_i;            // 操作数 1: rs1 的值
                        op2_o         = rs2_data_i;            // 操作数 2: rs2 的值 (待写入内存的数据)
                        reg_wen       = 1'b0;                  // 禁止写回
                        base_addr_o   = rs1_data_i;            // 访存基地址: rs1 的值
                        // S 型立即数拼接: {imm[11:5], imm[4:0]} → 符号扩展
                        addr_offset_o = {{20{inst_i[31]}}, inst_i[31:25], inst_i[11:7]};
                        mem_rd_reg_o  = 1'b0;                  // 不是 Load 指令
                    end
                    default: begin
                        op1_o = 32'b0; op2_o = 32'b0;
                        reg_wen = 1'b0;
                        base_addr_o = 32'b0; addr_offset_o = 32'b0;
                        mem_rd_reg_o = 1'b0;
                    end
                endcase
            end

            // =========================================================
            // JAL: 无条件跳转并链接 (PC 相对)
            // rd = PC + 4; PC = PC + imm
            // =========================================================
            `INST_JAL: begin
                op1_o         = inst_addr_i;                   // 操作数 1: 当前 PC
                op2_o         = 32'd4;                         // 操作数 2: 4 (计算 PC+4 作返回地址)
                reg_wen       = 1'b1;                          // 使能写回
                base_addr_o   = inst_addr_i;                   // 跳转基地址: 当前 PC
                // J 型立即数拼接: {imm[20|10:1|11|19:12]} → 符号扩展后左移 1 位
                addr_offset_o = {{12{inst_i[31]}}, inst_i[19:12], inst_i[20], inst_i[30:21], 1'b0};
                mem_rd_reg_o  = 1'b0;                          // 不是 Load 指令
            end

            // =========================================================
            // JALR: 寄存器间接跳转并链接
            // rd = PC + 4; PC = (rs1 + imm) & ~1
            // =========================================================
            `INST_JALR: begin
                op1_o         = inst_addr_i;                   // 操作数 1: 当前 PC
                op2_o         = 32'd4;                         // 操作数 2: 4 (计算 PC+4)
                reg_wen       = 1'b1;                          // 使能写回
                base_addr_o   = rs1_data_i;                    // 跳转基地址: rs1 寄存器的值
                addr_offset_o = {{20{imm[11]}}, imm};          // 偏移: 12 位立即数符号扩展
                mem_rd_reg_o  = 1'b0;                          // 不是 Load 指令
            end

            // =========================================================
            // AUIPC: 高位立即数加 PC
            // rd = PC + (imm << 12)
            // =========================================================
            `INST_AUIPC: begin
                op1_o         = inst_addr_i;                   // 操作数 1: 当前 PC
                op2_o         = {inst_i[31:12], 12'b0};        // 操作数 2: 高 20 位立即数左移 12 位
                reg_wen       = 1'b1;                          // 使能写回
                base_addr_o   = 32'b0;                         // 无访存
                addr_offset_o = 32'b0;                         // 无偏移
                mem_rd_reg_o  = 1'b0;                          // 不是 Load 指令
            end

            // =========================================================
            // LUI: 高位立即数加载
            // rd = imm << 12
            // =========================================================
            `INST_LUI: begin
                op1_o         = {inst_i[31:12], 12'b0};        // 操作数 1: 高 20 位立即数左移 12 位
                op2_o         = 32'b0;                         // 操作数 2: 0 (结果 = imm)
                reg_wen       = 1'b1;                          // 使能写回
                base_addr_o   = 32'b0;                         // 无访存
                addr_offset_o = 32'b0;                         // 无偏移
                mem_rd_reg_o  = 1'b0;                          // 不是 Load 指令
            end

            // =========================================================
            // 默认: 未知/不支持的指令
            // =========================================================
            default: begin
                op1_o         = 32'b0;
                op2_o         = 32'b0;
                reg_wen       = 1'b0;
                base_addr_o   = 32'b0;
                addr_offset_o = 32'b0;
                mem_rd_reg_o  = 1'b0;
            end

        endcase
    end

endmodule