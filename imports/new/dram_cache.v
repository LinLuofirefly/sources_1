`timescale 1ns / 1ps
`ifndef DRAM_CACHE_V
`define DRAM_CACHE_V
`ifndef INST_LB
`include "defines.v"
`endif

module dram_cache #(
    parameter [31:0] DRAM_ADDR_START = 32'h8010_0000,
    parameter [31:0] DRAM_ADDR_END   = 32'h8014_0000,
    parameter integer INDEX_BITS = 6
) (
    input  wire        clk,
    input  wire        rst,

    // Normal architectural read address; it may include general forwarding.
    input  wire [31:0] ex_load_addr_i,
    // Dedicated early-probe address formed only from raw base + immediate.
    input  wire [31:0] ex_fast_load_addr_i,

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
    output wire [31:0] mem1_rd_data_o,
    output wire        ex_fast_load_cache_hit_o,
    output wire        branch_fast_load_valid_o,
    output wire [31:0] branch_fast_load_data_o
);
    localparam integer LINES = (1 << INDEX_BITS);
    localparam integer TAG_BITS = 32 - INDEX_BITS - 2;

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
    wire [INDEX_BITS-1:0] fast_read_idx =
        ex_fast_load_addr_i[INDEX_BITS+1:2];

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
    wire [31:0] refill_word_after_old_store =
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
    // Refill pipeline: capture the complete fill packet in cycle N, then
    // update data/tag/valid together in cycle N+1.
    reg refill_pending_r;
    reg [INDEX_BITS-1:0] refill_idx_r;
    reg [TAG_BITS-1:0] refill_tag_r;
    reg [31:0] refill_word_r;
    integer i;
    wire store_hit =
        store_req &&
        valid_array[store_idx] &&
        (tag_array[store_idx] == store_tag);
    wire refill_store_same_idx =
        refill_req &&
        (refill_idx == store_idx);
    wire refill_store_same_line =
        refill_store_same_idx &&
        store_req &&
        (refill_tag == store_tag);
    wire [3:0] refill_store_wstrb =
        refill_store_same_line ? store_wstrb_i : 4'b0000;
    // refill 与当前 MEM1 store 命中同一 cache line 时，不能简单屏蔽
    // store 对 data_array 的更新。外部 DRAM 已经接收该 store，如果 cache
    // 只写入旧 refill 数据，后续命中 load 会读到回退值。合并顺序为：
    // 1) 先把更早的 store->load forwarding 数据合入 refill word；
    // 2) 再用当前 MEM1 store 的字节写使能覆盖同一 line 的对应字节。
    // 同 index 但 tag 不同表示 refill 将替换另一条 line，当前 store 只
    // 更新外部 DRAM，不允许污染本次 refill 的 cache line。
    wire [31:0] refill_word =
        merge_store_word(refill_word_after_old_store, store_data_i, refill_store_wstrb);
    wire pending_store_same_idx =
        refill_pending_r && (refill_idx_r == store_idx);
    wire pending_store_same_line =
        pending_store_same_idx && store_req && (refill_tag_r == store_tag);
    wire [3:0] pending_store_wstrb =
        pending_store_same_line ? store_wstrb_i : 4'b0000;
    wire [31:0] refill_commit_word =
        merge_store_word(refill_word_r, store_data_i, pending_store_wstrb);
    wire data_write_store_hit = store_hit && !pending_store_same_idx;

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
        end else if (refill_pending_r) begin
            valid_array[refill_idx_r] <= 1'b1;
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b1 && refill_pending_r) begin
            tag_array[refill_idx_r] <= refill_tag_r;
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b1) begin
            if (refill_pending_r) begin
                data_array[refill_idx_r] <= refill_commit_word;
            end
            if (data_write_store_hit) begin
                data_array[store_idx] <=
                    merge_store_word(data_array[store_idx], store_data_i, store_wstrb_i);
            end
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            refill_pending_r <= 1'b0;
        end else begin
            refill_pending_r <= refill_req;
            if (refill_req) begin
                refill_idx_r  <= refill_idx;
                refill_tag_r  <= refill_tag;
                refill_word_r <= refill_word;
            end
        end
    end

    assign mem1_load_cache_hit_o =
        mem1_is_load_i &&
        mem1_load_hits_dram_i &&
        read_valid_r &&
        (read_tag_r == mem1_load_addr_i[31:INDEX_BITS+2]);

    // Kept behind a simulation/build-time legacy switch in the top level for
    // Early tag probe used only by the load-to-branch admission logic.
    assign ex_fast_load_cache_hit_o =
        (ex_fast_load_addr_i >= DRAM_ADDR_START) &&
        (ex_fast_load_addr_i <  DRAM_ADDR_END) &&
        valid_array[fast_read_idx] &&
        (tag_array[fast_read_idx] ==
         ex_fast_load_addr_i[31:INDEX_BITS+2]);

    wire [3:0] mem1_fwd_wstrb =
        mem1_store_load_fwd_valid_i ? mem1_store_load_fwd_wstrb_i : 4'b0000;
    wire [31:0] mem1_cache_word =
        merge_store_word(read_data_r, mem1_store_load_fwd_data_i, mem1_fwd_wstrb);
    wire [31:0] mem1_cache_load_data =
        align_load_word(mem1_inst_i, mem1_load_addr_i, mem1_cache_word);

    // Only a clean resident-line hit uses the dedicated branch comparator.
    // A hit that needs store-to-load byte merging uses the completed MEM2
    // result, keeping the merge mux out of the clean-hit fast path.
    assign branch_fast_load_valid_o =
        mem1_load_cache_hit_o && !mem1_store_load_fwd_valid_i;
    assign branch_fast_load_data_o =
        align_load_word(mem1_inst_i, mem1_load_addr_i, read_data_r);

    // late-load 首次执行无条件使用当前 DCache data array 的读出数据。
    // cache miss 时该数据可能无效，但消费者会被 late_load_miss kill，
    // 正式 miss 数据仍在 MEM2 由 load_cache_hit_i 选择外部 RAM 返回值。
    // 因此 mem1_load_cache_hit_o 只保留为有效性/miss 控制信号，不再进入
    // MEM1 -> late-load forwarding -> EX ALU 的 32 位数据选择锥。
    assign mem1_rd_data_o = mem1_cache_load_data;

endmodule
`endif
