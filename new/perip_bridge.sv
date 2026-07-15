`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2025/04/22 10:25:24
// Design Name: 
// Module Name: perip_bridge
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
// CPU 外设桥
// ----------------------------------------------------------------------------
// 负责把 CPU 的统一外设访问拆分到 DRAM、开关、按键、数码管、LED 和计数器：
//   - DRAM 地址范围：0x8010_0000 ~ 0x8013_FFFF；
//   - MMIO 地址范围：0x8020_xxxx，用固定地址访问 SW/KEY/SEG/LED/COUNTER；
//   - 读路径对 DRAM/MMIO 做两拍对齐，保证 CPU load 返回时序一致；
//   - 虚拟输入/输出跨 cpu_clk 与 cnt_clk，使用两级同步寄存器。
// ============================================================================
module perip_bridge(
    input  logic         clk				,
    input  logic         cnt_clk			,
    input  logic         rst                ,

    input  logic [31:0]  perip_addr			,
    input  logic [31:0]  perip_wdata		,
	input  logic [3:0]	 perip_wstrb			,
    input  logic         perip_rd_en        ,
    input  logic [31:0]  perip_rd_addr      ,
    output logic [31:0]  perip_rdata		,
    output logic [31:0]  perip_dram_rdata   ,
    output logic [31:0]  perip_mmio_rdata   ,

    input  logic [63:0]  virtual_sw_input	,
    input  logic [7:0]   virtual_key_input	,	

	output logic [39:0]  virtual_seg_output	,
    output logic [31:0]  virtual_led_output
);
    localparam DRAM_ADDR_START = 32'h8010_0000;
    localparam DRAM_ADDR_END   = 32'h8013_FFFF;
    localparam SW0_ADDR  = 32'h8020_0000;  // sw[31:0]
    localparam SW1_ADDR  = 32'h8020_0004;  // sw[63:32]
    localparam KEY_ADDR  = 32'h8020_0010;  // key[7:0]
    localparam SEG_ADDR  = 32'h8020_0020;  // seg
    localparam LED_ADDR  = 32'h8020_0040;  // led[31:0]
    localparam CNT_ADDR  = 32'h8020_0050;  // counter
    localparam CNT_START_CMD = 32'h8000_0000;
    localparam CNT_STOP_CMD  = 32'hFFFF_FFFF; 
    logic [31:0] LED;

    // 输入同步器：virtual_sw/key 可能来自不同步外设域，先同步到 CPU 时钟域。
    // 多 bit 信号仍可能出现不同 bit 非同拍变化，但对开关/按键这类慢速输入足够。
    logic [63:0] sw_sync_d1, sw_sync_d2;
    logic [7:0]  key_sync_d1, key_sync_d2;

    always_ff @(posedge clk) begin
        if (rst) begin
            sw_sync_d1 <= 64'd0;
            sw_sync_d2 <= 64'd0;
            key_sync_d1 <= 8'd0;
            key_sync_d2 <= 8'd0;
        end else begin
            sw_sync_d1 <= virtual_sw_input;
            sw_sync_d2 <= sw_sync_d1;
            key_sync_d1 <= virtual_key_input;
            key_sync_d2 <= key_sync_d1;
        end
    end
    logic [31:0] seg_wdata, cnt_rdata, dram_rdata;
    logic [31:0] mmio_rdata_next;
    logic [31:0] mmio_rdata_r;
    logic [39:0] seg_output;
    logic cnt_enable_cfg;
    logic perip_write_req;
    logic perip_rd_en_r;
    logic perip_rd_en_rr;
    logic wr_is_dram;
    logic [3:0] dram_wstrb;

    // 写请求只由 byte strobe 决定；DRAM 会继续使用完整 wstrb 做字节写。
    assign perip_write_req = |perip_wstrb;

    // 读使能和 MMIO 读数据打一拍。与下方地址译码流水一起形成固定读延迟。
    always_ff @(posedge clk) begin
        if (rst) begin
            perip_rd_en_r  <= 1'b0;
            perip_rd_en_rr <= 1'b0;
            mmio_rdata_r   <= 32'b0;
        end else begin
            perip_rd_en_r  <= perip_rd_en;
            perip_rd_en_rr <= perip_rd_en_r;
            mmio_rdata_r   <= mmio_rdata_next;
        end
    end

    // 读地址在请求当拍完成译码，然后流水两级。
    // 这样返回数据选择与 DRAM 的同步读延迟对齐，不需要在返回拍重新比较地址。
    logic rd_is_dram_r,  rd_is_dram_rr;
    logic rd_is_cnt_r,   rd_is_cnt_rr;
    logic rd_is_sw0_r,   rd_is_sw0_rr;
    logic rd_is_sw1_r,   rd_is_sw1_rr;
    logic rd_is_key_r,   rd_is_key_rr;
    logic rd_is_seg_r,   rd_is_seg_rr;

    always_ff @(posedge clk) begin
        if (rst) begin
            rd_is_dram_r  <= 1'b0;  rd_is_dram_rr <= 1'b0;
            rd_is_cnt_r   <= 1'b0;  rd_is_cnt_rr  <= 1'b0;
            rd_is_sw0_r   <= 1'b0;  rd_is_sw0_rr  <= 1'b0;
            rd_is_sw1_r   <= 1'b0;  rd_is_sw1_rr  <= 1'b0;
            rd_is_key_r   <= 1'b0;  rd_is_key_rr  <= 1'b0;
            rd_is_seg_r   <= 1'b0;  rd_is_seg_rr  <= 1'b0;
        end else begin
            // Cycle 0：在发起读请求时锁存地址译码结果。
            rd_is_dram_r <= perip_rd_en &&
                            perip_rd_addr >= DRAM_ADDR_START &&
                            perip_rd_addr <  DRAM_ADDR_END;
            rd_is_cnt_r  <= perip_rd_en && perip_rd_addr == CNT_ADDR;
            rd_is_sw0_r  <= perip_rd_en && perip_rd_addr == SW0_ADDR;
            rd_is_sw1_r  <= perip_rd_en && perip_rd_addr == SW1_ADDR;
            rd_is_key_r  <= perip_rd_en && perip_rd_addr == KEY_ADDR;
            rd_is_seg_r  <= perip_rd_en && perip_rd_addr == SEG_ADDR;

            // Cycle 1：译码结果继续后推，用于最终读数据 mux。
            rd_is_dram_rr <= rd_is_dram_r;
            rd_is_cnt_rr  <= rd_is_cnt_r;
            rd_is_sw0_rr  <= rd_is_sw0_r;
            rd_is_sw1_rr  <= rd_is_sw1_r;
            rd_is_key_rr  <= rd_is_key_r;
            rd_is_seg_rr  <= rd_is_seg_r;
        end
    end

    // MMIO 写寄存器。
    // LED/SEG/COUNTER 只看是否有写请求，不按 byte strobe 部分更新；
    // byte strobe 的逐字节语义只在 DRAM 写路径中使用。
    always_ff @(posedge clk) begin
        if (rst) begin
            LED            <= 32'd0;
            seg_wdata      <= 32'd0;
            cnt_enable_cfg <= 1'b0;
        end else if (perip_write_req) begin
            case (perip_addr)
                LED_ADDR:   LED <= perip_wdata;
                SEG_ADDR:   seg_wdata <= perip_wdata;
                CNT_ADDR: begin
                    if (perip_wdata == CNT_START_CMD) begin
                        cnt_enable_cfg <= 1'b1;
                    end else if (perip_wdata == CNT_STOP_CMD) begin
                        cnt_enable_cfg <= 1'b0;
                    end
                end
            endcase
        end
    end

    // MMIO 读数据选择。使用已经流水后的 rd_is_*_rr，和返回拍对齐。
    always_comb begin
        unique case (1'b1)
            rd_is_cnt_rr:  mmio_rdata_next = cnt_rdata;
            rd_is_sw0_rr:  mmio_rdata_next = sw_sync_d2[31:0];
            rd_is_sw1_rr:  mmio_rdata_next = sw_sync_d2[63:32];
            rd_is_key_rr:  mmio_rdata_next = {24'd0, key_sync_d2};
            rd_is_seg_rr:  mmio_rdata_next = seg_wdata;
            default:       mmio_rdata_next = 32'h0;
        endcase
    end


    // 最终读返回 mux：DRAM 命中返回 dram_rdata，其余 MMIO 返回 mmio_rdata_r。
    always_comb begin
        if (rd_is_dram_rr) begin
            perip_rdata = dram_rdata;
        end else begin
            perip_rdata = mmio_rdata_r;
        end
    end

    assign perip_dram_rdata = dram_rdata;
    assign perip_mmio_rdata = mmio_rdata_r;

    // 数码管显示驱动：seg_wdata 是软件写入的显示值，display_seg 负责七段编码。
    display_seg seg_driver (
        .clk    (clk),
        .rst    (rst),
        .s      (seg_wdata),
        .seg1   (seg_output[6:0]),
        .seg2   (seg_output[16:10]),
        .seg3   (seg_output[26:20]),
        .seg4   (seg_output[36:30]),
        .ans    ({seg_output[39:38], seg_output[29:28], seg_output[19:18], seg_output[9:8]})
    ); 
   
    assign seg_output[7]  = 0;
    assign seg_output[17] = 0;
    assign seg_output[27] = 0;
    assign seg_output[37] = 0;
    
    // 只有落在 DRAM 地址范围内的写请求才传给 dram_driver；
    // MMIO 写会在上面的寄存器写逻辑中处理。
    assign wr_is_dram =
        perip_addr >= DRAM_ADDR_START &&
        perip_addr <= DRAM_ADDR_END;

    assign dram_wstrb = wr_is_dram ? perip_wstrb : 4'b0000;
    
    // DRAM 读写通路。
    dram_driver dram_driver_inst (
        .clk				(clk),
        .perip_addr			(perip_addr[17:0]),
        .perip_wdata		(perip_wdata),
        .perip_wstrb		(dram_wstrb),
        .perip_rdata		(dram_rdata),
        .perip_rd_en        (perip_rd_en),
        .perip_rd_addr      (perip_rd_addr[17:0])
    );  

    // 计数器外设。cnt_enable_cfg 在 CPU 域配置，counter 内部再同步到 cnt_clk。
    counter counter_inst (
        .cpu_clk            (clk),
        .cnt_clk            (cnt_clk),
        .rst                (rst),
        .cnt_enable_cpu     (cnt_enable_cfg),
        .perip_rdata		(cnt_rdata)
    );
    
    // 输出同步器：LED/SEG 最终给显示/虚拟外设侧使用，跨到 cnt_clk 域后输出。
    logic [31:0] led_sync_d1, led_sync_d2;
    logic [39:0] seg_sync_d1, seg_sync_d2;

    always_ff @(posedge cnt_clk) begin
        if (rst) begin
            led_sync_d1 <= 32'd0;
            led_sync_d2 <= 32'd0;
            seg_sync_d1 <= 40'd0;
            seg_sync_d2 <= 40'd0;
        end else begin
            led_sync_d1 <= LED;
            led_sync_d2 <= led_sync_d1;
            seg_sync_d1 <= seg_output;
            seg_sync_d2 <= seg_sync_d1;
        end
    end

    assign virtual_led_output = led_sync_d2;
    assign virtual_seg_output = seg_sync_d2;
//进行vivado同步
endmodule
