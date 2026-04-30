`include "defines.v"

module Hazard_detection_unit (
    input  wire [4:0]  id_rs1_i,
    input  wire [4:0]  id_rs2_i,
    input  wire        id_use_rs1_ex_i,
    input  wire        id_use_rs2_ex_i,
    input  wire        id_use_rs2_store_data_i,
    input  wire [4:0]  ex_rd_i,
    input  wire        ex_is_load_i,
    input  wire [4:0]  mem1_rd_i,
    input  wire        mem1_is_load_i,
    input  wire [4:0]  mem1_mem2_rd_i,
    input  wire        mem1_mem2_is_load_i,
    input  wire [4:0]  mem2a_rd_i,
    input  wire        mem2a_is_load_i,
    output reg         hold_flag_o,
    output reg         flush_flag_o
);

    always @(*) begin
        hold_flag_o  = 1'b0;
        flush_flag_o = 1'b0;

        if (ex_is_load_i && (ex_rd_i != 5'b0)) begin
            if ((id_use_rs1_ex_i && (ex_rd_i == id_rs1_i)) ||
                (id_use_rs2_ex_i && (ex_rd_i == id_rs2_i)) ||
                (id_use_rs2_store_data_i && (ex_rd_i == id_rs2_i))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end

        if (mem1_is_load_i && (mem1_rd_i != 5'b0)) begin
            if ((id_use_rs1_ex_i && (mem1_rd_i == id_rs1_i)) ||
                (id_use_rs2_ex_i && (mem1_rd_i == id_rs2_i)) ||
                (id_use_rs2_store_data_i && (mem1_rd_i == id_rs2_i))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end

        if (mem1_mem2_is_load_i && (mem1_mem2_rd_i != 5'b0)) begin
            if ((id_use_rs1_ex_i && (mem1_mem2_rd_i == id_rs1_i)) ||
                (id_use_rs2_ex_i && (mem1_mem2_rd_i == id_rs2_i)) ||
                (id_use_rs2_store_data_i && (mem1_mem2_rd_i == id_rs2_i))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end

        if (mem2a_is_load_i && (mem2a_rd_i != 5'b0)) begin
            if ((id_use_rs1_ex_i && (mem2a_rd_i == id_rs1_i)) ||
                (id_use_rs2_ex_i && (mem2a_rd_i == id_rs2_i)) ||
                (id_use_rs2_store_data_i && (mem2a_rd_i == id_rs2_i))) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end
    end

endmodule
