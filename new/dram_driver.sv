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
    logic [15:0] rd_addr, wr_addr;

    assign rd_addr  = perip_rd_addr[17:2];
    assign wr_addr  = perip_addr[17:2];
    assign perip_wen = |perip_wstrb;

    Mem_RAM Mem_DRAM (
        .clka   (clk),
        .addra  (wr_addr),
        .dina   (perip_wdata),
        .douta  (dram_data),
        .ena    (perip_wen),
        .wea    (perip_wstrb),
        .clkb   (clk),
        .addrb  (rd_addr),
        .dinb   (32'b0),
        .doutb  (perip_rdata),
        .enb    (perip_rd_en),
        .web    (4'b0)
    );

endmodule
