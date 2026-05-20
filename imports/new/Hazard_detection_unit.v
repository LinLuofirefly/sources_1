`include "defines.v"

module Hazard_detection_unit (
    input  wire [4:0]  id_rs1_addr_i,
    input  wire [4:0]  id_rs2_addr_i,

    input  wire        id_is_branch_i,
    input  wire        id_is_jalr_i,

    input  wire        id_use_rs1_i,
    input  wire        id_use_rs2_i,
    input wire ex_done_i,
    input  wire [31:0] ex_inst_i,
    input  wire [31:0] mem1_inst_i,
    input  wire [31:0] mem1_mem2_inst_i,
    input  wire [31:0] mem2a_inst_i,
    input  wire [31:0] mem2_inst_i,
    input  wire [31:0] mem_wb_inst_i,

    input  wire        mem2a_is_slow_load_i,
    input  wire        mem2_is_slow_load_i,

    input  wire        ex_busy_i,

    output reg         branch_ex_stall_o,
    (* max_fanout = 32 *) output reg hold_flag_o,
    (* max_fanout = 32 *) output reg flush_flag_o
);
    wire [6:0] ex_opcode        = ex_inst_i[6:0];
    wire [4:0] ex_rd            = ex_inst_i[11:7];

    wire [6:0] mem1_opcode      = mem1_inst_i[6:0];
    wire [4:0] mem1_rd          = mem1_inst_i[11:7];

    wire [6:0] mem1_mem2_opcode = mem1_mem2_inst_i[6:0];
    wire [4:0] mem1_mem2_rd     = mem1_mem2_inst_i[11:7];

    wire [6:0] mem2a_opcode     = mem2a_inst_i[6:0];
    wire [4:0] mem2a_rd         = mem2a_inst_i[11:7];

    wire [6:0] mem2_opcode      = mem2_inst_i[6:0];
    wire [4:0] mem2_rd          = mem2_inst_i[11:7];

    wire [6:0] mem_wb_opcode    = mem_wb_inst_i[6:0];
    wire [4:0] mem_wb_rd        = mem_wb_inst_i[11:7];

    // ================================================================
    // rd write detection
    // ================================================================

    wire ex_writes_rd =
        (ex_rd != 5'b0) &&
        (ex_opcode != `INST_TYPE_S) &&
        (ex_opcode != `INST_TYPE_B);

    wire mem1_writes_rd =
        (mem1_rd != 5'b0) &&
        (mem1_opcode != `INST_TYPE_S) &&
        (mem1_opcode != `INST_TYPE_B);

    wire mem1_mem2_writes_rd =
        (mem1_mem2_rd != 5'b0) &&
        (mem1_mem2_opcode != `INST_TYPE_S) &&
        (mem1_mem2_opcode != `INST_TYPE_B);

    wire mem2a_writes_rd =
        (mem2a_rd != 5'b0) &&
        (mem2a_opcode != `INST_TYPE_S) &&
        (mem2a_opcode != `INST_TYPE_B);

    wire mem2_writes_rd =
        (mem2_rd != 5'b0) &&
        (mem2_opcode != `INST_TYPE_S) &&
        (mem2_opcode != `INST_TYPE_B);

    wire mem_wb_writes_rd =
        (mem_wb_rd != 5'b0) &&
        (mem_wb_opcode != `INST_TYPE_S) &&
        (mem_wb_opcode != `INST_TYPE_B);

    // ================================================================
    // Normal dependency match
    // ================================================================

    wire ex_dep_match =
        ex_writes_rd &&
        ((id_use_rs1_i && (ex_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (ex_rd == id_rs2_addr_i)));

    wire mem1_dep_match =
        mem1_writes_rd &&
        ((id_use_rs1_i && (mem1_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem1_rd == id_rs2_addr_i)));

    wire mem1_mem2_dep_match =
        mem1_mem2_writes_rd &&
        ((id_use_rs1_i && (mem1_mem2_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem1_mem2_rd == id_rs2_addr_i)));

    wire mem2a_dep_match =
        mem2a_writes_rd &&
        ((id_use_rs1_i && (mem2a_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem2a_rd == id_rs2_addr_i)));

    wire mem2_dep_match =
        mem2_writes_rd &&
        ((id_use_rs1_i && (mem2_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem2_rd == id_rs2_addr_i)));

    wire mem_wb_dep_match =
        mem_wb_writes_rd &&
        ((id_use_rs1_i && (mem_wb_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem_wb_rd == id_rs2_addr_i)));

    // ================================================================
    // Load-use dependency
    // ================================================================

    wire ex_load_dep =
        (ex_opcode == `INST_TYPE_L) &&
        ex_dep_match;

    wire mem1_load_dep =
        (mem1_opcode == `INST_TYPE_L) &&
        mem1_dep_match;

    wire mem1_mem2_load_dep =
        (mem1_mem2_opcode == `INST_TYPE_L) &&
        mem1_mem2_dep_match;

    wire mem2a_slow_load_dep =
        mem2a_is_slow_load_i &&
        (mem2a_opcode == `INST_TYPE_L) &&
        mem2a_dep_match;

    wire mem2_slow_load_dep =
        mem2_is_slow_load_i &&
        (mem2_opcode == `INST_TYPE_L) &&
        mem2_dep_match;

    // ================================================================
    // Control dependency
    //
    // Branch compare and JALR/RET base do not use forwarding.
    // Therefore control instructions must stay in ID until the needed
    // operands are safely readable from regfile.
    // ================================================================

    wire id_is_control =
        id_is_branch_i | id_is_jalr_i;

    wire control_late_dep =
        id_is_control &&
        (ex_dep_match ||
         mem1_dep_match ||
         mem1_mem2_dep_match ||
         mem2a_dep_match ||
         mem2_dep_match ||
         mem_wb_dep_match);

    always @(*) begin
        branch_ex_stall_o = 1'b0;
        hold_flag_o       = 1'b0;
        flush_flag_o      = 1'b0;

        if (ex_busy_i == 1'b1) begin
            hold_flag_o = 1'b1;
        end
        if (ex_done_i == 1'b1) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end
        if (ex_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem1_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem1_mem2_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem2a_slow_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem2_slow_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (control_late_dep) begin
            branch_ex_stall_o = id_is_branch_i;
            hold_flag_o       = 1'b1;
            flush_flag_o      = 1'b1;
        end
    end
endmodule
