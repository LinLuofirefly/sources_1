`timescale 1ns / 1ps
`include "defines.v"

module rori_decode_ex_tb;
    logic clk = 1'b0, rst = 1'b0, hold = 1'b0, flush = 1'b0;
    always #5 clk = ~clk;

    // rori 标准 OP-IMM 编码：funct7=0110000, funct3=101, opcode=0010011，shamt=inst[24:20]。
    localparam [31:0] RORI_X5_X6_1 = {7'b0110000, 5'd1, 5'd6, 3'b101, 5'd5, 7'b0010011};
    localparam [31:0] BAD_FUNCT7   = {7'b0110001, 5'd1, 5'd6, 3'b101, 5'd5, 7'b0010011};

    logic [31:0] inst_i, rs1_data_i, op2_data_i;
    wire [4:0] id_rd_addr_o, ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire id_reg_wen, id_use_rs1_o, id_use_rs2_o, id_ex_is_rori_o, p_ex_is_rori_o;
    wire ex_rd_wen_o, ex_jump_en_o;

    id id_dut (.inst_i(inst_i), .inst_addr_i(32'h8000_1000), .rs1_data_i(rs1_data_i), .rs2_data_i(32'h0),
        .rd_addr_o(id_rd_addr_o), .reg_wen(id_reg_wen), .use_rs1_o(id_use_rs1_o), .use_rs2_o(id_use_rs2_o), .op2_o(op2_data_i), .ex_is_rori_o(id_ex_is_rori_o));
    id_ex pipe_dut (.clk(clk), .rst(rst), .hold_flag_i(hold), .flush_flag_i(flush), .ex_is_rori_i(id_ex_is_rori_o), .ex_is_rori_o(p_ex_is_rori_o));
    ex ex_dut (.clk(clk), .rst(rst), .inst_i(inst_i), .inst_addr_i(32'h8000_1000),
        .fwd_op1_i(rs1_data_i), .fwd_op2_i(op2_data_i), .fwd_cmp_op2_i(op2_data_i),
        .fwd_br_op1_i(rs1_data_i), .fwd_br_op2_i(op2_data_i), .store_data_i(32'h0),
        .pred_taken_i(1'b0), .pred_target_i(32'b0), .pred_ghr_i({`BP_GHR_WIDTH{1'b0}}),
        .rd_addr_i(5'd5), .rd_wen_i(1'b1), .kill_i(1'b0), .fwd_ls_base_i(32'b0), .fwd_jalr_base_i(32'b0),
        .branch_offset_i(32'b0), .mem_offset_i(32'b0), .jump_offset_i(32'b0), .branch_cond_i(3'b0), .dec_func3_i(3'b101),
        .dec_func7_bit5_i(1'b1), .dec_func7_is_r_i(1'b0), .dec_func7_is_sub_i(1'b0), .dec_is_op_imm_i(1'b0),
        .dec_is_op_reg_i(1'b0), .dec_is_branch_i(1'b0), .dec_is_load_i(1'b0), .dec_is_store_i(1'b0),
        .dec_is_jal_i(1'b0), .dec_is_jalr_i(1'b0), .dec_is_auipc_i(1'b0), .dec_is_lui_i(1'b0),
        .dec_is_system_i(1'b0), .dec_is_rv32m_i(1'b0), .dec_is_csr_op_i(1'b0), .dec_is_rori_i(p_ex_is_rori_o),
        .dec_is_call_jal_i(1'b0), .dec_ras_should_push_jalr_i(1'b0), .dec_ras_should_pop_jalr_i(1'b0), .dec_ras_predicted_jalr_i(1'b0),
        .rd_addr_o(ex_rd_addr_o), .rd_data_o(ex_rd_data_o), .rd_wen_o(ex_rd_wen_o), .jump_en_o(ex_jump_en_o));

    function automatic [31:0] make_rori(input [4:0] sh);
        begin make_rori = {7'b0110000, sh, 5'd6, 3'b101, 5'd5, 7'b0010011}; end
    endfunction
    function automatic [31:0] ref_rori(input [31:0] v, input [4:0] sh);
        begin ref_rori = (sh == 5'd0) ? v : ((v >> sh) | (v << (5'd0 - sh))); end
    endfunction
    task automatic check(input bit cond, input string msg); if (!cond) begin $display("FAIL: %s", msg); $finish; end endtask
    task automatic run_case(input [31:0] a, input [4:0] sh);
        begin
            rs1_data_i = a; inst_i = make_rori(sh);
            @(posedge clk); #1;
            check(ex_rd_data_o == ref_rori(a, sh), "rori result mismatch");
            check(!ex_jump_en_o, "rori must not redirect PC");
        end
    endtask

    integer i;
    initial begin
        rs1_data_i = 32'h8000_0001; inst_i = RORI_X5_X6_1;
        repeat (2) @(posedge clk); rst = 1'b1; #1;
        check(id_ex_is_rori_o, "ID must recognize rori");
        check(id_use_rs1_o && !id_use_rs2_o && id_rd_addr_o == 5'd5 && id_reg_wen, "rori decode metadata");
        inst_i = BAD_FUNCT7; #1; check(!id_ex_is_rori_o, "bad funct7 must not decode as rori");
        inst_i = RORI_X5_X6_1; @(posedge clk); #1;
        check(p_ex_is_rori_o && ex_rd_wen_o && ex_rd_addr_o == 5'd5, "EX rori writeback metadata");
        check(ex_rd_data_o == 32'hc000_0000, "EX rori result");
        hold = 1'b1; inst_i = `INST_NOP; @(posedge clk); #1; check(p_ex_is_rori_o, "hold keeps rori valid");
        hold = 1'b0; flush = 1'b1; @(posedge clk); #1; check(!p_ex_is_rori_o, "flush clears rori valid");
        flush = 1'b0;
        run_case(32'h0000_0000, 5'd0);
        run_case(32'hffff_ffff, 5'd31);
        run_case(32'h8000_0000, 5'd1);
        run_case(32'h0000_0001, 5'd31);
        run_case(32'h5555_5555, 5'd4);
        for (i = 0; i < 500; i = i + 1) run_case($urandom(), $urandom());
        $display("PASS: rori decode/id_ex/ex tests");
        $finish;
    end
endmodule
