`timescale 1ns / 1ps
`include "defines.v"

`ifndef SIM_TIME_NS
`define SIM_TIME_NS 64'd30_000_000_000
`endif

module tb_perf_profile_first_led;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam longint SIM_TIME_NS = `SIM_TIME_NS;
    localparam integer HISTORY_LEN = 32;
    localparam [31:0] SEG_ADDR     = 32'h8020_0020;
    localparam [31:0] LED_ADDR     = 32'h8020_0040;

    longint cycle_count;
    longint retired_slots;
    longint regwrite_retired;
    longint stall_cycles;
    longint flush_ifid_cycles;
    longint flush_idex_cycles;
    longint control_redirects;
    longint branch_updates;
    longint branch_mispredicts;
    longint pred_accepted;
    longint jal_jalr_redirects;
    longint load_use_stall_cycles;
    longint stall_from_ex_load;
    longint stall_from_mem1_load;
    longint stall_from_mem12_load;
    longint stall_from_mem2a_load;
    longint stall_consumer_branch;
    longint stall_consumer_alu;
    longint stall_consumer_store;
    longint stall_consumer_jalr;
    longint stall_consumer_load;
    longint stall_alu_rtype;
    longint stall_alu_itype;
    longint stall_alu_addsub;
    longint stall_alu_logic;
    longint stall_alu_shift;
    longint stall_alu_compare;
    longint stall_itype_addi;
    longint stall_itype_slti;
    longint stall_itype_xori;
    longint stall_itype_ori;
    longint stall_itype_andi;
    longint stall_itype_slli;
    longint stall_itype_sri;
    longint stall_rtype_addsub;
    longint stall_rtype_logic;
    longint stall_rtype_shift;
    longint stall_rtype_compare;
    longint stall_rtype_muldiv;
    longint stall_branch_beq;
    longint stall_branch_bne;
    longint stall_branch_blt;
    longint stall_branch_bge;
    longint stall_branch_bltu;
    longint stall_branch_bgeu;
    longint stall_alu_from_ex;
    longint stall_alu_from_mem1;
    longint stall_alu_from_mem12;
    longint stall_alu_from_mem2a;
    longint stall_branch_from_ex;
    longint stall_branch_from_mem1;
    longint stall_branch_from_mem12;
    longint stall_branch_from_mem2a;
    longint stall_store_from_ex;
    longint stall_store_from_mem1;
    longint stall_store_from_mem12;
    longint stall_store_from_mem2a;
    integer seg_write_count;
    integer led_write_count;
    integer hist_wr_ptr;
    integer hist_count;
    integer i;
    integer idx;
    real cpi;

    longint    hist_cycle   [0:HISTORY_LEN-1];
    time       hist_time    [0:HISTORY_LEN-1];
    reg [31:0] hist_pc      [0:HISTORY_LEN-1];
    reg [31:0] hist_inst    [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid    [0:HISTORY_LEN-1];
    reg [31:0] hist_idex    [0:HISTORY_LEN-1];
    reg [31:0] hist_exmem   [0:HISTORY_LEN-1];
    reg [31:0] hist_mem12   [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2a   [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2    [0:HISTORY_LEN-1];
    reg        hist_hold    [0:HISTORY_LEN-1];
    reg        hist_hflush  [0:HISTORY_LEN-1];
    reg        hist_ifflush [0:HISTORY_LEN-1];
    reg        hist_idflush [0:HISTORY_LEN-1];
    reg        hist_ctrlj   [0:HISTORY_LEN-1];
    reg        hist_bpacc   [0:HISTORY_LEN-1];
    reg        hist_bpupd   [0:HISTORY_LEN-1];
    reg [31:0] hist_fop1    [0:HISTORY_LEN-1];
    reg [31:0] hist_fop2    [0:HISTORY_LEN-1];
    reg        hist_wbwen   [0:HISTORY_LEN-1];
    reg [4:0]  hist_wbaddr  [0:HISTORY_LEN-1];
    reg [31:0] hist_wbdata  [0:HISTORY_LEN-1];
    reg [31:0] hist_x10     [0:HISTORY_LEN-1];
    reg [31:0] hist_x14     [0:HISTORY_LEN-1];
    reg [31:0] hist_x15     [0:HISTORY_LEN-1];

    wire [31:0] id_inst         = dut.Core_cpu.cpu_core.if_id_inst_o;
    wire [6:0]  id_opcode       = id_inst[6:0];
    wire [2:0]  id_funct3       = id_inst[14:12];
    wire [4:0]  id_rs1          = id_inst[19:15];
    wire [4:0]  id_rs2          = id_inst[24:20];
    wire        id_use_rs1      = (id_opcode == `INST_TYPE_R_M) ||
                                  (id_opcode == `INST_TYPE_I)   ||
                                  (id_opcode == `INST_TYPE_S)   ||
                                  (id_opcode == `INST_TYPE_B)   ||
                                  (id_opcode == `INST_TYPE_L)   ||
                                  (id_opcode == `INST_JALR);
    wire        id_use_rs2      = (id_opcode == `INST_TYPE_R_M) ||
                                  (id_opcode == `INST_TYPE_S)   ||
                                  (id_opcode == `INST_TYPE_B);

    wire [31:0] ex_inst         = dut.Core_cpu.cpu_core.id_ex_inst_o;
    wire [31:0] mem1_inst       = dut.Core_cpu.cpu_core.mem_inst_o;
    wire [31:0] mem12_inst      = dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
    wire [31:0] mem2a_inst      = dut.Core_cpu.cpu_core.mem2_align_inst_o;

    wire [4:0]  ex_rd           = ex_inst[11:7];
    wire [4:0]  mem1_rd         = mem1_inst[11:7];
    wire [4:0]  mem12_rd        = mem12_inst[11:7];
    wire [4:0]  mem2a_rd        = mem2a_inst[11:7];

    wire        ex_is_load_inst    = (ex_inst[6:0] == `INST_TYPE_L) && (ex_rd != 5'b0);
    wire        mem1_is_load_inst  = (mem1_inst[6:0] == `INST_TYPE_L) && (mem1_rd != 5'b0);
    wire        mem12_is_load_inst = (mem12_inst[6:0] == `INST_TYPE_L) && (mem12_rd != 5'b0);
    wire        mem2a_is_load_inst = (mem2a_inst[6:0] == `INST_TYPE_L) && (mem2a_rd != 5'b0);

    wire        ex_matches_id    = ex_is_load_inst &&
                                   ((id_use_rs1 && (ex_rd == id_rs1)) || (id_use_rs2 && (ex_rd == id_rs2)));
    wire        mem1_matches_id  = mem1_is_load_inst &&
                                   ((id_use_rs1 && (mem1_rd == id_rs1)) || (id_use_rs2 && (mem1_rd == id_rs2)));
    wire        mem12_matches_id = mem12_is_load_inst &&
                                   ((id_use_rs1 && (mem12_rd == id_rs1)) || (id_use_rs2 && (mem12_rd == id_rs2)));
    wire        mem2a_matches_id = mem2a_is_load_inst &&
                                   ((id_use_rs1 && (mem2a_rd == id_rs1)) || (id_use_rs2 && (mem2a_rd == id_rs2)));
    wire        id_is_branch      = (id_opcode == `INST_TYPE_B);
    wire        id_is_store       = (id_opcode == `INST_TYPE_S);
    wire        id_is_jalr        = (id_opcode == `INST_JALR);
    wire        id_is_load        = (id_opcode == `INST_TYPE_L);
    wire        id_is_alu_consumer= (id_opcode == `INST_TYPE_R_M) ||
                                    (id_opcode == `INST_TYPE_I);
    wire        id_is_alu_rtype   = (id_opcode == `INST_TYPE_R_M);
    wire        id_is_alu_itype   = (id_opcode == `INST_TYPE_I);
    wire        id_alu_is_addsub  = id_is_alu_consumer &&
                                    (id_funct3 == `INST_ADD_SUB);
    wire        id_alu_is_logic   = id_is_alu_consumer &&
                                    ((id_funct3 == `INST_XOR) ||
                                     (id_funct3 == `INST_OR)  ||
                                     (id_funct3 == `INST_AND));
    wire        id_alu_is_shift   = id_is_alu_consumer &&
                                    ((id_funct3 == `INST_SLL) ||
                                     (id_funct3 == `INST_SR));
    wire        id_alu_is_compare = id_is_alu_consumer &&
                                    ((id_funct3 == `INST_SLT) ||
                                     (id_funct3 == `INST_SLTU));
    wire        id_itype_is_addi   = id_is_alu_itype && (id_funct3 == `INST_ADDI);
    wire        id_itype_is_slti   = id_is_alu_itype &&
                                     ((id_funct3 == `INST_SLTI) || (id_funct3 == `INST_SLTIU));
    wire        id_itype_is_xori   = id_is_alu_itype && (id_funct3 == `INST_XORI);
    wire        id_itype_is_ori    = id_is_alu_itype && (id_funct3 == `INST_ORI);
    wire        id_itype_is_andi   = id_is_alu_itype && (id_funct3 == `INST_ANDI);
    wire        id_itype_is_slli   = id_is_alu_itype && (id_funct3 == `INST_SLLI);
    wire        id_itype_is_sri    = id_is_alu_itype && (id_funct3 == `INST_SRI);
    wire        id_rtype_is_addsub = id_is_alu_rtype && (id_funct3 == `INST_ADD_SUB);
    wire        id_rtype_is_logic  = id_is_alu_rtype &&
                                     ((id_funct3 == `INST_XOR) ||
                                      (id_funct3 == `INST_OR)  ||
                                      (id_funct3 == `INST_AND));
    wire        id_rtype_is_shift  = id_is_alu_rtype &&
                                     ((id_funct3 == `INST_SLL) ||
                                      (id_funct3 == `INST_SR));
    wire        id_rtype_is_compare= id_is_alu_rtype &&
                                     ((id_funct3 == `INST_SLT) ||
                                      (id_funct3 == `INST_SLTU));
    wire        id_rtype_is_muldiv = id_is_alu_rtype && (id_inst[31:25] == 7'b0000001);
    wire        id_branch_is_beq   = id_is_branch && (id_funct3 == `INST_BEQ);
    wire        id_branch_is_bne   = id_is_branch && (id_funct3 == `INST_BNE);
    wire        id_branch_is_blt   = id_is_branch && (id_funct3 == `INST_BLT);
    wire        id_branch_is_bge   = id_is_branch && (id_funct3 == `INST_BGE);
    wire        id_branch_is_bltu  = id_is_branch && (id_funct3 == `INST_BLTU);
    wire        id_branch_is_bgeu  = id_is_branch && (id_funct3 == `INST_BGEU);

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

    task automatic dump_recent_history;
        integer start_idx;
        integer j;
        integer slot;
        begin
            $display("PERF_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "PERF_TRACE cycle=%0d time=%0t pc=%08h inst=%08h ifid=%08h idex=%08h exmem=%08h mem12=%08h mem2a=%08h mem2=%08h | hold=%0d hflush=%0d ifflush=%0d idflush=%0d ctrlj=%0d bpacc=%0d bpupd=%0d | fop1=%08h fop2=%08h | wb=(%0d,%0d,%08h) | x10=%08h x14=%08h x15=%08h",
                    hist_cycle[slot],
                    hist_time[slot],
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_idex[slot],
                    hist_exmem[slot],
                    hist_mem12[slot],
                    hist_mem2a[slot],
                    hist_mem2[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_ifflush[slot],
                    hist_idflush[slot],
                    hist_ctrlj[slot],
                    hist_bpacc[slot],
                    hist_bpupd[slot],
                    hist_fop1[slot],
                    hist_fop2[slot],
                    hist_wbwen[slot],
                    hist_wbaddr[slot],
                    hist_wbdata[slot],
                    hist_x10[slot],
                    hist_x14[slot],
                    hist_x15[slot]
                );
            end
            $display("PERF_HISTORY_END");
        end
    endtask

    task automatic print_perf_summary;
        input [255:0] reason;
        begin
            cpi = (retired_slots != 0) ? (cycle_count * 1.0) / retired_slots : 0.0;
            $display("PERF_STOP reason=%0s cycle=%0d time=%0t pc=%08h inst=%08h",
                     reason, cycle_count, $time, dut.pc, dut.instruction);
            $display("PERF_IO seg_writes=%0d led_writes=%0d seg=%08h led=%08h vseg=%010h",
                     seg_write_count, led_write_count, dut.bridge_inst.seg_wdata, virtual_led, virtual_seg);
            $display("PERF_COUNTER cycles=%0d retired=%0d regwrite_retired=%0d cpi=%0f",
                     cycle_count, retired_slots, regwrite_retired, cpi);
            $display("PERF_STALL hold_cycles=%0d load_use_stall_cycles=%0d ex=%0d mem1=%0d mem12=%0d mem2a=%0d",
                     stall_cycles, load_use_stall_cycles, stall_from_ex_load, stall_from_mem1_load,
                     stall_from_mem12_load, stall_from_mem2a_load);
            $display("PERF_STALL_BY_CONSUMER branch=%0d alu=%0d store=%0d jalr=%0d load=%0d",
                     stall_consumer_branch, stall_consumer_alu, stall_consumer_store,
                     stall_consumer_jalr, stall_consumer_load);
            $display("PERF_STALL_BY_ALU rtype=%0d itype=%0d addsub=%0d logic=%0d shift=%0d compare=%0d",
                     stall_alu_rtype, stall_alu_itype, stall_alu_addsub,
                     stall_alu_logic, stall_alu_shift, stall_alu_compare);
            $display("PERF_STALL_ITYPE addi=%0d slti=%0d xori=%0d ori=%0d andi=%0d slli=%0d sri=%0d",
                     stall_itype_addi, stall_itype_slti, stall_itype_xori,
                     stall_itype_ori, stall_itype_andi, stall_itype_slli,
                     stall_itype_sri);
            $display("PERF_STALL_RTYPE addsub=%0d logic=%0d shift=%0d compare=%0d muldiv=%0d",
                     stall_rtype_addsub, stall_rtype_logic, stall_rtype_shift,
                     stall_rtype_compare, stall_rtype_muldiv);
            $display("PERF_STALL_BRANCH beq=%0d bne=%0d blt=%0d bge=%0d bltu=%0d bgeu=%0d",
                     stall_branch_beq, stall_branch_bne, stall_branch_blt,
                     stall_branch_bge, stall_branch_bltu, stall_branch_bgeu);
            $display("PERF_STALL_MATRIX_ALU ex=%0d mem1=%0d mem12=%0d mem2a=%0d",
                     stall_alu_from_ex, stall_alu_from_mem1,
                     stall_alu_from_mem12, stall_alu_from_mem2a);
            $display("PERF_STALL_MATRIX_BRANCH ex=%0d mem1=%0d mem12=%0d mem2a=%0d",
                     stall_branch_from_ex, stall_branch_from_mem1,
                     stall_branch_from_mem12, stall_branch_from_mem2a);
            $display("PERF_STALL_MATRIX_STORE ex=%0d mem1=%0d mem12=%0d mem2a=%0d",
                     stall_store_from_ex, stall_store_from_mem1,
                     stall_store_from_mem12, stall_store_from_mem2a);
            $display("PERF_FLUSH ifid=%0d idex=%0d redirects=%0d branch_updates=%0d branch_mispredicts=%0d pred_accepted=%0d jal_jalr_redirects=%0d",
                     flush_ifid_cycles, flush_idex_cycles, control_redirects, branch_updates,
                     branch_mispredicts, pred_accepted, jal_jalr_redirects);
            $display("PERF_REGS x10=%08h x14=%08h x15=%08h x31=%08h",
                     dut.Core_cpu.cpu_core.regs_inst.regs[10],
                     dut.Core_cpu.cpu_core.regs_inst.regs[14],
                     dut.Core_cpu.cpu_core.regs_inst.regs[15],
                     dut.Core_cpu.cpu_core.regs_inst.regs[31]);
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;

        cycle_count          = 0;
        retired_slots        = 0;
        regwrite_retired     = 0;
        stall_cycles         = 0;
        flush_ifid_cycles    = 0;
        flush_idex_cycles    = 0;
        control_redirects    = 0;
        branch_updates       = 0;
        branch_mispredicts   = 0;
        pred_accepted        = 0;
        jal_jalr_redirects   = 0;
        load_use_stall_cycles= 0;
        stall_from_ex_load   = 0;
        stall_from_mem1_load = 0;
        stall_from_mem12_load= 0;
        stall_from_mem2a_load= 0;
        stall_consumer_branch= 0;
        stall_consumer_alu   = 0;
        stall_consumer_store = 0;
        stall_consumer_jalr  = 0;
        stall_consumer_load  = 0;
        stall_alu_rtype      = 0;
        stall_alu_itype      = 0;
        stall_alu_addsub     = 0;
        stall_alu_logic      = 0;
        stall_alu_shift      = 0;
        stall_alu_compare    = 0;
        stall_itype_addi     = 0;
        stall_itype_slti     = 0;
        stall_itype_xori     = 0;
        stall_itype_ori      = 0;
        stall_itype_andi     = 0;
        stall_itype_slli     = 0;
        stall_itype_sri      = 0;
        stall_rtype_addsub   = 0;
        stall_rtype_logic    = 0;
        stall_rtype_shift    = 0;
        stall_rtype_compare  = 0;
        stall_rtype_muldiv   = 0;
        stall_branch_beq     = 0;
        stall_branch_bne     = 0;
        stall_branch_blt     = 0;
        stall_branch_bge     = 0;
        stall_branch_bltu    = 0;
        stall_branch_bgeu    = 0;
        stall_alu_from_ex    = 0;
        stall_alu_from_mem1  = 0;
        stall_alu_from_mem12 = 0;
        stall_alu_from_mem2a = 0;
        stall_branch_from_ex    = 0;
        stall_branch_from_mem1  = 0;
        stall_branch_from_mem12 = 0;
        stall_branch_from_mem2a = 0;
        stall_store_from_ex    = 0;
        stall_store_from_mem1  = 0;
        stall_store_from_mem12 = 0;
        stall_store_from_mem2a = 0;
        seg_write_count      = 0;
        led_write_count      = 0;
        hist_wr_ptr          = 0;
        hist_count           = 0;

        for (i = 0; i < HISTORY_LEN; i = i + 1) begin
            hist_cycle[i]   = 0;
            hist_time[i]    = 0;
            hist_pc[i]      = 32'b0;
            hist_inst[i]    = 32'b0;
            hist_ifid[i]    = 32'b0;
            hist_idex[i]    = 32'b0;
            hist_exmem[i]   = 32'b0;
            hist_mem12[i]   = 32'b0;
            hist_mem2a[i]   = 32'b0;
            hist_mem2[i]    = 32'b0;
            hist_hold[i]    = 1'b0;
            hist_hflush[i]  = 1'b0;
            hist_ifflush[i] = 1'b0;
            hist_idflush[i] = 1'b0;
            hist_ctrlj[i]   = 1'b0;
            hist_bpacc[i]   = 1'b0;
            hist_bpupd[i]   = 1'b0;
            hist_fop1[i]    = 32'b0;
            hist_fop2[i]    = 32'b0;
            hist_wbwen[i]   = 1'b0;
            hist_wbaddr[i]  = 5'b0;
            hist_wbdata[i]  = 32'b0;
            hist_x10[i]     = 32'b0;
            hist_x14[i]     = 32'b0;
            hist_x15[i]     = 32'b0;
        end

        #20;
        w_clk_rst = 1'b0;

        #(SIM_TIME_NS);
        dump_recent_history();
        print_perf_summary("MAX_TIME_REACHED");
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            idx = hist_wr_ptr;
            hist_cycle[idx]   = cycle_count;
            hist_time[idx]    = $time;
            hist_pc[idx]      = dut.pc;
            hist_inst[idx]    = dut.instruction;
            hist_ifid[idx]    = dut.Core_cpu.cpu_core.if_id_inst_o;
            hist_idex[idx]    = dut.Core_cpu.cpu_core.id_ex_inst_o;
            hist_exmem[idx]   = dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_mem12[idx]   = dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            hist_mem2a[idx]   = dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_mem2[idx]    = dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_hold[idx]    = dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[idx]  = dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_ifflush[idx] = dut.Core_cpu.cpu_core.ctrl_flush_ifid_o;
            hist_idflush[idx] = dut.Core_cpu.cpu_core.ctrl_flush_idex_o;
            hist_ctrlj[idx]   = dut.Core_cpu.cpu_core.ctrl_jump_en_o;
            hist_bpacc[idx]   = dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o;
            hist_bpupd[idx]   = dut.Core_cpu.cpu_core.bp_update_en_o;
            hist_fop1[idx]    = dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_fop2[idx]    = dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_wbwen[idx]   = dut.Core_cpu.cpu_core.wb_rd_wen_o;
            hist_wbaddr[idx]  = dut.Core_cpu.cpu_core.wb_rd_addr_o;
            hist_wbdata[idx]  = dut.Core_cpu.cpu_core.wb_rd_data_o;
            hist_x10[idx]     = dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x14[idx]     = dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[idx]     = dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_wr_ptr       = (hist_wr_ptr + 1) % HISTORY_LEN;
            if (hist_count < HISTORY_LEN) hist_count = hist_count + 1;

            if (dut.Core_cpu.cpu_core.mem_wb_inst_o != `INST_NOP) begin
                retired_slots = retired_slots + 1;
            end

            if (dut.Core_cpu.cpu_core.wb_rd_wen_o) begin
                regwrite_retired = regwrite_retired + 1;
            end

            if (dut.Core_cpu.cpu_core.hdu_hold_flag_o) begin
                stall_cycles = stall_cycles + 1;
            end

            if (dut.Core_cpu.cpu_core.ctrl_flush_ifid_o) begin
                flush_ifid_cycles = flush_ifid_cycles + 1;
            end

            if (dut.Core_cpu.cpu_core.ctrl_flush_idex_o) begin
                flush_idex_cycles = flush_idex_cycles + 1;
            end

            if (dut.Core_cpu.cpu_core.ctrl_jump_en_o) begin
                control_redirects = control_redirects + 1;
                if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                    branch_mispredicts = branch_mispredicts + 1;
                end else begin
                    jal_jalr_redirects = jal_jalr_redirects + 1;
                end
            end

            if (dut.Core_cpu.cpu_core.bp_update_en_o) begin
                branch_updates = branch_updates + 1;
            end

            if (dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o) begin
                pred_accepted = pred_accepted + 1;
            end

            if (dut.Core_cpu.cpu_core.hdu_hold_flag_o && dut.Core_cpu.cpu_core.hdu_flush_flag_o) begin
                load_use_stall_cycles = load_use_stall_cycles + 1;
                if (ex_matches_id)    stall_from_ex_load    = stall_from_ex_load + 1;
                if (mem1_matches_id)  stall_from_mem1_load  = stall_from_mem1_load + 1;
                if (mem12_matches_id) stall_from_mem12_load = stall_from_mem12_load + 1;
                if (mem2a_matches_id) stall_from_mem2a_load = stall_from_mem2a_load + 1;
                if (id_is_branch)       stall_consumer_branch = stall_consumer_branch + 1;
                if (id_is_alu_consumer) stall_consumer_alu    = stall_consumer_alu + 1;
                if (id_is_store)        stall_consumer_store  = stall_consumer_store + 1;
                if (id_is_jalr)         stall_consumer_jalr   = stall_consumer_jalr + 1;
                if (id_is_load)         stall_consumer_load   = stall_consumer_load + 1;
                if (id_is_alu_rtype)    stall_alu_rtype       = stall_alu_rtype + 1;
                if (id_is_alu_itype)    stall_alu_itype       = stall_alu_itype + 1;
                if (id_alu_is_addsub)   stall_alu_addsub      = stall_alu_addsub + 1;
                if (id_alu_is_logic)    stall_alu_logic       = stall_alu_logic + 1;
                if (id_alu_is_shift)    stall_alu_shift       = stall_alu_shift + 1;
                if (id_alu_is_compare)  stall_alu_compare     = stall_alu_compare + 1;
                if (id_itype_is_addi)   stall_itype_addi      = stall_itype_addi + 1;
                if (id_itype_is_slti)   stall_itype_slti      = stall_itype_slti + 1;
                if (id_itype_is_xori)   stall_itype_xori      = stall_itype_xori + 1;
                if (id_itype_is_ori)    stall_itype_ori       = stall_itype_ori + 1;
                if (id_itype_is_andi)   stall_itype_andi      = stall_itype_andi + 1;
                if (id_itype_is_slli)   stall_itype_slli      = stall_itype_slli + 1;
                if (id_itype_is_sri)    stall_itype_sri       = stall_itype_sri + 1;
                if (id_rtype_is_addsub) stall_rtype_addsub    = stall_rtype_addsub + 1;
                if (id_rtype_is_logic)  stall_rtype_logic     = stall_rtype_logic + 1;
                if (id_rtype_is_shift)  stall_rtype_shift     = stall_rtype_shift + 1;
                if (id_rtype_is_compare)stall_rtype_compare   = stall_rtype_compare + 1;
                if (id_rtype_is_muldiv) stall_rtype_muldiv    = stall_rtype_muldiv + 1;
                if (id_branch_is_beq)   stall_branch_beq      = stall_branch_beq + 1;
                if (id_branch_is_bne)   stall_branch_bne      = stall_branch_bne + 1;
                if (id_branch_is_blt)   stall_branch_blt      = stall_branch_blt + 1;
                if (id_branch_is_bge)   stall_branch_bge      = stall_branch_bge + 1;
                if (id_branch_is_bltu)  stall_branch_bltu     = stall_branch_bltu + 1;
                if (id_branch_is_bgeu)  stall_branch_bgeu     = stall_branch_bgeu + 1;
                if (id_is_alu_consumer && ex_matches_id)   stall_alu_from_ex    = stall_alu_from_ex + 1;
                if (id_is_alu_consumer && mem1_matches_id) stall_alu_from_mem1  = stall_alu_from_mem1 + 1;
                if (id_is_alu_consumer && mem12_matches_id)stall_alu_from_mem12 = stall_alu_from_mem12 + 1;
                if (id_is_alu_consumer && mem2a_matches_id)stall_alu_from_mem2a = stall_alu_from_mem2a + 1;
                if (id_is_branch && ex_matches_id)         stall_branch_from_ex    = stall_branch_from_ex + 1;
                if (id_is_branch && mem1_matches_id)       stall_branch_from_mem1  = stall_branch_from_mem1 + 1;
                if (id_is_branch && mem12_matches_id)      stall_branch_from_mem12 = stall_branch_from_mem12 + 1;
                if (id_is_branch && mem2a_matches_id)      stall_branch_from_mem2a = stall_branch_from_mem2a + 1;
                if (id_is_store && ex_matches_id)          stall_store_from_ex    = stall_store_from_ex + 1;
                if (id_is_store && mem1_matches_id)        stall_store_from_mem1  = stall_store_from_mem1 + 1;
                if (id_is_store && mem12_matches_id)       stall_store_from_mem12 = stall_store_from_mem12 + 1;
                if (id_is_store && mem2a_matches_id)       stall_store_from_mem2a = stall_store_from_mem2a + 1;
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == SEG_ADDR) begin
                seg_write_count = seg_write_count + 1;
                $display("PERF_SEG_WRITE #%0d cycle=%0d time=%0t pc=%08h inst=%08h data=%08h vseg=%010h",
                         seg_write_count, cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata, virtual_seg);
            end

            if (dut.perip_wstrb != 4'b0000 && dut.perip_addr == LED_ADDR) begin
                led_write_count = led_write_count + 1;
                $display("PERF_LED_WRITE #%0d cycle=%0d time=%0t pc=%08h inst=%08h data=%08h vseg=%010h",
                         led_write_count, cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata, virtual_seg);
                dump_recent_history();
                print_perf_summary("FIRST_LED_WRITE");
            end
        end
    end
endmodule
