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


// ============================================================================
// 毫秒计数器外设
// ----------------------------------------------------------------------------
// 该模块横跨两个时钟域：
//   - cpu_clk：CPU/外设总线读取计数值的时钟域；
//   - cnt_clk：实际计数使用的时钟域，当前按 50 MHz 设计，50000 拍累加 1 ms。
//
// CDC 处理：
//   - cnt_enable_cpu 是 CPU 域配置位，经过两级同步后进入 cnt_clk 域；
//   - cnt_ms_bin 在 cnt_clk 域递增后转换成 Gray code；
//   - Gray code 经过两级同步进入 cpu_clk 域，再转回二进制供 CPU 读取。
// ============================================================================
module counter(
    input  logic         cpu_clk,
    input  logic         cnt_clk,
    input  logic         rst,

    input  logic         cnt_enable_cpu,
    output logic [31:0]  perip_rdata
);

    // Gray code 转二进制。每一位二进制等于高位二进制与当前 Gray 位异或。
    function automatic logic [31:0] gray_to_bin(input logic [31:0] gray);
        integer i;
        begin
            gray_to_bin[31] = gray[31];
            for (i = 30; i >= 0; i = i - 1) begin
                gray_to_bin[i] = gray_to_bin[i + 1] ^ gray[i];
            end
        end
    endfunction

    logic [15:0] cnt_1ms;
    logic [31:0] cnt_ms_bin;
    logic [31:0] cnt_ms_gray;
    logic cnt_enable_cnt_d1, cnt_enable_cnt_d2;
    logic [31:0] cnt_gray_cpu_d1, cnt_gray_cpu_d2;
    logic [31:0] cnt_bin_cpu_d;

    // CPU -> counter 时钟域同步：控制位是电平信号，两级触发器用于降低亚稳传播风险。
    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            cnt_enable_cnt_d1 <= 1'b0;
            cnt_enable_cnt_d2 <= 1'b0;
        end else begin
            cnt_enable_cnt_d1 <= cnt_enable_cpu;
            cnt_enable_cnt_d2 <= cnt_enable_cnt_d1;
        end
    end

    // 1 ms 分频计数。cnt_enable 关闭时清零，重新开启后从完整 ms 周期开始计。
    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            cnt_1ms <= 0;
        end else if (cnt_enable_cnt_d2) begin
            if (cnt_1ms == 49999) begin
                cnt_1ms <= 0;
            end else begin
                cnt_1ms <= cnt_1ms + 1;
            end
        end else begin
            cnt_1ms <= 0;
        end
    end

    // 毫秒计数器，只在 1 ms tick 到来时递增。
    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            cnt_ms_bin <= 0;
        end else if (cnt_enable_cnt_d2 && cnt_1ms == 49999) begin
            cnt_ms_bin <= cnt_ms_bin + 1;
        end else begin
            cnt_ms_bin <= cnt_ms_bin;
        end
    end

    assign cnt_ms_gray = cnt_ms_bin ^ (cnt_ms_bin >> 1);

    // counter -> CPU 时钟域同步：先同步 Gray code，再在 CPU 域转回二进制。
    always_ff @(posedge cpu_clk) begin
        if (rst) begin
            cnt_gray_cpu_d1 <= 32'd0;
            cnt_gray_cpu_d2 <= 32'd0;
            cnt_bin_cpu_d   <= 32'd0;
        end else begin
            cnt_gray_cpu_d1 <= cnt_ms_gray;
            cnt_gray_cpu_d2 <= cnt_gray_cpu_d1;
            cnt_bin_cpu_d   <= gray_to_bin(cnt_gray_cpu_d2);
        end
    end

    assign perip_rdata = cnt_bin_cpu_d;

endmodule
