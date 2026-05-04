`timescale 1ns / 1ps

module tb_func70_second_call;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] FUNC70_START = 32'h8000_0070;
    localparam [31:0] FUNC70_END   = 32'h8000_0100;
    localparam [31:0] REM_WRAPPER  = 32'h8000_1ea8;
    localparam [31:0] DIV_WRAPPER  = 32'h8000_1e30;
    localparam [31:0] SEG_ADDR     = 32'h8020_0020;
    localparam time MAX_SIM_TIME_NS = 30_000_000_000;

    integer cycle_count;
    integer seg_write_count;
    reg     active_target_call;

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

    task automatic finish_trace;
        input [255:0] reason;
        begin
            $display("FUNC70_STOP reason=%0s cyc=%0d time=%0t pc=%08h inst=%08h entries=%0d a0=%08h a4=%08h a5=%08h s0=%08h sp=%08h",
                     reason, cycle_count, $time, dut.pc, dut.instruction, 0,
                     dut.Core_cpu.cpu_core.regs_inst.regs[10],
                     dut.Core_cpu.cpu_core.regs_inst.regs[14],
                     dut.Core_cpu.cpu_core.regs_inst.regs[15],
                     dut.Core_cpu.cpu_core.regs_inst.regs[8],
                     dut.Core_cpu.cpu_core.regs_inst.regs[2]);
            $finish;
        end
    endtask

    initial begin
        virtual_key       = 8'd0;
        virtual_sw        = 64'd0;
        w_clk_rst         = 1'b1;
        cycle_count       = 0;
        seg_write_count   = 0;
        active_target_call = 1'b0;

        #20;
        w_clk_rst = 1'b0;

        #MAX_SIM_TIME_NS;
        finish_trace("TIMEOUT");
    end

    always @(posedge w_cpu_clk) begin
        reg [31:0] s0_now;
        reg [31:0] slot_in;
        reg [31:0] slot_acc;
        reg [31:0] slot_shift;
        reg [31:0] slot_digit;
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            s0_now     = dut.Core_cpu.cpu_core.regs_inst.regs[8];
            slot_in    = s0_now - 32'h24;
            slot_acc   = s0_now - 32'h14;
            slot_shift = s0_now - 32'h18;
            slot_digit = s0_now - 32'h1c;

            if ((dut.perip_wstrb != 4'b0000) &&
                (dut.perip_addr == SEG_ADDR) &&
                (dut.perip_wdata != 32'h0000_0000)) begin
                seg_write_count = seg_write_count + 1;
                $display("FUNC70_SEG_OBS #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h",
                         seg_write_count, cycle_count, $time, dut.pc, dut.instruction, dut.perip_wdata);
            end

            if (!active_target_call &&
                (seg_write_count >= 1) &&
                (dut.pc == FUNC70_START) &&
                (dut.Core_cpu.cpu_core.regs_inst.regs[1] == 32'h8000_016c)) begin
                active_target_call = 1'b1;
                $display("FUNC70_TARGET_ENTRY cyc=%0d time=%0t pc=%08h inst=%08h a0=%08h sp=%08h ra=%08h",
                         cycle_count, $time, dut.pc, dut.instruction,
                         dut.Core_cpu.cpu_core.regs_inst.regs[10],
                         dut.Core_cpu.cpu_core.regs_inst.regs[2],
                         dut.Core_cpu.cpu_core.regs_inst.regs[1]);
            end

            if (active_target_call) begin
                if ((dut.pc >= FUNC70_START) && (dut.pc <= FUNC70_END)) begin
                    $display("FUNC70_TRACE cyc=%0d pc=%08h inst=%08h | a0=%08h a1=%08h a4=%08h a5=%08h s0=%08h sp=%08h ra=%08h | issue=%08h idex=%08h exmem=%08h m12=%08h m2=%08h | hold=%0d",
                             cycle_count, dut.pc, dut.instruction,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.Core_cpu.cpu_core.regs_inst.regs[11],
                             dut.Core_cpu.cpu_core.regs_inst.regs[14],
                             dut.Core_cpu.cpu_core.regs_inst.regs[15],
                             s0_now,
                             dut.Core_cpu.cpu_core.regs_inst.regs[2],
                             dut.Core_cpu.cpu_core.regs_inst.regs[1],
                             dut.Core_cpu.cpu_core.id_pipe_inst_o,
                             dut.Core_cpu.cpu_core.id_ex_inst_o,
                             dut.Core_cpu.cpu_core.ex_mem_inst_o,
                             dut.Core_cpu.cpu_core.mem1_mem2_inst_o,
                             dut.Core_cpu.cpu_core.mem2_inst_o,
                             dut.Core_cpu.cpu_core.hdu_hold_flag_o);
                end

                if (dut.perip_wstrb != 4'b0000) begin
                    if ((dut.perip_addr == slot_in) || (dut.perip_addr == slot_acc) ||
                        (dut.perip_addr == slot_shift) || (dut.perip_addr == slot_digit)) begin
                        $display("FUNC70_LOCAL_WRITE cyc=%0d pc=%08h inst=%08h addr=%08h data=%08h slot_in=%08h slot_acc=%08h slot_shift=%08h slot_digit=%08h",
                                 cycle_count, dut.pc, dut.instruction, dut.perip_addr, dut.perip_wdata,
                                 slot_in, slot_acc, slot_shift, slot_digit);
                    end
                end

                if (dut.perip_rd_en) begin
                    if ((dut.perip_rd_addr == slot_in) || (dut.perip_rd_addr == slot_acc) ||
                        (dut.perip_rd_addr == slot_shift) || (dut.perip_rd_addr == slot_digit)) begin
                        $display("FUNC70_LOCAL_READ cyc=%0d pc=%08h inst=%08h addr=%08h rdata=%08h slot_in=%08h slot_acc=%08h slot_shift=%08h slot_digit=%08h",
                                 cycle_count, dut.pc, dut.instruction, dut.perip_rd_addr, dut.perip_rdata,
                                 slot_in, slot_acc, slot_shift, slot_digit);
                    end
                end

                if ((dut.pc == REM_WRAPPER) || (dut.pc == DIV_WRAPPER) ||
                    (dut.Core_cpu.cpu_core.if_id_inst_addr_o == REM_WRAPPER) ||
                    (dut.Core_cpu.cpu_core.if_id_inst_addr_o == DIV_WRAPPER)) begin
                    $display("FUNC70_SUBCALL cyc=%0d pc=%08h inst=%08h a0=%08h a1=%08h ra=%08h",
                             cycle_count, dut.pc, dut.instruction,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.Core_cpu.cpu_core.regs_inst.regs[11],
                             dut.Core_cpu.cpu_core.regs_inst.regs[1]);
                end

                if ((dut.pc == 32'h8000_016c) && (dut.Core_cpu.cpu_core.regs_inst.regs[1] == 32'h8000_016c)) begin
                    $display("FUNC70_POSTCALL_MARK cyc=%0d a0=%08h a4=%08h a5=%08h",
                             cycle_count,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.Core_cpu.cpu_core.regs_inst.regs[14],
                             dut.Core_cpu.cpu_core.regs_inst.regs[15]);
                end

                if (dut.pc == 32'h8000_016c) begin
                    $display("FUNC70_TARGET_RETURN cyc=%0d time=%0t a0=%08h pc=%08h ra=%08h",
                             cycle_count, $time,
                             dut.Core_cpu.cpu_core.regs_inst.regs[10],
                             dut.pc,
                             dut.Core_cpu.cpu_core.regs_inst.regs[1]);
                    finish_trace("TARGET_CALL_RETURN");
                end
            end
        end
    end
endmodule
