`include "defines.v"

module ex (
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    input  wire        pred_taken_i,
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
    output reg         bp_actual_taken_o
);

    wire [6:0] opcode = inst_i[6:0];
    wire [2:0] func3  = inst_i[14:12];
    wire [6:0] func7  = inst_i[31:25];
    wire [4:0] shamt  = op2_i[4:0];

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
    wire [31:0] fallthrough_addr          = inst_addr_i + 32'd4;

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
        bp_actual_taken_o  = 1'b0;
        branch_taken_r     = 1'b0;

        if (kill_i == 1'b0) begin
            case (opcode)
                `INST_TYPE_I: begin
                    case (func3)
                        `INST_ADDI:  rd_data_o = op1_i_add_op2_i;
                        `INST_SLTI:  rd_data_o = {31'b0, op1_i_less_op2_i_signed};
                        `INST_SLTIU: rd_data_o = {31'b0, op1_i_less_op2_i_unsigned};
                        `INST_ANDI:  rd_data_o = op1_i_and_op2_i;
                        `INST_ORI:   rd_data_o = op1_i_or_op2_i;
                        `INST_XORI:  rd_data_o = op1_i_xor_op2_i;
                        `INST_SLLI:  rd_data_o = op1_i_shift_left_op2_i;
                        `INST_SRI: begin
                            if (func7[5] == 1'b0) begin
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
                end

                `INST_TYPE_R_M: begin
                    case (func3)
                        `INST_ADD_SUB: begin
                            if (func7 == 7'b0000000) begin
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
                            if (func7[5] == 1'b0) begin
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
                end

                `INST_TYPE_B: begin
                    case (func3)
                        `INST_BNE:  branch_taken_r = ~op1_i_equal_op2_i;
                        `INST_BEQ:  branch_taken_r = op1_i_equal_op2_i;
                        `INST_BLT:  branch_taken_r = op1_i_less_op2_i_signed;
                        `INST_BGE:  branch_taken_r = ~op1_i_less_op2_i_signed;
                        `INST_BLTU: branch_taken_r = op1_i_less_op2_i_unsigned;
                        `INST_BGEU: branch_taken_r = ~op1_i_less_op2_i_unsigned;
                        default:    branch_taken_r = 1'b0;
                    endcase

                    bp_update_en_o    = 1'b1;
                    bp_update_pc_o    = inst_addr_i;
                    bp_actual_taken_o = branch_taken_r;

                    if (branch_taken_r != pred_taken_i) begin
                        jump_en_o   = 1'b1;
                        jump_addr_o = branch_taken_r ? base_addr_add_addr_offset : fallthrough_addr;
                    end
                end

                `INST_TYPE_L: begin
                    is_load_o     = 1'b1;
                    rd_addr_o     = rd_addr_i;
                    rd_wen_o      = rd_wen_i;
                    mem_rd_addr_o = base_addr_add_addr_offset;
                end

                `INST_TYPE_S: begin
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
                end

                `INST_JAL: begin
                    rd_data_o = op1_i_add_op2_i;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;

                    if (pred_taken_i == 1'b0) begin
                        jump_addr_o = base_addr_add_addr_offset;
                        jump_en_o   = 1'b1;
                    end
                end

                `INST_JALR: begin
                    rd_data_o   = inst_addr_i + 32'd4;
                    rd_addr_o   = rd_addr_i;
                    rd_wen_o    = rd_wen_i;
                    jump_addr_o = base_addr_add_addr_offset & ~32'd1;
                    jump_en_o   = 1'b1;
                end

                `INST_AUIPC: begin
                    rd_data_o = op1_i_add_op2_i;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
                end

                `INST_LUI: begin
                    rd_data_o = op1_i;
                    rd_addr_o = rd_addr_i;
                    rd_wen_o  = rd_wen_i;
                end

                default: begin
                    rd_addr_o = 5'b0;
                    rd_data_o = 32'b0;
                    rd_wen_o  = 1'b0;
                end
            endcase
        end
    end

endmodule
