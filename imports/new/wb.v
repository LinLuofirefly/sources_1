`timescale 1ns / 1ps
`include "defines.v"

module wb (
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire        is_slow_load_i,
    input  wire [31:0] mmio_data_i,
    input  wire [31:0] inst_i,

    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o,
    output wire [31:0] inst_o
);

    wire [2:0] func3 = inst_i[14:12];
    wire       is_load_w = (inst_i[6:0] == `INST_TYPE_L);
    reg [31:0] mmio_load_data_w;

    assign rd_addr_o = rd_addr_i;
    assign rd_wen_o  = rd_wen_i;
    assign inst_o    = inst_i;

    always @(*) begin
        case (func3)
            `INST_LB: begin
                case (mem_rd_addr_i[1:0])
                    2'b00: mmio_load_data_w = {{24{mmio_data_i[7]}},  mmio_data_i[7:0]};
                    2'b01: mmio_load_data_w = {{24{mmio_data_i[15]}}, mmio_data_i[15:8]};
                    2'b10: mmio_load_data_w = {{24{mmio_data_i[23]}}, mmio_data_i[23:16]};
                    default: mmio_load_data_w = {{24{mmio_data_i[31]}}, mmio_data_i[31:24]};
                endcase
            end
            `INST_LH: begin
                case (mem_rd_addr_i[1])
                    1'b0: mmio_load_data_w = {{16{mmio_data_i[15]}}, mmio_data_i[15:0]};
                    default: mmio_load_data_w = {{16{mmio_data_i[31]}}, mmio_data_i[31:16]};
                endcase
            end
            `INST_LW: begin
                mmio_load_data_w = mmio_data_i;
            end
            `INST_LBU: begin
                case (mem_rd_addr_i[1:0])
                    2'b00: mmio_load_data_w = {24'b0, mmio_data_i[7:0]};
                    2'b01: mmio_load_data_w = {24'b0, mmio_data_i[15:8]};
                    2'b10: mmio_load_data_w = {24'b0, mmio_data_i[23:16]};
                    default: mmio_load_data_w = {24'b0, mmio_data_i[31:24]};
                endcase
            end
            `INST_LHU: begin
                case (mem_rd_addr_i[1])
                    1'b0: mmio_load_data_w = {16'b0, mmio_data_i[15:0]};
                    default: mmio_load_data_w = {16'b0, mmio_data_i[31:16]};
                endcase
            end
            default: begin
                mmio_load_data_w = mmio_data_i;
            end
        endcase
    end

    assign rd_data_o =
        (is_slow_load_i && is_load_w) ? mmio_load_data_w : rd_data_i;

endmodule