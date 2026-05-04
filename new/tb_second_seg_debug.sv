`timescale 1ns / 1ps

module tb_second_seg_debug;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam time MAX_SIM_TIME_NS = 30_000_000_000;
    localparam integer HISTORY_LEN = 400;
    localparam integer FUNC_HIST_LEN = 512;
    localparam integer LOOP_MAX_PERIOD = 16;
    // Keep this low enough to trip within a practical debug run while still
    // requiring a long repeated state pattern rather than a transient stall.
    localparam integer LOOP_REPEAT_LIMIT = 512;

    integer cycle_count;
    integer seg_write_count;
    integer hist_wr_ptr;
    integer hist_count;
    integer i;
    integer j;
    integer p;
    integer slot;
    integer func_wr_ptr;
    integer func_count;
    integer loop_hist_wr_ptr;
    integer loop_match_streak [1:LOOP_MAX_PERIOD];
    reg [31:0] loop_sig_hist [0:LOOP_MAX_PERIOD-1];
    reg [31:0] loop_sig_now;

    integer      hist_cycle   [0:HISTORY_LEN-1];
    time         hist_time    [0:HISTORY_LEN-1];
    reg [31:0]   hist_pc      [0:HISTORY_LEN-1];
    reg [31:0]   hist_inst    [0:HISTORY_LEN-1];
    reg [31:0]   hist_ifid    [0:HISTORY_LEN-1];
    reg [31:0]   hist_issue   [0:HISTORY_LEN-1];
    reg [31:0]   hist_idex    [0:HISTORY_LEN-1];
    reg [31:0]   hist_exmem   [0:HISTORY_LEN-1];
    reg [31:0]   hist_mem12   [0:HISTORY_LEN-1];
    reg [31:0]   hist_m2a     [0:HISTORY_LEN-1];
    reg [31:0]   hist_m2      [0:HISTORY_LEN-1];
    reg          hist_ifid_valid [0:HISTORY_LEN-1];
    reg          hist_issue_in_valid [0:HISTORY_LEN-1];
    reg          hist_issue_ready [0:HISTORY_LEN-1];
    reg          hist_issue_fire [0:HISTORY_LEN-1];
    reg          hist_bp_taken_acc [0:HISTORY_LEN-1];
    reg          hist_hold    [0:HISTORY_LEN-1];
    reg          hist_hflush  [0:HISTORY_LEN-1];
    reg          hist_ifflush [0:HISTORY_LEN-1];
    reg          hist_idflush [0:HISTORY_LEN-1];
    reg [4:0]    hist_wbaddr  [0:HISTORY_LEN-1];
    reg          hist_wbwen   [0:HISTORY_LEN-1];
    reg [31:0]   hist_wbdata  [0:HISTORY_LEN-1];
    reg [31:0]   hist_x1      [0:HISTORY_LEN-1];
    reg [31:0]   hist_x2      [0:HISTORY_LEN-1];
    reg [31:0]   hist_x8      [0:HISTORY_LEN-1];
    reg [31:0]   hist_x10     [0:HISTORY_LEN-1];
    reg [31:0]   hist_x11     [0:HISTORY_LEN-1];
    reg [31:0]   hist_x12     [0:HISTORY_LEN-1];
    reg [31:0]   hist_x13     [0:HISTORY_LEN-1];
    reg [31:0]   hist_x14     [0:HISTORY_LEN-1];
    reg [31:0]   hist_x15     [0:HISTORY_LEN-1];
    reg [31:0]   hist_wr_addr [0:HISTORY_LEN-1];
    reg [3:0]    hist_wr_strb [0:HISTORY_LEN-1];
    reg [31:0]   hist_wr_data [0:HISTORY_LEN-1];

    integer      func_kind    [0:FUNC_HIST_LEN-1];
    integer      func_cycle   [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_pc      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_inst    [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_a0      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_a1      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_a3      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_a4      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_a5      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_s0      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_sp      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_ra      [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_slot_in [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_slot_acc[0:FUNC_HIST_LEN-1];
    reg [31:0]   func_slot_sh [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_slot_dig[0:FUNC_HIST_LEN-1];
    reg [31:0]   func_evt_addr[0:FUNC_HIST_LEN-1];
    reg [31:0]   func_evt_data[0:FUNC_HIST_LEN-1];
    reg [31:0]   func_ifid    [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_issue   [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_idex    [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_exmem   [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_m12     [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_m2a     [0:FUNC_HIST_LEN-1];
    reg [31:0]   func_m2      [0:FUNC_HIST_LEN-1];
    reg          func_ifid_valid [0:FUNC_HIST_LEN-1];
    reg          func_issue_in_valid [0:FUNC_HIST_LEN-1];
    reg          func_issue_ready [0:FUNC_HIST_LEN-1];
    reg          func_issue_fire [0:FUNC_HIST_LEN-1];
    reg          func_bp_taken_acc [0:FUNC_HIST_LEN-1];

    task automatic push_func_hist;
        input integer kind_i;
        input [31:0] evt_addr_i;
        input [31:0] evt_data_i;
        begin
            func_kind[func_wr_ptr]     = kind_i;
            func_cycle[func_wr_ptr]    = cycle_count;
            func_pc[func_wr_ptr]       = dut.pc;
            func_inst[func_wr_ptr]     = dut.instruction;
            func_a0[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[10];
            func_a1[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[11];
            func_a3[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[13];
            func_a4[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[14];
            func_a5[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[15];
            func_s0[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[8];
            func_sp[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[2];
            func_ra[func_wr_ptr]       = dut.Core_cpu.cpu_core.regs_inst.regs[1];
            func_slot_in[func_wr_ptr]  = dut.Core_cpu.cpu_core.regs_inst.regs[8] - 32'h24;
            func_slot_acc[func_wr_ptr] = dut.Core_cpu.cpu_core.regs_inst.regs[8] - 32'h14;
            func_slot_sh[func_wr_ptr]  = dut.Core_cpu.cpu_core.regs_inst.regs[8] - 32'h18;
            func_slot_dig[func_wr_ptr] = dut.Core_cpu.cpu_core.regs_inst.regs[8] - 32'h1c;
            func_evt_addr[func_wr_ptr] = evt_addr_i;
            func_evt_data[func_wr_ptr] = evt_data_i;
            func_ifid[func_wr_ptr]     = dut.Core_cpu.cpu_core.if_id_inst_o;
            func_issue[func_wr_ptr]    = dut.Core_cpu.cpu_core.id_pipe_inst_o;
            func_idex[func_wr_ptr]     = dut.Core_cpu.cpu_core.id_ex_inst_o;
            func_exmem[func_wr_ptr]    = dut.Core_cpu.cpu_core.ex_mem_inst_o;
            func_m12[func_wr_ptr]      = dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            func_m2a[func_wr_ptr]      = dut.Core_cpu.cpu_core.mem2_align_inst_o;
            func_m2[func_wr_ptr]       = dut.Core_cpu.cpu_core.mem2_inst_o;
            func_ifid_valid[func_wr_ptr] = dut.Core_cpu.cpu_core.id_issue_valid_i;
            func_issue_in_valid[func_wr_ptr] = dut.Core_cpu.cpu_core.id_issue_valid_i;
            func_issue_ready[func_wr_ptr] = dut.Core_cpu.cpu_core.issue_ready_o;
            func_issue_fire[func_wr_ptr] = dut.Core_cpu.cpu_core.issue_fire_o;
            func_bp_taken_acc[func_wr_ptr] = dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o;
            func_wr_ptr = (func_wr_ptr + 1) % FUNC_HIST_LEN;
            if (func_count < FUNC_HIST_LEN) begin
                func_count = func_count + 1;
            end
        end
    endtask

    task automatic dump_func_history;
        integer start_idx;
        integer k;
        integer kind_slot;
        begin
            $display("FUNC70_SEG2_HISTORY_BEGIN count=%0d", func_count);
            start_idx = (func_count == FUNC_HIST_LEN) ? func_wr_ptr : 0;
            for (k = 0; k < func_count; k = k + 1) begin
                slot = (start_idx + k) % FUNC_HIST_LEN;
                kind_slot = func_kind[slot];
                $display(
                    "FSEG kind=%0d cyc=%0d pc=%08h inst=%08h evt=(%08h,%08h) | a0=%08h a1=%08h a3=%08h a4=%08h a5=%08h s0=%08h sp=%08h ra=%08h | slots in=%08h acc=%08h sh=%08h dig=%08h | ifid=%08h issue=%08h idex=%08h exmem=%08h m12=%08h m2a=%08h m2=%08h | ifv=%0d in_v=%0d ready=%0d fire=%0d bpacc=%0d",
                    kind_slot,
                    func_cycle[slot],
                    func_pc[slot],
                    func_inst[slot],
                    func_evt_addr[slot],
                    func_evt_data[slot],
                    func_a0[slot],
                    func_a1[slot],
                    func_a3[slot],
                    func_a4[slot],
                    func_a5[slot],
                    func_s0[slot],
                    func_sp[slot],
                    func_ra[slot],
                    func_slot_in[slot],
                    func_slot_acc[slot],
                    func_slot_sh[slot],
                    func_slot_dig[slot],
                    func_ifid[slot],
                    func_issue[slot],
                    func_idex[slot],
                    func_exmem[slot],
                    func_m12[slot],
                    func_m2a[slot],
                    func_m2[slot],
                    func_ifid_valid[slot],
                    func_issue_in_valid[slot],
                    func_issue_ready[slot],
                    func_issue_fire[slot],
                    func_bp_taken_acc[slot]
                );
            end
            $display("FUNC70_SEG2_HISTORY_END");
        end
    endtask

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
            $display("SECOND_SEG_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "SSEG cyc=%0d time=%0t pc=%08h inst=%08h | ifid=%08h issue=%08h idex=%08h exmem=%08h m12=%08h m2a=%08h m2=%08h | hold=%0d hfl=%0d iffl=%0d idfl=%0d | wb=(%0d,%0d,%08h) | x1=%08h x2=%08h x8=%08h x10=%08h x11=%08h x12=%08h x13=%08h x14=%08h x15=%08h | wr=(%08h,%b,%08h)",
                    hist_cycle[slot],
                    hist_time[slot],
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_issue[slot],
                    hist_idex[slot],
                    hist_exmem[slot],
                    hist_mem12[slot],
                    hist_m2a[slot],
                    hist_m2[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_ifflush[slot],
                    hist_idflush[slot],
                    hist_wbwen[slot],
                    hist_wbaddr[slot],
                    hist_wbdata[slot],
                    hist_x1[slot],
                    hist_x2[slot],
                    hist_x8[slot],
                    hist_x10[slot],
                    hist_x11[slot],
                    hist_x12[slot],
                    hist_x13[slot],
                    hist_x14[slot],
                    hist_x15[slot],
                    hist_wr_addr[slot],
                    hist_wr_strb[slot],
                    hist_wr_data[slot]
                );
            end
            $display("SECOND_SEG_HISTORY_END");
        end
    endtask

    task automatic finish_deadloop;
        input integer period_i;
        begin
            $display("SECOND_SEG_DEADLOOP period=%0d repeat=%0d cyc=%0d pc=%08h inst=%08h seg_writes=%0d seg=%08h led=%08h sig=%08h",
                     period_i, LOOP_REPEAT_LIMIT, cycle_count, dut.pc, dut.instruction,
                     seg_write_count, dut.bridge_inst.seg_wdata, virtual_led, loop_sig_now);
            dump_func_history();
            dump_history();
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        seg_write_count = 0;
        hist_wr_ptr = 0;
        hist_count  = 0;
        func_wr_ptr = 0;
        func_count  = 0;
        loop_hist_wr_ptr = 0;
        loop_sig_now = 32'b0;

        for (i = 0; i < HISTORY_LEN; i = i + 1) begin
            hist_cycle[i]   = 0;
            hist_time[i]    = 0;
            hist_pc[i]      = 32'b0;
            hist_inst[i]    = 32'b0;
            hist_ifid[i]    = 32'b0;
            hist_issue[i]   = 32'b0;
            hist_idex[i]    = 32'b0;
            hist_exmem[i]   = 32'b0;
            hist_mem12[i]   = 32'b0;
            hist_m2a[i]     = 32'b0;
            hist_m2[i]      = 32'b0;
            hist_ifid_valid[i] = 1'b0;
            hist_issue_in_valid[i] = 1'b0;
            hist_issue_ready[i] = 1'b0;
            hist_issue_fire[i] = 1'b0;
            hist_bp_taken_acc[i] = 1'b0;
            hist_hold[i]    = 1'b0;
            hist_hflush[i]  = 1'b0;
            hist_ifflush[i] = 1'b0;
            hist_idflush[i] = 1'b0;
            hist_wbaddr[i]  = 5'b0;
            hist_wbwen[i]   = 1'b0;
            hist_wbdata[i]  = 32'b0;
            hist_x1[i]      = 32'b0;
            hist_x2[i]      = 32'b0;
            hist_x8[i]      = 32'b0;
            hist_x10[i]     = 32'b0;
            hist_x11[i]     = 32'b0;
            hist_x12[i]     = 32'b0;
            hist_x13[i]     = 32'b0;
            hist_x14[i]     = 32'b0;
            hist_x15[i]     = 32'b0;
            hist_wr_addr[i] = 32'b0;
            hist_wr_strb[i] = 4'b0;
            hist_wr_data[i] = 32'b0;
        end

        for (i = 0; i < FUNC_HIST_LEN; i = i + 1) begin
            func_kind[i]     = 0;
            func_cycle[i]    = 0;
            func_pc[i]       = 32'b0;
            func_inst[i]     = 32'b0;
            func_a0[i]       = 32'b0;
            func_a1[i]       = 32'b0;
            func_a3[i]       = 32'b0;
            func_a4[i]       = 32'b0;
            func_a5[i]       = 32'b0;
            func_s0[i]       = 32'b0;
            func_sp[i]       = 32'b0;
            func_ra[i]       = 32'b0;
            func_slot_in[i]  = 32'b0;
            func_slot_acc[i] = 32'b0;
            func_slot_sh[i]  = 32'b0;
            func_slot_dig[i] = 32'b0;
            func_evt_addr[i] = 32'b0;
            func_evt_data[i] = 32'b0;
            func_ifid[i]     = 32'b0;
            func_issue[i]    = 32'b0;
            func_idex[i]     = 32'b0;
            func_exmem[i]    = 32'b0;
            func_m12[i]      = 32'b0;
            func_m2a[i]      = 32'b0;
            func_m2[i]       = 32'b0;
            func_ifid_valid[i] = 1'b0;
            func_issue_in_valid[i] = 1'b0;
            func_issue_ready[i] = 1'b0;
            func_issue_fire[i] = 1'b0;
            func_bp_taken_acc[i] = 1'b0;
        end

        for (i = 0; i < LOOP_MAX_PERIOD; i = i + 1) begin
            loop_sig_hist[i] = 32'b0;
        end
        for (i = 1; i <= LOOP_MAX_PERIOD; i = i + 1) begin
            loop_match_streak[i] = 0;
        end

        #20;
        w_clk_rst = 1'b0;

        #MAX_SIM_TIME_NS;
        $display("SECOND_SEG_TIMEOUT cyc=%0d pc=%08h inst=%08h seg_writes=%0d seg=%08h led=%08h",
                 cycle_count, dut.pc, dut.instruction, seg_write_count,
                 dut.bridge_inst.seg_wdata, virtual_led);
        dump_history();
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        reg [31:0] s0_now;
        reg [31:0] slot_in;
        reg [31:0] slot_acc;
        reg [31:0] slot_shift;
        reg [31:0] slot_digit;
        integer hist_idx;
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;
            s0_now      = dut.Core_cpu.cpu_core.regs_inst.regs[8];
            slot_in     = s0_now - 32'h24;
            slot_acc    = s0_now - 32'h14;
            slot_shift  = s0_now - 32'h18;
            slot_digit  = s0_now - 32'h1c;

            hist_cycle[hist_wr_ptr]   = cycle_count;
            hist_time[hist_wr_ptr]    = $time;
            hist_pc[hist_wr_ptr]      = dut.pc;
            hist_inst[hist_wr_ptr]    = dut.instruction;
            hist_ifid[hist_wr_ptr]    = dut.Core_cpu.cpu_core.if_id_inst_o;
            hist_issue[hist_wr_ptr]   = dut.Core_cpu.cpu_core.id_pipe_inst_o;
            hist_idex[hist_wr_ptr]    = dut.Core_cpu.cpu_core.id_ex_inst_o;
            hist_exmem[hist_wr_ptr]   = dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_mem12[hist_wr_ptr]   = dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            hist_m2a[hist_wr_ptr]     = dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_m2[hist_wr_ptr]      = dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_ifid_valid[hist_wr_ptr] = dut.Core_cpu.cpu_core.id_issue_valid_i;
            hist_issue_in_valid[hist_wr_ptr] = dut.Core_cpu.cpu_core.id_issue_valid_i;
            hist_issue_ready[hist_wr_ptr] = dut.Core_cpu.cpu_core.issue_ready_o;
            hist_issue_fire[hist_wr_ptr] = dut.Core_cpu.cpu_core.issue_fire_o;
            hist_bp_taken_acc[hist_wr_ptr] = dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o;
            hist_hold[hist_wr_ptr]    = dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[hist_wr_ptr]  = dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_ifflush[hist_wr_ptr] = dut.Core_cpu.cpu_core.ctrl_flush_ifid_o;
            hist_idflush[hist_wr_ptr] = dut.Core_cpu.cpu_core.ctrl_flush_idex_o;
            hist_wbaddr[hist_wr_ptr]  = dut.Core_cpu.cpu_core.wb_rd_addr_o;
            hist_wbwen[hist_wr_ptr]   = dut.Core_cpu.cpu_core.wb_rd_wen_o;
            hist_wbdata[hist_wr_ptr]  = dut.Core_cpu.cpu_core.wb_rd_data_o;
            hist_x1[hist_wr_ptr]      = dut.Core_cpu.cpu_core.regs_inst.regs[1];
            hist_x2[hist_wr_ptr]      = dut.Core_cpu.cpu_core.regs_inst.regs[2];
            hist_x8[hist_wr_ptr]      = dut.Core_cpu.cpu_core.regs_inst.regs[8];
            hist_x10[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x11[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[11];
            hist_x12[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[12];
            hist_x13[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[13];
            hist_x14[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[hist_wr_ptr]     = dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_wr_addr[hist_wr_ptr] = dut.perip_addr;
            hist_wr_strb[hist_wr_ptr] = dut.perip_wstrb;
            hist_wr_data[hist_wr_ptr] = dut.perip_wdata;

            hist_wr_ptr = (hist_wr_ptr + 1) % HISTORY_LEN;
            if (hist_count < HISTORY_LEN) begin
                hist_count = hist_count + 1;
            end

            loop_sig_now = dut.pc ^
                           dut.instruction ^
                           dut.Core_cpu.cpu_core.if_id_inst_o ^
                           dut.Core_cpu.cpu_core.id_pipe_inst_o ^
                           dut.Core_cpu.cpu_core.id_ex_inst_o ^
                           dut.Core_cpu.cpu_core.ex_mem_inst_o ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[1] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[2] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[8] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[10] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[11] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[12] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[13] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[14] ^
                           dut.Core_cpu.cpu_core.regs_inst.regs[15] ^
                           {31'b0, dut.Core_cpu.cpu_core.issue_fire_o} ^
                           {31'b0, dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o} ^
                           {24'b0, dut.perip_wstrb, 3'b0, seg_write_count[0]};

            if (seg_write_count >= 1) begin
                for (p = 1; p <= LOOP_MAX_PERIOD; p = p + 1) begin
                    if (cycle_count > p) begin
                        hist_idx = loop_hist_wr_ptr - p;
                        if (hist_idx < 0) begin
                            hist_idx = hist_idx + LOOP_MAX_PERIOD;
                        end
                        if (loop_sig_now == loop_sig_hist[hist_idx]) begin
                            loop_match_streak[p] = loop_match_streak[p] + 1;
                            if (loop_match_streak[p] >= LOOP_REPEAT_LIMIT) begin
                                finish_deadloop(p);
                            end
                        end else begin
                            loop_match_streak[p] = 0;
                        end
                    end else begin
                        loop_match_streak[p] = 0;
                    end
                end
            end else begin
                for (p = 1; p <= LOOP_MAX_PERIOD; p = p + 1) begin
                    loop_match_streak[p] = 0;
                end
            end

            loop_sig_hist[loop_hist_wr_ptr] = loop_sig_now;
            loop_hist_wr_ptr = (loop_hist_wr_ptr + 1) % LOOP_MAX_PERIOD;

            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR) &&
                (dut.perip_wdata != 32'h0000_0000)) begin
                seg_write_count = seg_write_count + 1;
                $display("SECOND_SEG_OBS #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         seg_write_count, cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                if (seg_write_count == 2) begin
                    dump_func_history();
                    dump_history();
                    $finish;
                end
            end

            if (seg_write_count >= 1) begin
                if ((dut.pc >= 32'h8000_0150) && (dut.pc <= 32'h8000_019c)) begin
                    push_func_hist(1, 32'b0, 32'b0);
                end

                if ((dut.pc >= 32'h8000_0070) && (dut.pc <= 32'h8000_0100)) begin
                    push_func_hist(2, 32'b0, 32'b0);
                end

                if ((dut.pc == 32'h8000_1ea8) || (dut.pc == 32'h8000_1e30)) begin
                    push_func_hist(3, 32'b0, 32'b0);
                end

                if ((dut.pc >= 32'h8000_1ef4) && (dut.pc <= 32'h8000_1f40)) begin
                    push_func_hist(6, 32'b0, 32'b0);
                end

                if (((dut.pc >= 32'h8000_0070) && (dut.pc <= 32'h8000_0100) ||
                     (dut.pc >= 32'h8000_1e30) && (dut.pc <= 32'h8000_1f30)) &&
                    dut.perip_rd_en &&
                    ((dut.perip_rd_addr == slot_in) ||
                     (dut.perip_rd_addr == slot_acc) ||
                     (dut.perip_rd_addr == slot_shift) ||
                     (dut.perip_rd_addr == slot_digit))) begin
                    push_func_hist(4, dut.perip_rd_addr, dut.perip_rdata);
                end

                if (((dut.pc >= 32'h8000_0070) && (dut.pc <= 32'h8000_0100) ||
                     (dut.pc >= 32'h8000_1e30) && (dut.pc <= 32'h8000_1f30)) &&
                    (dut.perip_wstrb != 4'b0000) &&
                    ((dut.perip_addr == slot_in) ||
                     (dut.perip_addr == slot_acc) ||
                     (dut.perip_addr == slot_shift) ||
                     (dut.perip_addr == slot_digit))) begin
                    push_func_hist(5, dut.perip_addr, dut.perip_wdata);
                end
            end
        end
    end
endmodule
