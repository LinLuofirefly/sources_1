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

module perip_bridge #(
    parameter integer P_CPU_CLK_HZ     = 257142857,
    parameter integer P_UART_BAUD_RATE = 115200
)(
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
    output logic [31:0]  virtual_led_output,
    output logic         uart_tx_output
);
    localparam DRAM_ADDR_START = 32'h8010_0000;
    localparam DRAM_ADDR_END   = 32'h8013_FFFF;
    localparam SW0_ADDR  = 32'h8020_0000;  // sw[31:0]
    localparam SW1_ADDR  = 32'h8020_0004;  // sw[63:32]
    localparam KEY_ADDR  = 32'h8020_0010;  // key[7:0]
    localparam SEG_ADDR  = 32'h8020_0020;  // seg
    localparam LED_ADDR  = 32'h8020_0040;  // led[31:0]
    localparam CNT_ADDR  = 32'h8020_0050;  // counter
    localparam UART_DATA_ADDR   = 32'h8020_0070;  // write: TX byte
    localparam UART_STATUS_ADDR = 32'h8020_0074;  // read bit 0: TX ready
    localparam CNT_START_CMD = 32'h8000_0000;
    localparam CNT_STOP_CMD  = 32'hFFFF_FFFF; 
    localparam integer UART_BAUD_DIV_CALC = P_CPU_CLK_HZ / P_UART_BAUD_RATE;
    localparam integer UART_BAUD_DIV =
        (UART_BAUD_DIV_CALC < 2) ? 2 : UART_BAUD_DIV_CALC;
    logic [31:0] LED;

    // input synchronizers
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

    assign perip_write_req = |perip_wstrb;

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

    // Address decode at request time, then pipeline the result
    logic rd_is_dram_r,  rd_is_dram_rr;
    logic rd_is_cnt_r,   rd_is_cnt_rr;
    logic rd_is_sw0_r,   rd_is_sw0_rr;
    logic rd_is_sw1_r,   rd_is_sw1_rr;
    logic rd_is_key_r,   rd_is_key_rr;
    logic rd_is_seg_r,   rd_is_seg_rr;
    logic rd_is_uart_status_r, rd_is_uart_status_rr;

    always_ff @(posedge clk) begin
        if (rst) begin
            rd_is_dram_r  <= 1'b0;  rd_is_dram_rr <= 1'b0;
            rd_is_cnt_r   <= 1'b0;  rd_is_cnt_rr  <= 1'b0;
            rd_is_sw0_r   <= 1'b0;  rd_is_sw0_rr  <= 1'b0;
            rd_is_sw1_r   <= 1'b0;  rd_is_sw1_rr  <= 1'b0;
            rd_is_key_r   <= 1'b0;  rd_is_key_rr  <= 1'b0;
            rd_is_seg_r   <= 1'b0;  rd_is_seg_rr  <= 1'b0;
            rd_is_uart_status_r  <= 1'b0;
            rd_is_uart_status_rr <= 1'b0;
        end else begin
            // Cycle 0: decode address at request time
            rd_is_dram_r <= perip_rd_en &&
                            perip_rd_addr >= DRAM_ADDR_START &&
                            perip_rd_addr <  DRAM_ADDR_END;
            rd_is_cnt_r  <= perip_rd_en && perip_rd_addr == CNT_ADDR;
            rd_is_sw0_r  <= perip_rd_en && perip_rd_addr == SW0_ADDR;
            rd_is_sw1_r  <= perip_rd_en && perip_rd_addr == SW1_ADDR;
            rd_is_key_r  <= perip_rd_en && perip_rd_addr == KEY_ADDR;
            rd_is_seg_r  <= perip_rd_en && perip_rd_addr == SEG_ADDR;
            rd_is_uart_status_r <= perip_rd_en &&
                                   perip_rd_addr == UART_STATUS_ADDR;

            // Cycle 1: first pipeline stage
            rd_is_dram_rr <= rd_is_dram_r;
            rd_is_cnt_rr  <= rd_is_cnt_r;
            rd_is_sw0_rr  <= rd_is_sw0_r;
            rd_is_sw1_rr  <= rd_is_sw1_r;
            rd_is_key_rr  <= rd_is_key_r;
            rd_is_seg_rr  <= rd_is_seg_r;
            rd_is_uart_status_rr <= rd_is_uart_status_r;
        end
    end

    // we don't care perip_wstrb in LED, SEG, SW & KEY, only care in DRAM
    // write process
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

    always_comb begin
        unique case (1'b1)
            rd_is_cnt_rr:  mmio_rdata_next = cnt_rdata;
            rd_is_sw0_rr:  mmio_rdata_next = sw_sync_d2[31:0];
            rd_is_sw1_rr:  mmio_rdata_next = sw_sync_d2[63:32];
            rd_is_key_rr:  mmio_rdata_next = {24'd0, key_sync_d2};
            rd_is_seg_rr:  mmio_rdata_next = seg_wdata;
            rd_is_uart_status_rr:
                mmio_rdata_next = {31'd0, ~uart_tx_busy};
            default:       mmio_rdata_next = 32'h0;
        endcase
    end

    // Minimal polling UART transmitter for the CPU console.  The existing
    // top-level UART remains dedicated to the digital-twin protocol.
    logic        uart_tx_busy;
    logic [31:0] uart_baud_count;
    logic [3:0]  uart_bit_index;
    logic [9:0]  uart_shift;
    wire uart_data_write = perip_write_req &&
                           (perip_addr == UART_DATA_ADDR);

    always_ff @(posedge clk) begin
        if (rst) begin
            uart_tx_output  <= 1'b1;
            uart_tx_busy    <= 1'b0;
            uart_baud_count <= 32'd0;
            uart_bit_index  <= 4'd0;
            uart_shift      <= 10'h3ff;
        end else if (!uart_tx_busy) begin
            uart_tx_output  <= 1'b1;
            uart_baud_count <= 32'd0;
            uart_bit_index  <= 4'd0;
            if (uart_data_write) begin
                uart_shift     <= {1'b1, perip_wdata[7:0], 1'b0};
                uart_tx_output <= 1'b0;
                uart_tx_busy   <= 1'b1;
            end
        end else if (uart_baud_count >= (UART_BAUD_DIV - 1)) begin
            uart_baud_count <= 32'd0;
            if (uart_bit_index == 4'd9) begin
                uart_tx_output <= 1'b1;
                uart_tx_busy   <= 1'b0;
            end else begin
                uart_bit_index <= uart_bit_index + 4'd1;
                uart_tx_output <= uart_shift[uart_bit_index + 4'd1];
            end
        end else begin
            uart_baud_count <= uart_baud_count + 32'd1;
        end
    end


    always_comb begin
        if (rd_is_dram_rr) begin
            perip_rdata = dram_rdata;
        end else begin
            perip_rdata = mmio_rdata_r;
        end
    end

    assign perip_dram_rdata = dram_rdata;
    assign perip_mmio_rdata = mmio_rdata_r;

    // seg driver
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
    
    assign wr_is_dram =
        perip_addr >= DRAM_ADDR_START &&
        perip_addr <= DRAM_ADDR_END;

    assign dram_wstrb = wr_is_dram ? perip_wstrb : 4'b0000;
    
    // dram rw
    dram_driver dram_driver_inst (
        .clk				(clk),
        .perip_addr			(perip_addr[17:0]),
        .perip_wdata		(perip_wdata),
        .perip_wstrb		(dram_wstrb),
        .perip_rdata		(dram_rdata),
        .perip_rd_en        (perip_rd_en),
        .perip_rd_addr      (perip_rd_addr[17:0])
    );  

    // counter rw
    counter counter_inst (
        .cpu_clk            (clk),
        .cnt_clk            (cnt_clk),
        .rst                (rst),
        .cnt_enable_cpu     (cnt_enable_cfg),
        .perip_rdata		(cnt_rdata)
    );
    
    // output synchronizers
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
