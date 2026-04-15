// =============================================================================
// 文件名: Hazard_detection_unit.v
// 功  能: 冒险检测单元 (Hazard Detection Unit)
// 说  明: 检测 Load-Use 数据冒险，当检测到冒险时:
//         - hold_flag_o = 1: 冻结 PC 和 IF/ID (暂停取指和译码)
//         - flush_flag_o = 1: 清空 ID/EX (在执行级插入 NOP 气泡)
//
//         Load-Use 冒险场景:
//         当 EX 级正在执行一条 Load 指令，而 ID 级的下一条指令需要使用
//         Load 的目标寄存器 (rd) 作为源操作数时，由于 Load 数据尚未从
//         RAM 读出 (需等到 MEM2 级)，无法通过前递解决，必须暂停 1 拍。
// =============================================================================

`include "defines.v"

module Hazard_detection_unit (
    input  wire [31:0] id_inst_i,          // ID 级指令 (来自 IF/ID 寄存器输出)
    input  wire [31:0] ex_inst_i,          // EX 级指令 (来自 ID/EX 寄存器输出)
    output reg         hold_flag_o,        // 冻结信号 → PC 和 IF/ID (暂停取指)
    (* max_fanout = 32 *) output reg         flush_flag_o        // 冲刷信号 → ID/EX (插入 NOP 气泡)
);

    // --- 提取 ID 级和 EX 级指令的关键字段 ---
    wire [6:0] id_opcode = id_inst_i[6:0];    // ID 级指令操作码
    wire [6:0] ex_opcode = ex_inst_i[6:0];    // EX 级指令操作码
    wire [4:0] id_rs1    = id_inst_i[19:15];  // ID 级源寄存器 1
    wire [4:0] id_rs2    = id_inst_i[24:20];  // ID 级源寄存器 2
    wire [4:0] ex_rd     = ex_inst_i[11:7];   // EX 级目标寄存器

    // --- 判断 ID 级指令是否真正使用 rs1 ---
    wire id_use_rs1 = (id_opcode == `INST_TYPE_R_M) ||    // R 型
                      (id_opcode == `INST_TYPE_I)   ||    // I 型
                      (id_opcode == `INST_TYPE_S)   ||    // S 型
                      (id_opcode == `INST_TYPE_B)   ||    // B 型
                      (id_opcode == `INST_TYPE_L)   ||    // L 型
                      (id_opcode == `INST_JALR);          // JALR

    // --- 判断 ID 级指令是否真正使用 rs2 ---
    wire id_use_rs2 = (id_opcode == `INST_TYPE_R_M) ||    // R 型
                      (id_opcode == `INST_TYPE_S)   ||    // S 型
                      (id_opcode == `INST_TYPE_B);        // B 型

    // =================================================================
    // 冒险检测逻辑 (纯组合逻辑)
    // =================================================================
    always @(*) begin
        // 默认: 无冒险
        hold_flag_o  = 1'b0;
        flush_flag_o = 1'b0;

        // 检测 Load-Use 冒险:
        // 条件: EX 级是 Load 指令，且 rd != x0
        if (ex_opcode == `INST_TYPE_L && ex_rd != 5'b0) begin
            // 检查 rs1 相关: ID 级使用 rs1 且 rs1 == EX 级的 rd
            if (id_use_rs1 && ex_rd == id_rs1) begin
                hold_flag_o  = 1'b1;               // 冻结 PC 和 IF/ID
                flush_flag_o = 1'b1;               // 清空 ID/EX (插入气泡)
            end
            // 检查 rs2 相关: ID 级使用 rs2 且 rs2 == EX 级的 rd
            if (id_use_rs2 && ex_rd == id_rs2) begin
                hold_flag_o  = 1'b1;               // 冻结 PC 和 IF/ID
                flush_flag_o = 1'b1;               // 清空 ID/EX (插入气泡)
            end
        end
    end

endmodule