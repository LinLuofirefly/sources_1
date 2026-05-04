`timescale 1ns/1ps

module tb_issue_load_loop;
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
    reg  [31:0] last_pc_r;
    integer     cyc;

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

    always @(posedge clk) begin
        integer idx;
        idx = ram_rd_addr_r[31:2];
        if (!rst_n) begin
            ram_rd_addr_r <= 32'b0;
            ram_rd_en_r   <= 1'b0;
            ram_data_r    <= 32'b0;
        end else begin
            if (ram_rd_en_r) begin
                ram_data_r <= ram[idx];
            end
            ram_rd_addr_r <= mem_rd_addr;
            ram_rd_en_r   <= mem_rd_en;

            if (w_en[0]) ram[w_addr[31:2]][7:0]   <= w_data[7:0];
            if (w_en[1]) ram[w_addr[31:2]][15:8]  <= w_data[15:8];
            if (w_en[2]) ram[w_addr[31:2]][23:16] <= w_data[23:16];
            if (w_en[3]) ram[w_addr[31:2]][31:24] <= w_data[31:24];
        end
    end

    initial begin
        integer i;
        for (i = 0; i < 32; i = i + 1) begin
            rom[i] = 32'h0000_0013;
        end
        for (i = 0; i < 128; i = i + 1) begin
            ram[i] = 32'b0;
        end

        // addi x6, x0, 0x100
        rom[0] = 32'h1000_0313;
        // loop: lw x1, 0(x6)
        rom[1] = 32'h0003_2083;
        // beq x1, x0, done
        rom[2] = 32'h0000_8863;
        // addi x1, x1, -1
        rom[3] = 32'hfff0_8093;
        // sw x1, 0(x6)
        rom[4] = 32'h0013_2023;
        // jal x0, loop
        rom[5] = 32'hff1f_f06f;
        // done: addi x2, x0, 0x55
        rom[6] = 32'h0550_0113;
        // halt: jal x0, 0
        rom[7] = 32'h0000_006f;

        ram[32'h100 >> 2] = 32'd3;

        inst_r = 32'h0000_0013;
        ram_data_r = 32'b0;
        ram_rd_addr_r = 32'b0;
        ram_rd_en_r = 1'b0;
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

            if (uut.wb_rd_wen_o || (w_en != 4'b0)) begin
                $display("LOAD_LOOP_TRACE cyc=%0d pc=%08h wb=(%0d,%08h,%0d) memrd=(%0d,%08h,%08h) wr=(%04b,%08h,%08h) ifid=%08h issue=%08h idex=%08h x1=%08h x2=%08h x6=%08h mem=%08h",
                         cyc, last_pc_r,
                         uut.wb_rd_addr_o, uut.wb_rd_data_o, uut.wb_rd_wen_o,
                         mem_rd_en, mem_rd_addr, ram_data_r,
                         w_en, w_addr, w_data,
                         uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o,
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2], uut.regs_inst.regs[6],
                         ram[32'h100 >> 2]);
            end

            if ((uut.regs_inst.regs[2] == 32'h0000_0055) && (ram[32'h100 >> 2] == 32'd0)) begin
                $display("ISSUE_LOAD_LOOP_PASS cyc=%0d x1=%08h x2=%08h mem=%08h pc=%08h",
                         cyc, uut.regs_inst.regs[1], uut.regs_inst.regs[2],
                         ram[32'h100 >> 2], pc);
                $finish;
            end

            if (cyc > 200) begin
                $display("ISSUE_LOAD_LOOP_TIMEOUT x1=%08h x2=%08h x6=%08h mem=%08h pc=%08h ifid=%08h issue=%08h idex=%08h",
                         uut.regs_inst.regs[1], uut.regs_inst.regs[2], uut.regs_inst.regs[6],
                         ram[32'h100 >> 2], pc, uut.if_id_inst_o, uut.id_pipe_inst_o, uut.id_ex_inst_o);
                $finish;
            end
        end
    end
endmodule
