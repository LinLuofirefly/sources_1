// =============================================================================
// 文件名: wb.v
// 功  能: 写回模块 (Write Back)
// 说  明: 流水线最后一级，将最终结果写回寄存器堆。
//         本模块是纯组合逻辑透传，信号从 MEM2/WB 流水线寄存器
//         直接送往寄存器堆的写端口。
//
//         之所以独立为一个模块，是为了保持流水线结构的清晰性，
//         便于后续扩展 (如添加 CSR 写回路径)。
// =============================================================================

module wb (
    // --- 从 MEM2/WB 流水线寄存器接收的输入 ---
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // 写回数据 (ALU 结果或 Load 数据)
    input  wire        rd_wen_i,           // 寄存器写使能
    input  wire [31:0] inst_i,             // 指令机器码 (用于调试)

    // --- 输出给寄存器堆的写回信号 ---
    output wire [4:0]  rd_addr_o,          // 写回目标寄存器地址 → Regfile
    output wire [31:0] rd_data_o,          // 写回数据 → Regfile
    output wire        rd_wen_o,           // 写使能 → Regfile
    output wire [31:0] inst_o              // 指令机器码 (透传，通常悬空)
);

    // 所有信号纯透传
    assign rd_addr_o = rd_addr_i;          // 写回地址透传
    assign rd_data_o = rd_data_i;          // 写回数据透传
    assign rd_wen_o  = rd_wen_i;           // 写使能透传
    assign inst_o    = inst_i;             // 指令码透传

endmodule