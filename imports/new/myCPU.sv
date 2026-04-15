`timescale 1ns / 1ps

module myCPU (
    input  logic         cpu_rst,
    input  logic         cpu_clk,

    output logic [31:0]  irom_addr,
    input  logic [31:0]  irom_data,

    output logic [31:0]  perip_addr,
    output logic [3:0]   perip_wen,
    output logic [31:0]  perip_wdata,
    input  logic [31:0]  perip_rdata,
    output logic [31:0]  perip_rd_addr,
    output logic         perip_rd_en
);

    open_risc_v cpu_core (
        .clk           (cpu_clk),
        .rst_n         (~cpu_rst),
        .inst_i        (irom_data),
        .ram_data_i    (perip_rdata),
        .pc_reg_pc_o   (irom_addr),
        .mem_rd_reg_o  (perip_rd_en),
        .mem_rd_addr_o (perip_rd_addr),
        .w_en          (perip_wen),
        .w_addr_i      (perip_addr),
        .w_data_i      (perip_wdata)
    );

    /*always_comb begin
        perip_wen = |mem_wen;  //将mem_wen的4位进行或运算，如果有一个位为1，则perip_wen为1，否则为0

        if (perip_wen) begin
            perip_addr  = mem_waddr;
            perip_wdata = mem_wdata;
            unique case (mem_wen)
                4'b0001,
                4'b0010,
                4'b0100,
                4'b1000: perip_mask = 2'b00;
                4'b0011,
                4'b1100: perip_mask = 2'b01;
                4'b1111: perip_mask = 2'b10;
                default: perip_mask = 2'b10;
            endcase
        end else begin
            perip_addr  = mem_rd_en ? mem_rd_addr : 32'b0;
            perip_wdata = 32'b0;
            perip_mask  = mem_rd_en ? mem_rd_mask : 2'b10;
        end
    end
   */
endmodule
