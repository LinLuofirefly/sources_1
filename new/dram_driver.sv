`timescale 1ns / 1ps

module dram_driver(
    input  logic         clk,
    input  logic [17:0]  perip_addr,
    input  logic [31:0]  perip_wdata,
    input  logic [3:0]   perip_wstrb,
    input  logic         perip_rd_en,
    input  logic [17:0]  perip_rd_addr,
    output logic [31:0]  perip_rdata
);
    logic        perip_wen;
    logic [31:0] dram_data;
    logic [31:0] dram_rdata_q1;
    logic [15:0] rd_addr, wr_addr;

    assign rd_addr  = perip_rd_addr[17:2];
    assign wr_addr  = perip_addr[17:2];
    assign perip_wen = |perip_wstrb;

    Mem_RAM Mem_DRAM (
        .clka   (clk),
        .addra  (wr_addr),
        .dina   (perip_wdata),
        .douta  (dram_data),
        // BRAM 端口 A 的实际写入由 WEA 字节写使能逐位决定；
        // 当 perip_wstrb 为 4'b0000 时 WEA 全 0，不会写入任何字节。
        // ENA 常开只让端口保持可访问，用于切断数据/地址转发、
        // 地址计算和 DRAM 译码到 Mem_DRAM ENBWREN 的长组合路径。
        .ena    (1'b1),
        .wea    (perip_wstrb),
        .clkb   (clk),
        .addrb  (rd_addr),
        .dinb   (32'b0),
        .doutb  (dram_rdata_q1),
        .enb    (1'b1),
        .web    (4'b0)
    );

    // The Vivado BRAM IP already has a registered Port B output.
    // Keep one more register here so the whole DRAM read path still
    // matches the CPU/perip_bridge two-cycle latency assumption.
    always_ff @(posedge clk) begin
        perip_rdata <= dram_rdata_q1;
    end

endmodule
