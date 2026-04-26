`timescale 1ns / 1ps

module tb_student_top;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

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

        #100;
        w_clk_rst = 1'b0;

        repeat (20000) @(posedge w_cpu_clk);

        $display("FINAL_LED=%08h", virtual_led);
        $display("FINAL_SEG=%010h", virtual_seg);
        $display("FINAL_SEG_WDATA=%08h", dut.bridge_inst.seg_wdata);
        $finish;
    end

    integer pc_trace_count;
    initial pc_trace_count = 0;

    integer loop_dbg_count;
    initial loop_dbg_count = 0;

    integer jump_hold_dbg_count;
    initial jump_hold_dbg_count = 0;

    initial begin
        $dumpfile("sim_cpu.vcd");
        $dumpvars(0, tb_student_top);
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            if (pc_trace_count < 250) begin
                $display("PC_TRACE T=%0t PC=%08h INST=%08h", $time, dut.pc, dut.instruction);
                pc_trace_count = pc_trace_count + 1;
            end
            if (dut.perip_wstrb != 4'b0000) begin
                $display("CPU_WRITE T=%0t ADDR=%08h WSTRB=%b WDATA=%08h", $time, dut.perip_addr, dut.perip_wstrb, dut.perip_wdata);
            end
            if (dut.perip_rd_en) begin
                $display("CPU_READ  T=%0t ADDR=%08h RDATA=%08h", $time, dut.perip_rd_addr, dut.perip_rdata);
            end
            if (dut.bridge_inst.perip_write_req && dut.perip_addr == 32'h8020_0020) begin
                $display("SEG_WRITE T=%0t DATA=%08h", $time, dut.perip_wdata);
            end
            if (dut.bridge_inst.perip_write_req && dut.perip_addr == 32'h8020_0040) begin
                $display("LED_WRITE T=%0t DATA=%08h", $time, dut.perip_wdata);
            end

            if ((dut.pc >= 32'h8000_035c) && (dut.pc <= 32'h8000_0374) && (loop_dbg_count < 220)) begin
                $display(
                    "LOOP_DBG T=%0t PC=%08h IF_INST=%08h IF_ID=%08h ID_EX=%08h EX_MEM=%08h M1_M2=%08h M2A=%08h M2=%08h WB=%08h | HOLD=%b HDU_FLUSH=%b CTRL_IFID_FLUSH=%b CTRL_IDEX_FLUSH=%b | ID_OP1=%08h ID_OP2=%08h ID_EX_OP1=%08h ID_EX_OP2=%08h FWD_OP1=%08h FWD_OP2=%08h | WB_WEN=%b WB_ADDR=%0d WB_DATA=%08h | A5=%08h S0=%08h PERIP_RD_EN=%b RR=%b RD_A=%08h RD_A_RR=%08h DRAM=%08h PERIP_R=%08h",
                    $time,
                    dut.pc,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_mem_inst_o,
                    dut.Core_cpu.cpu_core.mem1_mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem2_align_inst_o,
                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.id_op1_o,
                    dut.Core_cpu.cpu_core.id_op2_o,
                    dut.Core_cpu.cpu_core.id_ex_op1_o,
                    dut.Core_cpu.cpu_core.id_ex_op2_o,
                    dut.Core_cpu.cpu_core.fwd_op1_o,
                    dut.Core_cpu.cpu_core.fwd_op2_o,
                    dut.Core_cpu.cpu_core.wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[15],
                    dut.Core_cpu.cpu_core.regs_inst.regs[8],
                    dut.bridge_inst.perip_rd_en,
                    dut.bridge_inst.perip_rd_en_rr,
                    dut.bridge_inst.perip_rd_addr,
                    dut.bridge_inst.perip_rd_addr_rr,
                    dut.bridge_inst.dram_rdata,
                    dut.perip_rdata
                );
                loop_dbg_count = loop_dbg_count + 1;
            end

            if (((dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o || dut.Core_cpu.cpu_core.ctrl_jump_en_o ||
                  dut.Core_cpu.cpu_core.hdu_hold_flag_o || dut.Core_cpu.cpu_core.ctrl_flush_ifid_o ||
                  dut.Core_cpu.cpu_core.bp_pred_flush_d1_r) && (jump_hold_dbg_count < 260))) begin
                $display(
                    "JH_DBG T=%0t PC=%08h IF_PC=%08h IF_INST=%08h BP_TK=%b BP_ACC=%b BP_TGT=%08h BP_FL_D1=%b | CTRL_J=%b CTRL_JA=%08h EX_J=%b EX_JA=%08h | HOLD=%b HDU_FLUSH=%b CTRL_IFID=%b CTRL_IDEX=%b | IFID_A=%08h IFID_I=%08h IFID_P=%b | IDEX_A=%08h IDEX_I=%08h IDEX_P=%b",
                    $time,
                    dut.pc,
                    dut.Core_cpu.cpu_core.bp_fetch_pc_r,
                    dut.instruction,
                    dut.Core_cpu.cpu_core.bp_pred_taken_o,
                    dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                    dut.Core_cpu.cpu_core.bp_pred_target_o,
                    dut.Core_cpu.cpu_core.bp_pred_flush_d1_r,
                    dut.Core_cpu.cpu_core.ctrl_jump_en_o,
                    dut.Core_cpu.cpu_core.ctrl_jump_addr_o,
                    dut.Core_cpu.cpu_core.ex_jump_en_o,
                    dut.Core_cpu.cpu_core.ex_jump_addr_o,
                    dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                    dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                    dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                    dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                    dut.Core_cpu.cpu_core.if_id_inst_o,
                    dut.Core_cpu.cpu_core.if_id_pred_taken_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.id_ex_pred_taken_o
                );
                jump_hold_dbg_count = jump_hold_dbg_count + 1;
            end
        end
    end
endmodule
