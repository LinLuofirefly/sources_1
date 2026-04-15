// =============================================================================
// 文件名: dff_set.v
// 功  能: 通用流水线寄存器 (带 Stall 和 Flush 控制)
// 说  明: 本模块是一个参数化的 D 触发器，支持三种工作模式:
//         1. 复位/冲刷 (rst=0 或 flush=1): 输出预设的默认值 (如 NOP)
//         2. 冻结 (hold=1):                保持当前输出不变
//         3. 正常流通:                      将输入数据锁存并输出
//         优先级: 复位/冲刷 > 冻结 > 正常流通
// 参  数: DW - 数据位宽 (默认 32 位)
// =============================================================================
(* keep_hierarchy = "yes" *)
module dff_set
    #(parameter DW = 32)                   // 参数: 数据位宽，可在例化时指定
    (
    input  wire           clk,             // 时钟信号
    input  wire           rst,             // 复位信号 (低电平有效)
    input  wire           hold_flag_i,     // Stall 冻结信号: 为 1 时保持输出不变
    input  wire           flush_flag_i,    // Flush 冲刷信号: 为 1 时输出默认值
    input  wire [DW-1:0]  set_data,        // 冲刷/复位时的默认值 (如 NOP 指令码)
    input  wire [DW-1:0]  data_i,          // 正常流通时的数据输入
    output reg  [DW-1:0]  data_o           // 数据输出
    );
    (* max_fanout = 32 *) wire internal_flush;
    (* max_fanout = 32 *) wire internal_hold;

    // 将复杂的 || 逻辑提前算出，并死死钉在内部线网上
    assign internal_flush = (rst == 1'b0) || (flush_flag_i == 1'b1);
    assign internal_hold  = (hold_flag_i == 1'b1);

    always @(posedge clk) begin
        if (internal_flush) begin
            data_o <= set_data;            // 复位或冲刷: 输出预设默认值 (插入气泡)
        end else if (internal_hold) begin
            data_o <= data_o;              // 冻结: 保持输出不变 (流水线暂停)
        end else begin
            data_o <= data_i;              // 正常: 锁存输入数据并输出
        end
    end

endmodule