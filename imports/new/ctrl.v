module ctrl (
    input  wire        clk,
    input  wire        rst,
    input  wire [31:0] jump_addr_i,
    input  wire        jump_en_i,

    output wire        jump_en_o,
    output wire [31:0] jump_addr_o,
    output wire        kill_ex_o,
    (* max_fanout = 32 *) output wire flush_ifid_o,
    (* max_fanout = 32 *) output wire flush_idex_o,
    (* max_fanout = 32 *) output wire flush_exmem1_o,
    (* max_fanout = 32 *) output wire flush_flag_o
);

    // Delay one cycle to clear the ghost instruction from synchronous IROM.
    reg jump_en_d1;

    always @(posedge clk) begin
        if (!rst) begin
            jump_en_d1 <= 1'b0;
        end else begin
            jump_en_d1 <= jump_en_i;
        end
    end

    assign jump_en_o      = jump_en_i;
    assign jump_addr_o    = jump_addr_i;
    assign kill_ex_o      = jump_en_d1;

    assign flush_ifid_o   = jump_en_d1;
    assign flush_idex_o   = jump_en_d1;

    assign flush_flag_o   = flush_ifid_o;

endmodule
