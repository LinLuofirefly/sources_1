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

    // PREP latches raw operands first, so the heavy signedness/absolute-value
    // decode no longer fans out directly from ID/EX into the iterative state.
    localparam [2:0] RV32M_IDLE       = 3'b000;
    localparam [2:0] RV32M_PREP       = 3'b001;
    localparam [2:0] RV32M_MUL_ISSUE  = 3'b010;
    localparam [2:0] RV32M_MUL_WAIT   = 3'b011;
    localparam [2:0] RV32M_DIV        = 3'b100;
    localparam [2:0] RV32M_DIV_FINISH = 3'b101;

    reg [2:0]  state_r;
    reg        done_r;
    reg [2:0]  func3_r;
    reg [5:0]  iter_count_r;
    reg [31:0] op1_raw_r;
    reg [31:0] op2_raw_r;
    reg signed [32:0] mul_op1_ext_r;
    reg signed [32:0] mul_op2_ext_r;
    (* use_dsp = "yes" *) reg signed [65:0] mul_product_r;

    reg [32:0] div_remainder_r;
    reg [32:0] div_remainder_shift_r;
    reg [31:0] div_dividend_r;
    reg [31:0] div_divisor_r;
    reg [31:0] div_quotient_accum_r;
    reg        div_quotient_negate_r;
    reg        div_remainder_negate_r;
    reg        div_return_remainder_r;
    reg        div_phase_r;
    reg [31:0] div_result_r;

    wire is_mul_op = (func3_r == `INST_MUL)    ||
                     (func3_r == `INST_MULH)   ||
                     (func3_r == `INST_MULHSU) ||
                     (func3_r == `INST_MULHU);

    wire is_signed_mul_a = (func3_r == `INST_MUL) ||
                           (func3_r == `INST_MULH) ||
                           (func3_r == `INST_MULHSU);
    wire is_signed_mul_b = (func3_r == `INST_MUL) ||
                           (func3_r == `INST_MULH);

    // Drive multiply through signed 33x33 operands so synthesis can map the
    // operation into DSPs while still covering MUL/MULH/MULHSU/MULHU.
    wire signed [32:0] mul_op1_ext_w =
        is_signed_mul_a ? $signed({op1_raw_r[31], op1_raw_r}) : $signed({1'b0, op1_raw_r});
    wire signed [32:0] mul_op2_ext_w =
        is_signed_mul_b ? $signed({op2_raw_r[31], op2_raw_r}) : $signed({1'b0, op2_raw_r});
    wire [63:0] mul_product_final = mul_product_r[63:0];
    wire [31:0] mul_result_final =
        (func3_r == `INST_MUL) ? mul_product_final[31:0] : mul_product_final[63:32];

    wire is_signed_div = (func3_r == `INST_DIV) || (func3_r == `INST_REM);
    wire is_rem_op     = (func3_r == `INST_REM) || (func3_r == `INST_REMU);

    // Divide/rem also run on magnitudes first. Quotient and remainder signs are
    // fixed only after the final unsigned iteration completes.
    wire [31:0] div_op1_abs = (is_signed_div && op1_raw_r[31]) ? (~op1_raw_r + 32'd1) : op1_raw_r;
    wire [31:0] div_op2_abs = (is_signed_div && op2_raw_r[31]) ? (~op2_raw_r + 32'd1) : op2_raw_r;
    wire        div_overflow = is_signed_div && (op1_raw_r == 32'h8000_0000) && (op2_raw_r == 32'hffff_ffff);
    wire        div_dividend_zero = (div_op1_abs == 32'b0);
    wire        div_dividend_less = (div_op1_abs < div_op2_abs);
    wire        div_divisor_one = (div_op2_abs == 32'd1);

    // Two-phase restoring divider:
    // phase 0 shifts the next dividend bit into a 33-bit remainder register,
    // phase 1 performs the compare/subtract and appends one quotient bit.
    wire [32:0] div_trial_remainder = {div_remainder_r[31:0], div_dividend_r[31]};
    wire        div_can_subtract = (div_remainder_shift_r >= {1'b0, div_divisor_r});
    wire [32:0] div_remainder_next =
        div_can_subtract ? (div_remainder_shift_r - {1'b0, div_divisor_r}) : div_remainder_shift_r;
    wire [31:0] div_quotient_accum_next = {div_quotient_accum_r[30:0], div_can_subtract};
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
            op1_raw_r               <= 32'b0;
            op2_raw_r               <= 32'b0;
            mul_op1_ext_r           <= 33'sd0;
            mul_op2_ext_r           <= 33'sd0;
            mul_product_r           <= 66'sd0;
            div_remainder_r         <= 33'b0;
            div_remainder_shift_r   <= 33'b0;
            div_dividend_r          <= 32'b0;
            div_divisor_r           <= 32'b0;
            div_quotient_accum_r    <= 32'b0;
            div_quotient_negate_r   <= 1'b0;
            div_remainder_negate_r  <= 1'b0;
            div_return_remainder_r  <= 1'b0;
            div_phase_r             <= 1'b0;
            div_result_r            <= 32'b0;
            result_o                <= 32'b0;
        end else begin
            if (done_r == 1'b1) begin
                done_r <= 1'b0;
            end

            case (state_r)
                RV32M_IDLE: begin
                    if (start_i == 1'b1) begin
                        state_r      <= RV32M_PREP;
                        func3_r      <= func3_i;
                        op1_raw_r    <= op1_i;
                        op2_raw_r    <= op2_i;
                        iter_count_r <= 6'd0;
                    end
                end

                RV32M_PREP: begin
                    if (is_mul_op == 1'b1) begin
                            if ((op1_raw_r == 32'b0) || (op2_raw_r == 32'b0)) begin
                                state_r  <= RV32M_IDLE;
                                result_o <= 32'b0;
                                done_r   <= 1'b1;
                            end else begin
                                state_r      <= RV32M_MUL_ISSUE;
                                mul_op1_ext_r <= mul_op1_ext_w;
                                mul_op2_ext_r <= mul_op2_ext_w;
                            end
                    end else if (op2_raw_r == 32'b0) begin
                            // RISC-V mandates all-ones quotient and dividend remainder on divide-by-zero.
                            state_r  <= RV32M_IDLE;
                            result_o <= is_rem_op ? op1_raw_r : 32'hffff_ffff;
                            done_r   <= 1'b1;
                    end else if (div_overflow == 1'b1) begin
                            // Signed overflow only happens on INT_MIN / -1.
                            state_r  <= RV32M_IDLE;
                            result_o <= is_rem_op ? 32'b0 : 32'h8000_0000;
                            done_r   <= 1'b1;
                    end else if (div_dividend_zero == 1'b1) begin
                            state_r  <= RV32M_IDLE;
                            result_o <= 32'b0;
                            done_r   <= 1'b1;
                    end else if (div_dividend_less == 1'b1) begin
                            state_r  <= RV32M_IDLE;
                            result_o <= is_rem_op ? op1_raw_r : 32'b0;
                            done_r   <= 1'b1;
                    end else if (div_divisor_one == 1'b1) begin
                            state_r  <= RV32M_IDLE;
                            result_o <= is_rem_op ? 32'b0 :
                                        ((is_signed_div && (op1_raw_r[31] ^ op2_raw_r[31])) ? (~div_op1_abs + 32'd1) : div_op1_abs);
                            done_r   <= 1'b1;
                    end else begin
                            state_r                <= RV32M_DIV;
                            iter_count_r           <= 6'd32;
                            div_remainder_r        <= 33'b0;
                            div_remainder_shift_r  <= 33'b0;
                            div_dividend_r         <= div_op1_abs;
                            div_divisor_r          <= div_op2_abs;
                            div_quotient_accum_r   <= 32'b0;
                            div_quotient_negate_r  <= is_signed_div && (op1_raw_r[31] ^ op2_raw_r[31]);
                            div_remainder_negate_r <= is_signed_div && op1_raw_r[31];
                            div_return_remainder_r <= is_rem_op;
                            div_phase_r            <= 1'b0;
                            div_result_r           <= 32'b0;
                    end
                end

                RV32M_MUL_ISSUE: begin
                    mul_product_r <= mul_op1_ext_r * mul_op2_ext_r;
                    state_r       <= RV32M_MUL_WAIT;
                end

                RV32M_MUL_WAIT: begin
                    state_r  <= RV32M_IDLE;
                    done_r   <= 1'b1;
                    result_o <= mul_result_final;
                end

                RV32M_DIV: begin
                    if (div_phase_r == 1'b0) begin
                        div_remainder_shift_r <= div_trial_remainder;
                        div_dividend_r        <= {div_dividend_r[30:0], 1'b0};
                        div_phase_r           <= 1'b1;
                    end else begin
                        div_remainder_r      <= div_remainder_next;
                        div_quotient_accum_r <= div_quotient_accum_next;
                        div_phase_r          <= 1'b0;

                        if (iter_count_r == 6'd1) begin
                            state_r      <= RV32M_DIV_FINISH;
                            div_result_r <= div_return_remainder_r ? div_remainder_final : div_quotient_final;
                        end

                        iter_count_r <= iter_count_r - 1'b1;
                    end
                end

                RV32M_DIV_FINISH: begin
                    state_r  <= RV32M_IDLE;
                    done_r   <= 1'b1;
                    result_o <= div_result_r;
                end

                default: begin
                    state_r <= RV32M_IDLE;
                end
            endcase
        end
    end

endmodule
