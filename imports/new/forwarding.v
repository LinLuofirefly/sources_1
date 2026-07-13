`timescale 1ns / 1ps
module forwarding (
    input  wire        clk,
    input  wire        rst,
    input  wire        late_load_miss_i,

    input  wire [31:0] id_ex_op1_i,
    input  wire [31:0] id_ex_op2_i,
    input  wire [31:0] id_ex_cmp_op2_i,
    input  wire [31:0] id_ex_store_data_i,
    input  wire [31:0] id_ex_ls_base_addr_i,
    input  wire [31:0] id_ex_jalr_base_addr_i,
    input  wire [31:0] id_ex_br_op1_i,
    input  wire [31:0] id_ex_br_op2_i,

    input  wire [2:0]  id_ex_rs1_fwd_sel_i,
    input  wire [2:0]  id_ex_rs2_fwd_sel_i,

    input  wire [31:0] ex_mem_rd_data_i,

    input  wire [31:0] mem1_mem2_rd_data_i,
    input  wire        mem1_load_cache_hit_i,
    input  wire [31:0] mem1_load_rd_data_i,
    input  wire [31:0] mem2_rd_data_i,

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

    localparam [2:0] FWD_REG       = 3'd0;
    localparam [2:0] FWD_EX_MEM    = 3'd1;
    localparam [2:0] FWD_MEM1_MEM2 = 3'd2;
    localparam [2:0] FWD_LATE_LOAD = 3'd3;
    localparam [2:0] FWD_MEM_WB    = 3'd4;

    // On a hit the load is currently in MEM1.  After a miss replay the same
    // selector is held in ID/EX, while the completed load has moved to MEM2.
    wire [31:0] late_load_data =
        mem1_load_cache_hit_i ? mem1_load_rd_data_i : mem2_rd_data_i;

    reg         late_load_replay_r;
    reg  [31:0] replay_rs1_data_r;
    reg  [31:0] replay_rs2_data_r;

    function [31:0] select_rs1_fwd_data;
        input [2:0]  sel_i;
        input [31:0] reg_data_i;
        begin
            case (sel_i)
                FWD_EX_MEM:    select_rs1_fwd_data = ex_mem_rd_data_i;
                FWD_MEM1_MEM2: select_rs1_fwd_data = mem1_mem2_rd_data_i;
                FWD_LATE_LOAD: select_rs1_fwd_data = late_load_data;
                FWD_MEM_WB:    select_rs1_fwd_data = mem_wb_rd_data_i;
                default:       select_rs1_fwd_data = reg_data_i;
            endcase
        end
    endfunction

    function [31:0] select_rs2_fwd_data;
        input [2:0]  sel_i;
        input [31:0] reg_data_i;
        begin
            case (sel_i)
                FWD_EX_MEM:    select_rs2_fwd_data = ex_mem_rd_data_i;
                FWD_MEM1_MEM2: select_rs2_fwd_data = mem1_mem2_rd_data_i;
                FWD_LATE_LOAD: select_rs2_fwd_data = late_load_data;
                FWD_MEM_WB:    select_rs2_fwd_data = mem_wb_rd_data_i;
                default:       select_rs2_fwd_data = reg_data_i;
            endcase
        end
    endfunction

    wire [31:0] selected_rs1_data =
        select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_op1_i);
    wire [31:0] selected_rs2_data =
        select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_op2_i);

    // If the late load misses, every older producer advances while the
    // consumer is held.  Preserve any independently forwarded second source
    // so replay does not read a now-unrelated pipeline register.
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            late_load_replay_r <= 1'b0;
            replay_rs1_data_r  <= 32'b0;
            replay_rs2_data_r  <= 32'b0;
        end else begin
            late_load_replay_r <= late_load_miss_i;
            if (late_load_miss_i) begin
                replay_rs1_data_r <= selected_rs1_data;
                replay_rs2_data_r <= selected_rs2_data;
            end
        end
    end

    wire replay_rs1_forward =
        late_load_replay_r &&
        (id_ex_rs1_fwd_sel_i != FWD_REG) &&
        (id_ex_rs1_fwd_sel_i != FWD_LATE_LOAD);

    wire replay_rs2_forward =
        late_load_replay_r &&
        (id_ex_rs2_fwd_sel_i != FWD_REG) &&
        (id_ex_rs2_fwd_sel_i != FWD_LATE_LOAD);

    assign fwd_op1_o            = replay_rs1_forward ? replay_rs1_data_r :
                                  select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_op1_i);
    assign fwd_ls_base_addr_o   = replay_rs1_forward ? replay_rs1_data_r :
                                  select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_ls_base_addr_i);
    assign fwd_jalr_base_addr_o = replay_rs1_forward ? replay_rs1_data_r :
                                  select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_jalr_base_addr_i);
    assign fwd_br_op1_o         = replay_rs1_forward ? replay_rs1_data_r :
                                  select_rs1_fwd_data(id_ex_rs1_fwd_sel_i, id_ex_br_op1_i);

    assign fwd_op2_o            = replay_rs2_forward ? replay_rs2_data_r :
                                  select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_op2_i);
    assign fwd_cmp_op2_o        = replay_rs2_forward ? replay_rs2_data_r :
                                  select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_cmp_op2_i);
    assign fwd_store_data_o     = replay_rs2_forward ? replay_rs2_data_r :
                                  select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_store_data_i);
    assign fwd_br_op2_o         = replay_rs2_forward ? replay_rs2_data_r :
                                  select_rs2_fwd_data(id_ex_rs2_fwd_sel_i, id_ex_br_op2_i);

endmodule
