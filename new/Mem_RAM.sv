`timescale 1ns / 1ps
// ============================================================================
// 双端口数据 RAM 模型
// ----------------------------------------------------------------------------
// 用于 Verilator/仿真环境替代 Vivado Block RAM IP：
//   - Port A 支持同步读和 4-bit byte write enable；
//   - Port B 支持同步读，也保留 byte write enable 以贴近真双口 RAM 接口；
//   - 初始内容从 sim/dram.mem 加载。
//
// 注意：读数据在时钟上升沿寄存输出，等价于同步 RAM 一拍读延迟。
// ============================================================================
module Mem_RAM (
    input  wire        clka,
    input  wire [15:0] addra,
    input  wire [31:0] dina,
    output reg  [31:0] douta,
    input  wire        ena,
    input  wire [3:0]  wea,
    input  wire        clkb,
    input  wire [15:0] addrb,
    input  wire [31:0] dinb,
    output reg  [31:0] doutb,
    input  wire        enb,
    input  wire [3:0]  web
);
    reg [31:0] mem [0:65535];
    integer i;

    // 仿真初始化。先清零再读文件，避免 mem 文件较短时未覆盖地址保持 X。
    initial begin
        for (i = 0; i < 65536; i = i + 1) begin
            mem[i] = 32'h0000_0000;
        end
        $readmemh("sim/dram.mem", mem);
    end

    // A 端口：按字节写，随后同步读出 addra 对应 word。
    always @(posedge clka) begin
        if (ena) begin
            if (wea[0]) mem[addra][7:0]   <= dina[7:0];
            if (wea[1]) mem[addra][15:8]  <= dina[15:8];
            if (wea[2]) mem[addra][23:16] <= dina[23:16];
            if (wea[3]) mem[addra][31:24] <= dina[31:24];
        end
        douta <= mem[addra];
    end

    // B 端口：同步读为主，保留 web 写入口以匹配双口 RAM 形式。
    always @(posedge clkb) begin
        if (enb) begin
            doutb <= mem[addrb];
        end
        if (|web) begin
            if (web[0]) mem[addrb][7:0]   <= dinb[7:0];
            if (web[1]) mem[addrb][15:8]  <= dinb[15:8];
            if (web[2]) mem[addrb][23:16] <= dinb[23:16];
            if (web[3]) mem[addrb][31:24] <= dinb[31:24];
        end
    end
endmodule
