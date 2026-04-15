// =============================================================================
// 文件名: reg.v
// 功  能: 通用寄存器堆 (Register File)
// 说  明: 实现 RISC-V 的 32 个 32 位通用寄存器 (x0 ~ x31)。
//         - x0 硬连线为 0，任何写入操作都会被忽略
//         - 支持 2 个异步读端口 (组合逻辑，0 延迟)
//         - 支持 1 个同步写端口 (时钟上升沿写入)
//         - 内建写后读前递: 当读地址与写地址相同时，直接输出写入数据
// =============================================================================

module regs (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)

    // --- 读端口 1 ---
    input  wire [4:0]  reg1_raddr_i,       // 源寄存器 1 读地址 (rs1)
    output reg  [31:0] reg1_rdata_o,       // 源寄存器 1 读数据

    // --- 读端口 2 ---
    input  wire [4:0]  reg2_raddr_i,       // 源寄存器 2 读地址 (rs2)
    output reg  [31:0] reg2_rdata_o,       // 源寄存器 2 读数据

    // --- 写端口 (来自 WB 写回级) ---
    input  wire [4:0]  reg_waddr_i,        // 写目标寄存器地址
    input  wire [31:0] reg_wdata_i,        // 写入数据
    input  wire        reg_wen             // 写使能 (1: 允许写入)
);

    // 32 个 32 位通用寄存器
    reg [31:0] regs [0:31];

    // =================================================================
    // 读端口 1 (组合逻辑，异步读取)
    // 优先级: 复位 > x0 恒零 > 写后读前递 > 正常读取
    // =================================================================
    always @(*) begin
        if (rst == 1'b0) begin
            reg1_rdata_o = 32'b0;                              // 复位: 输出 0
        end
        else if (reg1_raddr_i == 5'b0) begin
            reg1_rdata_o = 32'b0;                              // x0 硬连线为 0
        end
        else if (reg_wen == 1'b1 && reg1_raddr_i == reg_waddr_i) begin
            reg1_rdata_o = reg_wdata_i;                        // 写后读前递: 输出正在写入的新值
        end
        else begin
            reg1_rdata_o = regs[reg1_raddr_i];                 // 正常读取寄存器值
        end
    end

    // =================================================================
    // 读端口 2 (组合逻辑，异步读取)
    // 优先级: 复位 > x0 恒零 > 写后读前递 > 正常读取
    // =================================================================
    always @(*) begin
        if (rst == 1'b0) begin
            reg2_rdata_o = 32'b0;                              // 复位: 输出 0
        end
        else if (reg2_raddr_i == 5'b0) begin
            reg2_rdata_o = 32'b0;                              // x0 硬连线为 0
        end
        else if (reg_wen == 1'b1 && reg2_raddr_i == reg_waddr_i) begin
            reg2_rdata_o = reg_wdata_i;                        // 写后读前递: 输出正在写入的新值
        end
        else begin
            reg2_rdata_o = regs[reg2_raddr_i];                 // 正常读取寄存器值
        end
    end

    // =================================================================
    // 写端口 (时序逻辑，时钟上升沿写入)
    // =================================================================
    integer i;
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            // 复位: 将所有寄存器清零
            for (i = 0; i <= 31; i = i + 1) begin
                regs[i] <= 32'b0;
            end
        end
        else if (reg_wen == 1'b1 && reg_waddr_i != 5'b0) begin
            // 写入: 使能有效且地址非 x0 时，写入新值
            // x0 不可写入，因为 RISC-V 规定 x0 恒为 0
            regs[reg_waddr_i] <= reg_wdata_i;
        end
    end

endmodule