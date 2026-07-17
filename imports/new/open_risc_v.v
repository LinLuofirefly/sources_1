`timescale 1ns / 1ps
`include "defines.v"
`include "dram_cache.v"

module open_risc_v (
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

    wire        bp_req_btb_hit_o;
    wire        bp_req_pred_taken_o;
    wire [31:0] bp_req_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_req_pred_ghr_o;
    reg         bp_early_hit_r;
    reg         bp_early_pred_taken_r;
    reg  [31:0] bp_early_pred_target_r;
    reg  [`BP_GHR_WIDTH-1:0] bp_early_pred_ghr_r;

    reg         bp_pred_flush_d1_r;
    reg         bp_replay_flush_d1_r;

    wire [31:0] pc_jump_addr_o;
    wire        pc_jump_en_o;
    reg         pc_redirect_valid;
    reg  [31:0] pc_redirect_target;
    wire        bp_pc_redirect_valid;
    wire [31:0] bp_pc_redirect_target;

    reg  [31:0] bp_fetch_pc_r;

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
    wire [1:0]  id_rs1_fwd_sel_o;
    wire [1:0]  id_rs2_fwd_sel_o;
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
    wire [2:0]  id_branch_cond_o;
    wire        id_use_rs1_o;
    wire        id_use_rs2_o;
    wire        id_is_branch_o;
    wire        id_use_base_addr_o;
    wire [2:0]  id_dec_func3_o;
    wire        id_dec_func7_bit5_o;
    wire        id_dec_func7_is_r_o;
    wire        id_dec_func7_is_sub_o;
    wire        id_dec_is_op_imm_o;
    wire        id_dec_is_op_reg_o;
    wire        id_dec_is_branch_o;
    wire        id_dec_is_load_o;
    wire        id_dec_is_store_o;
    wire        id_dec_is_jal_o;
    wire        id_dec_is_jalr_o;
    wire        id_dec_is_auipc_o;
    wire        id_dec_is_lui_o;
    wire        id_dec_is_system_o;
    wire        id_dec_is_rv32m_o;
    wire        id_dec_is_csr_op_o;
    wire        id_dec_is_zip_o;
    wire        id_dec_is_call_jal_o;
    wire        id_dec_ras_should_push_jalr_o;
    wire        id_dec_ras_should_pop_jalr_o;
    wire        id_dec_ras_predicted_jalr_o;
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
    wire [1:0]  id_ex_rs1_fwd_sel_o;
    wire [1:0]  id_ex_rs2_fwd_sel_o;
    wire        id_ex_use_rs1_o;
    wire        id_ex_use_rs2_o;
    wire        id_ex_use_base_addr_o;
    wire [4:0]  id_ex_rd_addr_o;
    wire        id_ex_reg_wen;
    wire [31:0] id_ex_base_addr_o;
    wire [31:0] id_ex_branch_offset_o;
    wire [31:0] id_ex_mem_offset_o;
    wire [31:0] id_ex_jump_offset_o;
    wire [2:0]  id_ex_branch_cond_o;
    wire [2:0]  id_ex_func3_o;
    wire        id_ex_func7_bit5_o;
    wire        id_ex_func7_is_r_o;
    wire        id_ex_func7_is_sub_o;
    wire        id_ex_is_op_imm_o;
    wire        id_ex_is_op_reg_o;
    wire        id_ex_is_branch_o;
    wire        id_ex_is_load_o;
    wire        id_ex_is_store_o;
    wire        id_ex_is_jal_o;
    wire        id_ex_is_jalr_o;
    wire        id_ex_is_auipc_o;
    wire        id_ex_is_lui_o;
    wire        id_ex_is_system_o;
    wire        id_ex_is_rv32m_o;
    wire        id_ex_is_csr_op_o;
    wire        id_ex_is_zip_o;
    wire        id_ex_is_call_jal_o;
    wire        id_ex_ras_should_push_jalr_o;
    wire        id_ex_ras_should_pop_jalr_o;
    wire        id_ex_ras_predicted_jalr_o;

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
    wire [31:0] bp_update_target_o;
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
    wire [31:0] ex_mem_bp_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] ex_mem_bp_update_ghr_o;
    wire        ex_mem_bp_ras_push_en_o;
    wire        ex_mem_bp_ras_pop_en_o;
    wire [31:0] ex_mem_bp_ras_push_addr_o;
    wire        ex_mem_bp_actual_taken_o;

    wire        mem1_mem2_bp_update_en_o;
    wire [31:0] mem1_mem2_bp_update_pc_o;
    wire [31:0] mem1_mem2_bp_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] mem1_mem2_bp_update_ghr_o;
    wire        mem1_mem2_bp_ras_push_en_o;
    wire        mem1_mem2_bp_ras_pop_en_o;
    wire [31:0] mem1_mem2_bp_ras_push_addr_o;
    wire        mem1_mem2_bp_actual_taken_o;

    wire        mem_wb_bp_update_en_o;
    wire [31:0] mem_wb_bp_update_pc_o;
    wire [31:0] mem_wb_bp_update_target_o;
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
    wire [31:0] fwd_br_op1_o;
    wire [31:0] fwd_br_op2_o;
    wire [31:0] fwd_store_data_o;
    wire [31:0] fwd_ls_base_addr_o;
    wire [31:0] fwd_jalr_base_addr_o;

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
    wire        ex_mem_store_load_fwd_valid_o;
    wire [3:0]  ex_mem_store_load_fwd_wstrb_o;
    wire [31:0] ex_mem_store_load_fwd_data_o;

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
    wire        mem1_mem2_load_cache_hit_o;
    wire        mem1_mem2_store_load_fwd_valid_o;
    wire [3:0]  mem1_mem2_store_load_fwd_wstrb_o;
    wire [31:0] mem1_mem2_store_load_fwd_data_o;

    // ------------------------------------------------------------------
    // MEM2
    // ------------------------------------------------------------------
    wire [31:0] mem2_inst_o;
    wire [4:0]  mem2_rd_addr_o;
    wire [31:0] mem2_rd_data_o;
    wire        mem2_rd_wen_o;
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
    wire [4:0]  mem_wb_rd_addr_fwd_o;
    wire [31:0] mem_wb_rd_data_fwd_o;
    wire        mem_wb_rd_wen_fwd_o;
    wire        mem_wb_is_slow_load_fwd_o;

    assign mem_rd_reg_o  = ex_is_load_o;
    assign mem_rd_addr_o = ex_rd_mem_addr_o;

    wire ex_mem_store_hits_dram =
        (ex_mem_wd_addr_o >= DRAM_ADDR_START) &&
        (ex_mem_wd_addr_o <  DRAM_ADDR_END);

    wire store_load_fwd_valid_ex =
        ex_is_load_o &&
        ex_load_hits_dram_o &&
        (|ex_mem_wd_reg_o) &&
        ex_mem_store_hits_dram &&
        (ex_rd_mem_addr_o[31:2] == ex_mem_wd_addr_o[31:2]);

    wire [3:0]  store_load_fwd_wstrb_ex = ex_mem_wd_reg_o;
    wire [31:0] store_load_fwd_data_ex  = ex_mem_wd_data_o;

    wire        mem1_load_cache_hit;
    wire [31:0] mem1_rd_data_to_mem2;

    dram_cache #(
        .DRAM_ADDR_START(DRAM_ADDR_START),
        .DRAM_ADDR_END  (DRAM_ADDR_END),
        .INDEX_BITS     (6)
    ) dram_cache_inst (
        .clk                         (clk),
        .rst                         (rst),
        .ex_load_addr_i              (ex_rd_mem_addr_o),
        .mem1_is_load_i              (ex_mem_is_load_o),
        .mem1_load_hits_dram_i       (ex_mem_load_hits_dram_o),
        .mem1_inst_i                 (ex_mem_inst_o),
        .mem1_load_addr_i            (ex_mem_mem_rd_addr_o),
        .mem1_uncached_rd_data_i     (mem_out_rd_data_o),
        .mem1_store_load_fwd_valid_i (ex_mem_store_load_fwd_valid_o),
        .mem1_store_load_fwd_wstrb_i (ex_mem_store_load_fwd_wstrb_o),
        .mem1_store_load_fwd_data_i  (ex_mem_store_load_fwd_data_o),
        .mem2_is_load_i              (mem1_mem2_is_load_o),
        .mem2_load_hits_dram_i       (mem1_mem2_load_hits_dram_o),
        .mem2_load_cache_hit_i       (mem1_mem2_load_cache_hit_o),
        .mem2_load_addr_i            (mem1_mem2_mem_rd_addr_o),
        .mem2_ram_data_i             (ram_data_i),
        .mem2_store_load_fwd_valid_i (mem1_mem2_store_load_fwd_valid_o),
        .mem2_store_load_fwd_wstrb_i (mem1_mem2_store_load_fwd_wstrb_o),
        .mem2_store_load_fwd_data_i  (mem1_mem2_store_load_fwd_data_o),
        .store_wstrb_i               (w_en),
        .store_addr_i                (w_addr_i),
        .store_data_i                (w_data_i),
        .mem1_load_cache_hit_o       (mem1_load_cache_hit),
        .mem1_rd_data_o              (mem1_rd_data_to_mem2)
    );
    // ==================================================================
    // Fetch / IF-ID / branch predictor accept control
    // ==================================================================

    wire bp_if_valid =
        ~bp_pred_flush_d1_r &
        ~bp_early_hit_r;

    // Select the live or held prediction as one complete packet.
    // Taken, target and prediction metadata must stay cycle-aligned.
    wire use_held_prediction = bp_early_hit_r;
    wire live_pred_valid     = bp_if_valid;
    wire held_pred_valid     = bp_early_hit_r;

    wire effective_pred_valid =
        use_held_prediction ? held_pred_valid : live_pred_valid;
    wire effective_pred_taken =
        use_held_prediction ? bp_early_pred_taken_r : bp_pred_taken_o;
    wire [31:0] effective_pred_target =
        use_held_prediction ? bp_early_pred_target_r : bp_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] effective_pred_ghr =
        use_held_prediction ? bp_early_pred_ghr_r : bp_pred_ghr_o;

    // A synchronous fetch package can coincide with the package already held
    // by IF/ID, especially after a predicted redirect. Suppress only exact
    // same-PC duplicates; unrelated sequential fetches must still pass.
    wire ifid_duplicate =
        if_id_load_valid_o && (bp_fetch_pc_r == if_id_inst_addr_o);

    wire ifid_fetch_valid =
        effective_pred_valid &
        ~ctrl_flush_ifid_o &
        ~bp_pred_flush_d1_r &
        ~ifid_duplicate;

    wire ifid_direct_fire =
        ifid_fetch_valid &
        ~hdu_hold_flag_o &
        ~if_id_replay_pending_o;

    // Keep the prediction-to-PC redirect path independent from
    // predictor bookkeeping, statistics and update control.
    wire bp_fetch_redirect =
        ifid_direct_fire &
        ~use_held_prediction &
        bp_pred_taken_o;
    wire bp_replay_redirect =
        if_id_replaying_o &
        if_id_pred_taken_o &
        ~hdu_hold_flag_o;
    assign bp_pc_redirect_valid =
        bp_fetch_redirect | bp_replay_redirect;
    assign bp_pc_redirect_target =
        bp_replay_redirect ? if_id_pred_target_o : bp_pred_target_o;

    // Predictor acceptance bookkeeping is generated in parallel.
    // It must not add logic levels to the timing-critical PC path.
    assign bp_pred_taken_accepted_o = bp_pc_redirect_valid;

    // Request-stage redirect: the target request enters IROM immediately, so
    // unlike the late fallback it must not create bp_pred_flush_d1_r.
    wire bp_early_redirect =
        rst &
        ~hdu_hold_flag_o &
        ~ctrl_jump_en_o &
        ~bp_pc_redirect_valid &
        bp_req_btb_hit_o &
        bp_req_pred_taken_o;

    // Select the final PC redirect valid and target in one priority block.
    // This keeps redirect control and target selection consistent and avoids
    // duplicated combinational cones feeding the PC update path.
    always @(*) begin
        pc_redirect_valid  = 1'b0;
        pc_redirect_target = 32'b0;

        if (ctrl_jump_en_o) begin
            pc_redirect_valid  = 1'b1;
            pc_redirect_target = ctrl_jump_addr_o;
        end else if (bp_pc_redirect_valid) begin
            pc_redirect_valid  = 1'b1;
            pc_redirect_target = bp_pc_redirect_target;
        end else if (bp_early_redirect) begin
            pc_redirect_valid  = 1'b1;
            pc_redirect_target = bp_req_pred_target_o;
        end
    end

    assign pc_jump_en_o   = pc_redirect_valid;
    assign pc_jump_addr_o = pc_redirect_target;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            bp_fetch_pc_r            <= 32'h8000_0000;
            bp_pred_flush_d1_r       <= 1'b0;
            bp_replay_flush_d1_r     <= 1'b0;
            bp_early_hit_r           <= 1'b0;
            bp_early_pred_taken_r    <= 1'b0;
            bp_early_pred_target_r   <= 32'b0;
            bp_early_pred_ghr_r      <= {`BP_GHR_WIDTH{1'b0}};
        end else begin
            bp_fetch_pc_r            <= pc_reg_pc_o;
            bp_early_hit_r           <= bp_req_btb_hit_o;
            bp_early_pred_taken_r    <= bp_req_pred_taken_o;
            bp_early_pred_target_r   <= bp_req_pred_target_o;
            bp_early_pred_ghr_r      <= bp_req_pred_ghr_o;

            // ?????redirect ??????IROM ??????ghost fetch??
            bp_pred_flush_d1_r       <= bp_pred_taken_accepted_o;

            // replay redirect ??????
            bp_replay_flush_d1_r     <= bp_replay_redirect;
        end
    end

    wire frontend_flush_ifid =
        ctrl_flush_ifid_o |
        bp_replay_flush_d1_r;

    wire frontend_flush_idex =
        ctrl_flush_idex_o |
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
        .req_pc_i        (pc_reg_pc_o),
        .req_btb_hit_o   (bp_req_btb_hit_o),
        .req_pred_taken_o(bp_req_pred_taken_o),
        .req_pred_target_o(bp_req_pred_target_o),
        .req_pred_ghr_o  (bp_req_pred_ghr_o),
        .pred_taken_o    (bp_pred_taken_o),
        .pred_target_o   (bp_pred_target_o),
        .pred_ghr_o      (bp_pred_ghr_o),
        .update_en_i     (mem_wb_bp_update_en_o),
        .update_pc_i     (mem_wb_bp_update_pc_o),
        .update_target_i (mem_wb_bp_update_target_o),
        .update_ghr_i    (mem_wb_bp_update_ghr_o),
        .ras_push_en_i   (bp_ras_push_en_o),
        .ras_pop_en_i    (bp_ras_pop_en_o),
        .ras_push_addr_i (bp_ras_push_addr_o),
        .actual_taken_i  (mem_wb_bp_actual_taken_o)
    );

    // ==================================================================
    // PC
    // ==================================================================

    pc_reg pc_reg_inst (
        .clk         (clk),
        .rst         (rst),
        .jump_en     (pc_jump_en_o),
        .jump_addr_i (pc_jump_addr_o),
        .hold_flag_i (hdu_hold_flag_o),
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
        .pred_taken_i       (effective_pred_taken),
        .pred_target_i      (effective_pred_target),
        .pred_ghr_i         (effective_pred_ghr),
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
        .branch_cond_o   (id_branch_cond_o),
        .mem_rd_reg_o    (data_read_en),
        .is_branch_o     (id_is_branch_o),
        .use_rs1_o       (id_use_rs1_o),
        .use_rs2_o       (id_use_rs2_o),
        .use_base_addr_o (id_use_base_addr_o),
        .ex_func3_o      (id_dec_func3_o),
        .ex_func7_bit5_o (id_dec_func7_bit5_o),
        .ex_func7_is_r_o (id_dec_func7_is_r_o),
        .ex_func7_is_sub_o(id_dec_func7_is_sub_o),
        .ex_is_op_imm_o  (id_dec_is_op_imm_o),
        .ex_is_op_reg_o  (id_dec_is_op_reg_o),
        .ex_is_branch_o  (id_dec_is_branch_o),
        .ex_is_load_o    (id_dec_is_load_o),
        .ex_is_store_o   (id_dec_is_store_o),
        .ex_is_jal_o     (id_dec_is_jal_o),
        .ex_is_jalr_o    (id_dec_is_jalr_o),
        .ex_is_auipc_o   (id_dec_is_auipc_o),
        .ex_is_lui_o     (id_dec_is_lui_o),
        .ex_is_system_o  (id_dec_is_system_o),
        .ex_is_rv32m_o   (id_dec_is_rv32m_o),
        .ex_is_csr_op_o  (id_dec_is_csr_op_o),
        .ex_is_zip_o     (id_dec_is_zip_o),
        .ex_is_call_jal_o(id_dec_is_call_jal_o),
        .ex_ras_should_push_jalr_o(id_dec_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_o (id_dec_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_o  (id_dec_ras_predicted_jalr_o)
    );

    // ==================================================================
    // Early forwarding select
    // ==================================================================
    early_forwarding_select early_forwarding_select_inst (
        .id_rs1_addr_i         (id_rs1_addr_o),
        .id_rs2_addr_i         (id_rs2_addr_o),
        .id_use_rs1_i          (id_use_rs1_o),
        .id_use_rs2_i          (id_use_rs2_o),
        .id_use_base_addr_i    (id_use_base_addr_o),
        .ex_rd_addr_i          (id_ex_rd_addr_o),
        .ex_rd_wen_i           (id_ex_reg_wen),
        .ex_is_load_i          (id_ex_is_load_o),
        .mem1_rd_addr_i        (ex_mem_pipe_rd_addr_o),
        .mem1_rd_wen_i         (ex_mem_rd_wen_o),
        .mem1_is_load_i        (ex_mem_is_load_o),
        .mem1_load_cache_hit_i (mem1_load_cache_hit),
        .mem2_rd_addr_i        (mem2_rd_addr_o),
        .mem2_rd_wen_i         (mem2_rd_wen_o),
        .mem2_is_slow_load_i   (mem2_is_slow_load_o),
        .rs1_fwd_sel_o         (id_rs1_fwd_sel_o),
        .rs2_fwd_sel_o         (id_rs2_fwd_sel_o)
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
        .rs1_fwd_sel_i   (id_rs1_fwd_sel_o),
        .rs2_fwd_sel_i   (id_rs2_fwd_sel_o),
        .use_rs1_i       (id_use_rs1_o),
        .use_rs2_i       (id_use_rs2_o),
        .use_base_addr_i (id_use_base_addr_o),
        .rd_addr_i       (id_rd_addr_o),
        .reg_wen_i       (id_reg_wen),
        .base_addr_i     (id_base_addr_o),
        .branch_offset_i (id_branch_offset_o),
        .mem_offset_i    (id_mem_offset_o),
        .jump_offset_i   (id_jump_offset_o),
        .branch_cond_i   (id_branch_cond_o),
        .ex_func3_i      (id_dec_func3_o),
        .ex_func7_bit5_i (id_dec_func7_bit5_o),
        .ex_func7_is_r_i (id_dec_func7_is_r_o),
        .ex_func7_is_sub_i(id_dec_func7_is_sub_o),
        .ex_is_op_imm_i  (id_dec_is_op_imm_o),
        .ex_is_op_reg_i  (id_dec_is_op_reg_o),
        .ex_is_branch_i  (id_dec_is_branch_o),
        .ex_is_load_i    (id_dec_is_load_o),
        .ex_is_store_i   (id_dec_is_store_o),
        .ex_is_jal_i     (id_dec_is_jal_o),
        .ex_is_jalr_i    (id_dec_is_jalr_o),
        .ex_is_auipc_i   (id_dec_is_auipc_o),
        .ex_is_lui_i     (id_dec_is_lui_o),
        .ex_is_system_i  (id_dec_is_system_o),
        .ex_is_rv32m_i   (id_dec_is_rv32m_o),
        .ex_is_csr_op_i  (id_dec_is_csr_op_o),
        .ex_is_zip_i     (id_dec_is_zip_o),
        .ex_is_call_jal_i(id_dec_is_call_jal_o),
        .ex_ras_should_push_jalr_i(id_dec_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_i (id_dec_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_i  (id_dec_ras_predicted_jalr_o),
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
        .rs1_fwd_sel_o   (id_ex_rs1_fwd_sel_o),
        .rs2_fwd_sel_o   (id_ex_rs2_fwd_sel_o),
        .use_rs1_o       (id_ex_use_rs1_o),
        .use_rs2_o       (id_ex_use_rs2_o),
        .use_base_addr_o (id_ex_use_base_addr_o),
        .rd_addr_o       (id_ex_rd_addr_o),
        .reg_wen_o       (id_ex_reg_wen),
        .base_addr_o     (id_ex_base_addr_o),
        .branch_offset_o (id_ex_branch_offset_o),
        .mem_offset_o    (id_ex_mem_offset_o),
        .jump_offset_o   (id_ex_jump_offset_o),
        .branch_cond_o   (id_ex_branch_cond_o),
        .ex_func3_o      (id_ex_func3_o),
        .ex_func7_bit5_o (id_ex_func7_bit5_o),
        .ex_func7_is_r_o (id_ex_func7_is_r_o),
        .ex_func7_is_sub_o(id_ex_func7_is_sub_o),
        .ex_is_op_imm_o  (id_ex_is_op_imm_o),
        .ex_is_op_reg_o  (id_ex_is_op_reg_o),
        .ex_is_branch_o  (id_ex_is_branch_o),
        .ex_is_load_o    (id_ex_is_load_o),
        .ex_is_store_o   (id_ex_is_store_o),
        .ex_is_jal_o     (id_ex_is_jal_o),
        .ex_is_jalr_o    (id_ex_is_jalr_o),
        .ex_is_auipc_o   (id_ex_is_auipc_o),
        .ex_is_lui_o     (id_ex_is_lui_o),
        .ex_is_system_o  (id_ex_is_system_o),
        .ex_is_rv32m_o   (id_ex_is_rv32m_o),
        .ex_is_csr_op_o  (id_ex_is_csr_op_o),
        .ex_is_zip_o     (id_ex_is_zip_o),
        .ex_is_call_jal_o(id_ex_is_call_jal_o),
        .ex_ras_should_push_jalr_o(id_ex_ras_should_push_jalr_o),
        .ex_ras_should_pop_jalr_o (id_ex_ras_should_pop_jalr_o),
        .ex_ras_predicted_jalr_o  (id_ex_ras_predicted_jalr_o)
    );

    // Do not force max_fanout on wide datapath buses.
    // Excessive register replication can worsen physical routing timing.
    assign mem2_is_slow_load_o = mem1_mem2_is_load_o &&
                                  ~mem1_mem2_load_hits_dram_o;

    // ==================================================================
    // Forwarding
    // ==================================================================
    forwarding forwarding_inst (
        .id_ex_op1_i              (id_ex_op1_o),
        .id_ex_op2_i              (id_ex_op2_o),
        .id_ex_cmp_op2_i          (id_ex_cmp_op2_o),
        .id_ex_store_data_i       (id_ex_store_data_o),
        .id_ex_ls_base_addr_i     (id_ex_base_addr_o),
        .id_ex_jalr_base_addr_i   (id_ex_base_addr_o),
        .id_ex_br_op1_i           (id_ex_op1_o),
        .id_ex_br_op2_i           (id_ex_cmp_op2_o),
        .id_ex_rs1_fwd_sel_i      (id_ex_rs1_fwd_sel_o),
        .id_ex_rs2_fwd_sel_i      (id_ex_rs2_fwd_sel_o),
        .ex_mem_rd_data_i         (ex_mem_rd_data_o),
        .mem1_mem2_rd_data_i      (mem1_mem2_rd_data_o),
        .mem_wb_rd_data_i         (mem_wb_rd_data_fwd_o),
        .fwd_op1_o                (fwd_op1_o),
        .fwd_op2_o                (fwd_op2_o),
        .fwd_cmp_op2_o            (fwd_cmp_op2_o),
        .fwd_br_op1_o             (fwd_br_op1_o),
        .fwd_br_op2_o             (fwd_br_op2_o),
        .fwd_store_data_o         (fwd_store_data_o),
        .fwd_ls_base_addr_o       (fwd_ls_base_addr_o),
        .fwd_jalr_base_addr_o     (fwd_jalr_base_addr_o)
    );

    // ==================================================================
    // HDU
    // ==================================================================
    Hazard_detection_unit hdu_inst (
        .id_inst_i            (id_inst_o),
        .id_rs1_addr_i        (id_rs1_addr_o),
        .id_rs2_addr_i        (id_rs2_addr_o),
        .id_use_rs1_i         (id_use_rs1_o),
        .id_use_rs2_i         (id_use_rs2_o),
        .ex_inst_i            (id_ex_inst_o),
        .mem1_inst_i          (ex_mem_inst_o),
        .mem1_load_cache_hit_i(mem1_load_cache_hit),
        .mem2_inst_i          (mem1_mem2_inst_o),
        .mem2_is_slow_load_i  (mem2_is_slow_load_o),
        .ex_busy_i            (ex_rv32m_busy_o),
        .ex_done_i            (ex_rv32m_done_o),
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
        .fwd_op1_i           (fwd_op1_o),
        .fwd_op2_i           (fwd_op2_o),
        .fwd_cmp_op2_i       (fwd_cmp_op2_o),
        .fwd_br_op1_i        (fwd_br_op1_o),
        .fwd_br_op2_i        (fwd_br_op2_o),
        .store_data_i        (fwd_store_data_o),
        .pred_taken_i        (id_ex_pred_taken_o),
        .pred_target_i       (id_ex_pred_target_o),
        .pred_ghr_i          (id_ex_pred_ghr_o),
        .rd_addr_i           (id_ex_rd_addr_o),
        .rd_wen_i            (id_ex_reg_wen),
        .kill_i              (ctrl_kill_ex_o),
        .fwd_ls_base_i       (fwd_ls_base_addr_o),
        .fwd_jalr_base_i     (fwd_jalr_base_addr_o),
        .branch_offset_i     (id_ex_branch_offset_o),
        .mem_offset_i        (id_ex_mem_offset_o),
        .jump_offset_i       (id_ex_jump_offset_o),
        .branch_cond_i       (id_ex_branch_cond_o),
        .dec_func3_i         (id_ex_func3_o),
        .dec_func7_bit5_i    (id_ex_func7_bit5_o),
        .dec_func7_is_r_i    (id_ex_func7_is_r_o),
        .dec_func7_is_sub_i  (id_ex_func7_is_sub_o),
        .dec_is_op_imm_i     (id_ex_is_op_imm_o),
        .dec_is_op_reg_i     (id_ex_is_op_reg_o),
        .dec_is_branch_i     (id_ex_is_branch_o),
        .dec_is_load_i       (id_ex_is_load_o),
        .dec_is_store_i      (id_ex_is_store_o),
        .dec_is_jal_i        (id_ex_is_jal_o),
        .dec_is_jalr_i       (id_ex_is_jalr_o),
        .dec_is_auipc_i      (id_ex_is_auipc_o),
        .dec_is_lui_i        (id_ex_is_lui_o),
        .dec_is_system_i     (id_ex_is_system_o),
        .dec_is_rv32m_i      (id_ex_is_rv32m_o),
        .dec_is_csr_op_i     (id_ex_is_csr_op_o),
        .dec_is_zip_i        (id_ex_is_zip_o),
        .dec_is_call_jal_i   (id_ex_is_call_jal_o),
        .dec_ras_should_push_jalr_i(id_ex_ras_should_push_jalr_o),
        .dec_ras_should_pop_jalr_i (id_ex_ras_should_pop_jalr_o),
        .dec_ras_predicted_jalr_i  (id_ex_ras_predicted_jalr_o),
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
        .bp_update_target_o  (bp_update_target_o),
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
        .store_load_fwd_valid_i(store_load_fwd_valid_ex),
        .store_load_fwd_wstrb_i(store_load_fwd_wstrb_ex),
        .store_load_fwd_data_i (store_load_fwd_data_ex),
        .bp_update_en_i    (bp_update_en_o),
        .bp_update_pc_i    (bp_update_pc_o),
        .bp_update_target_i(bp_update_target_o),
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
        .store_load_fwd_valid_o(ex_mem_store_load_fwd_valid_o),
        .store_load_fwd_wstrb_o(ex_mem_store_load_fwd_wstrb_o),
        .store_load_fwd_data_o (ex_mem_store_load_fwd_data_o),
        .bp_update_en_o    (ex_mem_bp_update_en_o),
        .bp_update_pc_o    (ex_mem_bp_update_pc_o),
        .bp_update_target_o(ex_mem_bp_update_target_o),
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
        .rd_data_i         (mem1_rd_data_to_mem2),
        .rd_wen_i          (mem_out_rd_wen_o),
        .mem_rd_addr_i     (mem_out_mem_rd_addr_o),
        .is_load_i         (mem_out_is_load_o),
        .load_hits_dram_i  (ex_mem_load_hits_dram_o),
        .load_cache_hit_i  (mem1_load_cache_hit),
        .store_load_fwd_valid_i(ex_mem_store_load_fwd_valid_o),
        .store_load_fwd_wstrb_i(ex_mem_store_load_fwd_wstrb_o),
        .store_load_fwd_data_i (ex_mem_store_load_fwd_data_o),
        .bp_update_en_i    (ex_mem_bp_update_en_o),
        .bp_update_pc_i    (ex_mem_bp_update_pc_o),
        .bp_update_target_i(ex_mem_bp_update_target_o),
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
        .load_cache_hit_o  (mem1_mem2_load_cache_hit_o),
        .store_load_fwd_valid_o(mem1_mem2_store_load_fwd_valid_o),
        .store_load_fwd_wstrb_o(mem1_mem2_store_load_fwd_wstrb_o),
        .store_load_fwd_data_o (mem1_mem2_store_load_fwd_data_o),
        .bp_update_en_o    (mem1_mem2_bp_update_en_o),
        .bp_update_pc_o    (mem1_mem2_bp_update_pc_o),
        .bp_update_target_o(mem1_mem2_bp_update_target_o),
        .bp_update_ghr_o   (mem1_mem2_bp_update_ghr_o),
        .bp_ras_push_en_o  (mem1_mem2_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (mem1_mem2_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(mem1_mem2_bp_ras_push_addr_o),
        .bp_actual_taken_o (mem1_mem2_bp_actual_taken_o),
        .inst_o            (mem1_mem2_inst_o)
    );

    // ==================================================================
    // MEM2
    // ==================================================================
    mem2 mem2_inst (
        .inst_i        (mem1_mem2_inst_o),
        .rd_addr_i     (mem1_mem2_rd_addr_o),
        .rd_data_i     (mem1_mem2_rd_data_o),
        .rd_wen_i      (mem1_mem2_rd_wen_o),
        .mem_rd_addr_i (mem1_mem2_mem_rd_addr_o),
        .is_load_i     (mem1_mem2_is_load_o),
        .load_cache_hit_i(mem1_mem2_load_cache_hit_o),
        .mem_rd_data_i (ram_data_i),
        .store_load_fwd_valid_i(mem1_mem2_store_load_fwd_valid_o),
        .store_load_fwd_wstrb_i(mem1_mem2_store_load_fwd_wstrb_o),
        .store_load_fwd_data_i (mem1_mem2_store_load_fwd_data_o),
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
        .mem_rd_addr_i     (mem1_mem2_mem_rd_addr_o),
        .is_slow_load_i    (mem2_is_slow_load_o),
        .bp_update_en_i    (mem1_mem2_bp_update_en_o),
        .bp_update_pc_i    (mem1_mem2_bp_update_pc_o),
        .bp_update_target_i(mem1_mem2_bp_update_target_o),
        .bp_update_ghr_i   (mem1_mem2_bp_update_ghr_o),
        .bp_ras_push_en_i  (mem1_mem2_bp_ras_push_en_o),
        .bp_ras_pop_en_i   (mem1_mem2_bp_ras_pop_en_o),
        .bp_ras_push_addr_i(mem1_mem2_bp_ras_push_addr_o),
        .bp_actual_taken_i (mem1_mem2_bp_actual_taken_o),
        .rd_addr_o         (mem_wb_rd_addr_o),
        .rd_data_o         (mem_wb_rd_data_o),
        .rd_wen_o          (mem_wb_rd_wen_o),
        .mem_rd_addr_o     (mem_wb_mem_rd_addr_o),
        .is_slow_load_o    (mem_wb_is_slow_load_o),
        .bp_update_en_o    (mem_wb_bp_update_en_o),
        .bp_update_pc_o    (mem_wb_bp_update_pc_o),
        .bp_update_target_o(mem_wb_bp_update_target_o),
        .bp_update_ghr_o   (mem_wb_bp_update_ghr_o),
        .bp_ras_push_en_o  (mem_wb_bp_ras_push_en_o),
        .bp_ras_pop_en_o   (mem_wb_bp_ras_pop_en_o),
        .bp_ras_push_addr_o(mem_wb_bp_ras_push_addr_o),
        .bp_actual_taken_o (mem_wb_bp_actual_taken_o),
        .inst_o            (mem_wb_inst_o),
        .rd_addr_fwd_o      (mem_wb_rd_addr_fwd_o),
        .rd_data_fwd_o      (mem_wb_rd_data_fwd_o),
        .rd_wen_fwd_o       (mem_wb_rd_wen_fwd_o),
        .is_slow_load_fwd_o (mem_wb_is_slow_load_fwd_o)
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
