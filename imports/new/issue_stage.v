`include "defines.v"

module issue_stage (
    input  wire        clk,
    input  wire        rst,
    input  wire        flush_i,
    input  wire        issue_can_go_ex_i,
    input  wire        in_valid_i,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    input  wire        pred_taken_i,
    input  wire        raw_pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [8:0]  pred_ghr_i,
    input  wire [4:0]  rd_addr_i,
    input  wire        reg_wen_i,
    input  wire [31:0] base_addr_i,
    input  wire [31:0] addr_offset_i,
    input  wire [14:0] ctrl_flags_i,
    output wire        issue_ready_o,
    output wire        issue_fire_o,
    output reg         issue_valid_o,
    output reg  [31:0] inst_o,
    output reg  [31:0] inst_addr_o,
    output reg  [31:0] op1_o,
    output reg  [31:0] op2_o,
    output reg         pred_taken_o,
    output reg         raw_pred_taken_o,
    output reg  [31:0] pred_target_o,
    output reg  [8:0]  pred_ghr_o,
    output reg  [4:0]  rd_addr_o,
    output reg         reg_wen_o,
    output reg  [31:0] base_addr_o,
    output reg  [31:0] addr_offset_o,
    output reg  [14:0] ctrl_flags_o
);

    assign issue_ready_o = (~issue_valid_o) | issue_can_go_ex_i;
    assign issue_fire_o  = issue_valid_o & issue_can_go_ex_i;

    always @(posedge clk) begin
        if (rst == 1'b0 || flush_i == 1'b1) begin
            issue_valid_o    <= 1'b0;
            inst_o           <= `INST_NOP;
            inst_addr_o      <= 32'b0;
            op1_o            <= 32'b0;
            op2_o            <= 32'b0;
            pred_taken_o     <= 1'b0;
            raw_pred_taken_o <= 1'b0;
            pred_target_o    <= 32'b0;
            pred_ghr_o       <= 9'b0;
            rd_addr_o        <= 5'b0;
            reg_wen_o        <= 1'b0;
            base_addr_o      <= 32'b0;
            addr_offset_o    <= 32'b0;
            ctrl_flags_o     <= 15'b0;
        end else if (issue_ready_o) begin
            issue_valid_o    <= in_valid_i;
            inst_o           <= in_valid_i ? inst_i : `INST_NOP;
            inst_addr_o      <= in_valid_i ? inst_addr_i : 32'b0;
            op1_o            <= in_valid_i ? op1_i : 32'b0;
            op2_o            <= in_valid_i ? op2_i : 32'b0;
            pred_taken_o     <= in_valid_i ? pred_taken_i : 1'b0;
            raw_pred_taken_o <= in_valid_i ? raw_pred_taken_i : 1'b0;
            pred_target_o    <= in_valid_i ? pred_target_i : 32'b0;
            pred_ghr_o       <= in_valid_i ? pred_ghr_i : 9'b0;
            rd_addr_o        <= in_valid_i ? rd_addr_i : 5'b0;
            reg_wen_o        <= in_valid_i ? reg_wen_i : 1'b0;
            base_addr_o      <= in_valid_i ? base_addr_i : 32'b0;
            addr_offset_o    <= in_valid_i ? addr_offset_i : 32'b0;
            ctrl_flags_o     <= in_valid_i ? ctrl_flags_i : 15'b0;
        end
    end

endmodule
