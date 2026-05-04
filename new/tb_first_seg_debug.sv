`timescale 1ns / 1ps

module tb_first_seg_debug;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer HISTORY_LEN = 64;
    localparam [31:0] SEG_ADDR     = 32'h8020_0020;
    localparam [31:0] FIRST_EXPECT = 32'h3700_0000;

    integer cycle_count;
    integer hist_wr_ptr;
    integer hist_count;
    integer j;
    integer slot;

    reg [31:0] hist_pc       [0:HISTORY_LEN-1];
    reg [31:0] hist_cycle    [0:HISTORY_LEN-1];
    reg [31:0] hist_inst     [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid     [0:HISTORY_LEN-1];
    reg [31:0] hist_idex     [0:HISTORY_LEN-1];
    reg [31:0] hist_exmem    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem1     [0:HISTORY_LEN-1];
    reg [31:0] hist_mem12    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2a    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2     [0:HISTORY_LEN-1];
    reg        hist_hold     [0:HISTORY_LEN-1];
    reg        hist_hflush   [0:HISTORY_LEN-1];
    reg        hist_ifflush  [0:HISTORY_LEN-1];
    reg        hist_idflush  [0:HISTORY_LEN-1];
    reg [31:0] hist_fop1     [0:HISTORY_LEN-1];
    reg [31:0] hist_fop2     [0:HISTORY_LEN-1];
    reg        hist_wbwen    [0:HISTORY_LEN-1];
    reg [4:0]  hist_wbaddr   [0:HISTORY_LEN-1];
    reg [31:0] hist_wbdata   [0:HISTORY_LEN-1];
    reg [31:0] hist_x8       [0:HISTORY_LEN-1];
    reg [31:0] hist_x10      [0:HISTORY_LEN-1];
    reg [31:0] hist_x14      [0:HISTORY_LEN-1];
    reg [31:0] hist_x15      [0:HISTORY_LEN-1];
    reg [31:0] hist_seg      [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_addr  [0:HISTORY_LEN-1];
    reg        hist_rd_req   [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_data  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_addr  [0:HISTORY_LEN-1];
    reg [3:0]  hist_wr_strb  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_data  [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid_pc  [0:HISTORY_LEN-1];
    reg [31:0] hist_issue_pc [0:HISTORY_LEN-1];
    reg [31:0] hist_issue_inst [0:HISTORY_LEN-1];
    reg [31:0] hist_idex_pc  [0:HISTORY_LEN-1];
    reg [31:0] hist_exmem_pc [0:HISTORY_LEN-1];
    reg [31:0] hist_emit1    [0:HISTORY_LEN-1];
    reg [31:0] hist_emit2    [0:HISTORY_LEN-1];
    reg [31:0] hist_exfwd1   [0:HISTORY_LEN-1];
    reg [31:0] hist_exfwd2   [0:HISTORY_LEN-1];
    reg        hist_issue_v  [0:HISTORY_LEN-1];
    reg        hist_issue_r  [0:HISTORY_LEN-1];
    reg        hist_issue_f  [0:HISTORY_LEN-1];
    reg        hist_if_replay[0:HISTORY_LEN-1];
    reg        hist_idpflush [0:HISTORY_LEN-1];
    reg        hist_jump_en  [0:HISTORY_LEN-1];
    reg [31:0] hist_jump_addr[0:HISTORY_LEN-1];
    reg        hist_bp_take  [0:HISTORY_LEN-1];
    reg        hist_bp_acc   [0:HISTORY_LEN-1];
    reg [31:0] hist_bp_tgt   [0:HISTORY_LEN-1];
    reg [31:0] hist_pc_req   [0:HISTORY_LEN-1];
    reg [31:0] hist_fetch_pc [0:HISTORY_LEN-1];
    reg        hist_fetch_v  [0:HISTORY_LEN-1];
    reg [31:0] hist_fetch_inst [0:HISTORY_LEN-1];
    reg        hist_bp_if_valid [0:HISTORY_LEN-1];
    reg        hist_ifetch_req_fire [0:HISTORY_LEN-1];
    reg        hist_front_hold [0:HISTORY_LEN-1];
    reg        hist_ifid_valid [0:HISTORY_LEN-1];
    reg        hist_ifid_consume [0:HISTORY_LEN-1];
    reg        hist_id_issue_valid [0:HISTORY_LEN-1];
    reg        hist_ex_jump_en [0:HISTORY_LEN-1];
    reg [31:0] hist_ex_jump_addr [0:HISTORY_LEN-1];
    reg        hist_ctrl_redirect_hold [0:HISTORY_LEN-1];
    reg        hist_ctrl_jump_en [0:HISTORY_LEN-1];
    reg        hist_ctrl_flush_ifid_d1 [0:HISTORY_LEN-1];
    reg        hist_pc_jump_en [0:HISTORY_LEN-1];
    reg [31:0] hist_pc_jump_addr [0:HISTORY_LEN-1];
    reg [4:0]  hist_ex_rd    [0:HISTORY_LEN-1];
    reg [31:0] hist_ex_data  [0:HISTORY_LEN-1];
    reg        hist_ex_wen   [0:HISTORY_LEN-1];
    reg        hist_ex_ld    [0:HISTORY_LEN-1];
    reg [4:0]  hist_m1_rd    [0:HISTORY_LEN-1];
    reg [31:0] hist_m1_data  [0:HISTORY_LEN-1];
    reg        hist_m1_wen   [0:HISTORY_LEN-1];
    reg        hist_m1_ld    [0:HISTORY_LEN-1];
    reg [4:0]  hist_m12_rd   [0:HISTORY_LEN-1];
    reg [31:0] hist_m12_data [0:HISTORY_LEN-1];
    reg        hist_m12_wen  [0:HISTORY_LEN-1];
    reg        hist_m12_ld   [0:HISTORY_LEN-1];
    reg [4:0]  hist_m2a_rd   [0:HISTORY_LEN-1];
    reg [31:0] hist_m2a_data [0:HISTORY_LEN-1];
    reg        hist_m2a_wen  [0:HISTORY_LEN-1];
    reg        hist_m2a_ld   [0:HISTORY_LEN-1];
    reg [4:0]  hist_m2_rd    [0:HISTORY_LEN-1];
    reg [31:0] hist_m2_data  [0:HISTORY_LEN-1];
    reg        hist_m2_wen   [0:HISTORY_LEN-1];
    reg [4:0]  hist_mwb_rd   [0:HISTORY_LEN-1];
    reg [31:0] hist_mwb_data [0:HISTORY_LEN-1];
    reg        hist_mwb_wen  [0:HISTORY_LEN-1];
    reg [31:0] hist_x1       [0:HISTORY_LEN-1];
    reg [31:0] hist_x2       [0:HISTORY_LEN-1];
    reg [31:0] hist_x11      [0:HISTORY_LEN-1];
    reg [31:0] hist_x12      [0:HISTORY_LEN-1];
    reg [31:0] hist_x13      [0:HISTORY_LEN-1];
    reg [31:0] hist_x5       [0:HISTORY_LEN-1];
    reg [31:0] hist_x6       [0:HISTORY_LEN-1];
    reg        seen_bad_a0;
    reg        seen_bad_a3;
    reg        seen_bad_ret_zero;
    reg        seen_bp_ret_pending_accept;

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

    task automatic dump_history;
        integer start_idx;
        begin
            $display("FIRST_SEG_DEBUG_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "DBG cyc=%0d pc=%08h inst=%08h | ifid=(%08h@%08h rp=%0d) issue=(%08h@%08h v=%0d r=%0d f=%0d e=%08h/%08h) idex=(%08h@%08h) exmem=(%08h@%08h je=%0d ja=%08h) mem1=%08h mem12=%08h m2a=%08h m2=%08h | hold=%0d hfl=%0d iffl=%0d idpfl=%0d idfl=%0d | exfwd=%08h/%08h bp=%0d/%0d/%08h | exrd=(%0d,%0d,%0d,%08h) m1=(%0d,%0d,%0d,%08h) m12=(%0d,%0d,%0d,%08h) m2a=(%0d,%0d,%0d,%08h) m2=(%0d,%0d,%08h) mwb=(%0d,%0d,%08h) wb=(%0d,%0d,%08h) | x1=%08h x2=%08h x5=%08h x6=%08h x8=%08h x10=%08h x11=%08h x12=%08h x13=%08h x14=%08h x15=%08h | rd=(%0d,%08h,%08h) wr=(%b,%08h,%08h) seg=%08h",
                    hist_cycle[slot],
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_ifid_pc[slot],
                    hist_if_replay[slot],
                    hist_ifid[slot],
                    hist_issue_pc[slot],
                    hist_issue_v[slot],
                    hist_issue_r[slot],
                    hist_issue_f[slot],
                    hist_emit1[slot],
                    hist_emit2[slot],
                    hist_idex[slot],
                    hist_idex_pc[slot],
                    hist_exmem[slot],
                    hist_exmem_pc[slot],
                    hist_jump_en[slot],
                    hist_jump_addr[slot],
                    hist_mem1[slot],
                    hist_mem12[slot],
                    hist_mem2a[slot],
                    hist_mem2[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_ifflush[slot],
                    hist_idpflush[slot],
                    hist_idflush[slot],
                    hist_exfwd1[slot],
                    hist_exfwd2[slot],
                    hist_bp_take[slot],
                    hist_bp_acc[slot],
                    hist_bp_tgt[slot],
                    hist_ex_rd[slot],
                    hist_ex_wen[slot],
                    hist_ex_ld[slot],
                    hist_ex_data[slot],
                    hist_m1_rd[slot],
                    hist_m1_wen[slot],
                    hist_m1_ld[slot],
                    hist_m1_data[slot],
                    hist_m12_rd[slot],
                    hist_m12_wen[slot],
                    hist_m12_ld[slot],
                    hist_m12_data[slot],
                    hist_m2a_rd[slot],
                    hist_m2a_wen[slot],
                    hist_m2a_ld[slot],
                    hist_m2a_data[slot],
                    hist_m2_rd[slot],
                    hist_m2_wen[slot],
                    hist_m2_data[slot],
                    hist_mwb_rd[slot],
                    hist_mwb_wen[slot],
                    hist_mwb_data[slot],
                    hist_wbaddr[slot],
                    hist_wbwen[slot],
                    hist_wbdata[slot],
                    hist_x1[slot],
                    hist_x2[slot],
                    hist_x5[slot],
                    hist_x6[slot],
                    hist_x8[slot],
                    hist_x10[slot],
                    hist_x11[slot],
                    hist_x12[slot],
                    hist_x13[slot],
                    hist_x14[slot],
                    hist_x15[slot],
                    hist_rd_req[slot],
                    hist_rd_addr[slot],
                    hist_rd_data[slot],
                    hist_wr_strb[slot],
                    hist_wr_addr[slot],
                    hist_wr_data[slot],
                    hist_seg[slot]
                );
                $display(
                    "DBG2 cyc=%0d req(pc=%08h fvalid=%0d ifvalid=%0d fire=%0d hold=%0d inst=%08h) | ifid(v=%0d rp=%0d cons=%0d pc=%08h inst=%08h) | issue(in_v=%0d v=%0d r=%0d f=%0d pc=%08h inst=%08h) | exjump=(%0d,%08h) ctrl=(rhold=%0d jump=%0d iffl=%0d iffl_d1=%0d idpfl=%0d idexfl=%0d) | pred=(take=%0d acc=%0d tgt=%08h) pcjump=(%0d,%08h)",
                    hist_cycle[slot],
                    hist_pc_req[slot],
                    hist_fetch_v[slot],
                    hist_bp_if_valid[slot],
                    hist_ifetch_req_fire[slot],
                    hist_front_hold[slot],
                    hist_fetch_inst[slot],
                    hist_ifid_valid[slot],
                    hist_if_replay[slot],
                    hist_ifid_consume[slot],
                    hist_ifid_pc[slot],
                    hist_ifid[slot],
                    hist_id_issue_valid[slot],
                    hist_issue_v[slot],
                    hist_issue_r[slot],
                    hist_issue_f[slot],
                    hist_issue_pc[slot],
                    hist_issue_inst[slot],
                    hist_ex_jump_en[slot],
                    hist_ex_jump_addr[slot],
                    hist_ctrl_redirect_hold[slot],
                    hist_ctrl_jump_en[slot],
                    hist_ifflush[slot],
                    hist_ctrl_flush_ifid_d1[slot],
                    hist_idpflush[slot],
                    hist_idflush[slot],
                    hist_bp_take[slot],
                    hist_bp_acc[slot],
                    hist_bp_tgt[slot],
                    hist_pc_jump_en[slot],
                    hist_pc_jump_addr[slot]
                );
            end
            $display("FIRST_SEG_DEBUG_HISTORY_END");
        end
    endtask

    initial begin
        $dumpfile("tb_first_seg_debug.vcd");
        $dumpvars(0, tb_first_seg_debug);
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        hist_wr_ptr = 0;
        hist_count  = 0;
        seen_bad_a0 = 1'b0;
        seen_bad_a3 = 1'b0;
        seen_bad_ret_zero = 1'b0;
        seen_bp_ret_pending_accept = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        repeat (5000) @(posedge w_cpu_clk);
        $display("FIRST_SEG_DEBUG_TIMEOUT pc=%08h inst=%08h seg=%08h", dut.pc, dut.instruction, dut.bridge_inst.seg_wdata);
        dump_history();
        $finish;
    end
    reg [31:0] sb_mem [0:4095];
integer sb_i;

initial begin
    for (sb_i = 0; sb_i < 4096; sb_i = sb_i + 1) begin
        sb_mem[sb_i] = 32'h0;
    end
end

always @(posedge w_cpu_clk) begin
    if (!w_clk_rst) begin
        if (dut.perip_wstrb != 4'b0000) begin
            if (dut.perip_wstrb[0]) sb_mem[dut.perip_addr[13:2]][7:0]   <= dut.perip_wdata[7:0];
            if (dut.perip_wstrb[1]) sb_mem[dut.perip_addr[13:2]][15:8]  <= dut.perip_wdata[15:8];
            if (dut.perip_wstrb[2]) sb_mem[dut.perip_addr[13:2]][23:16] <= dut.perip_wdata[23:16];
            if (dut.perip_wstrb[3]) sb_mem[dut.perip_addr[13:2]][31:24] <= dut.perip_wdata[31:24];

            if (dut.perip_addr >= 32'h00000400 && dut.perip_addr <= 32'h00000480) begin
                $display("SB_WRITE cyc=%0d addr=%08h idx=%0d data=%08h strb=%b new=%08h",
                    cycle_count,
                    dut.perip_addr,
                    dut.perip_addr[13:2],
                    dut.perip_wdata,
                    dut.perip_wstrb,
                    sb_mem[dut.perip_addr[13:2]]
                );
            end
        end

        if (dut.perip_rd_en &&
            dut.perip_rd_addr >= 32'h00000400 &&
            dut.perip_rd_addr <= 32'h00000480) begin
            $display("SB_READ cyc=%0d addr=%08h idx=%0d dut_rdata=%08h expected=%08h",
                cycle_count,
                dut.perip_rd_addr,
                dut.perip_rd_addr[13:2],
                dut.perip_rdata,
                sb_mem[dut.perip_rd_addr[13:2]]
            );
        end
    end
end
    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            hist_pc[hist_wr_ptr]      <= dut.pc;
            hist_cycle[hist_wr_ptr]   <= cycle_count;
            hist_inst[hist_wr_ptr]    <= dut.instruction;
            hist_pc_req[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.pc_reg_pc_o;
            hist_fetch_pc[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_fetch_pc_r;
            hist_fetch_v[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_fetch_valid_r;
            hist_fetch_inst[hist_wr_ptr] <= dut.Core_cpu.cpu_core.inst_i;
            hist_bp_if_valid[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_if_valid;
            hist_ifetch_req_fire[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ifetch_req_fire;
            hist_front_hold[hist_wr_ptr] <= dut.Core_cpu.cpu_core.front_hold_o;
            hist_ifid[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.if_id_inst_o;
            hist_ifid_valid[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_valid_o;
            hist_idex[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.id_ex_inst_o;
            hist_exmem[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_mem1[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.mem_inst_o;
            hist_mem12[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            hist_mem2a[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_mem2[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_hold[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_ifflush[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_ifid_o;
            hist_idflush[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_idex_o;
            hist_fop1[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_fop2[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_wbwen[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.wb_rd_wen_o;
            hist_wbaddr[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.wb_rd_addr_o;
            hist_wbdata[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.wb_rd_data_o;
            hist_x8[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[8];
            hist_x10[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x14[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_seg[hist_wr_ptr]     <= dut.bridge_inst.seg_wdata;
            hist_rd_addr[hist_wr_ptr] <= dut.perip_rd_addr;
            hist_rd_req[hist_wr_ptr]  <= dut.perip_rd_en;
            hist_rd_data[hist_wr_ptr] <= dut.perip_rdata;
            hist_wr_addr[hist_wr_ptr] <= dut.perip_addr;
            hist_wr_strb[hist_wr_ptr] <= dut.perip_wstrb;
            hist_wr_data[hist_wr_ptr] <= dut.perip_wdata;
            hist_ifid_pc[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_inst_addr_o;
            hist_issue_pc[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_inst_addr_o;
            hist_issue_inst[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_inst_o;
            hist_idex_pc[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_ex_inst_addr_o;
            hist_exmem_pc[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_emit1[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.issue_emit_op1_o;
            hist_emit2[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.issue_emit_op2_o;
            hist_exfwd1[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_exfwd2[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_issue_v[hist_wr_ptr] <= dut.Core_cpu.cpu_core.issue_valid_o;
            hist_issue_r[hist_wr_ptr] <= dut.Core_cpu.cpu_core.issue_ready_o;
            hist_issue_f[hist_wr_ptr] <= dut.Core_cpu.cpu_core.issue_fire_o;
            hist_if_replay[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_replaying_o;
            hist_ifid_consume[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_consume_i;
            hist_id_issue_valid[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_issue_valid_i;
            hist_idpflush[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o;
            hist_jump_en[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_jump_en_o;
            hist_jump_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_jump_addr_o;
            hist_ex_jump_en[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ex_jump_en_o;
            hist_ex_jump_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ex_jump_addr_o;
            hist_ctrl_redirect_hold[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_redirect_hold_o;
            hist_ctrl_jump_en[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_jump_en_o;
            hist_ctrl_flush_ifid_d1[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_ifid_d1_r;
            hist_bp_take[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_pred_taken_o;
            hist_bp_acc[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o;
            hist_bp_tgt[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.bp_pred_target_o;
            hist_pc_jump_en[hist_wr_ptr] <= dut.Core_cpu.cpu_core.pc_jump_en_o;
            hist_pc_jump_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.pc_jump_addr_o;
            hist_ex_rd[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.ex_mem_pipe_rd_addr_o;
            hist_ex_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ex_mem_rd_data_o;
            hist_ex_wen[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.ex_mem_rd_wen_o;
            hist_ex_ld[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.ex_mem_is_load_o;
            hist_m1_rd[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem_out_rd_addr_o;
            hist_m1_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem_out_rd_data_o;
            hist_m1_wen[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem_out_rd_wen_o;
            hist_m1_ld[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem_out_is_load_o;
            hist_m12_rd[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem1_mem2_rd_addr_o;
            hist_m12_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem1_mem2_rd_data_o;
            hist_m12_wen[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem1_mem2_rd_wen_o;
            hist_m12_ld[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem1_mem2_is_load_o;
            hist_m2a_rd[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem2_align_rd_addr_o;
            hist_m2a_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem2_align_rd_data_o;
            hist_m2a_wen[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem2_align_rd_wen_o;
            hist_m2a_ld[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem2_align_is_load_o;
            hist_m2_rd[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem2_rd_addr_o;
            hist_m2_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem2_rd_data_o;
            hist_m2_wen[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem2_rd_wen_o;
            hist_mwb_rd[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.mem_wb_rd_addr_o;
            hist_mwb_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem_wb_rd_data_o;
            hist_mwb_wen[hist_wr_ptr] <= dut.Core_cpu.cpu_core.mem_wb_rd_wen_o;
            hist_x1[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[1];
            hist_x2[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[2];
            hist_x11[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[11];
            hist_x12[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[12];
            hist_x13[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[13];
            hist_x5[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[5];
            hist_x6[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[6];

            if (cycle_count <= 1500) begin
                $display(
                    "FIRST1500 cyc=%0d pc_req=%08h fetch_pc=%08h inst_i=%08h bp_if_valid=%0d ifetch_fire=%0d front_hold=%0d | ifid(v=%0d rp=%0d cons=%0d pc=%08h inst=%08h) | issue(r=%0d v=%0d f=%0d in_v=%0d pc=%08h inst=%08h) | exjump=(%0d,%08h) ctrl=(rhold=%0d jump=%0d iffl=%0d iffl_d1=%0d idpfl=%0d idexfl=%0d) | pred=(take=%0d acc=%0d tgt=%08h) pcjump=(%0d,%08h)",
                    cycle_count,
                    dut.Core_cpu.cpu_core.pc_reg_pc_o,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.inst_i,
                    dut.Core_cpu.cpu_core.bp_if_valid,
                    dut.Core_cpu.cpu_core.ifetch_req_fire,
                    dut.Core_cpu.cpu_core.front_hold_o,
                    dut.Core_cpu.cpu_core.if_id_valid_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o,
                    dut.Core_cpu.cpu_core.if_id_consume_i,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_issue_valid_i,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o,
                    dut.Core_cpu.cpu_core.ctrl_redirect_hold_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_d1_r,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.bp_pred_target_o,
                    dut.Core_cpu.cpu_core.pc_jump_en_o,
                    dut.Core_cpu.cpu_core.pc_jump_addr_o
                );
            end

            if (hist_count < HISTORY_LEN) begin
                hist_count <= hist_count + 1;
            end
            hist_wr_ptr <= (hist_wr_ptr + 1) % HISTORY_LEN;

            if (dut.perip_wstrb != 4'b0000) begin
                $display("DBG_WRITE cyc=%0d time=%0t addr=%08h wstrb=%b data=%08h pc=%08h inst=%08h",
                         cycle_count, $time, dut.perip_addr, dut.perip_wstrb, dut.perip_wdata, dut.pc, dut.instruction);
            end

            if (dut.perip_rd_en) begin
                $display("DBG_READ cyc=%0d time=%0t addr=%08h rdata=%08h pc=%08h inst=%08h",
                         cycle_count, $time, dut.perip_rd_addr, dut.perip_rdata, dut.pc, dut.instruction);
            end

            if (!seen_bad_a0 && (dut.Core_cpu.cpu_core.regs_inst.regs[10] == 32'hffff_ffff)) begin
                seen_bad_a0 <= 1'b1;
                $display("FIRST_BAD_A0 cyc=%0d pc=%08h inst=%08h", cycle_count, dut.pc, dut.instruction);
                dump_history();
            end

            if (!seen_bad_a3 && (dut.Core_cpu.cpu_core.regs_inst.regs[13] == 32'h0000_0004)) begin
                seen_bad_a3 <= 1'b1;
                $display("FIRST_BAD_A3 cyc=%0d pc=%08h inst=%08h", cycle_count, dut.pc, dut.instruction);
                dump_history();
            end

            if (((dut.pc >= 32'h8000_0070) && (dut.pc <= 32'h8000_0100)) ||
                ((dut.pc >= 32'h8000_1e60) && (dut.pc <= 32'h8000_1f2c)) ||
                ((dut.Core_cpu.cpu_core.if_id_inst_addr_o >= 32'h8000_0070) && (dut.Core_cpu.cpu_core.if_id_inst_addr_o <= 32'h8000_0100)) ||
                ((dut.Core_cpu.cpu_core.if_id_inst_addr_o >= 32'h8000_1e60) && (dut.Core_cpu.cpu_core.if_id_inst_addr_o <= 32'h8000_1f2c)) ||
                ((dut.Core_cpu.cpu_core.id_pipe_inst_addr_o >= 32'h8000_0070) && (dut.Core_cpu.cpu_core.id_pipe_inst_addr_o <= 32'h8000_0100)) ||
                ((dut.Core_cpu.cpu_core.id_pipe_inst_addr_o >= 32'h8000_1e60) && (dut.Core_cpu.cpu_core.id_pipe_inst_addr_o <= 32'h8000_1f2c)) ||
                ((dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_0070) && (dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_0100)) ||
                ((dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_1e60) && (dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_1f2c))) begin
                $display(
                    "HELPER_TRACE cyc=%0d pc=%08h inst=%08h | ifid=(%08h@%08h rp=%0d) issue=(%08h@%08h v=%0d r=%0d f=%0d emit=%08h/%08h) idex=(%08h@%08h op1=%08h op2=%08h) exfwd=(%08h,%08h) exmem=(%08h rd=%0d wen=%0d ld=%0d data=%08h memra=%08h) mem1=(%08h rd=%0d wen=%0d ld=%0d data=%08h) m12=(rd=%0d wen=%0d ld=%0d data=%08h) m2a=(rd=%0d wen=%0d ld=%0d data=%08h) m2=(%08h rd=%0d wen=%0d data=%08h) mwb=(rd=%0d wen=%0d data=%08h) wb=(rd=%0d wen=%0d data=%08h) | a0=%08h a1=%08h a2=%08h a3=%08h s0=%08h sp=%08h ra=%08h | hold=%0d hfl=%0d iffl=%0d idpfl=%0d idfl=%0d",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.issue_emit_op1_o,
                    dut.Core_cpu.cpu_core.issue_emit_op2_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_op1_o,
                    dut.Core_cpu.cpu_core.id_ex_op2_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_op2_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_pipe_rd_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_mem_is_load_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_data_o,
                    dut.Core_cpu.cpu_core.ex_mem_mem_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_out_is_load_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_data_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_is_load_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_align_is_load_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_data_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[10],
                    dut.Core_cpu.cpu_core.regs_inst.regs[11],
                    dut.Core_cpu.cpu_core.regs_inst.regs[12],
                    dut.Core_cpu.cpu_core.regs_inst.regs[13],
                    dut.Core_cpu.cpu_core.regs_inst.regs[8],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o
                );
                $display(
                    "FETCH_TRACE cyc=%0d reqpc=%08h fetch=(v=%0d pc=%08h inst=%08h) pc_now=%08h inst_now=%08h hold=%0d jump=%0d bpacc=%0d",
                    cycle_count,
                    dut.Core_cpu.cpu_core.pc_reg_pc_o,
                    dut.Core_cpu.cpu_core.bp_fetch_valid_r,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.inst_i,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.front_hold_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o
                );
            end

            if (((dut.pc >= 32'h8000_1e60) && (dut.pc <= 32'h8000_1f2c)) ||
                ((dut.Core_cpu.cpu_core.if_id_inst_addr_o >= 32'h8000_1e60) && (dut.Core_cpu.cpu_core.if_id_inst_addr_o <= 32'h8000_1f2c)) ||
                ((dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_1e60) && (dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_1f2c))) begin
                $display(
                    "DIV_TRACE cyc=%0d pc=%08h inst=%08h ifid=(%08h@%08h) idex=(%08h@%08h) exmem=%08h mem1=%08h m2=%08h | a0=%08h a1=%08h a2=%08h a3=%08h t0=%08h t1=%08h | hold=%0d hfl=%0d iffl=%0d idfl=%0d",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[10],
                    dut.Core_cpu.cpu_core.regs_inst.regs[11],
                    dut.Core_cpu.cpu_core.regs_inst.regs[12],
                    dut.Core_cpu.cpu_core.regs_inst.regs[13],
                    dut.Core_cpu.cpu_core.regs_inst.regs[5],
                    dut.Core_cpu.cpu_core.regs_inst.regs[6],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o
                );
            end


            // -----------------------------------------------------------------
            // RET/JALR debug: track why 00008067 calculates jump target 0.
            // This prints only when a ret-like instruction is visible in the
            // front end / issue / ID_EX / EX path, or when IF sees ret-like JALR.
            // -----------------------------------------------------------------
            if ((dut.Core_cpu.cpu_core.inst_i == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.ex_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == 32'h00008067) ||
                (dut.Core_cpu.cpu_core.bp_if_is_ret_like == 1'b1)) begin
                $display(
                    "RET_TRACE cyc=%0d pc_req=%08h fetch_pc=%08h inst_i=%08h bp_if_valid=%0d fire=%0d hold=%0d | ifid=(v=%0d rp=%0d cons=%0d pc=%08h inst=%08h pred=%0d raw=%0d tgt=%08h) | id=(pc=%08h inst=%08h rs1=%0d reg1=%08h op1=%08h base=%08h) | issue=(in_v=%0d v=%0d r=%0d f=%0d pc=%08h inst=%08h op1=%08h base=%08h emit1=%08h emitbase=%08h ireg1=%08h pred=%0d tgt=%08h) | idex=(pc=%08h inst=%08h op1=%08h base=%08h fop1=%08h fbase=%08h pred=%0d tgt=%08h kill=%0d) | ex=(inst=%08h jump=%0d/%08h rd=%0d wen=%0d data=%08h) | bp_ret=(is=%0d holdoff=%0d pending_x1=%0d take=%0d acc=%0d tgt=%08h pcjump=%0d/%08h) | x1=%08h x5=%08h sp=%08h | src idp=(rd=%0d wen=%0d data/base=%08h) idex=(rd=%0d wen=%0d) exm=(rd=%0d wen=%0d ld=%0d data=%08h) m1=(rd=%0d wen=%0d ld=%0d data=%08h) m12=(rd=%0d wen=%0d ld=%0d data=%08h) m2a=(rd=%0d wen=%0d ld=%0d data=%08h) m2=(rd=%0d wen=%0d data=%08h) mwb=(rd=%0d wen=%0d data=%08h) wb=(rd=%0d wen=%0d data=%08h) | hdu=(req=%0d can=%0d hflag=%0d fl=%0d)",
                    cycle_count,
                    dut.Core_cpu.cpu_core.pc_reg_pc_o,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.inst_i,
                    dut.Core_cpu.cpu_core.bp_if_valid,
                    dut.Core_cpu.cpu_core.ifetch_req_fire,
                    dut.Core_cpu.cpu_core.front_hold_o,
                    dut.Core_cpu.cpu_core.if_id_valid_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o,
                    dut.Core_cpu.cpu_core.if_id_consume_i,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_pred_taken_o,
                    dut.Core_cpu.cpu_core.if_id_raw_pred_taken_o,
                    dut.Core_cpu.cpu_core.if_id_pred_target_o,
                    dut.Core_cpu.cpu_core.id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_inst_o,
                    dut.Core_cpu.cpu_core.id_rs1_addr_o,
                    dut.Core_cpu.cpu_core.regs_reg1_rdata_o,
                    dut.Core_cpu.cpu_core.id_op1_o,
                    dut.Core_cpu.cpu_core.id_base_addr_o,
                    dut.Core_cpu.cpu_core.id_issue_valid_i,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_op1_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.issue_emit_op1_o,
                    dut.Core_cpu.cpu_core.issue_emit_base_addr_o,
                    dut.Core_cpu.cpu_core.issue_regs_rs1_rdata_o,
                    dut.Core_cpu.cpu_core.id_pipe_pred_taken_o,
                    dut.Core_cpu.cpu_core.id_pipe_pred_target_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_op1_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_pred_taken_o,
                    dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                    dut.Core_cpu.cpu_core.ctrl_kill_ex_o,
                    dut.Core_cpu.cpu_core.ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o,
                    dut.Core_cpu.cpu_core.ex_rd_addr_o,
                    dut.Core_cpu.cpu_core.ex_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_rd_data_o,
                    dut.Core_cpu.cpu_core.bp_if_is_ret_like,
                    dut.Core_cpu.cpu_core.bp_ret_holdoff,
                    dut.Core_cpu.cpu_core.pending_x1_write,
                    dut.Core_cpu.cpu_core.bp_pred_taken_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.bp_pred_target_o,
                    dut.Core_cpu.cpu_core.pc_jump_en_o,
                    dut.Core_cpu.cpu_core.pc_jump_addr_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[5],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.id_pipe_rd_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_reg_wen_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rd_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_reg_wen,
                    dut.Core_cpu.cpu_core.ex_mem_pipe_rd_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_mem_is_load_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_data_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_out_is_load_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_data_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_is_load_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_align_is_load_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_data_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.hdu_hold_req_o,
                    dut.Core_cpu.cpu_core.issue_can_go_ex_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o
                );
            end

            // A ret in EX must not use x1=0 unless the program really wrote x1=0.
            // This stops the log close to the first bad reason but does not finish.
            if (!seen_bad_ret_zero &&
                (dut.Core_cpu.cpu_core.id_ex_inst_o == 32'h00008067) &&
                (dut.Core_cpu.cpu_core.fwd_base_addr_o == 32'h00000000) &&
                (dut.Core_cpu.cpu_core.ctrl_kill_ex_o == 1'b0)) begin
                seen_bad_ret_zero <= 1'b1;
                $display("BAD_RET_ZERO cyc=%0d pc=%08h idex_base=%08h idex_op1=%08h fwd_base=%08h fwd_op1=%08h x1=%08h x5=%08h pending_x1=%0d pred=%0d tgt=%08h exjump=%0d/%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_op1_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[5],
                    dut.Core_cpu.cpu_core.pending_x1_write,
                    dut.Core_cpu.cpu_core.id_ex_pred_taken_o,
                    dut.Core_cpu.cpu_core.id_ex_pred_target_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o
                );
                dump_history();
            end

            // Ret prediction should not be accepted while x1 is still pending.
            if (!seen_bp_ret_pending_accept &&
                (dut.Core_cpu.cpu_core.bp_if_is_ret_like == 1'b1) &&
                (dut.Core_cpu.cpu_core.pending_x1_write == 1'b1) &&
                (dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o == 1'b1)) begin
                seen_bp_ret_pending_accept <= 1'b1;
                $display("BAD_BP_RET_ACCEPT_PENDING cyc=%0d fetch_pc=%08h inst_i=%08h x1=%08h pending_x1=%0d holdoff=%0d pred_tgt=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.inst_i,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.pending_x1_write,
                    dut.Core_cpu.cpu_core.bp_ret_holdoff,
                    dut.Core_cpu.cpu_core.bp_pred_target_o
                );
                dump_history();
            end
            if (dut.perip_wstrb != 4'b0000 &&
                (dut.perip_addr == 32'h0000044c ||
                 dut.perip_addr == 32'h00000448 ||
                 dut.perip_addr == 32'h00000450 ||
                 dut.perip_addr == 32'h00000420)) begin
                $display("STACK_WRITE cyc=%0d pc=%08h inst=%08h addr=%08h strb=%b data=%08h sp=%08h ra=%08h s0=%08h",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.perip_addr,
                    dut.perip_wstrb,
                    dut.perip_wdata,
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[8]
                );
            end
            if (dut.perip_rd_en &&
                (dut.perip_rd_addr >= 32'h00000400) &&
                (dut.perip_rd_addr <= 32'h00000480)) begin
                $display("STACK_READ cyc=%0d pc=%08h inst=%08h addr=%08h rdata=%08h sp=%08h ra=%08h s0=%08h",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.perip_rd_addr,
                    dut.perip_rdata,
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[8]
                );
            end
            // When any stage is producing x1/ra, print the producing path.
            if ((dut.Core_cpu.cpu_core.ex_rd_wen_o       && (dut.Core_cpu.cpu_core.ex_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.ex_mem_rd_wen_o   && (dut.Core_cpu.cpu_core.ex_mem_pipe_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.mem_out_rd_wen_o  && (dut.Core_cpu.cpu_core.mem_out_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.mem1_mem2_rd_wen_o && (dut.Core_cpu.cpu_core.mem1_mem2_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.mem2_align_rd_wen_o && (dut.Core_cpu.cpu_core.mem2_align_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.mem2_rd_wen_o     && (dut.Core_cpu.cpu_core.mem2_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.mem_wb_rd_wen_o   && (dut.Core_cpu.cpu_core.mem_wb_rd_addr_o == 5'd1)) ||
                (dut.Core_cpu.cpu_core.wb_rd_wen_o       && (dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd1))) begin
                $display("X1_PROD cyc=%0d x1=%08h ex=(%0d,%08h) exm=(%0d,%08h) m1=(%0d,%08h) m12=(%0d,%08h) m2a=(%0d,%08h) m2=(%0d,%08h) mwb=(%0d,%08h) wb=(%0d,%08h)",
                    cycle_count,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.ex_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_rd_data_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_data_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_out_rd_data_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_align_rd_data_o,
                    dut.Core_cpu.cpu_core.mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_data_o,
                    dut.Core_cpu.cpu_core.wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o
                );
            end

            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR) &&
                (dut.perip_wdata != 32'h0000_0000)) begin
                $display("FIRST_SEG_DEBUG_HIT cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                dump_history();
                if (dut.perip_wdata != FIRST_EXPECT) begin
                    $display("FIRST_SEG_DEBUG_FAIL expected=%08h actual=%08h", FIRST_EXPECT, dut.perip_wdata);
                end else begin
                    $display("FIRST_SEG_DEBUG_PASS");
                end
                $finish;
            end

            if (dut.pc < 32'h0000_0100) begin
                $display("FIRST_SEG_DEBUG_RUNAWAY cyc=%0d time=%0t pc=%08h inst=%08h", cycle_count, $time, dut.pc, dut.instruction);
                dump_history();
                $finish;
            end
        end
    end
endmodule
