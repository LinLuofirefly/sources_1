`timescale 1ns / 1ps
`include "defines.v"

module ex (
    input  wire        clk,
    input  wire        rst,
    input  wire        valid_i,
    input  wire        timer_irq_i,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] fwd_op1_i,
    input  wire [31:0] fwd_op2_i,
    input  wire [31:0] fwd_cmp_op2_i,
    input  wire [31:0] fwd_br_op1_i,
    input  wire [31:0] fwd_br_op2_i,
    input  wire [31:0] branch_fast_load_data_i,
    input  wire        branch_fast_rs1_i,
    input  wire        branch_fast_rs2_i,
    input  wire [31:0] branch_mem2_load_data_i,
    input  wire        branch_mem2_rs1_i,
    input  wire        branch_mem2_rs2_i,
    input  wire        load_dependent_branch_i,
    input  wire [31:0] store_data_i,
    input  wire        pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [`BP_GHR_WIDTH-1:0] pred_ghr_i,
    input  wire [1:0]  pred_type_i,
    input  wire [4:0]  rd_addr_i,
    input  wire        rd_wen_i,
    input  wire        kill_i,

    // Do not force max_fanout on wide datapath buses.
    // Excessive register replication can worsen physical routing timing.
    output reg  [4:0]  rd_addr_o,
    output reg  [31:0] rd_data_o,
    output reg         rd_wen_o,

    output reg  [31:0] jump_addr_o,
    output reg         jump_en_o,
    output reg  [31:0] load_branch_jump_addr_o,
    output reg         load_branch_jump_en_o,

    output reg  [31:0] inst_o,

    input  wire [31:0] fwd_load_base_i,
    input  wire [31:0] fwd_store_base_i,
    input  wire [31:0] fwd_jalr_base_i,
    input  wire [31:0] branch_offset_i,
    input  wire [31:0] mem_offset_i,
    input  wire [31:0] jump_offset_i,
    input  wire [2:0]  branch_cond_i,
    input  wire [2:0]  dec_func3_i,
    input  wire        dec_func7_bit5_i,
    input  wire        dec_func7_is_r_i,
    input  wire        dec_func7_is_sub_i,
    input  wire        dec_is_op_imm_i,
    input  wire        dec_is_op_reg_i,
    input  wire        dec_is_branch_i,
    input  wire        dec_is_load_i,
    input  wire        dec_is_store_i,
    input  wire        dec_is_jal_i,
    input  wire        dec_is_jalr_i,
    input  wire        dec_is_auipc_i,
    input  wire        dec_is_lui_i,
    input  wire        dec_is_system_i,
    input  wire        dec_is_rv32m_i,
    input  wire        dec_is_csr_op_i,
    input  wire        dec_is_call_jal_i,
    input  wire        dec_ras_should_push_jalr_i,
    input  wire        dec_ras_should_pop_jalr_i,
    input  wire        dec_ras_predicted_jalr_i,
    output reg  [31:0] mem_rd_addr_o,
    output reg  [3:0]  mem_wd_reg_o,
    output reg  [31:0] mem_wd_addr_o,
    output reg  [31:0] mem_wd_data_o,
    output reg         is_load_o,
    output reg         load_hits_dram_o,

     output reg         bp_update_en_o,
      output reg  [31:0] bp_update_pc_o,
      output reg  [31:0] bp_update_target_o,
     output reg  [`BP_GHR_WIDTH-1:0] bp_update_ghr_o,
     output reg         bp_ras_push_en_o,
     output reg         bp_ras_pop_en_o,
     output reg  [31:0] bp_ras_push_addr_o,
     output reg         bp_jalr_update_en_o,
     output reg  [31:0] bp_jalr_update_pc_o,
     output reg  [31:0] bp_jalr_update_target_o,
     output reg  [`BP_GHR_WIDTH-1:0] bp_jalr_update_ghr_o,
     output reg         bp_jalr_update_is_call_o,
     output reg         bp_actual_taken_o,
     output wire        rv32m_busy_o,
     output wire        rv32m_done_o,
     output wire        timer_irq_trap_o
);

     wire [2:0] func3  = dec_func3_i;
     wire [4:0] shamt  = fwd_op2_i[4:0];

     wire [31:0] alu_op1     = fwd_op1_i;
     wire [31:0] alu_op2     = fwd_op2_i;
     wire [31:0] alu_cmp_op2 = fwd_cmp_op2_i;
     wire [31:0] branch_op1 = fwd_br_op1_i;
     wire [31:0] branch_op2 = fwd_br_op2_i;

     wire is_cmcrc16_w = (inst_i[6:0] == `INST_CUSTOM_0) &&
                         (inst_i[14:12] == `INST_CMCRC16_FUNC3) &&
                         (inst_i[31:25] == `INST_CMCRC16_FUNC7);

     // Parallel form of CoreMark's reflected 0xa001 CRC update.  Let x be
     // data XOR the incoming CRC.  The fixed polynomial reduces the original
     // 16 serial bit iterations to a shallow LUT-friendly XOR network.
     wire [15:0] cmcrc_x_w = alu_op1[15:0] ^ alu_op2[15:0];
     wire [15:0] cmcrc16_result16_w;
     assign cmcrc16_result16_w[0]  = cmcrc_x_w[0] ^ cmcrc_x_w[1] ^
                                     (^cmcrc_x_w[15:3]);
     assign cmcrc16_result16_w[1]  = cmcrc_x_w[2]  ^ cmcrc_x_w[3];
     assign cmcrc16_result16_w[2]  = cmcrc_x_w[3]  ^ cmcrc_x_w[4];
     assign cmcrc16_result16_w[3]  = cmcrc_x_w[4]  ^ cmcrc_x_w[5];
     assign cmcrc16_result16_w[4]  = cmcrc_x_w[5]  ^ cmcrc_x_w[6];
     assign cmcrc16_result16_w[5]  = cmcrc_x_w[6]  ^ cmcrc_x_w[7];
     assign cmcrc16_result16_w[6]  = cmcrc_x_w[7]  ^ cmcrc_x_w[8];
     assign cmcrc16_result16_w[7]  = cmcrc_x_w[8]  ^ cmcrc_x_w[9];
     assign cmcrc16_result16_w[8]  = cmcrc_x_w[9]  ^ cmcrc_x_w[10];
     assign cmcrc16_result16_w[9]  = cmcrc_x_w[10] ^ cmcrc_x_w[11];
     assign cmcrc16_result16_w[10] = cmcrc_x_w[11] ^ cmcrc_x_w[12];
     assign cmcrc16_result16_w[11] = cmcrc_x_w[12] ^ cmcrc_x_w[13];
     assign cmcrc16_result16_w[12] = cmcrc_x_w[0]  ^ cmcrc_x_w[13] ^
                                     cmcrc_x_w[14];
     assign cmcrc16_result16_w[13] = cmcrc_x_w[1]  ^ cmcrc_x_w[14] ^
                                     cmcrc_x_w[15];
     assign cmcrc16_result16_w[14] = ^cmcrc_x_w[14:1];
     assign cmcrc16_result16_w[15] = cmcrc_x_w[0] ^ (^cmcrc_x_w[15:2]);
     wire [31:0] cmcrc16_result_w = {16'b0, cmcrc16_result16_w};

     // Normal branches and load-dependent branches terminate in separate
     // comparators.  The latter is defined below and feeds only a registered
     // redirect packet.
     (* keep = "true" *) wire branch_eq_normal =
         (branch_op1 == branch_op2);
     (* keep = "true" *) wire branch_lt_signed_normal =
         ($signed(branch_op1) < $signed(branch_op2));
     (* keep = "true" *) wire branch_lt_unsigned_normal =
         (branch_op1 < branch_op2);

     wire alu_less_signed   = ($signed(alu_op1) < $signed(alu_cmp_op2));
     wire alu_less_unsigned = (alu_op1 < alu_cmp_op2);

     wire [31:0] op1_i_add_op2_i = alu_op1 + alu_op2;
     wire [31:0] op1_i_and_op2_i = alu_op1 & alu_op2;
     wire [31:0] op1_i_xor_op2_i = alu_op1 ^ alu_op2;
     wire [31:0] op1_i_or_op2_i  = alu_op1 | alu_op2;

     wire [31:0] op1_i_shift_left_op2_i  = alu_op1 << alu_op2[4:0];
     wire [31:0] op1_i_shift_right_op2_i = alu_op1 >> alu_op2[4:0];
     wire [31:0] sra_mask                = (32'hffff_ffff >> shamt);
     wire [31:0] branch_target_addr = inst_addr_i + branch_offset_i;
     wire [31:0] load_mem_addr      = fwd_load_base_i + mem_offset_i;

    // ================================================================
    // DRAM 区间命中判断：用进位选择，避开 32 位进位链
    // ----------------------------------------------------------------
    // 原写法 (load_mem_addr[31:18] == TAG) 要等整条 32 位加法进位链，
    // 而 fwd_load_base_i 是转发 mux 的晚到输出，报告里从 bit5 进链要走
    // 满 7 级 CARRY4，是当前 WNS 路径。
    //
    // mem_offset_i = {{20{imm[11]}}, imm}，所以 [31:12] 恒为符号位：
    //   addr[31:18] = base[31:18] + {14{sgn}} + c18
    //   c18 由 base[17:0] + {6{sgn},imm[11:0]} 的进位决定，而其中
    //   [17:12] 段也只是加符号位，可以用 1 级 LUT 代替进位传播：
    //     sgn=0: c18 = (base[17:12]==6'h3F) & c12
    //     sgn=1: c18 = ~((base[17:12]==6'd0) & ~c12)
    //   真正的进位链只剩 base[11:0]+imm[11:0]，12 位 = 3 级 CARRY4。
    //
    //   sgn=0: hi = base_hi + c18  -> hit = c18 ? (base_hi==TAG-1) : (base_hi==TAG)
    //   sgn=1: hi = base_hi -1+c18 -> hit = c18 ? (base_hi==TAG)   : (base_hi==TAG+1)
    // 三个常数比较互相并行，各 2 级 LUT，与进位链并行展开。
    // 逐位等价于原式，CPI 不变。
    // ================================================================
    localparam [13:0] DRAM_REGION_TAG = 14'h2004;

    wire        load_off_sgn = mem_offset_i[31];
    wire [12:0] load_lo_sum  = {1'b0, fwd_load_base_i[11:0]} +
                               {1'b0, mem_offset_i[11:0]};
    wire        load_c12     = load_lo_sum[12];
    wire [5:0]  load_mid     = fwd_load_base_i[17:12];
    wire        load_c18     =
        load_off_sgn ? ~((load_mid == 6'd0)   & ~load_c12)
                     :  ((load_mid == 6'h3F)  &  load_c12);

    wire [13:0] load_base_hi   = fwd_load_base_i[31:18];
    wire        load_hi_eq_t   = (load_base_hi == DRAM_REGION_TAG);
    wire        load_hi_eq_tm1 = (load_base_hi == (DRAM_REGION_TAG - 14'd1));
    wire        load_hi_eq_tp1 = (load_base_hi == (DRAM_REGION_TAG + 14'd1));

    wire        load_hits_dram_w =
        load_off_sgn ? (load_c18 ? load_hi_eq_t   : load_hi_eq_tp1)
                     : (load_c18 ? load_hi_eq_tm1 : load_hi_eq_t);
     wire [31:0] store_mem_addr     = fwd_store_base_i + mem_offset_i;
    wire [31:0] jal_target_addr    = inst_addr_i + jump_offset_i;
    wire [31:0] jalr_target_sum    = fwd_jalr_base_i + jump_offset_i;
    wire [31:0] jalr_target_addr   = {jalr_target_sum[31:1], 1'b0};
    wire [31:0] fallthrough_addr   = inst_addr_i + 32'd4;

    // Carry-save equality check for the JALR target.  Comparing
    // pred_target_i against jalr_target_addr directly can place a second
    // carry chain after the 32-bit target adder on the redirect path.
    //
    // For A=fwd_jalr_base_i[31:1], B=jump_offset_i[31:1],
    // P=pred_target_i[31:1] and c1=base[0]&offset[0]:
    //   A + B + c1 == P  (mod 2^31)
    // is equivalent to
    //   (A ^ B ^ ~P) == ~({majority(A,B,~P)[29:0], c1}).
    // This maps to LUT logic plus an AND reduction, without a carry chain.
    wire [30:0] jalr_cmp_a  =  fwd_jalr_base_i[31:1];
    wire [30:0] jalr_cmp_b  =  jump_offset_i[31:1];
    wire [30:0] jalr_cmp_np = ~pred_target_i[31:1];
    wire        jalr_cmp_c1 =  fwd_jalr_base_i[0] & jump_offset_i[0];

    wire [30:0] jalr_csa_s  = jalr_cmp_a ^ jalr_cmp_b ^ jalr_cmp_np;
    wire [30:0] jalr_csa_cy = (jalr_cmp_a  & jalr_cmp_b ) |
                              (jalr_cmp_a  & jalr_cmp_np) |
                              (jalr_cmp_b  & jalr_cmp_np);
    wire [30:0] jalr_csa_v  = {jalr_csa_cy[29:0], jalr_cmp_c1};

    // jalr_target_addr[0] is forced low, so the predicted bit 0 must match.
    wire jalr_target_match =
        ~pred_target_i[0] & (&(jalr_csa_s ^ jalr_csa_v));
    function branch_cond_result;
        input [2:0] cond_i;
        input       eq_i;
        input       lt_signed_i;
        input       lt_unsigned_i;
        begin
            case (cond_i)
                `BR_EQ:  branch_cond_result = eq_i;
                `BR_NE:  branch_cond_result = ~eq_i;
                `BR_LT:  branch_cond_result = lt_signed_i;
                `BR_GE:  branch_cond_result = ~lt_signed_i;
                `BR_LTU: branch_cond_result = lt_unsigned_i;
                `BR_GEU: branch_cond_result = ~lt_unsigned_i;
                default: branch_cond_result = 1'b0;
            endcase
        end
    endfunction

    wire branch_condition_normal = branch_cond_result(
        branch_cond_i,
        branch_eq_normal,
        branch_lt_signed_normal,
        branch_lt_unsigned_normal);
    // Load-dependent branches have their own operand mux and comparator.
    // This path ends at load_branch_jump_* and is registered by the top
    // level; it never contributes to the normal same-cycle jump output.
    wire [31:0] load_branch_op1 =
        branch_fast_rs1_i ? branch_fast_load_data_i :
        branch_mem2_rs1_i ? branch_mem2_load_data_i : branch_op1;
    wire [31:0] load_branch_op2 =
        branch_fast_rs2_i ? branch_fast_load_data_i :
        branch_mem2_rs2_i ? branch_mem2_load_data_i : branch_op2;
    wire load_branch_eq = (load_branch_op1 == load_branch_op2);
    wire load_branch_lt_signed =
        ($signed(load_branch_op1) < $signed(load_branch_op2));
    wire load_branch_lt_unsigned = (load_branch_op1 < load_branch_op2);
    wire branch_condition_load = branch_cond_result(
        branch_cond_i, load_branch_eq,
        load_branch_lt_signed, load_branch_lt_unsigned);

    wire branch_taken_w = load_dependent_branch_i ?
        branch_condition_load : branch_condition_normal;
    wire branch_pred_taken_w =
        (pred_type_i == `BP_PRED_BRANCH) && pred_taken_i;
    wire jal_pred_taken_w =
        (pred_type_i == `BP_PRED_JAL) && pred_taken_i;
    wire jalr_pred_taken_w =
        (pred_type_i == `BP_PRED_JALR) && pred_taken_i;
    wire normal_branch_direction_mismatch_w =
        (branch_condition_normal != branch_pred_taken_w);
    wire load_branch_direction_mismatch_w =
        (branch_condition_load != branch_pred_taken_w);
    // Conditional-branch targets are static for this IROM and BTB entries are
    // tag-checked.  On a direction miss, the registered prediction already
    // identifies the correction target, so the late comparison result need
    // not select the 32-bit PC redirect bus.
    wire branch_redirect_w =
        dec_is_branch_i && !load_dependent_branch_i &&
        normal_branch_direction_mismatch_w;
    wire load_branch_redirect_w =
        dec_is_branch_i && load_dependent_branch_i &&
        load_branch_direction_mismatch_w;
    wire [31:0] branch_redirect_addr_w =
        branch_pred_taken_w ? fallthrough_addr : branch_target_addr;
    wire ex_branch_redirect_valid = branch_redirect_w;
    wire [31:0] ex_branch_redirect_target = branch_redirect_addr_w;
    wire jal_redirect_w =
        dec_is_jal_i &&
        !jal_pred_taken_w;
    wire jalr_redirect_w =
        dec_is_jalr_i &&
        (
            !jalr_pred_taken_w ||
            !jalr_target_match
        );

    reg  [31:0] rv32m_inst_r;
    reg  [4:0]  rv32m_rd_addr_r;
    reg         rv32m_rd_wen_r;
    // EX only launches the iterative unit once per decoded M instruction.
    // While busy is high, HDU freezes the front of the pipeline and EX emits NOP.
    wire        rv32m_iter_busy_w;
    wire        rv32m_iter_done_w;
    wire [31:0] rv32m_result_w;
    wire rv32m_start_slot =
        dec_is_rv32m_i &&
        (rv32m_iter_busy_w == 1'b0) &&
        (rv32m_iter_done_w == 1'b0);
    wire csr_timer_irq_trap_w;
    assign timer_irq_trap_o = csr_timer_irq_trap_w;
    wire rv32m_start = valid_i && (kill_i == 1'b0) &&
                       !csr_timer_irq_trap_w && rv32m_start_slot;
    wire rv32m_hide_ex = rv32m_start_slot || rv32m_iter_busy_w;

    rv32m_iter rv32m_iter_inst (
        .clk    (clk),
        .rst    (rst),
        .start_i(rv32m_start),
        .func3_i(func3),
        .op1_i  (alu_op1),
        .op2_i  (alu_op2),
        .busy_o (rv32m_iter_busy_w),
        .done_o (rv32m_iter_done_w),
        .result_o(rv32m_result_w)
    );

    assign rv32m_busy_o = rv32m_start || rv32m_iter_busy_w;
    assign rv32m_done_o = rv32m_iter_done_w;

    wire [31:0] csr_rdata_w;
    wire [31:0] csr_trap_jump_addr_w;
    wire        csr_trap_jump_en_w;

    csr csr_inst (
        .clk            (clk),
        .rst            (rst),
        // This core's executable IROM starts at 0x8000_0000.  Redirect
        // bubbles carry inst_addr=0 and must never become interrupt points.
        .valid_i        (valid_i && (kill_i == 1'b0) && inst_addr_i[31] &&
                         !rv32m_iter_busy_w && !rv32m_iter_done_w),
        .timer_irq_i    (timer_irq_i),
        .inst_i         (inst_i),
        .inst_addr_i    (inst_addr_i),
        .csr_src_i      (alu_op1),
        .csr_rdata_o    (csr_rdata_w),
        .trap_jump_addr_o(csr_trap_jump_addr_w),
        .trap_jump_en_o (csr_trap_jump_en_w),
        .timer_irq_trap_o(csr_timer_irq_trap_w)
    );

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            rv32m_inst_r    <= `INST_NOP;
            rv32m_rd_addr_r <= 5'b0;
            rv32m_rd_wen_r  <= 1'b0;
        end else if (rv32m_start) begin
            // Latch writeback metadata so the result can be replayed after the
            // iterative unit finishes, even though ID/EX is stalled meanwhile.
            rv32m_inst_r    <= inst_i;
            rv32m_rd_addr_r <= rd_addr_i;
            rv32m_rd_wen_r  <= rd_wen_i;
        end
    end

    always @(*) begin

        rd_addr_o          = 5'b0;
        rd_data_o          = 32'b0;
        rd_wen_o           = 1'b0;
        jump_addr_o        = csr_trap_jump_addr_w;
        jump_en_o          = csr_trap_jump_en_w;
        load_branch_jump_addr_o = 32'b0;
        load_branch_jump_en_o = 1'b0;
        mem_rd_addr_o      = 32'b0;
        mem_wd_reg_o       = 4'b0000;
        mem_wd_addr_o      = 32'b0;
        mem_wd_data_o      = 32'b0;
        is_load_o          = 1'b0;
        load_hits_dram_o   = 1'b0;
        bp_update_en_o     = 1'b0;
        bp_update_pc_o     = 32'b0;
        bp_update_target_o = 32'b0;
        bp_update_ghr_o    = {`BP_GHR_WIDTH{1'b0}};
        bp_ras_push_en_o   = 1'b0;
        bp_ras_pop_en_o    = 1'b0;
        bp_ras_push_addr_o = 32'b0;
        bp_jalr_update_en_o = 1'b0;
        bp_jalr_update_pc_o = 32'b0;
        bp_jalr_update_target_o = 32'b0;
        bp_jalr_update_ghr_o = {`BP_GHR_WIDTH{1'b0}};
        bp_jalr_update_is_call_o = 1'b0;
        bp_actual_taken_o  = 1'b0;
        inst_o             = (kill_i || !valid_i) ? `INST_NOP : inst_i;

        if (rv32m_hide_ex == 1'b1) begin
            // Hide the in-flight M instruction from later stages until the
            // iterative unit produces a single-cycle done pulse.
            inst_o = `INST_NOP;
        end else if (rv32m_iter_done_w == 1'b1) begin
            rd_addr_o = rv32m_rd_addr_r;
            rd_data_o = rv32m_result_w;
            rd_wen_o  = rv32m_rd_wen_r;
            inst_o    = rv32m_inst_r;
        end else begin
            if (is_cmcrc16_w) begin
                    rd_data_o = cmcrc16_result_w;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
            end

            else if (dec_is_op_imm_i) begin
                    case (func3)
                        `INST_ADDI:  rd_data_o = op1_i_add_op2_i;
                        `INST_SLTI:  rd_data_o = {31'b0, alu_less_signed};
                        `INST_SLTIU: rd_data_o = {31'b0, alu_less_unsigned};
                        `INST_ANDI:  rd_data_o = op1_i_and_op2_i;
                        `INST_ORI:   rd_data_o = op1_i_or_op2_i;
                        `INST_XORI:  rd_data_o = op1_i_xor_op2_i;
                        `INST_SLLI:  rd_data_o = op1_i_shift_left_op2_i;
                        `INST_SRI: begin
                            if (dec_func7_bit5_i == 1'b0) begin
                                rd_data_o = op1_i_shift_right_op2_i;
                            end else begin
                                rd_data_o = (op1_i_shift_right_op2_i & sra_mask)
                                          | ({32{alu_op1[31]}} & ~sra_mask);
                            end
                        end
                        default: rd_data_o = 32'b0;
                    endcase

                    if (func3 == `INST_ADDI || func3 == `INST_SLTI || func3 == `INST_SLTIU ||
                        func3 == `INST_ANDI || func3 == `INST_ORI  || func3 == `INST_XORI  ||
                        func3 == `INST_SLLI || func3 == `INST_SRI) begin
                        rd_addr_o = rd_addr_i;
                        rd_wen_o  = rd_wen_i;
                    end
            end

            else if (dec_is_op_reg_i) begin
                    case (func3)
                        `INST_ADD_SUB: begin
                            if (dec_func7_is_r_i == 1'b1) begin
                                rd_data_o = op1_i_add_op2_i;
                            end else if (dec_func7_is_sub_i == 1'b1) begin
                                rd_data_o = alu_op1 - alu_op2;
                            end else begin
                                rd_data_o = 32'b0;
                            end
                        end
                        `INST_SLL:  rd_data_o = op1_i_shift_left_op2_i;
                        `INST_SLT:  rd_data_o = {31'b0, alu_less_signed};
                        `INST_SLTU: rd_data_o = {31'b0, alu_less_unsigned};
                        `INST_OR:   rd_data_o = op1_i_or_op2_i;
                        `INST_XOR:  rd_data_o = op1_i_xor_op2_i;
                        `INST_AND:  rd_data_o = op1_i_and_op2_i;
                        `INST_SR: begin
                            if (dec_func7_bit5_i == 1'b0) begin
                                rd_data_o = op1_i_shift_right_op2_i;
                            end else begin
                                rd_data_o = (op1_i_shift_right_op2_i & sra_mask)
                                          | ({32{alu_op1[31]}} & ~sra_mask);
                            end
                        end
                        default: rd_data_o = 32'b0;
                    endcase

                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
            end

            else if (dec_is_branch_i) begin
                    bp_update_en_o    = 1'b1;
                    bp_update_pc_o    = inst_addr_i;
                    bp_update_target_o = branch_target_addr;
                    bp_update_ghr_o   = pred_ghr_i;
                    bp_actual_taken_o = branch_taken_w;

                    if (ex_branch_redirect_valid) begin
                        jump_en_o   = 1'b1;
                        jump_addr_o = ex_branch_redirect_target;
                    end
                    if (load_branch_redirect_w) begin
                        load_branch_jump_en_o = 1'b1;
                        load_branch_jump_addr_o = branch_redirect_addr_w;
                    end
            end

            else if (dec_is_load_i) begin
                    is_load_o     = 1'b1;
                    rd_addr_o     = rd_addr_i;
                    rd_wen_o      = rd_wen_i;
                    mem_rd_addr_o = load_mem_addr;
                    load_hits_dram_o = load_hits_dram_w;
            end

            else if (dec_is_store_i) begin
                    mem_wd_addr_o = store_mem_addr;
                    case (func3)
                        `INST_SB: begin
                            case (store_mem_addr[1:0])
                                2'b00: begin mem_wd_reg_o = 4'b0001; mem_wd_data_o = {24'b0, store_data_i[7:0]}; end
                                2'b01: begin mem_wd_reg_o = 4'b0010; mem_wd_data_o = {16'b0, store_data_i[7:0], 8'b0}; end
                                2'b10: begin mem_wd_reg_o = 4'b0100; mem_wd_data_o = {8'b0, store_data_i[7:0], 16'b0}; end
                                2'b11: begin mem_wd_reg_o = 4'b1000; mem_wd_data_o = {store_data_i[7:0], 24'b0}; end
                                default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                            endcase
                        end
                        `INST_SH: begin
                            case (store_mem_addr[1])
                                1'b0: begin mem_wd_reg_o = 4'b0011; mem_wd_data_o = {16'b0, store_data_i[15:0]}; end
                                1'b1: begin mem_wd_reg_o = 4'b1100; mem_wd_data_o = {store_data_i[15:0], 16'b0}; end
                                default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                            endcase
                        end
                        `INST_SW: begin
                            mem_wd_reg_o  = 4'b1111;
                            mem_wd_data_o = store_data_i;
                        end
                        default: begin
                            mem_wd_reg_o  = 4'b0000;
                            mem_wd_data_o = 32'b0;
                        end
                    endcase
            end

            else if (dec_is_jal_i) begin
                    rd_data_o = op1_i_add_op2_i;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;

                    if (dec_is_call_jal_i == 1'b1) begin
                        bp_ras_push_en_o = 1'b1;
                        bp_ras_push_addr_o = fallthrough_addr;
                    end

                    if (jal_redirect_w) begin
                        jump_addr_o = jal_target_addr;
                        jump_en_o   = 1'b1;
                    end
            end

            else if (dec_is_jalr_i) begin
                    rd_data_o   = inst_addr_i + 32'd4;
                    rd_addr_o   = rd_addr_i;
                    rd_wen_o    = rd_wen_i;
                    jump_addr_o = jalr_target_addr;

                    if (dec_ras_should_push_jalr_i == 1'b1) begin
                        bp_ras_push_en_o = 1'b1;
                        bp_ras_push_addr_o = fallthrough_addr;
                    end

                    if (dec_ras_should_pop_jalr_i == 1'b1) begin
                        bp_ras_pop_en_o = 1'b1;
                    end

                    // Returns continue to use the RAS.  Train the separate
                    // target cache only for indirect calls and jumps.
                    if (dec_ras_predicted_jalr_i == 1'b0) begin
                        bp_jalr_update_en_o = 1'b1;
                        bp_jalr_update_pc_o = inst_addr_i;
                        bp_jalr_update_target_o = jalr_target_addr;
                        bp_jalr_update_ghr_o = pred_ghr_i;
                        bp_jalr_update_is_call_o =
                            dec_ras_should_push_jalr_i;
                    end

                    if (jalr_redirect_w) begin
                        jump_en_o = 1'b1;
                    end
            end

            else if (dec_is_auipc_i) begin
                    rd_data_o = op1_i_add_op2_i;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
            end

            else if (dec_is_lui_i) begin
                    rd_data_o = alu_op1;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
            end

            else if (dec_is_system_i) begin
                    if (dec_is_csr_op_i == 1'b1) begin
                        rd_data_o = csr_rdata_w;
                        rd_addr_o = rd_addr_i;
                        rd_wen_o  = rd_wen_i;
                    end
            end

            else begin
                    rd_addr_o = 5'b0;
                    rd_data_o = 32'b0;
                    rd_wen_o  = 1'b0;
            end
        end

        // Kill only the architectural side effects.  Keep rd_data_o as the
        // decoded datapath result so late_load_miss/kill_i does not select
        // the 32-bit ALU result bus.  A killed EX/MEM entry is harmless
        // because all downstream forwarding and writeback selection is
        // qualified by rd_wen_o, and memory/redirect requests are qualified
        // by their enable bits.
        // An asynchronous interrupt discards the current EX instruction and
        // stores its address in mepc, so mret replays it precisely.
        if (csr_timer_irq_trap_w == 1'b1) begin
            rd_wen_o         = 1'b0;
            mem_wd_reg_o     = 4'b0000;
            jump_en_o        = 1'b1;
            jump_addr_o      = csr_trap_jump_addr_w;
            load_branch_jump_en_o = 1'b0;
            is_load_o        = 1'b0;
            load_hits_dram_o = 1'b0;
            bp_update_en_o   = 1'b0;
            bp_ras_push_en_o = 1'b0;
            bp_ras_pop_en_o  = 1'b0;
            bp_jalr_update_en_o = 1'b0;
            inst_o           = `INST_NOP;
        end

        // Once an RV32M operation has been accepted by rv32m_start, the
        // iterative unit and the metadata registers above own that
        // instruction until done.  ID/EX may subsequently lose its valid bit
        // because of a younger frontend replay/flush; that must not cancel the
        // already accepted result.  No older redirect can coexist with an M
        // operation in this single-issue EX stage, and timer interrupts are
        // explicitly deferred while the iterator is active.
        if (((kill_i == 1'b1) || (valid_i == 1'b0)) &&
            (rv32m_iter_done_w == 1'b0)) begin
            rd_wen_o         = 1'b0;
            mem_wd_reg_o     = 4'b0000;
            jump_en_o        = 1'b0;
            load_branch_jump_en_o = 1'b0;
            is_load_o        = 1'b0;
            load_hits_dram_o = 1'b0;
            bp_update_en_o   = 1'b0;
            bp_ras_push_en_o = 1'b0;
            bp_ras_pop_en_o  = 1'b0;
            bp_jalr_update_en_o = 1'b0;
            inst_o           = `INST_NOP;
        end
    end

`ifndef SYNTHESIS
    // Check the value sampled by the pipeline.  A separate combinational
    // assertion block races the EX output block for one delta cycle whenever
    // kill_i changes, which produces false failures even though the killed
    // values are settled before the active clock edge.
    always @(posedge clk) begin
        if (kill_i == 1'b1) begin
            if (rd_wen_o !== 1'b0)         $error("EX kill_i asserted with rd_wen_o high");
            if (mem_wd_reg_o !== 4'b0000) $error("EX kill_i asserted with store write strobe high");
            if (jump_en_o !== 1'b0)       $error("EX kill_i asserted with jump_en_o high");
            if (is_load_o !== 1'b0)       $error("EX kill_i asserted with is_load_o high");
            if (bp_update_en_o !== 1'b0)  $error("EX kill_i asserted with bp_update_en_o high");
            if (inst_o !== `INST_NOP)     $error("EX kill_i asserted without NOP inst_o");
        end
    end
`endif

endmodule
