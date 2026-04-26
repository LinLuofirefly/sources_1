`timescale 1ns / 1ps

module tb_400ms_silent_watch;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer CPU_CYCLES_MAX     = 60006000;
    localparam integer HEARTBEAT_CYCLES   = 200000;
    localparam integer TRACE_CYCLES       = 96;
    localparam integer LOOP_REPEAT_LIMIT  = 2000000;
    localparam integer WAIT_LOOP_LIMIT    = 1000000;

    integer cycle_count;
    integer nonzero_seg_write_count;
    integer event_trace_left;
    integer next_heartbeat_cycle;
    integer pc_rep1_count;
    integer pc_rep2_count;
    integer pc_rep4_count;
    integer pc_rep8_count;
    integer wait_loop_cycles;

    reg [31:0] pc_d1;
    reg [31:0] pc_d2;
    reg [31:0] pc_d3;
    reg [31:0] pc_d4;
    reg [31:0] pc_d5;
    reg [31:0] pc_d6;
    reg [31:0] pc_d7;
    reg [31:0] pc_d8;

    reg loop_flagged;
    reg dump_enabled;
    reg dump_initialized;

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

    task automatic start_trace_window;
        begin
            event_trace_left = TRACE_CYCLES;
            if (!dump_initialized) begin
                dump_initialized = 1'b1;
                $dumpfile("sim_400ms_watch.vcd");
                $dumpvars(0, tb_400ms_silent_watch);
            end
            if (!dump_enabled) begin
                dump_enabled = 1'b1;
                $dumpon;
            end
        end
    endtask

    task automatic stop_with_summary;
        input [255:0] reason;
        begin
            $display("STOP_REASON=%0s", reason);
            $display("STOP_CYC=%0d TIME=%0t PC=%08h INST=%08h", cycle_count, $time, dut.pc, dut.instruction);
            $display("STOP_SEG_WDATA=%08h STOP_LED=%08h", dut.bridge_inst.seg_wdata, virtual_led);
            $display("STOP_BP_ACC=%0d HOLD=%0d HFLUSH=%0d IFID_FLUSH=%0d IDEX_FLUSH=%0d",
                     dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                     dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                     dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                     dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                     dut.Core_cpu.cpu_core.ctrl_flush_idex_o);
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        nonzero_seg_write_count = 0;
        event_trace_left = 0;
        next_heartbeat_cycle = HEARTBEAT_CYCLES;
        pc_rep1_count = 0;
        pc_rep2_count = 0;
        pc_rep4_count = 0;
        pc_rep8_count = 0;
        wait_loop_cycles = 0;
        pc_d1 = 32'd0;
        pc_d2 = 32'd0;
        pc_d3 = 32'd0;
        pc_d4 = 32'd0;
        pc_d5 = 32'd0;
        pc_d6 = 32'd0;
        pc_d7 = 32'd0;
        pc_d8 = 32'd0;
        loop_flagged = 1'b0;
        dump_enabled = 1'b0;
        dump_initialized = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        repeat (CPU_CYCLES_MAX) @(posedge w_cpu_clk);

        $display("SIM_400MS_DONE CYC=%0d TIME=%0t PC=%08h INST=%08h", cycle_count, $time, dut.pc, dut.instruction);
        $display("FINAL_SEG_WDATA=%08h FINAL_LED=%08h NONZERO_SEG_WRITES=%0d",
                 dut.bridge_inst.seg_wdata, virtual_led, nonzero_seg_write_count);
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (cycle_count == next_heartbeat_cycle) begin
                $display("HEARTBEAT CYC=%0d TIME=%0t PC=%08h INST=%08h SEG=%08h LED=%08h NZSEG=%0d",
                         cycle_count, $time, dut.pc, dut.instruction, dut.bridge_inst.seg_wdata,
                         virtual_led, nonzero_seg_write_count);
                next_heartbeat_cycle = next_heartbeat_cycle + HEARTBEAT_CYCLES;
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == 32'h8020_0020 && dut.perip_wdata != 32'h0000_0000) begin
                nonzero_seg_write_count = nonzero_seg_write_count + 1;
                $display("NONZERO_SEG_WRITE #%0d CYC=%0d TIME=%0t PC=%08h INST=%08h DATA=%08h",
                         nonzero_seg_write_count, cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                start_trace_window();
                if (nonzero_seg_write_count >= 2) begin
                    stop_with_summary("SECOND_NONZERO_SEG_WRITE");
                end
            end

            if (dut.pc < 32'h0000_0100) begin
                start_trace_window();
                stop_with_summary("RUNAWAY_LOW_PC");
            end

            if (dut.pc == pc_d1) pc_rep1_count = pc_rep1_count + 1; else pc_rep1_count = 0;
            if (dut.pc == pc_d2) pc_rep2_count = pc_rep2_count + 1; else pc_rep2_count = 0;
            if (dut.pc == pc_d4) pc_rep4_count = pc_rep4_count + 1; else pc_rep4_count = 0;
            if (dut.pc == pc_d8) pc_rep8_count = pc_rep8_count + 1; else pc_rep8_count = 0;

            if (!loop_flagged &&
                ((pc_rep1_count > LOOP_REPEAT_LIMIT) ||
                 (pc_rep2_count > LOOP_REPEAT_LIMIT) ||
                 (pc_rep4_count > LOOP_REPEAT_LIMIT) ||
                 (pc_rep8_count > LOOP_REPEAT_LIMIT))) begin
                loop_flagged = 1'b1;
                $display("LOOP_SUSPECT CYC=%0d TIME=%0t PC=%08h INST=%08h REP1=%0d REP2=%0d REP4=%0d REP8=%0d",
                         cycle_count, $time, dut.pc, dut.instruction,
                         pc_rep1_count, pc_rep2_count, pc_rep4_count, pc_rep8_count);
                start_trace_window();
                stop_with_summary("TIGHT_PC_LOOP");
            end

            if (nonzero_seg_write_count >= 1 &&
                dut.pc >= 32'h8000_034c &&
                dut.pc <= 32'h8000_0378) begin
                wait_loop_cycles = wait_loop_cycles + 1;
            end else begin
                wait_loop_cycles = 0;
            end

            if (!loop_flagged && wait_loop_cycles > WAIT_LOOP_LIMIT) begin
                loop_flagged = 1'b1;
                $display("WAIT_LOOP_SUSPECT CYC=%0d TIME=%0t PC=%08h INST=%08h LOOP_CYC=%0d SEG=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, wait_loop_cycles,
                         dut.bridge_inst.seg_wdata);
                start_trace_window();
                stop_with_summary("WAIT_LOOP_AFTER_FIRST_NONZERO_SEG");
            end

            pc_d8 <= pc_d7;
            pc_d7 <= pc_d6;
            pc_d6 <= pc_d5;
            pc_d5 <= pc_d4;
            pc_d4 <= pc_d3;
            pc_d3 <= pc_d2;
            pc_d2 <= pc_d1;
            pc_d1 <= dut.pc;

            if (event_trace_left > 0) begin
                event_trace_left = event_trace_left - 1;
                $display(
                    "TRACE CYC=%0d TIME=%0t PC=%08h INST=%08h IFID_A=%08h IFID_I=%08h IDEX_A=%08h IDEX_I=%08h EXJ=%0d CTRLJ=%0d BPACC=%0d BPD1=%0d HOLD=%0d HFL=%0d IFFL=%0d IDFL=%0d SEG=%08h",
                    cycle_count,
                    $time,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.bp_pred_flush_d1_r,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.bridge_inst.seg_wdata
                );
                if (event_trace_left == 1 && dump_enabled) begin
                    dump_enabled = 1'b0;
                    $dumpoff;
                end
            end
        end
    end
endmodule
