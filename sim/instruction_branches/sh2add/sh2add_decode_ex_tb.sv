`timescale 1ns / 1ps
`include "defines.v"

module sh2add_decode_ex_tb;
    logic clk = 1'b0;
    logic rst = 1'b0;
    logic hold = 1'b0;
    logic flush = 1'b0;

    always #5 clk = ~clk;

    // sh2add 标准 R 型编码：funct7=0010000, funct3=100, opcode=0110011。
    // 测试直接使用机器码，避免依赖汇编器是否支持 Zba。
    localparam [31:0] SH2ADD_X5_X6_X7 = {7'b0010000, 5'd7, 5'd6, 3'b100, 5'd5, 7'b0110011};
    localparam [31:0] BAD_FUNCT7      = {7'b0010001, 5'd7, 5'd6, 3'b100, 5'd5, 7'b0110011};

    logic [31:0] inst_i;
    logic [31:0] rs1_data_i;
    logic [31:0] rs2_data_i;

    wire [4:0]  id_rs1_addr_o;
    wire [4:0]  id_rs2_addr_o;
    wire [4:0]  id_rd_addr_o;
    wire        id_reg_wen;
    wire        id_use_rs1_o;
    wire        id_use_rs2_o;
    wire        id_ex_is_sh2add_o;

    id id_dut (
        .inst_i(inst_i),
        .inst_addr_i(32'h8000_1000),
        .rs1_data_i(rs1_data_i),
        .rs2_data_i(rs2_data_i),
        .rs1_addr_o(id_rs1_addr_o),
        .rs2_addr_o(id_rs2_addr_o),
        .rd_addr_o(id_rd_addr_o),
        .reg_wen(id_reg_wen),
        .use_rs1_o(id_use_rs1_o),
        .use_rs2_o(id_use_rs2_o),
        .ex_is_sh2add_o(id_ex_is_sh2add_o)
    );

    wire p_ex_is_sh2add_o;

    id_ex pipe_dut (
        .clk(clk),
        .rst(rst),
        .hold_flag_i(hold),
        .flush_flag_i(flush),
        .ex_is_sh2add_i(id_ex_is_sh2add_o),
        .ex_is_sh2add_o(p_ex_is_sh2add_o)
    );

    wire [4:0]  ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire        ex_rd_wen_o;
    wire        ex_jump_en_o;

    ex ex_dut (
        .clk(clk),
        .rst(rst),
        .inst_i(SH2ADD_X5_X6_X7),
        .inst_addr_i(32'h8000_1000),
        .fwd_op1_i(rs1_data_i),
        .fwd_op2_i(rs2_data_i),
        .fwd_cmp_op2_i(rs2_data_i),
        .fwd_br_op1_i(rs1_data_i),
        .fwd_br_op2_i(rs2_data_i),
        .store_data_i(rs2_data_i),
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
        .dec_func3_i(3'b100),
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
        .dec_is_sh2add_i(p_ex_is_sh2add_o),
        .dec_is_call_jal_i(1'b0),
        .dec_ras_should_push_jalr_i(1'b0),
        .dec_ras_should_pop_jalr_i(1'b0),
        .dec_ras_predicted_jalr_i(1'b0),
        .rd_addr_o(ex_rd_addr_o),
        .rd_data_o(ex_rd_data_o),
        .rd_wen_o(ex_rd_wen_o),
        .jump_en_o(ex_jump_en_o)
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
    logic [31:0] expected_result;

    initial begin
        rs1_data_i = 32'd3;
        rs2_data_i = 32'd10;
        inst_i = SH2ADD_X5_X6_X7;

        repeat (2) @(posedge clk);
        rst = 1'b1;
        #1;

        check(id_ex_is_sh2add_o == 1'b1, "ID must recognize sh2add");
        check(id_use_rs1_o == 1'b1, "sh2add must use rs1");
        check(id_use_rs2_o == 1'b1, "sh2add must use rs2");
        check(id_rd_addr_o == 5'd5, "sh2add rd decode");
        check(id_reg_wen == 1'b1, "sh2add must write rd");

        inst_i = BAD_FUNCT7;
        #1;
        check(id_ex_is_sh2add_o == 1'b0, "reserved adjacent funct7 must not decode as sh2add");
        inst_i = SH2ADD_X5_X6_X7;

        @(posedge clk);
        #1;
        check(p_ex_is_sh2add_o == 1'b1, "ID/EX must latch sh2add valid");
        check(ex_rd_wen_o == 1'b1, "EX must write sh2add rd");
        check(ex_rd_addr_o == 5'd5, "EX rd address");
        check(ex_rd_data_o == 32'd22, "EX sh2add result");
        check(ex_jump_en_o == 1'b0, "sh2add must not redirect PC");

        hold = 1'b1;
        inst_i = `INST_NOP;
        @(posedge clk);
        #1;
        check(p_ex_is_sh2add_o == 1'b1, "hold must keep sh2add valid");

        hold = 1'b0;
        flush = 1'b1;
        @(posedge clk);
        #1;
        check(p_ex_is_sh2add_o == 1'b0, "flush must clear sh2add valid");
        flush = 1'b0;

        // 独立参考模型只做固定拼接左移，不调用 DUT 中的结果线。
        // 覆盖全 0、全 1、最高位、最低位、交错位以及 500 组随机输入。
        foreach_case(32'h0000_0000, 32'h0000_0000);
        foreach_case(32'hffff_ffff, 32'hffff_ffff);
        foreach_case(32'h8000_0000, 32'h0000_0001);
        foreach_case(32'h0000_0001, 32'h8000_0000);
        foreach_case(32'h7fff_ffff, 32'h5555_5555);
        foreach_case(32'h5555_5555, 32'haaaa_aaaa);
        foreach_case(32'haaaa_aaaa, 32'h5555_5555);

        for (i = 0; i < 500; i = i + 1) begin
            foreach_case($urandom(), $urandom());
        end

        $display("PASS: sh2add decode/id_ex/ex tests");
        $finish;
    end

    task automatic foreach_case(input [31:0] op1, input [31:0] op2);
        begin
            a = op1;
            b = op2;
            expected_result = b + {a[29:0], 2'b00};
            rs1_data_i = a;
            rs2_data_i = b;
            inst_i = SH2ADD_X5_X6_X7;
            @(posedge clk);
            #1;
            check(ex_rd_data_o == expected_result, "sh2add result mismatch");
            check(ex_jump_en_o == 1'b0, "sh2add random case must not redirect PC");
        end
    endtask
endmodule
