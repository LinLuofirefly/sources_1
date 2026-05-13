`timescale 1ns / 1ps

module tb_ex_predecode_2000;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    integer cycle_count;
    reg seen_seg_37000000;

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
    always #3 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        virtual_key       = 8'd0;
        virtual_sw        = 64'd0;
        w_clk_rst         = 1'b1;
        cycle_count       = 0;
        seen_seg_37000000 = 1'b0;

        #100;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count <= cycle_count + 1;

            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr  == 32'h8020_0020 &&
                dut.perip_wdata == 32'h3700_0000) begin
                seen_seg_37000000 <= 1'b1;
                $display("PASS: saw SEG write 37000000 at cycle %0d time %0t", cycle_count, $time);
                $finish;
            end

            if (cycle_count >= 2000) begin
                $display("FAIL: no SEG write 37000000 within 2000 cycles");
                $display("FINAL_PC=%08h FINAL_SEG_WDATA=%08h", dut.pc, dut.bridge_inst.seg_wdata);
                $finish;
            end
        end
    end

endmodule
