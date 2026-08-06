`timescale 1ns / 1ps

module myCPU (
    input  logic         cpu_rst,
    input  logic         cpu_clk,

    output logic [31:0]  irom_addr,
    input  logic [31:0]  irom_data,

    output logic [31:0]  perip_addr,
    output logic [3:0]   perip_wen,
    output logic [31:0]  perip_wdata,
    input  logic [31:0]  perip_dram_rdata,
    input  logic [31:0]  perip_mmio_rdata,
    output logic [31:0]  perip_rd_addr,
    output logic         perip_rd_en
);

    // Minimal machine timer used by RT-Thread's system tick.  The registers
    // are write-only from software and intentionally live in the CPU clock
    // domain so no CDC is needed for the interrupt request.
    localparam logic [31:0] MTIMER_PERIOD_ADDR = 32'h8020_0060;
    localparam logic [31:0] MTIMER_CTRL_ADDR   = 32'h8020_0064;
    localparam logic [31:0] MTIMER_ACK_ADDR    = 32'h8020_0068;

    logic [31:0] timer_period_r;
    logic [31:0] timer_count_r;
    logic        timer_enable_r;
    logic        timer_irq_pending_r;

    wire timer_write = |perip_wen;

    always_ff @(posedge cpu_clk) begin
        if (cpu_rst) begin
            timer_period_r      <= 32'd0;
            timer_count_r       <= 32'd0;
            timer_enable_r      <= 1'b0;
            timer_irq_pending_r <= 1'b0;
        end else if (timer_write && (perip_addr == MTIMER_CTRL_ADDR)) begin
            timer_enable_r      <= perip_wdata[0];
            timer_count_r       <= 32'd0;
            timer_irq_pending_r <= 1'b0;
        end else if (timer_write && (perip_addr == MTIMER_ACK_ADDR)) begin
            timer_count_r       <= 32'd0;
            timer_irq_pending_r <= 1'b0;
        end else if (timer_write && (perip_addr == MTIMER_PERIOD_ADDR)) begin
            timer_period_r <= perip_wdata;
            timer_count_r  <= 32'd0;
        end else if (timer_enable_r && !timer_irq_pending_r &&
                     (timer_period_r != 32'd0)) begin
            if (timer_count_r >= (timer_period_r - 32'd1)) begin
                timer_count_r       <= 32'd0;
                timer_irq_pending_r <= 1'b1;
            end else begin
                timer_count_r <= timer_count_r + 32'd1;
            end
        end
    end

    open_risc_v cpu_core (
        .clk           (cpu_clk),
        .rst_n         (~cpu_rst),
        .inst_i        (irom_data),
        .ram_data_i    (perip_dram_rdata),
        .mmio_data_i   (perip_mmio_rdata),
        .timer_irq_i   (timer_irq_pending_r),
        .pc_reg_pc_o   (irom_addr),
        .mem_rd_reg_o  (perip_rd_en),
        .mem_rd_addr_o (perip_rd_addr),
        .w_en          (perip_wen),
        .w_addr_i      (perip_addr),
        .w_data_i      (perip_wdata)
    );

    /*always_comb begin
        perip_wen = |mem_wen;  //将mem_wen的4位进行或运算，如果有一个位为1，则perip_wen为1，否则为0

        if (perip_wen) begin
            perip_addr  = mem_waddr;
            perip_wdata = mem_wdata;
            unique case (mem_wen)
                4'b0001,
                4'b0010,
                4'b0100,
                4'b1000: perip_mask = 2'b00;
                4'b0011,
                4'b1100: perip_mask = 2'b01;
                4'b1111: perip_mask = 2'b10;
                default: perip_mask = 2'b10;
            endcase
        end else begin
            perip_addr  = mem_rd_en ? mem_rd_addr : 32'b0;
            perip_wdata = 32'b0;
            perip_mask  = mem_rd_en ? mem_rd_mask : 2'b10;
        end
    end
   */
endmodule
