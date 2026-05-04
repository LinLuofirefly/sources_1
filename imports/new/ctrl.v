module ctrl (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] jump_addr_i,
    input  wire        jump_en_i,
    (* max_fanout = 32 *)output wire        redirect_hold_o,
    (* max_fanout = 32 *)output wire        jump_en_o,
    (* max_fanout = 32 *)output wire [31:0] jump_addr_o,
    (* max_fanout = 32 *)output wire        kill_ex_o,
    (* max_fanout = 32 *) output wire flush_ifid_o,
    (* max_fanout = 32 *) output wire flush_idpipe_o,
    (* max_fanout = 32 *) output wire flush_idex_o,
    (* max_fanout = 32 *) output wire flush_flag_o
);
    
    // Two-phase redirect with split squashing:
    //   d0: detect redirect, hold fetch front-end for one cycle
    //   d1: commit redirect to PC and squash the held wrong-path decode/EX input
    //   d2: flush the synchronous-IROM ghost after the committed redirect
    (* extract_enable = "no" *) reg        jump_en_d1;
    (* extract_enable = "no" *) reg        jump_en_d2;
    (* extract_enable = "no" *) reg [31:0] jump_addr_d1;
    reg        jump_en_d1_n;
    reg        jump_en_d2_n;
    reg [31:0]jump_addr_d1_n; ;
    always @(*) begin
        jump_en_d1_n   = jump_en_d1;
        jump_en_d2_n   = jump_en_d2;
        jump_addr_d1_n = jump_addr_d1;

        if (!rst) begin
            jump_en_d1_n   = 1'b0;
            jump_en_d2_n   = 1'b0;
            jump_addr_d1_n = 32'b0;
        end else begin
            jump_en_d1_n = jump_en_i;
            jump_en_d2_n = jump_en_d1;
            if(jump_en_i)begin
                jump_addr_d1_n = jump_addr_i; // Assuming jump_addr_i is available
            end
        end
    end

    always @(posedge clk) begin
        jump_en_d1   <= jump_en_d1_n;
        jump_en_d2   <= jump_en_d2_n;
        jump_addr_d1 <= jump_addr_d1_n;
    end

    assign redirect_hold_o = jump_en_i;
    assign jump_en_o       = jump_en_d1;
    assign kill_ex_o       = jump_en_d1;
    assign jump_addr_o     = jump_addr_d1;
    assign flush_ifid_o   = jump_en_d2;
    assign flush_idpipe_o = jump_en_d1;
    assign flush_idex_o   = jump_en_d1;

    assign flush_flag_o   = flush_ifid_o;

endmodule
