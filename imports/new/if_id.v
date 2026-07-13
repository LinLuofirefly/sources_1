`timescale 1ns / 1ps
`include "defines.v"

module if_id (
    input  wire        clk,
    input  wire        rst,

    // 表示当前 inst_i / inst_addr_i / pred_*_i 这个 fetch 包有效。
    // 注意：这个信号不应该因为 hold 而变 0。
    // hold 时如果 load_valid_i=1，模块会把这个包存入 skid buffer。
    input  wire        load_valid_i,

    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire        pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [`BP_GHR_WIDTH-1:0] pred_ghr_i,

    input  wire        hold_flag_i,
    input  wire        flush_flag_i,

    output reg  [31:0] inst_addr_o,
    output reg         pred_taken_o,
    output reg  [31:0] pred_target_o,
    output reg  [`BP_GHR_WIDTH-1:0] pred_ghr_o,
    output reg  [31:0] inst_o,

    // 本拍 IF/ID 是否真正装载/回放了一个包。
    // 用于顶层判断 replay predicted-taken 是否需要 redirect。
    output reg         load_valid_o,
    output reg         load_pred_taken_o,
    output reg  [31:0] load_pred_target_o,

    output wire        replaying_o,
    output wire        replay_pending_o
);

    reg [31:0] hold_inst_reg;
    reg [31:0] hold_inst_addr_reg;
    reg        hold_pred_taken_reg;
    reg [31:0] hold_pred_target_reg;
    reg [`BP_GHR_WIDTH-1:0] hold_pred_ghr_reg;

    reg        is_holding_reg;
    reg        replaying_reg;
    reg        replay_pending_reg;

    assign replaying_o      = replaying_reg;
    assign replay_pending_o = replay_pending_reg;

    always @(posedge clk) begin
        if (rst == 1'b0 || flush_flag_i == 1'b1) begin
            inst_addr_o          <= 32'b0;
            inst_o               <= `INST_NOP;
            pred_taken_o         <= 1'b0;
            pred_target_o        <= 32'b0;
            pred_ghr_o           <= {`BP_GHR_WIDTH{1'b0}};

            load_valid_o         <= 1'b0;
            load_pred_taken_o    <= 1'b0;
            load_pred_target_o   <= 32'b0;

            hold_inst_reg        <= 32'b0;
            hold_inst_addr_reg   <= 32'b0;
            hold_pred_taken_reg  <= 1'b0;
            hold_pred_target_reg <= 32'b0;
            hold_pred_ghr_reg    <= {`BP_GHR_WIDTH{1'b0}};

            is_holding_reg       <= 1'b0;
            replaying_reg        <= 1'b0;
            replay_pending_reg   <= 1'b0;

        end else if (hold_flag_i == 1'b1) begin
            // hold 期间 IF/ID 输出保持不变，但本拍没有对外“装载新包”。
            load_valid_o         <= 1'b0;
            load_pred_taken_o    <= 1'b0;
            load_pred_target_o   <= 32'b0;
            replaying_reg        <= replaying_reg;

            // 关键：hold 时仍然允许保存当前有效 fetch 包。
            // 这要求顶层 load_valid_i 不要被 hold gate 掉。
            if (load_valid_i == 1'b1 && is_holding_reg == 1'b0) begin
                hold_inst_reg        <= inst_i;
                hold_inst_addr_reg   <= inst_addr_i;
                hold_pred_taken_reg  <= pred_taken_i;
                hold_pred_target_reg <= pred_target_i;
                hold_pred_ghr_reg    <= pred_ghr_i;

                is_holding_reg       <= 1'b1;
                replay_pending_reg   <= 1'b1;
            end

        end else begin
            if (is_holding_reg == 1'b1) begin
                // stall 释放后，优先 replay skid buffer 中保存的包。
                inst_addr_o          <= hold_inst_addr_reg;
                inst_o               <= hold_inst_reg;
                pred_taken_o         <= hold_pred_taken_reg;
                pred_target_o        <= hold_pred_target_reg;
                pred_ghr_o           <= hold_pred_ghr_reg;

                load_valid_o         <= 1'b1;
                load_pred_taken_o    <= hold_pred_taken_reg;
                load_pred_target_o   <= hold_pred_taken_reg ? hold_pred_target_reg : 32'b0;

                is_holding_reg       <= 1'b0;
                replaying_reg        <= 1'b1;
                replay_pending_reg   <= 1'b0;

            end else begin
            // 正常无 hold、无 replay 的路径

            replaying_reg       <= 1'b0;
            replay_pending_reg  <= 1'b0;

            if (load_valid_i == 1'b1) begin
                // 有效 fetch 包进入 IF/ID
                inst_addr_o          <= inst_addr_i;
                inst_o               <= inst_i;
                pred_taken_o         <= pred_taken_i;
                pred_target_o        <= pred_target_i;
                pred_ghr_o           <= pred_ghr_i;

                load_valid_o         <= 1'b1;
                load_pred_taken_o    <= pred_taken_i;
                load_pred_target_o   <= pred_taken_i ? pred_target_i : 32'b0;
            end else begin
                // 关键：无有效 fetch 包时，向后级送 bubble，而不是保持旧指令
                inst_addr_o          <= 32'b0;
                inst_o               <= `INST_NOP;
                pred_taken_o         <= 1'b0;
                pred_target_o        <= 32'b0;
                pred_ghr_o           <= {`BP_GHR_WIDTH{1'b0}};

                load_valid_o         <= 1'b0;
                load_pred_taken_o    <= 1'b0;
                load_pred_target_o   <= 32'b0;
            end
        end
        end
    end

endmodule
