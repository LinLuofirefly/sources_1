// =============================================================================
// 文件名: ex_mem1.v
// 功  能: EX/MEM1 流水线寄存器 (执行级 → 访存级 1)
// 说  明: 在执行级 (EX) 和第一访存级 (MEM1) 之间保存所有信号。
//         EX 级的计算结果、内存访问控制信号等在此打一拍后传递给 MEM1。
//
//         本级支持 Hold (冻结) 控制，但在当前设计中不使用 (hold_flag_i=0)。
//         不支持 Flush，因为跳转冲刷只影响 IF/ID 和 ID/EX 级。
// =============================================================================

`include "defines.v"

module ex_mem1 (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire        hold_flag_i,        // 冻结信号 (当前不使用，恒为 0)

    // --- 从 EX 级接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码 (透传用于后续级解析)
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // ALU 计算结果
    input  wire        rd_wen_i,           // 寄存器写使能
    input  wire [31:0] mem_rd_addr_i,      // 内存读地址 (Load)
    input  wire [3:0]  mem_wd_reg_i,       // 内存写掩码 (Store: 字节使能)
    input  wire [31:0] mem_wd_addr_i,      // 内存写地址 (Store)
    input  wire [31:0] mem_wd_data_i,      // 内存写数据 (Store)
    input  wire        is_load_i,          // Load 标记

    // --- 打一拍后输出给 MEM1 级 ---
    output wire [31:0] inst_o,             // 指令机器码
    output wire [4:0]  rd_addr_o,          // 写回目标寄存器地址
    output wire [31:0] rd_data_o,          // ALU 计算结果
    output wire        rd_wen_o,           // 寄存器写使能
    output wire [31:0] mem_rd_addr_o,      // 内存读地址 (Load)
    output wire [3:0]  mem_wd_reg_o,       // 内存写掩码 (Store)
    output wire [31:0] mem_wd_addr_o,      // 内存写地址 (Store)
    output wire [31:0] mem_wd_data_o,      // 内存写数据 (Store)
    output wire        is_load_o           // Load 标记
);

    // 每个信号使用独立的 dff_set 实例打拍
    // flush_flag 固定为 0 (本级不需要冲刷)
    dff_set #(5)  dff_rd_addr    (clk, rst, hold_flag_i, 1'b0, 5'b0,      rd_addr_i,     rd_addr_o);
    dff_set #(32) dff_rd_data    (clk, rst, hold_flag_i, 1'b0, 32'b0,     rd_data_i,     rd_data_o);
    dff_set #(1)  dff_rd_wen     (clk, rst, hold_flag_i, 1'b0, 1'b0,      rd_wen_i,      rd_wen_o);
    dff_set #(4)  dff_mem_wd_reg (clk, rst, hold_flag_i, 1'b0, 4'b0,      mem_wd_reg_i,  mem_wd_reg_o);
    dff_set #(32) dff_mem_wd_addr(clk, rst, hold_flag_i, 1'b0, 32'b0,     mem_wd_addr_i, mem_wd_addr_o);
    dff_set #(32) dff_mem_wd_data(clk, rst, hold_flag_i, 1'b0, 32'b0,     mem_wd_data_i, mem_wd_data_o);
    dff_set #(1)  dff_is_load    (clk, rst, hold_flag_i, 1'b0, 1'b0,      is_load_i,     is_load_o);
    dff_set #(32) dff_inst       (clk, rst, hold_flag_i, 1'b0, `INST_NOP, inst_i,        inst_o);
    dff_set #(32) dff_mem_rd_addr(clk, rst, hold_flag_i, 1'b0, 32'b0,     mem_rd_addr_i, mem_rd_addr_o);

endmodule