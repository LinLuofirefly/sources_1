`timescale 1ns / 1ps

module tb_src0_mtest_trace;

    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    integer cycle_count;

    student_top dut (
        .w_cpu_clk   (w_cpu_clk),
        .w_clk_50Mhz (w_clk_50Mhz),
        .w_clk_rst   (w_clk_rst),
        .virtual_key (virtual_key),
        .virtual_sw  (virtual_sw),
        .virtual_led (virtual_led),
        .virtual_seg (virtual_seg)
    );

    initial w_cpu_clk = 1'b0;
    always #3 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;

        $dumpfile("sim/tb_src0_mtest_trace.vcd");
        $dumpvars(0, tb_src0_mtest_trace);

        #100;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count <= cycle_count + 1;

            if (cycle_count >= 20000) begin
                $display(
                    "TRACE_DONE CYC=%0d PC=%08h SEG=%08h LED=%08h",
                    cycle_count,
                    dut.pc,
                    dut.bridge_inst.seg_wdata,
                    virtual_led
                );
                $finish;
            end
        end
    end

    // ============================================================
    // 1. SEG / LED 写监控
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr == 32'h8020_0020) begin
                $display(
                    "SEG_WRITE CYC=%0d T=%0t PC_EX=%08h INST_EX=%08h DATA=%08h",
                    cycle_count,
                    $time,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.perip_wdata
                );
            end

            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr == 32'h8020_0040) begin
                $display(
                    "LED_WRITE CYC=%0d T=%0t PC_EX=%08h INST_EX=%08h DATA=%08h",
                    cycle_count,
                    $time,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.perip_wdata
                );
            end
        end
    end

    // ============================================================
    // 2. 打印 8 个 M 扩展子测试入口
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            case (dut.Core_cpu.cpu_core.id_ex_inst_addr_o)

                32'h8000_1cc8:
                    $display("ENTER_MTEST CYC=%0d TEST=mul    PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1d50:
                    $display("ENTER_MTEST CYC=%0d TEST=mulh   PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1dd8:
                    $display("ENTER_MTEST CYC=%0d TEST=mulhsu PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1e64:
                    $display("ENTER_MTEST CYC=%0d TEST=mulhu  PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1ef0:
                    $display("ENTER_MTEST CYC=%0d TEST=div    PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1f74:
                    $display("ENTER_MTEST CYC=%0d TEST=divu   PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_1ffc:
                    $display("ENTER_MTEST CYC=%0d TEST=rem    PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

                32'h8000_2080:
                    $display("ENTER_MTEST CYC=%0d TEST=remu   PC=%08h",
                        cycle_count,
                        dut.Core_cpu.cpu_core.id_ex_inst_addr_o
                    );

            endcase
        end
    end

    // ============================================================
    // 3. M 扩展指令执行结果追踪
    //
    // RISC-V M 扩展：
    // opcode = 0110011
    // funct7 = 0000001
    // ============================================================

    wire idex_is_m_ext;

    assign idex_is_m_ext =
        dut.Core_cpu.cpu_core.id_ex_inst_o[6:0]   == 7'b0110011 &&
        dut.Core_cpu.cpu_core.id_ex_inst_o[31:25] == 7'b0000001;

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (idex_is_m_ext ||
                dut.Core_cpu.cpu_core.ex_rv32m_busy_o ||
                dut.Core_cpu.cpu_core.ex_rv32m_done_o) begin

                $display(
                    "MTRACE CYC=%0d PC=%08h INST=%08h FUNCT3=%03b RS1=%0d RS2=%0d RD=%0d OP1=%08h OP2=%08h BUSY=%b DONE=%b EX_WEN=%b EX_DATA=%08h EXMEM_WEN=%b EXMEM_DATA=%08h HOLD=%b HFL=%b KILL=%b",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o[14:12],
                    dut.Core_cpu.cpu_core.id_ex_rs1_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rs2_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rd_addr_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_op2_o,
                    dut.Core_cpu.cpu_core.ex_rv32m_busy_o,
                    dut.Core_cpu.cpu_core.ex_rv32m_done_o,
                    dut.Core_cpu.cpu_core.ex_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_rd_data_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_wen_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_data_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_kill_ex_o
                );
            end
        end
    end

    // ============================================================
    // 4. M 测试区间内 branch taken 监控
    //
    // 这些测试通常是：
    //   bne  实际值, 期望值, fail
    //   bnez 实际值, fail
    //
    // 所以 M 区间内 branch taken 基本就是当前 case 失败。
    // ============================================================

    wire idex_is_branch;
    wire idex_in_mtest_range;

    assign idex_is_branch =
        dut.Core_cpu.cpu_core.id_ex_inst_o[6:0] == 7'b1100011;

    assign idex_in_mtest_range =
        dut.Core_cpu.cpu_core.id_ex_inst_addr_o >= 32'h8000_1cc8 &&
        dut.Core_cpu.cpu_core.id_ex_inst_addr_o <= 32'h8000_2108;

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (idex_is_branch &&
                idex_in_mtest_range &&
                dut.Core_cpu.cpu_core.ex_jump_en_o) begin

                $display(
                    "MTEST_FAIL_BRANCH CYC=%0d PC=%08h INST=%08h RS1=%0d RS2=%0d RAW_OP1=%08h RAW_OP2=%08h FOP1=%08h FOP2=%08h CMP2=%08h FCMP2=%08h JUMP_ADDR=%08h HOLD=%b HFL=%b",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_rs1_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rs2_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_op1_o,
                    dut.Core_cpu.cpu_core.id_ex_op2_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_op2_o,
                    dut.Core_cpu.cpu_core.id_ex_cmp_op2_o,
                    dut.Core_cpu.cpu_core.fwd_cmp_op2_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o
                );
            end
        end
    end

    // ============================================================
    // 5. M 测试通过计数 / 失败计数写入监控
    //
    // 重点看：
    //   0x80100030：你最终看到的 M 通过数来源
    //
    // 如果最后是 5，说明这个地址只被有效加到 5。
    // ============================================================

    wire idex_is_store;

    assign idex_is_store =
        dut.Core_cpu.cpu_core.id_ex_inst_o[6:0] == 7'b0100011;

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (idex_is_store &&
                dut.Core_cpu.cpu_core.ex_wd_addr_o >= 32'h8010_0020 &&
                dut.Core_cpu.cpu_core.ex_wd_addr_o <= 32'h8010_0050) begin

                $display(
                    "COUNT_STORE CYC=%0d PC=%08h INST=%08h ADDR=%08h DATA=%08h STRB=%b BASE=%08h FBASE=%08h STORE_RAW=%08h STORE_FWD=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_wd_addr_o,
                    dut.Core_cpu.cpu_core.ex_wd_data_o,
                    dut.Core_cpu.cpu_core.ex_wd_reg_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_store_data_o,
                    dut.Core_cpu.cpu_core.fwd_store_data_o
                );
            end
        end
    end

    // ============================================================
    // 6. 所有 M 测试区间内的 branch 都打印一次
    //
    // 用于确认 branch not taken / taken。
    // 如果某个 bne 应该不跳但跳了，就能看到比较值。
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (idex_is_branch && idex_in_mtest_range) begin
                $display(
                    "M_BRANCH CYC=%0d PC=%08h INST=%08h J=%b JA=%08h RS1=%0d RS2=%0d FOP1=%08h FCMP2=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rs1_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_rs2_addr_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_cmp_op2_o
                );
            end
        end
    end

    // ============================================================
    // 7. 写回 t2/x7 监控
    //
    // 大部分 M 测试把实际结果写到 t2，也就是 x7。
    // 这个可以看到实际 M 指令结果最终有没有写回。
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (dut.Core_cpu.cpu_core.ex_rd_wen_o &&
                dut.Core_cpu.cpu_core.ex_rd_addr_o == 5'd7) begin

                $display(
                    "X7_EX CYC=%0d PC=%08h INST=%08h DATA=%08h KILL=%b",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_rd_data_o,
                    dut.Core_cpu.cpu_core.ctrl_kill_ex_o
                );
            end

            if (dut.Core_cpu.cpu_core.ex_mem_rd_wen_o &&
                dut.Core_cpu.cpu_core.ex_mem_pipe_rd_addr_o == 5'd7) begin

                $display(
                    "X7_EXMEM CYC=%0d INST=%08h DATA=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_rd_data_o
                );
            end

            if (dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd7) begin

                $display(
                    "X7_WB CYC=%0d INST=%08h DATA=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o
                );
            end
        end
    end

    // ============================================================
    // 8. 写回 t3/x28 监控
    //
    // 很多测试会用 t3 存期望值。
    // 这个可以配合 branch 比较看实际值 vs 期望值。
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd28) begin

                $display(
                    "X28_T3_WB CYC=%0d INST=%08h DATA=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o
                );
            end
        end
    end

    // ============================================================
    // 9. 如果 ret 跳到 0，直接报错
    // ============================================================

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (dut.Core_cpu.cpu_core.ex_jump_en_o &&
                dut.Core_cpu.cpu_core.ex_inst_o == 32'h0000_8067 &&
                dut.Core_cpu.cpu_core.ex_jump_addr_o == 32'h0000_0000) begin

                $display(
                    "ERROR_RET_TO_ZERO CYC=%0d PC=%08h INST=%08h BASE=%08h FBASE=%08h JA=%08h",
                    cycle_count,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_base_addr_o,
                    dut.Core_cpu.cpu_core.fwd_base_addr_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o
                );

                $stop;
            end
        end
    end

endmodule