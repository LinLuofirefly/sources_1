`timescale 1ns / 1ps

module tb_first_fail_debug;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam integer HISTORY_LEN     = 96;
    localparam [31:0] FAIL_COUNT_ADDR  = 32'h8010_0004;

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
    reg [31:0] hist_m2a      [0:HISTORY_LEN-1];
    reg [31:0] hist_m2b      [0:HISTORY_LEN-1];
    reg [31:0] hist_m2       [0:HISTORY_LEN-1];
    reg        hist_hold     [0:HISTORY_LEN-1];
    reg        hist_hflush   [0:HISTORY_LEN-1];
    reg [31:0] hist_f1       [0:HISTORY_LEN-1];
    reg [31:0] hist_f2       [0:HISTORY_LEN-1];
    reg [31:0] hist_x10      [0:HISTORY_LEN-1];
    reg [31:0] hist_x11      [0:HISTORY_LEN-1];
    reg [31:0] hist_x12      [0:HISTORY_LEN-1];
    reg [31:0] hist_x13      [0:HISTORY_LEN-1];
    reg [31:0] hist_x14      [0:HISTORY_LEN-1];
    reg [31:0] hist_x15      [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_addr  [0:HISTORY_LEN-1];
    reg [3:0]  hist_wr_strb  [0:HISTORY_LEN-1];
    reg [31:0] hist_wr_data  [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_addr  [0:HISTORY_LEN-1];
    reg        hist_rd_req   [0:HISTORY_LEN-1];
    reg [31:0] hist_rd_data  [0:HISTORY_LEN-1];

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
            $display("FIRST_FAIL_HISTORY_BEGIN count=%0d", hist_count);
            start_idx = (hist_count == HISTORY_LEN) ? hist_wr_ptr : 0;
            for (j = 0; j < hist_count; j = j + 1) begin
                slot = (start_idx + j) % HISTORY_LEN;
                $display(
                    "FAILDBG cyc=%0d pc=%08h inst=%08h ifid=%08h idex=%08h exmem=%08h mem1=%08h mem12=%08h m2a=%08h m2b=%08h m2=%08h | hold=%0d hfl=%0d | f1=%08h f2=%08h | x10=%08h x11=%08h x12=%08h x13=%08h x14=%08h x15=%08h | rd=(%0d,%08h,%08h) wr=(%b,%08h,%08h)",
                    start_idx + j,
                    hist_pc[slot],
                    hist_inst[slot],
                    hist_ifid[slot],
                    hist_idex[slot],
                    hist_exmem[slot],
                    hist_mem1[slot],
                    hist_mem12[slot],
                    hist_m2a[slot],
                    hist_m2b[slot],
                    hist_m2[slot],
                    hist_hold[slot],
                    hist_hflush[slot],
                    hist_f1[slot],
                    hist_f2[slot],
                    hist_x10[slot],
                    hist_x11[slot],
                    hist_x12[slot],
                    hist_x13[slot],
                    hist_x14[slot],
                    hist_x15[slot],
                    hist_rd_req[slot],
                    hist_rd_addr[slot],
                    hist_rd_data[slot],
                    hist_wr_strb[slot],
                    hist_wr_addr[slot],
                    hist_wr_data[slot]
                );
            end
            $display("FIRST_FAIL_HISTORY_END");
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

        repeat (2000) @(posedge w_cpu_clk);
        $display("FIRST_FAIL_TIMEOUT pc=%08h inst=%08h", dut.pc, dut.instruction);
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
            hist_m2a[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.mem2_align_inst_o;
            hist_m2b[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.mem2_pre_inst_o;
            hist_m2[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.mem2_inst_o;
            hist_hold[hist_wr_ptr]    <= dut.Core_cpu.cpu_core.hdu_hold_flag_o;
            hist_hflush[hist_wr_ptr]  <= dut.Core_cpu.cpu_core.hdu_flush_flag_o;
            hist_f1[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.fwd_op1_o;
            hist_f2[hist_wr_ptr]      <= dut.Core_cpu.cpu_core.fwd_op2_o;
            hist_x10[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[10];
            hist_x11[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[11];
            hist_x12[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[12];
            hist_x13[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[13];
            hist_x14[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[14];
            hist_x15[hist_wr_ptr]     <= dut.Core_cpu.cpu_core.regs_inst.regs[15];
            hist_wr_addr[hist_wr_ptr] <= dut.perip_addr;
            hist_wr_strb[hist_wr_ptr] <= dut.perip_wstrb;
            hist_wr_data[hist_wr_ptr] <= dut.perip_wdata;
            hist_rd_addr[hist_wr_ptr] <= dut.perip_rd_addr;
            hist_rd_req[hist_wr_ptr]  <= dut.perip_rd_en;
            hist_rd_data[hist_wr_ptr] <= dut.perip_rdata;

            if (hist_count < HISTORY_LEN) begin
                hist_count <= hist_count + 1;
            end
            hist_wr_ptr <= (hist_wr_ptr + 1) % HISTORY_LEN;

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == FAIL_COUNT_ADDR)) begin
                $display("FIRST_FAIL_HIT cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
                dump_history();
                $finish;
            end
        end
    end
endmodule
