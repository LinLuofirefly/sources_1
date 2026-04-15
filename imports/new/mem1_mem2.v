// =============================================================================
// 文件名: mem1_mem2.v
// 功  能: MEM1/MEM2 流水线寄存器 (访存级 1 → 访存级 2)
// 说  明: 在 MEM1 和 MEM2 之间保存信号。
//         MEM1 发起 RAM 读请求后，需要等待 1 个时钟周期才能获得读数据，
//         因此通过此流水线寄存器将控制信号延迟 1 拍，与 RAM 读数据同步。
//
//         本级支持 Hold 和 Flush 控制，但在当前设计中均不使用。
// =============================================================================

`include "defines.v"

module mem1_mem2 (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire        hold_flag_i,        // 冻结信号 (当前不使用，恒为 0)
    input  wire        flush_flag_i,       // 冲刷信号 (当前不使用，恒为 0)

    // --- 从 MEM1 级接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // ALU 计算结果
    input  wire        rd_wen_i,           // 寄存器写使能
    input  wire [31:0] mem_rd_addr_i,      // 内存读地址 (含字节偏移信息)
    input  wire        is_load_i,          // Load 标记

    // --- 打一拍后输出给 MEM2 级 ---
    output wire [31:0] inst_o,             // 指令机器码
    output wire [4:0]  rd_addr_o,          // 写回目标寄存器地址
    output wire [31:0] rd_data_o,          // ALU 计算结果
    output wire        rd_wen_o,           // 寄存器写使能
    output wire [31:0] mem_rd_addr_o,      // 内存读地址 (MEM2 级用于字节选择)
    output wire        is_load_o           // Load 标记
);

    // 每个信号使用独立的 dff_set 实例打拍
    dff_set #(32) dff_inst       (clk, rst, hold_flag_i, flush_flag_i, `INST_NOP, inst_i,        inst_o);
    dff_set #(32) dff_rd_data    (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     rd_data_i,     rd_data_o);
    dff_set #(5)  dff_rd_addr    (clk, rst, hold_flag_i, flush_flag_i, 5'b0,      rd_addr_i,     rd_addr_o);
    dff_set #(1)  dff_rd_wen     (clk, rst, hold_flag_i, flush_flag_i, 1'b0,      rd_wen_i,      rd_wen_o);
    dff_set #(32) dff_mem_rd_addr(clk, rst, hold_flag_i, flush_flag_i, 32'b0,     mem_rd_addr_i, mem_rd_addr_o);
    dff_set #(1)  dff_is_load    (clk, rst, hold_flag_i, flush_flag_i, 1'b0,      is_load_i,     is_load_o);

endmodule
