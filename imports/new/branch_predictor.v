`include "defines.v"

module branch_predictor(
    input  wire        clk,
    input  wire        rst,

    input  wire        if_valid_i,
    input  wire [31:0] if_inst_i,
    input  wire [31:0] if_pc_i,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,

    output reg         pred_taken_o,
    output reg  [31:0] pred_target_o,
    output reg         pred_flush_o,

    input  wire        update_en_i,
    input  wire [31:0] update_pc_i,
    input  wire        actual_taken_i
);

    parameter BHT_ADDR_WIDTH = 7;
    parameter BHT_SIZE = 128;

    localparam [1:0] STRONGLY_NOT_TAKEN = 2'b00;
    localparam [1:0] WEAKLY_NOT_TAKEN   = 2'b01;
    localparam [1:0] WEAKLY_TAKEN       = 2'b10;
    localparam [1:0] STRONGLY_TAKEN     = 2'b11;

    reg [1:0] bht [0:BHT_SIZE-1];

    wire [6:0] opcode = if_inst_i[6:0];
    wire [BHT_ADDR_WIDTH-1:0] pred_idx   = if_pc_i[8:2];
    wire [BHT_ADDR_WIDTH-1:0] update_idx = update_pc_i[8:2];

    wire [31:0] b_imm =
        {{20{if_inst_i[31]}}, if_inst_i[7], if_inst_i[30:25], if_inst_i[11:8], 1'b0};
    wire [31:0] j_imm =
        {{12{if_inst_i[31]}}, if_inst_i[19:12], if_inst_i[20], if_inst_i[30:21], 1'b0};

    integer i;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            for (i = 0; i < BHT_SIZE; i = i + 1) begin
                bht[i] <= WEAKLY_NOT_TAKEN;
            end
            pred_flush_o <= 1'b0;
        end else begin
            if (update_en_i) begin
                case (bht[update_idx])
                    STRONGLY_NOT_TAKEN: bht[update_idx] <= actual_taken_i ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                    WEAKLY_NOT_TAKEN:   bht[update_idx] <= actual_taken_i ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
                    WEAKLY_TAKEN:       bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
                    default:            bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
                endcase
            end

            if (flush_flag_i) begin
                pred_flush_o <= 1'b0;
            end else begin
                pred_flush_o <= if_valid_i && pred_taken_o && (hold_flag_i == 1'b0);
            end
        end
    end

    always @(*) begin
        pred_taken_o  = 1'b0;
        pred_target_o = 32'b0;

        if (if_valid_i) begin
            case (opcode)
                `INST_TYPE_B: begin
                    if (bht[pred_idx][1] == 1'b1) begin
                        pred_taken_o  = 1'b1;
                        pred_target_o = if_pc_i + b_imm;
                    end
                end
                `INST_JAL: begin
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                end
                default: begin
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                end
            endcase
        end
    end

endmodule
