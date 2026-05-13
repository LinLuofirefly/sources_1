`include "defines.v"

module rv32m_iter (
    input  wire        clk,
    input  wire        rst,
    input  wire        start_i,
    input  wire [2:0]  func3_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    output wire        busy_o,
    output wire        done_o,
    output reg  [31:0] result_o
);

    // A tiny 3-state FSM is enough here:
    // IDLE waits for a new M instruction, MUL iterates shift-add,
    // DIV iterates an aligned long-division loop.
    localparam [1:0] RV32M_IDLE = 2'b00;
    localparam [1:0] RV32M_MUL  = 2'b01;
    localparam [1:0] RV32M_DIV  = 2'b10;

    reg [1:0]  state_r;
    reg        done_r;
    reg [2:0]  func3_r;
    reg [5:0]  iter_count_r;

    reg [63:0] mul_accum_r;
    reg [63:0] mul_multiplicand_r;
    reg [31:0] mul_multiplier_r;
    reg        mul_negate_r;

    reg [63:0] div_remainder_r;
    reg [63:0] div_divisor_shift_r;
    reg [31:0] div_quotient_accum_r;
    reg [31:0] div_quotient_bit_r;
    reg        div_quotient_negate_r;
    reg        div_remainder_negate_r;
    reg        div_return_remainder_r;

    wire is_mul_op = (func3_i == `INST_MUL)    ||
                     (func3_i == `INST_MULH)   ||
                     (func3_i == `INST_MULHSU) ||
                     (func3_i == `INST_MULHU);

    wire is_signed_mul_a = (func3_i == `INST_MUL) ||
                           (func3_i == `INST_MULH) ||
                           (func3_i == `INST_MULHSU);
    wire is_signed_mul_b = (func3_i == `INST_MUL) ||
                           (func3_i == `INST_MULH);

    // Multiply is performed on magnitudes, then the final 64-bit product is
    // negated when the signedness combination requires it.
    wire [31:0] mul_op1_abs = (is_signed_mul_a && op1_i[31]) ? (~op1_i + 32'd1) : op1_i;
    wire [31:0] mul_op2_abs = (is_signed_mul_b && op2_i[31]) ? (~op2_i + 32'd1) : op2_i;
    wire        mul_negate  = (is_signed_mul_a && op1_i[31]) ^ (is_signed_mul_b && op2_i[31]);

    wire is_signed_div = (func3_i == `INST_DIV) || (func3_i == `INST_REM);
    wire is_rem_op     = (func3_i == `INST_REM) || (func3_i == `INST_REMU);

    // Divide/rem also run on magnitudes first. Quotient and remainder signs are
    // fixed only after the final unsigned iteration completes.
    wire [31:0] div_op1_abs = (is_signed_div && op1_i[31]) ? (~op1_i + 32'd1) : op1_i;
    wire [31:0] div_op2_abs = (is_signed_div && op2_i[31]) ? (~op2_i + 32'd1) : op2_i;
    wire        div_overflow = is_signed_div && (op1_i == 32'h8000_0000) && (op2_i == 32'hffff_ffff);
    wire        div_dividend_zero = (div_op1_abs == 32'b0);
    wire        div_dividend_less = (div_op1_abs < div_op2_abs);
    wire        div_divisor_one = (div_op2_abs == 32'd1);

    // One shift-add step per cycle.
    wire [63:0] mul_accum_next = mul_accum_r + (mul_multiplier_r[0] ? mul_multiplicand_r : 64'b0);
    wire [63:0] mul_product_final = mul_negate_r ? (~mul_accum_next + 64'd1) : mul_accum_next;
    wire [31:0] mul_result_final = (func3_r == `INST_MUL) ? mul_product_final[31:0] : mul_product_final[63:32];
    wire        mul_last_cycle = (mul_multiplier_r[31:1] == 31'b0);

    function [5:0] msb_index32;
        input [31:0] value;
        integer idx;
        begin : msb_search
            msb_index32 = 6'd0;
            for (idx = 31; idx >= 0; idx = idx - 1) begin
                if (value[idx] == 1'b1) begin
                    msb_index32 = idx[5:0];
                    disable msb_search;
                end
            end
        end
    endfunction

    wire [5:0] div_align_shift = msb_index32(div_op1_abs) - msb_index32(div_op2_abs);

    // Aligned long division:
    // start with divisor shifted under the dividend MSB, then walk the divisor
    // and quotient bit down together until the last useful quotient bit.
    wire        div_can_subtract = (div_remainder_r >= div_divisor_shift_r);
    wire [63:0] div_remainder_next = div_can_subtract ? (div_remainder_r - div_divisor_shift_r) : div_remainder_r;
    wire [31:0] div_quotient_accum_next = div_can_subtract ? (div_quotient_accum_r | div_quotient_bit_r) : div_quotient_accum_r;
    wire [31:0] div_quotient_final = div_quotient_negate_r ? (~div_quotient_accum_next + 32'd1) : div_quotient_accum_next;
    wire [31:0] div_remainder_final = div_remainder_negate_r ? (~div_remainder_next[31:0] + 32'd1) : div_remainder_next[31:0];

    assign busy_o = (state_r != RV32M_IDLE);
    assign done_o = done_r;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            state_r                 <= RV32M_IDLE;
            done_r                  <= 1'b0;
            func3_r                 <= 3'b0;
            iter_count_r            <= 6'b0;
            mul_accum_r             <= 64'b0;
            mul_multiplicand_r      <= 64'b0;
            mul_multiplier_r        <= 32'b0;
            mul_negate_r            <= 1'b0;
            div_remainder_r         <= 64'b0;
            div_divisor_shift_r     <= 64'b0;
            div_quotient_accum_r    <= 32'b0;
            div_quotient_bit_r      <= 32'b0;
            div_quotient_negate_r   <= 1'b0;
            div_remainder_negate_r  <= 1'b0;
            div_return_remainder_r  <= 1'b0;
            result_o                <= 32'b0;
        end else begin
            if (done_r == 1'b1) begin
                done_r <= 1'b0;
            end

            case (state_r)
                RV32M_IDLE: begin
                    if (start_i == 1'b1) begin
                        func3_r      <= func3_i;
                        iter_count_r <= 6'd0;

                        if (is_mul_op == 1'b1) begin
                            if ((mul_op1_abs == 32'b0) || (mul_op2_abs == 32'b0)) begin
                                result_o <= 32'b0;
                                done_r   <= 1'b1;
                            end else begin
                                state_r            <= RV32M_MUL;
                                mul_accum_r        <= 64'b0;
                                mul_multiplicand_r <= {32'b0, mul_op1_abs};
                                mul_multiplier_r   <= mul_op2_abs;
                                mul_negate_r       <= mul_negate;
                            end
                        end else if (op2_i == 32'b0) begin
                            // RISC-V mandates all-ones quotient and dividend remainder on divide-by-zero.
                            result_o <= is_rem_op ? op1_i : 32'hffff_ffff;
                            done_r   <= 1'b1;
                        end else if (div_overflow == 1'b1) begin
                            // Signed overflow only happens on INT_MIN / -1.
                            result_o <= is_rem_op ? 32'b0 : 32'h8000_0000;
                            done_r   <= 1'b1;
                        end else if (div_dividend_zero == 1'b1) begin
                            result_o <= 32'b0;
                            done_r   <= 1'b1;
                        end else if (div_dividend_less == 1'b1) begin
                            result_o <= is_rem_op ? op1_i : 32'b0;
                            done_r   <= 1'b1;
                        end else if (div_divisor_one == 1'b1) begin
                            result_o <= is_rem_op ? 32'b0 :
                                        ((is_signed_div && (op1_i[31] ^ op2_i[31])) ? (~div_op1_abs + 32'd1) : div_op1_abs);
                            done_r   <= 1'b1;
                        end else begin
                            state_r                <= RV32M_DIV;
                            iter_count_r           <= div_align_shift;
                            div_remainder_r        <= {32'b0, div_op1_abs};
                            div_divisor_shift_r    <= ({32'b0, div_op2_abs} << div_align_shift);
                            div_quotient_accum_r   <= 32'b0;
                            div_quotient_bit_r     <= (32'b1 << div_align_shift);
                            div_quotient_negate_r  <= is_signed_div && (op1_i[31] ^ op2_i[31]);
                            div_remainder_negate_r <= is_signed_div && op1_i[31];
                            div_return_remainder_r <= is_rem_op;
                        end
                    end
                end

                RV32M_MUL: begin
                    mul_accum_r        <= mul_accum_next;
                    mul_multiplicand_r <= mul_multiplicand_r << 1;
                    mul_multiplier_r   <= mul_multiplier_r >> 1;

                    // Stop once the current highest live multiplier bit has
                    // been consumed instead of always burning a full 32 steps.
                    if ((iter_count_r == 6'd31) || (mul_last_cycle == 1'b1)) begin
                        state_r  <= RV32M_IDLE;
                        done_r   <= 1'b1;
                        result_o <= mul_result_final;
                    end

                    iter_count_r <= iter_count_r + 1'b1;
                end

                RV32M_DIV: begin
                    div_remainder_r <= div_remainder_next;
                    div_divisor_shift_r <= div_divisor_shift_r >> 1;
                    div_quotient_accum_r <= div_quotient_accum_next;
                    div_quotient_bit_r <= div_quotient_bit_r >> 1;

                    // Only iterate across quotient bits that can actually be non-zero.
                    if (iter_count_r == 6'd0) begin
                        state_r  <= RV32M_IDLE;
                        done_r   <= 1'b1;
                        result_o <= div_return_remainder_r ? div_remainder_final : div_quotient_final;
                    end else begin
                        iter_count_r <= iter_count_r - 1'b1;
                    end
                end

                default: begin
                    state_r <= RV32M_IDLE;
                end
            endcase
        end
    end

endmodule
