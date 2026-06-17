`timescale 1ns / 1ps

module tb_bp_profile_led4;
    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam [31:0] LED_ADDR = 32'h8020_0040;

    localparam [6:0] OP_BRANCH = 7'b1100011;
    localparam [6:0] OP_JAL    = 7'b1101111;
    localparam [6:0] OP_JALR   = 7'b1100111;
    localparam [6:0] OP_SYSTEM = 7'b1110011;

    localparam [31:0] INST_NOP = 32'h0000_0013;
    localparam time SIM_TIME_LIMIT_NS = 30_000_000_000;
    localparam integer STUCK_PC_LIMIT = 200000;
    localparam integer MAX_BRANCH_SITES = 512;

    localparam TRACE_ALL_BRANCHES = 0;
    localparam TRACE_MISPRED      = 0;

    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

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

    longint cycle_count;
    integer seg_write_count;
    integer led_write_count;
    integer same_pc_count;
    reg [31:0] prev_pc;

    integer hold_cycles;
    integer hdu_flush_cycles;
    integer ifid_valid_cycles;
    integer fetch_valid_cycles;
    integer ifid_direct_fire_cycles;
    integer replay_cycles;
    integer replay_pending_cycles;
    integer frontend_flush_ifid_cycles;
    integer frontend_flush_idex_cycles;
    integer ctrl_flush_ifid_cycles;
    integer ctrl_flush_idex_cycles;
    integer pred_ghost_flush_cycles;
    integer replay_flush_cycles;

    integer if_control_predictions;
    integer if_cond_predictions;
    integer if_jal_predictions;
    integer if_jalr_predictions;
    integer if_pred_taken;
    integer if_pred_not_taken;
    integer if_bht_hit;
    integer if_bht_cold;
    integer pred_taken_accepted;
    integer pred_fetch_redirects;
    integer pred_replay_redirects;

    integer cond_total;
    integer cond_taken;
    integer cond_not_taken;
    integer cond_pred_taken;
    integer cond_pred_not_taken;
    integer cond_correct;
    integer cond_miss;
    integer cond_false_taken;
    integer cond_false_not_taken;
    integer cond_target_miss;
    integer cond_backward_total;
    integer cond_backward_miss;
    integer cond_forward_total;
    integer cond_forward_miss;
    integer cond_func_total [0:7];
    integer cond_func_miss  [0:7];

    integer jal_total;
    integer jal_correct;
    integer jal_miss;
    integer jal_target_miss;

    integer jalr_total;
    integer jalr_correct;
    integer jalr_miss;
    integer jalr_pred_taken;
    integer jalr_pred_not_taken;
    integer jalr_target_miss;
    integer jalr_return_total;
    integer jalr_return_correct;
    integer jalr_return_miss;

    integer ex_redirects;
    integer cond_redirects;
    integer jal_redirects;
    integer jalr_redirects;
    integer system_redirects;
    integer other_redirects;
    integer memwb_bp_updates;
    integer ras_pushes;
    integer ras_pops;

    integer site_count;
    reg [31:0] site_pc [0:MAX_BRANCH_SITES-1];
    integer site_total [0:MAX_BRANCH_SITES-1];
    integer site_miss [0:MAX_BRANCH_SITES-1];
    integer site_taken [0:MAX_BRANCH_SITES-1];
    integer site_pred_taken [0:MAX_BRANCH_SITES-1];
    integer site_backward [0:MAX_BRANCH_SITES-1];
    integer site_target_miss [0:MAX_BRANCH_SITES-1];
    integer site_func3_mask [0:MAX_BRANCH_SITES-1];
    integer dropped_sites;

    integer i;

    wire [31:0] if_inst = dut.instruction;
    wire [6:0]  if_opcode = if_inst[6:0];
    wire [31:0] idex_inst = dut.Core_cpu.cpu_core.id_ex_inst_o;
    wire [6:0]  idex_opcode = idex_inst[6:0];
    wire [2:0]  idex_func3 = idex_inst[14:12];
    wire [4:0]  idex_rd = idex_inst[11:7];
    wire [4:0]  idex_rs1 = idex_inst[19:15];
    wire        idex_valid =
        (idex_inst != INST_NOP) &&
        (dut.Core_cpu.cpu_core.ctrl_kill_ex_o == 1'b0);

    wire [31:0] branch_actual_target =
        dut.Core_cpu.cpu_core.id_ex_inst_addr_o +
        dut.Core_cpu.cpu_core.id_ex_branch_offset_o;

    wire [31:0] jal_actual_target =
        dut.Core_cpu.cpu_core.id_ex_inst_addr_o +
        dut.Core_cpu.cpu_core.id_ex_jump_offset_o;

    wire [31:0] jalr_actual_target =
        (dut.Core_cpu.cpu_core.id_ex_base_addr_o +
         dut.Core_cpu.cpu_core.id_ex_jump_offset_o) & ~32'd1;

    wire [8:0] pred_bht_idx =
        dut.Core_cpu.cpu_core.bp_fetch_pc_r[10:2] ^
        dut.Core_cpu.cpu_core.branch_predictor_inst.ghr_r;
    wire pred_bht_valid =
        dut.Core_cpu.cpu_core.branch_predictor_inst.bht_valid[pred_bht_idx];
    wire [1:0] pred_bht_state =
        dut.Core_cpu.cpu_core.branch_predictor_inst.bht[pred_bht_idx];
    wire [8:0] resolve_bht_idx =
        dut.Core_cpu.cpu_core.id_ex_inst_addr_o[10:2] ^
        dut.Core_cpu.cpu_core.id_ex_pred_ghr_o;
    wire resolve_bht_valid =
        dut.Core_cpu.cpu_core.branch_predictor_inst.bht_valid[resolve_bht_idx];
    wire [1:0] resolve_bht_state =
        dut.Core_cpu.cpu_core.branch_predictor_inst.bht[resolve_bht_idx];

    function [31:0] branch_imm;
        input [31:0] inst;
        begin
            branch_imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
        end
    endfunction

    function integer pct_x100;
        input integer num;
        input integer den;
        begin
            if (den == 0) begin
                pct_x100 = 0;
            end else begin
                pct_x100 = (num * 10000) / den;
            end
        end
    endfunction

    task automatic print_pct;
        input [255:0] label;
        input integer num;
        input integer den;
        integer p;
        begin
            p = pct_x100(num, den);
            $display("%0s %0d/%0d %0d.%02d%%", label, num, den, p / 100, p % 100);
        end
    endtask

    task automatic record_branch_site;
        input [31:0] pc;
        input [2:0]  func3;
        input        actual_taken;
        input        predicted_taken;
        input        is_miss;
        input        is_backward;
        input        target_miss;
        integer idx;
        integer found;
        begin
            found = 0;
            idx = 0;
            for (i = 0; i < MAX_BRANCH_SITES; i = i + 1) begin
                if ((i < site_count) && (site_pc[i] == pc) && (found == 0)) begin
                    idx = i;
                    found = 1;
                end
            end

            if (found == 0) begin
                if (site_count < MAX_BRANCH_SITES) begin
                    idx = site_count;
                    site_count = site_count + 1;
                    site_pc[idx] = pc;
                    site_total[idx] = 0;
                    site_miss[idx] = 0;
                    site_taken[idx] = 0;
                    site_pred_taken[idx] = 0;
                    site_backward[idx] = 0;
                    site_target_miss[idx] = 0;
                    site_func3_mask[idx] = 0;
                    found = 1;
                end else begin
                    dropped_sites = dropped_sites + 1;
                end
            end

            if (found != 0) begin
                site_total[idx] = site_total[idx] + 1;
                if (is_miss) site_miss[idx] = site_miss[idx] + 1;
                if (actual_taken) site_taken[idx] = site_taken[idx] + 1;
                if (predicted_taken) site_pred_taken[idx] = site_pred_taken[idx] + 1;
                if (is_backward) site_backward[idx] = site_backward[idx] + 1;
                if (target_miss) site_target_miss[idx] = site_target_miss[idx] + 1;
                site_func3_mask[idx] = site_func3_mask[idx] | (1 << func3);
            end
        end
    endtask

    task automatic print_summary;
        input [127:0] reason;
        integer p;
        begin
            $display("BP_PROFILE_SUMMARY_BEGIN reason=%0s", reason);
            $display("RUN cycles=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h same_pc=%0d",
                     cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, led_write_count, virtual_led, virtual_seg,
                     same_pc_count);

            $display("PIPE fetch_valid=%0d ifid_valid=%0d ifid_direct_fire=%0d replay=%0d replay_pending=%0d hold=%0d hdu_flush=%0d",
                     fetch_valid_cycles, ifid_valid_cycles, ifid_direct_fire_cycles,
                     replay_cycles, replay_pending_cycles, hold_cycles, hdu_flush_cycles);
            $display("FLUSH frontend_ifid=%0d frontend_idex=%0d ctrl_ifid=%0d ctrl_idex=%0d pred_ghost=%0d replay_flush=%0d",
                     frontend_flush_ifid_cycles, frontend_flush_idex_cycles,
                     ctrl_flush_ifid_cycles, ctrl_flush_idex_cycles,
                     pred_ghost_flush_cycles, replay_flush_cycles);

            $display("IF_PRED control=%0d cond=%0d jal=%0d jalr=%0d taken=%0d not_taken=%0d bht_hit=%0d bht_cold=%0d accepted=%0d fetch_redirect=%0d replay_redirect=%0d",
                     if_control_predictions, if_cond_predictions, if_jal_predictions,
                     if_jalr_predictions, if_pred_taken, if_pred_not_taken,
                     if_bht_hit, if_bht_cold, pred_taken_accepted,
                     pred_fetch_redirects, pred_replay_redirects);
            print_pct("IF_BHT_HIT_RATE", if_bht_hit, if_cond_predictions);

            $display("COND total=%0d taken=%0d not_taken=%0d pred_taken=%0d pred_not_taken=%0d correct=%0d miss=%0d false_taken=%0d false_not_taken=%0d target_miss=%0d redirects=%0d",
                     cond_total, cond_taken, cond_not_taken, cond_pred_taken,
                     cond_pred_not_taken, cond_correct, cond_miss,
                     cond_false_taken, cond_false_not_taken, cond_target_miss,
                     cond_redirects);
            print_pct("COND_ACCURACY", cond_correct, cond_total);
            print_pct("COND_MISS_RATE", cond_miss, cond_total);
            print_pct("COND_TAKEN_RATE", cond_taken, cond_total);
            print_pct("COND_BACKWARD_MISS_RATE", cond_backward_miss, cond_backward_total);
            print_pct("COND_FORWARD_MISS_RATE", cond_forward_miss, cond_forward_total);

            for (p = 0; p < 8; p = p + 1) begin
                if (cond_func_total[p] != 0) begin
                    $display("COND_FUNC3 func3=%0d total=%0d miss=%0d correct=%0d",
                             p, cond_func_total[p], cond_func_miss[p],
                             cond_func_total[p] - cond_func_miss[p]);
                    print_pct("COND_FUNC3_ACCURACY", cond_func_total[p] - cond_func_miss[p],
                              cond_func_total[p]);
                end
            end

            $display("JAL total=%0d correct=%0d miss=%0d target_miss=%0d redirects=%0d",
                     jal_total, jal_correct, jal_miss, jal_target_miss, jal_redirects);
            print_pct("JAL_ACCURACY", jal_correct, jal_total);

            $display("JALR total=%0d pred_taken=%0d pred_not_taken=%0d correct=%0d miss=%0d target_miss=%0d redirects=%0d",
                     jalr_total, jalr_pred_taken, jalr_pred_not_taken,
                     jalr_correct, jalr_miss, jalr_target_miss, jalr_redirects);
            print_pct("JALR_ACCURACY", jalr_correct, jalr_total);
            $display("JALR_RETURN total=%0d correct=%0d miss=%0d",
                     jalr_return_total, jalr_return_correct, jalr_return_miss);
            print_pct("JALR_RETURN_ACCURACY", jalr_return_correct, jalr_return_total);

            $display("REDIRECT total_ex=%0d cond=%0d jal=%0d jalr=%0d system=%0d other=%0d",
                     ex_redirects, cond_redirects, jal_redirects,
                     jalr_redirects, system_redirects, other_redirects);
            $display("UPDATE memwb_bp_updates=%0d ras_pushes=%0d ras_pops=%0d ras_count_final=%0d ghr_final=%b",
                     memwb_bp_updates, ras_pushes, ras_pops,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ras_count_r,
                     dut.Core_cpu.cpu_core.branch_predictor_inst.ghr_r);

            $display("BP_SITE_TABLE_BEGIN count=%0d dropped=%0d", site_count, dropped_sites);
            for (p = 0; p < site_count; p = p + 1) begin
                $display("BP_SITE idx=%0d pc=%08h total=%0d miss=%0d correct=%0d taken=%0d pred_taken=%0d backward_seen=%0d target_miss=%0d func3_mask=%02h",
                         p, site_pc[p], site_total[p], site_miss[p],
                         site_total[p] - site_miss[p], site_taken[p],
                         site_pred_taken[p], site_backward[p],
                         site_target_miss[p], site_func3_mask[p]);
            end
            $display("BP_SITE_TABLE_END");
            $display("BP_PROFILE_SUMMARY_END");
        end
    endtask

    task automatic finish_now;
        input [127:0] reason;
        begin
            print_summary(reason);
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

        hold_cycles = 0;
        hdu_flush_cycles = 0;
        ifid_valid_cycles = 0;
        fetch_valid_cycles = 0;
        ifid_direct_fire_cycles = 0;
        replay_cycles = 0;
        replay_pending_cycles = 0;
        frontend_flush_ifid_cycles = 0;
        frontend_flush_idex_cycles = 0;
        ctrl_flush_ifid_cycles = 0;
        ctrl_flush_idex_cycles = 0;
        pred_ghost_flush_cycles = 0;
        replay_flush_cycles = 0;

        if_control_predictions = 0;
        if_cond_predictions = 0;
        if_jal_predictions = 0;
        if_jalr_predictions = 0;
        if_pred_taken = 0;
        if_pred_not_taken = 0;
        if_bht_hit = 0;
        if_bht_cold = 0;
        pred_taken_accepted = 0;
        pred_fetch_redirects = 0;
        pred_replay_redirects = 0;

        cond_total = 0;
        cond_taken = 0;
        cond_not_taken = 0;
        cond_pred_taken = 0;
        cond_pred_not_taken = 0;
        cond_correct = 0;
        cond_miss = 0;
        cond_false_taken = 0;
        cond_false_not_taken = 0;
        cond_target_miss = 0;
        cond_backward_total = 0;
        cond_backward_miss = 0;
        cond_forward_total = 0;
        cond_forward_miss = 0;

        jal_total = 0;
        jal_correct = 0;
        jal_miss = 0;
        jal_target_miss = 0;

        jalr_total = 0;
        jalr_correct = 0;
        jalr_miss = 0;
        jalr_pred_taken = 0;
        jalr_pred_not_taken = 0;
        jalr_target_miss = 0;
        jalr_return_total = 0;
        jalr_return_correct = 0;
        jalr_return_miss = 0;

        ex_redirects = 0;
        cond_redirects = 0;
        jal_redirects = 0;
        jalr_redirects = 0;
        system_redirects = 0;
        other_redirects = 0;
        memwb_bp_updates = 0;
        ras_pushes = 0;
        ras_pops = 0;

        site_count = 0;
        dropped_sites = 0;
        for (i = 0; i < 8; i = i + 1) begin
            cond_func_total[i] = 0;
            cond_func_miss[i] = 0;
        end
        for (i = 0; i < MAX_BRANCH_SITES; i = i + 1) begin
            site_pc[i] = 32'b0;
            site_total[i] = 0;
            site_miss[i] = 0;
            site_taken[i] = 0;
            site_pred_taken[i] = 0;
            site_backward[i] = 0;
            site_target_miss[i] = 0;
            site_func3_mask[i] = 0;
        end

        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        reg actual_taken;
        reg predicted_taken;
        reg target_miss;
        reg is_miss;
        reg is_backward;
        reg is_return_like;
        reg [31:0] actual_target;

        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (dut.pc == prev_pc) begin
                same_pc_count = same_pc_count + 1;
            end else begin
                same_pc_count = 0;
                prev_pc = dut.pc;
            end

            if (cycle_count > 100 && dut.pc < 32'h8000_0000) begin
                finish_now("RUNAWAY_LOW_PC");
            end
            if (same_pc_count >= STUCK_PC_LIMIT) begin
                finish_now("STUCK_SAME_PC");
            end

            if (dut.Core_cpu.cpu_core.hdu_hold_flag_o) hold_cycles = hold_cycles + 1;
            if (dut.Core_cpu.cpu_core.hdu_flush_flag_o) hdu_flush_cycles = hdu_flush_cycles + 1;
            if (dut.Core_cpu.cpu_core.bp_if_valid) fetch_valid_cycles = fetch_valid_cycles + 1;
            if (dut.Core_cpu.cpu_core.if_id_load_valid_o) ifid_valid_cycles = ifid_valid_cycles + 1;
            if (dut.Core_cpu.cpu_core.ifid_direct_fire) ifid_direct_fire_cycles = ifid_direct_fire_cycles + 1;
            if (dut.Core_cpu.cpu_core.if_id_replaying_o) replay_cycles = replay_cycles + 1;
            if (dut.Core_cpu.cpu_core.if_id_replay_pending_o) replay_pending_cycles = replay_pending_cycles + 1;
            if (dut.Core_cpu.cpu_core.frontend_flush_ifid) frontend_flush_ifid_cycles = frontend_flush_ifid_cycles + 1;
            if (dut.Core_cpu.cpu_core.frontend_flush_idex) frontend_flush_idex_cycles = frontend_flush_idex_cycles + 1;
            if (dut.Core_cpu.cpu_core.ctrl_flush_ifid_o) ctrl_flush_ifid_cycles = ctrl_flush_ifid_cycles + 1;
            if (dut.Core_cpu.cpu_core.ctrl_flush_idex_o) ctrl_flush_idex_cycles = ctrl_flush_idex_cycles + 1;
            if (dut.Core_cpu.cpu_core.bp_pred_flush_d1_r) pred_ghost_flush_cycles = pred_ghost_flush_cycles + 1;
            if (dut.Core_cpu.cpu_core.bp_replay_flush_d1_r) replay_flush_cycles = replay_flush_cycles + 1;

            if (dut.Core_cpu.cpu_core.bp_if_valid &&
                ((if_opcode == OP_BRANCH) || (if_opcode == OP_JAL) || (if_opcode == OP_JALR))) begin
                if_control_predictions = if_control_predictions + 1;
                if (dut.Core_cpu.cpu_core.bp_pred_taken_o) if_pred_taken = if_pred_taken + 1;
                else if_pred_not_taken = if_pred_not_taken + 1;

                if (if_opcode == OP_BRANCH) begin
                    if_cond_predictions = if_cond_predictions + 1;
                    if (pred_bht_valid) if_bht_hit = if_bht_hit + 1;
                    else if_bht_cold = if_bht_cold + 1;
                end else if (if_opcode == OP_JAL) begin
                    if_jal_predictions = if_jal_predictions + 1;
                end else begin
                    if_jalr_predictions = if_jalr_predictions + 1;
                end
            end

            if (dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o) pred_taken_accepted = pred_taken_accepted + 1;
            if (dut.Core_cpu.cpu_core.bp_fetch_redirect) pred_fetch_redirects = pred_fetch_redirects + 1;
            if (dut.Core_cpu.cpu_core.bp_replay_redirect) pred_replay_redirects = pred_replay_redirects + 1;

            if (dut.Core_cpu.cpu_core.ex_jump_en_o) begin
                ex_redirects = ex_redirects + 1;
                if (idex_opcode == OP_BRANCH) cond_redirects = cond_redirects + 1;
                else if (idex_opcode == OP_JAL) jal_redirects = jal_redirects + 1;
                else if (idex_opcode == OP_JALR) jalr_redirects = jalr_redirects + 1;
                else if (idex_opcode == OP_SYSTEM) system_redirects = system_redirects + 1;
                else other_redirects = other_redirects + 1;
            end

            if (dut.Core_cpu.cpu_core.mem_wb_bp_update_en_o) memwb_bp_updates = memwb_bp_updates + 1;
            if (dut.Core_cpu.cpu_core.bp_ras_push_en_o) ras_pushes = ras_pushes + 1;
            if (dut.Core_cpu.cpu_core.bp_ras_pop_en_o) ras_pops = ras_pops + 1;

            if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                actual_taken = dut.Core_cpu.cpu_core.bp_actual_taken_o;
                predicted_taken = dut.Core_cpu.cpu_core.id_ex_pred_taken_o;
                actual_target = branch_actual_target;
                target_miss = actual_taken && predicted_taken &&
                              (dut.Core_cpu.cpu_core.id_ex_pred_target_o != actual_target);
                is_miss = (actual_taken != predicted_taken) || target_miss;
                is_backward = dut.Core_cpu.cpu_core.id_ex_branch_offset_o[31];

                cond_total = cond_total + 1;
                if (actual_taken) cond_taken = cond_taken + 1;
                else cond_not_taken = cond_not_taken + 1;
                if (predicted_taken) cond_pred_taken = cond_pred_taken + 1;
                else cond_pred_not_taken = cond_pred_not_taken + 1;
                if (is_miss) cond_miss = cond_miss + 1;
                else cond_correct = cond_correct + 1;
                if (predicted_taken && !actual_taken) cond_false_taken = cond_false_taken + 1;
                if (!predicted_taken && actual_taken) cond_false_not_taken = cond_false_not_taken + 1;
                if (target_miss) cond_target_miss = cond_target_miss + 1;

                if (is_backward) begin
                    cond_backward_total = cond_backward_total + 1;
                    if (is_miss) cond_backward_miss = cond_backward_miss + 1;
                end else begin
                    cond_forward_total = cond_forward_total + 1;
                    if (is_miss) cond_forward_miss = cond_forward_miss + 1;
                end

                cond_func_total[idex_func3] = cond_func_total[idex_func3] + 1;
                if (is_miss) cond_func_miss[idex_func3] = cond_func_miss[idex_func3] + 1;

                record_branch_site(dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                                   idex_func3, actual_taken, predicted_taken,
                                   is_miss, is_backward, target_miss);

                if (TRACE_ALL_BRANCHES || (TRACE_MISPRED && is_miss)) begin
                    $display("BP_BRANCH cyc=%0d pc=%08h inst=%08h func3=%0d pred=%0d actual=%0d miss=%0d target_miss=%0d pred_target=%08h actual_target=%08h ghr=%b bht_idx=%0d bht_valid_now=%0d bht_state_now=%0d",
                             cycle_count,
                             dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             idex_inst,
                             idex_func3,
                             predicted_taken,
                             actual_taken,
                             is_miss,
                             target_miss,
                             dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                             actual_target,
                             dut.Core_cpu.cpu_core.id_ex_pred_ghr_o,
                             resolve_bht_idx,
                             resolve_bht_valid,
                             resolve_bht_state);
                end
            end

            if (idex_valid && (idex_opcode == OP_JAL)) begin
                actual_target = jal_actual_target;
                target_miss = dut.Core_cpu.cpu_core.id_ex_pred_taken_o &&
                              (dut.Core_cpu.cpu_core.id_ex_pred_target_o != actual_target);
                is_miss = !dut.Core_cpu.cpu_core.id_ex_pred_taken_o || target_miss;
                jal_total = jal_total + 1;
                if (is_miss) jal_miss = jal_miss + 1;
                else jal_correct = jal_correct + 1;
                if (target_miss) jal_target_miss = jal_target_miss + 1;
                if (TRACE_ALL_BRANCHES || (TRACE_MISPRED && is_miss)) begin
                    $display("BP_JAL cyc=%0d pc=%08h pred=%0d miss=%0d target_miss=%0d pred_target=%08h actual_target=%08h",
                             cycle_count, dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             dut.Core_cpu.cpu_core.id_ex_pred_taken_o, is_miss,
                             target_miss, dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                             actual_target);
                end
            end

            if (idex_valid && (idex_opcode == OP_JALR)) begin
                actual_target = jalr_actual_target;
                target_miss = dut.Core_cpu.cpu_core.id_ex_pred_taken_o &&
                              (dut.Core_cpu.cpu_core.id_ex_pred_target_o != actual_target);
                is_miss = !dut.Core_cpu.cpu_core.id_ex_pred_taken_o || target_miss;
                is_return_like = (idex_func3 == 3'b000) &&
                                 (idex_rs1 == 5'd1) &&
                                 (((idex_rd == 5'd1) ? 1'b0 : 1'b1) || (idex_rd != idex_rs1));

                jalr_total = jalr_total + 1;
                if (dut.Core_cpu.cpu_core.id_ex_pred_taken_o) jalr_pred_taken = jalr_pred_taken + 1;
                else jalr_pred_not_taken = jalr_pred_not_taken + 1;
                if (is_miss) jalr_miss = jalr_miss + 1;
                else jalr_correct = jalr_correct + 1;
                if (target_miss) jalr_target_miss = jalr_target_miss + 1;
                if (is_return_like) begin
                    jalr_return_total = jalr_return_total + 1;
                    if (is_miss) jalr_return_miss = jalr_return_miss + 1;
                    else jalr_return_correct = jalr_return_correct + 1;
                end
                if (TRACE_ALL_BRANCHES || (TRACE_MISPRED && is_miss)) begin
                    $display("BP_JALR cyc=%0d pc=%08h inst=%08h rs1=%0d rd=%0d return_like=%0d pred=%0d miss=%0d target_miss=%0d pred_target=%08h actual_target=%08h ras_count=%0d",
                             cycle_count, dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             idex_inst, idex_rs1, idex_rd, is_return_like,
                             dut.Core_cpu.cpu_core.id_ex_pred_taken_o, is_miss,
                             target_miss, dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                             actual_target,
                             dut.Core_cpu.cpu_core.branch_predictor_inst.ras_count_r);
                end
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == SEG_ADDR)) begin
                seg_write_count = seg_write_count + 1;
                $display("SEG_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vseg=%010h",
                         seg_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb,
                         virtual_seg);
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == LED_ADDR)) begin
                led_write_count = led_write_count + 1;
                $display("LED_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vled=%08h vseg=%010h seg_writes=%0d",
                         led_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb,
                         virtual_led, virtual_seg, seg_write_count);
                if (led_write_count == 1) begin
                    finish_now("FIRST_LED_WRITE");
                end
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        finish_now("TIMEOUT");
    end
endmodule
