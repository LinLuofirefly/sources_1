module pc_reg (
    input  wire        clk,                
    input  wire        rst,                
    input  wire        hold_flag_i,        
    input  wire [31:0] jump_addr_i,        
    input  wire        jump_en,            
    input  wire        pred_en,            // 分支预测使能
    input  wire [31:0] pred_addr,          // 预测目标地址
    
    // 魔法原语依然保留：严禁 Vivado 动用 CE 引脚
    (* extract_enable = "no" *) output reg  [31:0] pc_o               
);

    reg [31:0] next_pc;

    // =================================================================
    // 组合逻辑部分：专门负责算数
    // 使用 if-else 结构，完美免疫 CPU 启动时的 X 态干扰
    // =================================================================
    always @(*) begin
        // 显式加上 == 1'b1，防止高阻态 Z 或 X 态误触发
        if (jump_en == 1'b1) begin
            next_pc = jump_addr_i;
        end else if (hold_flag_i == 1'b1) begin
            next_pc = pc_o;
        end else if (pred_en == 1'b1) begin
            next_pc = pred_addr;
        end else begin
            next_pc = pc_o + 32'd4;
        end
    end

    // =================================================================
    // 时序逻辑部分：纯粹的打拍机器
    // 没有任何 if-else 分支，彻底切断 CE 提取的可能
    // =================================================================
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            pc_o <= 32'h8000_0000;         
        end else begin
            pc_o <= next_pc;               
        end
    end

endmodule