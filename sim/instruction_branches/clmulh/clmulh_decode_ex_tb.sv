`timescale 1ns / 1ps
`include "defines.v"

module clmulh_decode_ex_tb;
    reg clk, rst, hold_flag, flush_flag;
    reg [31:0] inst, rs1_data, rs2_data;
    wire [4:0] id_rs1_addr, id_rs2_addr, id_rd_addr_o;
    wire [31:0] id_inst_o, id_inst_addr_o, id_op1_o, id_op2_o, id_cmp_op2_o, id_store_data_o;
    wire id_reg_wen_o, id_use_rs1_o, id_use_rs2_o, id_ex_is_op_reg_o, id_ex_is_clmulh_o;
    wire [31:0] p_inst_o, p_inst_addr_o, p_op1_o, p_op2_o;
    wire [4:0] p_rd_addr_o;
    wire p_reg_wen_o, p_ex_is_op_reg_o, p_ex_is_clmulh_o;
    wire [4:0] ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire ex_rd_wen_o, ex_rv32m_busy_o, ex_rv32m_done_o;
    integer i, k, cycles, done_count;
    reg [31:0] a, b, expected;

    function automatic [31:0] make_clmulh;
        begin
            make_clmulh = {7'b0000101, 5'd7, 5'd6, 3'b011, 5'd5, 7'b0110011};
        end
    endfunction

    function automatic [31:0] ref_clmulh(input [31:0] value1, input [31:0] value2);
        reg [63:0] acc;
        begin
            acc = 64'b0;
            for (k = 0; k < 32; k = k + 1)
                if (value2[k])
                    acc = acc ^ ({32'b0, value1} << k);
            ref_clmulh = acc[63:32];
        end
    endfunction

    id u_id (
        .inst_i(inst), .inst_addr_i(32'h8000_0000),
        .rs1_addr_o(id_rs1_addr), .rs2_addr_o(id_rs2_addr),
        .rs1_data_i(rs1_data), .rs2_data_i(rs2_data),
        .inst_o(id_inst_o), .inst_addr_o(id_inst_addr_o),
        .op1_o(id_op1_o), .op2_o(id_op2_o), .cmp_op2_o(id_cmp_op2_o),
        .store_data_o(id_store_data_o), .rd_addr_o(id_rd_addr_o),
        .reg_wen(id_reg_wen_o), .use_rs1_o(id_use_rs1_o), .use_rs2_o(id_use_rs2_o),
        .ex_is_op_reg_o(id_ex_is_op_reg_o), .ex_is_clmulh_o(id_ex_is_clmulh_o)
    );

    id_ex u_id_ex (
        .clk(clk), .rst(rst), .hold_flag_i(hold_flag), .flush_flag_i(flush_flag),
        .inst_i(id_inst_o), .inst_addr_i(id_inst_addr_o),
        .op1_i(id_op1_o), .op2_i(id_op2_o), .cmp_op2_i(id_cmp_op2_o),
        .store_data_i(id_store_data_o), .rd_addr_i(id_rd_addr_o),
        .reg_wen_i(id_reg_wen_o), .ex_is_op_reg_i(id_ex_is_op_reg_o),
        .ex_is_clmulh_i(id_ex_is_clmulh_o),
        .inst_o(p_inst_o), .inst_addr_o(p_inst_addr_o),
        .op1_o(p_op1_o), .op2_o(p_op2_o), .rd_addr_o(p_rd_addr_o),
        .reg_wen_o(p_reg_wen_o), .ex_is_op_reg_o(p_ex_is_op_reg_o),
        .ex_is_clmulh_o(p_ex_is_clmulh_o)
    );

    ex u_ex (
        .clk(clk), .rst(rst), .inst_i(p_inst_o), .inst_addr_i(p_inst_addr_o),
        .fwd_op1_i(p_op1_o), .fwd_op2_i(p_op2_o), .fwd_cmp_op2_i(32'b0),
        .fwd_br_op1_i(32'b0), .fwd_br_op2_i(32'b0), .store_data_i(32'b0),
        .pred_taken_i(1'b0), .pred_target_i(32'b0), .pred_ghr_i({`BP_GHR_WIDTH{1'b0}}),
        .rd_addr_i(p_rd_addr_o), .rd_wen_i(p_reg_wen_o), .kill_i(1'b0),
        .rd_addr_o(ex_rd_addr_o), .rd_data_o(ex_rd_data_o), .rd_wen_o(ex_rd_wen_o),
        .fwd_ls_base_i(32'b0), .fwd_jalr_base_i(32'b0), .branch_offset_i(32'b0),
        .mem_offset_i(32'b0), .jump_offset_i(32'b0), .branch_cond_i(`BR_NONE),
        .dec_func3_i(3'b011), .dec_func7_bit5_i(1'b0), .dec_func7_is_r_i(1'b0),
        .dec_func7_is_sub_i(1'b0), .dec_is_op_imm_i(1'b0), .dec_is_op_reg_i(p_ex_is_op_reg_o),
        .dec_is_branch_i(1'b0), .dec_is_load_i(1'b0), .dec_is_store_i(1'b0),
        .dec_is_jal_i(1'b0), .dec_is_jalr_i(1'b0), .dec_is_auipc_i(1'b0),
        .dec_is_lui_i(1'b0), .dec_is_system_i(1'b0), .dec_is_rv32m_i(1'b0),
        .dec_is_csr_op_i(1'b0), .dec_is_clmulh_i(p_ex_is_clmulh_o),
        .dec_is_call_jal_i(1'b0), .dec_ras_should_push_jalr_i(1'b0),
        .dec_ras_should_pop_jalr_i(1'b0), .dec_ras_predicted_jalr_i(1'b0),
        .rv32m_busy_o(ex_rv32m_busy_o), .rv32m_done_o(ex_rv32m_done_o)
    );

    always #5 clk = ~clk;
    task automatic tick; begin @(posedge clk); #1; end endtask
    task automatic run_case(input [31:0] value1, input [31:0] value2);
        begin
            inst = make_clmulh(); rs1_data = value1; rs2_data = value2; hold_flag = 1'b0; flush_flag = 1'b0;
            tick(); inst = `INST_NOP; rs1_data = 32'b0; rs2_data = 32'b0; tick();
            expected = ref_clmulh(value1, value2); cycles = 0; done_count = 0;
            while (cycles < 80 && done_count == 0) begin
                if (ex_rv32m_done_o) begin
                    done_count = done_count + 1;
                    if (!ex_rd_wen_o || ex_rd_addr_o != 5'd5 || ex_rd_data_o !== expected) begin
                        $error("clmulh failed rs1=%h rs2=%h got=%h expected=%h", value1, value2, ex_rd_data_o, expected);
                        $finish;
                    end
                end
                tick(); cycles = cycles + 1;
            end
            if (done_count != 1 || ex_rv32m_done_o) begin
                $error("clmulh done pulse error count=%0d", done_count);
                $finish;
            end
        end
    endtask

    initial begin
        clk = 1'b0; rst = 1'b0; hold_flag = 1'b0; flush_flag = 1'b0;
        inst = make_clmulh(); rs1_data = 32'b0; rs2_data = 32'b0;
        repeat (2) tick(); rst = 1'b1;
        #1;
        if (!id_ex_is_clmulh_o || !id_use_rs1_o || !id_use_rs2_o || !id_reg_wen_o ||
            id_rd_addr_o != 5'd5 || id_rs1_addr != 5'd6 || id_rs2_addr != 5'd7) begin
            $error("clmulh decode failed");
            $finish;
        end
        inst = {7'b0000100, 5'd7, 5'd6, 3'b011, 5'd5, 7'b0110011}; #1;
        if (id_ex_is_clmulh_o) begin
            $error("neighboring funct7 decoded as clmulh");
            $finish;
        end
        flush_flag = 1'b1; tick();
        if (p_ex_is_clmulh_o) begin
            $error("id_ex flush failed");
            $finish;
        end
        flush_flag = 1'b0;
        run_case(32'h0000_0000, 32'h0000_0000);
        run_case(32'hffff_ffff, 32'hffff_ffff);
        run_case(32'h8000_0000, 32'h0000_0001);
        run_case(32'h0000_0001, 32'h8000_0000);
        run_case(32'h5555_5555, 32'haaaa_aaaa);
        for (i = 0; i < 500; i = i + 1) begin
            a = {$random, $random};
            b = {$random, $random};
            run_case(a, b);
        end
        $display("PASS: clmulh decode/id_ex/ex iterative tests");
        $finish;
    end
endmodule
