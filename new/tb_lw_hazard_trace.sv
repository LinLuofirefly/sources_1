`timescale 1ns / 1ps

module tb_lw_hazard_trace;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer CPU_CYCLES_MAX   = 2_000;
    localparam integer TRACE_START_CYC  = 820;
    localparam integer TRACE_END_CYC    = 880;

    integer cycle_count;

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

        #20;
        w_clk_rst = 1'b0;

        repeat (CPU_CYCLES_MAX) @(posedge w_cpu_clk);

        $display("LW_TRACE_DONE CYC=%0d PC=%08h INST=%08h SEG=%08h",
                 cycle_count, dut.pc, dut.instruction, dut.bridge_inst.seg_wdata);
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (cycle_count >= TRACE_START_CYC && cycle_count <= TRACE_END_CYC) begin
                $display(
                    "LWTRACE CYC=%0d PC=%08h INST=%08h IFID=%08h IDEX=%08h EXMEM=%08h MEM1=%08h M12=%08h M2A=%08h M2=%08h HOLD=%0d HFLUSH=%0d JFLUSH=%0d KILL=%0d F1=%08h F2=%08h M12RD=%08h M2RD=%08h RAMRD=%08h PRDEN=%0d PRDADDR=%08h",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem2_align_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_kill_ex_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_op2_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,
                    dut.perip_rdata,
                    dut.perip_rd_en,
                    dut.perip_rd_addr
                );
            end

            if (dut.pc < 32'h0000_0100) begin
                $display("LWTRACE_RUNAWAY CYC=%0d PC=%08h INST=%08h", cycle_count, dut.pc, dut.instruction);
                $finish;
            end
        end
    end
endmodule
