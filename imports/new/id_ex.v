// =============================================================================
// 文件名: id_ex.v
// 功  能: ID/EX 流水线寄存器 (译码级 → 执行级)
// 说  明: 在译码级 (ID) 和执行级 (EX) 之间保存操作数和控制信号。
//
//         控制行为:
//         - Stall (hold_flag_i=1): 本级一般不使用冻结 (保留接口)
//         - Flush (flush_flag_i=1): 清空本级，插入 NOP 气泡
//           触发条件: Load-Use 冒险 或 跳转指令
//
//         使用 dff_set 通用触发器实现每个信号的打拍和控制。
// =============================================================================

`include "defines.v"

module id_ex (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire        hold_flag_i,        // 冻结信号 (本级不使用，保留接口)
    input  wire        flush_flag_i,       // 冲刷信号: Load-Use 或跳转时清空

    // --- 从 ID 级接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码
    input  wire [31:0] inst_addr_i,        // 指令 PC 地址
    input  wire [31:0] op1_i,              // ALU 操作数 1
    input  wire [31:0] op2_i,              // ALU 操作数 2
    input  wire [4:0]  rd_addr_i,          // 目标寄存器地址
    input  wire        reg_wen_i,          // 寄存器写使能
    input  wire [31:0] base_addr_i,        // 访存/跳转基地址
    input  wire [31:0] addr_offset_i,      // 地址偏移量

    // --- 打一拍后输出给 EX 级 ---
    output wire [31:0] inst_o,             // 指令机器码
    output wire [31:0] inst_addr_o,        // 指令 PC 地址
    output wire [31:0] op1_o,              // ALU 操作数 1
    output wire [31:0] op2_o,              // ALU 操作数 2
    output wire [4:0]  rd_addr_o,          // 目标寄存器地址
    output wire        reg_wen_o,          // 寄存器写使能
    output wire [31:0] base_addr_o,        // 访存/跳转基地址
    output wire [31:0] addr_offset_o       // 地址偏移量
);

    // 时序优化:
    // 仅对 inst/reg_wen 使用 flush 以插入气泡并屏蔽副作用，
    // 其余宽数据总线不参与 flush 组合，降低关键路径负担。
    dff_set #(32) dff_inst        (clk, rst, hold_flag_i, flush_flag_i, `INST_NOP, inst_i,        inst_o);
    dff_set #(32) dff_inst_addr   (clk, rst, hold_flag_i, 1'b0,        32'b0,     inst_addr_i,   inst_addr_o);
    dff_set #(32) dff_op1         (clk, rst, hold_flag_i, 1'b0,        32'b0,     op1_i,         op1_o);
    dff_set #(32) dff_op2         (clk, rst, hold_flag_i, 1'b0,        32'b0,     op2_i,         op2_o);
    dff_set #(5)  dff_rd_addr     (clk, rst, hold_flag_i, 1'b0,        5'b0,      rd_addr_i,     rd_addr_o);
    dff_set #(1)  dff_reg_wen     (clk, rst, hold_flag_i, flush_flag_i, 1'b0,      reg_wen_i,     reg_wen_o);
    dff_set #(32) dff_base_addr   (clk, rst, hold_flag_i, 1'b0,        32'b0,     base_addr_i,   base_addr_o);
    dff_set #(32) dff_addr_offset (clk, rst, hold_flag_i, 1'b0,        32'b0,     addr_offset_i, addr_offset_o);

endmodule