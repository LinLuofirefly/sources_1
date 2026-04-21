`include "defines.v"

module branch_predictor(
    input  wire        clk,
    input  wire        rst,
    
    // IF级预测接口 (组合逻辑)
    input  wire [31:0] if_inst_i,      // 从ROM预取到的当前指令
    input  wire [31:0] if_pc_i,        // 当前正准备取指令的PC地址
    input  wire        hold_flag_i,    // 冻结信号
    input  wire        flush_flag_i,   // 冲刷信号
    
    output reg         pred_taken_o,   // 当前指令是否预测跳转
    output reg  [31:0] pred_target_o,  // 预测的跳转目标地址
    output reg         pred_flush_o,   // 给IF/ID使用的延迟1拍冲刷信号
    
    // EX级更新接口 (时序逻辑)
    input  wire        update_en_i,    // 更新使能 (仅在执行分支指令时为 1)
    input  wire [31:0] update_pc_i,    // 导致此更新的分支指令的 PC
    input  wire        actual_taken_i  // 分支指令实际是否发生了跳转
);

    // =================================================================
    // 内部状态定义 BHT
    // =================================================================
    parameter BHT_ADDR_WIDTH = 7;
    parameter BHT_SIZE = 128;
    
    // 2-bit状态定义
    localparam STRONGLY_NOT_TAKEN = 2'b00;
    localparam WEAKLY_NOT_TAKEN   = 2'b01;
    localparam WEAKLY_TAKEN       = 2'b10;
    localparam STRONGLY_TAKEN     = 2'b11;

    // 分支历史表BHT: 128 x 2 bits
    reg [1:0] bht [BHT_SIZE-1:0];

    // =================================================================
    // 复位 / 更新逻辑 (时序逻辑)
    // =================================================================
    integer i;
    wire [BHT_ADDR_WIDTH-1:0] update_idx = update_pc_i[8:2];

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            for (i = 0; i < BHT_SIZE; i = i + 1) begin
                bht[i] <= WEAKLY_NOT_TAKEN; // 默认状态
            end
            pred_flush_o <= 1'b0;
        end else begin
            // BHT 2-bit饱和计数器状态机更新
            if (update_en_i) begin
                case (bht[update_idx])
                    STRONGLY_NOT_TAKEN: bht[update_idx] <= actual_taken_i ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                    WEAKLY_NOT_TAKEN:   bht[update_idx] <= actual_taken_i ? WEAKLY_TAKEN       : STRONGLY_NOT_TAKEN;
                    WEAKLY_TAKEN:       bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN     : WEAKLY_NOT_TAKEN;
                    STRONGLY_TAKEN:     bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN     : WEAKLY_TAKEN;
                endcase
            end
            
           if (flush_flag_i) begin
            // 优先级最高：如果控制单元发出了真实冲刷，清零预测冲刷
            pred_flush_o <= 1'b0;
        end else begin
            // 只有在流水线正常流动 (!hold_flag_i) 时，才允许产生 1 拍的幽灵冲刷
            pred_flush_o <= pred_taken_o & ~hold_flag_i;
        end
        end
    end

    // =================================================================
    // 预测逻辑 (纯组合逻辑)
    // =================================================================
    wire [6:0] opcode = if_inst_i[6:0];
    wire [BHT_ADDR_WIDTH-1:0] pred_idx = if_pc_i[8:2];

    always @(*) begin
        pred_taken_o = 1'b0;
        pred_target_o = 32'b0;
        
        // 遇到分支指令 `INST_TYPE_B` (7'b1100011) 根据BHT进行预测
        if (opcode == 7'b1100011) begin
            if (bht[pred_idx] == WEAKLY_TAKEN || bht[pred_idx] == STRONGLY_TAKEN) begin
                pred_taken_o = 1'b1;
                // 计算B型指令的预测目标地址
                pred_target_o = if_pc_i + {{20{if_inst_i[31]}}, if_inst_i[7], if_inst_i[30:25], if_inst_i[11:8], 1'b0};
            end
        end
        // 遇到 `INST_JAL` (7'b1101111) 时，无条件直接预测Taken以消除1个气泡
        else if (opcode == 7'b1101111) begin
            pred_taken_o = 1'b1;
            // 计算J型指令的预测目标地址
            pred_target_o = if_pc_i + {{12{if_inst_i[31]}}, if_inst_i[19:12], if_inst_i[20], if_inst_i[30:21], 1'b0};
        end
        // JALR等依赖寄存器的跳转由于在IF无法拿到寄存器值，没法预测目标，故在此不强行预测跳转
    end

endmodule
