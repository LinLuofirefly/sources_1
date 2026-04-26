`include "defines.v"

module if_id (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire        pred_taken_i,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,
    output reg  [31:0] inst_addr_o,
    output reg         pred_taken_o,
    output reg  [31:0] inst_o,
    output wire        replaying_o
);

    reg [31:0] hold_inst_reg;
    reg [31:0] hold_inst_addr_reg;
    reg        hold_pred_taken_reg;
    reg        is_holding_reg;

    assign replaying_o = is_holding_reg;

    always @(posedge clk) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            hold_inst_reg       <= 32'b0;
            hold_inst_addr_reg  <= 32'b0;
            hold_pred_taken_reg <= 1'b0;
            is_holding_reg      <= 1'b0;
        end else if (hold_flag_i == 1'b1 && is_holding_reg == 1'b0) begin
            hold_inst_reg       <= inst_i;
            hold_inst_addr_reg  <= inst_addr_i;
            hold_pred_taken_reg <= pred_taken_i;
            is_holding_reg      <= 1'b1;
        end else if (hold_flag_i == 1'b0) begin
            is_holding_reg <= 1'b0;
        end
    end

    always @(*) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            inst_addr_o = 32'b0;
            inst_o = `INST_NOP;
            pred_taken_o = 1'b0;
        end else if (is_holding_reg == 1'b1) begin
            inst_addr_o = hold_inst_addr_reg;
            inst_o = hold_inst_reg;
            pred_taken_o = hold_pred_taken_reg;
        end else begin
            inst_addr_o = inst_addr_i;
            inst_o = inst_i;
            pred_taken_o = pred_taken_i;
        end
    end

endmodule
