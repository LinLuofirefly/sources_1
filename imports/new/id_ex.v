`include "defines.v"

module id_ex (
    input  wire        clk,
    input  wire        rst,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    input  wire        pred_taken_i,
    input  wire [4:0]  rd_addr_i,
    input  wire        reg_wen_i,
    input  wire [31:0] base_addr_i,
    input  wire [31:0] addr_offset_i,
    input  wire [14:0] ctrl_flags_i,
    output wire [31:0] inst_o,
    output wire [31:0] inst_addr_o,
    output wire [31:0] op1_o,
    output wire [31:0] op2_o,
    output wire        pred_taken_o,
    output wire [4:0]  rd_addr_o,
    output wire        reg_wen_o,
    output wire [31:0] base_addr_o,
    output wire [31:0] addr_offset_o,
    output wire [14:0] ctrl_flags_o
);

    dff_set #(32) dff_inst        (clk, rst, hold_flag_i, flush_flag_i, `INST_NOP, inst_i,        inst_o);
    dff_set #(32) dff_inst_addr   (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     inst_addr_i,   inst_addr_o);
    dff_set #(32) dff_op1         (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     op1_i,         op1_o);
    dff_set #(32) dff_op2         (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     op2_i,         op2_o);
    dff_set #(1)  dff_pred_taken  (clk, rst, hold_flag_i, flush_flag_i, 1'b0,      pred_taken_i,  pred_taken_o);
    dff_set #(5)  dff_rd_addr     (clk, rst, hold_flag_i, flush_flag_i, 5'b0,      rd_addr_i,     rd_addr_o);
    dff_set #(1)  dff_reg_wen     (clk, rst, hold_flag_i, flush_flag_i, 1'b0,      reg_wen_i,     reg_wen_o);
    dff_set #(32) dff_base_addr   (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     base_addr_i,   base_addr_o);
    dff_set #(32) dff_addr_offset (clk, rst, hold_flag_i, flush_flag_i, 32'b0,     addr_offset_i, addr_offset_o);
    dff_set #(15) dff_ctrl_flags  (clk, rst, hold_flag_i, flush_flag_i, 15'b0,     ctrl_flags_i,  ctrl_flags_o);

endmodule
