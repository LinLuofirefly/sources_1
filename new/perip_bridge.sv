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
    input  logic         uart_rx_input      ,
    input  logic         hcsr04_echo_input  ,

	output logic [39:0]  virtual_seg_output	,
    output logic [31:0]  virtual_led_output,
    output logic         uart_tx_output,
    output logic         hcsr04_trig_output
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
    localparam UART_RX_DATA_ADDR   = 32'h8020_0078;  // read: oldest RX byte
    localparam UART_RX_STATUS_ADDR = 32'h8020_007C;  // read bit 0: RX valid
    localparam HCSR04_CTRL_ADDR        = 32'h8020_0080; // write bit 0: start
    localparam HCSR04_STATUS_ADDR      = 32'h8020_0084; // busy/done/timeout/echo
    localparam HCSR04_ECHO_US_ADDR     = 32'h8020_0088; // latched pulse width
    localparam HCSR04_ECHO_CYCLES_ADDR = 32'h8020_008C; // raw CPU-clock cycles
    localparam CNT_START_CMD = 32'h8000_0000;
    localparam CNT_STOP_CMD  = 32'hFFFF_FFFF; 
    localparam integer UART_BAUD_DIV_CALC = P_CPU_CLK_HZ / P_UART_BAUD_RATE;
    localparam integer UART_BAUD_DIV =
        (UART_BAUD_DIV_CALC < 2) ? 2 : UART_BAUD_DIV_CALC;
    localparam integer UART_HALF_BAUD_DIV =
        (UART_BAUD_DIV / 2 < 1) ? 1 : (UART_BAUD_DIV / 2);
    localparam integer UART_RX_FIFO_DEPTH = 16;
    localparam logic [4:0] UART_RX_FIFO_CAPACITY = 5'd16;
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
    logic rd_is_uart_rx_data_r, rd_is_uart_rx_data_rr;
    logic rd_is_uart_rx_status_r, rd_is_uart_rx_status_rr;
    logic rd_is_hcsr04_status_r, rd_is_hcsr04_status_rr;
    logic rd_is_hcsr04_echo_us_r, rd_is_hcsr04_echo_us_rr;
    logic rd_is_hcsr04_echo_cycles_r, rd_is_hcsr04_echo_cycles_rr;

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
            rd_is_uart_rx_data_r   <= 1'b0;
            rd_is_uart_rx_data_rr  <= 1'b0;
            rd_is_uart_rx_status_r <= 1'b0;
            rd_is_uart_rx_status_rr <= 1'b0;
            rd_is_hcsr04_status_r <= 1'b0;
            rd_is_hcsr04_status_rr <= 1'b0;
            rd_is_hcsr04_echo_us_r <= 1'b0;
            rd_is_hcsr04_echo_us_rr <= 1'b0;
            rd_is_hcsr04_echo_cycles_r <= 1'b0;
            rd_is_hcsr04_echo_cycles_rr <= 1'b0;
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
            rd_is_uart_rx_data_r <= perip_rd_en &&
                                    perip_rd_addr == UART_RX_DATA_ADDR;
            rd_is_uart_rx_status_r <= perip_rd_en &&
                                      perip_rd_addr == UART_RX_STATUS_ADDR;
            rd_is_hcsr04_status_r <= perip_rd_en &&
                                     perip_rd_addr == HCSR04_STATUS_ADDR;
            rd_is_hcsr04_echo_us_r <= perip_rd_en &&
                                      perip_rd_addr == HCSR04_ECHO_US_ADDR;
            rd_is_hcsr04_echo_cycles_r <= perip_rd_en &&
                                          perip_rd_addr == HCSR04_ECHO_CYCLES_ADDR;

            // Cycle 1: first pipeline stage
            rd_is_dram_rr <= rd_is_dram_r;
            rd_is_cnt_rr  <= rd_is_cnt_r;
            rd_is_sw0_rr  <= rd_is_sw0_r;
            rd_is_sw1_rr  <= rd_is_sw1_r;
            rd_is_key_rr  <= rd_is_key_r;
            rd_is_seg_rr  <= rd_is_seg_r;
            rd_is_uart_status_rr <= rd_is_uart_status_r;
            rd_is_uart_rx_data_rr <= rd_is_uart_rx_data_r;
            rd_is_uart_rx_status_rr <= rd_is_uart_rx_status_r;
            rd_is_hcsr04_status_rr <= rd_is_hcsr04_status_r;
            rd_is_hcsr04_echo_us_rr <= rd_is_hcsr04_echo_us_r;
            rd_is_hcsr04_echo_cycles_rr <= rd_is_hcsr04_echo_cycles_r;
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
            rd_is_uart_rx_data_rr:
                mmio_rdata_next = {24'd0, uart_rx_read_data};
            rd_is_uart_rx_status_rr:
                mmio_rdata_next = {22'd0, uart_rx_overrun, uart_rx_count,
                                    3'd0, |uart_rx_count};
            rd_is_hcsr04_status_rr:      mmio_rdata_next = hcsr04_status;
            rd_is_hcsr04_echo_us_rr:     mmio_rdata_next = hcsr04_echo_us;
            rd_is_hcsr04_echo_cycles_rr: mmio_rdata_next = hcsr04_echo_cycles;
            default:       mmio_rdata_next = 32'h0;
        endcase
    end

    // HC-SR04 measurement engine.  START is ignored while BUSY, which also
    // makes the command robust if a CPU MMIO write is held for several cycles.
    logic        hcsr04_busy;
    logic        hcsr04_done;
    logic        hcsr04_timeout;
    logic        hcsr04_echo_level;
    logic [31:0] hcsr04_echo_us;
    logic [31:0] hcsr04_echo_cycles;
    logic [31:0] hcsr04_status;

    wire hcsr04_start = perip_write_req &&
                        (perip_addr == HCSR04_CTRL_ADDR) && perip_wdata[0];
    wire hcsr04_clear = perip_write_req &&
                        (perip_addr == HCSR04_CTRL_ADDR) && perip_wdata[1];

    assign hcsr04_status = {28'd0, hcsr04_echo_level, hcsr04_timeout,
                            hcsr04_done, hcsr04_busy};

    hcsr04_controller #(
        .P_CLK_HZ(P_CPU_CLK_HZ)
    ) hcsr04_inst (
        .clk         (clk),
        .rst         (rst),
        .start       (hcsr04_start),
        .clear       (hcsr04_clear),
        .echo_async  (hcsr04_echo_input),
        .trig        (hcsr04_trig_output),
        .busy        (hcsr04_busy),
        .done        (hcsr04_done),
        .timeout     (hcsr04_timeout),
        .echo_level  (hcsr04_echo_level),
        .echo_cycles (hcsr04_echo_cycles),
        .echo_us     (hcsr04_echo_us)
    );

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

    // 8-N-1 UART receiver.  A small FIFO decouples the serial line from the
    // polling console so complete command lines are not lost between MMIO
    // reads.  Reading UART_RX_DATA_ADDR removes exactly one byte.
    typedef enum logic [1:0] {
        UART_RX_IDLE,
        UART_RX_START,
        UART_RX_DATA,
        UART_RX_STOP
    } uart_rx_state_t;

    uart_rx_state_t uart_rx_state;
    logic uart_rx_sync_d1, uart_rx_sync_d2;
    logic [31:0] uart_rx_baud_count;
    logic [2:0] uart_rx_bit_index;
    logic [7:0] uart_rx_shift;
    logic [7:0] uart_rx_byte;
    logic uart_rx_byte_ready;

    logic [7:0] uart_rx_fifo [0:UART_RX_FIFO_DEPTH-1];
    logic [3:0] uart_rx_write_ptr;
    logic [3:0] uart_rx_read_ptr;
    logic [4:0] uart_rx_count;
    logic [7:0] uart_rx_read_data;
    logic uart_rx_overrun;

    wire uart_rx_data_read = perip_rd_en &&
                             (perip_rd_addr == UART_RX_DATA_ADDR);
    wire uart_rx_pop = uart_rx_data_read && (uart_rx_count != 0);
    wire uart_rx_push = uart_rx_byte_ready &&
                        ((uart_rx_count < UART_RX_FIFO_CAPACITY) || uart_rx_pop);

    always_ff @(posedge clk) begin
        if (rst) begin
            uart_rx_sync_d1 <= 1'b1;
            uart_rx_sync_d2 <= 1'b1;
            uart_rx_state <= UART_RX_IDLE;
            uart_rx_baud_count <= 32'd0;
            uart_rx_bit_index <= 3'd0;
            uart_rx_shift <= 8'd0;
            uart_rx_byte <= 8'd0;
            uart_rx_byte_ready <= 1'b0;
        end else begin
            uart_rx_sync_d1 <= uart_rx_input;
            uart_rx_sync_d2 <= uart_rx_sync_d1;
            uart_rx_byte_ready <= 1'b0;

            case (uart_rx_state)
                UART_RX_IDLE: begin
                    uart_rx_baud_count <= 32'd0;
                    uart_rx_bit_index <= 3'd0;
                    if (!uart_rx_sync_d2) begin
                        uart_rx_state <= UART_RX_START;
                        uart_rx_baud_count <= UART_HALF_BAUD_DIV - 1;
                    end
                end
                UART_RX_START: begin
                    if (uart_rx_baud_count == 0) begin
                        if (!uart_rx_sync_d2) begin
                            uart_rx_state <= UART_RX_DATA;
                            uart_rx_baud_count <= UART_BAUD_DIV - 1;
                        end else begin
                            uart_rx_state <= UART_RX_IDLE;
                        end
                    end else begin
                        uart_rx_baud_count <= uart_rx_baud_count - 1;
                    end
                end
                UART_RX_DATA: begin
                    if (uart_rx_baud_count == 0) begin
                        uart_rx_shift[uart_rx_bit_index] <= uart_rx_sync_d2;
                        uart_rx_baud_count <= UART_BAUD_DIV - 1;
                        if (uart_rx_bit_index == 3'd7) begin
                            uart_rx_state <= UART_RX_STOP;
                        end else begin
                            uart_rx_bit_index <= uart_rx_bit_index + 1'b1;
                        end
                    end else begin
                        uart_rx_baud_count <= uart_rx_baud_count - 1;
                    end
                end
                default: begin
                    if (uart_rx_baud_count == 0) begin
                        if (uart_rx_sync_d2) begin
                            uart_rx_byte <= uart_rx_shift;
                            uart_rx_byte_ready <= 1'b1;
                        end
                        uart_rx_state <= UART_RX_IDLE;
                    end else begin
                        uart_rx_baud_count <= uart_rx_baud_count - 1;
                    end
                end
            endcase
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin
            uart_rx_write_ptr <= 4'd0;
            uart_rx_read_ptr <= 4'd0;
            uart_rx_count <= 5'd0;
            uart_rx_read_data <= 8'd0;
            uart_rx_overrun <= 1'b0;
        end else begin
            if (uart_rx_pop) begin
                uart_rx_read_data <= uart_rx_fifo[uart_rx_read_ptr];
                uart_rx_read_ptr <= uart_rx_read_ptr + 1'b1;
            end
            if (uart_rx_push) begin
                uart_rx_fifo[uart_rx_write_ptr] <= uart_rx_byte;
                uart_rx_write_ptr <= uart_rx_write_ptr + 1'b1;
            end else if (uart_rx_byte_ready) begin
                uart_rx_overrun <= 1'b1;
            end

            case ({uart_rx_push, uart_rx_pop})
                2'b10: uart_rx_count <= uart_rx_count + 1'b1;
                2'b01: uart_rx_count <= uart_rx_count - 1'b1;
                default: uart_rx_count <= uart_rx_count;
            endcase
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
