`timescale 1ns / 1ps
`ifndef DRAM_CACHE_V
`define DRAM_CACHE_V
`ifndef INST_LB
`include "defines.v"
`endif

// ============================================================================
// 简单直接映射 DRAM load cache
// ----------------------------------------------------------------------------
// 只缓存 DRAM 区域的 load word，用于降低重复 load 延迟：
//   - MEM1 用 ex_load_addr_i 提前发起同步读；
//   - MEM2 在 miss 后用 RAM 返回数据 refill；
//   - store 命中缓存时按字节更新对应 cache line；
//   - store 与 refill 同 index 时，refill 优先，避免同拍双写同一行产生不确定行为。
//
// 本缓存不是一致性完整的数据缓存，只服务本流水线内 DRAM load 加速。
// ============================================================================
module dram_cache #(
    parameter [31:0] DRAM_ADDR_START = 32'h8010_0000,
    parameter [31:0] DRAM_ADDR_END   = 32'h8014_0000,
    parameter integer INDEX_BITS = 6
) (
    input  wire        clk,
    input  wire        rst,

    input  wire [31:0] ex_load_addr_i,

    input  wire        mem1_is_load_i,
    input  wire        mem1_load_hits_dram_i,
    input  wire [31:0] mem1_inst_i,
    input  wire [31:0] mem1_load_addr_i,
    input  wire [31:0] mem1_uncached_rd_data_i,
    input  wire        mem1_store_load_fwd_valid_i,
    input  wire [3:0]  mem1_store_load_fwd_wstrb_i,
    input  wire [31:0] mem1_store_load_fwd_data_i,

    input  wire        mem2_is_load_i,
    input  wire        mem2_load_hits_dram_i,
    input  wire        mem2_load_cache_hit_i,
    input  wire [31:0] mem2_load_addr_i,
    input  wire [31:0] mem2_ram_data_i,
    input  wire        mem2_store_load_fwd_valid_i,
    input  wire [3:0]  mem2_store_load_fwd_wstrb_i,
    input  wire [31:0] mem2_store_load_fwd_data_i,

    input  wire [3:0]  store_wstrb_i,
    input  wire [31:0] store_addr_i,
    input  wire [31:0] store_data_i,

    output wire        mem1_load_cache_hit_o,
    output wire [31:0] mem1_rd_data_o
);
    localparam integer LINES = (1 << INDEX_BITS);
    localparam integer TAG_BITS = 32 - INDEX_BITS - 2;

    // 按 byte write strobe 合并 store 数据，用于 store hit 更新和 refill 后覆盖。
    function [31:0] merge_store_word;
        input [31:0] old_word;
        input [31:0] store_data;
        input [3:0]  wstrb;
        reg [31:0] mask;
        begin
            mask = {{8{wstrb[3]}}, {8{wstrb[2]}}, {8{wstrb[1]}}, {8{wstrb[0]}}};
            merge_store_word = (old_word & ~mask) | (store_data & mask);
        end
    endfunction

    // 根据 load 指令类型和地址低位完成字节/半字选择与符号扩展。
    function [31:0] align_load_word;
        input [31:0] inst;
        input [31:0] addr;
        input [31:0] word;
        begin
            case (inst[14:12])
                `INST_LB: begin
                    case (addr[1:0])
                        2'b00: align_load_word = {{24{word[7]}},  word[7:0]};
                        2'b01: align_load_word = {{24{word[15]}}, word[15:8]};
                        2'b10: align_load_word = {{24{word[23]}}, word[23:16]};
                        default: align_load_word = {{24{word[31]}}, word[31:24]};
                    endcase
                end
                `INST_LH: begin
                    if (addr[1] == 1'b0) begin
                        align_load_word = {{16{word[15]}}, word[15:0]};
                    end else begin
                        align_load_word = {{16{word[31]}}, word[31:16]};
                    end
                end
                `INST_LW: begin
                    align_load_word = word;
                end
                `INST_LBU: begin
                    case (addr[1:0])
                        2'b00: align_load_word = {24'b0, word[7:0]};
                        2'b01: align_load_word = {24'b0, word[15:8]};
                        2'b10: align_load_word = {24'b0, word[23:16]};
                        default: align_load_word = {24'b0, word[31:24]};
                    endcase
                end
                `INST_LHU: begin
                    if (addr[1] == 1'b0) begin
                        align_load_word = {16'b0, word[15:0]};
                    end else begin
                        align_load_word = {16'b0, word[31:16]};
                    end
                end
                default: begin
                    align_load_word = word;
                end
            endcase
        end
    endfunction

    wire [INDEX_BITS-1:0] read_idx = ex_load_addr_i[INDEX_BITS+1:2];

    wire [INDEX_BITS-1:0] store_idx = store_addr_i[INDEX_BITS+1:2];
    wire [TAG_BITS-1:0]   store_tag = store_addr_i[31:INDEX_BITS+2];
    wire store_hits_dram =
        (store_addr_i >= DRAM_ADDR_START) &&
        (store_addr_i <  DRAM_ADDR_END);
    wire store_req = (|store_wstrb_i) && store_hits_dram;

    wire [INDEX_BITS-1:0] refill_idx = mem2_load_addr_i[INDEX_BITS+1:2];
    wire [TAG_BITS-1:0]   refill_tag = mem2_load_addr_i[31:INDEX_BITS+2];
    wire [3:0] refill_wstrb =
        mem2_store_load_fwd_valid_i ? mem2_store_load_fwd_wstrb_i : 4'b0000;
    wire [31:0] refill_word =
        merge_store_word(mem2_ram_data_i, mem2_store_load_fwd_data_i, refill_wstrb);
    wire refill_req =
        mem2_is_load_i &&
        mem2_load_hits_dram_i &&
        !mem2_load_cache_hit_i;

    (* ram_style = "block" *) reg [31:0] data_array [0:LINES-1];
    (* ram_style = "distributed" *) reg [TAG_BITS-1:0] tag_array [0:LINES-1];
    reg valid_array [0:LINES-1];

    reg [31:0] read_data_r;
    reg [TAG_BITS-1:0] read_tag_r;
    reg read_valid_r;
    integer i;
    // store 命中已缓存行时，需要同步更新 data_array，避免后续 load 读到旧值。
    wire store_hit =
        store_req &&
        valid_array[store_idx] &&
        (tag_array[store_idx] == store_tag);
    // refill 与 store hit 同 index 同拍发生时只执行 refill 写。
    // refill_word 已经融合 MEM2 store-load 前递数据，避免双写同一数组元素。
    wire refill_store_same_idx =
        refill_req &&
        (refill_idx == store_idx);
    wire data_write_refill = refill_req;
    wire data_write_store_hit = store_hit && !refill_store_same_idx;

    // data/tag/valid 为同步读：MEM1 当拍使用的是上一拍 ex_load_addr_i 的读出结果。
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            read_data_r  <= 32'b0;
            read_tag_r   <= {TAG_BITS{1'b0}};
            read_valid_r <= 1'b0;
        end else begin
            read_data_r  <= data_array[read_idx];
            read_tag_r   <= tag_array[read_idx];
            read_valid_r <= valid_array[read_idx];
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            for (i = 0; i < LINES; i = i + 1) begin
                valid_array[i] <= 1'b0;
            end
        end else if (refill_req) begin
            valid_array[refill_idx] <= 1'b1;
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b1 && refill_req) begin
            tag_array[refill_idx] <= refill_tag;
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b1) begin
            if (data_write_refill) begin
                data_array[refill_idx] <= refill_word;
            end
            if (data_write_store_hit) begin
                data_array[store_idx] <=
                    merge_store_word(data_array[store_idx], store_data_i, store_wstrb_i);
            end
        end
    end

    // MEM1 命中要求：当前是 DRAM load、有效位为 1，且 tag 与 load 地址匹配。
    assign mem1_load_cache_hit_o =
        mem1_is_load_i &&
        mem1_load_hits_dram_i &&
        read_valid_r &&
        (read_tag_r == mem1_load_addr_i[31:INDEX_BITS+2]);

    wire [3:0] mem1_fwd_wstrb =
        mem1_store_load_fwd_valid_i ? mem1_store_load_fwd_wstrb_i : 4'b0000;
    wire [31:0] mem1_cache_word =
        merge_store_word(read_data_r, mem1_store_load_fwd_data_i, mem1_fwd_wstrb);
    wire [31:0] mem1_cache_load_data =
        align_load_word(mem1_inst_i, mem1_load_addr_i, mem1_cache_word);

    assign mem1_rd_data_o =
        mem1_load_cache_hit_o ? mem1_cache_load_data : mem1_uncached_rd_data_i;

endmodule
`endif
