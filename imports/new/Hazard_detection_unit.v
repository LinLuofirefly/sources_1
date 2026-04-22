`include "defines.v"

module Hazard_detection_unit (
    input  wire [31:0] id_inst_i,
    input  wire [31:0] ex_inst_i,
    input  wire [31:0] mem1_inst_i,
    input  wire [31:0] mem1_mem2_inst_i,
    input  wire [31:0] mem2a_inst_i,
    input  wire [31:0] mem2_inst_i,
    output reg         hold_flag_o,
    output reg         flush_flag_o
);

    wire [6:0] id_opcode    = id_inst_i[6:0];
    wire [4:0] id_rs1       = id_inst_i[19:15];
    wire [4:0] id_rs2       = id_inst_i[24:20];

    wire [6:0] ex_opcode    = ex_inst_i[6:0];
    wire [4:0] ex_rd        = ex_inst_i[11:7];

    wire [6:0] mem1_opcode  = mem1_inst_i[6:0];
    wire [4:0] mem1_rd      = mem1_inst_i[11:7];

    wire [6:0] mem1_mem2_opcode = mem1_mem2_inst_i[6:0];
    wire [4:0] mem1_mem2_rd     = mem1_mem2_inst_i[11:7];

    wire [6:0] mem2a_opcode = mem2a_inst_i[6:0];
    wire [4:0] mem2a_rd     = mem2a_inst_i[11:7];

    wire [6:0] mem2_opcode  = mem2_inst_i[6:0];
    wire [4:0] mem2_rd      = mem2_inst_i[11:7];

    wire id_use_rs1 = (id_opcode == `INST_TYPE_R_M) ||
                      (id_opcode == `INST_TYPE_I)   ||
                      (id_opcode == `INST_TYPE_S)   ||
                      (id_opcode == `INST_TYPE_B)   ||
                      (id_opcode == `INST_TYPE_L)   ||
                      (id_opcode == `INST_JALR);

    wire id_use_rs2 = (id_opcode == `INST_TYPE_R_M) ||
                      (id_opcode == `INST_TYPE_S)   ||
                      (id_opcode == `INST_TYPE_B);

    wire ex_conflict =
        (ex_opcode == `INST_TYPE_L) && (ex_rd != 5'b0) &&
        ((id_use_rs1 && (ex_rd == id_rs1)) || (id_use_rs2 && (ex_rd == id_rs2)));

    wire mem1_conflict =
        (mem1_opcode == `INST_TYPE_L) && (mem1_rd != 5'b0) &&
        ((id_use_rs1 && (mem1_rd == id_rs1)) || (id_use_rs2 && (mem1_rd == id_rs2)));

    wire mem1_mem2_conflict =
        (mem1_mem2_opcode == `INST_TYPE_L) && (mem1_mem2_rd != 5'b0) &&
        ((id_use_rs1 && (mem1_mem2_rd == id_rs1)) || (id_use_rs2 && (mem1_mem2_rd == id_rs2)));

    wire mem2a_conflict =
        (mem2a_opcode == `INST_TYPE_L) && (mem2a_rd != 5'b0) &&
        ((id_use_rs1 && (mem2a_rd == id_rs1)) || (id_use_rs2 && (mem2a_rd == id_rs2)));

    wire mem2_conflict =
        (mem2_opcode == `INST_TYPE_L) && (mem2_rd != 5'b0) &&
        ((id_use_rs1 && (mem2_rd == id_rs1)) || (id_use_rs2 && (mem2_rd == id_rs2)));

    always @(*) begin
        hold_flag_o  = 1'b0;
        flush_flag_o = 1'b0;

        if (ex_conflict || mem1_conflict || mem1_mem2_conflict || mem2a_conflict || mem2_conflict) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end
    end

endmodule
