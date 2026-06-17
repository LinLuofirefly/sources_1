`timescale 1ns / 1ps

module tb_duplicate_origin_probe;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer HIST = 24;
    localparam [31:0] TARGET_PC   = 32'h8000_1fbc;
    localparam [31:0] TARGET_INST = 32'h0015_d593;

    integer cycle_count;
    integer i;
    integer idx;
    integer dup_seen;

    reg [31:0] h_pc        [0:HIST-1];
    reg [31:0] h_fetch_pc  [0:HIST-1];
    reg [31:0] h_inst      [0:HIST-1];
    reg [31:0] h_ifid_pc   [0:HIST-1];
    reg [31:0] h_ifid_inst [0:HIST-1];
    reg [31:0] h_idex_pc   [0:HIST-1];
    reg [31:0] h_idex_inst [0:HIST-1];
    reg [31:0] h_exmem_inst [0:HIST-1];
    reg [31:0] h_m12_inst   [0:HIST-1];
    reg [31:0] h_m2_inst    [0:HIST-1];
    reg [31:0] h_wb_inst    [0:HIST-1];
    reg [31:0] h_jaddr     [0:HIST-1];
    reg [4:0]  h_id_rs1    [0:HIST-1];
    reg        h_id_jalr    [0:HIST-1];
    reg        h_ifv       [0:HIST-1];
    reg        h_dup       [0:HIST-1];
    reg        h_hold      [0:HIST-1];
    reg        h_replay_p  [0:HIST-1];
    reg        h_replay    [0:HIST-1];
    reg        h_ex_jump   [0:HIST-1];
    reg        h_ctrl_fl   [0:HIST-1];
    reg        h_pred_fl   [0:HIST-1];
    reg        h_rply_fl   [0:HIST-1];

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

    task automatic dump_hist;
        integer k;
        integer p;
        begin
            $display("DUP_ORIGIN_DUMP cyc=%0d", cycle_count);
            for (k = HIST - 1; k >= 0; k = k - 1) begin
                p = (idx + HIST - k) % HIST;
                $display(
                    "HIST age=%0d cyc=%0d pc=%08h fetch_pc=%08h inst=%08h ifv=%b dup=%b hold=%b replay_p=%b replay=%b ifid_pc=%08h ifid_inst=%08h id_rs1=%0d id_jalr=%b idex_pc=%08h idex_inst=%08h exmem_inst=%08h m12_inst=%08h m2_inst=%08h wb_inst=%08h ex_jump=%b jaddr=%08h ctrl_fl=%b pred_fl=%b rply_fl=%b",
                    k,
                    cycle_count - k,
                    h_pc[p],
                    h_fetch_pc[p],
                    h_inst[p],
                    h_ifv[p],
                    h_dup[p],
                    h_hold[p],
                    h_replay_p[p],
                    h_replay[p],
                    h_ifid_pc[p],
                    h_ifid_inst[p],
                    h_id_rs1[p],
                    h_id_jalr[p],
                    h_idex_pc[p],
                    h_idex_inst[p],
                    h_exmem_inst[p],
                    h_m12_inst[p],
                    h_m2_inst[p],
                    h_wb_inst[p],
                    h_ex_jump[p],
                    h_jaddr[p],
                    h_ctrl_fl[p],
                    h_pred_fl[p],
                    h_rply_fl[p]
                );
            end
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        idx         = 0;
        dup_seen    = 0;

        for (i = 0; i < HIST; i = i + 1) begin
            h_pc[i]        = 32'b0;
            h_fetch_pc[i]  = 32'b0;
            h_inst[i]      = 32'b0;
            h_ifid_pc[i]   = 32'b0;
            h_ifid_inst[i] = 32'b0;
            h_idex_pc[i]   = 32'b0;
            h_idex_inst[i] = 32'b0;
            h_exmem_inst[i] = 32'b0;
            h_m12_inst[i]   = 32'b0;
            h_m2_inst[i]    = 32'b0;
            h_wb_inst[i]    = 32'b0;
            h_jaddr[i]     = 32'b0;
            h_id_rs1[i]     = 5'b0;
            h_id_jalr[i]    = 1'b0;
            h_ifv[i]       = 1'b0;
            h_dup[i]       = 1'b0;
            h_hold[i]      = 1'b0;
            h_replay_p[i]  = 1'b0;
            h_replay[i]    = 1'b0;
            h_ex_jump[i]   = 1'b0;
            h_ctrl_fl[i]   = 1'b0;
            h_pred_fl[i]   = 1'b0;
            h_rply_fl[i]   = 1'b0;
        end

        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;
            idx = (idx + 1) % HIST;

            h_pc[idx]        = dut.Core_cpu.cpu_core.pc_reg_pc_o;
            h_fetch_pc[idx]  = dut.Core_cpu.cpu_core.bp_fetch_pc_r;
            h_inst[idx]      = dut.instruction;
            h_ifid_pc[idx]   = dut.Core_cpu.cpu_core.if_id_inst_addr_o;
            h_ifid_inst[idx] = dut.Core_cpu.cpu_core.if_id_inst_o;
            h_idex_pc[idx]   = dut.Core_cpu.cpu_core.id_ex_inst_addr_o;
            h_idex_inst[idx] = dut.Core_cpu.cpu_core.id_ex_inst_o;
            h_exmem_inst[idx] = dut.Core_cpu.cpu_core.ex_mem_inst_o;
            h_m12_inst[idx]   = dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            h_m2_inst[idx]    = dut.Core_cpu.cpu_core.mem2_align_inst_o;
            h_wb_inst[idx]    = dut.Core_cpu.cpu_core.mem_wb_inst_o;
            h_jaddr[idx]     = dut.Core_cpu.cpu_core.ex_jump_addr_o;
            h_id_rs1[idx]     = dut.Core_cpu.cpu_core.id_rs1_addr_o;
            h_id_jalr[idx]    = dut.Core_cpu.cpu_core.id_is_jalr_w;
            h_ifv[idx]       = dut.Core_cpu.cpu_core.ifid_fetch_valid;
            h_dup[idx]       = dut.Core_cpu.cpu_core.ifid_duplicate;
            h_hold[idx]      = dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            h_replay_p[idx]  = dut.Core_cpu.cpu_core.if_id_replay_pending_o;
            h_replay[idx]    = dut.Core_cpu.cpu_core.if_id_replaying_o;
            h_ex_jump[idx]   = dut.Core_cpu.cpu_core.ex_jump_en_o;
            h_ctrl_fl[idx]   = dut.Core_cpu.cpu_core.ctrl_flush_ifid_o;
            h_pred_fl[idx]   = dut.Core_cpu.cpu_core.bp_pred_flush_d1_r;
            h_rply_fl[idx]   = dut.Core_cpu.cpu_core.bp_replay_flush_d1_r;

            if ((dup_seen == 0) &&
                (cycle_count > 100) &&
                dut.Core_cpu.cpu_core.ifid_duplicate &&
                (dut.Core_cpu.cpu_core.bp_fetch_pc_r == TARGET_PC) &&
                (dut.Core_cpu.cpu_core.if_id_inst_addr_o == TARGET_PC) &&
                (dut.instruction == TARGET_INST) &&
                (dut.Core_cpu.cpu_core.if_id_inst_o == TARGET_INST)) begin
                dup_seen = 1;
                dump_hist();
                $finish;
            end

            if (cycle_count >= 10000) begin
                $display("DUP_ORIGIN_TIMEOUT cyc=%0d", cycle_count);
                $finish;
            end
        end
    end
endmodule
