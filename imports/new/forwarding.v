`timescale 1ns / 1ps
module forwarding (
    input  wire [31:0] id_ex_op1_i,
    input  wire [31:0] id_ex_op2_i,
    input  wire [31:0] id_ex_cmp_op2_i,
    input  wire [31:0] id_ex_store_data_i,
    input  wire [31:0] id_ex_base_addr_i,

    input  wire [2:0]  id_ex_rs1_fwd_sel_i,
    input  wire [2:0]  id_ex_rs2_fwd_sel_i,

    input  wire [31:0] ex_mem_rd_data_i,

    input  wire [31:0] mem1_mem2_rd_data_i,

    input  wire [31:0] mem2_rd_data_i,

    input  wire [31:0] mem_wb_rd_data_i,

    output reg  [31:0] fwd_op1_o,
    output reg  [31:0] fwd_op2_o,
    output reg  [31:0] fwd_cmp_op2_o,
    output reg  [31:0] fwd_store_data_o,
    output reg  [31:0] fwd_base_addr_o
);

    localparam [2:0] FWD_REG       = 3'd0;
    localparam [2:0] FWD_EX_MEM    = 3'd1;
    localparam [2:0] FWD_MEM1_MEM2 = 3'd2;
    localparam [2:0] FWD_MEM2      = 3'd3;
    localparam [2:0] FWD_MEM_WB    = 3'd4;

    always @(*) begin
        case (id_ex_rs1_fwd_sel_i)
            FWD_EX_MEM:    fwd_op1_o = ex_mem_rd_data_i;
            FWD_MEM1_MEM2: fwd_op1_o = mem1_mem2_rd_data_i;
            FWD_MEM2:      fwd_op1_o = mem2_rd_data_i;
            FWD_MEM_WB:    fwd_op1_o = mem_wb_rd_data_i;
            default:       fwd_op1_o = id_ex_op1_i;
        endcase

        case (id_ex_rs2_fwd_sel_i)
            FWD_EX_MEM:    fwd_op2_o = ex_mem_rd_data_i;
            FWD_MEM1_MEM2: fwd_op2_o = mem1_mem2_rd_data_i;
            FWD_MEM2:      fwd_op2_o = mem2_rd_data_i;
            FWD_MEM_WB:    fwd_op2_o = mem_wb_rd_data_i;
            default:       fwd_op2_o = id_ex_op2_i;
        endcase

        case (id_ex_rs2_fwd_sel_i)
            FWD_EX_MEM:    fwd_cmp_op2_o = ex_mem_rd_data_i;
            FWD_MEM1_MEM2: fwd_cmp_op2_o = mem1_mem2_rd_data_i;
            FWD_MEM2:      fwd_cmp_op2_o = mem2_rd_data_i;
            FWD_MEM_WB:    fwd_cmp_op2_o = mem_wb_rd_data_i;
            default:       fwd_cmp_op2_o = id_ex_cmp_op2_i;
        endcase

        case (id_ex_rs2_fwd_sel_i)
            FWD_EX_MEM:    fwd_store_data_o = ex_mem_rd_data_i;
            FWD_MEM1_MEM2: fwd_store_data_o = mem1_mem2_rd_data_i;
            FWD_MEM2:      fwd_store_data_o = mem2_rd_data_i;
            FWD_MEM_WB:    fwd_store_data_o = mem_wb_rd_data_i;
            default:       fwd_store_data_o = id_ex_store_data_i;
        endcase

        case (id_ex_rs1_fwd_sel_i)
            FWD_EX_MEM:    fwd_base_addr_o = ex_mem_rd_data_i;
            FWD_MEM1_MEM2: fwd_base_addr_o = mem1_mem2_rd_data_i;
            FWD_MEM2:      fwd_base_addr_o = mem2_rd_data_i;
            FWD_MEM_WB:    fwd_base_addr_o = mem_wb_rd_data_i;
            default:       fwd_base_addr_o = id_ex_base_addr_i;
        endcase
    end

endmodule
