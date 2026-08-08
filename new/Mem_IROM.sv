`timescale 1ns / 1ps
module Mem_IROM (
    input  wire        wea,
    input  wire [12:0] addra,
    output reg  [31:0] douta,
    input  wire        clka,
    input  wire [31:0] dina
);
    reg [31:0] mem [0:8191];

    initial begin
        $readmemh("sim/irom.mem", mem);
    end

    always @(posedge clka) begin
        douta <= mem[addra];
    end

    // This behavioral model is read-only. Keep the port so it matches the
    // generated Vivado Block Memory IP used by synthesis.
    wire unused_wea = wea;
endmodule
