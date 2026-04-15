// =============================================================================
// 文件名: mem2.v
// 功  能: 第二访存级 (MEM2 - Memory Access Stage 2)
// 说  明: 在 6 级流水线中，MEM2 负责接收外部 RAM 返回的读数据，
//         并根据 Load 指令的类型 (LB/LH/LW/LBU/LHU) 完成:
//         1. 字节选择: 根据地址低位选取目标字节/半字
//         2. 符号/零扩展: 将选取的数据扩展为 32 位
//
//         对于非 Load 指令，直接透传 ALU 计算结果作为写回数据。
// =============================================================================

`include "defines.v"

module mem2 (
    // --- 从 MEM1/MEM2 流水线寄存器接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码 (用于提取 funct3)
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // ALU 计算结果 (非 Load 时的写回数据)
    input  wire        rd_wen_i,           // 寄存器写使能
    input  wire [31:0] mem_rd_addr_i,      // 内存读地址 (低位用于字节选择)
    input  wire        is_load_i,          // Load 标记 (1: 当前为 Load 指令)
    input  wire [31:0] mem_rd_data_i,      // 从外部 RAM 读取的 32 位原始数据

    // --- 输出给 MEM2/WB 流水线寄存器 ---
    output wire [31:0] inst_o,             // 透传: 指令机器码
    output wire [4:0]  rd_addr_o,          // 透传: 写回目标寄存器地址
    output reg  [31:0] rd_data_o,          // 最终写回数据 (经 Load 对齐或 ALU 结果)
    output wire        rd_wen_o            // 透传: 寄存器写使能
);

    // 提取 funct3: 用于区分 LB/LH/LW/LBU/LHU
    wire [2:0] func3 = inst_i[14:12];

    // 直接透传信号
    assign rd_addr_o = rd_addr_i;          // 写回地址透传
    assign rd_wen_o  = rd_wen_i;           // 写使能透传
    assign inst_o    = inst_i;             // 指令码透传

    // =================================================================
    // Load 数据对齐与扩展逻辑 (组合逻辑)
    // =================================================================
    always @(*) begin
        if (is_load_i) begin
            case (func3)
                // =====================================================
                // LB: 加载字节 (符号扩展)
                // 根据地址低 2 位选择 RAM 输出的哪个字节
                // =====================================================
                `INST_LB: begin
                    case (mem_rd_addr_i[1:0])
                        2'b00: rd_data_o = {{24{mem_rd_data_i[7]}},  mem_rd_data_i[7:0]};    // 字节 0
                        2'b01: rd_data_o = {{24{mem_rd_data_i[15]}}, mem_rd_data_i[15:8]};   // 字节 1
                        2'b10: rd_data_o = {{24{mem_rd_data_i[23]}}, mem_rd_data_i[23:16]};  // 字节 2
                        2'b11: rd_data_o = {{24{mem_rd_data_i[31]}}, mem_rd_data_i[31:24]};  // 字节 3
                        default: rd_data_o = 32'b0;
                    endcase
                end

                // =====================================================
                // LH: 加载半字 (符号扩展)
                // 根据地址 bit[1] 选择低半字或高半字
                // =====================================================
                `INST_LH: begin
                    case (mem_rd_addr_i[1])
                        1'b0: rd_data_o = {{16{mem_rd_data_i[15]}}, mem_rd_data_i[15:0]};   // 低半字
                        1'b1: rd_data_o = {{16{mem_rd_data_i[31]}}, mem_rd_data_i[31:16]};  // 高半字
                        default: rd_data_o = 32'b0;
                    endcase
                end

                // =====================================================
                // LW: 加载字 (32 位直接使用)
                // =====================================================
                `INST_LW: begin
                    rd_data_o = mem_rd_data_i;                     // 整字直接使用
                end

                // =====================================================
                // LBU: 加载无符号字节 (零扩展)
                // =====================================================
                `INST_LBU: begin
                    case (mem_rd_addr_i[1:0])
                        2'b00: rd_data_o = {24'b0, mem_rd_data_i[7:0]};                     // 字节 0
                        2'b01: rd_data_o = {24'b0, mem_rd_data_i[15:8]};                    // 字节 1
                        2'b10: rd_data_o = {24'b0, mem_rd_data_i[23:16]};                   // 字节 2
                        2'b11: rd_data_o = {24'b0, mem_rd_data_i[31:24]};                   // 字节 3
                        default: rd_data_o = 32'b0;
                    endcase
                end

                // =====================================================
                // LHU: 加载无符号半字 (零扩展)
                // =====================================================
                `INST_LHU: begin
                    case (mem_rd_addr_i[1])
                        1'b0: rd_data_o = {16'b0, mem_rd_data_i[15:0]};                    // 低半字
                        1'b1: rd_data_o = {16'b0, mem_rd_data_i[31:16]};                   // 高半字
                        default: rd_data_o = 32'b0;
                    endcase
                end

                default: rd_data_o = 32'b0;
            endcase
        end else begin
            // 非 Load 指令: 直接使用 EX 级传来的 ALU 结果
            rd_data_o = rd_data_i;
        end
    end

endmodule