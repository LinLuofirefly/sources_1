`include "defines.v"

module branch_predictor #(
    parameter BHT_ADDR_WIDTH = 9,
    parameter BHT_SIZE = 512,
    parameter RAS_DEPTH = 32,
    parameter RAS_PTR_WIDTH = 5
)(
    input  wire        clk,
    input  wire        rst,

    input  wire        if_valid_i,
    input  wire [31:0] if_inst_i,
    input  wire [31:0] if_pc_i,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,

    output reg         pred_taken_o,
    output reg  [31:0] pred_target_o,
    output wire [BHT_ADDR_WIDTH-1:0] pred_ghr_o,
    output reg         pred_flush_o,

    input  wire        update_en_i,
    input  wire [31:0] update_pc_i,
    input  wire [BHT_ADDR_WIDTH-1:0] update_ghr_i,
    input  wire        ras_push_en_i,
    input  wire        ras_pop_en_i,
    input  wire [31:0] ras_push_addr_i,
    input  wire        actual_taken_i
);

    localparam [1:0] STRONGLY_NOT_TAKEN = 2'b00;
    localparam [1:0] WEAKLY_NOT_TAKEN   = 2'b01;
    localparam [1:0] WEAKLY_TAKEN       = 2'b10;
    localparam [1:0] STRONGLY_TAKEN     = 2'b11;

    reg [1:0] bht [0:BHT_SIZE-1];
    reg       bht_valid [0:BHT_SIZE-1];
    reg [BHT_ADDR_WIDTH-1:0] ghr_r;
    reg [31:0] ras [0:RAS_DEPTH-1];
    reg [RAS_PTR_WIDTH-1:0] ras_sp_r;
    reg [RAS_PTR_WIDTH:0] ras_count_r;
    reg [RAS_PTR_WIDTH-1:0] ras_sp_next_r;
    reg [RAS_PTR_WIDTH:0] ras_count_next_r;

    wire [6:0] opcode = if_inst_i[6:0];
    wire [2:0] func3  = if_inst_i[14:12];
    wire [4:0] rd     = if_inst_i[11:7];
    wire [4:0] rs1    = if_inst_i[19:15];
    wire [BHT_ADDR_WIDTH-1:0] pred_pc_idx   = if_pc_i[BHT_ADDR_WIDTH+1:2];
    wire [BHT_ADDR_WIDTH-1:0] update_pc_idx = update_pc_i[BHT_ADDR_WIDTH+1:2];
    wire [BHT_ADDR_WIDTH-1:0] pred_idx      = pred_pc_idx ^ ghr_r;
    wire [BHT_ADDR_WIDTH-1:0] update_idx    = update_pc_idx ^ update_ghr_i;

    wire [31:0] b_imm =
        {{20{if_inst_i[31]}}, if_inst_i[7], if_inst_i[30:25], if_inst_i[11:8], 1'b0};
    wire [31:0] j_imm =
        {{12{if_inst_i[31]}}, if_inst_i[19:12], if_inst_i[20], if_inst_i[30:21], 1'b0};
    wire        btfnt_taken = b_imm[31];
    wire        rd_is_link = (rd == 5'd1) || (rd == 5'd5);
    wire        rs1_is_link = (rs1 == 5'd1) || (rs1 == 5'd5);
    wire        ras_nonempty = (ras_count_r != {RAS_PTR_WIDTH + 1{1'b0}});
    wire [RAS_PTR_WIDTH-1:0] ras_top_idx =
        (ras_sp_r == {RAS_PTR_WIDTH{1'b0}}) ? (RAS_DEPTH - 1) : (ras_sp_r - 1'b1);
    wire        is_jalr_hint = (opcode == `INST_JALR) && (func3 == 3'b000);
    wire        ras_pred_pop = is_jalr_hint && rs1_is_link && (!rd_is_link || (rd != rs1));
    wire        ras_pred_valid = ras_pred_pop && ras_nonempty;

    integer i;

    assign pred_ghr_o = ghr_r;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            for (i = 0; i < BHT_SIZE; i = i + 1) begin
                bht[i]       = WEAKLY_NOT_TAKEN;
                bht_valid[i] = 1'b0;
            end
            ghr_r <= {BHT_ADDR_WIDTH{1'b0}};
            ras_sp_r <= {RAS_PTR_WIDTH{1'b0}};
            ras_count_r <= {(RAS_PTR_WIDTH + 1){1'b0}};
            pred_flush_o <= 1'b0;
        end else begin
            if (update_en_i) begin
                bht_valid[update_idx] <= 1'b1;
                if (bht_valid[update_idx] == 1'b0) begin
                    bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN : STRONGLY_NOT_TAKEN;
                end else begin
                    case (bht[update_idx])
                        STRONGLY_NOT_TAKEN: bht[update_idx] <= actual_taken_i ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                        WEAKLY_NOT_TAKEN:   bht[update_idx] <= actual_taken_i ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
                        WEAKLY_TAKEN:       bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
                        default:            bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
                    endcase
                end

                ghr_r <= {ghr_r[BHT_ADDR_WIDTH-2:0], actual_taken_i};
            end

            if (ras_pop_en_i || ras_push_en_i) begin
                ras_sp_next_r = ras_sp_r;
                ras_count_next_r = ras_count_r;

                if (ras_pop_en_i && ras_nonempty) begin
                    ras_sp_next_r = ras_top_idx;
                    ras_count_next_r = ras_count_r - 1'b1;
                end

                if (ras_push_en_i) begin
                    ras[ras_sp_next_r] <= ras_push_addr_i;
                    ras_sp_next_r = ras_sp_next_r + 1'b1;
                    if (ras_count_next_r != RAS_DEPTH) begin
                        ras_count_next_r = ras_count_next_r + 1'b1;
                    end
                end

                ras_sp_r <= ras_sp_next_r;
                ras_count_r <= ras_count_next_r;
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
                    if (bht_valid[pred_idx] ? bht[pred_idx][1] : btfnt_taken) begin
                        pred_taken_o  = 1'b1;
                        pred_target_o = if_pc_i + b_imm;
                    end
                end
                `INST_JAL: begin
                    pred_taken_o  = 1'b1;
                    pred_target_o = if_pc_i + j_imm;
                end
                `INST_JALR: begin
                    if (ras_pred_valid) begin
                        pred_taken_o  = 1'b1;
                        pred_target_o = ras[ras_top_idx];
                    end
                end
                default: begin
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                end
            endcase
        end
    end

endmodule
