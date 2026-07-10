`timescale 1ns / 1ps

module early_forwarding_select (
    input  wire [4:0] id_rs1_addr_i,
    input  wire [4:0] id_rs2_addr_i,
    input  wire       id_use_rs1_i,
    input  wire       id_use_rs2_i,
    input  wire       id_use_base_addr_i,

    input  wire [4:0] ex_rd_addr_i,
    input  wire       ex_rd_wen_i,
    input  wire       ex_is_load_i,

    input  wire [4:0] mem1_rd_addr_i,
    input  wire       mem1_rd_wen_i,
    input  wire       mem1_is_load_i,
    input  wire       mem1_load_cache_hit_i,

    input  wire [4:0] mem2_rd_addr_i,
    input  wire       mem2_rd_wen_i,
    input  wire       mem2_is_slow_load_i,

    output wire [2:0] rs1_fwd_sel_o,
    output wire [2:0] rs2_fwd_sel_o
);

    localparam [2:0] FWD_REG       = 3'd0;
    localparam [2:0] FWD_EX_MEM    = 3'd1;
    localparam [2:0] FWD_MEM1_MEM2 = 3'd2;
    localparam [2:0] FWD_MEM_WB    = 3'd4;

    wire rs1_forward_allowed = id_use_rs1_i | id_use_base_addr_i;
    wire rs2_forward_allowed = id_use_rs2_i;

    // Current EX becomes EX/MEM for the consumer's next-cycle EX stage.
    wire rs1_match_ex =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        ex_rd_wen_i &&
        (ex_rd_addr_i == id_rs1_addr_i) &&
        !ex_is_load_i;

    wire rs2_match_ex =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        ex_rd_wen_i &&
        (ex_rd_addr_i == id_rs2_addr_i) &&
        !ex_is_load_i;

    // Current MEM1 becomes MEM1/MEM2, and only cache-hit loads are ready there.
    wire rs1_match_mem1 =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        mem1_rd_wen_i &&
        (mem1_rd_addr_i == id_rs1_addr_i) &&
        (!mem1_is_load_i || mem1_load_cache_hit_i);

    wire rs2_match_mem1 =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        mem1_rd_wen_i &&
        (mem1_rd_addr_i == id_rs2_addr_i) &&
        (!mem1_is_load_i || mem1_load_cache_hit_i);

    // Current MEM2 becomes MEM/WB for the consumer's next-cycle EX stage.
    wire rs1_match_mem2 =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_rs1_addr_i) &&
        !mem2_is_slow_load_i;

    wire rs2_match_mem2 =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_rs2_addr_i) &&
        !mem2_is_slow_load_i;

    assign rs1_fwd_sel_o =
        rs1_match_ex   ? FWD_EX_MEM    :
        rs1_match_mem1 ? FWD_MEM1_MEM2 :
        rs1_match_mem2 ? FWD_MEM_WB    :
                         FWD_REG;

    assign rs2_fwd_sel_o =
        rs2_match_ex   ? FWD_EX_MEM    :
        rs2_match_mem1 ? FWD_MEM1_MEM2 :
        rs2_match_mem2 ? FWD_MEM_WB    :
                         FWD_REG;

endmodule
