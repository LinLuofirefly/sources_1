`timescale 1ns / 1ps

module tb_150m_runaway_trace;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer CPU_CYCLES_MAX = 2000;

    integer cycle_count;
    integer trace_left;
    reg seen_65c;

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
    always #3.333 w_cpu_clk = ~w_cpu_clk;   // about 150 MHz

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        trace_left  = 0;
        seen_65c    = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        repeat (CPU_CYCLES_MAX) @(posedge w_cpu_clk);

        $display("TRACE150_DONE CYC=%0d T=%0t PC=%08h INST=%08h SEG=%08h",
                 cycle_count, $time, dut.pc, dut.instruction, dut.bridge_inst.seg_wdata);
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (!seen_65c && dut.pc == 32'h8000_065c) begin
                seen_65c   = 1'b1;
                trace_left = 80;
                $display("SEEN_65C_150 CYC=%0d T=%0t PC=%08h INST=%08h",
                         cycle_count, $time, dut.pc, dut.instruction);
            end

            if (trace_left > 0) begin
                trace_left = trace_left - 1;
                $display(
                    "TRACE150 CYC=%0d T=%0t PC=%08h INST=%08h IFID=%08h IDEX=%08h EXMEM=%08h EXJ=%0d KILL=%0d HLD=%0d HFL=%0d JFL=%0d RA=%08h SP=%08h SEG=%08h RDEN=%0d RDADDR=%08h RDATA=%08h",
                    cycle_count,
                    $time,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_kill_ex_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.bridge_inst.seg_wdata,
                    dut.perip_rd_en,
                    dut.perip_rd_addr,
                    dut.perip_rdata
                );
            end

            if (dut.pc < 32'h8000_0000) begin
                $display("RUNAWAY_150 CYC=%0d T=%0t PC=%08h INST=%08h RA=%08h SP=%08h",
                         cycle_count, $time, dut.pc, dut.instruction,
                         dut.Core_cpu.cpu_core.regs_inst.regs[1],
                         dut.Core_cpu.cpu_core.regs_inst.regs[2]);
                $finish;
            end
        end
    end
endmodule
