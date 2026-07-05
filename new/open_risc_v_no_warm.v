`timescale 1ns / 1ps
`include "defines.v"

module open_risc_v_no_warm (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] inst_i,
    input  wire [31:0] ram_data_i,
    input  wire [31:0] mmio_data_i,
    output wire [31:0] pc_reg_pc_o,
    output wire        mem_rd_reg_o,
    output wire [31:0] mem_rd_addr_o,
    output wire [3:0]  w_en,
    output wire [31:0] w_addr_i,
    output wire [31:0] w_data_i
);

    localparam [31:0] DRAM_ADDR_START = 32'h8010_0000;
    localparam [31:0] DRAM_ADDR_END   = 32'h8014_0000;

    wire        id_ex_is_branch_w;
    wire        id_is_jalr_w;
    wire        id_ex_is_jalr_w;

    wire rst = rst_n;

    // ------------------------------------------------------------------
    // CTRL / branch redirect
    // ------------------------------------------------------------------
    wire [31:0] ctrl_jump_addr_o;
    wire        ctrl_jump_en_o;
    wire        ctrl_kill_ex_o;
    wire        ctrl_flush_ifid_o;
    wire        ctrl_flush_idex_o;

    // ------------------------------------------------------------------
    // Branch predictor / fetch side
    // ------------------------------------------------------------------
    wire        bp_pred_taken_o;
    wire        bp_pred_taken_accepted_o;
    wire [31:0] bp_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_pred_ghr_o;
    wire        bp_pred_flush_o;

    reg         bp_pred_flush_d1_r;
    reg         bp_replay_flush_d1_r;

    wire [31:0] pc_jump_addr_o;
    wire        pc_jump_en_o;

    reg  [31:0] bp_fetch_pc_r;
    reg         bp_fetch_valid_r;
    reg         bp_fetch_valid_pending_r;

    // ------------------------------------------------------------------
    // HDU
    // ------------------------------------------------------------------
    wire        hdu_hold_flag_o;
    wire        hdu_flush_flag_o;

    // ------------------------------------------------------------------
    // IF/ID
    // ------------------------------------------------------------------
    wire [31:0] if_id_inst_addr_o;
    wire [31:0] if_id_inst_o;
    wire        if_id_pred_taken_o;
    wire [31:0] if_id_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] if_id_pred_ghr_o;

    wire        if_id_load_valid_o;
    wire        if_id_load_pred_taken_o;
    wire [31:0] if_id_load_pred_target_o;
    wire        if_id_replaying_o;
    wire        if_id_replay_pending_o;

    // ------------------------------------------------------------------
    // ID
    // ------------------------------------------------------------------
    wire [4:0]  id_rs1_addr_o;
    wire [4:0]  id_rs2_addr_o;
    wire [31:0] id_inst_o;
    wire [31:0] id_inst_addr_o;
    wire [31:0] id_op1_o;
    wire [31:0] id_op2_o;
    wire [31:0] id_cmp_op2_o;
    wire [31:0] id_store_data_o;
    wire [4:0]  id_rd_addr_o;
    wire        id_reg_wen;
    wire [31:0] id_base_addr_o;
    wire [31:0] id_branch_offset_o;
    wire [31:0] id_mem_offset_o;
    wire [31:0] id_jump_offset_o;
    wire        id_use_rs1_o;
    wire        id_use_rs2_o;
    wire        id_is_branch_o;
    wire        id_use_base_addr_o;
    wire        data_read_en;

    // ------------------------------------------------------------------
    // Regfile / WB
    // ------------------------------------------------------------------
    wire [31:0] regs_reg1_rdata_o;
    wire [31:0] regs_reg2_rdata_o;
    wire [4:0]  wb_rd_addr_o;
    wire [31:0] wb_rd_data_o;
    wire        wb_rd_wen_o;

    // ------------------------------------------------------------------
    // ID/EX
    // ------------------------------------------------------------------
    wire [31:0] id_ex_inst_o;
    wire [31:0] id_ex_inst_addr_o;
    wire [31:0] id_ex_op1_o;
    wire [31:0] id_ex_op2_o;
    wire [31:0] id_ex_cmp_op2_o;
    wire [31:0] id_ex_store_data_o;
    wire        id_ex_pred_taken_o;
    wire [31:0] id_ex_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] id_ex_pred_ghr_o;
    wire [4:0]  id_ex_rs1_addr_o;
    wire [4:0]  id_ex_rs2_addr_o;
    wire        id_ex_use_rs1_o;
    wire        id_ex_use_rs2_o;
    wire        id_ex_use_base_addr_o;
    wire [4:0]  id_ex_rd_addr_o;
    wire        id_ex_reg_wen;
    wire [31:0] id_ex_base_addr_o;
    wire [31:0] id_ex_branch_offset_o;
    wire [31:0] id_ex_mem_offset_o;
    wire [31:0] id_ex_jump_offset_o;

    // ------------------------------------------------------------------
    // EX
    // ------------------------------------------------------------------
    wire [4:0]  ex_rd_addr_o;
    wire [31:0] ex_rd_data_o;
    wire        ex_rd_wen_o;
    wire [3:0]  ex_wd_reg_o;
    wire [31:0] ex_wd_addr_o;
    wire [31:0] ex_wd_data_o;
    wire        ex_is_load_o;
    wire [31:0] ex_inst_o;
    wire [31:0] ex_jump_addr_o;
    wire        ex_jump_en_o;
    wire [31:0] ex_rd_mem_addr_o;
    wire        ex_load_hits_dram_o;

    wire        bp_update_en_o;
    wire [31:0] bp_update_pc_o;
    wire [`BP_GHR_WIDTH-1:0] bp_update_ghr_o;
    wire        bp_ras_push_en_o;
    wire        bp_ras_pop_en_o;
    wire [31:0] bp_ras_push_addr_o;
    wire        bp_actual_taken_o;

    wire        ex_rv32m_busy_o;
    wire        ex_rv32m_done_o;

    // ------------------------------------------------------------------
    // Pipeline branch predictor update buses
    // ------------------------------------------------------------------
    wire        ex_mem_bp_update_en_o;
    wire [31:0] ex_mem_bp_update_pc_o;
    wire [`BP_GHR_WIDTH-1:0] ex_mem_bp_update_ghr_o;
    wire        ex_mem_bp_ras_push_en_o;
    wire        ex_mem_bp_ras_pop_en_o;
    wire [31:0] ex_mem_bp_ras_push_addr_o;
    wire        ex_mem_bp_actual_taken_o;

    wire        mem1_mem2_bp_update_en_o;
    wire [31:0] mem1_mem2_bp_update_pc_o;
    wire [`BP_GHR_WIDTH-1:0] mem1_mem2_bp_update_ghr_o;
    wire        mem1_mem2_bp_ras_push_en_o;
    wire        mem1_mem2_bp_ras_pop_en_o;
    wire [31:0] mem1_mem2_bp_ras_push_addr_o;
    wire        mem1_mem2_bp_actual_taken_o;

    wire        mem2_align_bp_update_en_o;
    wire [31:0] mem2_align_bp_update_pc_o;
    wire [`BP_GHR_WIDTH-1:0] mem2_align_bp_update_ghr_o;
    wire        mem2_align_bp_ras_push_en_o;
    wire        mem2_align_bp_ras_pop_en_o;
    wire [31:0] mem2_align_bp_ras_push_addr_o;
    wire        mem2_align_bp_actual_taken_o;

    wire        mem_wb_bp_update_en_o;
    wire [31:0] mem_wb_bp_update_pc_o;
    wire [`BP_GHR_WIDTH-1:0] mem_wb_bp_update_ghr_o;
    wire        mem_wb_bp_ras_push_en_o;
    wire        mem_wb_bp_ras_pop_en_o;
    wire [31:0] mem_wb_bp_ras_push_addr_o;
    wire        mem_wb_bp_actual_taken_o;

    // ------------------------------------------------------------------
    // Forwarding
    // ------------------------------------------------------------------
    wire [31:0] fwd_op1_o;
    wire [31:0] fwd_op2_o;
    wire [31:0] fwd_cmp_op2_o;
    wire [31:0] fwd_store_data_o;
    wire [31:0] fwd_base_addr_o;

    // ------------------------------------------------------------------
    // EX/MEM1
    // ------------------------------------------------------------------
    wire [4:0]  ex_mem_pipe_rd_addr_o;
    wire [31:0] ex_mem_rd_data_o;
    wire        ex_mem_rd_wen_o;
    wire [3:0]  ex_mem_wd_reg_o;
    wire [31:0] ex_mem_wd_addr_o;
    wire [31:0] ex_mem_wd_data_o;
    wire        ex_mem_is_load_o;
    wire        ex_mem_load_hits_dram_o;
    wire [31:0] ex_mem_inst_o;
    wire [31:0] ex_mem_mem_rd_addr_o;

    // ------------------------------------------------------------------
    // MEM1
    // ------------------------------------------------------------------
    wire [4:0]  mem_out_rd_addr_o;
    wire [31:0] mem_out_rd_data_o;
    wire        mem_out_rd_wen_o;
    wire [31:0] mem_inst_o;
    wire [31:0] mem_out_mem_rd_addr_o;
    wire        mem_out_is_load_o;

    // ------------------------------------------------------------------
    // MEM1/MEM2
    // ------------------------------------------------------------------
    wire [4:0]  mem1_mem2_rd_addr_o;
    wire [31:0] mem1_mem2_rd_data_o;
    wire        mem1_mem2_rd_wen_o;
    wire [31:0] mem1_mem2_inst_o;
    wire [31:0] mem1_mem2_mem_rd_addr_o;
    wire        mem1_mem2_is_load_o;
    wire        mem1_mem2_load_hits_dram_o;

    // ------------------------------------------------------------------
    // MEM2 align
    // ------------------------------------------------------------------
    wire [4:0]  mem2_align_rd_addr_o;
    wire [31:0] mem2_align_rd_data_o;
    wire        mem2_align_rd_wen_o;
    wire [31:0] mem2_align_inst_o;
    wire [31:0] mem2_align_mem_rd_addr_o;
    wire        mem2_align_is_load_o;
    wire        mem2_align_load_hits_dram_o;

    // ------------------------------------------------------------------
    // MEM2
    // ------------------------------------------------------------------
    wire [31:0] mem2_inst_o;
    wire [4:0]  mem2_rd_addr_o;
    wire [31:0] mem2_rd_data_o;
    wire        mem2_rd_wen_o;
    wire        mem2a_is_slow_load_o;
    wire        mem2_is_slow_load_o;

    // ------------------------------------------------------------------
    // MEM/WB
    // ------------------------------------------------------------------
    wire [4:0]  mem_wb_rd_addr_o;
    wire [31:0] mem_wb_rd_data_o;
    wire        mem_wb_rd_wen_o;
    wire [31:0] mem_wb_mem_rd_addr_o;
    wire        mem_wb_is_slow_load_o;
    wire [31:0] mem_wb_inst_o;

    assign mem_rd_reg_o  = ex_mem_is_load_o;
    assign mem_rd_addr_o = ex_mem_mem_rd_addr_o;

    // ==================================================================
    // Fetch / IF-ID / branch predictor accept control
    // ==================================================================

    reg [1:0] fetch_warmup_r;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            fetch_warmup_r <= 2'd0;
        end else if (fetch_warmup_r != 2'd2) begin
            fetch_warmup_r <= fetch_warmup_r + 2'd1;
        end
    end

    wire fetch_ready = 1'b1;

    wire bp_if_valid =
        bp_fetch_valid_r & ~bp_pred_flush_d1_r;

    // A synchronous fetch package can coincide with the package already held
    // by IF/ID, especially after a predicted redirect. Suppress only exact
    // same-PC duplicates; unrelated sequential fetches must still pass.
    wire ifid_duplicate =
        if_id_load_valid_o && (bp_fetch_pc_r == if_id_inst_addr_o);

    wire ifid_fetch_valid =
        fetch_ready &
        bp_if_valid &
        ~ctrl_flush_ifid_o &
        ~bp_pred_flush_d1_r &
        ~ifid_duplicate;

    wire ifid_direct_fire =
        ifid_fetch_valid &
        ~hdu_hold_flag_o &
        ~if_id_replay_pending_o;

    // ifid_fetch_valid already suppresses exact replay duplicates.
    // 鏅€?fetch redirect锛氫繚鎸佸師閫昏緫锛屼笉瑕佸姞 ~if_id_replaying_o
    wire bp_fetch_redirect =
        ifid_direct_fire &
        bp_pred_taken_o;

    // replay 鍑烘潵鐨?IF/ID 鍖呭鏋滈娴?taken锛屽垯鏈媿 redirect
    wire bp_replay_redirect =
        if_id_replaying_o &
        if_id_pred_taken_o;

    assign bp_pred_taken_accepted_o =
        bp_fetch_redirect | bp_replay_redirect;

    assign pc_jump_en_o =
        ctrl_jump_en_o | bp_pred_taken_accepted_o;

    // 鍙敼杩欓噷锛氬綋 fetch redirect 鍜?replay redirect 鍚屾媿鍙戠敓鏃讹紝
    // 鍦板潃浼樺厛閫?replay 鐨?if_id_pred_target_o
    assign pc_jump_addr_o =
        ctrl_jump_en_o     ? ctrl_jump_addr_o :
        bp_replay_redirect ? if_id_pred_target_o :
        bp_fetch_redirect  ? bp_pred_target_o :
                              32'b0;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            bp_fetch_pc_r            <= 32'h8000_0000;
            bp_fetch_valid_r         <= 1'b0;
            bp_fetch_valid_pending_r <= 1'b0;
            bp_pred_flush_d1_r       <= 1'b0;
            bp_replay_flush_d1_r     <= 1'b0;
        end else begin
            bp_fetch_pc_r            <= pc_reg_pc_o;
            bp_fetch_valid_r         <= bp_fetch_valid_pending_r;
            bp_fetch_valid_pending_r <= fetch_ready;

            // 鎵€鏈夐娴?redirect 閮戒細璁╁悓姝?IROM 涓嬩竴鎷嶄骇鐢?ghost fetch銆?
            bp_pred_flush_d1_r       <= bp_pred_taken_accepted_o;

            // replay redirect 涓撶敤淇濇姢銆?
            bp_replay_flush_d1_r     <= bp_replay_redirect;
        end
    end

    wire frontend_flush_ifid =
        ctrl_flush_ifid_o |
        ex_jump_en_o |
        bp_replay_flush_d1_r;

    wire frontend_flush_idex =
        ctrl_flush_idex_o |
        bp_replay_flush_d1_r;

    wire bp_predictor_flush =
        ex_jump_en_o |
        ctrl_flush_ifid_o |
        bp_pred_flush_d1_r |
        bp_replay_flush_d1_r;

    // ==================================================================
    // Branch predictor
    // ==================================================================
    branch_predictor branch_predictor_inst (
        .clk             (clk),
        .rst             (rst),
        .if_valid_i      (bp_if_valid),
        .if_inst_i       (inst_i),
        .if_pc_i         (bp_fetch_pc_r),
        .hold_flag_i     (hdu_hold_flag_o),
        .flush_flag_i    (bp_predictor_flush),
        .pred_taken_o    (bp_pred_taken_o),
        .pred_target_o   (bp_pred_target_o),
        .pred_ghr_o      (bp_pred_ghr_o),
        .pred_flush_o    (bp_pred_flush_o),
        .update_en_i     (mem_wb_bp_update_en_o),
        .update_pc_i     (mem_wb_bp_update_pc_o),
        .update_ghr_i    (mem_wb_bp_update_ghr_o),
        .ras_push_en_i   (bp_ras_push_en_o),
        .ras_pop_en_i    (bp_ras_pop_en_o),
        .ras_push_addr_i (bp_ras_push_addr_o),
        .actual_taken_i  (mem_wb_bp_actual_taken_o)
    );

    // ==================================================================
    // PC
    // ==================================================================
    wire pc_front_hold =
        hdu_hold_flag_o |
        ~bp_fetch_valid_r;

    pc_reg pc_reg_inst (
        .clk         (clk),
        .rst         (rst),
        .jump_en     (pc_jump_en_o),
        .jump_addr_i (pc_jump_addr_o),
        .hold_flag_i (pc_front_hold),
        .pc_o        (pc_reg_pc_o)
    );

    // ==================================================================
    // IF/ID
    // ==================================================================
    if_id if_id_inst (
        .clk                (clk),
        .rst                (rst),
        .load_valid_i       (ifid_fetch_valid),
        .inst_i             (inst_i),
        .inst_addr_i        (bp_fetch_pc_r),
        .pred_taken_i       (bp_pred_taken_o),
        .pred_target_i      (bp_pred_target_o),
        .pred_ghr_i         (bp_pred_ghr_o),
        .hold_flag_i        (hdu_hold_flag_o),
        .flush_flag_i       (frontend_flush_ifid),
        .inst_addr_o        (if_id_inst_addr_o),
        .pred_taken_o       (if_id_pred_taken_o),
        .pred_target_o      (if_id_pred_target_o),
        .pred_ghr_o         (if_id_pred_ghr_o),
        .inst_o             (if_id_inst_o),
        .load_valid_o       (if_id_load_valid_o),
        .load_pred_taken_o  (if_id_load_pred_taken_o),
        .load_pred_target_o (if_id_load_pred_target_o),
        .replaying_o        (if_id_replaying_o),
        .replay_pending_o   (if_id_replay_pending_o)
    );

    // ==================================================================
    // Regfile
    // ==================================================================
    regs regs_inst (
        .clk          (clk),
        .reg1_raddr_i (id_rs1_addr_o),
        .reg2_raddr_i (id_rs2_addr_o),
        .reg1_rdata_o (regs_reg1_rdata_o),
        .reg2_rdata_o (regs_reg2_rdata_o),
        .reg_wen      (wb_rd_wen_o),
        .reg_waddr_i  (wb_rd_addr_o),
        .reg_wdata_i  (wb_rd_data_o)
    );

    // ==================================================================
    // ID
    // ==================================================================
    id id_inst (
        .inst_i          (if_id_inst_o),
        .inst_addr_i     (if_id_inst_addr_o),
        .rs1_data_i      (regs_reg1_rdata_o),
        .rs2_data_i      (regs_reg2_rdata_o),
        .rs1_addr_o      (id_rs1_addr_o),
        .rs2_addr_o      (id_rs2_addr_o),
        .inst_o          (id_inst_o),
        .inst_addr_o     (id_inst_addr_o),
        .op1_o           (id_op1_o),
        .op2_o           (id_op2_o),
        .cmp_op2_o       (id_cmp_op2_o),
        .store_data_o    (id_store_data_o),
        .rd_addr_o       (id_rd_addr_o),
        .reg_wen         (id_reg_wen),
        .base_addr_o     (id_base_addr_o),
        .branch_offset_o (id_branch_offset_o),
        .mem_offset_o    (id_mem_offset_o),
        .jump_offset_o   (id_jump_offset_o),
        .mem_rd_reg_o    (data_read_en),
        .is_branch_o     (id_is_branch_o),
        .use_rs1_o       (id_use_rs1_o),
        .use_rs2_o       (id_use_rs2_o),
        .use_base_addr_o (id_use_base_addr_o)
    );

    // ==================================================================
    // ID/EX
    // ==================================================================
    id_ex id_ex_inst (
        .clk             (clk),
        .rst             (rst),
        .hold_flag_i     (hdu_hold_flag_o),
        .flush_flag_i    (hdu_flush_flag_o | frontend_flush_idex),
        .inst_i          (id_inst_o),
        .inst_addr_i     (id_inst_addr_o),
        .op1_i           (id_op1_o),
        .op2_i           (id_op2_o),
        .cmp_op2_i       (id_cmp_op2_o),
        .store_data_i    (id_store_data_o),
        .pred_taken_i    (if_id_pred_taken_o),
        .pred_target_i   (if_id_pred_target_o),
        .pred_ghr_i      (if_id_pred_ghr_o),
        .rs1_addr_i      (id_rs1_addr_o),
        .rs2_addr_i      (id_rs2_addr_o),
        .use_rs1_i       (id_use_rs1_o),
        .use_rs2_i       (id_use_rs2_o),
        .use_base_addr_i (id_use_base_addr_o),
        .rd_addr_i       (id_rd_addr_o),
        .reg_wen_i       (id_reg_wen),
        .base_addr_i     (id_base_addr_o),
        .branch_offset_i (id_branch_offset_o),
        .mem_offset_i    (id_mem_offset_o),
        .jump_offset_i   (id_jump_offset_o),
        .inst_o          (id_ex_inst_o),
        .inst_addr_o     (id_ex_inst_addr_o),
        .op1_o           (id_ex_op1_o),
        .op2_o           (id_ex_op2_o),
        .cmp_op2_o       (id_ex_cmp_op2_o),
        .store_data_o    (id_ex_store_data_o),
        .pred_taken_o    (id_ex_pred_taken_o),
        .pred_target_o   (id_ex_pred_target_o),
        .pred_ghr_o      (id_ex_pred_ghr_o),
        .rs1_addr_o      (id_ex_rs1_addr_o),
        .rs2_addr_o      (id_ex_rs2_addr_o),
        .use_rs1_o       (id_ex_use_rs1_o),
        .use_rs2_o       (id_ex_use_rs2_o),
        .use_base_addr_o (id_ex_use_base_addr_o),
        .rd_addr_o       (id_ex_rd_addr_o),
        .reg_wen_o       (id_ex_reg_wen),
        .base_addr_o     (id_ex_base_addr_o),
        .branch_offset_o (id_ex_branch_offset_o),
        .mem_offset_o    (id_ex_mem_offset_o),
        .jump_offset_o   (id_ex_jump_offset_o)
    );

    (* max_fanout = 8 *)assign mem2a_is_slow_load_o = mem2_align_is_load_o;
    (* max_fanout = 8 *)assign mem2_is_slow_load_o  = mem2_align_is_load_o &&
                                  ~mem2_align_load_hits_dram_o;

    (* max_fanout = 8 *)assign id_is_jalr_w         = (id_inst_o[6:0] == `INST_JALR);
    (* max_fanout = 8 *)assign id_ex_is_branch_w    = (id_ex_inst_o[6:0] == `INST_TYPE_B);
    (* max_fanout = 8 *)assign id_ex_is_jalr_w      = (id_ex_inst_o[6:0] == `INST_JALR);

    // ==================================================================
    // Forwarding
    // ==================================================================
    forwarding forwarding_inst (
        .id_ex_op1_i              (id_ex_op1_o),
        .id_ex_op2_i              (id_ex_op2_o),
        .id_ex_cmp_op2_i          (id_ex_cmp_op2_o),
        .id_ex_store_data_i       (id_ex_store_data_o),
        .id_ex_base_addr_i        (id_ex_base_addr_o),
        .id_ex_rs1_addr_i         (id_ex_rs1_addr_o),
        .id_ex_rs2_addr_i         (id_ex_rs2_addr_o),
        .id_ex_is_branch_i        (id_ex_is_branch_w),
        .id_ex_is_jalr_i          (id_ex_is_jalr_w),
        .id_ex_use_rs1_i          (id_ex_use_rs1_o),
        .id_ex_use_rs2_i          (id_ex_use_rs2_o),
        .id_ex_use_base_addr_i    (id_ex_use_base_addr_o),
        .ex_mem_rd_addr_i         (ex_mem_pipe_rd_addr_o),
        .ex_mem_rd_data_i         (ex_mem_rd_data_o),
        .ex_mem_rd_wen_i          (ex_mem_rd_wen_o),
        .ex_mem_is_load_i         (ex_mem_is_load_o),
        .mem1_mem2_rd_addr_i      (mem1_mem2_rd_addr_o),
        .mem1_mem2_rd_data_i      (mem1_mem2_rd_data_o),
        .mem1_mem2_rd_wen_i       (mem1_mem2_rd_wen_o),
        .mem1_mem2_is_load_i      (mem1_mem2_is_load_o),
        .mem2a_rd_addr_i          (mem2_align_rd_addr_o),
        .mem2a_rd_data_i          (mem2_align_rd_data_o),
        .mem2a_rd_wen_i           (mem2_align_rd_wen_o),
        .mem2a_is_load_i          (mem2_align_is_load_o),
        .mem2_rd_addr_i           (mem2_rd_addr_o),
        .mem2_rd_data_i           (mem2_rd_data_o),
        .mem2_rd_wen_i            (mem2_rd_wen_o),
        .mem2_is_slow_load_i      (mem2_is_slow_load_o),
        .mem_wb_rd_addr_i         (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i         (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i          (mem_wb_rd_wen_o),
        .mem_wb_is_slow_load_i    (mem_wb_is_slow_load_o),
        .fwd_op1_o                (fwd_op1_o),
        .fwd_op2_o                (fwd_op2_o),
        .fwd_cmp_op2_o            (fwd_cmp_op2_o),
        .fwd_store_data_o         (fwd_store_data_o),
        .fwd_base_addr_o          (fwd_base_addr_o)
    );

    // ==================================================================
    // HDU
    // ==================================================================
    Hazard_detection_unit hdu_inst (
        .id_rs1_addr_i        (id_rs1_addr_o),
        .id_rs2_addr_i        (id_rs2_addr_o),
        .id_is_branch_i       (id_is_branch_o),
        .id_is_jalr_i         (id_is_jalr_w),
        .id_use_rs1_i         (id_use_rs1_o),
        .id_use_rs2_i         (id_use_rs2_o),
        .ex_inst_i            (id_ex_inst_o),
        .mem1_inst_i          (mem_inst_o),
        .mem1_mem2_inst_i     (mem1_mem2_inst_o),
        .mem2a_inst_i         (mem2_align_inst_o),
        .mem2_inst_i          (mem2_inst_o),
        .mem_wb_inst_i        (mem_wb_inst_o),
        .mem2a_is_slow_load_i (mem2a_is_slow_load_o),
        .mem2_is_slow_load_i  (mem2_is_slow_load_o),
        .ex_busy_i            (ex_rv32m_busy_o),
        .ex_done_i            (ex_rv32m_done_o),
        .branch_ex_stall_o    (),
        .hold_flag_o          (hdu_hold_flag_o),
        .flush_flag_o         (hdu_flush_flag_o)
    );

    // ==================================================================
    // EX
    // ==================================================================
    ex ex_inst (
        .clk                 (clk),
        .rst                 (rst),
        .inst_i              (id_ex_inst_o),
        .inst_addr_i         (id_ex_inst_addr_o),
        .raw_op1_i           (id_ex_op1_o),
        .fwd_op1_i           (fwd_op1_o),
        .fwd_op2_i           (fwd_op2_o),
        .raw_cmp_op2_i       (id_ex_cmp_op2_o),
        .fwd_cmp_op2_i       (fwd_cmp_op2_o),
        .store_data_i        (fwd_store_data_o),
        .pred_taken_i        (id_ex_pred_taken_o),
        .pred_target_i       (id_ex_pred_target_o),
        .pred_ghr_i          (id_ex_pred_ghr_o),
        .rd_addr_i           (id_ex_rd_addr_o),
        .rd_wen_i            (id_ex_reg_wen),
        .kill_i              (ctrl_kill_ex_o),
        .raw_base_i          (id_ex_base_addr_o),
        .fwd_base_i          (fwd_base_addr_o),
        .branch_offset_i     (id_ex_branch_offset_o),
        .mem_offset_i        (id_ex_mem_offset_o),
        .jump_offset_i       (id_ex_jump_offset_o),
        .rd_addr_o           (ex_rd_addr_o),
        .rd_wen_o            (ex_rd_wen_o),
        .rd_data_o           (ex_rd_data_o),
        .jump_addr_o         (ex_jump_addr_o),
        .jump_en_o           (ex_jump_en_o),
        .mem_wd_reg_o        (ex_wd_reg_o),
        .mem_wd_addr_o       (ex_wd_addr_o),
        .mem_wd_data_o       (ex_wd_data_o),
        .mem_rd_addr_o       (ex_rd_mem_addr_o),
        .is_load_o           (ex_is_load_o),
        .load_hits_dram_o    (ex_load_hits_dram_o),
        .inst_o              (ex_inst_o),
        .bp_update_en_o      (bp_update_en_o),
        .bp_update_pc_o      (bp_update_pc_o),
        .bp_update_ghr_o     (bp_update_ghr_o),
        .bp_ras_push_en_o    (bp_ras_push_en_o),
        .bp_ras_pop_en_o     (bp_ras_pop_en_o),
        .bp_ras_push_addr_o  (bp_ras_push_addr_o),
        .bp_actual_taken_o   (bp_actual_taken_o),
        .rv32m_busy_o        (ex_rv32m_busy_o),
        .rv32m_done_o        (ex_rv32m_done_o)
    );

    // ==================================================================
    // CTRL
    // ==================================================================
    ctrl ctrl_inst (
        .clk          (clk),
        .rst          (rst),
        .jump_addr_i  (ex_jump_addr_o),
        .jump_en_i    (ex_jump_en_o),
        .jump_en_o    (ctrl_jump_en_o),
        .jump_addr_o  (ctrl_jump_addr_o),
        .kill_ex_o    (ctrl_kill_ex_o),
        .flush_ifid_o (ctrl_flush_ifid_o),
        .flush_idex_o (ctrl_flush_idex_o),
        .flush_flag_o ()
    );

    // ==================================================================
    // EX/MEM1
    // ==================================================================
    ex_mem1 ex_mem_inst (
        .clk               (clk),
        .rst               (rst),
        .inst_i            (ex_inst_o),
        .rd_addr_i         (ex_rd_addr_o),
        .rd_data_i         (ex_rd_data_o),
        .rd_wen_i          (ex_rd_wen_o),
        .mem_wd_reg_i      (ex_wd_reg_o),
        .mem_wd_addr_i     (ex_wd_addr_o),
        .mem_wd_data_i     (ex_wd_data_o),
        .mem_rd_addr_i     (ex_rd_mem_addr_o),
        .is_load_i         (ex_is_load_o),
        .load_hits_dram_i  (ex_load_hits_dram_o),
        .bp_update_en_i    (bp_update_en_o),
        .bp_update_pc_i    (bp_update_pc_o),
        .bp_update_ghr_i   (bp_update_ghr_o),
        .bp_ras_push_en_i  (bp_ras_push_en_o),
        .bp_ras_pop_en_i   (bp_ras_pop_en_o),
        .bp_ras_push_addr_i(bp_ras_push_addr_o),
        .bp_actual_taken_i (bp_actual_taken_o),
        .rd_addr_o         (ex_mem_pipe_rd_addr_o),
        .rd_data_o         (ex_mem_rd_data_o),
        .rd_wen_o          (ex_mem_rd_wen_o),
        .mem_wd_reg_o      (ex_mem_wd_reg_o),
        .mem_wd_addr_o     (ex_mem_wd_addr_o),
        .mem_wd_data_o     (ex_mem_wd_data_o),
        .mem_rd_addr_o     (ex_mem_mem_rd_addr_o),
        .is_load_o         (ex_mem_is_load_o),
        .load_hits_dram_o  (ex_mem_load_hits_dram_o),
        .bp_update_en_o    (ex_mem_bp_update_en_o),
        .bp_update_pc_o    (ex_mem_bp_update_pc_o),
        .bp_update_ghr_o   (ex_mem_bp_update_ghr_o),
        .bp_ras_push_en_o  (ex_mem_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (ex_mem_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(ex_mem_bp_ras_push_addr_o),
        .bp_actual_taken_o (ex_mem_bp_actual_taken_o),
        .inst_o            (ex_mem_inst_o)
    );

    // ==================================================================
    // MEM1
    // ==================================================================
    mem1 mem_inst (
        .inst_i        (ex_mem_inst_o),
        .rd_addr_i     (ex_mem_pipe_rd_addr_o),
        .rd_data_i     (ex_mem_rd_data_o),
        .rd_wen_i      (ex_mem_rd_wen_o),
        .mem_rd_addr_i (ex_mem_mem_rd_addr_o),
        .mem_wd_reg_i  (ex_mem_wd_reg_o),
        .mem_wd_addr_i (ex_mem_wd_addr_o),
        .mem_wd_data_i (ex_mem_wd_data_o),
        .is_load_i     (ex_mem_is_load_o),
        .rd_addr_o     (mem_out_rd_addr_o),
        .rd_data_o     (mem_out_rd_data_o),
        .rd_wen_o      (mem_out_rd_wen_o),
        .mem_rd_addr_o (mem_out_mem_rd_addr_o),
        .mem_wd_reg_o  (w_en),
        .mem_wd_addr_o (w_addr_i),
        .mem_wd_data_o (w_data_i),
        .inst_o        (mem_inst_o),
        .is_load_o     (mem_out_is_load_o)
    );

    // ==================================================================
    // MEM1/MEM2
    // ==================================================================
    mem1_mem2 mem1_mem2_inst (
        .clk               (clk),
        .rst               (rst),
        .inst_i            (mem_inst_o),
        .rd_addr_i         (mem_out_rd_addr_o),
        .rd_data_i         (mem_out_rd_data_o),
        .rd_wen_i          (mem_out_rd_wen_o),
        .mem_rd_addr_i     (mem_out_mem_rd_addr_o),
        .is_load_i         (mem_out_is_load_o),
        .load_hits_dram_i  (ex_mem_load_hits_dram_o),
        .bp_update_en_i    (ex_mem_bp_update_en_o),
        .bp_update_pc_i    (ex_mem_bp_update_pc_o),
        .bp_update_ghr_i   (ex_mem_bp_update_ghr_o),
        .bp_ras_push_en_i  (ex_mem_bp_ras_push_en_o),
        .bp_ras_pop_en_i   (ex_mem_bp_ras_pop_en_o),
        .bp_ras_push_addr_i(ex_mem_bp_ras_push_addr_o),
        .bp_actual_taken_i (ex_mem_bp_actual_taken_o),
        .rd_addr_o         (mem1_mem2_rd_addr_o),
        .rd_data_o         (mem1_mem2_rd_data_o),
        .rd_wen_o          (mem1_mem2_rd_wen_o),
        .mem_rd_addr_o     (mem1_mem2_mem_rd_addr_o),
        .is_load_o         (mem1_mem2_is_load_o),
        .load_hits_dram_o  (mem1_mem2_load_hits_dram_o),
        .bp_update_en_o    (mem1_mem2_bp_update_en_o),
        .bp_update_pc_o    (mem1_mem2_bp_update_pc_o),
        .bp_update_ghr_o   (mem1_mem2_bp_update_ghr_o),
        .bp_ras_push_en_o  (mem1_mem2_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (mem1_mem2_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(mem1_mem2_bp_ras_push_addr_o),
        .bp_actual_taken_o (mem1_mem2_bp_actual_taken_o),
        .inst_o            (mem1_mem2_inst_o)
    );

    // ==================================================================
    // MEM2 align
    // ==================================================================
    mem1_mem2 mem2_align_inst (
        .clk               (clk),
        .rst               (rst),
        .inst_i            (mem1_mem2_inst_o),
        .rd_addr_i         (mem1_mem2_rd_addr_o),
        .rd_data_i         (mem1_mem2_rd_data_o),
        .rd_wen_i          (mem1_mem2_rd_wen_o),
        .mem_rd_addr_i     (mem1_mem2_mem_rd_addr_o),
        .is_load_i         (mem1_mem2_is_load_o),
        .load_hits_dram_i  (mem1_mem2_load_hits_dram_o),
        .bp_update_en_i    (mem1_mem2_bp_update_en_o),
        .bp_update_pc_i    (mem1_mem2_bp_update_pc_o),
        .bp_update_ghr_i   (mem1_mem2_bp_update_ghr_o),
        .bp_ras_push_en_i  (mem1_mem2_bp_ras_push_en_o),
        .bp_ras_pop_en_i   (mem1_mem2_bp_ras_pop_en_o),
        .bp_ras_push_addr_i(mem1_mem2_bp_ras_push_addr_o),
        .bp_actual_taken_i (mem1_mem2_bp_actual_taken_o),
        .rd_addr_o         (mem2_align_rd_addr_o),
        .rd_data_o         (mem2_align_rd_data_o),
        .rd_wen_o          (mem2_align_rd_wen_o),
        .mem_rd_addr_o     (mem2_align_mem_rd_addr_o),
        .is_load_o         (mem2_align_is_load_o),
        .load_hits_dram_o  (mem2_align_load_hits_dram_o),
        .bp_update_en_o    (mem2_align_bp_update_en_o),
        .bp_update_pc_o    (mem2_align_bp_update_pc_o),
        .bp_update_ghr_o   (mem2_align_bp_update_ghr_o),
        .bp_ras_push_en_o  (mem2_align_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (mem2_align_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(mem2_align_bp_ras_push_addr_o),
        .bp_actual_taken_o (mem2_align_bp_actual_taken_o),
        .inst_o            (mem2_align_inst_o)
    );

    // ==================================================================
    // MEM2
    // ==================================================================
    mem2 mem2_inst (
        .inst_i        (mem2_align_inst_o),
        .rd_addr_i     (mem2_align_rd_addr_o),
        .rd_data_i     (mem2_align_rd_data_o),
        .rd_wen_i      (mem2_align_rd_wen_o),
        .mem_rd_addr_i (mem2_align_mem_rd_addr_o),
        .is_load_i     (mem2_align_is_load_o),
        .mem_rd_data_i (ram_data_i),
        .rd_addr_o     (mem2_rd_addr_o),
        .rd_data_o     (mem2_rd_data_o),
        .rd_wen_o      (mem2_rd_wen_o),
        .inst_o        (mem2_inst_o)
    );

    // ==================================================================
    // MEM2/WB
    // ==================================================================
    mem2_wb mem_wb_inst (
        .clk               (clk),
        .rst               (rst),
        .inst_i            (mem2_inst_o),
        .rd_addr_i         (mem2_rd_addr_o),
        .rd_data_i         (mem2_rd_data_o),
        .rd_wen_i          (mem2_rd_wen_o),
        .mem_rd_addr_i     (mem2_align_mem_rd_addr_o),
        .is_slow_load_i    (mem2_is_slow_load_o),
        .bp_update_en_i    (mem2_align_bp_update_en_o),
        .bp_update_pc_i    (mem2_align_bp_update_pc_o),
        .bp_update_ghr_i   (mem2_align_bp_update_ghr_o),
        .bp_ras_push_en_i  (mem2_align_bp_ras_push_en_o),
        .bp_ras_pop_en_i   (mem2_align_bp_ras_pop_en_o),
        .bp_ras_push_addr_i(mem2_align_bp_ras_push_addr_o),
        .bp_actual_taken_i (mem2_align_bp_actual_taken_o),
        .rd_addr_o         (mem_wb_rd_addr_o),
        .rd_data_o         (mem_wb_rd_data_o),
        .rd_wen_o          (mem_wb_rd_wen_o),
        .mem_rd_addr_o     (mem_wb_mem_rd_addr_o),
        .is_slow_load_o    (mem_wb_is_slow_load_o),
        .bp_update_en_o    (mem_wb_bp_update_en_o),
        .bp_update_pc_o    (mem_wb_bp_update_pc_o),
        .bp_update_ghr_o   (mem_wb_bp_update_ghr_o),
        .bp_ras_push_en_o  (mem_wb_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (mem_wb_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(mem_wb_bp_ras_push_addr_o),
        .bp_actual_taken_o (mem_wb_bp_actual_taken_o),
        .inst_o            (mem_wb_inst_o)
    );

    // ==================================================================
    // WB
    // ==================================================================
    wb wb_inst (
        .inst_i         (mem_wb_inst_o),
        .rd_addr_i      (mem_wb_rd_addr_o),
        .rd_data_i      (mem_wb_rd_data_o),
        .rd_wen_i       (mem_wb_rd_wen_o),
        .mem_rd_addr_i  (mem_wb_mem_rd_addr_o),
        .is_slow_load_i (mem_wb_is_slow_load_o),
        .mmio_data_i    (mmio_data_i),
        .inst_o         (),
        .rd_data_o      (wb_rd_data_o),
        .rd_wen_o       (wb_rd_wen_o),
        .rd_addr_o      (wb_rd_addr_o)
    );

endmodule
