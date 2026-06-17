`timescale 1ns / 1ps

`ifndef TB_CPU_HALF_PERIOD_NS
`define TB_CPU_HALF_PERIOD_NS 2.5
`endif

module tb_src1_check1_sum;
    reg         w_cpu_clk   = 1'b0;
    reg         w_clk_50Mhz = 1'b0;
    reg         w_clk_rst   = 1'b1;
    reg  [7:0]  virtual_key = 8'd0;
    reg  [63:0] virtual_sw  = 64'd0;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] CHECK1_SUM_STORE_PC   = 32'h8000_05a8;
    localparam [31:0] CHECK1_SUM_STORE_INST = 32'hfef4_2423;
    localparam [31:0] F_STATE0_ANDI_PC      = 32'h8000_0478;
    localparam [31:0] F_STATE0_BRANCH_PC    = 32'h8000_047c;
    localparam [31:0] F_RET_MV_PC           = 32'h8000_057c;
    localparam [31:0] F_STATE_STORE_PC      = 32'h8000_0580;
    localparam [31:0] MUL_ARG_A0_PC         = 32'h8000_0590;
    localparam [31:0] MUL_CALL_PC           = 32'h8000_0594;
    localparam [31:0] MUL_RET_PC            = 32'h8000_0598;
    localparam [31:0] SOFT_MUL_ENTRY_A0_PC  = 32'h8000_1db0;
    localparam [31:0] SOFT_MUL_ENTRY_A1_PC  = 32'h8000_1db8;
    localparam [31:0] SEG_ADDR              = 32'h8020_0020;
    localparam [31:0] LED_ADDR              = 32'h8020_0040;
    localparam time SIM_TIME_LIMIT_NS       = 64'd80_000_000_000;

    longint cycle_count;
    integer inner_cnt;
    integer outer_cnt;
    integer sum_update_count;
    integer seg_write_count;
    integer led_write_count;

    reg        sum_store_pending;
    reg [31:0] ref_state;
    reg [31:0] ref_sum;
    reg        trace_target_active;
    reg [31:0] trace_f_x;
    reg [31:0] trace_state_store;
    reg [31:0] trace_mul_arg_a0;
    reg        fetch_saw_47c;
    reg        ex_saw_47c;

    function window_pc;
        input [31:0] pc_i;
        begin
            window_pc = (pc_i >= 32'h8000_0470) && (pc_i <= 32'h8000_048c);
        end
    endfunction

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
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    function [31:0] check1_next_state;
        input [31:0] state_i;
        input [31:0] x_i;
        begin
            case (state_i)
                32'd0: check1_next_state = ((x_i & 32'd1) == 32'd0) ? 32'd1 : 32'd2;
                32'd1: check1_next_state = ((x_i % 32'd3) == 32'd0) ? 32'd2 : 32'd3;
                32'd2: check1_next_state = ((x_i % 32'd5) == 32'd0) ? 32'd3 : 32'd0;
                32'd3: check1_next_state = ((x_i % 32'd7) != 32'd0) ? 32'd1 : 32'd0;
                default: check1_next_state = 32'd0;
            endcase
        end
    endfunction

    function [31:0] soft_mul_ref;
        input [31:0] a_i;
        input [31:0] b_i;
        reg [31:0] a;
        reg [31:0] b;
        begin
            a = a_i;
            b = b_i;
            soft_mul_ref = 32'd0;
            while (b != 32'd0) begin
                if (b[0]) begin
                    soft_mul_ref = soft_mul_ref + a;
                end
                b = b >> 1;
                a = a << 1;
            end
        end
    endfunction

    task check_sum_update;
        reg [31:0] x;
        reg [31:0] next_state;
        reg [31:0] next_sum;
        reg [31:0] observed_sum;
        begin
            observed_sum = dut.perip_wdata;
            x = (inner_cnt * 32'd17) + 32'd23;
            next_state = check1_next_state(ref_state, x);
            next_sum = ref_sum + soft_mul_ref(inner_cnt + 1, next_state);

            if (dut.perip_wstrb == 4'b0000) begin
                $display("CHECK1_STORE_MISSING cyc=%0d outer=%0d inner=%0d wstrb=%b addr=%08h data=%08h",
                         cycle_count, outer_cnt, inner_cnt,
                         dut.perip_wstrb, dut.perip_addr, dut.perip_wdata);
                $finish;
            end

            sum_update_count = sum_update_count + 1;
            if (observed_sum !== next_sum) begin
                $display("FIRST_CHECK1_SUM_MISMATCH cyc=%0d outer=%0d inner=%0d update=%0d cpu=%08h gold=%08h prev_state=%0d next_state=%0d prev_sum=%08h x=%0d",
                         cycle_count, outer_cnt, inner_cnt, sum_update_count,
                         observed_sum, next_sum, ref_state, next_state, ref_sum, x);
                $finish;
            end

            ref_state = next_state;
            ref_sum = next_sum;

            if (inner_cnt == 255) begin
                if ((outer_cnt % 100) == 0) begin
                    $display("CHECK1_OUTER_OK cyc=%0d outer=%0d sum=%08h state=%0d updates=%0d",
                             cycle_count, outer_cnt, ref_sum, ref_state, sum_update_count);
                end
                inner_cnt = 0;
                outer_cnt = outer_cnt + 1;
            end else begin
                inner_cnt = inner_cnt + 1;
            end
        end
    endtask

    initial begin
        $display("TB_SRC1_CHECK1_SUM half_period_ns=%0.6f", (`TB_CPU_HALF_PERIOD_NS * 1.0));
        cycle_count = 0;
        inner_cnt = 0;
        outer_cnt = 0;
        sum_update_count = 0;
        seg_write_count = 0;
        led_write_count = 0;
        sum_store_pending = 1'b0;
        ref_state = 32'd0;
        ref_sum = 32'd0;
        trace_target_active = 1'b0;
        trace_f_x = 32'd0;
        trace_state_store = 32'd0;
        trace_mul_arg_a0 = 32'd0;
        fetch_saw_47c = 1'b0;
        ex_saw_47c = 1'b0;
        virtual_key = 8'd0;
        virtual_sw = 64'd0;
        w_clk_rst = 1'b1;
        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (w_clk_rst) begin
            cycle_count = 0;
            inner_cnt = 0;
            outer_cnt = 0;
            sum_update_count = 0;
            seg_write_count = 0;
            led_write_count = 0;
            sum_store_pending <= 1'b0;
            ref_state = 32'd0;
            ref_sum = 32'd0;
            trace_target_active = 1'b0;
            trace_f_x = 32'd0;
            trace_state_store = 32'd0;
            trace_mul_arg_a0 = 32'd0;
            fetch_saw_47c = 1'b0;
            ex_saw_47c = 1'b0;
        end else begin
            cycle_count = cycle_count + 1;

            if (sum_store_pending) begin
                check_sum_update();
            end

            if (outer_cnt == 0 &&
                (window_pc(dut.Core_cpu.cpu_core.pc_reg_pc_o) ||
                 window_pc(dut.Core_cpu.cpu_core.bp_fetch_pc_r) ||
                 window_pc(dut.Core_cpu.cpu_core.if_id_inst_addr_o) ||
                 window_pc(dut.Core_cpu.cpu_core.id_ex_inst_addr_o))) begin
                $display("FRONT_WIN cyc=%0d inner=%0d pc_reg=%08h irom_addr=%03h if_valid=%b ifid_fetch_valid=%b if_pc=%08h if_inst=%08h pred=%b pred_tgt=%08h fetch_redir=%b replay_redir=%b pc_jump=%b pc_jump_addr=%08h",
                         cycle_count, inner_cnt,
                         dut.Core_cpu.cpu_core.pc_reg_pc_o,
                         dut.inst_addr,
                         dut.Core_cpu.cpu_core.bp_if_valid,
                         dut.Core_cpu.cpu_core.ifid_fetch_valid,
                         dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                         dut.instruction,
                         dut.Core_cpu.cpu_core.bp_pred_taken_o,
                         dut.Core_cpu.cpu_core.bp_pred_target_o,
                         dut.Core_cpu.cpu_core.bp_fetch_redirect,
                         dut.Core_cpu.cpu_core.bp_replay_redirect,
                         dut.Core_cpu.cpu_core.pc_jump_en_o,
                         dut.Core_cpu.cpu_core.pc_jump_addr_o);
                $display("FRONT_IFID cyc=%0d hold=%b flush=%b direct=%b duplicate=%b skid_valid=%b replay_pending=%b replaying=%b ifid_pc=%08h ifid_inst=%08h ifid_valid=%b ifid_pred=%b ifid_tgt=%08h load_pred=%b load_tgt=%08h",
                         cycle_count,
                         dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                         dut.Core_cpu.cpu_core.frontend_flush_ifid,
                         dut.Core_cpu.cpu_core.ifid_direct_fire,
                         dut.Core_cpu.cpu_core.ifid_duplicate,
                         dut.Core_cpu.cpu_core.if_id_inst.is_holding_reg,
                         dut.Core_cpu.cpu_core.if_id_replay_pending_o,
                         dut.Core_cpu.cpu_core.if_id_replaying_o,
                         dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                         dut.Core_cpu.cpu_core.if_id_inst_o,
                         dut.Core_cpu.cpu_core.if_id_load_valid_o,
                         dut.Core_cpu.cpu_core.if_id_pred_taken_o,
                         dut.Core_cpu.cpu_core.if_id_pred_target_o,
                         dut.Core_cpu.cpu_core.if_id_load_pred_taken_o,
                         dut.Core_cpu.cpu_core.if_id_load_pred_target_o);
                $display("FRONT_IDEX cyc=%0d flush_idex=%b hdu_flush=%b idex_pc=%08h idex_inst=%08h idex_valid=%b idex_pred=%b idex_tgt=%08h kill_ex=%b ex_jmp=%b ex_jmp_addr=%08h ctrl_jmp=%b ctrl_addr=%08h jump_d1=%b pred_flush_d1=%b replay_flush_d1=%b",
                         cycle_count,
                         (dut.Core_cpu.cpu_core.hdu_flush_flag_o | dut.Core_cpu.cpu_core.frontend_flush_idex),
                         dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_o,
                         (dut.Core_cpu.cpu_core.id_ex_inst_o != 32'h0000_0013),
                         dut.Core_cpu.cpu_core.id_ex_pred_taken_o,
                         dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                         dut.Core_cpu.cpu_core.ctrl_kill_ex_o,
                         dut.Core_cpu.cpu_core.ex_jump_en_o,
                         dut.Core_cpu.cpu_core.ex_jump_addr_o,
                         dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                         dut.Core_cpu.cpu_core.ctrl_jump_addr_o,
                         dut.Core_cpu.cpu_core.ctrl_inst.jump_en_d1,
                         dut.Core_cpu.cpu_core.bp_pred_flush_d1_r,
                         dut.Core_cpu.cpu_core.bp_replay_flush_d1_r);
            end

            if (outer_cnt == 0 &&
                dut.Core_cpu.cpu_core.bp_fetch_pc_r == F_STATE0_BRANCH_PC &&
                dut.instruction == 32'h0007_9663) begin
                fetch_saw_47c = 1'b1;
                if (dut.Core_cpu.cpu_core.bp_pred_taken_o &&
                    dut.Core_cpu.cpu_core.ifid_fetch_valid &&
                    !dut.Core_cpu.cpu_core.ifid_direct_fire) begin
                    $display("BUG_PRED_TAKEN_NO_ACCEPT cyc=%0d if_pc=%08h target=%08h hold=%b replay_pending=%b duplicate=%b",
                             cycle_count,
                             dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                             dut.Core_cpu.cpu_core.bp_pred_target_o,
                             dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                             dut.Core_cpu.cpu_core.if_id_replay_pending_o,
                             dut.Core_cpu.cpu_core.ifid_duplicate);
                end
            end

            if (outer_cnt == 0 &&
                dut.Core_cpu.cpu_core.id_ex_inst_addr_o == F_STATE0_BRANCH_PC &&
                dut.Core_cpu.cpu_core.id_ex_inst_o == 32'h0007_9663) begin
                ex_saw_47c = 1'b1;
            end

            if (outer_cnt == 0 &&
                fetch_saw_47c &&
                !ex_saw_47c &&
                dut.Core_cpu.cpu_core.id_ex_inst_addr_o == 32'h8000_0488) begin
                $display("BUG_47C_DISAPPEARED cyc=%0d idex_pc=%08h idex_inst=%08h ifid_pc=%08h ifid_inst=%08h hold=%b flush_ifid=%b flush_idex=%b kill=%b fetch_redir=%b replay_redir=%b",
                         cycle_count,
                         dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_o,
                         dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                         dut.Core_cpu.cpu_core.if_id_inst_o,
                         dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                         dut.Core_cpu.cpu_core.frontend_flush_ifid,
                         (dut.Core_cpu.cpu_core.hdu_flush_flag_o | dut.Core_cpu.cpu_core.frontend_flush_idex),
                         dut.Core_cpu.cpu_core.ctrl_kill_ex_o,
                         dut.Core_cpu.cpu_core.bp_fetch_redirect,
                         dut.Core_cpu.cpu_core.bp_replay_redirect);
            end

            if (outer_cnt == 0) begin
                if (dut.Core_cpu.cpu_core.id_ex_inst_addr_o == F_STATE0_ANDI_PC &&
                    dut.Core_cpu.cpu_core.fwd_op1_o == 32'h0000_015a) begin
                    trace_f_x = dut.Core_cpu.cpu_core.fwd_op1_o;
                    trace_target_active = 1'b1;
                    $display("F_STATE0_ANDI cyc=%0d outer=%0d inner=%0d pc=%08h x_raw=%08h x_fwd=%08h and_result=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o,
                             dut.Core_cpu.cpu_core.ex_rd_data_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_0474 &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_0488) begin
                    $display("F_STATE0_WINDOW cyc=%0d outer=%0d inner=%0d pc=%08h inst=%08h raw1=%08h fwd1=%08h ex_rd=%08h actual_taken=%b ex_jmp=%b pred_taken=%b kill=%b",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             dut.Core_cpu.cpu_core.id_ex_inst_o,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o,
                             dut.Core_cpu.cpu_core.ex_rd_data_o,
                             dut.Core_cpu.cpu_core.bp_actual_taken_o,
                             dut.Core_cpu.cpu_core.ex_jump_en_o,
                             dut.Core_cpu.cpu_core.id_ex_pred_taken_o,
                             dut.Core_cpu.cpu_core.ctrl_kill_ex_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == F_STATE0_BRANCH_PC) begin
                    $display("F_STATE0_BRANCH cyc=%0d outer=%0d inner=%0d x=%08h raw_a5=%08h fwd_a5=%08h and_bit=%0d actual_taken=%b ex_jmp=%b pred_taken=%b kill=%b",
                             cycle_count, outer_cnt, inner_cnt, trace_f_x,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o,
                             dut.Core_cpu.cpu_core.id_ex_op1_o[0],
                             dut.Core_cpu.cpu_core.bp_actual_taken_o,
                             dut.Core_cpu.cpu_core.ex_jump_en_o,
                             dut.Core_cpu.cpu_core.id_ex_pred_taken_o,
                             dut.Core_cpu.cpu_core.ctrl_kill_ex_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == F_RET_MV_PC) begin
                    $display("F_RET cyc=%0d outer=%0d inner=%0d pc=%08h raw_a0=%08h fwd_a0=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == F_STATE_STORE_PC) begin
                    trace_state_store = dut.Core_cpu.cpu_core.ex_wd_data_o;
                    $display("F_RET_STORE cyc=%0d outer=%0d inner=%0d pc=%08h stored_state=%08h store_addr=%08h wstrb=%b",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                             dut.Core_cpu.cpu_core.ex_wd_data_o,
                             dut.Core_cpu.cpu_core.ex_wd_addr_o,
                             dut.Core_cpu.cpu_core.ex_wd_reg_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == MUL_ARG_A0_PC) begin
                    trace_mul_arg_a0 = dut.Core_cpu.cpu_core.fwd_op1_o;
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == MUL_CALL_PC) begin
                    $display("MUL_CALL cyc=%0d outer=%0d inner=%0d a0=%08h a1=%08h stale_a0_reg=%08h stale_a1_reg=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             trace_mul_arg_a0,
                             trace_state_store,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.Core_cpu.cpu_core.regs_inst.regs[11]);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == SOFT_MUL_ENTRY_A0_PC) begin
                    $display("MUL_ENTRY_A0 cyc=%0d outer=%0d inner=%0d raw_a0=%08h fwd_a0=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == SOFT_MUL_ENTRY_A1_PC) begin
                    $display("MUL_ENTRY_A1 cyc=%0d outer=%0d inner=%0d raw_a1=%08h fwd_a1=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o);
                end

                if (trace_target_active &&
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o == MUL_RET_PC) begin
                    $display("MUL_RET cyc=%0d outer=%0d inner=%0d raw_a0=%08h fwd_a0=%08h a0_reg=%08h a5_reg=%08h",
                             cycle_count, outer_cnt, inner_cnt,
                             dut.Core_cpu.cpu_core.id_ex_op1_o,
                             dut.Core_cpu.cpu_core.fwd_op1_o,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.Core_cpu.cpu_core.regs_inst.regs[15]);
                end
            end

            sum_store_pending <=
                (dut.Core_cpu.cpu_core.id_ex_inst_addr_o == CHECK1_SUM_STORE_PC) &&
                (dut.Core_cpu.cpu_core.id_ex_inst_o == CHECK1_SUM_STORE_INST) &&
                !dut.Core_cpu.cpu_core.ctrl_kill_ex_o;

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == SEG_ADDR) begin
                seg_write_count = seg_write_count + 1;
                $display("SEG_WRITE #%0d cyc=%0d pc=%08h data=%08h",
                         seg_write_count, cycle_count, dut.pc, dut.perip_wdata);
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == LED_ADDR) begin
                led_write_count = led_write_count + 1;
                $display("LED_WRITE #%0d cyc=%0d pc=%08h data=%08h outer=%0d inner=%0d updates=%0d ref_sum=%08h",
                         led_write_count, cycle_count, dut.pc, dut.perip_wdata,
                         outer_cnt, inner_cnt, sum_update_count, ref_sum);
                $display("CHECK1_DONE led=%08h seg=%010h outer=%0d inner=%0d updates=%0d ref_sum=%08h",
                         virtual_led, virtual_seg, outer_cnt, inner_cnt,
                         sum_update_count, ref_sum);
                $finish;
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        $display("TIMEOUT cyc=%0d outer=%0d inner=%0d updates=%0d ref_sum=%08h seg_writes=%0d led_writes=%0d",
                 cycle_count, outer_cnt, inner_cnt, sum_update_count, ref_sum,
                 seg_write_count, led_write_count);
        $finish;
    end
endmodule
