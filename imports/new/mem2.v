`timescale 1ns / 1ps
`include "defines.v"

module mem2 (
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire        is_load_i,
    input  wire        load_cache_hit_i,
    input  wire [31:0] mem_rd_data_i,
    input  wire        store_load_fwd_valid_i,
    input  wire [3:0]  store_load_fwd_wstrb_i,
    input  wire [31:0] store_load_fwd_data_i,

    output wire [31:0] inst_o,
    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o
);

    wire [2:0] func3 = inst_i[14:12];

    // 将 valid 局部编码进字节写掩码，后续 4 条 byte mux 只使用本地掩码位。
    // 上游 MEM1/MEM2 已经为 MEM2 路径提供独立 valid 寄存副本。
    wire [3:0] store_load_fwd_wstrb_eff =
        store_load_fwd_valid_i ? store_load_fwd_wstrb_i : 4'b0000;

    wire fwd_b0 = store_load_fwd_wstrb_eff[0];
    wire fwd_b1 = store_load_fwd_wstrb_eff[1];
    wire fwd_b2 = store_load_fwd_wstrb_eff[2];
    wire fwd_b3 = store_load_fwd_wstrb_eff[3];

    wire [7:0] load_byte0 = fwd_b0 ? store_load_fwd_data_i[7:0]   : mem_rd_data_i[7:0];
    wire [7:0] load_byte1 = fwd_b1 ? store_load_fwd_data_i[15:8]  : mem_rd_data_i[15:8];
    wire [7:0] load_byte2 = fwd_b2 ? store_load_fwd_data_i[23:16] : mem_rd_data_i[23:16];
    wire [7:0] load_byte3 = fwd_b3 ? store_load_fwd_data_i[31:24] : mem_rd_data_i[31:24];
    wire [31:0] load_word = {load_byte3, load_byte2, load_byte1, load_byte0};
    wire [7:0] load_byte =
        (mem_rd_addr_i[1:0] == 2'b00) ? load_word[7:0]   :
        (mem_rd_addr_i[1:0] == 2'b01) ? load_word[15:8]  :
        (mem_rd_addr_i[1:0] == 2'b10) ? load_word[23:16] :
                                        load_word[31:24];
    wire [15:0] load_half =
        mem_rd_addr_i[1] ? load_word[31:16] : load_word[15:0];
    wire [31:0] uncached_load_data =
        (func3 == `INST_LB)  ? {{24{load_byte[7]}}, load_byte}  :
        (func3 == `INST_LH)  ? {{16{load_half[15]}}, load_half} :
        (func3 == `INST_LW)  ? load_word                         :
        (func3 == `INST_LBU) ? {24'b0, load_byte}               :
        (func3 == `INST_LHU) ? {16'b0, load_half}               :
                               32'b0;
    wire [31:0] load_result =
        load_cache_hit_i ? rd_data_i : uncached_load_data;

    assign rd_addr_o = rd_addr_i;
    assign rd_wen_o  = rd_wen_i;
    assign inst_o    = inst_i;
    assign rd_data_o = is_load_i ? load_result : rd_data_i;

endmodule
