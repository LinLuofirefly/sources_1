`timescale 1ns / 1ps
`include "defines.v"

`ifndef TB_CPU_HALF_PERIOD_NS
`define TB_CPU_HALF_PERIOD_NS 2.380952
`endif

module tb_seg_led_stop;
    reg         w_cpu_clk   = 1'b0;
    reg         w_clk_50Mhz = 1'b0;
    reg         w_clk_rst   = 1'b1;
    reg  [7:0]  virtual_key = 8'd0;
    reg  [63:0] virtual_sw  = 64'd0;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam [31:0] LED_ADDR = 32'h8020_0040;
    localparam [6:0]  OPC_BRANCH = 7'b1100011;
    localparam [6:0]  OPC_JAL    = 7'b1101111;
    localparam [6:0]  OPC_JALR   = 7'b1100111;
    localparam integer TB_BHT_SIZE = (1 << `BP_GHR_WIDTH);
    localparam time SIM_TIME_LIMIT_NS = 64'd30_000_000_000;
    localparam integer STUCK_PC_LIMIT = 200000;
    localparam integer LOW_PC_LIMIT = 32;

    localparam [3:0] CAUSE_NONE          = 4'd0;
    localparam [3:0] CAUSE_PIPE_FILL     = 4'd1;
    localparam [3:0] CAUSE_DCACHE_MISS   = 4'd2;
    localparam [3:0] CAUSE_DCACHE_HIT    = 4'd3;
    localparam [3:0] CAUSE_LOAD_USE      = 4'd4;
    localparam [3:0] CAUSE_MUL_WAIT      = 4'd5;
    localparam [3:0] CAUSE_DIV_WAIT      = 4'd6;
    localparam [3:0] CAUSE_BRANCH        = 4'd7;
    localparam [3:0] CAUSE_JAL           = 4'd8;
    localparam [3:0] CAUSE_JALR          = 4'd9;
    localparam [3:0] CAUSE_LATE_PRED_TAKEN = 4'd10;
    localparam [3:0] CAUSE_REPLAY        = 4'd11;
    localparam [3:0] CAUSE_MMIO          = 4'd12;
    localparam [3:0] CAUSE_STRUCTURAL    = 4'd13;
    localparam [3:0] CAUSE_FRONTEND      = 4'd14;
    localparam [3:0] CAUSE_OTHER         = 4'd15;

    longint cycle_count;
    integer seg_write_count;
    integer led_write_count;
    integer same_pc_count;
    integer low_pc_count;
    reg [31:0] prev_pc;
    longint bp_branch_total;
    longint bp_branch_correct;
    longint bp_branch_miss;
    longint bp_actual_taken_count;
    longint bp_pred_taken_count;
    longint bp_taken_correct;
    longint bp_not_taken_correct;
    longint bp_if_valid_count;
    longint bp_fetch_pred_taken_count;
    longint bp_pred_accept_count;
    longint bp_fetch_redirect_count;
    longint bp_replay_redirect_count;
    longint bp_ex_redirect_count;
    longint bp_req_btb_hit_count;
    longint bp_early_redirect_count;
    longint bp_fetch_branch_count;
    longint bp_fetch_jal_count;
    longint bp_fetch_jalr_count;
    longint bp_fetch_other_count;
    longint bp_ras_push_count;
    longint bp_ras_pop_count;
    longint bp_ras_pred_pop_count;
    longint bp_ras_pred_valid_count;
    longint bp_ex_cond_redirect_count;
    longint bp_ex_jal_redirect_count;
    longint bp_ex_jalr_redirect_count;
    longint bp_ex_other_redirect_count;
    longint bp_jal_total;
    longint bp_jal_pred_taken_count;
    longint bp_jal_target_correct_count;
    longint bp_jal_miss_count;
    longint bp_jalr_total;
    longint bp_jalr_pred_taken_count;
    longint bp_jalr_target_correct_count;
    longint bp_jalr_no_pred_count;
    longint bp_jalr_wrong_target_count;
    longint bp_return_total;
    longint bp_return_pred_count;
    longint bp_return_target_correct_count;
    longint bp_return_no_pred_count;
    longint bp_return_wrong_target_count;
    longint bp_nonreturn_jalr_count;
    longint retired_inst_count;
    longint load_total_count;
    longint uncached_load_count;
    longint dcache_load_count;
    longint dcache_hit_count;
    longint dcache_miss_count;
    longint dcache_refill_count;
    longint retire_0_cycles;
    longint retire_1_cycles;
    longint pipeline_fill_cycles;
    longint dcache_miss_stall_cycles;
    longint dcache_hit_wait_cycles;
    longint load_use_stall_cycles;
    longint mul_wait_cycles;
    longint div_wait_cycles;
    longint branch_recovery_cycles;
    longint jal_recovery_cycles;
    longint jalr_recovery_cycles;
    longint late_pred_taken_flush_bubble_cycles;
    longint frontend_empty_cycles;
    longint replay_hold_cycles;
    longint mmio_wait_cycles;
    longint structural_stall_cycles;
    longint other_stall_cycles;
    longint hdu_hold_cycles;
    longint hdu_flush_cycles;
    longint ifid_invalid_cycles;
    longint idex_nop_cycles;
    longint replay_pending_cycles;
    longint replay_active_cycles;
    longint late_pred_taken_flush_cycles;
    longint raw_ex_load_dep_cycles;
    longint raw_mem1_miss_dep_cycles;
    longint raw_mem1_hit_shift_dep_cycles;
    longint raw_mem2_slow_dep_cycles;
    longint raw_mdu_busy_cycles;
    longint cache_request_check_delta;
    longint cache_refill_check_delta;
    longint committed_arch_nop_count;
    longint invalid_non_nop_wb_count;
    // The RTL carries bubbles as INST_NOP and has no explicit valid bits.
    // Mirror its pipeline controls so a real ADDI x0,x0,0 still commits once.
    reg if_id_valid_r;
    reg id_ex_valid_r;
    reg ex_mem_valid_r;
    reg mem1_mem2_valid_r;
    reg mem_wb_valid_r;
    reg [3:0] if_id_cause_r;
    reg [3:0] id_ex_cause_r;
    reg [3:0] ex_mem_cause_r;
    reg [3:0] mem1_mem2_cause_r;
    reg [3:0] mem_wb_cause_r;
    reg [31:0] if_id_pc_r;
    reg [31:0] id_ex_pc_r;
    reg [31:0] ex_mem_pc_r;
    reg [31:0] mem1_mem2_pc_r;
    reg [31:0] mem_wb_pc_r;
    reg        mdu_active_r;
    reg        mdu_is_div_r;
    reg [6:0]  redirect_opcode_r;
    reg        stop_commit_pending_r;
    reg [31:0] stop_commit_pc_r;
    longint    stop_detect_cycle;

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
    always #(`TB_CPU_HALF_PERIOD_NS) w_cpu_clk = ~w_cpu_clk;
    initial w_clk_50Mhz = 1'b0;
    always #10  w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        $display("TB_CPU_CLOCK freq_mhz=%0.3f half_period_ns=%0.6f",
                 (500.0 / `TB_CPU_HALF_PERIOD_NS), (`TB_CPU_HALF_PERIOD_NS * 1.0));
        virtual_key = 8'd0; virtual_sw = 64'd0; w_clk_rst = 1'b1;
        cycle_count = 0; seg_write_count = 0; led_write_count = 0;
        same_pc_count = 0; low_pc_count = 0; prev_pc = 32'b0;
        bp_branch_total = 0; bp_branch_correct = 0; bp_branch_miss = 0;
        bp_actual_taken_count = 0; bp_pred_taken_count = 0;
        bp_taken_correct = 0; bp_not_taken_correct = 0;
        bp_if_valid_count = 0; bp_fetch_pred_taken_count = 0;
        bp_pred_accept_count = 0; bp_fetch_redirect_count = 0;
        bp_replay_redirect_count = 0; bp_ex_redirect_count = 0;
        bp_req_btb_hit_count = 0; bp_early_redirect_count = 0;
        bp_fetch_branch_count = 0; bp_fetch_jal_count = 0;
        bp_fetch_jalr_count = 0; bp_fetch_other_count = 0;
        bp_ras_push_count = 0; bp_ras_pop_count = 0;
        bp_ras_pred_pop_count = 0; bp_ras_pred_valid_count = 0;
        bp_ex_cond_redirect_count = 0; bp_ex_jal_redirect_count = 0;
        bp_ex_jalr_redirect_count = 0; bp_ex_other_redirect_count = 0;
        bp_jal_total = 0; bp_jal_pred_taken_count = 0;
        bp_jal_target_correct_count = 0; bp_jal_miss_count = 0;
        bp_jalr_total = 0; bp_jalr_pred_taken_count = 0;
        bp_jalr_target_correct_count = 0; bp_jalr_no_pred_count = 0;
        bp_jalr_wrong_target_count = 0; bp_return_total = 0;
        bp_return_pred_count = 0; bp_return_target_correct_count = 0;
        bp_return_no_pred_count = 0; bp_return_wrong_target_count = 0;
        bp_nonreturn_jalr_count = 0;
        retired_inst_count = 0; load_total_count = 0;
        uncached_load_count = 0; dcache_load_count = 0;
        dcache_hit_count = 0; dcache_miss_count = 0;
        dcache_refill_count = 0;
        retire_0_cycles = 0; retire_1_cycles = 0;
        pipeline_fill_cycles = 0;
        dcache_miss_stall_cycles = 0; dcache_hit_wait_cycles = 0;
        load_use_stall_cycles = 0;
        mul_wait_cycles = 0; div_wait_cycles = 0;
        branch_recovery_cycles = 0; jal_recovery_cycles = 0;
        jalr_recovery_cycles = 0; late_pred_taken_flush_bubble_cycles = 0;
        frontend_empty_cycles = 0; replay_hold_cycles = 0;
        mmio_wait_cycles = 0; structural_stall_cycles = 0;
        other_stall_cycles = 0;
        hdu_hold_cycles = 0; hdu_flush_cycles = 0;
        ifid_invalid_cycles = 0; idex_nop_cycles = 0;
        replay_pending_cycles = 0; replay_active_cycles = 0;
        late_pred_taken_flush_cycles = 0;
        raw_ex_load_dep_cycles = 0; raw_mem1_miss_dep_cycles = 0;
        raw_mem1_hit_shift_dep_cycles = 0; raw_mem2_slow_dep_cycles = 0;
        raw_mdu_busy_cycles = 0;
        cache_request_check_delta = 0; cache_refill_check_delta = 0;
        committed_arch_nop_count = 0; invalid_non_nop_wb_count = 0;
        if_id_valid_r = 1'b0; id_ex_valid_r = 1'b0;
        ex_mem_valid_r = 1'b0; mem1_mem2_valid_r = 1'b0;
        mem_wb_valid_r = 1'b0;
        if_id_cause_r = CAUSE_PIPE_FILL; id_ex_cause_r = CAUSE_PIPE_FILL;
        ex_mem_cause_r = CAUSE_PIPE_FILL; mem1_mem2_cause_r = CAUSE_PIPE_FILL;
        mem_wb_cause_r = CAUSE_PIPE_FILL;
        if_id_pc_r = 32'b0; id_ex_pc_r = 32'b0; ex_mem_pc_r = 32'b0;
        mem1_mem2_pc_r = 32'b0; mem_wb_pc_r = 32'b0;
        mdu_active_r = 1'b0; mdu_is_div_r = 1'b0;
        redirect_opcode_r = 7'b0;
        stop_commit_pending_r = 1'b0;
        stop_commit_pc_r = 32'b0;
        stop_detect_cycle = 0;
        #20; w_clk_rst = 1'b0;
    end

    function real pct;
        input longint num;
        input longint den;
        begin
            if (den != 0) pct = (100.0 * num) / den;
            else pct = 0.0;
        end
    endfunction

    function real per_inst;
        input longint num;
        begin
            if (retired_inst_count != 0) per_inst = (1.0 * num) / retired_inst_count;
            else per_inst = 0.0;
        end
    endfunction

    function is_div_or_rem_inst;
        input [31:0] inst;
        begin
            is_div_or_rem_inst =
                (inst[6:0] == `INST_TYPE_R_M) &&
                (inst[31:25] == `INST_FUNC7_M) &&
                (inst[14] == 1'b1);
        end
    endfunction

    function [3:0] redirect_cause;
        input [6:0] opcode;
        begin
            case (opcode)
                OPC_BRANCH: redirect_cause = CAUSE_BRANCH;
                OPC_JAL:    redirect_cause = CAUSE_JAL;
                OPC_JALR:   redirect_cause = CAUSE_JALR;
                default:    redirect_cause = CAUSE_OTHER;
            endcase
        end
    endfunction

    task print_cpi_cause;
        input [160*8-1:0] name;
        input longint cycles;
        begin
            $display("CPI_CAUSE name=%0s cycles=%0d cpi=%0.4f share_retire0=%0.2f%%",
                     name,
                     cycles,
                     per_inst(cycles),
                     pct(cycles, retire_0_cycles));
        end
    endtask

    task print_perf_stats;
        real cpi;
        real ipc;
        longint attributed0_cycles;
        longint known0_cycles;
        longint cycle_check_delta;
        longint retire_check_delta;
        begin
            if (retired_inst_count != 0) begin
                cpi = (1.0 * cycle_count) / retired_inst_count;
                ipc = (1.0 * retired_inst_count) / cycle_count;
            end else begin
                cpi = 0.0;
                ipc = 0.0;
            end

            attributed0_cycles =
                pipeline_fill_cycles +
                dcache_miss_stall_cycles +
                dcache_hit_wait_cycles +
                load_use_stall_cycles +
                mul_wait_cycles +
                div_wait_cycles +
                branch_recovery_cycles +
                jal_recovery_cycles +
                jalr_recovery_cycles +
                late_pred_taken_flush_bubble_cycles +
                frontend_empty_cycles +
                replay_hold_cycles +
                mmio_wait_cycles +
                structural_stall_cycles +
                other_stall_cycles;
            known0_cycles = attributed0_cycles - other_stall_cycles;
            cycle_check_delta = cycle_count - retire_0_cycles - retire_1_cycles;
            retire_check_delta = retired_inst_count - retire_1_cycles;
            cache_request_check_delta =
                dcache_load_count - dcache_hit_count - dcache_miss_count;
            if (dcache_refill_count > dcache_miss_count) begin
                cache_refill_check_delta = dcache_refill_count - dcache_miss_count;
            end else begin
                cache_refill_check_delta = 0;
            end

            $display("PERF_STATS cycles=%0d retired=%0d cpi=%0.4f ipc=%0.4f loads=%0d uncached_loads=%0d",
                     cycle_count,
                     retired_inst_count,
                     cpi,
                     ipc,
                     load_total_count,
                     uncached_load_count);
            $display("COMMIT_CHECK arch_nop_commits=%0d invalid_non_nop_wb=%0d",
                     committed_arch_nop_count,
                     invalid_non_nop_wb_count);
            $display("CACHE_STATS dcache_dram_loads=%0d hits=%0d misses=%0d refills=%0d hit_rate=%0.2f%% miss_rate=%0.2f%%",
                     dcache_load_count,
                     dcache_hit_count,
                     dcache_miss_count,
                     dcache_refill_count,
                     pct(dcache_hit_count, dcache_load_count),
                     pct(dcache_miss_count, dcache_load_count));
            $display("CACHE_CHECK request_minus_hit_miss=%0d refill_gt_miss=%0d",
                     cache_request_check_delta,
                     cache_refill_check_delta);
            $display("PERF_CPI_SUM cycles=%0d retired=%0d retire_1_cycles=%0d retire_0_cycles=%0d cpi=%0.4f excess_cpi=%0.4f known0=%0d other0=%0d accounted0=%0d check_delta=%0d cycle_delta=%0d retire_delta=%0d known_coverage=%0.2f%%",
                     cycle_count,
                     retired_inst_count,
                     retire_1_cycles,
                     retire_0_cycles,
                     cpi,
                     per_inst(retire_0_cycles),
                     known0_cycles,
                     other_stall_cycles,
                     attributed0_cycles,
                     retire_0_cycles - attributed0_cycles,
                     cycle_check_delta,
                     retire_check_delta,
                     pct(known0_cycles, retire_0_cycles));
            print_cpi_cause("pipeline_fill", pipeline_fill_cycles);
            print_cpi_cause("dcache_miss_dependency", dcache_miss_stall_cycles);
            print_cpi_cause("dcache_hit_shift_wait", dcache_hit_wait_cycles);
            print_cpi_cause("load_use", load_use_stall_cycles);
            print_cpi_cause("div_wait", div_wait_cycles);
            print_cpi_cause("mul_wait", mul_wait_cycles);
            print_cpi_cause("branch_recovery", branch_recovery_cycles);
            print_cpi_cause("jal_recovery", jal_recovery_cycles);
            print_cpi_cause("jalr_recovery", jalr_recovery_cycles);
            print_cpi_cause("late_pred_taken_flush_bubble", late_pred_taken_flush_bubble_cycles);
            print_cpi_cause("replay_hold", replay_hold_cycles);
            print_cpi_cause("mmio_wait", mmio_wait_cycles);
            print_cpi_cause("structural_stall", structural_stall_cycles);
            print_cpi_cause("frontend_empty", frontend_empty_cycles);
            print_cpi_cause("other", other_stall_cycles);
            $display("RAW_STALL_SIGNALS hdu_hold=%0d hdu_flush=%0d ifid_invalid=%0d idex_nop=%0d replay_pending=%0d replay_active=%0d late_pred_taken_flush=%0d ex_load_dep=%0d mem1_miss_dep=%0d mem1_hit_shift_dep=%0d mem2_slow_dep=%0d mdu_busy=%0d",
                     hdu_hold_cycles,
                     hdu_flush_cycles,
                     ifid_invalid_cycles,
                     idex_nop_cycles,
                     replay_pending_cycles,
                     replay_active_cycles,
                     late_pred_taken_flush_cycles,
                     raw_ex_load_dep_cycles,
                     raw_mem1_miss_dep_cycles,
                     raw_mem1_hit_shift_dep_cycles,
                     raw_mem2_slow_dep_cycles,
                     raw_mdu_busy_cycles);
        end
    endtask

    function [31:0] jal_target;
        input [31:0] pc;
        input [31:0] inst;
        reg [31:0] imm;
        begin
            imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
            jal_target = pc + imm;
        end
    endfunction

    function is_return_jalr;
        input [31:0] inst;
        begin
            is_return_jalr =
                (inst[6:0]   == OPC_JALR) &&
                (inst[14:12] == 3'b000) &&
                (inst[11:7]  == 5'd0) &&
                ((inst[19:15] == 5'd1) || (inst[19:15] == 5'd5)) &&
                (inst[31:20] == 12'd0);
        end
    endfunction

    task print_bp_stats;
        real accuracy;
        longint actual_not_taken_count;
        longint pred_not_taken_count;
        longint false_taken_count;
        longint false_not_taken_count;
        integer bht_idx;
        integer bht_valid_count;
        integer bht_snt_count;
        integer bht_wnt_count;
        integer bht_wt_count;
        integer bht_st_count;
        integer ras_top_idx;
        begin
            if (bp_branch_total != 0) begin
                accuracy = (100.0 * bp_branch_correct) / bp_branch_total;
            end else begin
                accuracy = 0.0;
            end
            actual_not_taken_count = bp_branch_total - bp_actual_taken_count;
            pred_not_taken_count = bp_branch_total - bp_pred_taken_count;
            false_not_taken_count = bp_actual_taken_count - bp_taken_correct;
            false_taken_count = actual_not_taken_count - bp_not_taken_correct;

            bht_valid_count = 0;
            bht_snt_count = 0;
            bht_wnt_count = 0;
            bht_wt_count = 0;
            bht_st_count = 0;
            for (bht_idx = 0; bht_idx < TB_BHT_SIZE; bht_idx = bht_idx + 1) begin
                if (dut.Core_cpu.cpu_core.branch_predictor_inst.bht_valid[bht_idx]) begin
                    bht_valid_count = bht_valid_count + 1;
                    case (dut.Core_cpu.cpu_core.branch_predictor_inst.bht[bht_idx])
                        2'b00: bht_snt_count = bht_snt_count + 1;
                        2'b01: bht_wnt_count = bht_wnt_count + 1;
                        2'b10: bht_wt_count  = bht_wt_count  + 1;
                        2'b11: bht_st_count  = bht_st_count  + 1;
                        default: ;
                    endcase
                end
            end

            if (dut.Core_cpu.cpu_core.branch_predictor_inst.ras_sp_r == 0) begin
                ras_top_idx = 31;
            end else begin
                ras_top_idx = {27'b0, dut.Core_cpu.cpu_core.branch_predictor_inst.ras_sp_r};
                ras_top_idx = ras_top_idx - 1;
            end

            $display("BP_STATS_COND led_first cyc=%0d branches=%0d correct=%0d miss=%0d accuracy=%0.2f%% actual_taken=%0d pred_taken=%0d taken_correct=%0d not_taken_correct=%0d",
                     cycle_count,
                     bp_branch_total,
                     bp_branch_correct,
                     bp_branch_miss,
                     accuracy,
                     bp_actual_taken_count,
                     bp_pred_taken_count,
                     bp_taken_correct,
                     bp_not_taken_correct);
            $display("BP_STATS_COND_RATE miss_rate=%0.2f%% actual_taken_rate=%0.2f%% pred_taken_rate=%0.2f%% taken_recall=%0.2f%% not_taken_recall=%0.2f%% pred_taken_precision=%0.2f%% pred_not_taken_precision=%0.2f%% false_taken=%0d false_not_taken=%0d",
                     pct(bp_branch_miss, bp_branch_total),
                     pct(bp_actual_taken_count, bp_branch_total),
                     pct(bp_pred_taken_count, bp_branch_total),
                     pct(bp_taken_correct, bp_actual_taken_count),
                     pct(bp_not_taken_correct, actual_not_taken_count),
                     pct(bp_taken_correct, bp_pred_taken_count),
                     pct(bp_not_taken_correct, pred_not_taken_count),
                     false_taken_count,
                     false_not_taken_count);
            $display("BP_STATS_FETCH if_valid=%0d branch=%0d jal=%0d jalr=%0d other=%0d pred_taken=%0d accepted=%0d fetch_redirect=%0d replay_redirect=%0d btb_hit=%0d early_redirect=%0d ex_redirect=%0d",
                     bp_if_valid_count,
                     bp_fetch_branch_count,
                     bp_fetch_jal_count,
                     bp_fetch_jalr_count,
                     bp_fetch_other_count,
                     bp_fetch_pred_taken_count,
                     bp_pred_accept_count,
                     bp_fetch_redirect_count,
                     bp_replay_redirect_count,
                     bp_req_btb_hit_count,
                     bp_early_redirect_count,
                     bp_ex_redirect_count);
            $display("BP_STATS_EX_REDIRECT cond=%0d jal=%0d jalr=%0d other=%0d",
                     bp_ex_cond_redirect_count,
                     bp_ex_jal_redirect_count,
                     bp_ex_jalr_redirect_count,
                     bp_ex_other_redirect_count);
            $display("BP_STATS_JUMP jal_total=%0d jal_pred_taken=%0d jal_target_correct=%0d jal_miss=%0d jal_accuracy=%0.2f%% jalr_total=%0d jalr_pred_taken=%0d jalr_target_correct=%0d jalr_no_pred=%0d jalr_wrong_target=%0d jalr_accuracy=%0.2f%%",
                     bp_jal_total,
                     bp_jal_pred_taken_count,
                     bp_jal_target_correct_count,
                     bp_jal_miss_count,
                     pct(bp_jal_target_correct_count, bp_jal_total),
                     bp_jalr_total,
                     bp_jalr_pred_taken_count,
                     bp_jalr_target_correct_count,
                     bp_jalr_no_pred_count,
                     bp_jalr_wrong_target_count,
                     pct(bp_jalr_target_correct_count, bp_jalr_total));
            $display("BP_STATS_BHT ghr=%0d ghr_hex=%03h valid=%0d invalid=%0d snt=%0d wnt=%0d wt=%0d st=%0d pred_idx=%0d update_idx=%0d",
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ghr_r,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ghr_r,
                     bht_valid_count,
                     TB_BHT_SIZE - bht_valid_count,
                     bht_snt_count,
                     bht_wnt_count,
                     bht_wt_count,
                     bht_st_count,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.pred_idx,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.update_idx);
            $display("BP_STATS_RAS push=%0d pop=%0d pred_pop=%0d pred_valid=%0d count=%0d sp=%0d top_idx=%0d top=%08h nonempty=%b",
                     bp_ras_push_count,
                     bp_ras_pop_count,
                     bp_ras_pred_pop_count,
                     bp_ras_pred_valid_count,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras_count_r,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras_sp_r,
                     ras_top_idx,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[ras_top_idx],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras_nonempty);
            $display("BP_STATS_RAS_TARGET return_total=%0d return_pred=%0d return_target_correct=%0d return_no_pred=%0d return_wrong_target=%0d return_accuracy=%0.2f%% return_coverage=%0.2f%% nonreturn_jalr=%0d",
                     bp_return_total,
                     bp_return_pred_count,
                     bp_return_target_correct_count,
                     bp_return_no_pred_count,
                     bp_return_wrong_target_count,
                     pct(bp_return_target_correct_count, bp_return_total),
                     pct(bp_return_pred_count, bp_return_total),
                     bp_nonreturn_jalr_count);
            $display("BP_STATS_RAS_RAW ras0=%08h ras1=%08h ras2=%08h ras3=%08h ras4=%08h ras5=%08h ras6=%08h ras7=%08h",
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[0],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[1],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[2],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[3],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[4],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[5],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[6],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[7]);
            $display("BP_STATS_RAS_RAW ras8=%08h ras9=%08h ras10=%08h ras11=%08h ras12=%08h ras13=%08h ras14=%08h ras15=%08h",
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[8],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[9],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[10],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[11],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[12],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[13],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[14],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[15]);
            $display("BP_STATS_RAS_RAW ras16=%08h ras17=%08h ras18=%08h ras19=%08h ras20=%08h ras21=%08h ras22=%08h ras23=%08h",
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[16],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[17],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[18],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[19],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[20],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[21],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[22],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[23]);
            $display("BP_STATS_RAS_RAW ras24=%08h ras25=%08h ras26=%08h ras27=%08h ras28=%08h ras29=%08h ras30=%08h ras31=%08h",
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[24],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[25],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[26],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[27],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[28],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[29],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[30],
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras[31]);
        end
    endtask

    // Shadow valid/cause pipeline. This runs on the DUT update edge and uses
    // nonblocking assignments so each tag advances with the same old stage.
    always @(posedge w_cpu_clk) begin
        if (w_clk_rst) begin
            if_id_valid_r    <= 1'b0;
            id_ex_valid_r    <= 1'b0;
            ex_mem_valid_r   <= 1'b0;
            mem1_mem2_valid_r <= 1'b0;
            mem_wb_valid_r   <= 1'b0;
            if_id_cause_r    <= CAUSE_PIPE_FILL;
            id_ex_cause_r    <= CAUSE_PIPE_FILL;
            ex_mem_cause_r   <= CAUSE_PIPE_FILL;
            mem1_mem2_cause_r <= CAUSE_PIPE_FILL;
            mem_wb_cause_r   <= CAUSE_PIPE_FILL;
            if_id_pc_r       <= 32'b0;
            id_ex_pc_r       <= 32'b0;
            ex_mem_pc_r      <= 32'b0;
            mem1_mem2_pc_r   <= 32'b0;
            mem_wb_pc_r      <= 32'b0;
            mdu_active_r     <= 1'b0;
            mdu_is_div_r     <= 1'b0;
            redirect_opcode_r <= 7'b0;
        end else begin
            mem_wb_valid_r    <= mem1_mem2_valid_r;
            mem_wb_cause_r    <= mem1_mem2_cause_r;
            mem_wb_pc_r       <= mem1_mem2_pc_r;
            mem1_mem2_valid_r <= ex_mem_valid_r;
            mem1_mem2_cause_r <= ex_mem_cause_r;
            mem1_mem2_pc_r    <= ex_mem_pc_r;

            if (dut.Core_cpu.cpu_core.ctrl_kill_ex_o) begin
                ex_mem_valid_r <= 1'b0;
                ex_mem_cause_r <= redirect_cause(redirect_opcode_r);
                ex_mem_pc_r    <= 32'b0;
            end else if (dut.Core_cpu.cpu_core.ex_rv32m_busy_o) begin
                ex_mem_valid_r <= 1'b0;
                ex_mem_cause_r <=
                    (mdu_active_r ? mdu_is_div_r :
                     is_div_or_rem_inst(dut.Core_cpu.cpu_core.id_ex_inst_o)) ?
                    CAUSE_DIV_WAIT : CAUSE_MUL_WAIT;
                ex_mem_pc_r <= 32'b0;
            end else begin
                // The done pulse emits the latched M instruction exactly once;
                // all other non-killed cycles emit the current ID/EX slot.
                ex_mem_valid_r <= id_ex_valid_r;
                ex_mem_cause_r <= id_ex_cause_r;
                ex_mem_pc_r    <= id_ex_pc_r;
            end

            if (dut.Core_cpu.cpu_core.frontend_flush_idex) begin
                id_ex_valid_r <= 1'b0;
                id_ex_pc_r    <= 32'b0;
                if (dut.Core_cpu.cpu_core.ctrl_flush_idex_o) begin
                    id_ex_cause_r <= redirect_cause(redirect_opcode_r);
                end else begin
                    id_ex_cause_r <= CAUSE_REPLAY;
                end
            end else if (dut.Core_cpu.cpu_core.hdu_flush_flag_o) begin
                id_ex_valid_r <= 1'b0;
                id_ex_pc_r    <= 32'b0;
                if (dut.Core_cpu.cpu_core.hdu_inst.ex_load_dep) begin
                    id_ex_cause_r <= CAUSE_LOAD_USE;
                end else if (dut.Core_cpu.cpu_core.hdu_inst.mem1_load_dep) begin
                    id_ex_cause_r <= CAUSE_DCACHE_MISS;
                end else if (dut.Core_cpu.cpu_core.hdu_inst.mem1_load_shift_dep) begin
                    id_ex_cause_r <= CAUSE_DCACHE_HIT;
                end else if (dut.Core_cpu.cpu_core.hdu_inst.mem2_slow_load_dep) begin
                    id_ex_cause_r <= CAUSE_MMIO;
                end else if (dut.Core_cpu.cpu_core.ex_rv32m_done_o) begin
                    id_ex_cause_r <= mdu_is_div_r ? CAUSE_DIV_WAIT : CAUSE_MUL_WAIT;
                end else begin
                    id_ex_cause_r <= CAUSE_STRUCTURAL;
                end
            end else if (!dut.Core_cpu.cpu_core.hdu_hold_flag_o) begin
                id_ex_valid_r <= if_id_valid_r;
                id_ex_cause_r <= if_id_cause_r;
                id_ex_pc_r    <= if_id_pc_r;
            end

            if (dut.Core_cpu.cpu_core.frontend_flush_ifid) begin
                if_id_valid_r <= 1'b0;
                if_id_pc_r    <= 32'b0;
                if (dut.Core_cpu.cpu_core.ctrl_flush_ifid_o) begin
                    if_id_cause_r <= redirect_cause(redirect_opcode_r);
                end else begin
                    if_id_cause_r <= CAUSE_REPLAY;
                end
            end else if (!dut.Core_cpu.cpu_core.hdu_hold_flag_o) begin
                if (dut.Core_cpu.cpu_core.if_id_replay_pending_o) begin
                    if_id_valid_r <= 1'b1;
                    if_id_cause_r <= CAUSE_NONE;
                    if_id_pc_r    <= dut.Core_cpu.cpu_core.if_id_inst.hold_inst_addr_reg;
                end else if (dut.Core_cpu.cpu_core.ifid_fetch_valid) begin
                    if_id_valid_r <= 1'b1;
                    if_id_cause_r <= CAUSE_NONE;
                    if_id_pc_r    <= dut.Core_cpu.cpu_core.bp_fetch_pc_r;
                end else begin
                    if_id_valid_r <= 1'b0;
                    if_id_pc_r    <= 32'b0;
                    if (dut.Core_cpu.cpu_core.bp_pred_flush_d1_r) begin
                        if_id_cause_r <= CAUSE_LATE_PRED_TAKEN;
                    end else if (dut.Core_cpu.cpu_core.bp_replay_flush_d1_r) begin
                        if_id_cause_r <= CAUSE_REPLAY;
                    end else begin
                        if_id_cause_r <= CAUSE_FRONTEND;
                    end
                end
            end

            if (!mdu_active_r && dut.Core_cpu.cpu_core.ex_rv32m_busy_o) begin
                mdu_active_r <= 1'b1;
                mdu_is_div_r <=
                    is_div_or_rem_inst(dut.Core_cpu.cpu_core.id_ex_inst_o);
            end else if (dut.Core_cpu.cpu_core.ex_rv32m_done_o) begin
                mdu_active_r <= 1'b0;
            end

            if (dut.Core_cpu.cpu_core.ex_jump_en_o) begin
                redirect_opcode_r <= dut.Core_cpu.cpu_core.id_ex_inst_o[6:0];
            end
        end
    end

    // Sample halfway between DUT update edges so all NBA updates are settled.
    always @(negedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (mem_wb_valid_r) begin
                retired_inst_count = retired_inst_count + 1;
                retire_1_cycles = retire_1_cycles + 1;
                if (dut.Core_cpu.cpu_core.mem_wb_inst_o == `INST_NOP) begin
                    committed_arch_nop_count = committed_arch_nop_count + 1;
                end
            end else begin
                retire_0_cycles = retire_0_cycles + 1;
                if (dut.Core_cpu.cpu_core.mem_wb_inst_o != `INST_NOP) begin
                    invalid_non_nop_wb_count = invalid_non_nop_wb_count + 1;
                end
                case (mem_wb_cause_r)
                    CAUSE_PIPE_FILL:  pipeline_fill_cycles = pipeline_fill_cycles + 1;
                    CAUSE_DCACHE_MISS: dcache_miss_stall_cycles = dcache_miss_stall_cycles + 1;
                    CAUSE_DCACHE_HIT: dcache_hit_wait_cycles = dcache_hit_wait_cycles + 1;
                    CAUSE_LOAD_USE:   load_use_stall_cycles = load_use_stall_cycles + 1;
                    CAUSE_MUL_WAIT:   mul_wait_cycles = mul_wait_cycles + 1;
                    CAUSE_DIV_WAIT:   div_wait_cycles = div_wait_cycles + 1;
                    CAUSE_BRANCH:     branch_recovery_cycles = branch_recovery_cycles + 1;
                    CAUSE_JAL:        jal_recovery_cycles = jal_recovery_cycles + 1;
                    CAUSE_JALR:       jalr_recovery_cycles = jalr_recovery_cycles + 1;
                    CAUSE_LATE_PRED_TAKEN: late_pred_taken_flush_bubble_cycles = late_pred_taken_flush_bubble_cycles + 1;
                    CAUSE_REPLAY:     replay_hold_cycles = replay_hold_cycles + 1;
                    CAUSE_MMIO:       mmio_wait_cycles = mmio_wait_cycles + 1;
                    CAUSE_STRUCTURAL: structural_stall_cycles = structural_stall_cycles + 1;
                    CAUSE_FRONTEND:   frontend_empty_cycles = frontend_empty_cycles + 1;
                    default:          other_stall_cycles = other_stall_cycles + 1;
                endcase
            end

            // Once the terminating store has executed, only drain older slots
            // through WB; do not count activity from younger instructions.
            if (!stop_commit_pending_r &&
                !(dut.perip_wstrb != 4'b0000 && dut.perip_addr == LED_ADDR)) begin
            if (dut.Core_cpu.cpu_core.hdu_hold_flag_o) begin
                hdu_hold_cycles = hdu_hold_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.hdu_flush_flag_o) begin
                hdu_flush_cycles = hdu_flush_cycles + 1;
            end
            if (!dut.Core_cpu.cpu_core.if_id_load_valid_o) begin
                ifid_invalid_cycles = ifid_invalid_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.id_ex_inst_o == `INST_NOP) begin
                idex_nop_cycles = idex_nop_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.if_id_replay_pending_o) begin
                replay_pending_cycles = replay_pending_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.if_id_replaying_o) begin
                replay_active_cycles = replay_active_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_pred_flush_d1_r) begin
                late_pred_taken_flush_cycles = late_pred_taken_flush_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.hdu_inst.ex_load_dep) begin
                raw_ex_load_dep_cycles = raw_ex_load_dep_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.hdu_inst.mem1_load_dep) begin
                raw_mem1_miss_dep_cycles = raw_mem1_miss_dep_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.hdu_inst.mem1_load_shift_dep) begin
                raw_mem1_hit_shift_dep_cycles = raw_mem1_hit_shift_dep_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.hdu_inst.mem2_slow_load_dep) begin
                raw_mem2_slow_dep_cycles = raw_mem2_slow_dep_cycles + 1;
            end
            if (dut.Core_cpu.cpu_core.ex_rv32m_busy_o) begin
                raw_mdu_busy_cycles = raw_mdu_busy_cycles + 1;
            end

            if (ex_mem_valid_r && dut.Core_cpu.cpu_core.ex_mem_is_load_o) begin
                load_total_count = load_total_count + 1;
                if (dut.Core_cpu.cpu_core.ex_mem_load_hits_dram_o) begin
                    dcache_load_count = dcache_load_count + 1;
                    if (dut.Core_cpu.cpu_core.mem1_load_cache_hit) begin
                        dcache_hit_count = dcache_hit_count + 1;
                    end else begin
                        dcache_miss_count = dcache_miss_count + 1;
                    end
                end else begin
                    uncached_load_count = uncached_load_count + 1;
                end
            end

            if (mem1_mem2_valid_r &&
                dut.Core_cpu.cpu_core.mem1_mem2_is_load_o &&
                dut.Core_cpu.cpu_core.mem1_mem2_load_hits_dram_o &&
                !dut.Core_cpu.cpu_core.mem1_mem2_load_cache_hit_o) begin
                dcache_refill_count = dcache_refill_count + 1;
            end

            if (dut.Core_cpu.cpu_core.bp_if_valid) begin
                bp_if_valid_count = bp_if_valid_count + 1;
                case (dut.Core_cpu.cpu_core.branch_predictor_inst.opcode)
                    OPC_BRANCH: bp_fetch_branch_count = bp_fetch_branch_count + 1;
                    OPC_JAL:    bp_fetch_jal_count = bp_fetch_jal_count + 1;
                    OPC_JALR:   bp_fetch_jalr_count = bp_fetch_jalr_count + 1;
                    default:    bp_fetch_other_count = bp_fetch_other_count + 1;
                endcase
            end
            if (dut.Core_cpu.cpu_core.bp_if_valid &&
                dut.Core_cpu.cpu_core.bp_pred_taken_o) begin
                bp_fetch_pred_taken_count = bp_fetch_pred_taken_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o) begin
                bp_pred_accept_count = bp_pred_accept_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_fetch_redirect) begin
                bp_fetch_redirect_count = bp_fetch_redirect_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_replay_redirect) begin
                bp_replay_redirect_count = bp_replay_redirect_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_req_btb_hit_o) begin
                bp_req_btb_hit_count = bp_req_btb_hit_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_early_redirect) begin
                bp_early_redirect_count = bp_early_redirect_count + 1;
            end
            if (dut.Core_cpu.cpu_core.ex_jump_en_o) begin
                bp_ex_redirect_count = bp_ex_redirect_count + 1;
            end
            if (dut.Core_cpu.cpu_core.ex_jump_en_o) begin
                case (dut.Core_cpu.cpu_core.id_ex_inst_o[6:0])
                    OPC_BRANCH: bp_ex_cond_redirect_count = bp_ex_cond_redirect_count + 1;
                    OPC_JAL:    bp_ex_jal_redirect_count = bp_ex_jal_redirect_count + 1;
                    OPC_JALR:   bp_ex_jalr_redirect_count = bp_ex_jalr_redirect_count + 1;
                    default:    bp_ex_other_redirect_count = bp_ex_other_redirect_count + 1;
                endcase
            end
            if (dut.Core_cpu.cpu_core.bp_ras_push_en_o) begin
                bp_ras_push_count = bp_ras_push_count + 1;
            end
            if (dut.Core_cpu.cpu_core.bp_ras_pop_en_o) begin
                bp_ras_pop_count = bp_ras_pop_count + 1;
            end
            if (dut.Core_cpu.cpu_core.branch_predictor_inst.if_valid_i &&
                dut.Core_cpu.cpu_core.branch_predictor_inst.ras_pred_pop) begin
                bp_ras_pred_pop_count = bp_ras_pred_pop_count + 1;
            end
            if (dut.Core_cpu.cpu_core.branch_predictor_inst.if_valid_i &&
                dut.Core_cpu.cpu_core.branch_predictor_inst.ras_pred_valid) begin
                bp_ras_pred_valid_count = bp_ras_pred_valid_count + 1;
            end

            if (id_ex_valid_r && !dut.Core_cpu.cpu_core.ctrl_kill_ex_o) begin
                case (dut.Core_cpu.cpu_core.id_ex_inst_o[6:0])
                    OPC_JAL: begin
                        bp_jal_total = bp_jal_total + 1;
                        if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                            bp_jal_pred_taken_count = bp_jal_pred_taken_count + 1;
                        end

                        if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o &&
                            (dut.Core_cpu.cpu_core.id_ex_pred_target_o ==
                             jal_target(dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                                        dut.Core_cpu.cpu_core.id_ex_inst_o))) begin
                            bp_jal_target_correct_count = bp_jal_target_correct_count + 1;
                        end else begin
                            bp_jal_miss_count = bp_jal_miss_count + 1;
                        end
                    end

                    OPC_JALR: begin
                        bp_jalr_total = bp_jalr_total + 1;
                        if (is_return_jalr(dut.Core_cpu.cpu_core.id_ex_inst_o)) begin
                            bp_return_total = bp_return_total + 1;
                        end else begin
                            bp_nonreturn_jalr_count = bp_nonreturn_jalr_count + 1;
                        end

                        if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                            bp_jalr_pred_taken_count = bp_jalr_pred_taken_count + 1;
                            if (is_return_jalr(dut.Core_cpu.cpu_core.id_ex_inst_o)) begin
                                bp_return_pred_count = bp_return_pred_count + 1;
                            end
                        end

                        if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o &&
                            (dut.Core_cpu.cpu_core.id_ex_pred_target_o ==
                             dut.Core_cpu.cpu_core.ex_jump_addr_o)) begin
                            bp_jalr_target_correct_count = bp_jalr_target_correct_count + 1;
                            if (is_return_jalr(dut.Core_cpu.cpu_core.id_ex_inst_o)) begin
                                bp_return_target_correct_count = bp_return_target_correct_count + 1;
                            end
                        end else if (!dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                            bp_jalr_no_pred_count = bp_jalr_no_pred_count + 1;
                            if (is_return_jalr(dut.Core_cpu.cpu_core.id_ex_inst_o)) begin
                                bp_return_no_pred_count = bp_return_no_pred_count + 1;
                            end
                        end else begin
                            bp_jalr_wrong_target_count = bp_jalr_wrong_target_count + 1;
                            if (is_return_jalr(dut.Core_cpu.cpu_core.id_ex_inst_o)) begin
                                bp_return_wrong_target_count = bp_return_wrong_target_count + 1;
                            end
                        end
                    end

                    default: ;
                endcase
            end

            if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                bp_branch_total = bp_branch_total + 1;

                if (dut.Core_cpu.cpu_core.bp_actual_taken_o) begin
                    bp_actual_taken_count = bp_actual_taken_count + 1;
                end
                if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                    bp_pred_taken_count = bp_pred_taken_count + 1;
                end

                if (dut.Core_cpu.cpu_core.bp_actual_taken_o ==
                    dut.Core_cpu.cpu_core.id_ex_pred_taken_o) begin
                    bp_branch_correct = bp_branch_correct + 1;
                    if (dut.Core_cpu.cpu_core.bp_actual_taken_o) begin
                        bp_taken_correct = bp_taken_correct + 1;
                    end else begin
                        bp_not_taken_correct = bp_not_taken_correct + 1;
                    end
                end else begin
                    bp_branch_miss = bp_branch_miss + 1;
                end
            end
            end

            if (dut.pc == prev_pc) same_pc_count = same_pc_count + 1;
            else begin same_pc_count = 0; prev_pc = dut.pc; end

`ifdef TB_RET_DEBUG
            if ((cycle_count >= 1980 && cycle_count <= 2120) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o[6:0] == OPC_JALR) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_0070 &&
                 dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_0088) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_0104 &&
                 dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_0110)) begin
                $display("RETDBG cyc=%0d pc=%08h inst=%08h ifid_pc=%08h ifid_inst=%08h id_pc=%08h id_inst=%08h idex_pc=%08h idex_inst=%08h hold=%b flush=%b ra=%08h id_rs1=%0d id_base=%08h idex_rs1=%0d idex_base=%08h fwd_base=%08h ex_jump=%b ex_jaddr=%08h ex_wen=%b ex_waddr=%08h ex_wdata=%08h mem_wb_inst=%08h mem_wb_rd=%0d mem_wb_data=%08h wb_rd=%0d wb_data=%08h wb_wen=%b",
                         cycle_count,
                         dut.pc,
                         dut.instruction,
                         dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                         dut.Core_cpu.cpu_core.if_id_inst_o,
                         dut.Core_cpu.cpu_core.id_inst_addr_o,
                         dut.Core_cpu.cpu_core.id_inst_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_o,
                         dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                         dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                         dut.Core_cpu.cpu_core.regs_inst.regs[1],
                         dut.Core_cpu.cpu_core.id_rs1_addr_o,
                         dut.Core_cpu.cpu_core.id_base_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_rs1_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                         dut.Core_cpu.cpu_core.fwd_base_addr_o,
                         dut.Core_cpu.cpu_core.ex_jump_en_o,
                         dut.Core_cpu.cpu_core.ex_jump_addr_o,
                         dut.Core_cpu.cpu_core.ex_wd_reg_o,
                         dut.Core_cpu.cpu_core.ex_wd_addr_o,
                         dut.Core_cpu.cpu_core.ex_wd_data_o,
                         dut.Core_cpu.cpu_core.mem_wb_inst_o,
                         dut.Core_cpu.cpu_core.mem_wb_rd_addr_o,
                         dut.Core_cpu.cpu_core.mem_wb_rd_data_o,
                         dut.Core_cpu.cpu_core.wb_rd_addr_o,
                         dut.Core_cpu.cpu_core.wb_rd_data_o,
                         dut.Core_cpu.cpu_core.wb_rd_wen_o);
            end
`endif

            if (cycle_count > 100 && dut.pc < 32'h8000_0000) begin
                low_pc_count = low_pc_count + 1;
            end else begin
                low_pc_count = 0;
            end

            if (low_pc_count >= LOW_PC_LIMIT) begin
                $display("FAIL RUNAWAY_LOW_PC cyc=%0d pc=%08h", cycle_count, dut.pc);
                print_perf_stats();
                print_bp_stats();
                $finish;
            end
            if (same_pc_count >= STUCK_PC_LIMIT) begin
                $display("FAIL STUCK_SAME_PC cyc=%0d pc=%08h", cycle_count, dut.pc);
                print_perf_stats();
                print_bp_stats();
                $finish;
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == SEG_ADDR) begin
                seg_write_count = seg_write_count + 1;
                $display("SEG_WRITE #%0d cyc=%0d pc=%08h data=%08h", seg_write_count, cycle_count, dut.pc, dut.perip_wdata);
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == LED_ADDR) begin
                led_write_count = led_write_count + 1;
                $display("LED_WRITE #%0d cyc=%0d pc=%08h data=%08h seg_writes=%0d", led_write_count, cycle_count, dut.pc, dut.perip_wdata, seg_write_count);
                if (led_write_count == 1) begin
                    stop_commit_pending_r = 1'b1;
                    stop_commit_pc_r = ex_mem_pc_r;
                    stop_detect_cycle = cycle_count;
                end
            end

            // The peripheral store takes effect in MEM1. Finish only when that
            // exact in-order slot reaches WB, so the terminating store retires.
            if (stop_commit_pending_r &&
                (cycle_count > stop_detect_cycle) &&
                mem_wb_valid_r &&
                (mem_wb_pc_r == stop_commit_pc_r)) begin
                stop_commit_pending_r = 1'b0;
                print_perf_stats();
                print_bp_stats();
                $display("SEG_LED_STOP_DONE led=%08h seg=%010h seg_writes=%0d led_writes=%0d cyc=%0d stop_pc=%08h",
                         virtual_led, virtual_seg, seg_write_count, led_write_count,
                         cycle_count, stop_commit_pc_r);
                $finish;
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        $display("TIMEOUT cyc=%0d seg_writes=%0d led_writes=%0d", cycle_count, seg_write_count, led_write_count);
        print_perf_stats();
        print_bp_stats();
        $finish;
    end
endmodule
