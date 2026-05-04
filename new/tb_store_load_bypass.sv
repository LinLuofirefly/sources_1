`timescale 1ns/1ps

module tb_store_load_bypass;
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
    reg  [31:0] ram_committed [0:127];
    reg         store_pending_v_r;
    reg  [31:0] store_pending_addr_r;
    reg  [31:0] store_pending_data_r;
    reg  [3:0]  store_pending_strb_r;
    reg  [31:0] ram_rd_addr_r;
    reg         ram_rd_en_r;
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

    always @(posedge clk) begin
        integer idx;
        idx = ram_rd_addr_r[31:2];
        if (!rst_n) begin
            ram_data_r <= 32'b0;
            ram_rd_addr_r <= 32'b0;
            ram_rd_en_r <= 1'b0;
            store_pending_v_r <= 1'b0;
            store_pending_addr_r <= 32'b0;
            store_pending_data_r <= 32'b0;
            store_pending_strb_r <= 4'b0;
        end else begin
            if (store_pending_v_r) begin
                if (store_pending_strb_r[0]) ram_committed[store_pending_addr_r[31:2]][7:0]   <= store_pending_data_r[7:0];
                if (store_pending_strb_r[1]) ram_committed[store_pending_addr_r[31:2]][15:8]  <= store_pending_data_r[15:8];
                if (store_pending_strb_r[2]) ram_committed[store_pending_addr_r[31:2]][23:16] <= store_pending_data_r[23:16];
                if (store_pending_strb_r[3]) ram_committed[store_pending_addr_r[31:2]][31:24] <= store_pending_data_r[31:24];
            end

            if (ram_rd_en_r) ram_data_r <= ram_committed[idx];
            ram_rd_addr_r <= mem_rd_addr;
            ram_rd_en_r   <= mem_rd_en;

            store_pending_v_r    <= (w_en != 4'b0000);
            store_pending_addr_r <= w_addr;
            store_pending_data_r <= w_data;
            store_pending_strb_r <= w_en;
        end
    end

    initial begin
        integer i;
        for (i = 0; i < 32; i = i + 1) rom[i] = 32'h0000_0013;
        for (i = 0; i < 128; i = i + 1) ram_committed[i] = 32'b0;

        // addi x6, x0, 0x100
        rom[0] = 32'h1000_0313;
        // addi x10, x0, 0x66
        rom[1] = 32'h0660_0513;
        // sw x10, 0(x6)
        rom[2] = 32'h00a3_2023;
        // lw x11, 0(x6)
        rom[3] = 32'h0003_2583;
        // addi x2, x11, 0
        rom[4] = 32'h0005_8113;
        // halt
        rom[5] = 32'h0000_006f;

        inst_r = 32'h0000_0013;
        ram_data_r = 32'b0;
        store_pending_v_r = 1'b0;
        store_pending_addr_r = 32'b0;
        store_pending_data_r = 32'b0;
        store_pending_strb_r = 4'b0;
        ram_rd_addr_r = 32'b0;
        ram_rd_en_r = 1'b0;
        cyc = 0;
        #20 rst_n = 1'b1;
    end

    always @(posedge clk) begin
        if (!rst_n) begin
            cyc <= 0;
        end else begin
            cyc <= cyc + 1;
            if (uut.wb_rd_wen_o || (w_en != 4'b0) || mem_rd_en) begin
                $display("STORE_LOAD_TRACE cyc=%0d pc=%08h wb=(%0d,%08h,%0d) rd=(%0d,%08h,%08h) wr=(%04b,%08h,%08h) x10=%08h x11=%08h x2=%08h",
                         cyc, pc, uut.wb_rd_addr_o, uut.wb_rd_data_o, uut.wb_rd_wen_o,
                         mem_rd_en, mem_rd_addr, ram_data_r, w_en, w_addr, w_data,
                         uut.regs_inst.regs[10], uut.regs_inst.regs[11], uut.regs_inst.regs[2]);
            end
            if (uut.regs_inst.regs[2] == 32'h0000_0066) begin
                $display("STORE_LOAD_BYPASS_PASS cyc=%0d x10=%08h x11=%08h x2=%08h pc=%08h",
                         cyc, uut.regs_inst.regs[10], uut.regs_inst.regs[11], uut.regs_inst.regs[2], pc);
                $finish;
            end
            if (cyc > 60) begin
                $display("STORE_LOAD_BYPASS_TIMEOUT x10=%08h x11=%08h x2=%08h pc=%08h",
                         uut.regs_inst.regs[10], uut.regs_inst.regs[11], uut.regs_inst.regs[2], pc);
                $finish;
            end
        end
    end
endmodule
