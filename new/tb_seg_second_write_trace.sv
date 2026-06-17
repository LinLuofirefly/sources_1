`timescale 1ns / 1ps

module tb_seg_second_write_trace;

    reg         w_cpu_clk   = 1'b0;
    reg         w_clk_50Mhz = 1'b0;
    reg         w_clk_rst   = 1'b1;
    reg  [7:0]  virtual_key = 8'd0;
    reg  [63:0] virtual_sw  = 64'd0;
    wire [31:0] virtual_led;
    wire [39:0] virtual_seg;

    integer cycle;
    integer max_cycles;
    reg     done;

    localparam [31:0] A_1_9_ADDR     = 32'h8011_3a50;
    localparam [31:0] BT_1_9_ADDR    = 32'h8013_53a0;

    localparam [31:0] C2_LOAD_A_PC   = 32'h8000_06e4;
    localparam [31:0] C2_LOAD_BT_PC  = 32'h8000_0724;
    localparam [31:0] C2_MV_A1_PC    = 32'h8000_0728;
    localparam [31:0] C2_MV_A0_PC    = 32'h8000_072c;
    localparam [31:0] C2_CALL_MUL_PC = 32'h8000_0730;
    localparam [31:0] C2_RET_PC      = 32'h8000_0734;
    localparam [31:0] C2_ACCUM_PC    = 32'h8000_0744;

    localparam [31:0] MUL_ENTRY_PC   = 32'h8000_1fa8;
    localparam [31:0] MUL_CLEAR_PC   = 32'h8000_1fac;
    localparam [31:0] MUL_ANDI_PC    = 32'h8000_1fb0;
    localparam [31:0] MUL_BEQZ_PC    = 32'h8000_1fb4;
    localparam [31:0] MUL_ADD_PC     = 32'h8000_1fb8;
    localparam [31:0] MUL_SRLI_PC    = 32'h8000_1fbc;
    localparam [31:0] MUL_SLLI_PC    = 32'h8000_1fc0;
    localparam [31:0] MUL_LOOP_PC    = 32'h8000_1fc4;
    localparam [31:0] MUL_RET_PRE_PC = 32'h8000_1fc8;
    localparam [31:0] MUL_RET_PC     = 32'h8000_1fcc;

    reg c2_target_ctx;
    reg c2_done;
    integer c2_ctx_cnt;

    reg [31:0] last_c2_a_addr;
    integer    last_c2_a_cycle;

    reg [31:0] prev_idex_pc;
    reg [31:0] prev_idex_inst;
    reg [31:0] prev_a1;
    reg [31:0] prev_a3;
    reg [31:0] prev_idex_base;
    reg [31:0] prev_fwd_base;
    reg [31:0] prev_wb_data;
    reg [4:0]  prev_wb_rd;
    reg        prev_wb_wen;

    student_top dut (
        .w_cpu_clk   (w_cpu_clk),
        .w_clk_50Mhz (w_clk_50Mhz),
        .w_clk_rst   (w_clk_rst),
        .virtual_key (virtual_key),
        .virtual_sw  (virtual_sw),
        .virtual_led (virtual_led),
        .virtual_seg (virtual_seg)
    );

    always #2.5 w_cpu_clk = ~w_cpu_clk;
    always #10  w_clk_50Mhz = ~w_clk_50Mhz;

    wire [31:0] idex_pc     = dut.Core_cpu.cpu_core.id_ex_inst_addr_o;
    wire [31:0] idex_inst   = dut.Core_cpu.cpu_core.id_ex_inst_o;
    wire        valid_idex  = !dut.Core_cpu.cpu_core.ctrl_kill_ex_o;
    wire [31:0] eff_addr    = dut.Core_cpu.cpu_core.fwd_base_addr_o;

    task print_state;
        input [8*64-1:0] tag;
        begin
            $display("%0s cyc=%0d pc=%08h ifid_pc=%08h idex_pc=%08h idex_inst=%08h ra=%08h a0=%08h a1=%08h a2=%08h a3=%08h a4=%08h a5=%08h fwd_base=%08h fwd_store=%08h ex_data=%08h ex_wen=%b wb_rd=%0d wb_data=%08h wb_wen=%b exJ=%b exAddr=%08h hold=%b kill=%b",
                tag, cycle, dut.pc,
                dut.Core_cpu.cpu_core.if_id_inst_addr_o,
                idex_pc, idex_inst,
                dut.Core_cpu.cpu_core.regs_inst.regs[1],
                dut.Core_cpu.cpu_core.regs_inst.regs[10],
                dut.Core_cpu.cpu_core.regs_inst.regs[11],
                dut.Core_cpu.cpu_core.regs_inst.regs[12],
                dut.Core_cpu.cpu_core.regs_inst.regs[13],
                dut.Core_cpu.cpu_core.regs_inst.regs[14],
                dut.Core_cpu.cpu_core.regs_inst.regs[15],
                eff_addr, dut.Core_cpu.cpu_core.fwd_store_data_o,
                dut.Core_cpu.cpu_core.ex_wd_data_o,
                dut.Core_cpu.cpu_core.ex_wd_reg_o,
                dut.Core_cpu.cpu_core.wb_rd_addr_o,
                dut.Core_cpu.cpu_core.wb_rd_data_o,
                dut.Core_cpu.cpu_core.wb_rd_wen_o,
                dut.Core_cpu.cpu_core.ex_jump_en_o,
                dut.Core_cpu.cpu_core.ex_jump_addr_o,
                dut.Core_cpu.cpu_core.hdu_hold_flag_o,
                dut.Core_cpu.cpu_core.ctrl_kill_ex_o);
        end
    endtask

    task print_prev_for_branch;
        begin
            $display("PREV cyc=%0d prev_pc=%08h prev_inst=%08h prev_a1=%08h prev_a3=%08h",
                cycle, prev_idex_pc, prev_idex_inst, prev_a1, prev_a3);
        end
    endtask

    initial begin
        cycle = 0; max_cycles = 300000000; done = 1'b0;
        c2_target_ctx = 1'b0; c2_done = 1'b0; c2_ctx_cnt = 0;
        last_c2_a_addr = 32'h0; last_c2_a_cycle = 0;
        prev_idex_pc = 0; prev_idex_inst = 0; prev_a1 = 0; prev_a3 = 0;
        prev_idex_base = 0; prev_fwd_base = 0; prev_wb_data = 0; prev_wb_rd = 0; prev_wb_wen = 0;
        repeat (20) @(posedge w_cpu_clk);
        w_clk_rst = 1'b0;
    end

    always @(posedge w_cpu_clk) begin
        if (w_clk_rst) begin
            cycle <= 0; done <= 1'b0;
            c2_target_ctx <= 1'b0; c2_done <= 1'b0; c2_ctx_cnt <= 0;
            last_c2_a_addr <= 0; last_c2_a_cycle <= 0;
            prev_idex_pc <= 0; prev_idex_inst <= 0; prev_a1 <= 0; prev_a3 <= 0;
            prev_idex_base <= 0; prev_fwd_base <= 0; prev_wb_data <= 0; prev_wb_rd <= 0; prev_wb_wen <= 0;
        end else if (!done) begin
            cycle <= cycle + 1;

            // Track C2 A loads
            if (valid_idex && idex_pc == C2_LOAD_A_PC) begin
                last_c2_a_addr <= eff_addr;
                last_c2_a_cycle <= cycle;
                if (eff_addr == A_1_9_ADDR) print_state("C2_LOAD_A_1_9_SEEN");
            end

            // Start C2 context when A[1][9] + BT[1][9]
            if (valid_idex && idex_pc == C2_LOAD_BT_PC &&
                eff_addr == BT_1_9_ADDR &&
                last_c2_a_addr == A_1_9_ADDR &&
                !c2_target_ctx && !c2_done) begin
                c2_target_ctx <= 1'b1; c2_ctx_cnt <= 0;
                $display(""); $display("=== C2 TRUE TARGET row=1 col=1 k=9 CONTEXT START ===");
                $display("LAST_C2_A: cyc=%0d addr=%08h", last_c2_a_cycle, last_c2_a_addr);
                print_state("C2_LOAD_BT_1_9");
            end

            // C2 context
            if (c2_target_ctx) begin
                c2_ctx_cnt <= c2_ctx_cnt + 1;

                if (valid_idex && idex_pc == C2_MV_A1_PC) print_state("C2_MV_A1");
                if (valid_idex && idex_pc == C2_MV_A0_PC) print_state("C2_MV_A0");
                if (valid_idex && idex_pc == C2_CALL_MUL_PC) print_state("C2_CALL_MUL");
                if (valid_idex && idex_pc == MUL_ENTRY_PC) print_state("MUL_ENTRY");
                if (valid_idex && idex_pc == MUL_CLEAR_PC) print_state("MUL_CLEAR");
                if (valid_idex && idex_pc == MUL_ANDI_PC) print_state("MUL_ANDI");
                if (valid_idex && idex_pc == MUL_BEQZ_PC) begin
                    print_state("MUL_BEQZ");
                    print_prev_for_branch();
                    $display("");
                end
                if (valid_idex && idex_pc == MUL_ADD_PC) print_state("MUL_ADD");
                if (valid_idex && idex_pc == MUL_SRLI_PC) print_state("MUL_SRLI");
                if (valid_idex && idex_pc == MUL_SLLI_PC) print_state("MUL_SLLI");
                if (valid_idex && idex_pc == MUL_LOOP_PC) print_state("MUL_LOOP");
                if (valid_idex && idex_pc == MUL_RET_PC) print_state("MUL_RET");
                if (valid_idex && idex_pc == C2_RET_PC) print_state("C2_RET");
                if (valid_idex && idex_pc == C2_ACCUM_PC) begin
                    print_state("C2_ACCUM");
                    $display("=== C2 CONTEXT END ==="); $display("");
                    c2_target_ctx <= 1'b0; c2_done <= 1'b1;
                end

                if (c2_ctx_cnt > 500) begin
                    $display("ERROR: C2 timeout"); done <= 1'b1; $finish;
                end
            end

            // WB for a0-a3,a5 during context
            if (c2_target_ctx && dut.Core_cpu.cpu_core.wb_rd_wen_o &&
                (dut.Core_cpu.cpu_core.wb_rd_addr_o inside {5'd10, 5'd11, 5'd12, 5'd13, 5'd15})) begin
                $display("WB cyc=%0d inst=%08h rd=%0d data=%08h a0=%08h a1=%08h a2=%08h a3=%08h a5=%08h",
                    cycle, dut.Core_cpu.cpu_core.mem_wb_inst_o,
                    dut.Core_cpu.cpu_core.wb_rd_addr_o,
                    dut.Core_cpu.cpu_core.wb_rd_data_o,
                    dut.Core_cpu.cpu_core.regs_inst.regs[10],
                    dut.Core_cpu.cpu_core.regs_inst.regs[11],
                    dut.Core_cpu.cpu_core.regs_inst.regs[12],
                    dut.Core_cpu.cpu_core.regs_inst.regs[13],
                    dut.Core_cpu.cpu_core.regs_inst.regs[15]);
            end

            if (c2_done) begin
                $display("=== DONE ==="); done <= 1'b1; $finish;
            end

            if (cycle >= max_cycles) begin
                $display("ERROR: timeout"); done <= 1'b1; $finish;
            end

            // Save prev for branch debug
            prev_idex_pc <= idex_pc; prev_idex_inst <= idex_inst;
            prev_a1 <= dut.Core_cpu.cpu_core.regs_inst.regs[11];
            prev_a3 <= dut.Core_cpu.cpu_core.regs_inst.regs[13];
        end
    end
endmodule
