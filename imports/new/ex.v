`timescale 1ns / 1ps
`include "defines.v"

module ex (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] fwd_op1_i,
    input  wire [31:0] fwd_op2_i,
    input  wire [31:0] fwd_cmp_op2_i,
    input  wire [31:0] fwd_br_op1_i,
    input  wire [31:0] fwd_br_op2_i,
    input  wire [31:0] store_data_i,
    input  wire        pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [`BP_GHR_WIDTH-1:0] pred_ghr_i,
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

    output reg  [31:0] inst_o,

    input  wire [31:0] fwd_ls_base_i,
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
    input  wire        dec_is_bclr_i,
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
    output reg         bp_actual_taken_o,
     output wire        rv32m_busy_o,
     output wire        rv32m_done_o
);

     wire [2:0] func3  = dec_func3_i;
     wire [4:0] shamt  = fwd_op2_i[4:0];

     wire [31:0] alu_op1     = fwd_op1_i;
     wire [31:0] alu_op2     = fwd_op2_i;
     wire [31:0] alu_cmp_op2 = fwd_cmp_op2_i;
     wire [31:0] branch_op1 = fwd_br_op1_i;
     wire [31:0] branch_op2 = fwd_br_op2_i;

     // Generate only the three base branch comparisons.
     // BNE, BGE and BGEU reuse the inverted base results.
     wire branch_eq          = (branch_op1 == branch_op2);
     wire branch_lt_signed   = ($signed(branch_op1) < $signed(branch_op2));
     wire branch_lt_unsigned = (branch_op1 < branch_op2);
     wire alu_less_signed   = ($signed(alu_op1) < $signed(alu_cmp_op2));
     wire alu_less_unsigned = (alu_op1 < alu_cmp_op2);

     wire [31:0] op1_i_add_op2_i = alu_op1 + alu_op2;
     wire [31:0] op1_i_and_op2_i = alu_op1 & alu_op2;
     wire [31:0] op1_i_xor_op2_i = alu_op1 ^ alu_op2;
     wire [31:0] op1_i_or_op2_i  = alu_op1 | alu_op2;

     wire [31:0] op1_i_shift_left_op2_i  = alu_op1 << alu_op2[4:0];
     wire [31:0] op1_i_shift_right_op2_i = alu_op1 >> alu_op2[4:0];
     wire [31:0] sra_mask                = (32'hffff_ffff >> shamt);

     // Zbs bclr 语义：清除 rs1 中由 rs2[4:0] 指定的位。
     // one-hot 掩码只在该指令结果路径局部生成，不放到普通 ALU 输入公共路径。
     wire [31:0] bclr_mask_w = 32'b1 << alu_op2[4:0];
     wire [31:0] bclr_result_w = alu_op1 & ~bclr_mask_w;

     wire [31:0] branch_target_addr = inst_addr_i + branch_offset_i;
     wire [31:0] mem_addr           = fwd_ls_base_i + mem_offset_i;
    wire [31:0] jal_target_addr    = inst_addr_i + jump_offset_i;
    wire [31:0] jalr_target_sum    = fwd_jalr_base_i + jump_offset_i;
    wire [31:0] jalr_target_addr   = {jalr_target_sum[31:1], 1'b0};
    wire [31:0] fallthrough_addr   = inst_addr_i + 32'd4;
    reg branch_condition_met;

    always @(*) begin
        branch_condition_met = 1'b0;

        case (branch_cond_i)
            `BR_EQ:  branch_condition_met = branch_eq;
            `BR_NE:  branch_condition_met = ~branch_eq;
            `BR_LT:  branch_condition_met = branch_lt_signed;
            `BR_GE:  branch_condition_met = ~branch_lt_signed;
            `BR_LTU: branch_condition_met = branch_lt_unsigned;
            `BR_GEU: branch_condition_met = ~branch_lt_unsigned;
            default: branch_condition_met = 1'b0;
        endcase
    end

    wire branch_taken_w = branch_condition_met;
    wire branch_direction_mismatch_w = (branch_taken_w != pred_taken_i);
    wire branch_target_mismatch_w =
        branch_taken_w && pred_taken_i && (pred_target_i != branch_target_addr);
    // Keep the timing-critical EX-to-PC redirect path local.
    // Predictor update and pipeline flush logic must preserve the same behavior.
    wire branch_redirect_w =
        dec_is_branch_i && (branch_direction_mismatch_w || branch_target_mismatch_w);
    wire [31:0] branch_redirect_addr_w =
        branch_taken_w ? branch_target_addr : fallthrough_addr;
    wire ex_branch_redirect_valid = branch_redirect_w;
    wire [31:0] ex_branch_redirect_target = branch_redirect_addr_w;
    wire jal_redirect_w =
        dec_is_jal_i &&
        (pred_taken_i == 1'b0);
    wire jalr_redirect_w =
        dec_is_jalr_i &&
        (
            !dec_ras_predicted_jalr_i ||
            !pred_taken_i ||
            (pred_target_i != jalr_target_addr)
        );
    localparam [13:0] DRAM_REGION_TAG = 14'h2004;

    reg  [31:0] rv32m_inst_r;
    reg  [4:0]  rv32m_rd_addr_r;
    reg         rv32m_rd_wen_r;
    // EX only launches the iterative unit once per decoded M instruction.
    // While busy is high, HDU freezes the front of the pipeline and EX emits NOP.
    wire        rv32m_iter_busy_w;
    wire        rv32m_iter_done_w;
    wire [31:0] rv32m_result_w;
    wire rv32m_start = (kill_i == 1'b0) && dec_is_rv32m_i && (rv32m_iter_busy_w == 1'b0) && (rv32m_iter_done_w == 1'b0);

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
        .valid_i        (kill_i == 1'b0),
        .inst_i         (inst_i),
        .inst_addr_i    (inst_addr_i),
        .csr_src_i      (alu_op1),
        .csr_rdata_o    (csr_rdata_w),
        .trap_jump_addr_o(csr_trap_jump_addr_w),
        .trap_jump_en_o (csr_trap_jump_en_w)
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
        bp_actual_taken_o  = 1'b0;
        inst_o             = kill_i ? `INST_NOP : inst_i;

        if (rv32m_busy_o == 1'b1) begin
            // Hide the in-flight M instruction from later stages until the
            // iterative unit produces a single-cycle done pulse.
            inst_o = `INST_NOP;
        end else if (rv32m_done_o == 1'b1) begin
            rd_addr_o = rv32m_rd_addr_r;
            rd_data_o = rv32m_result_w;
            rd_wen_o  = rv32m_rd_wen_r;
            inst_o    = rv32m_inst_r;
        end else if (kill_i == 1'b0) begin
            if (dec_is_bclr_i) begin
                rd_addr_o = rd_addr_i;
                rd_data_o = bclr_result_w;
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
            end

            else if (dec_is_load_i) begin
                    is_load_o     = 1'b1;
                    rd_addr_o     = rd_addr_i;
                    rd_wen_o      = rd_wen_i;
                    mem_rd_addr_o = mem_addr;
                    load_hits_dram_o = (mem_addr[31:18] == DRAM_REGION_TAG);
            end

            else if (dec_is_store_i) begin
                    mem_wd_addr_o = mem_addr;
                    case (func3)
                        `INST_SB: begin
                            case (mem_addr[1:0])
                                2'b00: begin mem_wd_reg_o = 4'b0001; mem_wd_data_o = {24'b0, store_data_i[7:0]}; end
                                2'b01: begin mem_wd_reg_o = 4'b0010; mem_wd_data_o = {16'b0, store_data_i[7:0], 8'b0}; end
                                2'b10: begin mem_wd_reg_o = 4'b0100; mem_wd_data_o = {8'b0, store_data_i[7:0], 16'b0}; end
                                2'b11: begin mem_wd_reg_o = 4'b1000; mem_wd_data_o = {store_data_i[7:0], 24'b0}; end
                                default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                            endcase
                        end
                        `INST_SH: begin
                            case (mem_addr[1])
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
    end

endmodule
