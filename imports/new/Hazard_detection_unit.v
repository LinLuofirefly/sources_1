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

    wire [6:0] id_opcode        = id_inst_i[6:0];
    wire [4:0] id_rs1           = id_inst_i[19:15];
    wire [4:0] id_rs2           = id_inst_i[24:20];

    wire [6:0] ex_opcode        = ex_inst_i[6:0];
    wire [4:0] ex_rd            = ex_inst_i[11:7];

    wire [6:0] mem1_opcode      = mem1_inst_i[6:0];
    wire [4:0] mem1_rd          = mem1_inst_i[11:7];

    wire [6:0] mem1_mem2_opcode = mem1_mem2_inst_i[6:0];
    wire [4:0] mem1_mem2_rd     = mem1_mem2_inst_i[11:7];

    wire id_use_rs1 = (id_opcode == `INST_TYPE_R_M) ||
                      (id_opcode == `INST_TYPE_I)   ||
                      (id_opcode == `INST_TYPE_S)   ||
                      (id_opcode == `INST_TYPE_B)   ||
                      (id_opcode == `INST_TYPE_L)   ||
                      (id_opcode == `INST_JALR);

    wire id_use_rs2 = (id_opcode == `INST_TYPE_R_M) ||
                      (id_opcode == `INST_TYPE_S)   ||
                      (id_opcode == `INST_TYPE_B);

    always @(*) begin
        hold_flag_o  = 1'b0;
        flush_flag_o = 1'b0;

        if ((ex_opcode == `INST_TYPE_L) && (ex_rd != 5'b0)) begin
            if ((id_use_rs1 && (ex_rd == id_rs1)) || (id_use_rs2 && (ex_rd == id_rs2))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end

        if ((mem1_opcode == `INST_TYPE_L) && (mem1_rd != 5'b0)) begin
            if ((id_use_rs1 && (mem1_rd == id_rs1)) || (id_use_rs2 && (mem1_rd == id_rs2))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end

        if ((mem1_mem2_opcode == `INST_TYPE_L) && (mem1_mem2_rd != 5'b0)) begin
            if ((id_use_rs1 && (mem1_mem2_rd == id_rs1)) || (id_use_rs2 && (mem1_mem2_rd == id_rs2))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end
    end

endmodule
