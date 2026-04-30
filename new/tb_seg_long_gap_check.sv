`timescale 1ns / 1ps

module tb_seg_long_gap_check;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam time MIN_SECOND_SEG_TIME_NS = 15_000_000_000;
    localparam time MAX_SIM_TIME_NS        = 30_000_000_000;
    localparam [31:0] SEG_ADDR             = 32'h8020_0020;
    localparam [31:0] FIRST_SEG_EXPECTED   = 32'h3700_0000;

    integer seg_write_count;
    time    first_seg_time;
    time    second_seg_time;
    reg [31:0] first_seg_data;
    reg [31:0] second_seg_data;

    student_top dut (
        .w_cpu_clk   (w_cpu_clk),
        .w_clk_50Mhz (w_clk_50Mhz),
        .w_clk_rst   (w_clk_rst),
        .virtual_key (virtual_key),
        .virtual_sw  (virtual_sw),
        .virtual_led (virtual_led),
        .virtual_seg (virtual_seg)
    );

    initial w_cpu_clk = 1'b0;
    always #3.333 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    task automatic finish_fail;
        input [255:0] reason;
        begin
            $display("SEG_CHECK_FAIL reason=%0s time=%0t pc=%08h inst=%08h seg_wdata=%08h",
                     reason, $time, dut.pc, dut.instruction, dut.bridge_inst.seg_wdata);
            $finish;
        end
    endtask

    initial begin
        virtual_key     = 8'd0;
        virtual_sw      = 64'd0;
        w_clk_rst       = 1'b1;
        seg_write_count = 0;
        first_seg_time  = 0;
        second_seg_time = 0;
        first_seg_data  = 32'd0;
        second_seg_data = 32'd0;

        #20;
        w_clk_rst = 1'b0;

        #(MAX_SIM_TIME_NS);
        $display("SEG_CHECK_TIMEOUT first_data=%08h first_time=%0t second_data=%08h second_time=%0t seg_count=%0d",
                 first_seg_data, first_seg_time, second_seg_data, second_seg_time, seg_write_count);
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR) &&
                (dut.perip_wdata != 32'h0000_0000)) begin
                seg_write_count = seg_write_count + 1;

                if (seg_write_count == 1) begin
                    first_seg_time = $time;
                    first_seg_data = dut.perip_wdata;
                    $display("SEG_CHECK_FIRST time=%0t pc=%08h inst=%08h data=%08h",
                             first_seg_time, dut.pc, dut.instruction, first_seg_data);
                    if (first_seg_data != FIRST_SEG_EXPECTED) begin
                        finish_fail("FIRST_SEG_MISMATCH");
                    end
                end else if (seg_write_count == 2) begin
                    second_seg_time = $time;
                    second_seg_data = dut.perip_wdata;
                    $display("SEG_CHECK_SECOND time=%0t pc=%08h inst=%08h data=%08h delta=%0t",
                             second_seg_time, dut.pc, dut.instruction, second_seg_data,
                             second_seg_time - first_seg_time);
                    if ((second_seg_time - first_seg_time) < MIN_SECOND_SEG_TIME_NS) begin
                        finish_fail("SECOND_SEG_TOO_EARLY");
                    end
                    $display("SEG_CHECK_PASS first_data=%08h first_time=%0t second_data=%08h second_time=%0t delta=%0t",
                             first_seg_data, first_seg_time, second_seg_data, second_seg_time,
                             second_seg_time - first_seg_time);
                    $finish;
                end
            end

            if (dut.pc < 32'h0000_0100) begin
                finish_fail("RUNAWAY_LOW_PC");
            end
        end
    end
endmodule
