`timescale 1ns / 1ps

module tb_issue_tight_loop;
    reg         clk;
    reg         rst_n;
    wire [31:0] pc;
    wire        mem_rd_en;
    wire [31:0] mem_rd_addr;
    wire [3:0]  w_en;
    wire [31:0] w_addr;
    wire [31:0] w_data;

    reg  [31:0] inst_i;
    reg  [31:0] rom [0:15];
    wire [31:0] ram_data_i = 32'b0;
    integer cycle_count;

    open_risc_v uut (
        .clk         (clk),
        .rst_n       (rst_n),
        .inst_i      (inst_i),
        .ram_data_i  (ram_data_i),
        .pc_reg_pc_o (pc),
        .mem_rd_reg_o(mem_rd_en),
        .mem_rd_addr_o(mem_rd_addr),
        .w_en        (w_en),
        .w_addr_i    (w_addr),
        .w_data_i    (w_data)
    );

    initial clk = 1'b0;
    always #3.333 clk = ~clk;

    initial begin
        rom[0] = 32'h0030_0093; // addi x1, x0, 3
        rom[1] = 32'hfff0_8093; // addi x1, x1, -1
        rom[2] = 32'hfe00_9ee3; // bne  x1, x0, -4
        rom[3] = 32'h0550_0113; // addi x2, x0, 0x55
        rom[4] = 32'h0000_006f; // jal  x0, 0
        rom[5] = 32'h0000_0013;
        rom[6] = 32'h0000_0013;
        rom[7] = 32'h0000_0013;
        rom[8] = 32'h0000_0013;
        rom[9] = 32'h0000_0013;
        rom[10] = 32'h0000_0013;
        rom[11] = 32'h0000_0013;
        rom[12] = 32'h0000_0013;
        rom[13] = 32'h0000_0013;
        rom[14] = 32'h0000_0013;
        rom[15] = 32'h0000_0013;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            inst_i <= 32'h0000_0013;
        end else if ((pc >= 32'h8000_0000) && (pc < 32'h8000_0040)) begin
            inst_i <= rom[(pc - 32'h8000_0000) >> 2];
        end else begin
            inst_i <= 32'h0000_0013;
        end
    end

    initial begin
        rst_n = 1'b0;
        inst_i = 32'h0000_0013;
        cycle_count = 0;
        #20;
        rst_n = 1'b1;
    end

    always @(posedge clk) begin
        if (rst_n) begin
            cycle_count = cycle_count + 1;

            if (uut.wb_rd_wen_o && ((uut.wb_rd_addr_o == 5'd1) || (uut.wb_rd_addr_o == 5'd2))) begin
                $display("LOOP_WB cyc=%0d pc=%08h rd=%0d data=%08h x1=%08h x2=%08h ifid=%08h issue=%08h idex=%08h",
                         cycle_count, pc, uut.wb_rd_addr_o, uut.wb_rd_data_o,
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
            end

            if (uut.regs_inst.regs[2] == 32'h0000_0055) begin
                if (uut.regs_inst.regs[1] == 32'h0000_0000) begin
                    $display("ISSUE_TIGHT_LOOP_PASS cyc=%0d x1=%08h x2=%08h pc=%08h",
                             cycle_count, uut.regs_inst.regs[1], uut.regs_inst.regs[2], pc);
                    $finish;
                end else begin
                    $display("ISSUE_TIGHT_LOOP_FAIL_BAD_X1 cyc=%0d x1=%08h x2=%08h pc=%08h",
                             cycle_count, uut.regs_inst.regs[1], uut.regs_inst.regs[2], pc);
                    $finish;
                end
            end

            if (cycle_count >= 200) begin
                $display("ISSUE_TIGHT_LOOP_TIMEOUT x1=%08h x2=%08h pc=%08h ifid=%08h issue=%08h idex=%08h",
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2], pc,
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
                $finish;
            end
        end
    end
endmodule
