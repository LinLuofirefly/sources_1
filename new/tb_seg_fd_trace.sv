`timescale 1ns / 1ps

module tb_seg_fd_trace;
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

        #100;
        w_clk_rst = 1'b0;
    end

    initial begin
        $dumpfile("sim/tb_seg_fd_trace.vcd");
        $dumpvars(0, tb_seg_fd_trace);
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count <= cycle_count + 1;

            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr  == 32'h8020_0020) begin
                $display("SEG_WRITE CYC=%0d T=%0t PC=%08h INST=%08h DATA=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
            end

            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr  == 32'h8020_0020 &&
                dut.perip_wdata == 32'hfd00_0000) begin
                $display("HIT_FD CYC=%0d T=%0t", cycle_count, $time);
                $display("TOP PC=%08h INST=%08h SEG=%08h LED=%08h",
                         dut.pc, dut.instruction, dut.bridge_inst.seg_wdata, virtual_led);
                $display("DRAM[0000]=%08h DRAM[0001]=%08h DRAM[0002]=%08h DRAM[0003]=%08h",
                         dut.bridge_inst.dram_driver_inst.Mem_DRAM.mem[16'h0000],
                         dut.bridge_inst.dram_driver_inst.Mem_DRAM.mem[16'h0001],
                         dut.bridge_inst.dram_driver_inst.Mem_DRAM.mem[16'h0002],
                         dut.bridge_inst.dram_driver_inst.Mem_DRAM.mem[16'h0003]);
                $display("PIPE IFID_A=%08h IFID_I=%08h IDEX_A=%08h IDEX_I=%08h EXMEM_I=%08h MEM1_I=%08h MEM2A_I=%08h MEM2_I=%08h WB_I=%08h",
                         dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                         dut.Core_cpu.cpu_core.if_id_inst_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_inst_o,
                         dut.Core_cpu.cpu_core.ex_mem_inst_o,
                         dut.Core_cpu.cpu_core.mem_inst_o,
                         dut.Core_cpu.cpu_core.mem2_align_inst_o,
                         dut.Core_cpu.cpu_core.mem2_inst_o,
                         dut.Core_cpu.cpu_core.mem_wb_inst_o);
                $display("EX op1=%08h op2=%08h cmp2=%08h store=%08h base=%08h branch_off=%08h mem_off=%08h jump_off=%08h ex_jump=%0d ex_jump_a=%08h",
                         dut.Core_cpu.cpu_core.fwd_op1_o,
                         dut.Core_cpu.cpu_core.fwd_op2_o,
                         dut.Core_cpu.cpu_core.fwd_cmp_op2_o,
                         dut.Core_cpu.cpu_core.fwd_store_data_o,
                         dut.Core_cpu.cpu_core.fwd_base_addr_o,
                         dut.Core_cpu.cpu_core.id_ex_branch_offset_o,
                         dut.Core_cpu.cpu_core.id_ex_mem_offset_o,
                         dut.Core_cpu.cpu_core.id_ex_jump_offset_o,
                         dut.Core_cpu.cpu_core.ex_jump_en_o,
                         dut.Core_cpu.cpu_core.ex_jump_addr_o);
                $display("WB wen=%0d addr=%0d data=%08h | HOLD=%0d HFL=%0d IFFL=%0d IDFL=%0d BPACC=%0d BPD1=%0d",
                         dut.Core_cpu.cpu_core.wb_rd_wen_o,
                         dut.Core_cpu.cpu_core.wb_rd_addr_o,
                         dut.Core_cpu.cpu_core.wb_rd_data_o,
                         dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                         dut.Core_cpu.cpu_core.hdu_flush_flag_o,
                         dut.Core_cpu.cpu_core.ctrl_flush_ifid_o,
                         dut.Core_cpu.cpu_core.ctrl_flush_idex_o,
                         dut.Core_cpu.cpu_core.bp_pred_taken_accepted_o,
                         dut.Core_cpu.cpu_core.bp_pred_flush_d1_r);
                $display("REG ra=%08h sp=%08h s0=%08h a0=%08h a1=%08h a5=%08h t0=%08h t1=%08h",
                         dut.Core_cpu.cpu_core.regs_inst.regs[1],
                         dut.Core_cpu.cpu_core.regs_inst.regs[2],
                         dut.Core_cpu.cpu_core.regs_inst.regs[8],
                         dut.Core_cpu.cpu_core.regs_inst.regs[10],
                         dut.Core_cpu.cpu_core.regs_inst.regs[11],
                         dut.Core_cpu.cpu_core.regs_inst.regs[15],
                         dut.Core_cpu.cpu_core.regs_inst.regs[5],
                         dut.Core_cpu.cpu_core.regs_inst.regs[6]);
                $finish;
            end

            if (dut.perip_wstrb != 4'b0000 &&
                dut.perip_addr  == 32'h8010_0000) begin
                $display("DRAM0_WRITE CYC=%0d T=%0t PC=%08h INST=%08h WSTRB=%1h DATA=%08h",
                         cycle_count, $time, dut.pc, dut.instruction,
                         dut.perip_wstrb, dut.perip_wdata);
            end

            if (dut.pc >= 32'h8000_1efc && dut.pc <= 32'h8000_1f50) begin
                $display("DIVTRACE CYC=%0d PC=%08h INST=%08h a0=%08h a1=%08h a2=%08h a3=%08h a4=%08h a5=%08h t0=%08h t1=%08h sp=%08h ra=%08h",
                         cycle_count,
                         dut.pc,
                         dut.instruction,
                         dut.Core_cpu.cpu_core.regs_inst.regs[10],
                         dut.Core_cpu.cpu_core.regs_inst.regs[11],
                         dut.Core_cpu.cpu_core.regs_inst.regs[12],
                         dut.Core_cpu.cpu_core.regs_inst.regs[13],
                         dut.Core_cpu.cpu_core.regs_inst.regs[14],
                         dut.Core_cpu.cpu_core.regs_inst.regs[15],
                         dut.Core_cpu.cpu_core.regs_inst.regs[5],
                         dut.Core_cpu.cpu_core.regs_inst.regs[6],
                         dut.Core_cpu.cpu_core.regs_inst.regs[2],
                         dut.Core_cpu.cpu_core.regs_inst.regs[1]);
            end

            if (cycle_count >= 30000) begin
                $display("TIMEOUT CYC=%0d PC=%08h FINAL_SEG=%08h",
                         cycle_count, dut.pc, dut.bridge_inst.seg_wdata);
                $finish;
            end
        end
    end
endmodule
