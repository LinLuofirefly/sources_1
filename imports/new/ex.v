`include "defines.v"

module ex (
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    input  wire        pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [8:0]  pred_ghr_i,
    input  wire [14:0] ctrl_flags_i,
    input  wire [4:0]  rd_addr_i,
    input  wire        rd_wen_i,
    input  wire        kill_i,

    output reg  [4:0]  rd_addr_o,
    output reg  [31:0] rd_data_o,
    output reg         rd_wen_o,

    output reg  [31:0] jump_addr_o,
    output reg         jump_en_o,

    output wire [31:0] inst_o,

    input  wire [31:0] base_addr_i,
    input  wire [31:0] addr_offset_i,
    output reg  [31:0] mem_rd_addr_o,
    output reg  [3:0]  mem_wd_reg_o,
    output reg  [31:0] mem_wd_addr_o,
    output reg  [31:0] mem_wd_data_o,
    output reg         is_load_o,

    output reg         bp_update_en_o,
    output reg  [31:0] bp_update_pc_o,
    output reg  [8:0]  bp_update_ghr_o,
    output reg         bp_ras_push_en_o,
    output reg         bp_ras_pop_en_o,
    output reg  [31:0] bp_ras_push_addr_o,
    output reg         bp_actual_taken_o
);

    wire [6:0] opcode = inst_i[6:0];
    wire [2:0] func3  = inst_i[14:12];
    wire [4:0] rd     = inst_i[11:7];
    wire [4:0] rs1    = inst_i[19:15];
    wire [4:0] shamt  = op2_i[4:0];
    wire is_itype = ctrl_flags_i[0];
    wire is_rtype = ctrl_flags_i[1];
    wire is_load  = ctrl_flags_i[2];
    wire is_store = ctrl_flags_i[3];
    wire is_jal   = ctrl_flags_i[4];
    wire is_jalr  = ctrl_flags_i[5];
    wire is_auipc = ctrl_flags_i[6];
    wire is_lui   = ctrl_flags_i[7];
    wire is_beq   = ctrl_flags_i[8];
    wire is_bne   = ctrl_flags_i[9];
    wire is_blt   = ctrl_flags_i[10];
    wire is_bge   = ctrl_flags_i[11];
    wire is_bltu  = ctrl_flags_i[12];
    wire is_bgeu  = ctrl_flags_i[13];
    wire func7_bit5 = ctrl_flags_i[14];
    wire is_branch = is_beq | is_bne | is_blt | is_bge | is_bltu | is_bgeu;

    wire op1_i_equal_op2_i         = (op1_i == op2_i);
    wire op1_i_less_op2_i_signed   = ($signed(op1_i) < $signed(op2_i));
    wire op1_i_less_op2_i_unsigned = (op1_i < op2_i);

    wire [31:0] op1_i_add_op2_i = op1_i + op2_i;
    wire [31:0] op1_i_and_op2_i = op1_i & op2_i;
    wire [31:0] op1_i_xor_op2_i = op1_i ^ op2_i;
    wire [31:0] op1_i_or_op2_i  = op1_i | op2_i;

    wire [31:0] op1_i_shift_left_op2_i  = op1_i << op2_i[4:0];
    wire [31:0] op1_i_shift_right_op2_i = op1_i >> op2_i[4:0];
    wire [31:0] sra_mask                = (32'hffff_ffff >> shamt);

    wire [31:0] base_addr_add_addr_offset = base_addr_i + addr_offset_i;
    wire [31:0] pc_relative_jump_addr     = inst_addr_i + addr_offset_i;
    wire [31:0] fallthrough_addr          = inst_addr_i + 32'd4;
    wire        rd_is_link = (rd == 5'd1) || (rd == 5'd5);
    wire        rs1_is_link = (rs1 == 5'd1) || (rs1 == 5'd5);
    wire        is_call_jal = (opcode == `INST_JAL) && rd_is_link;
    wire        is_jalr_hint = (opcode == `INST_JALR) && (func3 == 3'b000);
    wire        ras_should_push_jalr = is_jalr_hint && rd_is_link;
    wire        ras_should_pop_jalr = is_jalr_hint && rs1_is_link && (!rd_is_link || (rd != rs1));
    wire        ras_predicted_jalr = ras_should_pop_jalr;

    reg branch_taken_r;

    assign inst_o = kill_i ? `INST_NOP : inst_i;

    always @(*) begin
        rd_addr_o          = 5'b0;
        rd_data_o          = 32'b0;
        rd_wen_o           = 1'b0;
        jump_addr_o        = 32'b0;
        jump_en_o          = 1'b0;
        mem_rd_addr_o      = 32'b0;
        mem_wd_reg_o       = 4'b0000;
        mem_wd_addr_o      = 32'b0;
        mem_wd_data_o      = 32'b0;
        is_load_o          = 1'b0;
        bp_update_en_o     = 1'b0;
        bp_update_pc_o     = 32'b0;
        bp_update_ghr_o    = 9'b0;
        bp_ras_push_en_o   = 1'b0;
        bp_ras_pop_en_o    = 1'b0;
        bp_ras_push_addr_o = 32'b0;
        bp_actual_taken_o  = 1'b0;
        branch_taken_r     = 1'b0;

        if (kill_i == 1'b0) begin
            if (is_itype) begin
                case (func3)
                    `INST_ADDI:  rd_data_o = op1_i_add_op2_i;
                    `INST_SLTI:  rd_data_o = {31'b0, op1_i_less_op2_i_signed};
                    `INST_SLTIU: rd_data_o = {31'b0, op1_i_less_op2_i_unsigned};
                    `INST_ANDI:  rd_data_o = op1_i_and_op2_i;
                    `INST_ORI:   rd_data_o = op1_i_or_op2_i;
                    `INST_XORI:  rd_data_o = op1_i_xor_op2_i;
                    `INST_SLLI:  rd_data_o = op1_i_shift_left_op2_i;
                    `INST_SRI: begin
                        if (func7_bit5 == 1'b0) begin
                            rd_data_o = op1_i_shift_right_op2_i;
                        end else begin
                            rd_data_o = (op1_i_shift_right_op2_i & sra_mask)
                                      | ({32{op1_i[31]}} & ~sra_mask);
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
            end else if (is_rtype) begin
                case (func3)
                    `INST_ADD_SUB: begin
                        if (func7_bit5 == 1'b0) begin
                            rd_data_o = op1_i_add_op2_i;
                        end else begin
                            rd_data_o = op1_i - op2_i;
                        end
                    end
                    `INST_SLL:  rd_data_o = op1_i_shift_left_op2_i;
                    `INST_SLT:  rd_data_o = {31'b0, op1_i_less_op2_i_signed};
                    `INST_SLTU: rd_data_o = {31'b0, op1_i_less_op2_i_unsigned};
                    `INST_OR:   rd_data_o = op1_i_or_op2_i;
                    `INST_XOR:  rd_data_o = op1_i_xor_op2_i;
                    `INST_AND:  rd_data_o = op1_i_and_op2_i;
                    `INST_SR: begin
                        if (func7_bit5 == 1'b0) begin
                            rd_data_o = op1_i_shift_right_op2_i;
                        end else begin
                            rd_data_o = (op1_i_shift_right_op2_i & sra_mask)
                                      | ({32{op1_i[31]}} & ~sra_mask);
                        end
                    end
                    default: rd_data_o = 32'b0;
                endcase

                rd_addr_o = rd_addr_i;
                rd_wen_o  = rd_wen_i;
            end else if (is_branch) begin
                if (is_bne) begin
                    branch_taken_r = ~op1_i_equal_op2_i;
                end else if (is_beq) begin
                    branch_taken_r = op1_i_equal_op2_i;
                end else if (is_blt) begin
                    branch_taken_r = op1_i_less_op2_i_signed;
                end else if (is_bge) begin
                    branch_taken_r = ~op1_i_less_op2_i_signed;
                end else if (is_bltu) begin
                    branch_taken_r = op1_i_less_op2_i_unsigned;
                end else if (is_bgeu) begin
                    branch_taken_r = ~op1_i_less_op2_i_unsigned;
                end else begin
                    branch_taken_r = 1'b0;
                end

                bp_update_en_o    = 1'b1;
                bp_update_pc_o    = inst_addr_i;
                bp_update_ghr_o   = pred_ghr_i;
                bp_actual_taken_o = branch_taken_r;
                if (branch_taken_r != pred_taken_i) begin
                    jump_en_o   = 1'b1;
                    jump_addr_o = branch_taken_r ? pc_relative_jump_addr : fallthrough_addr;
                end
            end else if (is_load) begin
                is_load_o     = 1'b1;
                rd_addr_o     = rd_addr_i;
                rd_wen_o      = rd_wen_i;
                mem_rd_addr_o = base_addr_add_addr_offset;
            end else if (is_store) begin
                mem_wd_addr_o = base_addr_add_addr_offset;
                case (func3)
                    `INST_SB: begin
                        case (base_addr_add_addr_offset[1:0])
                            2'b00: begin mem_wd_reg_o = 4'b0001; mem_wd_data_o = {24'b0, op2_i[7:0]}; end
                            2'b01: begin mem_wd_reg_o = 4'b0010; mem_wd_data_o = {16'b0, op2_i[7:0], 8'b0}; end
                            2'b10: begin mem_wd_reg_o = 4'b0100; mem_wd_data_o = {8'b0, op2_i[7:0], 16'b0}; end
                            2'b11: begin mem_wd_reg_o = 4'b1000; mem_wd_data_o = {op2_i[7:0], 24'b0}; end
                            default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                        endcase
                    end
                    `INST_SH: begin
                        case (base_addr_add_addr_offset[1])
                            1'b0: begin mem_wd_reg_o = 4'b0011; mem_wd_data_o = {16'b0, op2_i[15:0]}; end
                            1'b1: begin mem_wd_reg_o = 4'b1100; mem_wd_data_o = {op2_i[15:0], 16'b0}; end
                            default: begin mem_wd_reg_o = 4'b0000; mem_wd_data_o = 32'b0; end
                        endcase
                    end
                    `INST_SW: begin
                        mem_wd_reg_o  = 4'b1111;
                        mem_wd_data_o = op2_i;
                    end
                    default: begin
                        mem_wd_reg_o  = 4'b0000;
                        mem_wd_data_o = 32'b0;
                    end
                endcase
            end else if (is_jal) begin
                rd_data_o = op1_i_add_op2_i;
                rd_addr_o = rd_addr_i;
                rd_wen_o  = rd_wen_i;

                if (is_call_jal) begin
                    bp_ras_push_en_o   = 1'b1;
                    bp_ras_push_addr_o = fallthrough_addr;
                end

                if (pred_taken_i == 1'b0) begin
                    jump_en_o   = 1'b1;
                    jump_addr_o = pc_relative_jump_addr;
                end
            end else if (is_jalr) begin
                rd_data_o   = inst_addr_i + 32'd4;
                rd_addr_o   = rd_addr_i;
                rd_wen_o    = rd_wen_i;
                jump_addr_o = base_addr_add_addr_offset & ~32'd1;

                if (ras_should_push_jalr) begin
                    bp_ras_push_en_o   = 1'b1;
                    bp_ras_push_addr_o = fallthrough_addr;
                end

                if (ras_should_pop_jalr) begin
                    bp_ras_pop_en_o = 1'b1;
                end

                if (ras_predicted_jalr) begin
                    if ((pred_taken_i == 1'b0) || (pred_target_i != (base_addr_add_addr_offset & ~32'd1))) begin
                        jump_en_o = 1'b1;
                    end
                end else begin
                    jump_en_o = 1'b1;
                end
            end else if (is_auipc) begin
                rd_data_o = op1_i_add_op2_i;
                rd_addr_o = rd_addr_i;
                rd_wen_o  = rd_wen_i;
            end else if (is_lui) begin
                rd_data_o = op1_i;
                rd_addr_o = rd_addr_i;
                rd_wen_o  = rd_wen_i;
            end else begin
                rd_addr_o = 5'b0;
                rd_data_o = 32'b0;
                rd_wen_o  = 1'b0;
            end
        end
    end

endmodule
