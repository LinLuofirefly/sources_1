`timescale 1ns / 1ps
module forwarding (
    input  wire [31:0] id_ex_op1_i,
    input  wire [31:0] id_ex_op2_i,
    input  wire [31:0] id_ex_cmp_op2_i,
    input  wire [31:0] id_ex_store_data_i,
    input  wire [31:0] id_ex_ls_base_addr_i,
    input  wire [31:0] id_ex_jalr_base_addr_i,
    input  wire [31:0] id_ex_br_op1_i,
    input  wire [31:0] id_ex_br_op2_i,

    input  wire [1:0]  id_ex_rs1_fwd_sel_i,
    input  wire [1:0]  id_ex_rs2_fwd_sel_i,

    input  wire [31:0] ex_mem_rd_data_i,

    input  wire [31:0] mem1_mem2_rd_data_i,

    input  wire [31:0] mem_wb_rd_data_i,

    output wire [31:0] fwd_op1_o,
    output wire [31:0] fwd_op2_o,
    output wire [31:0] fwd_cmp_op2_o,
    output wire [31:0] fwd_store_data_o,
    output wire [31:0] fwd_ls_base_addr_o,
    output wire [31:0] fwd_jalr_base_addr_o,
    output wire [31:0] fwd_br_op1_o,
    output wire [31:0] fwd_br_op2_o
);

    // 2位紧凑编码让单bit的4选1转发器只包含4个数据输入和2个选择输入，
    // 有机会映射进一个LUT6；不要恢复为3位稀疏编码或独热编码。
    localparam [1:0] FWD_REG       = 2'd0;
    localparam [1:0] FWD_EX_MEM    = 2'd1;
    localparam [1:0] FWD_MEM1_MEM2 = 2'd2;
    localparam [1:0] FWD_MEM_WB    = 2'd3;

    function [31:0] select_rs1_fwd_data;
        input [1:0]  sel_i;
        input [31:0] reg_data_i;
        begin
            case (sel_i)
                FWD_EX_MEM:    select_rs1_fwd_data = ex_mem_rd_data_i;
                FWD_MEM1_MEM2: select_rs1_fwd_data = mem1_mem2_rd_data_i;
                FWD_MEM_WB:    select_rs1_fwd_data = mem_wb_rd_data_i;
                default:       select_rs1_fwd_data = reg_data_i;
            endcase
        end
    endfunction

    function [31:0] select_rs2_fwd_data;
        input [1:0]  sel_i;
        input [31:0] reg_data_i;
        begin
            case (sel_i)
                FWD_EX_MEM:    select_rs2_fwd_data = ex_mem_rd_data_i;
                FWD_MEM1_MEM2: select_rs2_fwd_data = mem1_mem2_rd_data_i;
                FWD_MEM_WB:    select_rs2_fwd_data = mem_wb_rd_data_i;
                default:       select_rs2_fwd_data = reg_data_i;
            endcase
        end
    endfunction

    assign fwd_op1_o            = select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_op1_i);
    assign fwd_ls_base_addr_o   = select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_ls_base_addr_i);
    assign fwd_jalr_base_addr_o = select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_jalr_base_addr_i);
    assign fwd_br_op1_o         = select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_br_op1_i);

    assign fwd_op2_o            = select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_op2_i);
    assign fwd_cmp_op2_o        = select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_cmp_op2_i);
    assign fwd_store_data_o     = select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_store_data_i);
    assign fwd_br_op2_o         = select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_br_op2_i);

endmodule
