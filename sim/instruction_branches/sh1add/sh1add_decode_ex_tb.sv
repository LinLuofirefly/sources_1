`timescale 1ns / 1ps
`include "defines.v"

module sh1add_decode_ex_tb;
    logic clk = 1'b0;
    logic rst = 1'b0;
    logic hold = 1'b0;
    logic flush = 1'b0;

    always #5 clk = ~clk;

    function automatic [31:0] r_inst(
        input [6:0] funct7,
        input [4:0] rs2,
        input [4:0] rs1,
        input [2:0] funct3,
        input [4:0] rd,
        input [6:0] opcode
    );
        begin
            r_inst = {funct7, rs2, rs1, funct3, rd, opcode};
        end
    endfunction

    localparam [31:0] SH1ADD_X5_X6_X7 = {7'b0010000, 5'd7, 5'd6, 3'b010, 5'd5, 7'b0110011};
    localparam [31:0] BAD_FUNCT7      = {7'b0010001, 5'd7, 5'd6, 3'b010, 5'd5, 7'b0110011};

    logic [31:0] inst_i;
    logic [31:0] rs1_data_i;
    logic [31:0] rs2_data_i;

    wire [4:0]  id_rs1_addr_o;
    wire [4:0]  id_rs2_addr_o;
    wire [31:0] id_inst_o;
    wire [31:0] id_inst_addr_o;
    wire [31:0] id_op1_o;
    wire [31:0] id_op2_o;
    wire [31:0] id_cmp_op2_o;
    wire [31:0] id_store_data_o;
    wire [4:0]  id_rd_addr_o;
    wire        id_reg_wen;
    wire [31:0] id_base_addr_o;
    wire [31:0] id_branch_offset_o;
    wire [31:0] id_mem_offset_o;
    wire [31:0] id_jump_offset_o;
    wire [2:0]  id_branch_cond_o;
    wire        id_mem_rd_reg_o;
    wire        id_is_branch_o;
    wire        id_use_rs1_o;
    wire        id_use_rs2_o;
    wire        id_use_base_addr_o;
    wire [2:0]  id_ex_func3_o;
    wire        id_ex_func7_bit5_o;
    wire        id_ex_func7_is_r_o;
    wire        id_ex_func7_is_sub_o;
    wire        id_ex_is_op_imm_o;
    wire        id_ex_is_op_reg_o;
    wire        id_ex_is_branch_o;
    wire        id_ex_is_load_o;
    wire        id_ex_is_store_o;
    wire        id_ex_is_jal_o;
    wire        id_ex_is_jalr_o;
    wire        id_ex_is_auipc_o;
    wire        id_ex_is_lui_o;
    wire        id_ex_is_system_o;
    wire        id_ex_is_rv32m_o;
    wire        id_ex_is_csr_op_o;
    wire        id_ex_is_sh1add_o;
    wire        id_ex_is_call_jal_o;
    wire        id_ex_ras_should_push_jalr_o;
    wire        id_ex_ras_should_pop_jalr_o;
    wire        id_ex_ras_predicted_jalr_o;

    id id_dut (
        .inst_i(inst_i),
        .inst_addr_i(32'h8000_1000),
        .rs1_addr_o(id_rs1_addr_o),
        .rs2_addr_o(id_rs2_addr_o),
        .rs1_data_i(rs1_data_i),
        .rs2_data_i(rs2_data_i),
        .inst_o(id_inst_o),
        .inst_addr_o(id_inst_addr_o),
        .op1_o(id_op1_o),
        .op2_o(id_op2_o),
        .cmp_op2_o(id_cmp_op2_o),
        .store_data_o(id_store_data_o),
        .rd_addr_o(id_rd_addr_o),
        .reg_wen(id_reg_wen),
        .base_addr_o(id_base_addr_o),
        .branch_offset_o(id_branch_offset_o),
        .mem_offset_o(id_mem_offset_o),
        .jump_offset_o(id_jump_offset_o),
        .branch_cond_o(id_branch_cond_o),
        .mem_rd_reg_o(id_mem_rd_reg_o),
        .is_branch_o(id_is_branch_o),
        .use_rs1_o(id_use_rs1_o),
        .use_rs2_o(id_use_rs2_o),
        .use_base_addr_o(id_use_base_addr_o),
        .ex_func3_o(id_ex_func3_o),
        .ex_func7_bit5_o(id_ex_func7_bit5_o),
        .ex_func7_is_r_o(id_ex_func7_is_r_o),
        .ex_func7_is_sub_o(id_ex_func7_is_sub_o),
        .ex_is_op_imm_o(id_ex_is_op_imm_o),
        .ex_is_op_reg_o(id_ex_is_op_reg_o),
        .ex_is_branch_o(id_ex_is_branch_o),
        .ex_is_load_o(id_ex_is_load_o),
        .ex_is_store_o(id_ex_is_store_o),
        .ex_is_jal_o(id_ex_is_jal_o),
        .ex_is_jalr_o(id_ex_is_jalr_o),
        .ex_is_auipc_o(id_ex_is_auipc_o),
        .ex_is_lui_o(id_ex_is_lui_o),
        .ex_is_system_o(id_ex_is_system_o),
        .ex_is_rv32m_o(id_ex_is_rv32m_o),
        .ex_is_csr_op_o(id_ex_is_csr_op_o),
        .ex_is_sh1add_o(id_ex_is_sh1add_o),
        .ex_is_call_jal_o(id_ex_is_call_jal_o),
        .ex_ras_should_push_jalr_o(id_ex_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_o(id_ex_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_o(id_ex_ras_predicted_jalr_o)
    );

    wire [31:0] p_inst_o, p_inst_addr_o, p_op1_o, p_op2_o, p_cmp_op2_o, p_store_data_o;
    wire p_pred_taken_o;
    wire [31:0] p_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] p_pred_ghr_o;
    wire [4:0] p_rs1_addr_o, p_rs2_addr_o, p_rd_addr_o;
    wire [1:0] p_rs1_fwd_sel_o, p_rs2_fwd_sel_o;
    wire p_use_rs1_o, p_use_rs2_o, p_use_base_addr_o, p_reg_wen_o;
    wire [31:0] p_base_addr_o, p_branch_offset_o, p_mem_offset_o, p_jump_offset_o;
    wire [2:0] p_branch_cond_o, p_ex_func3_o;
    wire p_ex_func7_bit5_o, p_ex_func7_is_r_o, p_ex_func7_is_sub_o;
    wire p_ex_is_op_imm_o, p_ex_is_op_reg_o, p_ex_is_branch_o, p_ex_is_load_o, p_ex_is_store_o;
    wire p_ex_is_jal_o, p_ex_is_jalr_o, p_ex_is_auipc_o, p_ex_is_lui_o, p_ex_is_system_o;
    wire p_ex_is_rv32m_o, p_ex_is_csr_op_o, p_ex_is_sh1add_o, p_ex_is_call_jal_o;
    wire p_ex_ras_should_push_jalr_o, p_ex_ras_should_pop_jalr_o, p_ex_ras_predicted_jalr_o;

    id_ex pipe_dut (
        .clk(clk), .rst(rst), .hold_flag_i(hold), .flush_flag_i(flush),
        .inst_i(id_inst_o), .inst_addr_i(id_inst_addr_o), .op1_i(id_op1_o), .op2_i(id_op2_o),
        .cmp_op2_i(id_cmp_op2_o), .store_data_i(id_store_data_o),
        .pred_taken_i(1'b0), .pred_target_i(32'b0), .pred_ghr_i({`BP_GHR_WIDTH{1'b0}}),
        .rs1_addr_i(id_rs1_addr_o), .rs2_addr_i(id_rs2_addr_o),
        .rs1_fwd_sel_i(2'b0), .rs2_fwd_sel_i(2'b0),
        .use_rs1_i(id_use_rs1_o), .use_rs2_i(id_use_rs2_o), .use_base_addr_i(id_use_base_addr_o),
        .rd_addr_i(id_rd_addr_o), .reg_wen_i(id_reg_wen),
        .base_addr_i(id_base_addr_o), .branch_offset_i(id_branch_offset_o),
        .mem_offset_i(id_mem_offset_o), .jump_offset_i(id_jump_offset_o), .branch_cond_i(id_branch_cond_o),
        .ex_func3_i(id_ex_func3_o), .ex_func7_bit5_i(id_ex_func7_bit5_o),
        .ex_func7_is_r_i(id_ex_func7_is_r_o), .ex_func7_is_sub_i(id_ex_func7_is_sub_o),
        .ex_is_op_imm_i(id_ex_is_op_imm_o), .ex_is_op_reg_i(id_ex_is_op_reg_o),
        .ex_is_branch_i(id_ex_is_branch_o), .ex_is_load_i(id_ex_is_load_o),
        .ex_is_store_i(id_ex_is_store_o), .ex_is_jal_i(id_ex_is_jal_o),
        .ex_is_jalr_i(id_ex_is_jalr_o), .ex_is_auipc_i(id_ex_is_auipc_o),
        .ex_is_lui_i(id_ex_is_lui_o), .ex_is_system_i(id_ex_is_system_o),
        .ex_is_rv32m_i(id_ex_is_rv32m_o), .ex_is_csr_op_i(id_ex_is_csr_op_o),
        .ex_is_sh1add_i(id_ex_is_sh1add_o), .ex_is_call_jal_i(id_ex_is_call_jal_o),
        .ex_ras_should_push_jalr_i(id_ex_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_i(id_ex_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_i(id_ex_ras_predicted_jalr_o),
        .inst_o(p_inst_o), .inst_addr_o(p_inst_addr_o), .op1_o(p_op1_o), .op2_o(p_op2_o),
        .cmp_op2_o(p_cmp_op2_o), .store_data_o(p_store_data_o),
        .pred_taken_o(p_pred_taken_o), .pred_target_o(p_pred_target_o), .pred_ghr_o(p_pred_ghr_o),
        .rs1_addr_o(p_rs1_addr_o), .rs2_addr_o(p_rs2_addr_o),
        .rs1_fwd_sel_o(p_rs1_fwd_sel_o), .rs2_fwd_sel_o(p_rs2_fwd_sel_o),
        .use_rs1_o(p_use_rs1_o), .use_rs2_o(p_use_rs2_o), .use_base_addr_o(p_use_base_addr_o),
        .rd_addr_o(p_rd_addr_o), .reg_wen_o(p_reg_wen_o), .base_addr_o(p_base_addr_o),
        .branch_offset_o(p_branch_offset_o), .mem_offset_o(p_mem_offset_o),
        .jump_offset_o(p_jump_offset_o), .branch_cond_o(p_branch_cond_o),
        .ex_func3_o(p_ex_func3_o), .ex_func7_bit5_o(p_ex_func7_bit5_o),
        .ex_func7_is_r_o(p_ex_func7_is_r_o), .ex_func7_is_sub_o(p_ex_func7_is_sub_o),
        .ex_is_op_imm_o(p_ex_is_op_imm_o), .ex_is_op_reg_o(p_ex_is_op_reg_o),
        .ex_is_branch_o(p_ex_is_branch_o), .ex_is_load_o(p_ex_is_load_o),
        .ex_is_store_o(p_ex_is_store_o), .ex_is_jal_o(p_ex_is_jal_o),
        .ex_is_jalr_o(p_ex_is_jalr_o), .ex_is_auipc_o(p_ex_is_auipc_o),
        .ex_is_lui_o(p_ex_is_lui_o), .ex_is_system_o(p_ex_is_system_o),
        .ex_is_rv32m_o(p_ex_is_rv32m_o), .ex_is_csr_op_o(p_ex_is_csr_op_o),
        .ex_is_sh1add_o(p_ex_is_sh1add_o), .ex_is_call_jal_o(p_ex_is_call_jal_o),
        .ex_ras_should_push_jalr_o(p_ex_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_o(p_ex_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_o(p_ex_ras_predicted_jalr_o)
    );

    wire [4:0] ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire ex_rd_wen_o;
    wire [31:0] ex_jump_addr_o, ex_inst_o, ex_mem_rd_addr_o, ex_mem_wd_addr_o, ex_mem_wd_data_o;
    wire ex_jump_en_o, ex_is_load_o, ex_load_hits_dram_o;
    wire [3:0] ex_mem_wd_reg_o;
    wire ex_bp_update_en_o, ex_bp_ras_push_en_o, ex_bp_ras_pop_en_o, ex_bp_actual_taken_o;
    wire [31:0] ex_bp_update_pc_o, ex_bp_update_target_o, ex_bp_ras_push_addr_o;
    wire [`BP_GHR_WIDTH-1:0] ex_bp_update_ghr_o;
    wire ex_rv32m_busy_o, ex_rv32m_done_o;

    ex ex_dut (
        .clk(clk), .rst(rst), .inst_i(p_inst_o), .inst_addr_i(p_inst_addr_o),
        .fwd_op1_i(p_op1_o), .fwd_op2_i(p_op2_o), .fwd_cmp_op2_i(p_cmp_op2_o),
        .fwd_br_op1_i(p_op1_o), .fwd_br_op2_i(p_cmp_op2_o), .store_data_i(p_store_data_o),
        .pred_taken_i(p_pred_taken_o), .pred_target_i(p_pred_target_o), .pred_ghr_i(p_pred_ghr_o),
        .rd_addr_i(p_rd_addr_o), .rd_wen_i(p_reg_wen_o), .kill_i(1'b0),
        .fwd_ls_base_i(p_base_addr_o), .fwd_jalr_base_i(p_base_addr_o),
        .branch_offset_i(p_branch_offset_o), .mem_offset_i(p_mem_offset_o), .jump_offset_i(p_jump_offset_o),
        .branch_cond_i(p_branch_cond_o), .dec_func3_i(p_ex_func3_o),
        .dec_func7_bit5_i(p_ex_func7_bit5_o), .dec_func7_is_r_i(p_ex_func7_is_r_o),
        .dec_func7_is_sub_i(p_ex_func7_is_sub_o), .dec_is_op_imm_i(p_ex_is_op_imm_o),
        .dec_is_op_reg_i(p_ex_is_op_reg_o), .dec_is_branch_i(p_ex_is_branch_o),
        .dec_is_load_i(p_ex_is_load_o), .dec_is_store_i(p_ex_is_store_o),
        .dec_is_jal_i(p_ex_is_jal_o), .dec_is_jalr_i(p_ex_is_jalr_o),
        .dec_is_auipc_i(p_ex_is_auipc_o), .dec_is_lui_i(p_ex_is_lui_o),
        .dec_is_system_i(p_ex_is_system_o), .dec_is_rv32m_i(p_ex_is_rv32m_o),
        .dec_is_csr_op_i(p_ex_is_csr_op_o), .dec_is_sh1add_i(p_ex_is_sh1add_o),
        .dec_is_call_jal_i(p_ex_is_call_jal_o),
        .dec_ras_should_push_jalr_i(p_ex_ras_should_push_jalr_o),
        .dec_ras_should_pop_jalr_i(p_ex_ras_should_pop_jalr_o),
        .dec_ras_predicted_jalr_i(p_ex_ras_predicted_jalr_o),
        .rd_addr_o(ex_rd_addr_o), .rd_data_o(ex_rd_data_o), .rd_wen_o(ex_rd_wen_o),
        .jump_addr_o(ex_jump_addr_o), .jump_en_o(ex_jump_en_o), .inst_o(ex_inst_o),
        .mem_rd_addr_o(ex_mem_rd_addr_o), .mem_wd_reg_o(ex_mem_wd_reg_o),
        .mem_wd_addr_o(ex_mem_wd_addr_o), .mem_wd_data_o(ex_mem_wd_data_o),
        .is_load_o(ex_is_load_o), .load_hits_dram_o(ex_load_hits_dram_o),
        .bp_update_en_o(ex_bp_update_en_o), .bp_update_pc_o(ex_bp_update_pc_o),
        .bp_update_target_o(ex_bp_update_target_o), .bp_update_ghr_o(ex_bp_update_ghr_o),
        .bp_ras_push_en_o(ex_bp_ras_push_en_o), .bp_ras_pop_en_o(ex_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(ex_bp_ras_push_addr_o), .bp_actual_taken_o(ex_bp_actual_taken_o),
        .rv32m_busy_o(ex_rv32m_busy_o), .rv32m_done_o(ex_rv32m_done_o)
    );

    task automatic check(input bit cond, input string msg);
        if (!cond) begin
            $display("FAIL: %s", msg);
            $finish;
        end
    endtask

    integer i;
    logic [31:0] a;
    logic [31:0] b;

    initial begin
        rs1_data_i = 32'd3;
        rs2_data_i = 32'd10;
        inst_i = SH1ADD_X5_X6_X7;

        repeat (2) @(posedge clk);
        rst = 1'b1;
        #1;

        check(id_ex_is_sh1add_o == 1'b1, "ID must recognize sh1add");
        check(id_use_rs1_o == 1'b1, "sh1add must use rs1");
        check(id_use_rs2_o == 1'b1, "sh1add must use rs2");
        check(id_rd_addr_o == 5'd5, "sh1add rd decode");
        check(id_reg_wen == 1'b1, "sh1add must write rd");

        inst_i = BAD_FUNCT7;
        #1;
        check(id_ex_is_sh1add_o == 1'b0, "reserved adjacent funct7 must not decode as sh1add");
        inst_i = SH1ADD_X5_X6_X7;

        @(posedge clk);
        #1;
        check(p_ex_is_sh1add_o == 1'b1, "ID/EX must latch sh1add valid");
        check(ex_rd_wen_o == 1'b1, "EX must write sh1add rd");
        check(ex_rd_addr_o == 5'd5, "EX rd address");
        check(ex_rd_data_o == 32'd16, "EX sh1add result");
        check(ex_jump_en_o == 1'b0, "sh1add must not redirect PC");

        hold = 1'b1;
        inst_i = `INST_NOP;
        @(posedge clk);
        #1;
        check(p_ex_is_sh1add_o == 1'b1, "hold must keep sh1add valid");
        hold = 1'b0;
        flush = 1'b1;
        @(posedge clk);
        #1;
        check(p_ex_is_sh1add_o == 1'b0, "flush must clear sh1add valid");
        flush = 1'b0;

        for (i = 0; i < 500; i = i + 1) begin
            a = $urandom();
            b = $urandom();
            rs1_data_i = a;
            rs2_data_i = b;
            inst_i = SH1ADD_X5_X6_X7;
            @(posedge clk);
            #1;
            check(ex_rd_data_o == (b + {a[30:0], 1'b0}), "random sh1add result mismatch");
        end

        $display("PASS: sh1add decode/id_ex/ex tests");
        $finish;
    end
endmodule
