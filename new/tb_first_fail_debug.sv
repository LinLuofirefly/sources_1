`timescale 1ns / 1ps

module tb_first_fail_debug;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer HISTORY_LEN     = 96;
    localparam [31:0] FAIL_COUNT_ADDR  = 32'h8010_0004;
    localparam [31:0] SAVE_RA_SP20_INST = 32'h00112e23;
    localparam [31:0] SAVE_RA_SP30_INST = 32'h02112623;
    localparam [31:0] LOAD_RA_SP20_INST = 32'h01c12083;
    localparam [31:0] LOAD_RA_SP30_INST = 32'h02c12083;
    localparam [31:0] ADDI_SP_P20_INST  = 32'h02010113;
    localparam [31:0] ADDI_SP_P30_INST  = 32'h03010113;
    localparam [31:0] ADDI_SP_M30_INST  = 32'hfd010113;
    localparam [31:0] SAVE_RA_SP30B_INST = 32'h02112623;
    localparam [31:0] SAVE_S0_SP30_INST  = 32'h02812423;
    localparam [31:0] ADDI_S0_SP30_INST  = 32'h03010413;
    localparam [31:0] RET_INST          = 32'h00008067;

    integer cycle_count;
    integer hist_wr_ptr;
    integer hist_count;
    integer j;
    integer slot;

    reg [31:0] hist_pc       [0:HISTORY_LEN-1];
    reg [31:0] hist_inst     [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid     [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid_addr [0:HISTORY_LEN-1];
    reg        hist_ifid_pred_taken [0:HISTORY_LEN-1];
    reg        hist_ifid_raw_pred_taken [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid_pred_target [0:HISTORY_LEN-1];
    reg [31:0] hist_issue_inst [0:HISTORY_LEN-1];
    reg [31:0] hist_issue_addr [0:HISTORY_LEN-1];
    reg        hist_issue_pred_taken [0:HISTORY_LEN-1];
    reg        hist_issue_raw_pred_taken [0:HISTORY_LEN-1];
    reg [31:0] hist_issue_pred_target [0:HISTORY_LEN-1];
    reg [31:0] hist_idex     [0:HISTORY_LEN-1];
    reg [31:0] hist_idex_addr [0:HISTORY_LEN-1];
    reg        hist_idex_pred_taken [0:HISTORY_LEN-1];
    reg        hist_idex_raw_pred_taken [0:HISTORY_LEN-1];
    reg [31:0] hist_idex_pred_target [0:HISTORY_LEN-1];
    reg [31:0] hist_exmem    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem1     [0:HISTORY_LEN-1];
    reg [31:0] hist_mem12    [0:HISTORY_LEN-1];
    reg [31:0] hist_m2a      [0:HISTORY_LEN-1];
    reg [31:0] hist_m2       [0:HISTORY_LEN-1];
    reg        hist_hold     [0:HISTORY_LEN-1];
    reg        hist_hflush   [0:HISTORY_LEN-1];
    reg        hist_issue_valid [0:HISTORY_LEN-1];
    reg        hist_issue_ready [0:HISTORY_LEN-1];
    reg        hist_issue_fire  [0:HISTORY_LEN-1];
    reg [31:0] hist_f1       [0:HISTORY_LEN-1];
    reg [31:0] hist_f2       [0:HISTORY_LEN-1];
    reg [31:0] hist_x10      [0:HISTORY_LEN-1];
    reg [31:0] hist_x11      [0:HISTORY_LEN-1];
    reg [31:0] hist_x12      [0:HISTORY_LEN-1];
    reg [31:0] hist_x13      [0:HISTORY_LEN-1];
    reg [31:0] hist_x14      [0:HISTORY_LEN-1];
    reg [31:0] hist_x15      [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_addr  [0:HISTORY_LEN-1];
    reg [3:0]  hist_wr_strb  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_data  [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_addr  [0:HISTORY_LEN-1];
    reg        hist_rd_req   [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_data  [0:HISTORY_LEN-1];
    reg [4:0]  hist_wb_rd_addr [0:HISTORY_LEN-1];
    reg        hist_wb_rd_wen  [0:HISTORY_LEN-1];
    reg [31:0] hist_wb_rd_data [0:HISTORY_LEN-1];
    reg        hist_bp_pred_taken [0:HISTORY_LEN-1];
    reg [31:0] hist_bp_pred_target [0:HISTORY_LEN-1];
    reg        hist_bp_pred_accept [0:HISTORY_LEN-1];
    reg        hist_ctrl_jump [0:HISTORY_LEN-1];
    reg [31:0] hist_ctrl_jump_addr [0:HISTORY_LEN-1];

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
            $display("FIRST_FAIL_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "FAILDBG cyc=%0d pc=%08h inst=%08h ifid=(%08h@%08h pt=%0d rt=%0d tgt=%08h) issue=(%08h@%08h pt=%0d rt=%0d tgt=%08h v=%0d r=%0d f=%0d) idex=(%08h@%08h pt=%0d rt=%0d tgt=%08h) exmem=%08h mem1=%08h mem12=%08h m2a=%08h m2=%08h | bp=(%0d,%0d,%08h) ctrlj=(%0d,%08h) hold=%0d hfl=%0d | f1=%08h f2=%08h | wb=(%0d,%0d,%08h) | x10=%08h x11=%08h x12=%08h x13=%08h x14=%08h x15=%08h | rd=(%0d,%08h,%08h) wr=(%b,%08h,%08h)",
                    start_idx + j,
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_ifid_addr[slot],
                    hist_ifid_pred_taken[slot],
                    hist_ifid_raw_pred_taken[slot],
                    hist_ifid_pred_target[slot],
                    hist_issue_inst[slot],
                    hist_issue_addr[slot],
                    hist_issue_pred_taken[slot],
                    hist_issue_raw_pred_taken[slot],
                    hist_issue_pred_target[slot],
                    hist_issue_valid[slot],
                    hist_issue_ready[slot],
                    hist_issue_fire[slot],
                    hist_idex[slot],
                    hist_idex_addr[slot],
                    hist_idex_pred_taken[slot],
                    hist_idex_raw_pred_taken[slot],
                    hist_idex_pred_target[slot],
                    hist_exmem[slot],
                    hist_mem1[slot],
                    hist_mem12[slot],
                    hist_m2a[slot],
                    hist_m2[slot],
                    hist_bp_pred_taken[slot],
                    hist_bp_pred_accept[slot],
                    hist_bp_pred_target[slot],
                    hist_ctrl_jump[slot],
                    hist_ctrl_jump_addr[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_f1[slot],
                    hist_f2[slot],
                    hist_wb_rd_wen[slot],
                    hist_wb_rd_addr[slot],
                    hist_wb_rd_data[slot],
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
                    hist_wr_data[slot]
                );
            end
            $display("FIRST_FAIL_HISTORY_END");
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        hist_wr_ptr = 0;
        hist_count  = 0;

        #20;
        w_clk_rst = 1'b0;

        repeat (10000) @(posedge w_cpu_clk);
        $display("FIRST_FAIL_TIMEOUT pc=%08h inst=%08h", dut.pc, dut.instruction);
        dump_history();
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            hist_pc[hist_wr_ptr]      <= dut.pc;
            hist_inst[hist_wr_ptr]    <= dut.instruction;
            hist_ifid[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.if_id_inst_o;
            hist_ifid_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_inst_addr_o;
            hist_ifid_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_pred_taken_o;
            hist_ifid_raw_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_raw_pred_taken_o;
            hist_ifid_pred_target[hist_wr_ptr] <= dut.Core_cpu.cpu_core.if_id_pred_target_o;
            hist_issue_inst[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_inst_o;
            hist_issue_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_inst_addr_o;
            hist_issue_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_pred_taken_o;
            hist_issue_raw_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_raw_pred_taken_o;
            hist_issue_pred_target[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_pipe_pred_target_o;
            hist_idex[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.id_ex_inst_o;
            hist_idex_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_ex_inst_addr_o;
            hist_idex_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_ex_pred_taken_o;
            hist_idex_raw_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_ex_raw_pred_taken_o;
            hist_idex_pred_target[hist_wr_ptr] <= dut.Core_cpu.cpu_core.id_ex_pred_target_o;
            hist_exmem[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_mem1[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.mem_inst_o;
            hist_mem12[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            hist_m2a[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_m2[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_hold[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_issue_valid[hist_wr_ptr] <= dut.Core_cpu.cpu_core.issue_valid_o;
            hist_issue_ready[hist_wr_ptr] <= dut.Core_cpu.cpu_core.issue_ready_o;
            hist_issue_fire[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.issue_fire_o;
            hist_f1[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_f2[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_wb_rd_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.wb_rd_addr_o;
            hist_wb_rd_wen[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.wb_rd_wen_o;
            hist_wb_rd_data[hist_wr_ptr] <= dut.Core_cpu.cpu_core.wb_rd_data_o;
            hist_bp_pred_taken[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_pred_taken_o;
            hist_bp_pred_target[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_pred_target_o;
            hist_bp_pred_accept[hist_wr_ptr] <= dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o;
            hist_ctrl_jump[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_jump_en_o;
            hist_ctrl_jump_addr[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_jump_addr_o;
            hist_x10[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x11[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[11];
            hist_x12[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[12];
            hist_x13[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[13];
            hist_x14[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_wr_addr[hist_wr_ptr] <= dut.perip_addr;
            hist_wr_strb[hist_wr_ptr] <= dut.perip_wstrb;
            hist_wr_data[hist_wr_ptr] <= dut.perip_wdata;
            hist_rd_addr[hist_wr_ptr] <= dut.perip_rd_addr;
            hist_rd_req[hist_wr_ptr]  <= dut.perip_rd_en;
            hist_rd_data[hist_wr_ptr] <= dut.perip_rdata;

            if (hist_count < HISTORY_LEN) begin
                hist_count <= hist_count + 1;
            end
            hist_wr_ptr <= (hist_wr_ptr + 1) % HISTORY_LEN;

            if (dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                ((dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd10) ||
                 (dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd1))) begin
                $display(
                    "WBTRACE cyc=%0d pc=%08h inst=%08h wb=(%0d,%08h) x10=%08h x1=%08h issue=(%0d,%0d,%0d) hold=%0d hfl=%0d jump=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[10],
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o
                );
            end

            if (((dut.Core_cpu.cpu_core.mem_inst_o == SAVE_RA_SP20_INST) ||
                 (dut.Core_cpu.cpu_core.mem_inst_o == SAVE_RA_SP30_INST)) &&
                (dut.perip_wstrb != 4'b0000)) begin
                $display(
                    "SAVE_RA_TRACE cyc=%0d pc=%08h issue=%08h idex=%08h exmem=%08h mem1=%08h waddr=%08h wdata=%08h x1=%08h x2=%08h",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.perip_addr,
                    dut.perip_wdata,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2]
                );
            end

            if ((dut.Core_cpu.cpu_core.if_id_inst_o == SAVE_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == SAVE_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == SAVE_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == SAVE_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == SAVE_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == SAVE_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == SAVE_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == SAVE_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == SAVE_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == SAVE_RA_SP30_INST)) begin
                $display(
                    "SAVE_RA_FLOW cyc=%0d pc=%08h ifid=%08h issue=(%08h v=%0d r=%0d f=%0d) idex=%08h exmem=%08h mem1=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d bpacc=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if ((cycle_count > 1200) &&
                (dut.pc >= 32'h8000_0104) &&
                (dut.pc <= 32'h8000_0120)) begin
                $display(
                    "FUNC0104_FLOW cyc=%0d pc=%08h ifid=(%08h@%08h) issue=(%08h@%08h v=%0d r=%0d f=%0d) idex=(%08h@%08h) exmem=%08h mem1=%08h x1=%08h x2=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d bpacc=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if ((cycle_count >= 995) &&
                (cycle_count <= 1015) &&
                (dut.pc >= 32'h8000_00fc) &&
                (dut.pc <= 32'h8000_0120)) begin
                $display(
                    "ENTRY_TRACE cyc=%0d pc=%08h fetch=(pc=%08h v=%0d pv=%0d inst=%08h) ifid=(%08h@%08h pt=%0d tgt=%08h) issue=(%08h@%08h v=%0d r=%0d f=%0d base=%08h) idex=(%08h@%08h base=%08h) exmem=%08h mem1=%08h mem2=%08h memwb=%08h wb=(%0d,%08h) x1=%08h x2=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d ctrlj=%08h bpacc=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.bp_fetch_valid_r,
                    dut.Core_cpu.cpu_core.bp_fetch_valid_pending_r,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_pred_taken_o,
                    dut.Core_cpu.cpu_core.if_id_pred_target_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_addr_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if ((dut.Core_cpu.cpu_core.mem2_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == LOAD_RA_SP30_INST)) begin
                $display(
                    "LOAD_RA_TRACE cyc=%0d pc=%08h ifid=(%08h@%08h) issue=(%08h@%08h base=%08h) idex=(%08h@%08h base=%08h) fwd_base=%08h m2a_addr=%08h m2=%08h rd_addr=%0d rd_data=%08h x1=%08h x2=%08h",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.mem2_align_mem_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2]
                );
            end

            if ((dut.Core_cpu.cpu_core.if_id_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == ADDI_SP_P20_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == ADDI_SP_P30_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == RET_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == RET_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == RET_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == RET_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == RET_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == RET_INST)) begin
                $display(
                    "SP_RET_FLOW cyc=%0d pc=%08h ifid=(%08h@%08h) issue=(%08h@%08h base=%08h v=%0d r=%0d f=%0d) idex=(%08h@%08h base=%08h) exmem=%08h mem1=%08h mem2=%08h wb=(%0d,%08h) x1=%08h x2=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d bpacc=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if ((dut.Core_cpu.cpu_core.if_id_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == LOAD_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == LOAD_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == LOAD_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == LOAD_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == LOAD_RA_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == LOAD_RA_SP20_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == LOAD_RA_SP30_INST)) begin
                $display(
                    "LOAD_RA_FLOW cyc=%0d pc=%08h ifid=(%08h@%08h) issue=(%08h@%08h base=%08h v=%0d r=%0d f=%0d) idex=(%08h@%08h base=%08h) fwd_base=%08h exmem=%08h mem1=%08h m2a_addr=%08h m2=%08h x1=%08h x2=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem2_align_mem_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if ((dut.Core_cpu.cpu_core.if_id_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.if_id_inst_o == ADDI_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_pipe_inst_o == ADDI_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.id_ex_inst_o == ADDI_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.ex_mem_inst_o == ADDI_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem_inst_o == ADDI_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == ADDI_SP_M30_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == SAVE_RA_SP30B_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == SAVE_S0_SP30_INST) ||
                (dut.Core_cpu.cpu_core.mem2_inst_o == ADDI_S0_SP30_INST)) begin
                $display(
                    "PROLOGUE30_FLOW cyc=%0d pc=%08h fetch=(pc=%08h v=%0d pv=%0d inst=%08h) ifid=(%08h@%08h pt=%0d tgt=%08h) issue=(%08h@%08h v=%0d r=%0d f=%0d pt=%0d tgt=%08h base=%08h) idex=(%08h@%08h base=%08h) exmem=%08h mem1=%08h mem2=%08h memwb=%08h wb=(%0d,%08h) x1=%08h x2=%08h hold=%0d hfl=%0d flush_ifid=%0d flush_idpipe=%0d flush_idex=%0d jump=%0d ctrlj=%08h bpacc=%0d replay=%0d",
                    cycle_count,
                    dut.pc,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.Core_cpu.cpu_core.bp_fetch_valid_r,
                    dut.Core_cpu.cpu_core.bp_fetch_valid_pending_r,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_pred_taken_o,
                    dut.Core_cpu.cpu_core.if_id_pred_target_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.issue_valid_o,
                    dut.Core_cpu.cpu_core.issue_ready_o,
                    dut.Core_cpu.cpu_core.issue_fire_o,
                    dut.Core_cpu.cpu_core.id_pipe_pred_taken_o,
                    dut.Core_cpu.cpu_core.id_pipe_pred_target_o,
                    dut.Core_cpu.cpu_core.id_pipe_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[1],
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idpipe_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_addr_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.if_id_replaying_o
                );
            end

            if (dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                (dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd2)) begin
                $display(
                    "WB_SP_TRACE cyc=%0d pc=%08h inst=%08h memwb=%08h wb_sp=%08h x2_now=%08h ifid=(%08h@%08h) issue=(%08h@%08h) idex=(%08h@%08h) exmem=%08h mem1=%08h",
                    cycle_count,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[2],
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_o,
                    dut.Core_cpu.cpu_core.id_pipe_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem_inst_o
                );
            end

            if ((cycle_count > 1000) &&
                dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                (dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd1) &&
                (dut.Core_cpu.cpu_core.wb_rd_data_o == 32'b0)) begin
                $display("FIRST_RA_ZERO_HIT cyc=%0d time=%0t pc=%08h inst=%08h",
                         cycle_count, $time, dut.pc, dut.instruction);
                dump_history();
                $finish;
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == FAIL_COUNT_ADDR)) begin
                $display("FIRST_FAIL_HIT cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                dump_history();
                $finish;
            end
        end
    end
endmodule
