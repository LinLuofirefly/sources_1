`timescale 1ns / 1ps

module tb_seg_led_stop;
    reg         w_cpu_clk;
    reg         w_clk_50Mhz;
    reg         w_clk_rst;
    reg  [7:0]  virtual_key;
    reg  [63:0] virtual_sw;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    localparam [31:0] SEG_ADDR = 32'h8020_0020;
    localparam [31:0] LED_ADDR = 32'h8020_0040;
    localparam time SIM_TIME_LIMIT_NS = 30_000_000_000;
    localparam integer STUCK_PC_LIMIT = 200000;

    longint cycle_count;
    integer seg_write_count;
    integer led_write_count;
    integer same_pc_count;
    reg [31:0] prev_pc;

    reg after_3rd_led;
    longint after_3rd_led_cycle;

    localparam [31:0] TRACE_SEG_ADDR = 32'h8020_0020;
    localparam [31:0] TRACE_STACK_ADDR = 32'h8012_100c;

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
    always #2.5 w_cpu_clk = ~w_cpu_clk;

    initial w_clk_50Mhz = 1'b0;
    always #10 w_clk_50Mhz = ~w_clk_50Mhz;

    task automatic finish_fail;
        input [127:0] reason;
        begin
            $display("SEG_LED_STOP_FAIL reason=%0s cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h same_pc=%0d",
                     reason, cycle_count, $time, dut.pc, dut.instruction,
                     seg_write_count, led_write_count, virtual_led, virtual_seg,
                     same_pc_count);
            $finish;
        end
    endtask

    initial begin
        virtual_key = 8'd0;
        virtual_sw  = 64'd0;
        w_clk_rst   = 1'b1;
        cycle_count = 0;
        seg_write_count = 0;
        led_write_count = 0;
        same_pc_count = 0;
        prev_pc = 32'b0;
        after_3rd_led = 1'b0;
        after_3rd_led_cycle = 0;
        #20;
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst) begin
            cycle_count = cycle_count + 1;

            if (dut.pc == prev_pc) begin
                same_pc_count = same_pc_count + 1;
            end else begin
                same_pc_count = 0;
                prev_pc = dut.pc;
            end

            if (cycle_count > 100 && dut.pc < 32'h8000_0000) begin
                finish_fail("RUNAWAY_LOW_PC");
            end

            if (same_pc_count >= STUCK_PC_LIMIT) begin
                finish_fail("STUCK_SAME_PC");
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == SEG_ADDR)) begin
                seg_write_count = seg_write_count + 1;
                $display("SEG_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vseg=%010h",
                         seg_write_count, cycle_count, $time, dut.pc,
                         dut.instruction, dut.perip_wdata, dut.perip_wstrb, virtual_seg);
            end

            if ((dut.perip_wstrb != 4'b0000) && (dut.perip_addr == LED_ADDR)) begin
                led_write_count = led_write_count + 1;
                $display("LED_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b seg_writes=%0d vseg=%010h",
                         led_write_count, cycle_count, $time, dut.pc, dut.instruction,
                         dut.perip_wdata, dut.perip_wstrb, seg_write_count, virtual_seg);

                if (led_write_count == 3) begin
                    after_3rd_led = 1'b1;
                    after_3rd_led_cycle = cycle_count;
                    $display("A3_TRACE_START cyc=%0d time=%0t", cycle_count, $time);
                end

                if (led_write_count == 4) begin
                    $display("SEG_LED_STOP_DONE led=%08h seg=%010h seg_writes=%0d led_writes=%0d cyc=%0d time=%0t",
                             virtual_led, virtual_seg, seg_write_count, led_write_count, cycle_count, $time);
                    $finish;
                end
            end
        end
    end

    // ================================================================
    // MMIO / SEG read timing trace
    // ================================================================
    always @(posedge w_cpu_clk) begin
        if (!w_clk_rst && after_3rd_led &&
            cycle_count - after_3rd_led_cycle <= 220) begin

            // 1. CPU EX/MEM 发出 load 读请求时
            if (dut.Core_cpu.cpu_core.ex_is_load_o &&
                dut.Core_cpu.cpu_core.ex_rd_mem_addr_o == TRACE_SEG_ADDR) begin

                $display(
                    "SEG_LOAD_EX cyc=%0d dcyc=%0d | idex_pc=%08h idex_inst=%08h rd=%0d load_addr=%08h | cpu_ram_data_i=%08h | bridge_seg_wdata=%08h bridge_mmio_next=%08h bridge_mmio_r=%08h bridge_perip_rdata=%08h | rd_en=%b rd_addr=%08h rd_seg_r=%b rd_seg_rr=%b",
                    cycle_count,
                    cycle_count - after_3rd_led_cycle,

                    dut.Core_cpu.cpu_core.id_ex_inst_addr_o,
                    dut.Core_cpu.cpu_core.id_ex_inst_o,
                    dut.Core_cpu.cpu_core.ex_rd_addr_o,
                    dut.Core_cpu.cpu_core.ex_rd_mem_addr_o,

                    dut.Core_cpu.cpu_core.ram_data_i,

                    dut.bridge_inst.seg_wdata,
                    dut.bridge_inst.mmio_rdata_next,
                    dut.bridge_inst.mmio_rdata_r,
                    dut.bridge_inst.perip_rdata,

                    dut.bridge_inst.perip_rd_en,
                    dut.bridge_inst.perip_rd_addr,
                    dut.bridge_inst.rd_is_seg_r,
                    dut.bridge_inst.rd_is_seg_rr
                );
            end

            // 2. perip_bridge 收到 SEG 读请求时
            if (dut.bridge_inst.perip_rd_en &&
                dut.bridge_inst.perip_rd_addr == TRACE_SEG_ADDR) begin

                $display(
                    "SEG_READ_REQ cyc=%0d dcyc=%0d | perip_rd_en=%b perip_rd_addr=%08h | seg_wdata=%08h mmio_next=%08h mmio_r=%08h perip_rdata=%08h | rd_seg_r=%b rd_seg_rr=%b | cpu_mem_rd=%b cpu_mem_addr=%08h",
                    cycle_count,
                    cycle_count - after_3rd_led_cycle,

                    dut.bridge_inst.perip_rd_en,
                    dut.bridge_inst.perip_rd_addr,

                    dut.bridge_inst.seg_wdata,
                    dut.bridge_inst.mmio_rdata_next,
                    dut.bridge_inst.mmio_rdata_r,
                    dut.bridge_inst.perip_rdata,

                    dut.bridge_inst.rd_is_seg_r,
                    dut.bridge_inst.rd_is_seg_rr,

                    dut.Core_cpu.cpu_core.mem_rd_reg_o,
                    dut.Core_cpu.cpu_core.mem_rd_addr_o
                );
            end

            // 3. SEG 读请求进入 bridge pipeline 后的几拍
            if (dut.bridge_inst.rd_is_seg_r ||
                dut.bridge_inst.rd_is_seg_rr) begin

                $display(
                    "SEG_READ_PIPE cyc=%0d dcyc=%0d | seg_wdata=%08h mmio_next=%08h mmio_r=%08h perip_rdata=%08h | rd_seg_r=%b rd_seg_rr=%b | cpu_ram_data_i=%08h | mem2_inst=%08h mem2_rd=%0d mem2_wen=%b mem2_data=%08h | memwb_inst=%08h memwb_rd=%0d memwb_wen=%b memwb_data=%08h | wb_rd=%0d wb_wen=%b wb_data=%08h",
                    cycle_count,
                    cycle_count - after_3rd_led_cycle,

                    dut.bridge_inst.seg_wdata,
                    dut.bridge_inst.mmio_rdata_next,
                    dut.bridge_inst.mmio_rdata_r,
                    dut.bridge_inst.perip_rdata,

                    dut.bridge_inst.rd_is_seg_r,
                    dut.bridge_inst.rd_is_seg_rr,

                    dut.Core_cpu.cpu_core.ram_data_i,

                    dut.Core_cpu.cpu_core.mem2_inst_o,
                    dut.Core_cpu.cpu_core.mem2_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem2_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem2_rd_data_o,

                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.mem_wb_rd_data_o,

                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_wen_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o
                );
            end

            // 4. 专门抓写回 x13/x14
            if (dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                (dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd13 ||
                 dut.Core_cpu.cpu_core.wb_rd_addr_o == 5'd14)) begin

                $display(
                    "X13_X14_WB cyc=%0d dcyc=%0d | wb_inst=%08h rd=%0d data=%08h | x13=%08h x14=%08h | seg_wdata=%08h mmio_next=%08h mmio_r=%08h perip_rdata=%08h",
                    cycle_count,
                    cycle_count - after_3rd_led_cycle,

                    dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,

                    dut.Core_cpu.cpu_core.regs_inst.regs[13],
                    dut.Core_cpu.cpu_core.regs_inst.regs[14],

                    dut.bridge_inst.seg_wdata,
                    dut.bridge_inst.mmio_rdata_next,
                    dut.bridge_inst.mmio_rdata_r,
                    dut.bridge_inst.perip_rdata
                );
            end

            // 5. 栈地址 8012100c 的读写追踪
            if ((dut.perip_wstrb != 4'b0000 && dut.perip_addr == TRACE_STACK_ADDR) ||
                (dut.Core_cpu.cpu_core.ex_is_load_o &&
                 dut.Core_cpu.cpu_core.ex_rd_mem_addr_o == TRACE_STACK_ADDR)) begin

                $display(
                    "STACK_8012100C cyc=%0d dcyc=%0d | pc=%08h inst=%08h | wstrb=%b waddr=%08h wdata=%08h | load=%b load_addr=%08h load_rd=%0d | cpu_ram_data_i=%08h",
                    cycle_count,
                    cycle_count - after_3rd_led_cycle,

                    dut.pc,
                    dut.instruction,

                    dut.perip_wstrb,
                    dut.perip_addr,
                    dut.perip_wdata,

                    dut.Core_cpu.cpu_core.ex_is_load_o,
                    dut.Core_cpu.cpu_core.ex_rd_mem_addr_o,
                    dut.Core_cpu.cpu_core.ex_rd_addr_o,

                    dut.Core_cpu.cpu_core.ram_data_i
                );
            end
        end
    end

    initial begin
        #SIM_TIME_LIMIT_NS;
        $display("SEG_LED_STOP_TIMEOUT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led=%08h seg=%010h same_pc=%0d",
                 cycle_count, $time, dut.pc, dut.instruction,
                 seg_write_count, virtual_led, virtual_seg, same_pc_count);
        $finish;
    end
endmodule
