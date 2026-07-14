`timescale 1ns / 1ps

`ifndef TB_CPU_HALF_PERIOD_NS
`define TB_CPU_HALF_PERIOD_NS 2.380952
`endif

module tb_first_seg_stop;
    reg         w_cpu_clk   = 1'b0;
    reg         w_clk_50Mhz = 1'b0;
    reg         w_clk_rst   = 1'b1;
    reg  [7:0]  virtual_key = 8'd0;
    reg  [63:0] virtual_sw  = 64'd0;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR            = 32'h8020_0020;
    localparam [31:0] EXPECTED_FIRST_DATA = 32'h3700_0000;
    localparam integer EXPECTED_FIRST_CYC = 998;
    localparam integer TIMEOUT_CYCLES     = 5000;

    integer cycle_count = 0;

    student_top dut (
        .w_cpu_clk   (w_cpu_clk),
        .w_clk_50Mhz (w_clk_50Mhz),
        .w_clk_rst   (w_clk_rst),
        .virtual_key (virtual_key),
        .virtual_sw  (virtual_sw),
        .virtual_led (virtual_led),
        .virtual_seg (virtual_seg)
    );

    always #(`TB_CPU_HALF_PERIOD_NS) w_cpu_clk = ~w_cpu_clk;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        #20;
        w_clk_rst = 1'b0;
    end

    // Match tb_seg_led_stop's settled-value sampling convention.
    always @(negedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR)) begin
                $display("FIRST_SEG_WRITE cyc=%0d pc=%08h data=%08h wstrb=%b",
                         cycle_count, dut.pc, dut.perip_wdata,
                         dut.perip_wstrb);
                if ((cycle_count == EXPECTED_FIRST_CYC) &&
                    (dut.perip_wdata == EXPECTED_FIRST_DATA)) begin
                    $display("FIRST_SEG_PASS");
                end else begin
                    $display("FIRST_SEG_FAIL expected_cyc=%0d expected_data=%08h",
                             EXPECTED_FIRST_CYC, EXPECTED_FIRST_DATA);
                    $fatal(1);
                end
                $finish;
            end

            if (cycle_count >= TIMEOUT_CYCLES) begin
                $display("FIRST_SEG_TIMEOUT cyc=%0d pc=%08h", cycle_count,
                         dut.pc);
                $fatal(1);
            end
        end
    end
endmodule
