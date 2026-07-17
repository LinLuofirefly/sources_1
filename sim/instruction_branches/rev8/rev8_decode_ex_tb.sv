`timescale 1ns / 1ps
`include "defines.v"

module rev8_decode_ex_tb;
    logic clk = 1'b0;
    logic rst = 1'b0;
    logic hold = 1'b0;
    logic flush = 1'b0;

    always #5 clk = ~clk;

    // rev8 标准 OP-IMM 编码：imm[11:0]=0x698, funct3=101, opcode=0010011。
    localparam [31:0] REV8_X5_X6 = {12'h698, 5'd6, 3'b101, 5'd5, 7'b0010011};
    localparam [31:0] BAD_IMM    = {12'h699, 5'd6, 3'b101, 5'd5, 7'b0010011};

    logic [31:0] inst_i;
    logic [31:0] rs1_data_i;

    wire [4:0] id_rd_addr_o;
    wire       id_reg_wen;
    wire       id_use_rs1_o;
    wire       id_use_rs2_o;
    wire       id_ex_is_rev8_o;

    id id_dut (
        .inst_i(inst_i),
        .inst_addr_i(32'h8000_1000),
        .rs1_data_i(rs1_data_i),
        .rs2_data_i(32'hdead_beef),
        .rd_addr_o(id_rd_addr_o),
        .reg_wen(id_reg_wen),
        .use_rs1_o(id_use_rs1_o),
        .use_rs2_o(id_use_rs2_o),
        .ex_is_rev8_o(id_ex_is_rev8_o)
    );

    wire p_ex_is_rev8_o;

    id_ex pipe_dut (
        .clk(clk),
        .rst(rst),
        .hold_flag_i(hold),
        .flush_flag_i(flush),
        .ex_is_rev8_i(id_ex_is_rev8_o),
        .ex_is_rev8_o(p_ex_is_rev8_o)
    );

    wire [4:0]  ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire        ex_rd_wen_o;
    wire        ex_jump_en_o;

    ex ex_dut (
        .clk(clk),
        .rst(rst),
        .inst_i(REV8_X5_X6),
        .inst_addr_i(32'h8000_1000),
        .fwd_op1_i(rs1_data_i),
        .fwd_op2_i(32'hdead_beef),
        .fwd_cmp_op2_i(32'hdead_beef),
        .fwd_br_op1_i(rs1_data_i),
        .fwd_br_op2_i(32'hdead_beef),
        .store_data_i(32'hdead_beef),
        .pred_taken_i(1'b0),
        .pred_target_i(32'b0),
        .pred_ghr_i({`BP_GHR_WIDTH{1'b0}}),
        .rd_addr_i(5'd5),
        .rd_wen_i(1'b1),
        .kill_i(1'b0),
        .fwd_ls_base_i(32'b0),
        .fwd_jalr_base_i(32'b0),
        .branch_offset_i(32'b0),
        .mem_offset_i(32'b0),
        .jump_offset_i(32'b0),
        .branch_cond_i(3'b0),
        .dec_func3_i(3'b101),
        .dec_func7_bit5_i(1'b0),
        .dec_func7_is_r_i(1'b0),
        .dec_func7_is_sub_i(1'b0),
        .dec_is_op_imm_i(1'b0),
        .dec_is_op_reg_i(1'b0),
        .dec_is_branch_i(1'b0),
        .dec_is_load_i(1'b0),
        .dec_is_store_i(1'b0),
        .dec_is_jal_i(1'b0),
        .dec_is_jalr_i(1'b0),
        .dec_is_auipc_i(1'b0),
        .dec_is_lui_i(1'b0),
        .dec_is_system_i(1'b0),
        .dec_is_rv32m_i(1'b0),
        .dec_is_csr_op_i(1'b0),
        .dec_is_rev8_i(p_ex_is_rev8_o),
        .dec_is_call_jal_i(1'b0),
        .dec_ras_should_push_jalr_i(1'b0),
        .dec_ras_should_pop_jalr_i(1'b0),
        .dec_ras_predicted_jalr_i(1'b0),
        .rd_addr_o(ex_rd_addr_o),
        .rd_data_o(ex_rd_data_o),
        .rd_wen_o(ex_rd_wen_o),
        .jump_en_o(ex_jump_en_o)
    );

    function automatic [31:0] ref_rev8(input [31:0] value);
        begin
            ref_rev8 = {value[7:0], value[15:8], value[23:16], value[31:24]};
        end
    endfunction

    task automatic check(input bit cond, input string msg);
        if (!cond) begin
            $display("FAIL: %s", msg);
            $finish;
        end
    endtask

    task automatic run_case(input [31:0] op1);
        begin
            rs1_data_i = op1;
            inst_i = REV8_X5_X6;
            @(posedge clk);
            #1;
            check(ex_rd_data_o == ref_rev8(op1), "rev8 result mismatch");
            check(ex_jump_en_o == 1'b0, "rev8 must not redirect PC");
        end
    endtask

    integer i;

    initial begin
        rs1_data_i = 32'h1122_3344;
        inst_i = REV8_X5_X6;

        repeat (2) @(posedge clk);
        rst = 1'b1;
        #1;

        check(id_ex_is_rev8_o == 1'b1, "ID must recognize rev8");
        check(id_use_rs1_o == 1'b1, "rev8 must use rs1");
        check(id_use_rs2_o == 1'b0, "rev8 must not use rs2");
        check(id_rd_addr_o == 5'd5, "rev8 rd decode");
        check(id_reg_wen == 1'b1, "rev8 must write rd");

        inst_i = BAD_IMM;
        #1;
        check(id_ex_is_rev8_o == 1'b0, "adjacent imm must not decode as rev8");
        inst_i = REV8_X5_X6;

        @(posedge clk);
        #1;
        check(p_ex_is_rev8_o == 1'b1, "ID/EX must latch rev8 valid");
        check(ex_rd_wen_o == 1'b1, "EX must write rev8 rd");
        check(ex_rd_addr_o == 5'd5, "EX rd address");
        check(ex_rd_data_o == 32'h4433_2211, "EX rev8 result");

        hold = 1'b1;
        inst_i = `INST_NOP;
        @(posedge clk);
        #1;
        check(p_ex_is_rev8_o == 1'b1, "hold must keep rev8 valid");

        hold = 1'b0;
        flush = 1'b1;
        @(posedge clk);
        #1;
        check(p_ex_is_rev8_o == 1'b0, "flush must clear rev8 valid");
        flush = 1'b0;

        run_case(32'h0000_0000);
        run_case(32'hffff_ffff);
        run_case(32'h8000_0000);
        run_case(32'h0000_0001);
        run_case(32'h7fff_ffff);
        run_case(32'h5555_5555);
        run_case(32'haaaa_aaaa);
        run_case(32'h0123_4567);

        for (i = 0; i < 500; i = i + 1) begin
            run_case($urandom());
        end

        $display("PASS: rev8 decode/id_ex/ex tests");
        $finish;
    end
endmodule
