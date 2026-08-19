`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/22/2025 03:04:25 PM
// Design Name: 
// Module Name: counter
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module counter(
    input  logic         cpu_clk,
    input  logic         cnt_clk,
    input  logic         rst,

    input  logic         cnt_enable_cpu,
    output logic [31:0]  perip_rdata
);

    function automatic logic [31:0] gray_to_bin(input logic [31:0] gray);
        integer i;
        begin
            gray_to_bin[31] = gray[31];
            for (i = 30; i >= 0; i = i - 1) begin
                gray_to_bin[i] = gray_to_bin[i + 1] ^ gray[i];
            end
        end
    endfunction

    // Count the independent 50 MHz reference clock directly.  The previous
    // implementation divided this clock down to 1 kHz, which limited elapsed
    // time to millisecond resolution and forced the last three printed
    // decimal digits to zero.  A 32-bit 50 MHz elapsed count covers about
    // 85.9 seconds, sufficient for the 18,000-iteration CoreMark image.
    logic [31:0] cnt_cycles_bin;
    logic [31:0] cnt_cycles_gray;
    logic cnt_enable_cnt_d1, cnt_enable_cnt_d2;
    logic [31:0] cnt_gray_cpu_d1, cnt_gray_cpu_d2;
    logic [31:0] cnt_bin_cpu_d;

    // CPU->counter CDC: synchronize level control into cnt_clk domain.
    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            cnt_enable_cnt_d1 <= 1'b0;
            cnt_enable_cnt_d2 <= 1'b0;
        end else begin
            cnt_enable_cnt_d1 <= cnt_enable_cpu;
            cnt_enable_cnt_d2 <= cnt_enable_cnt_d1;
        end
    end

    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            cnt_cycles_bin <= 32'd0;
        end else if (cnt_enable_cnt_d2) begin
            cnt_cycles_bin <= cnt_cycles_bin + 32'd1;
        end
    end

    assign cnt_cycles_gray = cnt_cycles_bin ^ (cnt_cycles_bin >> 1);

    // Counter->CPU CDC: Gray code allows safe multi-bit crossing.
    always_ff @(posedge cpu_clk) begin
        if (rst) begin
            cnt_gray_cpu_d1 <= 32'd0;
            cnt_gray_cpu_d2 <= 32'd0;
            cnt_bin_cpu_d   <= 32'd0;
        end else begin
            cnt_gray_cpu_d1 <= cnt_cycles_gray;
            cnt_gray_cpu_d2 <= cnt_gray_cpu_d1;
            cnt_bin_cpu_d   <= gray_to_bin(cnt_gray_cpu_d2);
        end
    end

    assign perip_rdata = cnt_bin_cpu_d;

endmodule
