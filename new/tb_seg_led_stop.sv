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
    localparam integer STUCK_PC_LIMIT = 200000;
    localparam longint HEARTBEAT_CYCLES = 1000000;

    longint cycle_count;
    integer seg_write_count;
    integer led_write_count;
    integer same_pc_count;
    reg [31:0] prev_pc;
    integer second_seg_cycle;
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
            $display("SEG_LED_STOP_TIMEOUT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led=%08h seg=%010h second_seg_cycle=%0d same_pc=%0d",
                     cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, virtual_led, virtual_seg, second_seg_cycle, same_pc_count);
            $finish;
        end
    endtask


    task automatic finish_fail;
        input [127:0] reason;
        begin
            $display("SEG_LED_STOP_FAIL reason=%0s cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h second_seg_cycle=%0d same_pc=%0d",
                     reason, cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, led_write_count, virtual_led, virtual_seg,
                     second_seg_cycle, same_pc_count);
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
        same_pc_count = 0;
        prev_pc = 32'b0;
        second_seg_cycle = 0;

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

            if (cycle_count > 100 && dut.pc < 32'h8000_0000) begin
                finish_fail("RUNAWAY_LOW_PC");
            end

            if (same_pc_count >= STUCK_PC_LIMIT) begin
                finish_fail("STUCK_SAME_PC");
            end

            if ((cycle_count % HEARTBEAT_CYCLES) == 0) begin
                $display("SEG_LED_HEARTBEAT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h",
                         cycle_count, $time, dut.pc, dut.instruction,
                         seg_write_count, led_write_count, virtual_led, virtual_seg);
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == SEG_ADDR)) begin
                seg_write_count = seg_write_count + 1;
                $display("SEG_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vseg=%010h",
                         seg_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb, virtual_seg);
                if (seg_write_count == 2) begin
                    second_seg_cycle = cycle_count;
                end
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == LED_ADDR)) begin
                led_write_count = led_write_count + 1;
                $display("LED_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b seg_writes=%0d vseg=%010h",
                         led_write_count, cycle_count, $time, dut.pc, dut.instruction,
                         dut.perip_wdata, dut.perip_wstrb, seg_write_count, virtual_seg);
                $display("SEG_LED_STOP_DONE led=%08h seg=%010h seg_wdata=%08h seg_writes=%0d led_writes=%0d",
                         virtual_led, virtual_seg, dut.bridge_inst.seg_wdata,
                         seg_write_count, led_write_count);
                $finish;
            end

        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        finish_timeout();
    end
endmodule
