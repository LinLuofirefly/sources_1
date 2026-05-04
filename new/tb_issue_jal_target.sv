`timescale 1ns/1ps

module tb_issue_jal_target;
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
    reg  [31:0] last_pc_r;
    integer     cyc;

    open_risc_v uut (
        .clk         (clk),
        .rst_n       (rst_n),
        .inst_i      (inst_r),
        .ram_data_i  (ram_data_r),
        .pc_reg_pc_o (pc),
        .mem_rd_reg_o(mem_rd_en),
        .mem_rd_addr_o(mem_rd_addr),
        .w_en        (w_en),
        .w_addr_i    (w_addr),
        .w_data_i    (w_data)
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
        for (i = 0; i < 32; i = i + 1) begin
            rom[i] = 32'h0000_0013;
        end

        // 0x8000_0000: addi x4, x0, 1
        rom[0] = 32'h0010_0213;
        // 0x8000_0004: jal x1, 0x8000_0010
        rom[1] = 32'h00c0_00ef;
        // 0x8000_0008: addi x2, x0, 0x55
        rom[2] = 32'h0550_0113;
        // 0x8000_000c: jal x0, 0x8000_0018
        rom[3] = 32'h00c0_006f;
        // 0x8000_0010: addi x3, x3, 1
        rom[4] = 32'h0011_8193;
        // 0x8000_0014: jalr x0, 0(x1)
        rom[5] = 32'h0000_8067;
        // 0x8000_0018: jal x0, 0
        rom[6] = 32'h0000_006f;

        ram_data_r = 32'b0;
        cyc = 0;
        last_pc_r = 32'h8000_0000;

        #20;
        rst_n = 1'b1;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0;
            last_pc_r <= 32'h8000_0000;
        end else begin
            cyc <= cyc + 1;
            last_pc_r <= pc;

            if (uut.wb_rd_wen_o) begin
                $display("JAL_TGT_WB cyc=%0d pc=%08h rd=%0d data=%08h x1=%08h x2=%08h x3=%08h x4=%08h ifid=%08h issue=%08h idex=%08h",
                         cyc, last_pc_r, uut.wb_rd_addr_o, uut.wb_rd_data_o,
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                         uut.regs_inst.regs[3], uut.regs_inst.regs[4],
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
            end

            if ((uut.regs_inst.regs[2] == 32'h0000_0055) && (pc == 32'h8000_0018)) begin
                if (uut.regs_inst.regs[3] == 32'h0000_0001) begin
                    $display("ISSUE_JAL_TARGET_PASS cyc=%0d x1=%08h x2=%08h x3=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                             uut.regs_inst.regs[3], pc);
                end else begin
                    $display("ISSUE_JAL_TARGET_FAIL_BAD_X3 cyc=%0d x1=%08h x2=%08h x3=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                             uut.regs_inst.regs[3], pc);
                end
                $finish;
            end

            if (cyc > 80) begin
                $display("ISSUE_JAL_TARGET_TIMEOUT x1=%08h x2=%08h x3=%08h pc=%08h ifid=%08h issue=%08h idex=%08h",
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2], uut.regs_inst.regs[3],
                         pc, uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
                $finish;
            end
        end
    end
endmodule
