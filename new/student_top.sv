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


// ============================================================================
// 学生 CPU 工程顶层封装
// ----------------------------------------------------------------------------
// 该模块连接三部分：
//   1. myCPU：RISC-V CPU 核心封装；
//   2. Mem_IROM：同步指令 ROM，按 PC[13:2] 取 32-bit 指令；
//   3. perip_bridge：DRAM/MMIO/LED/SEG/KEY/SW/COUNTER 外设桥。
//
// w_cpu_clk 驱动 CPU、IROM 和外设桥主逻辑；w_clk_50Mhz 用于计数器和显示侧同步。
// ============================================================================
module student_top#(
    parameter                           P_SW_CNT            = 64,
    parameter                           P_LED_CNT           = 32,
    parameter                           P_SEG_CNT           = 40,
    parameter                           P_KEY_CNT           = 8
) (
    input                                       w_cpu_clk     ,
    input                                       w_clk_50Mhz   ,
    input                                       w_clk_rst     ,
    input  [P_KEY_CNT - 1:0]                    virtual_key   ,
    input  [P_SW_CNT  - 1:0]                    virtual_sw    ,

    output [P_LED_CNT - 1:0]                    virtual_led   ,
    output [P_SEG_CNT - 1:0]                    virtual_seg   
);

    // IROM 取指通路。CPU 输出 byte 地址 PC，IROM 使用 word 地址。
    logic [31:0] pc;
    logic [11:0] inst_addr;
    logic [31:0] instruction;

    // CPU 与外设桥之间的统一访存接口。
    // DRAM 和 MMIO 读数据在 bridge 内部分流后分别送回 CPU。
    logic [31:0] perip_addr, perip_wdata, perip_rdata;
    logic [31:0] perip_dram_rdata, perip_mmio_rdata;
    logic [31:0] perip_rd_addr;
    logic         perip_rd_en;
    logic [3:0] perip_wstrb;

    // 16KB = 2^12 * 32bit。PC[1:0] 是字节内偏移，取指按 word 对齐。
    assign inst_addr = pc[13:2];

    // CPU 核心。它只看到 IROM 指令输入和统一外设读写接口，
    // 不直接关心 LED/SEG/DRAM 等具体地址译码。
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

    // 同步指令 ROM：PC 请求后一拍返回 instruction。
    Mem_IROM Mem_IROM (
        .addra        (inst_addr),
        .douta        (instruction),
        .clka        (w_cpu_clk),
        .dina        (32'b0)
    );
    
    // 外设桥：负责把 CPU 的统一 load/store 请求拆到 DRAM 或 MMIO 外设。
    perip_bridge bridge_inst (
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
        .virtual_seg_output	(virtual_seg),
        .virtual_led_output (virtual_led)
    );

endmodule
