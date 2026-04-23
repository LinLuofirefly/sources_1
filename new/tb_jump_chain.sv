`timescale 1ns / 1ps

module tb_jump_chain;
    reg         clk;
    reg         rst;
    wire [31:0] irom_addr;
    reg  [31:0] irom_data;
    wire [31:0] perip_addr;
    wire [3:0]  perip_wen;
    wire [31:0] perip_wdata;
    wire [31:0] perip_rd_addr;
    wire        perip_rd_en;

    reg [31:0] rom [0:63];
    integer i;
    integer cyc;

    myCPU dut (
        .cpu_rst      (rst),
        .cpu_clk      (clk),
        .irom_addr    (irom_addr),
        .irom_data    (irom_data),
        .perip_addr   (perip_addr),
        .perip_wen    (perip_wen),
        .perip_wdata  (perip_wdata),
        .perip_rdata  (32'b0),
        .perip_rd_addr(perip_rd_addr),
        .perip_rd_en  (perip_rd_en)
    );

    initial clk = 1'b0;
    always #1 clk = ~clk;

    // Match Mem_IROM's synchronous read behavior.
    always @(posedge clk) begin
        irom_data <= rom[irom_addr[13:2]];
    end

    initial begin
        for (i = 0; i < 64; i = i + 1) begin
            rom[i] = 32'h00000013;
        end

        // Back-to-back JAL: the second jump at 0x8000_0004 must be killed.
        rom[0]  = 32'h010000ef; // 0x8000_0000: jal  x1, 0x8000_0010
        rom[1]  = 32'h0440016f; // 0x8000_0004: jal  x2, 0x8000_0048 (wrong path)
        rom[2]  = 32'h05500513; // 0x8000_0008: addi x10, x0, 0x55 (wrong path marker)
        rom[3]  = 32'h00000013; // 0x8000_000c: nop

        // Correct target of the first JAL.
        rom[4]  = 32'h01100193; // 0x8000_0010: addi x3, x0, 0x11
        rom[5]  = 32'h800002b7; // 0x8000_0014: lui  x5, 0x80000
        rom[6]  = 32'h03428293; // 0x8000_0018: addi x5, x5, 0x34
        rom[7]  = 32'h80000337; // 0x8000_001c: lui  x6, 0x80000
        rom[8]  = 32'h04830313; // 0x8000_0020: addi x6, x6, 0x48

        // Back-to-back JALR: the second jump at 0x8000_0028 must be killed.
        rom[9]  = 32'h000283e7; // 0x8000_0024: jalr x7, x5, 0
        rom[10] = 32'h00030467; // 0x8000_0028: jalr x8, x6, 0 (wrong path)
        rom[11] = 32'h06600513; // 0x8000_002c: addi x10, x0, 0x66 (wrong path marker)
        rom[12] = 32'h00000013; // 0x8000_0030: nop

        // Correct target of the first JALR.
        rom[13] = 32'h03300493; // 0x8000_0034: addi x9, x0, 0x33
        rom[14] = 32'h0180006f; // 0x8000_0038: jal  x0, 0x8000_0050
        rom[15] = 32'h07700593; // 0x8000_003c: addi x11, x0, 0x77 (wrong path marker)
        rom[16] = 32'h00000013; // 0x8000_0040: nop
        rom[17] = 32'h00000013; // 0x8000_0044: nop

        // Wrong-path targets that must never retire.
        rom[18] = 32'h04400213; // 0x8000_0048: addi x4,  x0, 0x44
        rom[19] = 32'h08800613; // 0x8000_004c: addi x12, x0, 0x88

        // Final pass marker.
        rom[20] = 32'h07b00f93; // 0x8000_0050: addi x31, x0, 0x7b
        rom[21] = 32'h0000006f; // 0x8000_0054: jal  x0, self

        rst = 1'b1;
        irom_data = 32'h00000013;
        cyc = 0;
        #8;
        rst = 1'b0;

        repeat (80) @(posedge clk);

        $display("JUMP_CHAIN PC=%08h x1=%08h x2=%08h x3=%08h x4=%08h x5=%08h x6=%08h x7=%08h x8=%08h x9=%08h x10=%08h x11=%08h x12=%08h x31=%08h",
                 irom_addr,
                 dut.cpu_core.regs_inst.regs[1],
                 dut.cpu_core.regs_inst.regs[2],
                 dut.cpu_core.regs_inst.regs[3],
                 dut.cpu_core.regs_inst.regs[4],
                 dut.cpu_core.regs_inst.regs[5],
                 dut.cpu_core.regs_inst.regs[6],
                 dut.cpu_core.regs_inst.regs[7],
                 dut.cpu_core.regs_inst.regs[8],
                 dut.cpu_core.regs_inst.regs[9],
                 dut.cpu_core.regs_inst.regs[10],
                 dut.cpu_core.regs_inst.regs[11],
                 dut.cpu_core.regs_inst.regs[12],
                 dut.cpu_core.regs_inst.regs[31]);

        if (dut.cpu_core.regs_inst.regs[1]  !== 32'h0000_0004) begin $display("FAIL_x1");  $finish; end
        if (dut.cpu_core.regs_inst.regs[3]  !== 32'h0000_0011) begin $display("FAIL_x3");  $finish; end
        if (dut.cpu_core.regs_inst.regs[5]  !== 32'h8000_0034) begin $display("FAIL_x5");  $finish; end
        if (dut.cpu_core.regs_inst.regs[6]  !== 32'h8000_0048) begin $display("FAIL_x6");  $finish; end
        if (dut.cpu_core.regs_inst.regs[7]  !== 32'h0000_0028) begin $display("FAIL_x7");  $finish; end
        if (dut.cpu_core.regs_inst.regs[9]  !== 32'h0000_0033) begin $display("FAIL_x9");  $finish; end
        if (dut.cpu_core.regs_inst.regs[4]  === 32'h0000_0044) begin $display("FAIL_x4");  $finish; end
        if (dut.cpu_core.regs_inst.regs[10] === 32'h0000_0055) begin $display("FAIL_x10a");$finish; end
        if (dut.cpu_core.regs_inst.regs[10] === 32'h0000_0066) begin $display("FAIL_x10b");$finish; end
        if (dut.cpu_core.regs_inst.regs[11] === 32'h0000_0077) begin $display("FAIL_x11"); $finish; end
        if (dut.cpu_core.regs_inst.regs[12] === 32'h0000_0088) begin $display("FAIL_x12"); $finish; end
        if (dut.cpu_core.regs_inst.regs[31] !== 32'h0000_007b) begin $display("FAIL_x31"); $finish; end

        $display("JUMP_CHAIN_PASS");
        $finish;
    end

    always @(posedge clk) begin
        if (!rst) begin
            cyc = cyc + 1;
            if (cyc <= 30) begin
                $display("TRACE CYC=%0d PC=%08h IROM=%08h IFID=%08h IDEX=%08h EXJ=%b KILL=%b FLUSHI=%b FLUSHD=%b x1=%08h x2=%08h x3=%08h x4=%08h x7=%08h x8=%08h",
                         cyc,
                         irom_addr,
                         irom_data,
                         dut.cpu_core.if_id_inst_o,
                         dut.cpu_core.id_ex_inst_o,
                         dut.cpu_core.ex_jump_en_o,
                         dut.cpu_core.ctrl_kill_ex_o,
                         dut.cpu_core.ctrl_flush_ifid_o,
                         dut.cpu_core.ctrl_flush_idex_o,
                         dut.cpu_core.regs_inst.regs[1],
                         dut.cpu_core.regs_inst.regs[2],
                         dut.cpu_core.regs_inst.regs[3],
                         dut.cpu_core.regs_inst.regs[4],
                         dut.cpu_core.regs_inst.regs[7],
                         dut.cpu_core.regs_inst.regs[8]);
            end
        end
    end
endmodule
