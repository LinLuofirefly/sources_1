`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Module Name: dram_driver
// Description: DRAM 读写驱动模块 (方案 B 修复版)
//
//   修复要点:
//   1. 读路径 (Load): 使用 qspo (同步寄存器输出, 1 拍延迟) → 直传全字给 CPU
//      核心的 mem2 模块负责字节/半字提取和符号扩展, dram_driver 不再重复处理
//   2. 写路径 (Store): 使用 spo (异步组合输出, 0 延迟) 做 read-modify-write
//      确保 SB/SH 读取的是 **当前写地址** 的正确旧值
//   3. SB/SH 写入时, 从 perip_wdata 的 **对应字节位置** 取数据
//      因为 EX 级已经将字节放到了正确位置 (perip_wdata[7:0] 对应 offset 0,
//      perip_wdata[15:8] 对应 offset 1, 以此类推)
//////////////////////////////////////////////////////////////////////////////////

module dram_driver(
    input  logic         clk				,

    input  logic [17:0]  perip_addr			,
    input  logic [31:0]  perip_wdata		,
	input  logic [3:0]	 perip_wstrb			,
    input  logic         perip_rd_en         ,
    input  logic [17:0]  perip_rd_addr      ,
    output logic [31:0]  perip_rdata	
);
    logic perip_wen;
    logic [31:0] dram_data;
    logic [15:0] rd_addr, wr_addr;
    assign rd_addr = perip_rd_addr[17:2];
    assign wr_addr = perip_addr[17:2];
    assign perip_wen=|perip_wstrb;  // 只要有任意字节写使能就认为是写请求
    // =========================================================================
    // DRAM IP 例化: 同时使用 spo (异步) 和 qspo (同步)
    // =========================================================================
    Mem_RAM Mem_DRAM (
        .clka       (clk),
        .addra       (wr_addr),
        .dina        (perip_wdata),         // 异步读: 当前地址的实时数据 → Store RMW
        .douta       (dram_data),        // 同步读: 上一拍地址的数据   → Load 数据
        .ena         (perip_wen),
        .wea         (perip_wstrb),
        .clkb        (clk),
        .addrb       (rd_addr),
        .dinb        (32'b0),
        .doutb       (perip_rdata),        // 同步读: 上一拍地址的数据   → Load 数据
        .enb         (perip_rd_en),
        .web         (4'b0)             // 读端不写入, 但某些 BRAM IP 要求写使能 1 才能输出数据
    );
    
    // =========================================================================
    // 读路径 (Load): 直传 qspo 全字数据
    // mem2.v 负责根据 funct3 和地址低位做字节/半字提取和符号扩展
    // =========================================================================
    //assign perip_rdata = dram_qspo;

    // =========================================================================
    // 写路径 (Store): 使用 spo (异步读, 当前地址的真实数据) 做 read-modify-write
    // perip_wdata 已由 EX 级做好字节对齐:
    //   SB offset=0: byte 在 perip_wdata[7:0]
    //   SB offset=1: byte 在 perip_wdata[15:8]
    //   SB offset=2: byte 在 perip_wdata[23:16]
    //   SB offset=3: byte 在 perip_wdata[31:24]
    //   SH offset=0: half 在 perip_wdata[15:0]
    //   SH offset=2: half 在 perip_wdata[31:16]
    // =========================================================================
  /*  always_comb begin
        case (perip_mask)
            2'b10: dram_data = perip_wdata;  // SW: 全字写入, 无需 RMW
            2'b01: begin                     // SH: 半字写入
                case (offset[1])
                    1'b0: dram_data = {dram_spo[31:16], perip_wdata[15:0]};
                    1'b1: dram_data = {perip_wdata[31:16], dram_spo[15:0]};
                endcase
            end
            2'b00: begin                     // SB: 字节写入
                case (offset)
                    2'b00: dram_data = {dram_spo[31:8],  perip_wdata[7:0]};
                    2'b01: dram_data = {dram_spo[31:16], perip_wdata[15:8],  dram_spo[7:0]};
                    2'b10: dram_data = {dram_spo[31:24], perip_wdata[23:16], dram_spo[15:0]};
                    2'b11: dram_data = {perip_wdata[31:24], dram_spo[23:0]};
                endcase
            end
            default: dram_data = perip_wdata;
        endcase
    end*/
endmodule
