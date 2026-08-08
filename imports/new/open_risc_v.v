`timescale 1ns / 1ps
`include "defines.v"
`include "dram_cache.v"

module open_risc_v #(
    // The request and its prediction metadata are registered as one packet
    // beside the synchronous IROM.  The default therefore keeps the fast
    // request-stage redirect enabled; set this to zero for A/B diagnostics.
    parameter ENABLE_REQUEST_STAGE_BP = 1'b1
) (
    input  wire        clk,
    input  wire        rst_n,
    input  wire [31:0] inst_i,
    input  wire [31:0] ram_data_i,
    input  wire [31:0] mmio_data_i,
    input  wire        timer_irq_i,
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
    wire [31:0] bp_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_pred_ghr_o;
    wire [1:0]  bp_pred_type_o;

    wire        bp_req_btb_hit_o;
    wire        bp_req_pred_valid_o;
    wire        bp_req_pred_taken_o;
    wire [31:0] bp_req_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_req_pred_ghr_o;
    wire [1:0]  bp_req_pred_type_o;
    reg         bp_fetch_valid_r;
    reg         bp_fetch_pred_valid_r;
    reg         bp_early_pred_taken_r;
    reg  [31:0] bp_early_pred_target_r;
    reg  [`BP_GHR_WIDTH-1:0] bp_early_pred_ghr_r;
    reg  [1:0]  bp_early_pred_type_r;
    reg         fetch_epoch_r;
    reg         bp_fetch_epoch_r;

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
    wire        late_load_miss_o;

    // ------------------------------------------------------------------
    // IF/ID
    // ------------------------------------------------------------------
    wire [31:0] if_id_inst_addr_o;
    wire [31:0] if_id_inst_o;
    wire        if_id_pred_taken_o;
    wire [31:0] if_id_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] if_id_pred_ghr_o;
    wire [1:0]  if_id_pred_type_o;

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
    wire [2:0]  id_rs1_fwd_sel_o;
    wire [2:0]  id_rs2_fwd_sel_o;
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
    wire [1:0]  id_ex_pred_type_o;
    wire [4:0]  id_ex_rs1_addr_o;
    wire [4:0]  id_ex_rs2_addr_o;
    wire [2:0]  id_ex_rs1_fwd_sel_o;
    wire [2:0]  id_ex_rs2_fwd_sel_o;
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
    wire        ex_timer_irq_trap_o;
    wire [31:0] ex_rd_mem_addr_o;
    wire        ex_load_hits_dram_o;

    wire        bp_update_en_o;
    wire [31:0] bp_update_pc_o;
    wire [31:0] bp_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_update_ghr_o;
    wire        bp_ras_push_en_o;
    wire        bp_ras_pop_en_o;
    wire [31:0] bp_ras_push_addr_o;
    wire        bp_jalr_update_en_o;
    wire [31:0] bp_jalr_update_pc_o;
    wire [31:0] bp_jalr_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] bp_jalr_update_ghr_o;
    wire        bp_jalr_update_is_call_o;
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
    wire        ex_mem_bp_actual_taken_o;

    wire        mem1_mem2_bp_update_en_o;
    wire [31:0] mem1_mem2_bp_update_pc_o;
    wire [31:0] mem1_mem2_bp_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] mem1_mem2_bp_update_ghr_o;
    wire        mem1_mem2_bp_actual_taken_o;

    wire        mem_wb_bp_update_en_o;
    wire [31:0] mem_wb_bp_update_pc_o;
    wire [31:0] mem_wb_bp_update_target_o;
    wire [`BP_GHR_WIDTH-1:0] mem_wb_bp_update_ghr_o;
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
    wire [31:0] fwd_load_base_addr_o;
    wire [31:0] fwd_store_base_addr_o;
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
    wire        ex_mem_store_load_fwd_valid_cache_o;
    wire        ex_mem_store_load_fwd_valid_pipe_o;
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
    wire        mem1_mem2_store_load_fwd_valid_cache_o;
    wire        mem1_mem2_store_load_fwd_valid_mem2_o;
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
    wire [31:0] mem_wb_rd_data_fwd_o;

    wire id_dec_is_shift_imm =
        id_dec_is_op_imm_o &&
        (((id_dec_func3_o == `INST_SLLI) && id_dec_func7_is_r_o) ||
         ((id_dec_func3_o == `INST_SRI) &&
          (id_dec_func7_is_r_o || id_dec_func7_is_sub_o)));

    wire id_dec_is_shift_reg =
        id_dec_is_op_reg_o &&
        (((id_dec_func3_o == `INST_SLL) && id_dec_func7_is_r_o) ||
         ((id_dec_func3_o == `INST_SR) &&
          (id_dec_func7_is_r_o || id_dec_func7_is_sub_o)));

    wire id_dec_has_deep_alu = id_dec_is_shift_imm || id_dec_is_shift_reg;

    // The EX load address is now physically driven by a non-late forwarding
    // mux.  Ordinary ALU/store consumers retain the hit bypass; a dependent
    // load waits for a registered result to avoid cache-hit -> address chains.
    // 当前 ID 指令为 shift 时也禁止 late-load：否则命中数据会直接进入
    // 桶形移位器，形成 DCache 输出到 EX/MEM1 寄存器的长组合路径。
    wire        ex_load_late_bypass_allowed =
        id_ex_is_load_o &&
        ex_load_hits_dram_o &&
        !ctrl_kill_ex_o &&
        !id_dec_is_branch_o &&
        !id_dec_is_jalr_o &&
        !id_dec_is_load_o &&
        !id_dec_has_deep_alu;

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
    wire [31:0] mem1_pipe_rd_data =
        mem_out_is_load_o ? mem1_rd_data_to_mem2 : mem_out_rd_data_o;

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
        .mem1_store_load_fwd_valid_i (ex_mem_store_load_fwd_valid_cache_o),
        .mem1_store_load_fwd_wstrb_i (ex_mem_store_load_fwd_wstrb_o),
        .mem1_store_load_fwd_data_i  (ex_mem_store_load_fwd_data_o),
        .mem2_is_load_i              (mem1_mem2_is_load_o),
        .mem2_load_hits_dram_i       (mem1_mem2_load_hits_dram_o),
        .mem2_load_cache_hit_i       (mem1_mem2_load_cache_hit_o),
        .mem2_load_addr_i            (mem1_mem2_mem_rd_addr_o),
        .mem2_ram_data_i             (ram_data_i),
        .mem2_store_load_fwd_valid_i (mem1_mem2_store_load_fwd_valid_cache_o),
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

    // bp_fetch_* and bp_early_* are one indivisible synchronous-IROM packet:
    // PC, prediction validity, taken, target, type, GHR and epoch are captured
    // on the request edge and consumed only by the matching response.
    wire bp_fetch_epoch_match = (bp_fetch_epoch_r == fetch_epoch_r);
    wire use_held_prediction =
        ENABLE_REQUEST_STAGE_BP &&
        bp_fetch_valid_r &&
        bp_fetch_epoch_match &&
        bp_fetch_pred_valid_r;

    wire bp_if_valid =
        bp_fetch_valid_r &
        bp_fetch_epoch_match &
        ~bp_pred_flush_d1_r &
        ~use_held_prediction;

    // Select the live or held prediction as one complete packet.
    // Taken, target and prediction metadata must stay cycle-aligned.
    wire live_pred_valid     = bp_if_valid;
    wire held_pred_valid     = bp_fetch_valid_r & bp_fetch_epoch_match;

    wire effective_pred_valid =
        use_held_prediction ? held_pred_valid : live_pred_valid;
    wire effective_pred_taken =
        use_held_prediction ? bp_early_pred_taken_r : bp_pred_taken_o;
    wire [31:0] effective_pred_target =
        use_held_prediction ? bp_early_pred_target_r : bp_pred_target_o;
    wire [`BP_GHR_WIDTH-1:0] effective_pred_ghr =
        use_held_prediction ? bp_early_pred_ghr_r : bp_pred_ghr_o;
    wire [1:0] effective_pred_type =
        use_held_prediction ? bp_early_pred_type_r : bp_pred_type_o;

    wire bp_replay_redirect =
        if_id_replaying_o &
        if_id_pred_taken_o &
        // A replay redirect invalidates the response currently returning from
        // the sequential path.  The delayed pulse still clears the following
        // pipeline slot after the replayed branch advances to ID/EX.
        ~bp_replay_flush_d1_r &
        ~hdu_hold_flag_o;

    wire irom_rsp_kill =
        ctrl_jump_en_o |
        ex_timer_irq_trap_o |
        bp_replay_redirect;

    wire ifid_fetch_valid =
        effective_pred_valid &
        ~ctrl_flush_ifid_o &
        ~bp_pred_flush_d1_r &
        ~irom_rsp_kill;

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
    assign bp_pc_redirect_valid =
        bp_fetch_redirect | bp_replay_redirect;
    assign bp_pc_redirect_target =
        bp_replay_redirect ? if_id_pred_target_o : bp_pred_target_o;

    // Recovery redirects start a new fetch epoch.  Correct request-stage
    // predictions do not advance it: their originating request remains valid
    // while only the following PC changes to the predicted target.
    wire fetch_epoch_advance =
        ctrl_jump_en_o |
        ex_timer_irq_trap_o |
        bp_pc_redirect_valid;

    // A request is accepted exactly once.  During a hold, BRAM may still see
    // the held address electrically, but the corresponding response packet is
    // invalid.  Late/replay/EX redirects likewise invalidate the sequential
    // request captured on that edge.
    wire irom_req_fire =
        rst &
        ~hdu_hold_flag_o &
        ~ctrl_jump_en_o &
        ~ex_timer_irq_trap_o &
        ~bp_pc_redirect_valid;

    // Request-stage redirect: the branch request itself remains valid and its
    // metadata is carried in the response packet; only the next PC changes.
    wire bp_early_redirect =
        ENABLE_REQUEST_STAGE_BP &
        irom_req_fire &
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
            bp_fetch_valid_r         <= 1'b0;
            bp_fetch_pc_r            <= 32'h8000_0000;
            bp_pred_flush_d1_r       <= 1'b0;
            bp_replay_flush_d1_r     <= 1'b0;
            bp_fetch_pred_valid_r    <= 1'b0;
            bp_early_pred_taken_r    <= 1'b0;
            bp_early_pred_target_r   <= 32'b0;
            bp_early_pred_ghr_r      <= {`BP_GHR_WIDTH{1'b0}};
            bp_early_pred_type_r     <= `BP_PRED_NONE;
            fetch_epoch_r            <= 1'b0;
            bp_fetch_epoch_r         <= 1'b0;
        end else begin
            // This register bank is the one-cycle IROM request/response tag.
            // inst_i observed after this edge belongs to this exact packet.
            bp_fetch_valid_r         <= irom_req_fire;
            bp_fetch_pc_r            <= pc_reg_pc_o;
            bp_fetch_pred_valid_r    <= bp_req_pred_valid_o;
            bp_early_pred_taken_r    <= bp_req_pred_taken_o;
            bp_early_pred_target_r   <= bp_req_pred_target_o;
            bp_early_pred_ghr_r      <= bp_req_pred_ghr_o;
            bp_early_pred_type_r     <= bp_req_pred_type_o;
            bp_fetch_epoch_r         <= fetch_epoch_r;

            if (fetch_epoch_advance) begin
                fetch_epoch_r <= ~fetch_epoch_r;
            end

            // The late predictor redirects after the sequential request has
            // reached IROM.  Suppress that one-cycle ghost response.
            bp_pred_flush_d1_r       <= bp_pc_redirect_valid;

            // Keep the existing one-cycle replay pipeline clear pulse.
            bp_replay_flush_d1_r     <= bp_replay_redirect;
        end
    end

    wire frontend_flush_ifid =
        ex_timer_irq_trap_o |
        ctrl_flush_ifid_o |
        bp_replay_flush_d1_r;

    wire frontend_flush_idex =
        ex_timer_irq_trap_o |
        ctrl_flush_idex_o |
        bp_replay_flush_d1_r;

`ifndef SYNTHESIS
    // A request-stage prediction is safe only if its metadata returns beside
    // the instruction for the same PC and epoch.  These checks catch future
    // edits that accidentally delay one packet field independently.
    always @(negedge clk) begin
        if (rst && use_held_prediction) begin
            if ((bp_early_pred_type_r == `BP_PRED_BRANCH) &&
                (inst_i[6:0] != `INST_TYPE_B)) begin
                $fatal(1, "request BP packet mismatch: branch type pc=%08x inst=%08x",
                       bp_fetch_pc_r, inst_i);
            end
            if ((bp_early_pred_type_r == `BP_PRED_JALR) &&
                (inst_i[6:0] != `INST_JALR)) begin
                $fatal(1, "request BP packet mismatch: JALR type pc=%08x inst=%08x",
                       bp_fetch_pc_r, inst_i);
            end
        end
        if (rst && bp_fetch_valid_r && !bp_fetch_epoch_match &&
            ifid_fetch_valid) begin
            $fatal(1, "stale IROM response accepted across fetch epoch");
        end
    end
`endif

    // ==================================================================
    // Branch predictor
    // ==================================================================
    branch_predictor branch_predictor_inst (
        .clk             (clk),
        .rst             (rst),
        .if_valid_i      (bp_if_valid),
        .if_inst_i       (inst_i),
        .if_pc_i         (bp_fetch_pc_r),
        .if_ghr_i        (bp_early_pred_ghr_r),
        .req_pc_i        (pc_reg_pc_o),
        .req_btb_hit_o   (bp_req_btb_hit_o),
        .req_pred_valid_o(bp_req_pred_valid_o),
        .req_pred_taken_o(bp_req_pred_taken_o),
        .req_pred_target_o(bp_req_pred_target_o),
        .req_pred_ghr_o  (bp_req_pred_ghr_o),
        .req_pred_type_o (bp_req_pred_type_o),
        .pred_taken_o    (bp_pred_taken_o),
        .pred_target_o   (bp_pred_target_o),
        .pred_ghr_o      (bp_pred_ghr_o),
        .pred_type_o     (bp_pred_type_o),
        .update_en_i     (mem_wb_bp_update_en_o),
        .update_pc_word_i(mem_wb_bp_update_pc_o[31:2]),
        .update_target_i (mem_wb_bp_update_target_o),
        .update_ghr_i    (mem_wb_bp_update_ghr_o),
        .ras_push_en_i   (bp_ras_push_en_o),
        .ras_pop_en_i    (bp_ras_pop_en_o),
        .ras_push_addr_i (bp_ras_push_addr_o),
        .jalr_update_en_i(bp_jalr_update_en_o),
        .jalr_update_pc_i(bp_jalr_update_pc_o),
        .jalr_update_target_i(bp_jalr_update_target_o),
        .jalr_update_ghr_i(bp_jalr_update_ghr_o),
        .jalr_update_is_call_i(bp_jalr_update_is_call_o),
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
        .pred_type_i        (effective_pred_type),
        .hold_flag_i        (hdu_hold_flag_o),
        .flush_flag_i       (frontend_flush_ifid),
        .inst_addr_o        (if_id_inst_addr_o),
        .pred_taken_o       (if_id_pred_taken_o),
        .pred_target_o      (if_id_pred_target_o),
        .pred_ghr_o         (if_id_pred_ghr_o),
        .pred_type_o        (if_id_pred_type_o),
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
        .ex_load_hits_dram_i   (ex_load_late_bypass_allowed),
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
        .pred_type_i     (if_id_pred_type_o),
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
        .pred_type_o     (id_ex_pred_type_o),
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
        .clk                      (clk),
        .rst                      (rst),
        .late_load_miss_i         (late_load_miss_o),
        .id_ex_op1_i              (id_ex_op1_o),
        .id_ex_op2_i              (id_ex_op2_o),
        .id_ex_cmp_op2_i          (id_ex_cmp_op2_o),
        .id_ex_store_data_i       (id_ex_store_data_o),
        .id_ex_ls_base_addr_i     (id_ex_base_addr_o),
        .id_ex_rs1_fwd_sel_i      (id_ex_rs1_fwd_sel_o),
        .id_ex_rs2_fwd_sel_i      (id_ex_rs2_fwd_sel_o),
        .ex_mem_rd_data_i         (ex_mem_rd_data_o),
        .mem1_mem2_rd_data_i      (mem1_mem2_rd_data_o),
        .mem1_load_rd_data_i      (mem1_rd_data_to_mem2),
        .mem2_rd_data_i           (mem2_rd_data_o),
        .mem_wb_rd_data_i         (mem_wb_rd_data_fwd_o),
        .fwd_op1_o                (fwd_op1_o),
        .fwd_op2_o                (fwd_op2_o),
        .fwd_cmp_op2_o            (fwd_cmp_op2_o),
        .fwd_br_op1_o             (fwd_br_op1_o),
        .fwd_br_op2_o             (fwd_br_op2_o),
        .fwd_store_data_o         (fwd_store_data_o),
        .fwd_load_base_addr_o     (fwd_load_base_addr_o),
        .fwd_store_base_addr_o    (fwd_store_base_addr_o),
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
        .ex_load_hits_dram_i  (ex_load_late_bypass_allowed),
        .id_ex_rs1_fwd_sel_i  (id_ex_rs1_fwd_sel_o),
        .id_ex_rs2_fwd_sel_i  (id_ex_rs2_fwd_sel_o),
        .mem1_inst_i          (ex_mem_inst_o),
        .mem1_load_cache_hit_i(mem1_load_cache_hit),
        .mem2_inst_i          (mem1_mem2_inst_o),
        .mem2_is_slow_load_i  (mem2_is_slow_load_o),
        .ex_busy_i            (ex_rv32m_busy_o),
        .ex_done_i            (ex_rv32m_done_o),
        .hold_flag_o          (hdu_hold_flag_o),
        .flush_flag_o         (hdu_flush_flag_o),
        .late_load_miss_o     (late_load_miss_o)
    );

    // ==================================================================
    // EX
    // ==================================================================
    ex ex_inst (
        .clk                 (clk),
        .rst                 (rst),
        .timer_irq_i         (timer_irq_i),
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
        .pred_type_i         (id_ex_pred_type_o),
        .rd_addr_i           (id_ex_rd_addr_o),
        .rd_wen_i            (id_ex_reg_wen),
        .kill_i              (ctrl_kill_ex_o | late_load_miss_o),
        .fwd_load_base_i     (fwd_load_base_addr_o),
        .fwd_store_base_i    (fwd_store_base_addr_o),
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
        .bp_jalr_update_en_o (bp_jalr_update_en_o),
        .bp_jalr_update_pc_o (bp_jalr_update_pc_o),
        .bp_jalr_update_target_o(bp_jalr_update_target_o),
        .bp_jalr_update_ghr_o(bp_jalr_update_ghr_o),
        .bp_jalr_update_is_call_o(bp_jalr_update_is_call_o),
        .bp_actual_taken_o   (bp_actual_taken_o),
        .rv32m_busy_o        (ex_rv32m_busy_o),
        .rv32m_done_o        (ex_rv32m_done_o),
        .timer_irq_trap_o    (ex_timer_irq_trap_o)
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
        .flush_idex_o (ctrl_flush_idex_o)
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
        .store_load_fwd_valid_cache_o(ex_mem_store_load_fwd_valid_cache_o),
        .store_load_fwd_valid_pipe_o (ex_mem_store_load_fwd_valid_pipe_o),
        .store_load_fwd_wstrb_o(ex_mem_store_load_fwd_wstrb_o),
        .store_load_fwd_data_o (ex_mem_store_load_fwd_data_o),
        .bp_update_en_o    (ex_mem_bp_update_en_o),
        .bp_update_pc_o    (ex_mem_bp_update_pc_o),
        .bp_update_target_o(ex_mem_bp_update_target_o),
        .bp_update_ghr_o   (ex_mem_bp_update_ghr_o),
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
        .rd_data_i         (mem1_pipe_rd_data),
        .rd_wen_i          (mem_out_rd_wen_o),
        .mem_rd_addr_i     (mem_out_mem_rd_addr_o),
        .is_load_i         (mem_out_is_load_o),
        .load_hits_dram_i  (ex_mem_load_hits_dram_o),
        .load_cache_hit_i  (mem1_load_cache_hit),
        .store_load_fwd_valid_i(ex_mem_store_load_fwd_valid_pipe_o),
        .store_load_fwd_wstrb_i(ex_mem_store_load_fwd_wstrb_o),
        .store_load_fwd_data_i (ex_mem_store_load_fwd_data_o),
        .bp_update_en_i    (ex_mem_bp_update_en_o),
        .bp_update_pc_i    (ex_mem_bp_update_pc_o),
        .bp_update_target_i(ex_mem_bp_update_target_o),
        .bp_update_ghr_i   (ex_mem_bp_update_ghr_o),
        .bp_actual_taken_i (ex_mem_bp_actual_taken_o),
        .rd_addr_o         (mem1_mem2_rd_addr_o),
        .rd_data_o         (mem1_mem2_rd_data_o),
        .rd_wen_o          (mem1_mem2_rd_wen_o),
        .mem_rd_addr_o     (mem1_mem2_mem_rd_addr_o),
        .is_load_o         (mem1_mem2_is_load_o),
        .load_hits_dram_o  (mem1_mem2_load_hits_dram_o),
        .load_cache_hit_o  (mem1_mem2_load_cache_hit_o),
        .store_load_fwd_valid_o(mem1_mem2_store_load_fwd_valid_o),
        .store_load_fwd_valid_cache_o(mem1_mem2_store_load_fwd_valid_cache_o),
        .store_load_fwd_valid_mem2_o (mem1_mem2_store_load_fwd_valid_mem2_o),
        .store_load_fwd_wstrb_o(mem1_mem2_store_load_fwd_wstrb_o),
        .store_load_fwd_data_o (mem1_mem2_store_load_fwd_data_o),
        .bp_update_en_o    (mem1_mem2_bp_update_en_o),
        .bp_update_pc_o    (mem1_mem2_bp_update_pc_o),
        .bp_update_target_o(mem1_mem2_bp_update_target_o),
        .bp_update_ghr_o   (mem1_mem2_bp_update_ghr_o),
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
        .store_load_fwd_valid_i(mem1_mem2_store_load_fwd_valid_mem2_o),
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
        .bp_actual_taken_o (mem_wb_bp_actual_taken_o),
        .inst_o            (mem_wb_inst_o),
        .rd_data_fwd_o      (mem_wb_rd_data_fwd_o)
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
