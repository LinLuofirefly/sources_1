`timescale 1ns / 1ps
`include "defines.v"

module Hazard_detection_unit (
    input  wire [31:0] id_inst_i,
    input  wire [4:0]  id_rs1_addr_i,
    input  wire [4:0]  id_rs2_addr_i,

    input  wire        id_use_rs1_i,
    input  wire        id_use_rs2_i,
    input wire ex_done_i,
    input  wire [31:0] ex_inst_i,
    input  wire [31:0] mem1_inst_i,
    input  wire        mem1_load_cache_hit_i,
    input  wire [31:0] mem2_inst_i,

    input  wire        mem2_is_slow_load_i,

    input  wire        ex_busy_i,

    (* max_fanout = 4 *) output reg hold_flag_o,
    (* max_fanout = 4 *) output reg flush_flag_o
);
    wire [6:0] id_opcode        = id_inst_i[6:0];
    wire [2:0] id_func3         = id_inst_i[14:12];
    wire [6:0] id_func7         = id_inst_i[31:25];

    wire [6:0] ex_opcode        = ex_inst_i[6:0];
    wire [4:0] ex_rd            = ex_inst_i[11:7];

    wire [6:0] mem1_opcode      = mem1_inst_i[6:0];
    wire [4:0] mem1_rd          = mem1_inst_i[11:7];


    wire [6:0] mem2_opcode      = mem2_inst_i[6:0];
    wire [4:0] mem2_rd          = mem2_inst_i[11:7];

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


    wire mem2_writes_rd =
        (mem2_rd != 5'b0) &&
        (mem2_opcode != `INST_TYPE_S) &&
        (mem2_opcode != `INST_TYPE_B);

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


    wire mem2_dep_match =
        mem2_writes_rd &&
        ((id_use_rs1_i && (mem2_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem2_rd == id_rs2_addr_i)));

    // ================================================================
    // Load-use dependency
    // ================================================================

    wire ex_load_dep =
        (ex_opcode == `INST_TYPE_L) &&
        ex_dep_match;

    wire mem1_load_dep =
        (mem1_opcode == `INST_TYPE_L) &&
        mem1_dep_match &&
        !mem1_load_cache_hit_i;


    wire mem2_slow_load_dep =
        mem2_is_slow_load_i &&
        (mem2_opcode == `INST_TYPE_L) &&
        mem2_dep_match;

    // Cache-hit load-use normally forwards from MEM2. For shift consumers,
    // that creates a MEM2 -> forwarding -> barrel shifter path, so delay only
    // this case by one cycle. Misses stay on the existing miss hold path.
    wire id_is_shift_imm =
        (id_opcode == `INST_TYPE_I) &&
        (((id_func3 == `INST_SLLI) && (id_func7 == `INST_FUNC7_R)) ||
         ((id_func3 == `INST_SRI)  &&
          ((id_func7 == `INST_FUNC7_R) || (id_func7 == `INST_FUNC7_SUB))));

    wire id_is_shift_reg =
        (id_opcode == `INST_TYPE_R_M) &&
        (((id_func3 == `INST_SLL) && (id_func7 == `INST_FUNC7_R)) ||
         ((id_func3 == `INST_SR)  &&
          ((id_func7 == `INST_FUNC7_R) || (id_func7 == `INST_FUNC7_SUB))));

    wire id_is_shift = id_is_shift_imm || id_is_shift_reg;

    wire mem1_load_shift_dep =
        mem1_load_cache_hit_i &&
        (mem1_opcode == `INST_TYPE_L) &&
        id_is_shift &&
        (mem1_rd != 5'b0) &&
        (((mem1_rd == id_rs1_addr_i)) ||
         (id_is_shift_reg && (mem1_rd == id_rs2_addr_i)));

    always @(*) begin
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

        if (mem1_load_shift_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem2_slow_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end


    end
endmodule

