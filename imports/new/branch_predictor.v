`timescale 1ns / 1ps
`include "defines.v"

module branch_predictor #(
    parameter BHT_ADDR_WIDTH = `BP_GHR_WIDTH,
    parameter BHT_SIZE = (1 << BHT_ADDR_WIDTH),
    parameter BTB_ADDR_WIDTH = 6,
    parameter BTB_SIZE = (1 << BTB_ADDR_WIDTH),
    parameter RAS_DEPTH = 32,
    parameter RAS_PTR_WIDTH = 5,
    parameter ENABLE_JALR_RAS_PRED = 1'b1,
    parameter ITC_ADDR_WIDTH = 6,
    parameter ITC_SIZE = (1 << ITC_ADDR_WIDTH),
    parameter HIST_ITC_ADDR_WIDTH = 8,
    parameter HIST_ITC_SIZE = (1 << HIST_ITC_ADDR_WIDTH),
    parameter HIST_ITC_TAG_WIDTH = 16,
    parameter ITC_CHOOSER_ADDR_WIDTH = 6,
    parameter ITC_CHOOSER_SIZE = (1 << ITC_CHOOSER_ADDR_WIDTH),
    parameter ENABLE_INDIRECT_JALR_PRED = 1'b1
)(
    input  wire        clk,
    input  wire        rst,

    input  wire        if_valid_i,
    input  wire [31:0] if_inst_i,
    input  wire [31:0] if_pc_i,
    input  wire [BHT_ADDR_WIDTH-1:0] if_ghr_i,

    // Request-address-stage lookup.  These outputs are registered beside the
    // synchronous IROM request by the top level and travel with its response.
    input  wire [31:0] req_pc_i,
    output wire        req_btb_hit_o,
    output wire        req_pred_valid_o,
    output wire        req_pred_taken_o,
    output wire [31:0] req_pred_target_o,
    output wire [BHT_ADDR_WIDTH-1:0] req_pred_ghr_o,
    output wire [1:0]  req_pred_type_o,

    output reg         pred_taken_o,
    output reg  [31:0] pred_target_o,
    output wire [BHT_ADDR_WIDTH-1:0] pred_ghr_o,
    output reg  [1:0]  pred_type_o,

    input  wire        update_en_i,
    input  wire [29:0] update_pc_word_i,
    input  wire [31:0] update_target_i,
    input  wire [BHT_ADDR_WIDTH-1:0] update_ghr_i,
    input  wire        ras_push_en_i,
    input  wire        ras_pop_en_i,
    input  wire [31:0] ras_push_addr_i,
    input  wire        jalr_update_en_i,
    input  wire [31:0] jalr_update_pc_i,
    input  wire [31:0] jalr_update_target_i,
    input  wire [BHT_ADDR_WIDTH-1:0] jalr_update_ghr_i,
    input  wire        jalr_update_is_call_i,
    input  wire        actual_taken_i
);

    // Do not force max_fanout on wide datapath buses.
    // Excessive register replication can worsen physical routing timing.
    localparam [1:0] STRONGLY_NOT_TAKEN = 2'b00;
    localparam [1:0] WEAKLY_NOT_TAKEN   = 2'b01;
    localparam [1:0] WEAKLY_TAKEN       = 2'b10;
    localparam [1:0] STRONGLY_TAKEN     = 2'b11;
    localparam BTB_TAG_WIDTH = 32 - BTB_ADDR_WIDTH - 2;
    localparam ITC_TAG_WIDTH = 32 - ITC_ADDR_WIDTH - 2;
    localparam ITC_CHOOSER_TAG_WIDTH = 32 - ITC_CHOOSER_ADDR_WIDTH - 2;

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
   // Last-target component: learns stable function-pointer calls after their
   // first execution, so the second execution can already be predicted.
   (* ram_style = "distributed" *) reg itc_valid [0:ITC_SIZE-1];
   (* ram_style = "distributed" *) reg [ITC_TAG_WIDTH-1:0] itc_tag [0:ITC_SIZE-1];
   (* ram_style = "distributed" *) reg [31:0] itc_target [0:ITC_SIZE-1];

   // History-correlated component: the same indirect-jump PC can retain a
   // different target for each folded GHR context.  This is aimed at switch
   // jump tables and other multi-target JALR instructions.
   (* ram_style = "distributed" *) reg hist_itc_valid [0:HIST_ITC_SIZE-1];
   (* ram_style = "distributed" *) reg [HIST_ITC_TAG_WIDTH-1:0]
       hist_itc_tag [0:HIST_ITC_SIZE-1];
   (* ram_style = "distributed" *) reg [31:0]
       hist_itc_target [0:HIST_ITC_SIZE-1];

   // Per-PC tournament chooser.  00/01 prefer last-target, 10/11 prefer the
   // history component.  A new call starts weak-last; a new jump starts
   // weak-history, then actual target correctness trains it adaptively.
   (* ram_style = "distributed" *) reg itc_chooser_valid [0:ITC_CHOOSER_SIZE-1];
   (* ram_style = "distributed" *) reg [ITC_CHOOSER_TAG_WIDTH-1:0]
       itc_chooser_tag [0:ITC_CHOOSER_SIZE-1];
   (* ram_style = "distributed" *) reg [1:0]
       itc_chooser [0:ITC_CHOOSER_SIZE-1];

   function [BHT_ADDR_WIDTH-1:0] pc_hash;
        input [(2*BHT_ADDR_WIDTH)-1:0] pc_bits;
        begin
            pc_hash = pc_bits[BHT_ADDR_WIDTH-1:0] ^
                      pc_bits[(2*BHT_ADDR_WIDTH)-1:BHT_ADDR_WIDTH];
        end
   endfunction

   function [HIST_ITC_ADDR_WIDTH-1:0] indirect_pc_hash;
        input [29:0] pc_word;
        integer hash_bit;
        begin
            indirect_pc_hash = {HIST_ITC_ADDR_WIDTH{1'b0}};
            for (hash_bit = 0; hash_bit < 30; hash_bit = hash_bit + 1) begin
                indirect_pc_hash[hash_bit % HIST_ITC_ADDR_WIDTH] =
                    indirect_pc_hash[hash_bit % HIST_ITC_ADDR_WIDTH] ^
                    pc_word[hash_bit];
            end
        end
   endfunction

   function [HIST_ITC_ADDR_WIDTH-1:0] fold_indirect_ghr;
        input [BHT_ADDR_WIDTH-1:0] history;
        integer history_bit;
        begin
            fold_indirect_ghr = {HIST_ITC_ADDR_WIDTH{1'b0}};
            for (history_bit = 0; history_bit < BHT_ADDR_WIDTH;
                 history_bit = history_bit + 1) begin
                fold_indirect_ghr[history_bit % HIST_ITC_ADDR_WIDTH] =
                    fold_indirect_ghr[history_bit % HIST_ITC_ADDR_WIDTH] ^
                    history[history_bit];
            end
        end
   endfunction

   function [HIST_ITC_TAG_WIDTH-1:0] indirect_pc_tag;
        input [29:0] pc_word;
        integer tag_bit;
        begin
            indirect_pc_tag = {HIST_ITC_TAG_WIDTH{1'b0}};
            for (tag_bit = 0; tag_bit < 30; tag_bit = tag_bit + 1) begin
                indirect_pc_tag[tag_bit % HIST_ITC_TAG_WIDTH] =
                    indirect_pc_tag[tag_bit % HIST_ITC_TAG_WIDTH] ^
                    pc_word[tag_bit];
            end
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
    wire [BHT_ADDR_WIDTH-1:0] pred_idx      = pred_pc_idx ^ if_ghr_i;
    wire [BHT_ADDR_WIDTH-1:0] req_pred_idx  = req_pc_idx ^ ghr_r;
   wire [BHT_ADDR_WIDTH-1:0] update_idx    = update_pc_idx ^ update_ghr_i;
    wire [BTB_ADDR_WIDTH-1:0] req_btb_idx = req_pc_i[BTB_ADDR_WIDTH+1:2];
    wire [BTB_ADDR_WIDTH-1:0] update_btb_idx =
        update_pc_word_i[BTB_ADDR_WIDTH-1:0];
    wire [ITC_ADDR_WIDTH-1:0] pred_itc_idx =
        if_pc_i[ITC_ADDR_WIDTH+1:2];
    wire [ITC_ADDR_WIDTH-1:0] req_itc_idx =
        req_pc_i[ITC_ADDR_WIDTH+1:2];
    wire [ITC_ADDR_WIDTH-1:0] update_itc_idx =
        jalr_update_pc_i[ITC_ADDR_WIDTH+1:2];
    wire [HIST_ITC_ADDR_WIDTH-1:0] pred_hist_itc_idx =
        indirect_pc_hash(if_pc_i[31:2]) ^ fold_indirect_ghr(if_ghr_i);
    wire [HIST_ITC_ADDR_WIDTH-1:0] req_hist_itc_idx =
        indirect_pc_hash(req_pc_i[31:2]) ^ fold_indirect_ghr(ghr_r);
    wire [HIST_ITC_ADDR_WIDTH-1:0] update_hist_itc_idx =
        indirect_pc_hash(jalr_update_pc_i[31:2]) ^
        fold_indirect_ghr(jalr_update_ghr_i);
    wire [ITC_CHOOSER_ADDR_WIDTH-1:0] pred_itc_chooser_idx =
        if_pc_i[ITC_CHOOSER_ADDR_WIDTH+1:2];
    wire [ITC_CHOOSER_ADDR_WIDTH-1:0] req_itc_chooser_idx =
        req_pc_i[ITC_CHOOSER_ADDR_WIDTH+1:2];
    wire [ITC_CHOOSER_ADDR_WIDTH-1:0] update_itc_chooser_idx =
        jalr_update_pc_i[ITC_CHOOSER_ADDR_WIDTH+1:2];

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
    wire itc_pred_hit =
        ENABLE_INDIRECT_JALR_PRED &&
        itc_valid[pred_itc_idx] &&
        (itc_tag[pred_itc_idx] == if_pc_i[31:ITC_ADDR_WIDTH+2]);
    wire hist_itc_pred_hit =
        ENABLE_INDIRECT_JALR_PRED &&
        hist_itc_valid[pred_hist_itc_idx] &&
        (hist_itc_tag[pred_hist_itc_idx] == indirect_pc_tag(if_pc_i[31:2]));
    wire itc_chooser_hit =
        itc_chooser_valid[pred_itc_chooser_idx] &&
        (itc_chooser_tag[pred_itc_chooser_idx] ==
         if_pc_i[31:ITC_CHOOSER_ADDR_WIDTH+2]);
    wire itc_chooser_prefers_history =
        itc_chooser_hit ? itc_chooser[pred_itc_chooser_idx][1] : !rd_is_link;
    wire indirect_jalr_use_history =
        hist_itc_pred_hit && (!itc_pred_hit || itc_chooser_prefers_history);
    wire indirect_jalr_pred_valid =
        is_jalr_hint && !ras_pred_pop && (itc_pred_hit || hist_itc_pred_hit);

    // At request time the instruction word is not available.  The full-PC
    // last-target entry therefore acts as an exact non-return-JALR directory.
    // A compressed history tag is allowed to select the target only after
    // that exact directory hit, so an alias can never redirect a normal PC.
    wire req_itc_pred_hit =
        ENABLE_INDIRECT_JALR_PRED &&
        itc_valid[req_itc_idx] &&
        (itc_tag[req_itc_idx] == req_pc_i[31:ITC_ADDR_WIDTH+2]);
    wire req_hist_itc_pred_hit =
        hist_itc_valid[req_hist_itc_idx] &&
        (hist_itc_tag[req_hist_itc_idx] == indirect_pc_tag(req_pc_i[31:2]));
    wire req_itc_chooser_hit =
        itc_chooser_valid[req_itc_chooser_idx] &&
        (itc_chooser_tag[req_itc_chooser_idx] ==
         req_pc_i[31:ITC_CHOOSER_ADDR_WIDTH+2]);
    wire req_itc_chooser_prefers_history =
        req_itc_chooser_hit && itc_chooser[req_itc_chooser_idx][1];
    wire req_indirect_use_history =
        req_itc_pred_hit && req_hist_itc_pred_hit &&
        req_itc_chooser_prefers_history;
    wire req_indirect_pred_valid = req_itc_pred_hit;
    wire [31:0] req_indirect_pred_target_w =
        req_indirect_use_history ? hist_itc_target[req_hist_itc_idx] :
                                   itc_target[req_itc_idx];

    wire branch_bht_pred_taken_w = bht_valid[pred_idx] ? bht[pred_idx][1] : btfnt_taken;
    wire req_branch_bht_pred_taken_w =
        bht_valid[req_pred_idx] ? bht[req_pred_idx][1] :
        (btb_target[req_btb_idx] < req_pc_i);
    wire [31:0] branch_pred_target_w = if_pc_i + b_imm;
    wire [31:0] jal_pred_target_w    = if_pc_i + j_imm;
    wire [31:0] jalr_pred_target_w   = ras[ras_top_idx];
    wire [31:0] indirect_jalr_pred_target_w =
        indirect_jalr_use_history ? hist_itc_target[pred_hist_itc_idx] :
                                    itc_target[pred_itc_idx];

    // Chooser training observes the two candidates before this update edge.
    // Architectural recovery still uses the prediction packet carried to EX;
    // these wires affect chooser quality only, never correctness.
    wire update_itc_hit =
        itc_valid[update_itc_idx] &&
        (itc_tag[update_itc_idx] ==
         jalr_update_pc_i[31:ITC_ADDR_WIDTH+2]);
    wire update_hist_itc_hit =
        hist_itc_valid[update_hist_itc_idx] &&
        (hist_itc_tag[update_hist_itc_idx] ==
         indirect_pc_tag(jalr_update_pc_i[31:2]));
    wire update_itc_chooser_hit =
        itc_chooser_valid[update_itc_chooser_idx] &&
        (itc_chooser_tag[update_itc_chooser_idx] ==
         jalr_update_pc_i[31:ITC_CHOOSER_ADDR_WIDTH+2]);
    wire update_itc_correct =
        update_itc_hit &&
        (itc_target[update_itc_idx] == jalr_update_target_i);
    wire update_hist_itc_correct =
        update_hist_itc_hit &&
        (hist_itc_target[update_hist_itc_idx] == jalr_update_target_i);

    integer i;
    integer j;
    integer k;
    integer m;
    integer n;

    assign pred_ghr_o = if_ghr_i;
    assign req_pred_ghr_o = ghr_r;
    assign req_btb_hit_o = btb_valid[req_btb_idx] &&
                           (btb_tag[req_btb_idx] ==
                            req_pc_i[31:BTB_ADDR_WIDTH+2]);
    assign req_pred_valid_o = req_indirect_pred_valid || req_btb_hit_o;
    assign req_pred_taken_o = req_indirect_pred_valid ? 1'b1 :
                              (req_btb_hit_o && req_branch_bht_pred_taken_w);
    assign req_pred_target_o = req_indirect_pred_valid ?
                               req_indirect_pred_target_w :
                               btb_target[req_btb_idx];
    assign req_pred_type_o = req_indirect_pred_valid ? `BP_PRED_JALR :
                             req_btb_hit_o ? `BP_PRED_BRANCH :
                                             `BP_PRED_NONE;

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
        for (k = 0; k < ITC_SIZE; k = k + 1) begin
            itc_valid[k] = 1'b0;
            itc_tag[k] = {ITC_TAG_WIDTH{1'b0}};
            itc_target[k] = 32'b0;
        end
        for (m = 0; m < HIST_ITC_SIZE; m = m + 1) begin
            hist_itc_valid[m] = 1'b0;
            hist_itc_tag[m] = {HIST_ITC_TAG_WIDTH{1'b0}};
            hist_itc_target[m] = 32'b0;
        end
        for (n = 0; n < ITC_CHOOSER_SIZE; n = n + 1) begin
            itc_chooser_valid[n] = 1'b0;
            itc_chooser_tag[n] = {ITC_CHOOSER_TAG_WIDTH{1'b0}};
            itc_chooser[n] = 2'b01;
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

            if (jalr_update_en_i) begin
                // Both components learn every non-return JALR.  Calls get an
                // immediate last-target hit; jump-table entries accumulate
                // distinct targets under different history contexts.
                itc_valid[update_itc_idx] <= 1'b1;
                itc_tag[update_itc_idx] <=
                    jalr_update_pc_i[31:ITC_ADDR_WIDTH+2];
                itc_target[update_itc_idx] <= jalr_update_target_i;

                hist_itc_valid[update_hist_itc_idx] <= 1'b1;
                hist_itc_tag[update_hist_itc_idx] <=
                    indirect_pc_tag(jalr_update_pc_i[31:2]);
                hist_itc_target[update_hist_itc_idx] <= jalr_update_target_i;

                if (!update_itc_chooser_hit) begin
                    itc_chooser_valid[update_itc_chooser_idx] <= 1'b1;
                    itc_chooser_tag[update_itc_chooser_idx] <=
                        jalr_update_pc_i[31:ITC_CHOOSER_ADDR_WIDTH+2];
                    itc_chooser[update_itc_chooser_idx] <=
                        jalr_update_is_call_i ? 2'b01 : 2'b10;
                end else if (update_itc_correct && !update_hist_itc_correct) begin
                    if (itc_chooser[update_itc_chooser_idx] != 2'b00) begin
                        itc_chooser[update_itc_chooser_idx] <=
                            itc_chooser[update_itc_chooser_idx] - 1'b1;
                    end
                end else if (update_hist_itc_correct && !update_itc_correct) begin
                    if (itc_chooser[update_itc_chooser_idx] != 2'b11) begin
                        itc_chooser[update_itc_chooser_idx] <=
                            itc_chooser[update_itc_chooser_idx] + 1'b1;
                    end
                end
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
        pred_type_o   = `BP_PRED_NONE;

        if (if_valid_i) begin
            case (opcode)
                `INST_TYPE_B: begin
                    pred_taken_o  = branch_bht_pred_taken_w;
                    pred_target_o = branch_pred_target_w;
                    pred_type_o   = `BP_PRED_BRANCH;
                end

                `INST_JAL: begin
                    pred_taken_o  = 1'b1;
                    pred_target_o = jal_pred_target_w;
                    pred_type_o   = `BP_PRED_JAL;
                end

                `INST_JALR: begin
                    pred_taken_o = ras_pred_valid || indirect_jalr_pred_valid;
                    pred_target_o = ras_pred_valid ? jalr_pred_target_w :
                                    indirect_jalr_pred_target_w;
                    pred_type_o = `BP_PRED_JALR;
                end

                default: begin
                    pred_taken_o  = 1'b0;
                    pred_target_o = 32'b0;
                    pred_type_o   = `BP_PRED_NONE;
                end
            endcase
        end
    end

endmodule
