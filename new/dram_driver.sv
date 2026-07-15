`timescale 1ns / 1ps

// ============================================================================
// DRAM 外设驱动
// ----------------------------------------------------------------------------
// 将 perip_bridge 的字节写使能/读地址转换为 Mem_RAM 双端口 RAM 访问：
//   - Port A：写端口，使用 perip_wstrb 做 byte enable；
//   - Port B：读端口，读数据经 RAM 输出寄存器后再打一拍输出。
//
// 额外打一拍是为了让 DRAM 读延迟与 CPU/perip_bridge 假设的两拍返回路径一致。
// ============================================================================
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

    // 外设地址是 byte 地址，RAM 按 32-bit word 编址，因此丢弃低 2 位。
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
        // 端口 A 写入完全由 wea 的 4 个字节写使能决定。
        // ena 常开可以避免把地址译码/写使能再串进 RAM enable 的长组合路径。
        .ena    (1'b1),
        .wea    (perip_wstrb),
        .clkb   (clk),
        .addrb  (rd_addr),
        .dinb   (32'b0),
        .doutb  (dram_rdata_q1),
        .enb    (1'b1),
        .web    (4'b0)
    );

    // Vivado BRAM IP 的 B 端口通常已经有输出寄存器；这里再打一拍，
    // 让整个 DRAM 读路径保持两拍延迟，和 CPU 的 load 返回时序一致。
    always_ff @(posedge clk) begin
        perip_rdata <= dram_rdata_q1;
    end

endmodule
