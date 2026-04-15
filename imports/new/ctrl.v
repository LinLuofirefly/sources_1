// =============================================================================
// 文件名: ctrl.v
// 功  能: 中央控制器 (流水线冲刷控制)
// 说  明: 检测跳转指令，生成冲刷信号 (flush_flag_o) 清除流水线中的错误指令。
//
//         由于使用同步 ROM (BRAM)，跳转时存在以下问题:
//         1. 跳转发起当拍: 已有一条错误地址的指令进入了 BRAM 读端口
//         2. 下一拍: 该错误指令从 BRAM 输出到 IF/ID，成为"幽灵指令"
//
//         解决方案: 连续冲刷 2 拍
//         - 第 1 拍: jump_en_i 为 1 时冲刷 (清除当前错误指令)
//         - 第 2 拍: jump_en_delay 为 1 时再次冲刷 (清除延迟 1 拍输出的幽灵指令)
//         flush_flag_o = jump_en_i | jump_en_delay
// =============================================================================

module ctrl (
    input  wire        clk,                // 时钟信号
    input  wire        rst,                // 复位信号 (低电平有效)
    input  wire [31:0] jump_addr_i,        // 来自 EX 级的跳转目标地址
    input  wire        jump_en_i,          // 来自 EX 级的跳转使能

    output wire        jump_en_o,          // 透传给 PC 寄存器的跳转使能
    output wire [31:0] jump_addr_o,        // 透传给 PC 寄存器的跳转地址
    (* max_fanout = 32 *) output wire        flush_flag_o        // 冲刷信号: 送往 IF/ID 和 ID/EX
);

    // 延迟寄存器: 记录上一拍是否发生过跳转
    reg jump_en_delay;

    always @(posedge clk) begin
        if (!rst) begin
            jump_en_delay <= 1'b0;         // 复位: 清零
        end else begin
            jump_en_delay <= jump_en_i;    // 打一拍: 保存上一拍的跳转使能
        end
    end

    // 跳转信号直接透传给 PC 寄存器
    assign jump_en_o   = jump_en_i;
    assign jump_addr_o = jump_addr_i;

    // 冲刷信号: 当前拍跳转 或 上一拍跳转，都需要冲刷
    // 这样可以消除同步 ROM 延迟 1 拍输出的"幽灵指令"
    assign flush_flag_o = jump_en_i | jump_en_delay;
//4月1日笔记：由于rom是同步的，所以当跳转发起冲刷的时候，有个指令的地址进入了bram，然后在第二个拍输出到id，这个也是废指令，所以需要二次flush
//当检测到要求跳转的时候，就再冲刷一遍，这样就能把那个废指令冲掉。
endmodule