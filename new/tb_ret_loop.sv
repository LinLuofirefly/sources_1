`timescale 1ns/1ps

module tb_ret_loop;
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
        if (!rst_n) inst_r <= 32'h0000_0013;
        else        inst_r <= rom[(pc - 32'h8000_0000) >> 2];
    end

    initial begin
        integer i;
        for (i = 0; i < 32; i = i + 1) rom[i] = 32'h0000_0013;

        // addi x2, x0, 5
        rom[0] = 32'h0050_0113;
        // jal x1, func
        rom[1] = 32'h0140_00ef;
        // addi x2, x2, -1
        rom[2] = 32'hfff1_0113;
        // bne x2, x0, call
        rom[3] = 32'hfe01_1ce3;
        // addi x5, x0, 0x55
        rom[4] = 32'h0550_0293;
        // halt
        rom[5] = 32'h0000_006f;
        // func: addi x4, x4, 1
        rom[6] = 32'h0012_0213;
        // ret
        rom[7] = 32'h0000_8067;

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
                $display("RET_LOOP_TRACE cyc=%0d pc=%08h rd=%0d data=%08h x1=%08h x2=%08h x4=%08h x5=%08h ifid=%08h issue=%08h idex=%08h",
                         cyc, pc, uut.wb_rd_addr_o, uut.wb_rd_data_o,
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                         uut.regs_inst.regs[4], uut.regs_inst.regs[5],
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
            end
            if (uut.regs_inst.regs[5] == 32'h0000_0055) begin
                if ((uut.regs_inst.regs[4] == 32'd5) && (uut.regs_inst.regs[2] == 32'd0)) begin
                    $display("RET_LOOP_PASS cyc=%0d x1=%08h x2=%08h x4=%08h x5=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                             uut.regs_inst.regs[4], uut.regs_inst.regs[5], pc);
                end else begin
                    $display("RET_LOOP_FAIL_BAD_STATE cyc=%0d x1=%08h x2=%08h x4=%08h x5=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                             uut.regs_inst.regs[4], uut.regs_inst.regs[5], pc);
                end
                $finish;
            end
            if (cyc > 120) begin
                $display("RET_LOOP_TIMEOUT x1=%08h x2=%08h x4=%08h x5=%08h pc=%08h ifid=%08h issue=%08h idex=%08h",
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2], uut.regs_inst.regs[4], uut.regs_inst.regs[5],
                         pc, uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
                $finish;
            end
        end
    end
endmodule
