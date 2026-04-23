`include "defines.v"

module if_id (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,
    output wire [31:0] inst_addr_o,
    output reg  [31:0] inst_o
);

    reg [31:0] hold_inst_reg;
    reg        is_holding_reg;

    always @(posedge clk) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            hold_inst_reg  <= 32'b0;
            is_holding_reg <= 1'b0;
        end else if (hold_flag_i == 1'b1 && is_holding_reg == 1'b0) begin
            hold_inst_reg  <= inst_i;
            is_holding_reg <= 1'b1;
        end else if (hold_flag_i == 1'b0) begin
            is_holding_reg <= 1'b0;
        end
    end

    always @(*) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            inst_o = `INST_NOP;
        end else if (is_holding_reg == 1'b1) begin
            inst_o = hold_inst_reg;
        end else begin
            inst_o = inst_i;
        end
    end

    dff_set #(32) dff_inst_addr (
        clk,
        rst,
        hold_flag_i,
        1'b0,
        32'b0,
        inst_addr_i,
        inst_addr_o
    );

endmodule
