`timescale 1ns / 1ps
`include "defines.v"

module tb_fetch_warmup_probe;
    localparam [31:0] INST0 = 32'h00121117;
    localparam [31:0] INST1 = 32'h24410113;
    localparam [31:0] INST2 = 32'h16c010ef;
    localparam [31:0] INST3 = 32'h7a5000ef;

    reg clk = 1'b0;
    always #5 clk = ~clk;

    reg rst_short_n = 1'b0;
    reg rst_long_n  = 1'b0;

    wire [31:0] pc_sw;
    wire [31:0] pc_sn;
    wire [31:0] pc_lw;
    wire [31:0] pc_ln;

    reg [31:0] inst_sw;
    reg [31:0] inst_sn;
    reg [31:0] inst_lw;
    reg [31:0] inst_ln;

    wire [31:0] ram_data = 32'b0;
    wire [31:0] mmio_data = 32'b0;

    function automatic [31:0] rom_read(input [31:0] pc);
        begin
            case (pc[3:2])
                2'd0: rom_read = INST0;
                2'd1: rom_read = INST1;
                2'd2: rom_read = INST2;
                default: rom_read = INST3;
            endcase
        end
    endfunction

    always @(posedge clk) begin
        inst_sw <= rom_read(pc_sw);
        inst_sn <= rom_read(pc_sn);
        inst_lw <= rom_read(pc_lw);
        inst_ln <= rom_read(pc_ln);
    end

    open_risc_v short_warm (
        .clk(clk), .rst_n(rst_short_n), .inst_i(inst_sw),
        .ram_data_i(ram_data), .mmio_data_i(mmio_data),
        .pc_reg_pc_o(pc_sw), .mem_rd_reg_o(), .mem_rd_addr_o(),
        .w_en(), .w_addr_i(), .w_data_i()
    );

    open_risc_v_no_warm short_nowarm (
        .clk(clk), .rst_n(rst_short_n), .inst_i(inst_sn),
        .ram_data_i(ram_data), .mmio_data_i(mmio_data),
        .pc_reg_pc_o(pc_sn), .mem_rd_reg_o(), .mem_rd_addr_o(),
        .w_en(), .w_addr_i(), .w_data_i()
    );

    open_risc_v long_warm (
        .clk(clk), .rst_n(rst_long_n), .inst_i(inst_lw),
        .ram_data_i(ram_data), .mmio_data_i(mmio_data),
        .pc_reg_pc_o(pc_lw), .mem_rd_reg_o(), .mem_rd_addr_o(),
        .w_en(), .w_addr_i(), .w_data_i()
    );

    open_risc_v_no_warm long_nowarm (
        .clk(clk), .rst_n(rst_long_n), .inst_i(inst_ln),
        .ram_data_i(ram_data), .mmio_data_i(mmio_data),
        .pc_reg_pc_o(pc_ln), .mem_rd_reg_o(), .mem_rd_addr_o(),
        .w_en(), .w_addr_i(), .w_data_i()
    );

    initial begin
        repeat (1) @(posedge clk);
        #1 rst_short_n = 1'b1;

        repeat (4) @(posedge clk);
        #1 rst_long_n = 1'b1;

        repeat (8) @(posedge clk);
        $finish;
    end

    always @(posedge clk) begin
        #1;
        $display("cyc=%0t SHORT warm=%0d rst=%b pc=%h inst_i=%h bp_pc=%h ifid_v=%b ifid_pc=%h ifid_inst=%h idex_pc=%h idex_inst=%h",
                 $time, short_warm.fetch_warmup_r, rst_short_n,
                 pc_sw, inst_sw, short_warm.bp_fetch_pc_r,
                 short_warm.if_id_load_valid_o,
                 short_warm.if_id_inst_addr_o, short_warm.if_id_inst_o,
                 short_warm.id_ex_inst_addr_o, short_warm.id_ex_inst_o);
        $display("cyc=%0t SHORT no_warm rst=%b pc=%h inst_i=%h bp_pc=%h ifid_v=%b ifid_pc=%h ifid_inst=%h idex_pc=%h idex_inst=%h",
                 $time, rst_short_n,
                 pc_sn, inst_sn, short_nowarm.bp_fetch_pc_r,
                 short_nowarm.if_id_load_valid_o,
                 short_nowarm.if_id_inst_addr_o, short_nowarm.if_id_inst_o,
                 short_nowarm.id_ex_inst_addr_o, short_nowarm.id_ex_inst_o);
        $display("cyc=%0t LONG  warm=%0d rst=%b pc=%h inst_i=%h bp_pc=%h ifid_v=%b ifid_pc=%h ifid_inst=%h idex_pc=%h idex_inst=%h",
                 $time, long_warm.fetch_warmup_r, rst_long_n,
                 pc_lw, inst_lw, long_warm.bp_fetch_pc_r,
                 long_warm.if_id_load_valid_o,
                 long_warm.if_id_inst_addr_o, long_warm.if_id_inst_o,
                 long_warm.id_ex_inst_addr_o, long_warm.id_ex_inst_o);
        $display("cyc=%0t LONG  no_warm rst=%b pc=%h inst_i=%h bp_pc=%h ifid_v=%b ifid_pc=%h ifid_inst=%h idex_pc=%h idex_inst=%h",
                 $time, rst_long_n,
                 pc_ln, inst_ln, long_nowarm.bp_fetch_pc_r,
                 long_nowarm.if_id_load_valid_o,
                 long_nowarm.if_id_inst_addr_o, long_nowarm.if_id_inst_o,
                 long_nowarm.id_ex_inst_addr_o, long_nowarm.id_ex_inst_o);
        $display("");
    end
endmodule
