`timescale 1ns / 1ps
// ============================================================================
// 指令 ROM 模型
// ----------------------------------------------------------------------------
// 用于仿真环境的同步 IROM：
//   - 地址按 32-bit word 编址；
//   - 内容从 sim/irom.mem 加载；
//   - douta 在 clka 上升沿更新，因此取指有一拍同步读延迟。
//
// dina 仅用于保持接口形状，当前 ROM 不写入。
// ============================================================================
module Mem_IROM (
    input  wire [11:0] addra,
    output reg  [31:0] douta,
    input  wire        clka,
    input  wire [31:0] dina
);
    reg [31:0] mem [0:4095];

    // 仿真启动时加载指令镜像。
    initial begin
        $readmemh("sim/irom.mem", mem);
    end

    // 同步读：PC 请求后一拍返回 instruction。
    always @(posedge clka) begin
        douta <= mem[addra];
    end
endmodule
