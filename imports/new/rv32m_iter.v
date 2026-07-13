`timescale 1ns / 1ps
`include "defines.v"

// ============================================================================
// RV32M iterative multiply/divide execution unit
// ----------------------------------------------------------------------------
// 功能：
//   实现 RISC-V RV32M 扩展中的乘法、除法和取余指令：
//     MUL / MULH / MULHSU / MULHU
//     DIV / DIVU / REM / REMU
//
// 接口语义：
//   start_i  ：EX 阶段发起一次 RV32M 运算请求。
//   func3_i  ：指令 funct3，用于区分 MUL/DIV/REM 以及 signed/unsigned 类型。
//   op1_i    ：源操作数 1。
//   op2_i    ：源操作数 2。
//   busy_o   ：模块非 IDLE 时拉高，表示 RV32M 单元正在计算，流水线需要 hold。
//   done_o   ：结果完成时拉高 1 拍。
//   result_o ：最终 32-bit 运算结果。
//
// 设计思路：
//   1. PREP 阶段先锁存原始操作数和 funct3，避免 ID/EX 侧信号直接驱动
//      后续大量符号扩展、取绝对值、比较和状态机逻辑，降低关键路径扇出。
//   2. 乘法使用 33x33 signed 扩展操作数：
//        - signed 操作数复制符号位；
//        - unsigned 操作数最高位补 0；
//      从而统一覆盖 MUL/MULH/MULHSU/MULHU，并让综合工具尽量映射到 DSP。
//   3. 除法/取余先转换为无符号幅值运算，完成 restoring division 后，
//      再根据 DIV/REM 和操作数符号修正 quotient/remainder 的符号。
//   4. 对除零、INT_MIN / -1 溢出、被除数为 0、被除数小于除数、除数为 1 等
//      特殊情况提前返回，减少无意义迭代。
//
// 状态机：
//   RV32M_IDLE       ：空闲，等待 start_i。
//   RV32M_PREP       ：锁存操作数后进行指令类型判断和特殊情况快速处理。
//   RV32M_MUL_WAIT   ：等待乘法结果稳定，并输出低 32 位或高 32 位。
//   RV32M_DIV        ：两阶段 restoring divider 主循环，每个 quotient bit 用两拍。
//   RV32M_DIV_FINISH ：除法/取余结果符号修正后输出 done。
// ============================================================================
module rv32m_iter (
    input  wire        clk,
    input  wire        rst,

    // start_i 拉高表示 EX 阶段发起一次 RV32M 运算请求。
    // 上层应保证 start_i 只在模块不 busy 时发起，避免覆盖当前运算。
    input  wire        start_i,

    // RISC-V 指令 funct3，用于区分 MUL/DIV/REM 具体类型。
    input  wire [2:0]  func3_i,

    // 两个源操作数。
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,

    // busy_o 表示模块正在计算，流水线需要等待。
    output wire        busy_o,

    // done_o 表示 result_o 有效，只保持 1 拍。
    output wire        done_o,

    // 最终 32-bit 结果。
    output reg  [31:0] result_o
);

    // ------------------------------------------------------------------------
    // FSM state encoding
    // ------------------------------------------------------------------------
    // PREP 先锁存 raw operand，使符号判断、绝对值、乘法扩展等逻辑
    // 不直接从 ID/EX 大扇出驱动，从而改善 EX 阶段时序。
    localparam [2:0] RV32M_IDLE       = 3'b000;
    localparam [2:0] RV32M_PREP       = 3'b001;
    localparam [2:0] RV32M_MUL_WAIT   = 3'b011;
    localparam [2:0] RV32M_DIV        = 3'b100;
    localparam [2:0] RV32M_DIV_FINISH = 3'b101;

    // 当前状态寄存器。
    reg [2:0] state_r;

    // done_r 为结果完成标志，只拉高 1 拍。
    reg       done_r;

    // 锁存后的 funct3。
    // 后续所有 MUL/DIV 类型判断都基于 func3_r，而不是直接使用 func3_i。
    reg [2:0] func3_r;

    // 除法迭代计数器。
    // 普通 32-bit 除法需要生成 32 bit 商，因此初始为 32。
    reg [5:0] iter_count_r;

    // 锁存后的原始操作数。
    reg [31:0] op1_raw_r;
    reg [31:0] op2_raw_r;

    // 乘法结果寄存器。
    // 33x33 乘法结果需要 66 bit。
    // use_dsp 提示综合器尽量将乘法映射到 DSP 资源。
    (* use_dsp = "yes" *) reg signed [65:0] mul_product_r;

    // ------------------------------------------------------------------------
    // Divider registers
    // ------------------------------------------------------------------------
    // restoring division 中的 33-bit remainder。
    // 多出来的 1 bit 用于比较/减法，防止溢出。
    reg [32:0] div_remainder_r;

    // phase 0 后暂存的 trial remainder。
    reg [32:0] div_remainder_shift_r;

    // 被除数移位寄存器。
    // 每轮取最高位移入 remainder，然后自身左移一位。
    reg [31:0] div_dividend_r;

    // 除数幅值。
    reg [31:0] div_divisor_r;

    // 商累加寄存器。
    // 每轮根据是否能减 divisor 追加 1 bit 商。
    reg [31:0] div_quotient_accum_r;

    // quotient 是否需要取负。
    // signed DIV/DIVU 中，quotient 符号 = op1 符号 XOR op2 符号。
    reg        div_quotient_negate_r;

    // remainder 是否需要取负。
    // RISC-V 规定 signed remainder 的符号跟 dividend 一致。
    reg        div_remainder_negate_r;

    // 当前指令是否返回 remainder。
    // REM/REMU 返回 remainder，DIV/DIVU 返回 quotient。
    reg        div_return_remainder_r;

    // 除法两阶段标志：
    //   0：shift dividend bit into remainder
    //   1：compare/subtract and append quotient bit
    reg        div_phase_r;

    // 除法/取余最终结果暂存。
    reg [31:0] div_result_r;

    // ------------------------------------------------------------------------
    // Instruction type decode
    // ------------------------------------------------------------------------
    // 判断当前锁存的 RV32M 指令是否属于乘法类。
    wire is_mul_op = (func3_r == `INST_MUL)    ||
                     (func3_r == `INST_MULH)   ||
                     (func3_r == `INST_MULHSU) ||
                     (func3_r == `INST_MULHU);

    // MUL/MULH/MULHSU/MULHU 的符号扩展规则：
    //   MUL    ：A signed，B signed，取低 32 位。
    //   MULH   ：A signed，B signed，取高 32 位。
    //   MULHSU ：A signed，B unsigned，取高 32 位。
    //   MULHU  ：A unsigned，B unsigned，取高 32 位。
    wire is_signed_mul_a = (func3_r == `INST_MUL) ||
                           (func3_r == `INST_MULH) ||
                           (func3_r == `INST_MULHSU);

    wire is_signed_mul_b = (func3_r == `INST_MUL) ||
                           (func3_r == `INST_MULH);

    // ------------------------------------------------------------------------
    // Multiply datapath
    // ------------------------------------------------------------------------
    // 使用 33-bit signed 扩展统一处理 signed/unsigned 乘法。
    // signed 操作数复制符号位；unsigned 操作数最高位补 0。
    wire signed [32:0] mul_op1_ext_w =
        is_signed_mul_a ? $signed({op1_raw_r[31], op1_raw_r}) :
                          $signed({1'b0, op1_raw_r});

    wire signed [32:0] mul_op2_ext_w =
        is_signed_mul_b ? $signed({op2_raw_r[31], op2_raw_r}) :
                          $signed({1'b0, op2_raw_r});

    // 低 64 bit 是 RV32M 所需要的完整乘积。
    wire [63:0] mul_product_final = mul_product_r[63:0];

    // MUL 取低 32 位；MULH/MULHSU/MULHU 取高 32 位。
    wire [31:0] mul_result_final =
        (func3_r == `INST_MUL) ? mul_product_final[31:0] :
                                 mul_product_final[63:32];

    // ------------------------------------------------------------------------
    // Divide instruction decode
    // ------------------------------------------------------------------------
    // signed DIV/REM 需要先对操作数取绝对值，再在最后修正符号。
    wire is_signed_div = (func3_r == `INST_DIV) || (func3_r == `INST_REM);

    // REM/REMU 返回 remainder；DIV/DIVU 返回 quotient。
    wire is_rem_op     = (func3_r == `INST_REM) || (func3_r == `INST_REMU);

    // ------------------------------------------------------------------------
    // Divide special cases and magnitude conversion
    // ------------------------------------------------------------------------
    // signed 除法内部先转换为幅值做 unsigned division。
    wire [31:0] div_op1_abs =
        (is_signed_div && op1_raw_r[31]) ? (~op1_raw_r + 32'd1) :
                                           op1_raw_r;

    wire [31:0] div_op2_abs =
        (is_signed_div && op2_raw_r[31]) ? (~op2_raw_r + 32'd1) :
                                           op2_raw_r;

    // RISC-V signed overflow 只有一种情况：
    //   INT_MIN / -1 = 0x80000000 / 0xffffffff
    // 结果 quotient = INT_MIN，remainder = 0。
    wire div_overflow =
        is_signed_div &&
        (op1_raw_r == 32'h8000_0000) &&
        (op2_raw_r == 32'hffff_ffff);

    // 常见快速返回条件。
    wire div_dividend_zero = (div_op1_abs == 32'b0);
    wire div_dividend_less = (div_op1_abs < div_op2_abs);
    wire div_divisor_one   = (div_op2_abs == 32'd1);

    // ------------------------------------------------------------------------
    // Restoring divider combinational next-state
    // ------------------------------------------------------------------------
    // 两阶段 restoring divider：
    //   phase 0：
    //     将 dividend 当前最高位移入 remainder，得到 trial remainder。
    //   phase 1：
    //     trial remainder 与 divisor 比较；
    //     若 trial >= divisor，则 remainder -= divisor，商追加 1；
    //     否则 remainder 保持不变，商追加 0。
    //
    // 因为每个 quotient bit 分两拍完成，所以普通 32-bit 除法大约需要 64 拍。
    wire [32:0] div_trial_remainder =
        {div_remainder_r[31:0], div_dividend_r[31]};

    wire div_can_subtract =
        (div_remainder_shift_r >= {1'b0, div_divisor_r});

    wire [32:0] div_remainder_next =
        div_can_subtract ? (div_remainder_shift_r - {1'b0, div_divisor_r}) :
                           div_remainder_shift_r;

    wire [31:0] div_quotient_accum_next =
        {div_quotient_accum_r[30:0], div_can_subtract};

    // 最后根据符号标志修正 quotient/remainder。
    wire [31:0] div_quotient_final =
        div_quotient_negate_r ? (~div_quotient_accum_next + 32'd1) :
                                div_quotient_accum_next;

    wire [31:0] div_remainder_final =
        div_remainder_negate_r ? (~div_remainder_next[31:0] + 32'd1) :
                                 div_remainder_next[31:0];

    // ------------------------------------------------------------------------
    // Handshake outputs
    // ------------------------------------------------------------------------
    // 非 IDLE 状态表示 RV32M 单元正在工作，上层流水线需要 hold。
    assign busy_o = (state_r != RV32M_IDLE);

    // done_o 只在结果完成时拉高 1 拍。
    assign done_o = done_r;

    // ------------------------------------------------------------------------
    // Main FSM
    // ------------------------------------------------------------------------
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            state_r                 <= RV32M_IDLE;
            done_r                  <= 1'b0;
            func3_r                 <= 3'b0;
            iter_count_r            <= 6'b0;
            op1_raw_r               <= 32'b0;
            op2_raw_r               <= 32'b0;
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
            // done_r 是 1 拍脉冲。
            // 如果上一拍已经置 1，本拍自动清零，避免同一个结果被重复接收。
            if (done_r == 1'b1) begin
                done_r <= 1'b0;
            end

            case (state_r)
                // ------------------------------------------------------------
                // IDLE：等待新 RV32M 请求
                // ------------------------------------------------------------
                RV32M_IDLE: begin
                    if (start_i == 1'b1) begin
                        state_r      <= RV32M_PREP;
                        func3_r      <= func3_i;
                        op1_raw_r    <= op1_i;
                        op2_raw_r    <= op2_i;
                        iter_count_r <= 6'd0;
                    end
                end

                // ------------------------------------------------------------
                // PREP：操作数准备、类型判断、特殊情况快速返回
                // ------------------------------------------------------------
                RV32M_PREP: begin
                    if (is_mul_op == 1'b1) begin
                        // 乘法中任意操作数为 0，结果直接为 0，无需启动 DSP 乘法。
                        if ((op1_raw_r == 32'b0) || (op2_raw_r == 32'b0)) begin
                            state_r  <= RV32M_IDLE;
                            result_o <= 32'b0;
                            done_r   <= 1'b1;
                        end else begin
                            // 原始操作数已经寄存；在 PREP 直接寄存 DSP
                            // 结果，跳过原先仅用于发起乘法的控制周期。
                            state_r       <= RV32M_MUL_WAIT;
                            mul_product_r <= mul_op1_ext_w * mul_op2_ext_w;
                        end
                    end else if (op2_raw_r == 32'b0) begin
                        // RISC-V 对除零的规定：
                        //   DIV/DIVU 结果为全 1；
                        //   REM/REMU 结果为 dividend。
                        state_r  <= RV32M_IDLE;
                        result_o <= is_rem_op ? op1_raw_r : 32'hffff_ffff;
                        done_r   <= 1'b1;
                    end else if (div_overflow == 1'b1) begin
                        // signed overflow 只发生在 INT_MIN / -1。
                        //   quotient  = INT_MIN
                        //   remainder = 0
                        state_r  <= RV32M_IDLE;
                        result_o <= is_rem_op ? 32'b0 : 32'h8000_0000;
                        done_r   <= 1'b1;
                    end else if (div_dividend_zero == 1'b1) begin
                        // 0 / divisor = 0，0 % divisor = 0。
                        state_r  <= RV32M_IDLE;
                        result_o <= 32'b0;
                        done_r   <= 1'b1;
                    end else if (div_dividend_less == 1'b1) begin
                        // |dividend| < |divisor| 时：
                        //   quotient  = 0
                        //   remainder = dividend
                        state_r  <= RV32M_IDLE;
                        result_o <= is_rem_op ? op1_raw_r : 32'b0;
                        done_r   <= 1'b1;
                    end else if (div_divisor_one == 1'b1) begin
                        // divisor 幅值为 1 时快速返回：
                        //   remainder = 0
                        //   quotient 根据 signed 规则决定是否取负。
                        state_r  <= RV32M_IDLE;
                        result_o <= is_rem_op ? 32'b0 :
                                    ((is_signed_div && (op1_raw_r[31] ^ op2_raw_r[31])) ?
                                     (~div_op1_abs + 32'd1) :
                                      div_op1_abs);
                        done_r   <= 1'b1;
                    end else begin
                        // 普通除法路径：
                        //   初始化 restoring divider 所需寄存器。
                        //   内部统一对操作数幅值做 unsigned division。
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

                // ------------------------------------------------------------
                // MUL_WAIT：输出乘法结果
                // ------------------------------------------------------------
                RV32M_MUL_WAIT: begin
                    // MUL 取低 32 位，其余 MULH 类指令取高 32 位。
                    state_r  <= RV32M_IDLE;
                    done_r   <= 1'b1;
                    result_o <= mul_result_final;
                end

                // ------------------------------------------------------------
                // DIV：两阶段 restoring division
                // ------------------------------------------------------------
                RV32M_DIV: begin
                    if (div_phase_r == 1'b0) begin
                        // phase 0：
                        //   将 dividend 最高位移入 remainder，形成 trial remainder；
                        //   dividend 左移，为下一轮准备。
                        div_remainder_shift_r <= div_trial_remainder;
                        div_dividend_r        <= {div_dividend_r[30:0], 1'b0};
                        div_phase_r           <= 1'b1;
                    end else begin
                        // phase 1：
                        //   根据 trial remainder 是否大于等于 divisor，
                        //   决定是否执行减法，并追加当前 quotient bit。
                        div_remainder_r      <= div_remainder_next;
                        div_quotient_accum_r <= div_quotient_accum_next;
                        div_phase_r          <= 1'b0;

                        // 最后一轮完成后，提前计算符号修正后的最终结果。
                        if (iter_count_r == 6'd1) begin
                            state_r      <= RV32M_DIV_FINISH;
                            div_result_r <= div_return_remainder_r ?
                                            div_remainder_final :
                                            div_quotient_final;
                        end

                        // 每完成一轮 quotient bit，计数器减 1。
                        iter_count_r <= iter_count_r - 1'b1;
                    end
                end

                // ------------------------------------------------------------
                // DIV_FINISH：输出除法/取余结果
                // ------------------------------------------------------------
                RV32M_DIV_FINISH: begin
                    state_r  <= RV32M_IDLE;
                    done_r   <= 1'b1;
                    result_o <= div_result_r;
                end

                // ------------------------------------------------------------
                // default：异常状态兜底回到 IDLE
                // ------------------------------------------------------------
                default: begin
                    state_r <= RV32M_IDLE;
                end
            endcase
        end
    end

endmodule
