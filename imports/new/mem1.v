// =============================================================================
// 文件名: mem1.v
// 功  能: 第一访存级 (MEM1 - Memory Access Stage 1)
// 说  明: 在 6 级流水线中，MEM 被拆分为 MEM1 和 MEM2 两级:
//         - MEM1: 发起内存读/写请求 (地址和数据送往外部 RAM)
//         - MEM2: 接收 RAM 返回的读数据，完成 Load 数据对齐
//
//         MEM1 本身是纯组合逻辑透传:
//         - Store 指令的写掩码/地址/数据直接输出到外部 RAM
//         - Load 指令的读地址通过顶层连接送往外部 RAM
//         - ALU 结果和控制信号直接透传给 MEM1/MEM2 流水线寄存器
//
//         拆分原因: 同步 BRAM 的读操作需要 1 个时钟周期延迟，
//                  MEM1 发起读请求，MEM2 接收读数据。
// =============================================================================

`include "defines.v"

module mem1 (
    // --- 从 EX/MEM1 流水线寄存器接收的输入 ---
    input  wire [31:0] inst_i,             // 指令机器码
    input  wire [4:0]  rd_addr_i,          // 写回目标寄存器地址
    input  wire [31:0] rd_data_i,          // ALU 计算结果
    input  wire        rd_wen_i,           // 寄存器写使能
    input  wire [31:0] mem_rd_addr_i,      // 内存读地址 (Load)
    input  wire [3:0]  mem_wd_reg_i,       // 内存写掩码 (Store)
    input  wire [31:0] mem_wd_addr_i,      // 内存写地址 (Store)
    input  wire [31:0] mem_wd_data_i,      // 内存写数据 (Store)
    input  wire        is_load_i,          // Load 标记

    // --- 输出 ---
    output wire [4:0]  rd_addr_o,          // 透传: 写回目标寄存器地址
    output wire [31:0] rd_data_o,          // 透传: ALU 计算结果
    output wire        rd_wen_o,           // 透传: 寄存器写使能
    output wire [31:0] mem_rd_addr_o,      // 透传: 内存读地址 → MEM1/MEM2
    output wire [3:0]  mem_wd_reg_o,       // 透传: 内存写掩码 → 外部 RAM
    output wire [31:0] mem_wd_addr_o,      // 透传: 内存写地址 → 外部 RAM
    output wire [31:0] mem_wd_data_o,      // 透传: 内存写数据 → 外部 RAM
    output wire [31:0] inst_o,             // 透传: 指令机器码
    output wire        is_load_o           // 透传: Load 标记
);

    // 所有信号纯透传 (组合逻辑)
    assign rd_addr_o     = rd_addr_i;      // 写回地址透传
    assign rd_data_o     = rd_data_i;      // ALU 结果透传 (非 Load 指令的写回数据)
    assign rd_wen_o      = rd_wen_i;       // 写使能透传
    assign mem_rd_addr_o = mem_rd_addr_i;  // Load 读地址透传
    assign mem_wd_reg_o  = mem_wd_reg_i;   // Store 写掩码透传 → 外部 RAM
    assign mem_wd_addr_o = mem_wd_addr_i;  // Store 写地址透传 → 外部 RAM
    assign mem_wd_data_o = mem_wd_data_i;  // Store 写数据透传 → 外部 RAM
    assign inst_o        = inst_i;         // 指令码透传
    assign is_load_o     = is_load_i;      // Load 标记透传

endmodule