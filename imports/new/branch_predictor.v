`timescale 1ns / 1ps
`include "defines.v"

module branch_predictor #(
    parameter BHT_ADDR_WIDTH = `BP_GHR_WIDTH,
    parameter BHT_SIZE = (1 << BHT_ADDR_WIDTH),
    parameter BTB_ADDR_WIDTH = 6,
    parameter BTB_SIZE = (1 << BTB_ADDR_WIDTH),
    parameter RAS_DEPTH = 32,
    parameter RAS_PTR_WIDTH = 5,
    parameter ENABLE_JALR_RAS_PRED = 1'b1
)(
    input  wire        clk,
    input  wire        rst,

    input  wire        if_valid_i,
    input  wire [31:0] if_inst_i,
    input  wire [31:0] if_pc_i,

    // Request-address-stage lookup.  These outputs are registered beside the
    // synchronous IROM request by the top level and travel with its response.
    input  wire [31:0] req_pc_i,
    output wire        req_btb_hit_o,
    output wire        req_pred_taken_o,
    output wire [31:0] req_pred_target_o,

    output reg         pred_taken_o,
    output reg  [31:0] pred_target_o,
    output wire [BHT_ADDR_WIDTH-1:0] pred_ghr_o,

    input  wire        update_en_i,
    input  wire [29:0] update_pc_word_i,
    input  wire [31:0] update_target_i,
    input  wire [BHT_ADDR_WIDTH-1:0] update_ghr_i,
    input  wire        ras_push_en_i,
    input  wire        ras_pop_en_i,
    input  wire [31:0] ras_push_addr_i,
    input  wire        actual_taken_i
);

    // Do not force max_fanout on wide datapath buses.
    // Excessive register replication can worsen physical routing timing.
    localparam [1:0] STRONGLY_NOT_TAKEN = 2'b00;
    localparam [1:0] WEAKLY_NOT_TAKEN   = 2'b01;
    localparam [1:0] WEAKLY_TAKEN       = 2'b10;
    localparam [1:0] STRONGLY_TAKEN     = 2'b11;
    localparam BTB_TAG_WIDTH = 32 - BTB_ADDR_WIDTH - 2;

    localparam [RAS_PTR_WIDTH-1:0] RAS_LAST_PTR    = {RAS_PTR_WIDTH{1'b1}};
    localparam [RAS_PTR_WIDTH:0]   RAS_DEPTH_COUNT = {1'b1, {RAS_PTR_WIDTH{1'b0}}};

   (* ram_style = "distributed" *) reg [1:0] bht [0:BHT_SIZE-1];
   (* ram_style = "distributed" *) reg       bht_valid [0:BHT_SIZE-1];
   (* ram_style = "distributed" *) reg       btb_valid [0:BTB_SIZE-1];
   (* ram_style = "distributed" *) reg [BTB_TAG_WIDTH-1:0] btb_tag [0:BTB_SIZE-1];
   (* ram_style = "distributed" *) reg [31:0] btb_target [0:BTB_SIZE-1];
   reg [BHT_ADDR_WIDTH-1:0] ghr_r;
   reg [31:0] ras [0:RAS_DEPTH-1];
   reg [RAS_PTR_WIDTH-1:0] ras_sp_r;
   reg [RAS_PTR_WIDTH:0] ras_count_r;

   function [BHT_ADDR_WIDTH-1:0] pc_hash;
        input [(2*BHT_ADDR_WIDTH)-1:0] pc_bits;
        begin
            pc_hash = pc_bits[BHT_ADDR_WIDTH-1:0] ^
                      pc_bits[(2*BHT_ADDR_WIDTH)-1:BHT_ADDR_WIDTH];
        end
   endfunction

   wire [6:0] opcode = if_inst_i[6:0];
   wire [2:0] funct3 = if_inst_i[14:12];
   wire [4:0] rd     = if_inst_i[11:7];
   wire [4:0] rs1    = if_inst_i[19:15];

    wire [BHT_ADDR_WIDTH-1:0] pred_pc_idx =
        pc_hash(if_pc_i[(2*BHT_ADDR_WIDTH)+1:2]);
    wire [BHT_ADDR_WIDTH-1:0] req_pc_idx =
        pc_hash(req_pc_i[(2*BHT_ADDR_WIDTH)+1:2]);
   wire [BHT_ADDR_WIDTH-1:0] update_pc_idx =
        pc_hash(update_pc_word_i[(2*BHT_ADDR_WIDTH)-1:0]);
    wire [BHT_ADDR_WIDTH-1:0] pred_idx      = pred_pc_idx ^ ghr_r;
    wire [BHT_ADDR_WIDTH-1:0] req_pred_idx  = req_pc_idx ^ ghr_r;
   wire [BHT_ADDR_WIDTH-1:0] update_idx    = update_pc_idx ^ update_ghr_i;
    wire [BTB_ADDR_WIDTH-1:0] req_btb_idx = req_pc_i[BTB_ADDR_WIDTH+1:2];
    wire [BTB_ADDR_WIDTH-1:0] update_btb_idx =
        update_pc_word_i[BTB_ADDR_WIDTH-1:0];

   wire [31:0] b_imm =
        {{20{if_inst_i[31]}}, if_inst_i[7], if_inst_i[30:25], if_inst_i[11:8], 1'b0};
    wire [31:0] j_imm =
        {{12{if_inst_i[31]}}, if_inst_i[19:12], if_inst_i[20], if_inst_i[30:21], 1'b0};

    wire btfnt_taken = b_imm[31];

    wire rd_is_link  = (rd == 5'b00001)||(rd == 5'b00101);
    wire rs1_is_link = (rs1 == 5'b00001)||(rs1 == 5'b00101);

    wire ras_nonempty = (ras_count_r != {RAS_PTR_WIDTH+1{1'b0}});
    wire [RAS_PTR_WIDTH-1:0] ras_top_idx =
        (ras_sp_r == {RAS_PTR_WIDTH{1'b0}}) ? RAS_LAST_PTR : (ras_sp_r - 1'b1);

    wire is_jalr_hint = (opcode == `INST_JALR) && (funct3 == 3'b000);
    wire ras_pred_pop = is_jalr_hint && rs1_is_link && (!rd_is_link || (rd != rs1));
    wire ras_pred_valid =
        ENABLE_JALR_RAS_PRED && ras_pred_pop && ras_nonempty;

    wire branch_bht_pred_taken_w = bht_valid[pred_idx] ? bht[pred_idx][1] : btfnt_taken;
    wire req_branch_bht_pred_taken_w =
        bht_valid[req_pred_idx] ? bht[req_pred_idx][1] :
        (btb_target[req_btb_idx] < req_pc_i);
    wire [31:0] branch_pred_target_w = if_pc_i + b_imm;
    wire [31:0] jal_pred_target_w    = if_pc_i + j_imm;
    wire [31:0] jalr_pred_target_w   = ras[ras_top_idx];

    integer i;
    integer j;

    assign pred_ghr_o = ghr_r;
    assign req_btb_hit_o = btb_valid[req_btb_idx] &&
                           (btb_tag[req_btb_idx] ==
                            req_pc_i[31:BTB_ADDR_WIDTH+2]);
    assign req_pred_taken_o = req_btb_hit_o && req_branch_bht_pred_taken_w;
    assign req_pred_target_o = btb_target[req_btb_idx];

    initial begin
        for (i = 0; i < BHT_SIZE; i = i + 1) begin
            bht[i] = WEAKLY_NOT_TAKEN;
            bht_valid[i] = 1'b0;
        end
        for (j = 0; j < BTB_SIZE; j = j + 1) begin
            btb_valid[j] = 1'b0;
            btb_tag[j] = {BTB_TAG_WIDTH{1'b0}};
            btb_target[j] = 32'b0;
        end
    end

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            ghr_r       <= {BHT_ADDR_WIDTH{1'b0}};
            ras_sp_r    <= {RAS_PTR_WIDTH{1'b0}};
            ras_count_r <= {RAS_PTR_WIDTH+1{1'b0}};
        end else begin
            if (update_en_i) begin
                btb_valid[update_btb_idx] <= 1'b1;
                btb_tag[update_btb_idx] <= update_pc_word_i[29:BTB_ADDR_WIDTH];
                btb_target[update_btb_idx] <= update_target_i;
                bht_valid[update_idx] <= 1'b1;

                case (bht[update_idx])
                    STRONGLY_NOT_TAKEN: bht[update_idx] <= actual_taken_i ? WEAKLY_NOT_TAKEN : STRONGLY_NOT_TAKEN;
                    WEAKLY_NOT_TAKEN:   bht[update_idx] <= actual_taken_i ? WEAKLY_TAKEN     : STRONGLY_NOT_TAKEN;
                    WEAKLY_TAKEN:       bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_NOT_TAKEN;
                    default:            bht[update_idx] <= actual_taken_i ? STRONGLY_TAKEN   : WEAKLY_TAKEN;
                endcase

                ghr_r <= {ghr_r[BHT_ADDR_WIDTH-2:0], actual_taken_i};
            end

            case ({ras_push_en_i, ras_pop_en_i})
                2'b01: begin
                    if (ras_nonempty) begin
                        ras_sp_r    <= ras_top_idx;
                        ras_count_r <= ras_count_r - 1'b1;
                    end
                end
                2'b10: begin
                    ras[ras_sp_r] <= ras_push_addr_i;
                    ras_sp_r <= ras_sp_r + 1'b1;
                    if (ras_count_r != RAS_DEPTH_COUNT) begin
                        ras_count_r <= ras_count_r + 1'b1;
                    end
                end
                2'b11: begin
                    if (ras_nonempty) begin
                        // Pop followed by push replaces the current top while
                        // preserving stack depth and pointer.
                        ras[ras_top_idx] <= ras_push_addr_i;
                    end else begin
                        ras[ras_sp_r] <= ras_push_addr_i;
                        ras_sp_r <= ras_sp_r + 1'b1;
                        ras_count_r <= ras_count_r + 1'b1;
                    end
                end
                default: begin
                end
            endcase
        end
    end

    always @(*) begin
        pred_taken_o  = 1'b0;
        pred_target_o = 32'b0;

        if (if_valid_i) begin
            case (opcode)
                `INST_TYPE_B: begin
                    pred_taken_o  = branch_bht_pred_taken_w;
                    pred_target_o = branch_pred_target_w;
                end

                `INST_JAL: begin
                    pred_taken_o  = 1'b1;
                    pred_target_o = jal_pred_target_w;
                end

                `INST_JALR: begin
                    pred_taken_o  = ras_pred_valid;
                    pred_target_o = jalr_pred_target_w;
                end

                default: begin
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                end
            endcase
        end
    end

endmodule
