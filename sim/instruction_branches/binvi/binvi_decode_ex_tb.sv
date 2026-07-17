`timescale 1ns / 1ps
`include "defines.v"

module binvi_decode_ex_tb;
    reg clk;
    reg rst;
    reg hold_flag;
    reg flush_flag;
    reg [31:0] inst;
    reg [31:0] rs1_data;
    reg [31:0] rs2_data;

    wire [4:0]  id_rs1_addr;
    wire [4:0]  id_rs2_addr;
    wire [31:0] id_inst_o;
    wire [31:0] id_inst_addr_o;
    wire [31:0] id_op1_o;
    wire [31:0] id_op2_o;
    wire [31:0] id_cmp_op2_o;
    wire [31:0] id_store_data_o;
    wire [4:0]  id_rd_addr_o;
    wire        id_reg_wen_o;
    wire        id_use_rs1_o;
    wire        id_use_rs2_o;
    wire        id_ex_is_op_imm_o;
    wire        id_ex_is_binvi_o;

    wire [31:0] p_inst_o;
    wire [31:0] p_inst_addr_o;
    wire [31:0] p_op1_o;
    wire [31:0] p_op2_o;
    wire [4:0]  p_rd_addr_o;
    wire        p_reg_wen_o;
    wire        p_ex_is_op_imm_o;
    wire        p_ex_is_binvi_o;

    wire [4:0]  ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire        ex_rd_wen_o;
    wire        ex_rv32m_busy_o;
    wire        ex_rv32m_done_o;

    integer i;
    reg [31:0] expected;
    reg [31:0] rnd;

    function automatic [31:0] make_binvi(input [4:0] shamt);
        begin
            make_binvi = {7'b0110100, shamt, 5'd6, 3'b001, 5'd5, 7'b0010011};
        end
    endfunction

    function automatic [31:0] ref_binvi(input [31:0] value, input [4:0] shamt);
        begin
            ref_binvi = value ^ (32'b1 << shamt);
        end
    endfunction

    id u_id (
        .inst_i(inst),
        .inst_addr_i(32'h8000_0000),
        .rs1_addr_o(id_rs1_addr),
        .rs2_addr_o(id_rs2_addr),
        .rs1_data_i(rs1_data),
        .rs2_data_i(rs2_data),
        .inst_o(id_inst_o),
        .inst_addr_o(id_inst_addr_o),
        .op1_o(id_op1_o),
        .op2_o(id_op2_o),
        .cmp_op2_o(id_cmp_op2_o),
        .store_data_o(id_store_data_o),
        .rd_addr_o(id_rd_addr_o),
        .reg_wen(id_reg_wen_o),
        .use_rs1_o(id_use_rs1_o),
        .use_rs2_o(id_use_rs2_o),
        .ex_is_op_imm_o(id_ex_is_op_imm_o),
        .ex_is_binvi_o(id_ex_is_binvi_o)
    );

    id_ex u_id_ex (
        .clk(clk),
        .rst(rst),
        .hold_flag_i(hold_flag),
        .flush_flag_i(flush_flag),
        .inst_i(id_inst_o),
        .inst_addr_i(id_inst_addr_o),
        .op1_i(id_op1_o),
        .op2_i(id_op2_o),
        .cmp_op2_i(id_cmp_op2_o),
        .store_data_i(id_store_data_o),
        .rd_addr_i(id_rd_addr_o),
        .reg_wen_i(id_reg_wen_o),
        .ex_is_op_imm_i(id_ex_is_op_imm_o),
        .ex_is_binvi_i(id_ex_is_binvi_o),
        .inst_o(p_inst_o),
        .inst_addr_o(p_inst_addr_o),
        .op1_o(p_op1_o),
        .op2_o(p_op2_o),
        .rd_addr_o(p_rd_addr_o),
        .reg_wen_o(p_reg_wen_o),
        .ex_is_op_imm_o(p_ex_is_op_imm_o),
        .ex_is_binvi_o(p_ex_is_binvi_o)
    );

    ex u_ex (
        .clk(clk),
        .rst(rst),
        .inst_i(p_inst_o),
        .inst_addr_i(p_inst_addr_o),
        .fwd_op1_i(p_op1_o),
        .fwd_op2_i(p_op2_o),
        .fwd_cmp_op2_i(32'b0),
        .fwd_br_op1_i(32'b0),
        .fwd_br_op2_i(32'b0),
        .store_data_i(32'b0),
        .pred_taken_i(1'b0),
        .pred_target_i(32'b0),
        .pred_ghr_i({`BP_GHR_WIDTH{1'b0}}),
        .rd_addr_i(p_rd_addr_o),
        .rd_wen_i(p_reg_wen_o),
        .kill_i(1'b0),
        .rd_addr_o(ex_rd_addr_o),
        .rd_data_o(ex_rd_data_o),
        .rd_wen_o(ex_rd_wen_o),
        .fwd_ls_base_i(32'b0),
        .fwd_jalr_base_i(32'b0),
        .branch_offset_i(32'b0),
        .mem_offset_i(32'b0),
        .jump_offset_i(32'b0),
        .branch_cond_i(`BR_NONE),
        .dec_func3_i(3'b001),
        .dec_func7_bit5_i(1'b1),
        .dec_func7_is_r_i(1'b0),
        .dec_func7_is_sub_i(1'b0),
        .dec_is_op_imm_i(p_ex_is_op_imm_o),
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
        .dec_is_binvi_i(p_ex_is_binvi_o),
        .dec_is_call_jal_i(1'b0),
        .dec_ras_should_push_jalr_i(1'b0),
        .dec_ras_should_pop_jalr_i(1'b0),
        .dec_ras_predicted_jalr_i(1'b0),
        .rv32m_busy_o(ex_rv32m_busy_o),
        .rv32m_done_o(ex_rv32m_done_o)
    );

    always #5 clk = ~clk;

    task automatic tick;
        begin
            @(posedge clk);
            #1;
        end
    endtask

    task automatic run_case(input [31:0] value, input [4:0] shamt);
        begin
            inst = make_binvi(shamt);
            rs1_data = value;
            rs2_data = 32'hxxxx_xxxx;
            hold_flag = 1'b0;
            flush_flag = 1'b0;
            tick();

            expected = ref_binvi(value, shamt);
            if (!p_ex_is_binvi_o || !ex_rd_wen_o || ex_rd_addr_o != 5'd5 ||
                ex_rd_data_o !== expected) begin
                $error("binvi failed value=%h shamt=%0d got=%h expected=%h valid=%b wen=%b rd=%0d",
                       value, shamt, ex_rd_data_o, expected, p_ex_is_binvi_o,
                       ex_rd_wen_o, ex_rd_addr_o);
                $finish;
            end
        end
    endtask

    initial begin
        clk = 1'b0;
        rst = 1'b0;
        hold_flag = 1'b0;
        flush_flag = 1'b0;
        inst = make_binvi(5'd0);
        rs1_data = 32'b0;
        rs2_data = 32'b0;
        repeat (2) tick();
        rst = 1'b1;

        inst = make_binvi(5'd31);
        rs1_data = 32'h1234_5678;
        #1;
        if (!id_ex_is_binvi_o || !id_use_rs1_o || id_use_rs2_o ||
            !id_reg_wen_o || id_rd_addr_o != 5'd5 ||
            id_rs1_addr != 5'd6 || id_op2_o != 32'd31) begin
            $error("binvi decode failed valid=%b use_rs1=%b use_rs2=%b wen=%b rd=%0d rs1=%0d op2=%h",
                   id_ex_is_binvi_o, id_use_rs1_o, id_use_rs2_o, id_reg_wen_o,
                   id_rd_addr_o, id_rs1_addr, id_op2_o);
            $finish;
        end

        inst = {7'b0110101, 5'd31, 5'd6, 3'b001, 5'd5, 7'b0010011};
        #1;
        if (id_ex_is_binvi_o) begin
            $error("reserved neighboring funct7 decoded as binvi");
            $finish;
        end

        inst = make_binvi(5'd7);
        rs1_data = 32'h0000_0000;
        tick();
        inst = make_binvi(5'd3);
        rs1_data = 32'hffff_ffff;
        hold_flag = 1'b1;
        tick();
        if (!p_ex_is_binvi_o || p_op2_o != 32'd7 || p_op1_o != 32'h0000_0000) begin
            $error("id_ex hold failed op1=%h op2=%h valid=%b", p_op1_o, p_op2_o, p_ex_is_binvi_o);
            $finish;
        end

        hold_flag = 1'b0;
        flush_flag = 1'b1;
        tick();
        if (p_ex_is_binvi_o) begin
            $error("id_ex flush failed to clear binvi valid");
            $finish;
        end
        flush_flag = 1'b0;

        run_case(32'h0000_0000, 5'd0);
        run_case(32'h0000_0000, 5'd31);
        run_case(32'h8000_0000, 5'd31);
        run_case(32'h0000_0001, 5'd0);
        run_case(32'hffff_ffff, 5'd4);
        run_case(32'h5555_5555, 5'd15);
        run_case(32'haaaa_aaaa, 5'd16);

        for (i = 0; i < 500; i = i + 1) begin
            rnd = {$random, $random};
            run_case(rnd, $random);
        end

        $display("PASS: binvi decode/id_ex/ex tests");
        $finish;
    end
endmodule
