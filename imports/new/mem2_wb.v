`timescale 1ns / 1ps
`include "defines.v"

// ============================================================================
// MEM2/WB 流水线寄存器
// ----------------------------------------------------------------------------
// 保存进入写回级的数据，同时额外复制一组 forwarding 专用输出。
// forwarding 输出禁止等价寄存器删除，目的是让综合器保留离转发网络更近的副本，
// 降低 MEM/WB 到 EX 转发路径的布线压力。
// ============================================================================
module mem2_wb (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire        is_slow_load_i,
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
    output reg         is_slow_load_o,
    output reg         bp_update_en_o,
    output reg  [31:0] bp_update_pc_o,
    output reg  [31:0] bp_update_target_o,
    output reg  [`BP_GHR_WIDTH-1:0] bp_update_ghr_o,
    output reg         bp_ras_push_en_o,
    output reg         bp_ras_pop_en_o,
    output reg  [31:0] bp_ras_push_addr_o,
    output reg         bp_actual_taken_o,
    (* equivalent_register_removal = "no" *) output reg [4:0]  rd_addr_fwd_o,
    (* equivalent_register_removal = "no" *) output reg [31:0] rd_data_fwd_o,
    (* equivalent_register_removal = "no" *) output reg        rd_wen_fwd_o,
    (* equivalent_register_removal = "no" *) output reg        is_slow_load_fwd_o
);

always @(posedge clk) begin
    if (rst == 1'b0) begin
        rd_addr_fwd_o      <= 5'b0;
        rd_data_fwd_o      <= 32'b0;
        rd_wen_fwd_o       <= 1'b0;
        is_slow_load_fwd_o <= 1'b0;
    end else begin
        rd_addr_fwd_o      <= rd_addr_i;
        rd_data_fwd_o      <= rd_data_i;
        rd_wen_fwd_o       <= rd_wen_i;
        is_slow_load_fwd_o <= is_slow_load_i;
    end
end

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            inst_o             <= `INST_NOP;
            rd_addr_o          <= 5'b0;
            rd_data_o          <= 32'b0;
            rd_wen_o           <= 1'b0;
            mem_rd_addr_o      <= 32'b0;
            is_slow_load_o     <= 1'b0;
            bp_update_en_o     <= 1'b0;
            bp_update_pc_o     <= 32'b0;
            bp_update_target_o <= 32'b0;
            bp_update_ghr_o    <= {`BP_GHR_WIDTH{1'b0}};
            bp_ras_push_en_o   <= 1'b0;
            bp_ras_pop_en_o    <= 1'b0;
            bp_ras_push_addr_o <= 32'b0;
            bp_actual_taken_o  <= 1'b0;
        end else begin
            inst_o             <= inst_i;
            rd_addr_o          <= rd_addr_i;
            rd_data_o          <= rd_data_i;
            rd_wen_o           <= rd_wen_i;
            mem_rd_addr_o      <= mem_rd_addr_i;
            is_slow_load_o     <= is_slow_load_i;
            bp_update_en_o     <= bp_update_en_i;
            bp_update_pc_o     <= bp_update_pc_i;
            bp_update_target_o <= bp_update_target_i;
            bp_update_ghr_o    <= bp_update_ghr_i;
            bp_ras_push_en_o   <= bp_ras_push_en_i;
            bp_ras_pop_en_o    <= bp_ras_pop_en_i;
            bp_ras_push_addr_o <= bp_ras_push_addr_i;
            bp_actual_taken_o  <= bp_actual_taken_i;
        end
    end

endmodule
