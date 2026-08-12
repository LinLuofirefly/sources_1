`timescale 1ns / 1ps
module pc_reg (
    input  wire        clk,
    input  wire        rst,
    input  wire        pc_enable_i,
    input  wire        redirect_valid_i,
    input  wire [31:0] redirect_target_i,
    input  wire [31:0] run_target_i,
    output reg  [31:0] pc_o
);

    // Redirect selection and pipeline advance are deliberately independent.
    // redirect_valid_i selects PC.D; pc_enable_i alone controls whether the
    // register advances.  The HDU/cache-hit cone is absent from this mux.
    wire [31:0] next_pc = redirect_valid_i ?
                          redirect_target_i : run_target_i;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            pc_o <= 32'h8000_0000;
        end else if (pc_enable_i) begin
            pc_o <= next_pc;
        end
    end

endmodule
