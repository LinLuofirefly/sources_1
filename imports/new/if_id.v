`include "defines.v"

module if_id (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire        pred_taken_i,
    input  wire        raw_pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [8:0]  pred_ghr_i,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,
    output reg  [31:0] inst_addr_o,
    output reg         pred_taken_o,
    output reg         raw_pred_taken_o,
    output reg  [31:0] pred_target_o,
    output reg  [8:0]  pred_ghr_o,
    output reg  [31:0] inst_o,
    output wire        replaying_o
);

    reg [31:0] hold_inst_reg;
    reg [31:0] hold_inst_addr_reg;
    reg        hold_pred_taken_reg;
    reg        hold_raw_pred_taken_reg;
    reg [31:0] hold_pred_target_reg;
    reg [8:0]  hold_pred_ghr_reg;
    reg        is_holding_reg;

    assign replaying_o = is_holding_reg;

    always @(posedge clk) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            hold_inst_reg           <= 32'b0;
            hold_inst_addr_reg      <= 32'b0;
            hold_pred_taken_reg     <= 1'b0;
            hold_raw_pred_taken_reg <= 1'b0;
            hold_pred_target_reg    <= 32'b0;
            hold_pred_ghr_reg       <= 9'b0;
            is_holding_reg          <= 1'b0;
        end else if (hold_flag_i == 1'b1 && is_holding_reg == 1'b0) begin
            hold_inst_reg           <= inst_i;
            hold_inst_addr_reg      <= inst_addr_i;
            hold_pred_taken_reg     <= pred_taken_i;
            hold_raw_pred_taken_reg <= raw_pred_taken_i;
            hold_pred_target_reg    <= pred_target_i;
            hold_pred_ghr_reg       <= pred_ghr_i;
            is_holding_reg          <= 1'b1;
        end else if (hold_flag_i == 1'b0) begin
            is_holding_reg <= 1'b0;
        end
    end

    always @(*) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            inst_addr_o = 32'b0;
            inst_o = `INST_NOP;
            pred_taken_o = 1'b0;
            raw_pred_taken_o = 1'b0;
            pred_target_o = 32'b0;
            pred_ghr_o = 9'b0;
        end else if (is_holding_reg == 1'b1) begin
            inst_addr_o = hold_inst_addr_reg;
            inst_o = hold_inst_reg;
            pred_taken_o = hold_pred_taken_reg;
            raw_pred_taken_o = hold_raw_pred_taken_reg;
            pred_target_o = hold_pred_target_reg;
            pred_ghr_o = hold_pred_ghr_reg;
        end else begin
            inst_addr_o = inst_addr_i;
            inst_o = inst_i;
            pred_taken_o = pred_taken_i;
            raw_pred_taken_o = raw_pred_taken_i;
            pred_target_o = pred_target_i;
            pred_ghr_o = pred_ghr_i;
        end
    end

endmodule
