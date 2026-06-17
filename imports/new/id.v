`include "defines.v"

module id (
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,

    output wire [4:0]  rs1_addr_o,
    output wire [4:0]  rs2_addr_o,
    input  wire [31:0] rs1_data_i,
    input  wire [31:0] rs2_data_i,

    output reg  [31:0] inst_o,
    output reg  [31:0] inst_addr_o,
    output reg  [31:0] op1_o,
    output reg  [31:0] op2_o,
    output reg  [31:0] cmp_op2_o,
    output reg  [31:0] store_data_o,
    output wire [4:0]  rd_addr_o,
    output reg         reg_wen,
    output reg  [31:0] base_addr_o,
    output reg  [31:0] branch_offset_o,
    output reg  [31:0] mem_offset_o,
    output reg  [31:0] jump_offset_o,
    output reg         mem_rd_reg_o,
    output wire        is_branch_o,
    output wire        use_rs1_o,
    output wire        use_rs2_o,
    output wire        use_base_addr_o
);

    wire [6:0]  opcode = inst_i[6:0];
    wire [4:0]  rd     = inst_i[11:7];
    wire [6:0]  func7  = inst_i[31:25];
    wire [2:0]  func3  = inst_i[14:12];
    wire [4:0]  rs1    = inst_i[19:15];
    wire [4:0]  rs2    = inst_i[24:20];
    wire [11:0] imm    = inst_i[31:20];
    wire [4:0]  shamt  = imm[4:0];

    wire system_use_rs1 = (opcode == `INST_SYSTEM) &&
                          ((func3 == `INST_CSRRW) || (func3 == `INST_CSRRS) || (func3 == `INST_CSRRC));

    assign rs1_addr_o = rs1;
    assign rs2_addr_o = rs2;
    assign rd_addr_o  = rd;
    assign is_branch_o = (opcode == `INST_TYPE_B);

    assign use_rs1_o = (opcode == `INST_TYPE_I)   ||
                       (opcode == `INST_TYPE_R_M) ||
                       (opcode == `INST_TYPE_B)   ||
                       (opcode == `INST_TYPE_L)   ||
                       (opcode == `INST_TYPE_S)   ||
                       (opcode == `INST_JALR)     ||
                       system_use_rs1;

    assign use_rs2_o = (opcode == `INST_TYPE_R_M) ||
                       (opcode == `INST_TYPE_B)   ||
                       (opcode == `INST_TYPE_S);

    assign use_base_addr_o = (opcode == `INST_TYPE_L) ||
                             (opcode == `INST_TYPE_S) ||
                             (opcode == `INST_JALR);

    always @(*) begin
        inst_o        = inst_i;
        inst_addr_o   = inst_addr_i;
        op1_o         = 32'b0;
        op2_o         = 32'b0;
        cmp_op2_o     = 32'b0;
        store_data_o  = 32'b0;
        reg_wen       = 1'b0;
        base_addr_o   = 32'b0;
        branch_offset_o = 32'b0;
        mem_offset_o    = 32'b0;
        jump_offset_o   = 32'b0;
        mem_rd_reg_o  = 1'b0;

        case (opcode)
            `INST_TYPE_I: begin
                case (func3)
                    `INST_ADDI, `INST_SLTI, `INST_SLTIU,
                    `INST_ORI, `INST_XORI, `INST_ANDI: begin
                        op1_o   = rs1_data_i;
                        op2_o   = {{20{imm[11]}}, imm};
                        cmp_op2_o = {{20{imm[11]}}, imm};
                        reg_wen = 1'b1;
                    end
                    `INST_SLLI, `INST_SRI: begin
                        op1_o   = rs1_data_i;
                        op2_o   = {27'b0, shamt};
                        reg_wen = 1'b1;
                    end
                    default: begin
                    end
                endcase
            end

            `INST_TYPE_R_M: begin
                case (func3)
                    `INST_ADD_SUB, `INST_SLL, `INST_SLT, `INST_SLTU,
                    `INST_XOR, `INST_SR, `INST_OR, `INST_AND: begin
                        op1_o     = rs1_data_i;
                        op2_o     = rs2_data_i;       // 保留完整 rs2
                        cmp_op2_o = rs2_data_i;
                        reg_wen   = 1'b1;
                    end
                    default: begin
                    end
                endcase
            end

            `INST_TYPE_B: begin
                case (func3)
                    `INST_BNE, `INST_BEQ, `INST_BLT,
                    `INST_BGE, `INST_BLTU, `INST_BGEU: begin
                        op1_o         = rs1_data_i;
                        cmp_op2_o     = rs2_data_i;
                        branch_offset_o = {{20{inst_i[31]}}, inst_i[7], inst_i[30:25], inst_i[11:8], 1'b0};
                    end
                    default: begin
                    end
                endcase
            end

            `INST_TYPE_L: begin
                case (func3)
                    `INST_LB, `INST_LH, `INST_LW,
                    `INST_LBU, `INST_LHU: begin
                        reg_wen       = 1'b1;
                        base_addr_o   = rs1_data_i;
                        mem_offset_o  = {{20{imm[11]}}, imm};
                        mem_rd_reg_o  = 1'b1;
                    end
                    default: begin
                    end
                endcase
            end

            `INST_TYPE_S: begin
                case (func3)
                    `INST_SB, `INST_SH, `INST_SW: begin
                        store_data_o  = rs2_data_i;
                        base_addr_o   = rs1_data_i;
                        mem_offset_o  = {{20{inst_i[31]}}, inst_i[31:25], inst_i[11:7]};
                    end
                    default: begin
                    end
                endcase
            end

            `INST_JAL: begin
                op1_o         = inst_addr_i;
                op2_o         = 32'd4;
                reg_wen       = 1'b1;
                jump_offset_o = {{12{inst_i[31]}}, inst_i[19:12], inst_i[20], inst_i[30:21], 1'b0};
            end

            `INST_JALR: begin
                op1_o         = inst_addr_i;
                op2_o         = 32'd4;
                reg_wen       = 1'b1;
                base_addr_o   = rs1_data_i;
                jump_offset_o = {{20{imm[11]}}, imm};
            end

            `INST_AUIPC: begin
                op1_o   = inst_addr_i;
                op2_o   = {inst_i[31:12], 12'b0};
                reg_wen = 1'b1;
            end

            `INST_LUI: begin
                op1_o   = {inst_i[31:12], 12'b0};
                reg_wen = 1'b1;
            end

            `INST_SYSTEM: begin
                case (func3)
                    `INST_CSRRW, `INST_CSRRS, `INST_CSRRC: begin
                        op1_o   = rs1_data_i;
                        reg_wen = 1'b1;
                    end
                    `INST_CSRRWI, `INST_CSRRSI, `INST_CSRRCI: begin
                        op1_o   = {27'b0, rs1};
                        reg_wen = 1'b1;
                    end
                    default: begin
                    end
                endcase
            end

            default: begin
            end
        endcase
    end

endmodule
