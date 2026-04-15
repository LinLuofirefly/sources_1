// =============================================================================
// 文件名: forwarding.v
// 功  能: 前递单元 (Forwarding Unit / 数据旁路单元)
// 说  明: 检测流水线中的数据相关 (RAW Hazard)，将最新的计算结果旁路到
//         EX 级的操作数输入端，避免因数据冒险读到过时的寄存器值。
//
//         支持的前递路径 (按优先级从高到低):
//         ① EX/MEM1  → EX  (上 1 条指令的 ALU 结果，但 Load 除外)
//         ② MEM1/MEM2 → EX  (上 2 条指令的结果)
//         ③ MEM2/WB  → EX  (上 3 条指令的结果，包括 Load 数据)
//         ④ 无相关:           使用 ID/EX 寄存器中的原始操作数
//
//         特殊处理:
//         - EX/MEM1 级的 Load 指令不前递 (数据尚未从 RAM 读出)，
//           此情况由冒险检测单元插入 1 个气泡后，在后续拍通过
//           MEM1/MEM2 或 MEM2/WB 路径完成前递
//         - 对 x0 寄存器不做前递 (x0 恒为 0)
//         - 对 base_addr (访存基地址) 单独做 rs1 前递
// =============================================================================

`include "defines.v"

module forwarding (
    // =================================================================
    // 1. 当前 ID/EX 级的指令信息
    // =================================================================
    input  wire [31:0] id_ex_inst_i,       // ID/EX 级指令机器码
    input  wire [31:0] id_ex_op1_i,        // ID/EX 级原始操作数 1
    input  wire [31:0] id_ex_op2_i,        // ID/EX 级原始操作数 2
    input  wire [31:0] id_ex_base_addr_i,  // ID/EX 级原始访存基地址
    input  wire [31:0] id_ex_addr_offset_i,// ID/EX 级地址偏移量

    // =================================================================
    // 2. EX/MEM1 级前递源 (上 1 条指令)
    // =================================================================
    input  wire [4:0]  ex_mem_rd_addr_i,   // EX/MEM1 目标寄存器地址
    input  wire [31:0] ex_mem_rd_data_i,   // EX/MEM1 ALU 计算结果
    input  wire        ex_mem_rd_wen_i,    // EX/MEM1 寄存器写使能
    input  wire        ex_mem_is_load_i,   // EX/MEM1 是否为 Load (Load 不可前递)

    // =================================================================
    // 3. MEM1/MEM2 级前递源 (上 2 条指令)
    // =================================================================
    input  wire [4:0]  mem1_mem2_rd_addr_i,// MEM1/MEM2 目标寄存器地址
    input  wire [31:0] mem1_mem2_rd_data_i,// MEM1/MEM2 数据
    input  wire        mem1_mem2_rd_wen_i, // MEM1/MEM2 寄存器写使能

    // =================================================================
    // 4. MEM2/WB 级前递源 (上 3 条指令)
    // =================================================================
    input  wire [4:0]  mem_wb_rd_addr_i,   // MEM2/WB 目标寄存器地址
    input  wire [31:0] mem_wb_rd_data_i,   // MEM2/WB 写回数据 (含 Load 结果)
    input  wire        mem_wb_rd_wen_i,    // MEM2/WB 寄存器写使能

    // =================================================================
    // 5. 前递修正后的输出 (送入 EX 级)
    // =================================================================
    output reg  [31:0] fwd_op1_o,          // 前递后的操作数 1
    output reg  [31:0] fwd_op2_o,          // 前递后的操作数 2
    output reg  [31:0] fwd_base_addr_o,    // 前递后的访存基地址
    output reg  [31:0] fwd_addr_offset_o   // 地址偏移量 (直接透传，不需前递)
);

    // =================================================================
    // 从指令中提取 rs1、rs2 和 opcode
    // =================================================================
    wire [6:0] opcode = id_ex_inst_i[6:0];     // 操作码
    wire [4:0] rs1    = id_ex_inst_i[19:15];   // 源寄存器 1 索引
    wire [4:0] rs2    = id_ex_inst_i[24:20];   // 源寄存器 2 索引

    // =================================================================
    // 判断当前指令是否使用 rs1 / rs2 / base_addr
    // 避免对不使用该寄存器的指令做无效前递
    // =================================================================
    // 使用 rs1 的指令: I / R / B / L / S / JALR
    wire use_rs1 = (opcode == `INST_TYPE_I)  ||
                   (opcode == `INST_TYPE_R_M) ||
                   (opcode == `INST_TYPE_B)  ||
                   (opcode == `INST_TYPE_L)  ||
                   (opcode == `INST_TYPE_S)  ||
                   (opcode == `INST_JALR);

    // 使用 rs2 的指令: R / B / S
    wire use_rs2 = (opcode == `INST_TYPE_R_M) ||
                   (opcode == `INST_TYPE_B)  ||
                   (opcode == `INST_TYPE_S);

    // 基地址依赖 rs1 的指令: L / S / JALR
    wire use_base_addr = (opcode == `INST_TYPE_L) ||
                         (opcode == `INST_TYPE_S) ||
                         (opcode == `INST_JALR);

    // =================================================================
    // 前递选择逻辑 (纯组合逻辑)
    // =================================================================
    always @(*) begin

        // ----- 操作数 1 (rs1) 前递 -----
        if (use_rs1 && (rs1 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs1) && !ex_mem_is_load_i) begin
            fwd_op1_o = ex_mem_rd_data_i;          // ① EX/MEM1 → EX (非 Load)
        end
        else if (use_rs1 && (rs1 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs1)) begin
            fwd_op1_o = mem1_mem2_rd_data_i;       // ② MEM1/MEM2 → EX
        end
        else if (use_rs1 && (rs1 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs1)) begin
            fwd_op1_o = mem_wb_rd_data_i;          // ③ MEM2/WB → EX
        end
        else begin
            fwd_op1_o = id_ex_op1_i;               // ④ 无相关: 原样透传
        end

        // ----- 操作数 2 (rs2) 前递 -----
        if (use_rs2 && (rs2 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs2) && !ex_mem_is_load_i) begin
            fwd_op2_o = ex_mem_rd_data_i;          // ① EX/MEM1 → EX (非 Load)
        end
        else if (use_rs2 && (rs2 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs2)) begin
            fwd_op2_o = mem1_mem2_rd_data_i;       // ② MEM1/MEM2 → EX
        end
        else if (use_rs2 && (rs2 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs2)) begin
            fwd_op2_o = mem_wb_rd_data_i;          // ③ MEM2/WB → EX
        end
        else begin
            fwd_op2_o = id_ex_op2_i;               // ④ 无相关: 原样透传
        end

        // ----- 访存基地址 (base_addr) 前递 -----
        // Load/Store/JALR 的 base_addr 来自 rs1，需单独做前递检测
        if (use_base_addr && (rs1 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs1) && !ex_mem_is_load_i) begin
            fwd_base_addr_o = ex_mem_rd_data_i;    // ① EX/MEM1 → EX (非 Load)
        end
        else if (use_base_addr && (rs1 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs1)) begin
            fwd_base_addr_o = mem1_mem2_rd_data_i; // ② MEM1/MEM2 → EX
        end
        else if (use_base_addr && (rs1 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs1)) begin
            fwd_base_addr_o = mem_wb_rd_data_i;    // ③ MEM2/WB → EX
        end
        else begin
            fwd_base_addr_o = id_ex_base_addr_i;   // ④ 无相关: 原样透传
        end

        // ----- 地址偏移量: 来自立即数，不依赖寄存器，直接透传 -----
        fwd_addr_offset_o = id_ex_addr_offset_i;

    end

endmodule
