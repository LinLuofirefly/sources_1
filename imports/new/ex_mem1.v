`include "defines.v"

module ex_mem1 (
    input  wire        clk,
    input  wire        rst,
    input  wire        hold_flag_i,
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire [3:0]  mem_wd_reg_i,
    input  wire [31:0] mem_wd_addr_i,
    input  wire [31:0] mem_wd_data_i,
    input  wire        is_load_i,
    output wire [31:0] inst_o,
    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o,
    output wire [31:0] mem_rd_addr_o,
    output wire [3:0]  mem_wd_reg_o,
    output wire [31:0] mem_wd_addr_o,
    output wire [31:0] mem_wd_data_o,
    output wire        is_load_o
);

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
