`timescale 1ns/1ps

module tb_pred_accept_replay;
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
    reg  [31:0] ram [0:127];
    reg  [31:0] ram_rd_addr_r;
    reg         ram_rd_en_r;
    integer cyc;
    reg saw_bad;

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

    always @(posedge clk) begin
        integer idx;
        idx = ram_rd_addr_r[31:2];
        if (!rst_n) begin
            ram_rd_addr_r <= 32'b0;
            ram_rd_en_r   <= 1'b0;
            ram_data_r    <= 32'b0;
        end else begin
            if (ram_rd_en_r) ram_data_r <= ram[idx];
            ram_rd_addr_r <= mem_rd_addr;
            ram_rd_en_r   <= mem_rd_en;
        end
    end

    initial begin
        integer i;
        for (i = 0; i < 32; i = i + 1) rom[i] = 32'h0000_0013;
        for (i = 0; i < 128; i = i + 1) ram[i] = 32'b0;

        // addi x6, x0, 0x100
        rom[0] = 32'h1000_0313;
        // lw x1, 0(x6)
        rom[1] = 32'h0003_2083;
        // addi x3, x1, 0   (forces replay behind load)
        rom[2] = 32'h0000_8193;
        // jal x0, target
        rom[3] = 32'h0080_006f;
        // wrong-path filler
        rom[4] = 32'h0012_0213;
        // target: addi x2, x0, 0x55
        rom[5] = 32'h0550_0113;
        // halt
        rom[6] = 32'h0000_006f;

        ram[32'h100 >> 2] = 32'h0000_0007;
        ram_data_r = 32'b0;
        ram_rd_addr_r = 32'b0;
        ram_rd_en_r = 1'b0;
        cyc = 0;
        saw_bad = 1'b0;
        #20 rst_n = 1'b1;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0;
            saw_bad <= 1'b0;
        end else begin
            cyc <= cyc + 1;
            if (uut.if_id_replaying_o && uut.bp_pred_taken_accepted_o) begin
                saw_bad <= 1'b1;
                $display("PRED_REPLAY_BAD cyc=%0d pc=%08h inst=%08h ifid=%08h issue=%08h idex=%08h bpacc=1 replay=1",
                         cyc, pc, inst_r, uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
            end
            if (uut.regs_inst.regs[2] == 32'h0000_0055) begin
                if (saw_bad) begin
                    $display("PRED_REPLAY_FAIL saw_bad=1 cyc=%0d x1=%08h x2=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2], pc);
                end else begin
                    $display("PRED_REPLAY_PASS cyc=%0d x1=%08h x2=%08h pc=%08h",
                             cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2], pc);
                end
                $finish;
            end
            if (cyc > 80) begin
                $display("PRED_REPLAY_TIMEOUT saw_bad=%0d x1=%08h x2=%08h pc=%08h replay=%0d bpacc=%0d",
                         saw_bad, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                         pc, uut.if_id_replaying_o, uut.bp_pred_taken_accepted_o);
                $finish;
            end
        end
    end
endmodule
