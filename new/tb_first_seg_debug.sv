`timescale 1ns / 1ps

module tb_first_seg_debug;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer HISTORY_LEN = 64;
    localparam [31:0] SEG_ADDR     = 32'h8020_0020;
    localparam [31:0] FIRST_EXPECT = 32'h3700_0000;

    integer cycle_count;
    integer hist_wr_ptr;
    integer hist_count;
    integer j;
    integer slot;

    reg [31:0] hist_pc       [0:HISTORY_LEN-1];
    reg [31:0] hist_inst     [0:HISTORY_LEN-1];
    reg [31:0] hist_ifid     [0:HISTORY_LEN-1];
    reg [31:0] hist_idex     [0:HISTORY_LEN-1];
    reg [31:0] hist_exmem    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem1     [0:HISTORY_LEN-1];
    reg [31:0] hist_mem12    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2a    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2b    [0:HISTORY_LEN-1];
    reg [31:0] hist_mem2     [0:HISTORY_LEN-1];
    reg        hist_hold     [0:HISTORY_LEN-1];
    reg        hist_hflush   [0:HISTORY_LEN-1];
    reg        hist_ifflush  [0:HISTORY_LEN-1];
    reg        hist_idflush  [0:HISTORY_LEN-1];
    reg [31:0] hist_fop1     [0:HISTORY_LEN-1];
    reg [31:0] hist_fop2     [0:HISTORY_LEN-1];
    reg        hist_wbwen    [0:HISTORY_LEN-1];
    reg [4:0]  hist_wbaddr   [0:HISTORY_LEN-1];
    reg [31:0] hist_wbdata   [0:HISTORY_LEN-1];
    reg [31:0] hist_x8       [0:HISTORY_LEN-1];
    reg [31:0] hist_x10      [0:HISTORY_LEN-1];
    reg [31:0] hist_x14      [0:HISTORY_LEN-1];
    reg [31:0] hist_x15      [0:HISTORY_LEN-1];
    reg [31:0] hist_seg      [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_addr  [0:HISTORY_LEN-1];
    reg        hist_rd_req   [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_data  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_addr  [0:HISTORY_LEN-1];
    reg [3:0]  hist_wr_strb  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_data  [0:HISTORY_LEN-1];

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
    always #3.333 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    task automatic dump_history;
        integer start_idx;
        begin
            $display("FIRST_SEG_DEBUG_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "DBG cyc=%0d pc=%08h inst=%08h ifid=%08h idex=%08h exmem=%08h mem1=%08h mem12=%08h m2a=%08h m2b=%08h m2=%08h | hold=%0d hfl=%0d iffl=%0d idfl=%0d | f1=%08h f2=%08h | wb=(%0d,%0d,%08h) | x8=%08h x10=%08h x14=%08h x15=%08h | rd=(%0d,%08h,%08h) wr=(%b,%08h,%08h) seg=%08h",
                    start_idx + j,
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_idex[slot],
                    hist_exmem[slot],
                    hist_mem1[slot],
                    hist_mem12[slot],
                    hist_mem2a[slot],
                    hist_mem2b[slot],
                    hist_mem2[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_ifflush[slot],
                    hist_idflush[slot],
                    hist_fop1[slot],
                    hist_fop2[slot],
                    hist_wbwen[slot],
                    hist_wbaddr[slot],
                    hist_wbdata[slot],
                    hist_x8[slot],
                    hist_x10[slot],
                    hist_x14[slot],
                    hist_x15[slot],
                    hist_rd_req[slot],
                    hist_rd_addr[slot],
                    hist_rd_data[slot],
                    hist_wr_strb[slot],
                    hist_wr_addr[slot],
                    hist_wr_data[slot],
                    hist_seg[slot]
                );
            end
            $display("FIRST_SEG_DEBUG_HISTORY_END");
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        hist_wr_ptr = 0;
        hist_count  = 0;

        #20;
        w_clk_rst = 1'b0;

        repeat (5000) @(posedge w_cpu_clk);
        $display("FIRST_SEG_DEBUG_TIMEOUT pc=%08h inst=%08h seg=%08h", dut.pc, dut.instruction, dut.bridge_inst.seg_wdata);
        dump_history();
        $finish;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            hist_pc[hist_wr_ptr]      <= dut.pc;
            hist_inst[hist_wr_ptr]    <= dut.instruction;
            hist_ifid[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.if_id_inst_o;
            hist_idex[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.id_ex_inst_o;
            hist_exmem[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.ex_mem_inst_o;
            hist_mem1[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.mem_inst_o;
            hist_mem12[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem1_mem2_inst_o;
            hist_mem2a[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_mem2b[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.mem2_pre_inst_o;
            hist_mem2[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_hold[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_ifflush[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_ifid_o;
            hist_idflush[hist_wr_ptr] <= dut.Core_cpu.cpu_core.ctrl_flush_idex_o;
            hist_fop1[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_fop2[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_wbwen[hist_wr_ptr]   <= dut.Core_cpu.cpu_core.wb_rd_wen_o;
            hist_wbaddr[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.wb_rd_addr_o;
            hist_wbdata[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.wb_rd_data_o;
            hist_x8[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.regs_inst.regs[8];
            hist_x10[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x14[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_seg[hist_wr_ptr]     <= dut.bridge_inst.seg_wdata;
            hist_rd_addr[hist_wr_ptr] <= dut.perip_rd_addr;
            hist_rd_req[hist_wr_ptr]  <= dut.perip_rd_en;
            hist_rd_data[hist_wr_ptr] <= dut.perip_rdata;
            hist_wr_addr[hist_wr_ptr] <= dut.perip_addr;
            hist_wr_strb[hist_wr_ptr] <= dut.perip_wstrb;
            hist_wr_data[hist_wr_ptr] <= dut.perip_wdata;

            if (hist_count < HISTORY_LEN) begin
                hist_count <= hist_count + 1;
            end
            hist_wr_ptr <= (hist_wr_ptr + 1) % HISTORY_LEN;

            if (dut.perip_wstrb != 4'b0000) begin
                $display("DBG_WRITE cyc=%0d time=%0t addr=%08h wstrb=%b data=%08h pc=%08h inst=%08h",
                         cycle_count, $time, dut.perip_addr, dut.perip_wstrb, dut.perip_wdata, dut.pc, dut.instruction);
            end

            if (dut.perip_rd_en) begin
                $display("DBG_READ cyc=%0d time=%0t addr=%08h rdata=%08h pc=%08h inst=%08h",
                         cycle_count, $time, dut.perip_rd_addr, dut.perip_rdata, dut.pc, dut.instruction);
            end

            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR) &&
                (dut.perip_wdata != 32'h0000_0000)) begin
                $display("FIRST_SEG_DEBUG_HIT cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                dump_history();
                if (dut.perip_wdata != FIRST_EXPECT) begin
                    $display("FIRST_SEG_DEBUG_FAIL expected=%08h actual=%08h", FIRST_EXPECT, dut.perip_wdata);
                end else begin
                    $display("FIRST_SEG_DEBUG_PASS");
                end
                $finish;
            end

            if (dut.pc < 32'h0000_0100) begin
                $display("FIRST_SEG_DEBUG_RUNAWAY cyc=%0d time=%0t pc=%08h inst=%08h", cycle_count, $time, dut.pc, dut.instruction);
                dump_history();
                $finish;
            end
        end
    end
endmodule
