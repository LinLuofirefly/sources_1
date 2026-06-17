`timescale 1ns / 1ps

module tb_branch_replay_probe;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] PC_ANDI = 32'h8000_1fb0;
    localparam [31:0] PC_BEQZ = 32'h8000_1fb4;
    localparam [31:0] PC_ADD  = 32'h8000_1fb8;
    localparam [31:0] PC_SRLI = 32'h8000_1fbc;

    integer cycle_count;
    integer trace_count;
    integer ex_redirect_fbc_count;
    integer dup_fbc_count;
    integer idex_srli_count;

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

    function automatic bit pc_near_mul_loop;
        input [31:0] pc;
        begin
            pc_near_mul_loop = (pc >= 32'h8000_1fac) && (pc <= 32'h8000_1fc4);
        end
    endfunction

    task automatic print_state;
        input [127:0] tag;
        begin
            $display(
                "%0s cyc=%0d pc=%08h fetch_pc=%08h inst_i=%08h ifv=%b dup=%b hold=%b hflush=%b replay_pend=%b replaying=%b ifid_v=%b ifid_pc=%08h ifid_inst=%08h idex_pc=%08h idex_inst=%08h ex_jump=%b ex_jaddr=%08h ctrl_flush=%b pred_flush_d1=%b replay_flush_d1=%b",
                tag,
                cycle_count,
                dut.Core_cpu.cpu_core.pc_reg_pc_o,
                dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                dut.instruction,
                dut.Core_cpu.cpu_core.ifid_fetch_valid,
                dut.Core_cpu.cpu_core.ifid_duplicate,
                dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                dut.Core_cpu.cpu_core.if_id_replay_pending_o,
                dut.Core_cpu.cpu_core.if_id_replaying_o,
                dut.Core_cpu.cpu_core.if_id_load_valid_o,
                dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                dut.Core_cpu.cpu_core.if_id_inst_o,
                dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                dut.Core_cpu.cpu_core.id_ex_inst_o,
                dut.Core_cpu.cpu_core.ex_jump_en_o,
                dut.Core_cpu.cpu_core.ex_jump_addr_o,
                dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                dut.Core_cpu.cpu_core.bp_pred_flush_d1_r,
                dut.Core_cpu.cpu_core.bp_replay_flush_d1_r
            );
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        trace_count = 0;
        ex_redirect_fbc_count = 0;
        dup_fbc_count = 0;
        idex_srli_count = 0;

        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if ((dut.Core_cpu.cpu_core.id_ex_inst_addr_o == PC_SRLI) &&
                (dut.Core_cpu.cpu_core.id_ex_inst_o == 32'h0015d593)) begin
                idex_srli_count = idex_srli_count + 1;
                if (idex_srli_count <= 20) begin
                    $display("IDEX_SRLI cyc=%0d count=%0d hold=%b ex_jump=%b ifid_pc=%08h fetch_pc=%08h dup=%b",
                             cycle_count, idex_srli_count,
                             dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                             dut.Core_cpu.cpu_core.ex_jump_en_o,
                             dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                             dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                             dut.Core_cpu.cpu_core.ifid_duplicate);
                end
            end

            if (dut.Core_cpu.cpu_core.ex_jump_en_o &&
                (dut.Core_cpu.cpu_core.ex_jump_addr_o == PC_SRLI)) begin
                ex_redirect_fbc_count = ex_redirect_fbc_count + 1;
                print_state("EX_REDIRECT_FBC");
            end

            if (dut.Core_cpu.cpu_core.ifid_duplicate &&
                (dut.Core_cpu.cpu_core.bp_fetch_pc_r == PC_SRLI)) begin
                dup_fbc_count = dup_fbc_count + 1;
                print_state("DUP_FBC");
            end

            if ((trace_count < 160) &&
                (pc_near_mul_loop(dut.Core_cpu.cpu_core.bp_fetch_pc_r) ||
                 pc_near_mul_loop(dut.Core_cpu.cpu_core.if_id_inst_addr_o) ||
                 pc_near_mul_loop(dut.Core_cpu.cpu_core.id_ex_inst_addr_o) ||
                 dut.Core_cpu.cpu_core.ifid_duplicate ||
                 dut.Core_cpu.cpu_core.if_id_replaying_o ||
                 dut.Core_cpu.cpu_core.ex_jump_en_o)) begin
                trace_count = trace_count + 1;
                print_state("TRACE");
            end

            if ((ex_redirect_fbc_count >= 3) && (dup_fbc_count >= 1)) begin
                $display("BRANCH_REPLAY_PROBE_DONE cyc=%0d ex_redirect_fbc=%0d dup_fbc=%0d idex_srli=%0d",
                         cycle_count, ex_redirect_fbc_count, dup_fbc_count, idex_srli_count);
                $finish;
            end

            if (cycle_count >= 400000) begin
                $display("BRANCH_REPLAY_PROBE_TIMEOUT cyc=%0d ex_redirect_fbc=%0d dup_fbc=%0d idex_srli=%0d pc=%08h",
                         cycle_count, ex_redirect_fbc_count, dup_fbc_count, idex_srli_count,
                         dut.Core_cpu.cpu_core.pc_reg_pc_o);
                $finish;
            end
        end
    end
endmodule
