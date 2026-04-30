`timescale 1ns / 1ps

module tb_seg_led_stop;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam [31:0] LED_ADDR = 32'h8020_0040;
    localparam time SIM_TIME_LIMIT_NS = 30_000_000_000;

    integer cycle_count;
    integer seg_write_count;
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
    // 180 MHz CPU clock => 5.555... ns period
    always #2.777 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    task automatic finish_timeout;
        begin
            $display("SEG_LED_STOP_TIMEOUT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led=%08h seg=%010h",
                     cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, virtual_led, virtual_seg);
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        seg_write_count = 0;

        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == SEG_ADDR)) begin
                if (seg_write_count < 2) begin
                    $display("SEG_WRITE_%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b",
                             seg_write_count + 1, cycle_count, $time, dut.pc,
                             dut.instruction, dut.perip_wdata, dut.perip_wstrb);
                end
                seg_write_count = seg_write_count + 1;
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == LED_ADDR)) begin
                $display("LED_WRITE_1 cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b seg_writes=%0d",
                         cycle_count, $time, dut.pc, dut.instruction,
                         dut.perip_wdata, dut.perip_wstrb, seg_write_count);
                $display("SEG_LED_STOP_DONE led=%08h seg=%010h seg_wdata=%08h",
                         virtual_led, virtual_seg, dut.bridge_inst.seg_wdata);
                $finish;
            end

        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        finish_timeout();
    end
endmodule
