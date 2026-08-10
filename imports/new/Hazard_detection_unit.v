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
    input  wire        ex_valid_i,
    // Late-load conditions independent of the EX address adder.
    input  wire        ex_load_late_bypass_pre_i,
    // Raw DRAM-region hit, available only after the EX address adder.
    input  wire        ex_load_hits_dram_raw_i,
    input  wire [2:0]  id_ex_rs1_fwd_sel_i,
    input  wire [2:0]  id_ex_rs2_fwd_sel_i,
    input  wire [31:0] mem1_inst_i,
    input  wire        mem1_load_cache_hit_i,
    input  wire [31:0] mem2_inst_i,

    input  wire        mem2_is_slow_load_i,

    input  wire        ex_busy_i,

   output reg hold_flag_o,
   output reg flush_flag_o,
   output wire late_load_miss_o
);
    localparam [2:0] FWD_LATE_LOAD = 3'd3;

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
        ex_valid_i &&
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

    // 当前 ID 指令如果是移位类指令，不能分配 FWD_LATE_LOAD。
    // 否则会形成 DCache BRAM -> load 对齐 -> forwarding mux ->
    // barrel shifter -> EX/MEM1 的长组合路径。这里在 EX load 与当前
    // ID shift 发生 RAW 相关时，直接走普通 load-use stall/flush 路径。
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

    wire ex_load_dep_pre =
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

    // A consumer carrying FWD_LATE_LOAD is executing beside its producer in
    // MEM1.  Cache misses kill that speculative EX result and hold the
    // consumer for one-cycle replay from MEM2.
    wire ex_uses_late_load =
        ex_valid_i &&
        ((id_ex_rs1_fwd_sel_i == FWD_LATE_LOAD) ||
         (id_ex_rs2_fwd_sel_i == FWD_LATE_LOAD));

    assign late_load_miss_o =
        ex_uses_late_load &&
        (mem1_opcode == `INST_TYPE_L) &&
        !mem1_load_cache_hit_i;

    // Split the dependency cone into an early part and the one late term
    // driven by the EX address/DRAM-range result.  Algebraically this is the
    // same as:
    //   ex_load_dep = pre & (~hits | shift)
    //               = (pre & shift) | (pre & ~shift & ~hits).
    (* keep = "true" *) wire dep_shift =
        ex_load_dep_pre & id_is_shift;
    (* keep = "true" *) wire dep_nohit =
        ex_load_dep_pre & ~id_is_shift;

    (* keep = "true" *) wire dep_early =
        dep_shift | mem1_load_dep | mem2_slow_load_dep;

    (* keep = "true" *) wire hold_early =
        (ex_busy_i & ~ex_done_i) | dep_early | late_load_miss_o;

    (* keep = "true" *) wire flush_early =
        dep_early & ~late_load_miss_o;

    // The late DRAM hit participates only in the final hold/flush LUT.
    wire dep_late_stall =
        dep_nohit &
        ~(ex_load_late_bypass_pre_i & ex_load_hits_dram_raw_i);

    always @(*) begin
        hold_flag_o = hold_early | dep_late_stall;
        flush_flag_o =
            flush_early | (dep_late_stall & ~late_load_miss_o);
    end
endmodule
