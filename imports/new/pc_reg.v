module pc_reg (
    input  wire        clk,                
    input  wire        rst,                
    input  wire        hold_flag_i,        
    input  wire [31:0] jump_addr_i,        
    input  wire        jump_en,            
    
    // 魔法原语依然保留：严禁 Vivado 动用 CE 引脚
    (* extract_enable = "no" *) output reg  [31:0] pc_o               
);

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            pc_o <= 32'h8000_0000;         
        end else if (jump_en == 1'b1) begin
            pc_o <= jump_addr_i;
        end else if (hold_flag_i != 1'b1) begin
            pc_o <= pc_o + 32'd4;
        end else begin
            pc_o <= pc_o;
        end
    end

endmodule
