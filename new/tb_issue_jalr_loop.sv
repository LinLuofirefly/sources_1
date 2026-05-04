`timescale 1ns/1ps

module tb_issue_jalr_loop;
    reg clk = 1'b0;
    reg rst_n = 1'b0;

    wire [31:0] pc;
    wire        mem_rd_en;
    wire [31:0] mem_rd_addr;
    wire [3:0]  w_en;
    wire [31:0] w_addr;
    wire [31:0] w_data;

    reg  [31:0] inst_r;
    reg  [31:0] ram_data_r;
    reg  [31:0] rom [0:31];
    integer cyc;

    open_risc_v uut (
        .clk          (clk),
        .rst_n        (rst_n),
        .inst_i       (inst_r),
        .ram_data_i   (ram_data_r),
        .pc_reg_pc_o  (pc),
        .mem_rd_reg_o (mem_rd_en),
        .mem_rd_addr_o(mem_rd_addr),
        .w_en         (w_en),
        .w_addr_i     (w_addr),
        .w_data_i     (w_data)
    );

    always #5 clk = ~clk;

    always @(posedge clk) begin
        if (!rst_n) begin
            inst_r <= 32'h0000_0013;
        end else begin
            inst_r <= rom[(pc - 32'h8000_0000) >> 2];
        end
    end

    initial begin
        integer i;
        for (i = 0; i < 32; i = i + 1) rom[i] = 32'h0000_0013;

        // auipc x3, 0
        rom[0] = 32'h0000_0197;
        // addi x3, x3, 8   -> points to 0x80000008
        rom[1] = 32'h0081_8193;
        // loop: addi x4, x4, 1
        rom[2] = 32'h0012_0213;
        // jalr x0, 0(x3)
        rom[3] = 32'h0001_8067;

        ram_data_r = 32'b0;
        cyc = 0;
        #20 rst_n = 1'b1;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0;
        end else begin
            cyc <= cyc + 1;
            if (uut.wb_rd_wen_o) begin
                $display("JALR_LOOP_TRACE cyc=%0d pc=%08h rd=%0d data=%08h x3=%08h x4=%08h ifid=%08h issue=%08h idex=%08h",
                         cyc, pc, uut.wb_rd_addr_o, uut.wb_rd_data_o,
                         uut.regs_inst.regs[3], uut.regs_inst.regs[4],
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
            end
            if (uut.regs_inst.regs[4] >= 32'd5) begin
                $display("ISSUE_JALR_LOOP_PASS cyc=%0d x3=%08h x4=%08h pc=%08h",
                         cyc, uut.regs_inst.regs[3], uut.regs_inst.regs[4], pc);
                $finish;
            end
            if (cyc > 80) begin
                $display("ISSUE_JALR_LOOP_TIMEOUT x3=%08h x4=%08h pc=%08h ifid=%08h issue=%08h idex=%08h",
                         uut.regs_inst.regs[3], uut.regs_inst.regs[4], pc,
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
                $finish;
            end
        end
    end
endmodule
