`timescale 1ns / 1ps
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
    input  wire        load_cache_hit_i,
    input  wire        store_load_fwd_valid_i,
    input  wire [3:0]  store_load_fwd_wstrb_i,
    input  wire [31:0] store_load_fwd_data_i,
    input  wire        bp_update_en_i,
    input  wire [31:0] bp_update_pc_i,
    input  wire [31:0] bp_update_target_i,
    input  wire [`BP_GHR_WIDTH-1:0] bp_update_ghr_i,
    input  wire        bp_ras_push_en_i,
    input  wire        bp_ras_pop_en_i,
    input  wire [31:0] bp_ras_push_addr_i,
    input  wire        bp_actual_taken_i,
    // Do not force max_fanout on wide datapath buses.
    // Excessive register replication can worsen physical routing timing.
    output wire [31:0] inst_o,
    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o,
    output wire [31:0] mem_rd_addr_o,
    output wire        is_load_o,
    output wire        load_hits_dram_o,
    output wire        load_cache_hit_o,
    output wire        store_load_fwd_valid_o,
    output wire [3:0]  store_load_fwd_wstrb_o,
    output wire [31:0] store_load_fwd_data_o,
    output wire        bp_update_en_o,
    output wire [31:0] bp_update_pc_o,
    output wire [31:0] bp_update_target_o,
    output wire [`BP_GHR_WIDTH-1:0] bp_update_ghr_o,
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
    dff_set #(1)  dff_load_cache_hit  (clk, rst, 1'b0, 1'b0, 1'b0,      load_cache_hit_i,  load_cache_hit_o);
    dff_set #(1)  dff_store_load_fwd_valid(clk, rst, 1'b0, 1'b0, 1'b0,   store_load_fwd_valid_i, store_load_fwd_valid_o);
    dff_set #(4)  dff_store_load_fwd_wstrb(clk, rst, 1'b0, 1'b0, 4'b0,   store_load_fwd_wstrb_i, store_load_fwd_wstrb_o);
    dff_set #(32) dff_store_load_fwd_data (clk, rst, 1'b0, 1'b0, 32'b0,  store_load_fwd_data_i, store_load_fwd_data_o);
    dff_set #(1)  dff_bp_update_en    (clk, rst, 1'b0, 1'b0, 1'b0,      bp_update_en_i,    bp_update_en_o);
    dff_set #(32) dff_bp_update_pc    (clk, rst, 1'b0, 1'b0, 32'b0,     bp_update_pc_i,    bp_update_pc_o);
    dff_set #(32) dff_bp_update_target(clk, rst, 1'b0, 1'b0, 32'b0,     bp_update_target_i, bp_update_target_o);
    dff_set #(`BP_GHR_WIDTH) dff_bp_update_ghr(clk, rst, 1'b0, 1'b0, {`BP_GHR_WIDTH{1'b0}}, bp_update_ghr_i, bp_update_ghr_o);
    dff_set #(1)  dff_bp_ras_push_en  (clk, rst, 1'b0, 1'b0, 1'b0,      bp_ras_push_en_i,  bp_ras_push_en_o);
    dff_set #(1)  dff_bp_ras_pop_en   (clk, rst, 1'b0, 1'b0, 1'b0,      bp_ras_pop_en_i,   bp_ras_pop_en_o);
    dff_set #(32) dff_bp_ras_push_addr(clk, rst, 1'b0, 1'b0, 32'b0,     bp_ras_push_addr_i, bp_ras_push_addr_o);
    dff_set #(1)  dff_bp_actual_taken (clk, rst, 1'b0, 1'b0, 1'b0,      bp_actual_taken_i, bp_actual_taken_o);

endmodule
