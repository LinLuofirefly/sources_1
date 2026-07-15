`timescale 1ns / 1ps
`include "defines.v"
// ============================================================================
// EX/MEM1 流水线寄存器
// ----------------------------------------------------------------------------
// 将 EX 结果推进到第一访存级，包含：
//   - 写回 rd 信息和 ALU/load 地址；
//   - store 写掩码/地址/数据；
//   - load 是否命中 DRAM 区域、store-load 前递信息；
//   - 分支预测器更新和 RAS 更新信息。
// ============================================================================
module ex_mem1 (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire [3:0]  mem_wd_reg_i,
    input  wire [31:0] mem_wd_addr_i,
    input  wire [31:0] mem_wd_data_i,
    input  wire        is_load_i,
    input  wire        load_hits_dram_i,
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
    output reg  [31:0] inst_o,
    output reg  [4:0]  rd_addr_o,
    output reg  [31:0] rd_data_o,
    output reg         rd_wen_o,
    output reg  [31:0] mem_rd_addr_o,
    output reg  [3:0]  mem_wd_reg_o,
    output reg  [31:0] mem_wd_addr_o,
    output reg  [31:0] mem_wd_data_o,
    output reg         is_load_o,
    output reg         load_hits_dram_o,
    output reg         store_load_fwd_valid_o,
    output reg  [3:0]  store_load_fwd_wstrb_o,
    output reg  [31:0] store_load_fwd_data_o,
    output reg         bp_update_en_o,
    output reg  [31:0] bp_update_pc_o,
    output reg  [31:0] bp_update_target_o,
    output reg  [`BP_GHR_WIDTH-1:0] bp_update_ghr_o,
    output reg         bp_ras_push_en_o,
    output reg         bp_ras_pop_en_o,
    output reg  [31:0] bp_ras_push_addr_o,
    output reg         bp_actual_taken_o
);

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            inst_o                 <= `INST_NOP;
            rd_addr_o              <= 5'b0;
            rd_data_o              <= 32'b0;
            rd_wen_o               <= 1'b0;
            mem_rd_addr_o          <= 32'b0;
            mem_wd_reg_o           <= 4'b0;
            mem_wd_addr_o          <= 32'b0;
            mem_wd_data_o          <= 32'b0;
            is_load_o              <= 1'b0;
            load_hits_dram_o       <= 1'b0;
            store_load_fwd_valid_o <= 1'b0;
            store_load_fwd_wstrb_o <= 4'b0;
            store_load_fwd_data_o  <= 32'b0;
            bp_update_en_o         <= 1'b0;
            bp_update_pc_o         <= 32'b0;
            bp_update_target_o     <= 32'b0;
            bp_update_ghr_o        <= {`BP_GHR_WIDTH{1'b0}};
            bp_ras_push_en_o       <= 1'b0;
            bp_ras_pop_en_o        <= 1'b0;
            bp_ras_push_addr_o     <= 32'b0;
            bp_actual_taken_o      <= 1'b0;
        end else begin
            inst_o                 <= inst_i;
            rd_addr_o              <= rd_addr_i;
            rd_data_o              <= rd_data_i;
            rd_wen_o               <= rd_wen_i;
            mem_rd_addr_o          <= mem_rd_addr_i;
            mem_wd_reg_o           <= mem_wd_reg_i;
            mem_wd_addr_o          <= mem_wd_addr_i;
            mem_wd_data_o          <= mem_wd_data_i;
            is_load_o              <= is_load_i;
            load_hits_dram_o       <= load_hits_dram_i;
            store_load_fwd_valid_o <= store_load_fwd_valid_i;
            store_load_fwd_wstrb_o <= store_load_fwd_wstrb_i;
            store_load_fwd_data_o  <= store_load_fwd_data_i;
            bp_update_en_o         <= bp_update_en_i;
            bp_update_pc_o         <= bp_update_pc_i;
            bp_update_target_o     <= bp_update_target_i;
            bp_update_ghr_o        <= bp_update_ghr_i;
            bp_ras_push_en_o       <= bp_ras_push_en_i;
            bp_ras_pop_en_o        <= bp_ras_pop_en_i;
            bp_ras_push_addr_o     <= bp_ras_push_addr_i;
            bp_actual_taken_o      <= bp_actual_taken_i;
        end
    end

endmodule
