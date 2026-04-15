// =============================================================================
// 文件名: pc_reg.v
// 功  能: 程序计数器寄存器 (Program Counter Register)
// 说  明: 维护当前取指地址 (PC)，支持三种行为:
//         1. 复位:   PC 初始化为 0x0000_3000 (程序入口地址)
//         2. 跳转:   当跳转使能有效时，PC 加载跳转目标地址
//         3. 顺序:   正常情况下 PC 每拍 +4 (指向下一条 32 位指令)
//         4. 冻结:   Load-Use 冒险时，PC 保持不变 (流水线暂停)
//         优先级: 复位 > 跳转 > 冻结 > 顺序递增
// =============================================================================

module pc_reg (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire        hold_flag_i,        // 冻结信号: 为 1 时 PC 保持不变 (Load-Use 暂停)
    input  wire [31:0] jump_addr_i,        // 跳转目标地址
    input  wire        jump_en,            // 跳转使能: 为 1 时 PC 加载跳转地址
    output reg  [31:0] pc_o               // 当前 PC 值输出 (送往 ROM 取指)
);

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            pc_o <= 32'h8000_0000;         // 复位: PC 初始化为程序入口地址
        end else begin
            if (jump_en) begin
                pc_o <= jump_addr_i;       // 跳转: PC 加载目标地址 (优先级最高)
            end else if (!hold_flag_i) begin
                pc_o <= pc_o + 4;          // 顺序递增: PC += 4 (每条指令 4 字节)
            end
            // hold_flag_i == 1 时: PC 保持不变，隐式由 reg 特性实现
        end
    end

endmodule
