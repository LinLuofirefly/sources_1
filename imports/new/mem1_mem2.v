`include "defines.v"

module mem1_mem2 (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire        is_load_i,
    input  wire        load_hits_dram_i,
    input  wire        bp_update_en_i,
    input  wire [31:0] bp_update_pc_i,
    input  wire [8:0]  bp_update_ghr_i,
    input  wire        bp_ras_push_en_i,
    input  wire        bp_ras_pop_en_i,
    input  wire [31:0] bp_ras_push_addr_i,
    input  wire        bp_actual_taken_i,
    output wire [31:0] inst_o,
    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o,
    output wire [31:0] mem_rd_addr_o,
    output wire        is_load_o,
    output wire        load_hits_dram_o,
    output wire        bp_update_en_o,
    output wire [31:0] bp_update_pc_o,
    output wire [8:0]  bp_update_ghr_o,
    output wire        bp_ras_push_en_o,
    output wire        bp_ras_pop_en_o,
    output wire [31:0] bp_ras_push_addr_o,
    output wire        bp_actual_taken_o
);

    dff_set #(32) dff_inst            (clk, rst, 1'b0, 1'b0, `INST_NOP, inst_i,            inst_o);
    dff_set #(32) dff_rd_data         (clk, rst, 1'b0, 1'b0, 32'b0,     rd_data_i,         rd_data_o);
    dff_set #(5)  dff_rd_addr         (clk, rst, 1'b0, 1'b0, 5'b0,      rd_addr_i,         rd_addr_o);
    dff_set #(1)  dff_rd_wen          (clk, rst, 1'b0, 1'b0, 1'b0,      rd_wen_i,          rd_wen_o);
    dff_set #(32) dff_mem_rd_addr     (clk, rst, 1'b0, 1'b0, 32'b0,     mem_rd_addr_i,     mem_rd_addr_o);
    dff_set #(1)  dff_is_load         (clk, rst, 1'b0, 1'b0, 1'b0,      is_load_i,         is_load_o);
    dff_set #(1)  dff_load_hits_dram  (clk, rst, 1'b0, 1'b0, 1'b0,      load_hits_dram_i,  load_hits_dram_o);
    dff_set #(1)  dff_bp_update_en    (clk, rst, 1'b0, 1'b0, 1'b0,      bp_update_en_i,    bp_update_en_o);
    dff_set #(32) dff_bp_update_pc    (clk, rst, 1'b0, 1'b0, 32'b0,     bp_update_pc_i,    bp_update_pc_o);
    dff_set #(9)  dff_bp_update_ghr   (clk, rst, 1'b0, 1'b0, 9'b0,      bp_update_ghr_i,   bp_update_ghr_o);
    dff_set #(1)  dff_bp_ras_push_en  (clk, rst, 1'b0, 1'b0, 1'b0,      bp_ras_push_en_i,  bp_ras_push_en_o);
    dff_set #(1)  dff_bp_ras_pop_en   (clk, rst, 1'b0, 1'b0, 1'b0,      bp_ras_pop_en_i,   bp_ras_pop_en_o);
    dff_set #(32) dff_bp_ras_push_addr(clk, rst, 1'b0, 1'b0, 32'b0,     bp_ras_push_addr_i, bp_ras_push_addr_o);
    dff_set #(1)  dff_bp_actual_taken (clk, rst, 1'b0, 1'b0, 1'b0,      bp_actual_taken_i, bp_actual_taken_o);

endmodule
