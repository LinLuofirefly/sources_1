`timescale 1ns / 1ps

module tb_seg_led_stop_shorttrace;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam [31:0] LED_ADDR = 32'h8020_0040;
    localparam [31:0] STOP_ADDR = 32'h8020_0050;
    localparam time SIM_TIME_LIMIT_NS = 2_000_000;
    localparam integer STUCK_PC_LIMIT = 50000;
    localparam integer HEARTBEAT_CYCLES = 10000;

    integer cycle_count;
    integer seg_write_count;
    integer led_write_count;
    integer stop_write_count;
    integer same_pc_count;
    reg [31:0] prev_pc;

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
    always #2.5 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    task automatic finish_now;
        input [127:0] reason;
        begin
            $display("SHORTTRACE_DONE reason=%0s cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d stop_writes=%0d led=%08h seg=%010h",
                     reason, cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, led_write_count, stop_write_count,
                     virtual_led, virtual_seg);
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        seg_write_count = 0;
        led_write_count = 0;
        stop_write_count = 0;
        same_pc_count = 0;
        prev_pc = 32'b0;

        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (dut.pc == prev_pc) begin
                same_pc_count = same_pc_count + 1;
            end else begin
                same_pc_count = 0;
                prev_pc = dut.pc;
            end

            if ((cycle_count % HEARTBEAT_CYCLES) == 0) begin
                $display("SHORTTRACE_HEARTBEAT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d stop_writes=%0d led=%08h seg=%010h",
                         cycle_count, $time, dut.pc, dut.instruction,
                         seg_write_count, led_write_count, stop_write_count,
                         virtual_led, virtual_seg);
            end

            if (same_pc_count >= STUCK_PC_LIMIT) begin
                finish_now("STUCK_SAME_PC");
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == SEG_ADDR)) begin
                seg_write_count = seg_write_count + 1;
                $display("SHORTTRACE_SEG_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vseg=%010h",
                         seg_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb, virtual_seg);
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == LED_ADDR)) begin
                led_write_count = led_write_count + 1;
                $display("SHORTTRACE_LED_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vled=%08h vseg=%010h",
                         led_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb,
                         virtual_led, virtual_seg);
                if (led_write_count == 2) begin
                    finish_now("SECOND_LED_WRITE");
                end
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == STOP_ADDR)) begin
                stop_write_count = stop_write_count + 1;
                $display("SHORTTRACE_STOP_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b",
                         stop_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb);
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        finish_now("TIMEOUT");
    end
endmodule
