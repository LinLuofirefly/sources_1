// =============================================================================
// 文件名: mem2_wb.v
// 功  能: MEM2/WB 流水线寄存器 (访存级 2 → 写回级)
// 说  明: 在 MEM2 和 WB 之间保存写回数据和控制信号。
//         经过此级后，数据将被写回寄存器堆。
//
//         本级支持 Hold 控制，但在当前设计中不使用 (hold_flag_i=0)。
// =============================================================================

`include "defines.v"

module mem2_wb (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire        hold_flag_i,        // 冻结信号 (当前不使用，恒为 0)

    // --- 从 MEM2 级接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码 (用于调试)
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // 写回数据 (ALU 结果或 Load 数据)
    input  wire        rd_wen_i,           // 寄存器写使能

    // --- 打一拍后输出给 WB 级 ---
    output wire [31:0] inst_o,             // 指令机器码
    output wire [4:0]  rd_addr_o,          // 写回目标寄存器地址
    output wire [31:0] rd_data_o,          // 写回数据
    output wire        rd_wen_o            // 寄存器写使能
);

    // 每个信号使用独立的 dff_set 实例打拍
    // flush_flag 固定为 0 (本级不需要冲刷)
    dff_set #(5)  dff_rd_addr (clk, rst, hold_flag_i, 1'b0, 5'b0,      rd_addr_i, rd_addr_o);
    dff_set #(32) dff_rd_data (clk, rst, hold_flag_i, 1'b0, 32'b0,     rd_data_i, rd_data_o);
    dff_set #(1)  dff_rd_wen  (clk, rst, hold_flag_i, 1'b0, 1'b0,      rd_wen_i,  rd_wen_o);
    dff_set #(32) dff_inst    (clk, rst, hold_flag_i, 1'b0, `INST_NOP,  inst_i,    inst_o);

endmodule