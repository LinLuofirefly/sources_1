`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/16/2025 06:21:13 PM
// Design Name: 
// Module Name: student_top
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


module student_top#(
    parameter                           P_SW_CNT            = 64,
    parameter                           P_LED_CNT           = 32,
    parameter                           P_SEG_CNT           = 40,
    parameter                           P_KEY_CNT           = 8,
    parameter integer                   P_CPU_CLK_HZ        = 190000000,
    parameter integer                   P_UART_BAUD_RATE    = 115200
) (
    input                                       w_cpu_clk     ,
    input                                       w_clk_50Mhz   ,
    input                                       w_clk_rst     ,
    input  [P_KEY_CNT - 1:0]                    virtual_key   ,
    input  [P_SW_CNT  - 1:0]                    virtual_sw    ,
    input                                       cpu_uart_rx   ,

    output [P_LED_CNT - 1:0]                    virtual_led   ,
    output [P_SEG_CNT - 1:0]                    virtual_seg   ,
    output                                      cpu_uart_tx
);

    // IROM
    logic [31:0] pc;
    logic [12:0] inst_addr;
    logic [31:0] instruction;

    // perip
    logic [31:0] perip_addr, perip_wdata, perip_rdata;
    logic [31:0] perip_dram_rdata, perip_mmio_rdata;
    logic [31:0] perip_rd_addr;
    logic         perip_rd_en;
    logic [3:0] perip_wstrb;

    // 32KB = 2^13 * 32bit
    assign inst_addr = pc[14:2];

    myCPU Core_cpu (
        .cpu_rst            (w_clk_rst),
        .cpu_clk            (w_cpu_clk),

        // Interface to IROM
        .irom_addr          (pc),             
        .irom_data          (instruction),   

        // Interface to DRAM & peripheral
        .perip_addr         (perip_addr),     
        .perip_wen          (perip_wstrb),       
        .perip_wdata        (perip_wdata),    
        .perip_dram_rdata   (perip_dram_rdata),
        .perip_mmio_rdata   (perip_mmio_rdata),
        .perip_rd_addr      (perip_rd_addr),
        .perip_rd_en        (perip_rd_en)     
    );

    Mem_IROM Mem_IROM (
        .wea          (1'b0),
        .addra        (inst_addr),
        .douta        (instruction),
        .clka        (w_cpu_clk),
        .dina        (32'b0)
    );
    
    perip_bridge #(
        .P_CPU_CLK_HZ       (P_CPU_CLK_HZ),
        .P_UART_BAUD_RATE   (P_UART_BAUD_RATE)
    ) bridge_inst (
        .clk				(w_cpu_clk),
        .cnt_clk            (w_clk_50Mhz),
        .rst                (w_clk_rst),
        .perip_addr			(perip_addr),
        .perip_wdata		(perip_wdata),
        .perip_wstrb			(perip_wstrb),
        .perip_rdata		(perip_rdata),
        .perip_dram_rdata   (perip_dram_rdata),
        .perip_mmio_rdata   (perip_mmio_rdata),
        .perip_rd_addr		(perip_rd_addr),
        .perip_rd_en		(perip_rd_en),
        .virtual_sw_input	(virtual_sw),
        .virtual_key_input	(virtual_key),	
        .uart_rx_input      (cpu_uart_rx),
        .virtual_seg_output	(virtual_seg),
        .virtual_led_output (virtual_led),
        .uart_tx_output     (cpu_uart_tx)
    );

endmodule
