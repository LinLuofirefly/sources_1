// =============================================================================
// 文件名: if_id.v
// 功  能: IF/ID 流水线寄存器 (取指级 → 译码级)
// 说  明: 本模块在取指级 (IF) 和译码级 (ID) 之间保存指令和 PC 地址。
//
//         ★ 核心设计: Skid Buffer (指令防滑缓冲器)
//         由于使用同步 ROM (BRAM)，ROM 的输出会在 Stall 期间继续变化，
//         导致被暂停的指令被新数据覆盖而丢失。Skid Buffer 在 Stall 开始时
//         将当前指令"抢救"到内部寄存器中，暂停结束后再恢复输出。
//
//         工作模式:
//         1. 复位/冲刷: 输出 NOP 气泡
//         2. 冻结 (Stall):
//            - 第一拍: 将 ROM 当前输出的指令保存到 hold_inst_reg
//            - 后续拍: 持续输出 hold_inst_reg 中保存的指令
//         3. 正常: 透传 ROM 最新输出的指令
// =============================================================================

`include "defines.v"

module if_id (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire [31:0] inst_i,             // 来自 ROM 实时输出的 32 位指令
    input  wire [31:0] inst_addr_i,        // 来自 PC 寄存器的指令地址
    input  wire        hold_flag_i,        // 冻结信号: Load-Use 冒险时为 1
    input  wire        flush_flag_i,       // 冲刷信号: 跳转时为 1
    output wire [31:0] inst_addr_o,        // 输出给 ID 级的指令地址
    output reg  [31:0] inst_o              // 输出给 ID 级的指令机器码
);

    // =================================================================
    //  Skid Buffer: 指令防滑缓冲器
    //  解决同步 ROM 在 Stall 期间覆盖当前指令的问题
    // =================================================================
    reg [31:0] hold_inst_reg;              // 缓冲寄存器: 保存被拦截的指令
    reg        is_holding_reg;             // 状态标记: 当前是否正在使用缓冲数据

    // --- 缓冲控制逻辑 (时序) ---
    always @(posedge clk) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            hold_inst_reg  <= 32'b0;       // 复位/冲刷: 清空缓冲
            is_holding_reg <= 1'b0;        // 清除状态标记
        end
        else if (hold_flag_i == 1'b1 && is_holding_reg == 1'b0) begin
            // Stall 第一拍: 将 ROM 当前输出的指令保存到缓冲寄存器
            hold_inst_reg  <= inst_i;      // 抢救指令到缓冲区
            is_holding_reg <= 1'b1;        // 标记已进入缓冲模式
        end
        else if (hold_flag_i == 1'b0) begin
            // Stall 结束: 恢复正常模式
            is_holding_reg <= 1'b0;        // 清除缓冲状态标记
        end
    end

    // --- 指令输出路由选择 (组合逻辑) ---
    always @(*) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            inst_o = `INST_NOP;            // 复位/冲刷: 输出 NOP 气泡
        end
        else if (is_holding_reg == 1'b1) begin
            inst_o = hold_inst_reg;        // 缓冲模式: 输出保存的指令
        end
        else begin
            inst_o = inst_i;              // 正常模式: 透传 ROM 最新数据
        end
    end

    // --- PC 地址: 使用 dff_set 打一拍传递 ---
    // PC 地址无需 Skid Buffer 处理，因为 Stall 时 PC 已被冻结
    dff_set #(32) dff_inst_addr (
        clk, rst,
        hold_flag_i,                       // Stall 时冻结地址
        1'b0,                              // 不冲刷地址 (地址在跳转时不应清零)
        32'b0,                             // 复位默认值
        inst_addr_i,                       // 输入地址
        inst_addr_o                        // 输出地址
    );

endmodule
//4月1日笔记：不能写inst_o=inst_o这种代码了，直接把课上学的都忘完了，还有一个lw mv冒险，为了解决冒险使得流水线暂停，
//lw指令在ex，mv指令在id，触发了暂停，然后因为inst_o=inst_o是组合逻辑非法，所以pc稳定+4送来的新指令覆盖了id里的MOV指令导致mv指令消失
//正确做法是将mv指令用时序逻辑打一拍存起来，然后用多路复用器判断究竟输出哪个指令，防止指令丢失
//解决问题的方法：首先查看各个寄存器的数值，对比dump文件，找出指令和pc地址，再通过波形图查看id的指令，ex的指令，冲刷信号，前馈的东西等等，综合判断是哪里出了问题
//PC地址在暂停时不能归零，跳转时的下一个指令如auipc需要这个pc地址，一旦清零就会进入错误的地方，指令冲刷了，但是地址不等你冲刷。