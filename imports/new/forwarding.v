`include "defines.v"

module forwarding (
    input  wire [31:0] id_ex_inst_i,
    input  wire [31:0] id_ex_op1_i,
    input  wire [31:0] id_ex_op2_i,
    input  wire [31:0] id_ex_base_addr_i,
    input  wire [31:0] id_ex_addr_offset_i,

    input  wire [4:0]  ex_mem_rd_addr_i,
    input  wire [31:0] ex_mem_rd_data_i,
    input  wire        ex_mem_rd_wen_i,
    input  wire        ex_mem_is_load_i,

    input  wire [4:0]  mem1_mem2_rd_addr_i,
    input  wire [31:0] mem1_mem2_rd_data_i,
    input  wire        mem1_mem2_rd_wen_i,

    input  wire [4:0]  mem2_rd_addr_i,
    input  wire [31:0] mem2_rd_data_i,
    input  wire        mem2_rd_wen_i,

    input  wire [4:0]  mem_wb_rd_addr_i,
    input  wire [31:0] mem_wb_rd_data_i,
    input  wire        mem_wb_rd_wen_i,

    output reg  [31:0] fwd_op1_o,
    output reg  [31:0] fwd_op2_o,
    output reg  [31:0] fwd_base_addr_o,
    output reg  [31:0] fwd_addr_offset_o
);

    wire [6:0] opcode = id_ex_inst_i[6:0];
    wire [4:0] rs1    = id_ex_inst_i[19:15];
    wire [4:0] rs2    = id_ex_inst_i[24:20];

    wire use_rs1 = (opcode == `INST_TYPE_I)   ||
                   (opcode == `INST_TYPE_R_M) ||
                   (opcode == `INST_TYPE_B)   ||
                   (opcode == `INST_TYPE_L)   ||
                   (opcode == `INST_TYPE_S)   ||
                   (opcode == `INST_JALR);

    wire use_rs2 = (opcode == `INST_TYPE_R_M) ||
                   (opcode == `INST_TYPE_B)   ||
                   (opcode == `INST_TYPE_S);

    wire use_base_addr = (opcode == `INST_TYPE_L) ||
                         (opcode == `INST_TYPE_S) ||
                         (opcode == `INST_JALR);

    always @(*) begin
        if (use_rs1 && (rs1 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs1) && !ex_mem_is_load_i) begin
            fwd_op1_o = ex_mem_rd_data_i;
        end else if (use_rs1 && (rs1 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs1)) begin
            fwd_op1_o = mem1_mem2_rd_data_i;
        end else if (use_rs1 && (rs1 != 5'b0) && mem2_rd_wen_i && (mem2_rd_addr_i == rs1)) begin
            fwd_op1_o = mem2_rd_data_i;
        end else if (use_rs1 && (rs1 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs1)) begin
            fwd_op1_o = mem_wb_rd_data_i;
        end else begin
            fwd_op1_o = id_ex_op1_i;
        end

        if (use_rs2 && (rs2 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs2) && !ex_mem_is_load_i) begin
            fwd_op2_o = ex_mem_rd_data_i;
        end else if (use_rs2 && (rs2 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs2)) begin
            fwd_op2_o = mem1_mem2_rd_data_i;
        end else if (use_rs2 && (rs2 != 5'b0) && mem2_rd_wen_i && (mem2_rd_addr_i == rs2)) begin
            fwd_op2_o = mem2_rd_data_i;
        end else if (use_rs2 && (rs2 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs2)) begin
            fwd_op2_o = mem_wb_rd_data_i;
        end else begin
            fwd_op2_o = id_ex_op2_i;
        end

        if (use_base_addr && (rs1 != 5'b0) && ex_mem_rd_wen_i && (ex_mem_rd_addr_i == rs1) && !ex_mem_is_load_i) begin
            fwd_base_addr_o = ex_mem_rd_data_i;
        end else if (use_base_addr && (rs1 != 5'b0) && mem1_mem2_rd_wen_i && (mem1_mem2_rd_addr_i == rs1)) begin
            fwd_base_addr_o = mem1_mem2_rd_data_i;
        end else if (use_base_addr && (rs1 != 5'b0) && mem2_rd_wen_i && (mem2_rd_addr_i == rs1)) begin
            fwd_base_addr_o = mem2_rd_data_i;
        end else if (use_base_addr && (rs1 != 5'b0) && mem_wb_rd_wen_i && (mem_wb_rd_addr_i == rs1)) begin
            fwd_base_addr_o = mem_wb_rd_data_i;
        end else begin
            fwd_base_addr_o = id_ex_base_addr_i;
        end

        fwd_addr_offset_o = id_ex_addr_offset_i;
    end

endmodule
