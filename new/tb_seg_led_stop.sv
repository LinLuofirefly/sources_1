`timescale 1ns / 1ps
`include "defines.v"

`ifndef TB_CPU_HALF_PERIOD_NS
`define TB_CPU_HALF_PERIOD_NS 2.941176
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
        reg [4:0] rd;
        reg [4:0] rs1;
        begin
            rd = inst[11:7];
            rs1 = inst[19:15];
            is_return_jalr =
                (inst[6:0] == OPC_JALR) &&
                (inst[14:12] == 3'b000) &&
                (rs1 == 5'd1) &&
                ((rd != 5'd1) || (rd != rs1));
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
            $display("BP_STATS_FETCH if_valid=%0d branch=%0d jal=%0d jalr=%0d other=%0d pred_taken=%0d accepted=%0d fetch_redirect=%0d replay_redirect=%0d ex_redirect=%0d",
                     bp_if_valid_count,
                     bp_fetch_branch_count,
                     bp_fetch_jal_count,
                     bp_fetch_jalr_count,
                     bp_fetch_other_count,
                     bp_fetch_pred_taken_count,
                     bp_pred_accept_count,
                     bp_fetch_redirect_count,
                     bp_replay_redirect_count,
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

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

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

            if (!dut.Core_cpu.cpu_core.ctrl_kill_ex_o) begin
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
                print_bp_stats();
                $finish;
            end
            if (same_pc_count >= STUCK_PC_LIMIT) begin
                $display("FAIL STUCK_SAME_PC cyc=%0d pc=%08h", cycle_count, dut.pc);
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
                if (led_write_count == 9) begin
                    print_bp_stats();
                    $display("SEG_LED_STOP_DONE led=%08h seg=%010h seg_writes=%0d led_writes=%0d cyc=%0d",
                             virtual_led, virtual_seg, seg_write_count, led_write_count, cycle_count);
                    $finish;
                end
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        $display("TIMEOUT cyc=%0d seg_writes=%0d led_writes=%0d", cycle_count, seg_write_count, led_write_count);
        print_bp_stats();
        $finish;
    end
endmodule
