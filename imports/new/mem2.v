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
    output reg  [31:0] rd_data_o,
    output wire        rd_wen_o
);

    wire [2:0] func3 = inst_i[14:12];

    wire [31:0] store_load_fwd_mask = {
        {8{store_load_fwd_wstrb_i[3]}},
        {8{store_load_fwd_wstrb_i[2]}},
        {8{store_load_fwd_wstrb_i[1]}},
        {8{store_load_fwd_wstrb_i[0]}}
    };

    wire [31:0] load_word = store_load_fwd_valid_i ?
        ((mem_rd_data_i & ~store_load_fwd_mask) |
         (store_load_fwd_data_i & store_load_fwd_mask)) :
        mem_rd_data_i;

    assign rd_addr_o = rd_addr_i;
    assign rd_wen_o  = rd_wen_i;
    assign inst_o    = inst_i;

    always @(*) begin
        rd_data_o = rd_data_i;

        if (is_load_i) begin
            if (load_cache_hit_i) begin
                rd_data_o = rd_data_i;
            end else begin
                case (func3)
                    `INST_LB: begin
                        case (mem_rd_addr_i[1:0])
                            2'b00: rd_data_o = {{24{load_word[7]}},  load_word[7:0]};
                            2'b01: rd_data_o = {{24{load_word[15]}}, load_word[15:8]};
                            2'b10: rd_data_o = {{24{load_word[23]}}, load_word[23:16]};
                            2'b11: rd_data_o = {{24{load_word[31]}}, load_word[31:24]};
                            default: rd_data_o = 32'b0;
                        endcase
                    end

                    `INST_LH: begin
                        case (mem_rd_addr_i[1])
                            1'b0: rd_data_o = {{16{load_word[15]}}, load_word[15:0]};
                            1'b1: rd_data_o = {{16{load_word[31]}}, load_word[31:16]};
                            default: rd_data_o = 32'b0;
                        endcase
                    end

                    `INST_LW: begin
                        rd_data_o = load_word;
                    end

                    `INST_LBU: begin
                        case (mem_rd_addr_i[1:0])
                            2'b00: rd_data_o = {24'b0, load_word[7:0]};
                            2'b01: rd_data_o = {24'b0, load_word[15:8]};
                            2'b10: rd_data_o = {24'b0, load_word[23:16]};
                            2'b11: rd_data_o = {24'b0, load_word[31:24]};
                            default: rd_data_o = 32'b0;
                        endcase
                    end

                    `INST_LHU: begin
                        case (mem_rd_addr_i[1])
                            1'b0: rd_data_o = {16'b0, load_word[15:0]};
                            1'b1: rd_data_o = {16'b0, load_word[31:16]};
                            default: rd_data_o = 32'b0;
                        endcase
                    end

                    default: rd_data_o = 32'b0;
                endcase
            end
        end
    end

endmodule
