`timescale 1ns / 1ps

module tb_runaway_check;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer CPU_CYCLES_MAX = 200_000;

    integer cycle_count;
    integer after_65c;
    reg seen_65c;
    reg seen_seg_write;
    reg seen_led_write;

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
    always #1 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #2 w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        after_65c   = 0;
        seen_65c    = 1'b0;
        seen_seg_write = 1'b0;
        seen_led_write = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        repeat (CPU_CYCLES_MAX) @(posedge w_cpu_clk);

        $display("RUNAWAY_CHECK_DONE CYC=%0d PC=%08h INST=%08h SEEN_65C=%0d SEG=%08h LED=%08h",
                 cycle_count, dut.pc, dut.instruction, seen_65c, dut.bridge_inst.seg_wdata, virtual_led);
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (dut.pc == 32'h8000_065c && !seen_65c) begin
                seen_65c  = 1'b1;
                after_65c = 120;
                $display("SEEN_65C CYC=%0d PC=%08h INST=%08h", cycle_count, dut.pc, dut.instruction);
            end

            if (seen_65c && after_65c > 0) begin
                after_65c = after_65c - 1;
                if (dut.pc < 32'h8000_0000) begin
                    $display("RUNAWAY_AFTER_65C CYC=%0d PC=%08h INST=%08h", cycle_count, dut.pc, dut.instruction);
                    $finish;
                end
            end

            if (dut.pc < 32'h0000_0100) begin
                $display("RUNAWAY_LOW_PC CYC=%0d PC=%08h INST=%08h", cycle_count, dut.pc, dut.instruction);
                $finish;
            end

            if (!seen_seg_write && dut.perip_wstrb != 4'b0000 && dut.perip_addr == 32'h8020_0020) begin
                seen_seg_write = 1'b1;
                $display("FIRST_SEG_WRITE CYC=%0d PC=%08h INST=%08h DATA=%08h SEG=%08h",
                         cycle_count, dut.pc, dut.instruction, dut.perip_wdata, dut.bridge_inst.seg_wdata);
            end

            if (!seen_led_write && dut.perip_wstrb != 4'b0000 && dut.perip_addr == 32'h8020_0040) begin
                seen_led_write = 1'b1;
                $display("FIRST_LED_WRITE CYC=%0d PC=%08h INST=%08h DATA=%08h",
                         cycle_count, dut.pc, dut.instruction, dut.perip_wdata);
            end
        end
    end
endmodule
