`timescale 1ns / 1ps

module sim_wrapper (
    input  logic        w_cpu_clk,
    input  logic        w_clk_50Mhz,
    input  logic        w_clk_rst,
    input  logic [7:0]  virtual_key,
    input  logic [63:0] virtual_sw,

    output logic [31:0] virtual_led,
    output logic [39:0] virtual_seg,

    output logic [31:0] mon_perip_addr,
    output logic [3:0]  mon_perip_wstrb,
    output logic [31:0] mon_perip_wdata,
    output logic [31:0] mon_pc,
    output logic        mon_hdu_hold,
    output logic        mon_hdu_flush,
    output logic        mon_late_load_miss,
    output logic [31:0] mon_id_inst,
    output logic [31:0] mon_id_ex_inst,
    output logic [2:0]  mon_id_ex_rs1_fwd_sel,
    output logic [2:0]  mon_id_ex_rs2_fwd_sel,
    output logic [31:0] mon_mem_inst,
    output logic [31:0] mon_wb_inst,
    output logic        mon_wb_rd_wen,
    output logic [31:0] mon_x10,
    output logic [31:0] mon_x13,
    output logic [31:0] mon_x14,
    output logic [31:0] mon_x15,

    // Performance monitoring signals
    output logic        mon_bp_update_en,
    output logic        mon_bp_actual_taken,
    output logic [31:0] mon_bp_update_pc,
    output logic        mon_ex_is_branch,
    output logic        mon_branch_redirect,

    output logic        mon_btb_hit,
    output logic        mon_btb_pred_taken,

    output logic        mon_dcache_hit,
    output logic        mon_mem2_is_load,
    output logic        mon_dcache_refill,

    output logic        mon_ex_busy,
    output logic        mon_ex_done,
    output logic        mon_ex_load_dep,
    output logic        mon_mem1_load_dep,
    output logic        mon_mem1_load_shift_dep,
    output logic        mon_mem2_slow_load_dep,

    output logic        mon_ctrl_flush_ifid,
    output logic        mon_ctrl_flush_idex,
    output logic        mon_bp_pred_flush,
    output logic        mon_bp_replay_flush
);

    student_top student_top_inst (
        .w_cpu_clk   (w_cpu_clk),
        .w_clk_50Mhz (w_clk_50Mhz),
        .w_clk_rst   (w_clk_rst),
        .virtual_key (virtual_key),
        .virtual_sw  (virtual_sw),
        .virtual_led (virtual_led),
        .virtual_seg (virtual_seg)
    );

    assign mon_perip_addr  = student_top_inst.perip_addr;
    assign mon_perip_wstrb = student_top_inst.perip_wstrb;
    assign mon_perip_wdata = student_top_inst.perip_wdata;
    assign mon_pc          = student_top_inst.pc;

    // Directed simulation monitors only; CPU RTL module interfaces are unchanged.
    assign mon_hdu_hold          = student_top_inst.Core_cpu.cpu_core.hdu_hold_flag_o;
    assign mon_hdu_flush         = student_top_inst.Core_cpu.cpu_core.hdu_flush_flag_o;
    assign mon_late_load_miss    = 1'b0;
    assign mon_id_inst           = student_top_inst.Core_cpu.cpu_core.id_inst_o;
    assign mon_id_ex_inst        = student_top_inst.Core_cpu.cpu_core.id_ex_inst_o;
    assign mon_id_ex_rs1_fwd_sel = student_top_inst.Core_cpu.cpu_core.id_ex_rs1_fwd_sel_o;
    assign mon_id_ex_rs2_fwd_sel = student_top_inst.Core_cpu.cpu_core.id_ex_rs2_fwd_sel_o;
    assign mon_mem_inst          = student_top_inst.Core_cpu.cpu_core.mem_inst_o;
    assign mon_wb_inst           = student_top_inst.Core_cpu.cpu_core.mem_wb_inst_o;
    assign mon_wb_rd_wen         = student_top_inst.Core_cpu.cpu_core.wb_rd_wen_o;
    assign mon_x10               = student_top_inst.Core_cpu.cpu_core.regs_inst.regs[10];
    assign mon_x13               = student_top_inst.Core_cpu.cpu_core.regs_inst.regs[13];
    assign mon_x14               = student_top_inst.Core_cpu.cpu_core.regs_inst.regs[14];
    assign mon_x15               = student_top_inst.Core_cpu.cpu_core.regs_inst.regs[15];

    // Branch prediction signals (EX stage)
    assign mon_bp_update_en      = student_top_inst.Core_cpu.cpu_core.bp_update_en_o;
    assign mon_bp_actual_taken   = student_top_inst.Core_cpu.cpu_core.bp_actual_taken_o;
    assign mon_bp_update_pc      = student_top_inst.Core_cpu.cpu_core.bp_update_pc_o;
    assign mon_ex_is_branch      = student_top_inst.Core_cpu.cpu_core.id_ex_is_branch_o;
    assign mon_branch_redirect   = student_top_inst.Core_cpu.cpu_core.ex_inst.branch_redirect_w;

    // BTB signals
    assign mon_btb_hit           = student_top_inst.Core_cpu.cpu_core.bp_req_btb_hit_o;
    assign mon_btb_pred_taken    = student_top_inst.Core_cpu.cpu_core.bp_req_pred_taken_o;

    // DCache signals
    assign mon_dcache_hit        = student_top_inst.Core_cpu.cpu_core.mem1_load_cache_hit;
    assign mon_mem2_is_load      = student_top_inst.Core_cpu.cpu_core.mem1_mem2_is_load_o;
    assign mon_dcache_refill     = student_top_inst.Core_cpu.cpu_core.dram_cache_inst.refill_req;

    // Stall sources
    assign mon_ex_busy           = student_top_inst.Core_cpu.cpu_core.ex_rv32m_busy_o;
    assign mon_ex_done           = student_top_inst.Core_cpu.cpu_core.ex_rv32m_done_o;
    assign mon_ex_load_dep       = student_top_inst.Core_cpu.cpu_core.hdu_inst.ex_load_dep;
    assign mon_mem1_load_dep     = student_top_inst.Core_cpu.cpu_core.hdu_inst.mem1_load_dep;
    assign mon_mem1_load_shift_dep = student_top_inst.Core_cpu.cpu_core.hdu_inst.mem1_load_shift_dep;
    assign mon_mem2_slow_load_dep  = student_top_inst.Core_cpu.cpu_core.hdu_inst.mem2_slow_load_dep;

    // Flush signals
    assign mon_ctrl_flush_ifid   = student_top_inst.Core_cpu.cpu_core.ctrl_flush_ifid_o;
    assign mon_ctrl_flush_idex   = student_top_inst.Core_cpu.cpu_core.ctrl_flush_idex_o;
    assign mon_bp_pred_flush     = student_top_inst.Core_cpu.cpu_core.bp_pred_flush_d1_r;
    assign mon_bp_replay_flush   = student_top_inst.Core_cpu.cpu_core.bp_replay_flush_d1_r;

endmodule
