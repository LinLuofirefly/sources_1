`timescale 1ns / 1ps

module tb_verilator_trace;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer DONE_HOLD_CYCLES    = 64;
    localparam [31:0]  DONE_PC             = 32'h8000_0010;
    localparam [31:0]  DONE_INST           = 32'h0000_006f;

    integer cycle_count;
    integer bp_total_count;
    integer bp_hit_count;
    integer bp_miss_count;
    integer bp_pred_taken_count;
    integer bp_actual_taken_count;
    integer done_pc_stable_count;
    integer seg_change_count;
    integer raw_bp_total_count;
    integer raw_bp_hit_count;
    integer raw_b_total_count;
    integer raw_b_hit_count;
    integer raw_jal_total_count;
    integer raw_jal_hit_count;
    integer raw_jalr_total_count;
    integer raw_jalr_hit_count;

    reg [31:0] last_led;
    reg [31:0] last_seg_wdata;
    reg [31:0] seg_first_value;
    reg [31:0] seg_second_value;
    reg [31:0] seg_third_value;
    real       bp_accuracy_pct;
    real       raw_bp_accuracy_pct;
    real       raw_b_accuracy_pct;
    real       raw_jal_accuracy_pct;
    real       raw_jalr_accuracy_pct;
    reg        saw_visible_activity;

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

    task automatic print_summary;
        input [255:0] reason;
        begin
            $display("STOP_REASON=%0s", reason);
            $display("FINAL_CYCLE=%0d FINAL_TIME=%0t", cycle_count, $time);
            $display("FINAL_PC=%08h FINAL_INST=%08h", dut.pc, dut.instruction);
            $display("FINAL_LED=%08h", virtual_led);
            $display("FINAL_SEG=%010h", virtual_seg);
            $display("FINAL_SEG_WDATA=%08h", dut.bridge_inst.seg_wdata);
            $display("BP_STATS total=%0d hit=%0d miss=%0d pred_taken=%0d actual_taken=%0d",
                     bp_total_count, bp_hit_count, bp_miss_count,
                     bp_pred_taken_count, bp_actual_taken_count);
            if (bp_total_count != 0) begin
                bp_accuracy_pct = (bp_hit_count * 100.0) / bp_total_count;
                $display("BP_ACCURACY_PCT=%0.4f", bp_accuracy_pct);
            end else begin
                $display("BP_ACCURACY_PCT=0.0000");
            end

            $display("RAW_BP_STATS total=%0d hit=%0d", raw_bp_total_count, raw_bp_hit_count);
            $display("RAW_B_STATS total=%0d hit=%0d", raw_b_total_count, raw_b_hit_count);
            $display("RAW_JAL_STATS total=%0d hit=%0d", raw_jal_total_count, raw_jal_hit_count);
            $display("RAW_JALR_STATS total=%0d hit=%0d", raw_jalr_total_count, raw_jalr_hit_count);

            if (raw_bp_total_count != 0) begin
                raw_bp_accuracy_pct = (raw_bp_hit_count * 100.0) / raw_bp_total_count;
                $display("RAW_BP_ACCURACY_PCT=%0.4f", raw_bp_accuracy_pct);
            end else begin
                $display("RAW_BP_ACCURACY_PCT=0.0000");
            end

            if (raw_b_total_count != 0) begin
                raw_b_accuracy_pct = (raw_b_hit_count * 100.0) / raw_b_total_count;
                $display("RAW_B_ACCURACY_PCT=%0.4f", raw_b_accuracy_pct);
            end else begin
                $display("RAW_B_ACCURACY_PCT=0.0000");
            end

            if (raw_jal_total_count != 0) begin
                raw_jal_accuracy_pct = (raw_jal_hit_count * 100.0) / raw_jal_total_count;
                $display("RAW_JAL_ACCURACY_PCT=%0.4f", raw_jal_accuracy_pct);
            end else begin
                $display("RAW_JAL_ACCURACY_PCT=0.0000");
            end

            if (raw_jalr_total_count != 0) begin
                raw_jalr_accuracy_pct = (raw_jalr_hit_count * 100.0) / raw_jalr_total_count;
                $display("RAW_JALR_ACCURACY_PCT=%0.4f", raw_jalr_accuracy_pct);
            end else begin
                $display("RAW_JALR_ACCURACY_PCT=0.0000");
            end
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;

        cycle_count          = 0;
        bp_total_count       = 0;
        bp_hit_count         = 0;
        bp_miss_count        = 0;
        bp_pred_taken_count  = 0;
        bp_actual_taken_count = 0;
        done_pc_stable_count = 0;
        seg_change_count     = 0;
        raw_bp_total_count   = 0;
        raw_bp_hit_count     = 0;
        raw_b_total_count    = 0;
        raw_b_hit_count      = 0;
        raw_jal_total_count  = 0;
        raw_jal_hit_count    = 0;
        raw_jalr_total_count = 0;
        raw_jalr_hit_count   = 0;
        last_led             = 32'hffff_ffff;
        last_seg_wdata       = 32'hffff_ffff;
        seg_first_value      = 32'h0000_0000;
        seg_second_value     = 32'h0000_0000;
        seg_third_value      = 32'h0000_0000;
        bp_accuracy_pct      = 0.0;
        raw_bp_accuracy_pct  = 0.0;
        raw_b_accuracy_pct   = 0.0;
        raw_jal_accuracy_pct = 0.0;
        raw_jalr_accuracy_pct = 0.0;
        saw_visible_activity = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        forever @(posedge w_cpu_clk);
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (virtual_led !== last_led) begin
                $display("LED_CHANGE CYC=%0d TIME=%0t DATA=%08h", cycle_count, $time, virtual_led);
                last_led = virtual_led;
                saw_visible_activity = 1'b1;
            end

            if (dut.bridge_inst.seg_wdata !== last_seg_wdata) begin
                $display("SEG_WDATA_CHANGE CYC=%0d TIME=%0t DATA=%08h", cycle_count, $time, dut.bridge_inst.seg_wdata);
                if (seg_change_count == 0) begin
                    seg_first_value = dut.bridge_inst.seg_wdata;
                end else if (seg_change_count == 1) begin
                    seg_second_value = dut.bridge_inst.seg_wdata;
                end else if (seg_change_count == 2) begin
                    seg_third_value = dut.bridge_inst.seg_wdata;
                end
                seg_change_count = seg_change_count + 1;
                last_seg_wdata = dut.bridge_inst.seg_wdata;
                saw_visible_activity = 1'b1;
            end

            if (dut.bridge_inst.perip_write_req && dut.perip_addr == 32'h8020_0040) begin
                $display("FIRST_LED_WRITE CYC=%0d TIME=%0t DATA=%08h", cycle_count, $time, dut.perip_wdata);
                $display("SEG_WDATA_FIRST=%08h", seg_first_value);
                $display("SEG_WDATA_SECOND=%08h", seg_second_value);
                $display("SEG_WDATA_THIRD=%08h", seg_third_value);
                print_summary("FIRST_LED_WRITE_REACHED");
                $finish;
            end

            if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                bp_total_count = bp_total_count + 1;

                if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                    bp_pred_taken_count = bp_pred_taken_count + 1;
                end

                if (dut.Core_cpu.cpu_core.bp_actual_taken_o) begin
                    bp_actual_taken_count = bp_actual_taken_count + 1;
                end

                if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o == dut.Core_cpu.cpu_core.bp_actual_taken_o) begin
                    bp_hit_count = bp_hit_count + 1;
                end else begin
                    bp_miss_count = bp_miss_count + 1;
                end

            end

            if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                raw_bp_total_count = raw_bp_total_count + 1;
                raw_b_total_count  = raw_b_total_count + 1;
                if (dut.Core_cpu.cpu_core.id_ex_raw_pred_taken_o == dut.Core_cpu.cpu_core.bp_actual_taken_o) begin
                    raw_bp_hit_count = raw_bp_hit_count + 1;
                    raw_b_hit_count  = raw_b_hit_count + 1;
                end
            end

            if (!dut.Core_cpu.cpu_core.ctrl_kill_ex_o && (dut.Core_cpu.cpu_core.id_ex_inst_o[6:0] == 7'b1101111)) begin
                raw_bp_total_count   = raw_bp_total_count + 1;
                raw_jal_total_count  = raw_jal_total_count + 1;
                if (dut.Core_cpu.cpu_core.id_ex_raw_pred_taken_o == 1'b1) begin
                    raw_bp_hit_count  = raw_bp_hit_count + 1;
                    raw_jal_hit_count = raw_jal_hit_count + 1;
                end
            end

            if (!dut.Core_cpu.cpu_core.ctrl_kill_ex_o && (dut.Core_cpu.cpu_core.id_ex_inst_o[6:0] == 7'b1100111)) begin
                raw_bp_total_count    = raw_bp_total_count + 1;
                raw_jalr_total_count  = raw_jalr_total_count + 1;
                if (dut.Core_cpu.cpu_core.id_ex_raw_pred_taken_o == 1'b1) begin
                    raw_bp_hit_count   = raw_bp_hit_count + 1;
                    raw_jalr_hit_count = raw_jalr_hit_count + 1;
                end
            end

            if (dut.pc < 32'h8000_0000) begin
                print_summary("RUNAWAY_LOW_PC");
                $finish;
            end

            if (saw_visible_activity && dut.pc == DONE_PC && dut.instruction == DONE_INST) begin
                done_pc_stable_count = done_pc_stable_count + 1;
            end else begin
                done_pc_stable_count = 0;
            end

            if (done_pc_stable_count >= DONE_HOLD_CYCLES) begin
                print_summary("PROGRAM_COMPLETED_AT_FINAL_SPIN");
                $finish;
            end
        end
    end
endmodule
