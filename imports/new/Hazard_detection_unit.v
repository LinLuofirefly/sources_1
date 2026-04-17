`include "defines.v"

module Hazard_detection_unit (
    input  wire [31:0] id_inst_i,          // ID 级指令
    input  wire [31:0] ex_inst_i,          // EX 级指令
    input  wire [31:0] mem1_inst_i,        // 【新增】MEM1 级指令 (来自 EX/MEM1 寄存器)
    input  wire [31:0] mem2a_inst_i,       // MEM2 对齐级指令 (新增)
    output reg         hold_flag_o,        // 冻结信号 → PC 和 IF/ID
    (* max_fanout = 32 *) output reg flush_flag_o // 冲刷信号 → ID/EX
);

    // --- 提取指令关键字段 ---
    wire [6:0] id_opcode   = id_inst_i[6:0];
    wire [4:0] id_rs1      = id_inst_i[19:15];
    wire [4:0] id_rs2      = id_inst_i[24:20];
    
    wire [6:0] ex_opcode   = ex_inst_i[6:0];
    wire [4:0] ex_rd       = ex_inst_i[11:7];
    
    wire [6:0] mem1_opcode = mem1_inst_i[6:0];    // 【新增】
    wire [4:0] mem1_rd     = mem1_inst_i[11:7];   // 【新增】

    wire [6:0] mem2a_opcode = mem2a_inst_i[6:0];
    wire [4:0] mem2a_rd     = mem2a_inst_i[11:7];

    // --- 判断 ID 级指令是否真正使用 rs1/rs2 (保持你的原逻辑) ---
    wire id_use_rs1 = (id_opcode == `INST_TYPE_R_M) || 
                      (id_opcode == `INST_TYPE_I)   || 
                      (id_opcode == `INST_TYPE_S)   || 
                      (id_opcode == `INST_TYPE_B)   || 
                      (id_opcode == `INST_TYPE_L)   || 
                      (id_opcode == `INST_JALR);

    wire id_use_rs2 = (id_opcode == `INST_TYPE_R_M) || 
                      (id_opcode == `INST_TYPE_S)   || 
                      (id_opcode == `INST_TYPE_B);

    // =================================================================
    // 冒险检测逻辑
    // =================================================================
    always @(*) begin
        // 默认: 无冒险
        hold_flag_o  = 1'b0;
        flush_flag_o = 1'b0;

        // 1. 检测 EX 级 Load 冒险 (产生第 1 个气泡)
        if (ex_opcode == `INST_TYPE_L && ex_rd != 5'b0) begin
            if ((id_use_rs1 && ex_rd == id_rs1) || (id_use_rs2 && ex_rd == id_rs2)) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end
        // 2. 检测 MEM1 级 Load 冒险 (产生第 2 个气泡)
        // 注意这里用 else if 即可，如果 EX 级已经触发 Stall，不需要重复触发
        else if (mem1_opcode == `INST_TYPE_L && mem1_rd != 5'b0) begin
            if ((id_use_rs1 && mem1_rd == id_rs1) || (id_use_rs2 && mem1_rd == id_rs2)) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end
        // 3. 检测 MEM2 对齐级 Load 冒险 (产生第 3 个气泡)
        else if (mem2a_opcode == `INST_TYPE_L && mem2a_rd != 5'b0) begin
            if ((id_use_rs1 && mem2a_rd == id_rs1) || (id_use_rs2 && mem2a_rd == id_rs2)) begin
                hold_flag_o  = 1'b1;
                flush_flag_o = 1'b1;
            end
        end
    end

endmodule