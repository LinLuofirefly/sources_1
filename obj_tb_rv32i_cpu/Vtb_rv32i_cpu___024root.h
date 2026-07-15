// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rv32i_cpu.h for the primary calling header

#ifndef VERILATED_VTB_RV32I_CPU___024ROOT_H_
#define VERILATED_VTB_RV32I_CPU___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_rv32i_cpu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rv32i_cpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_rv32i_cpu__DOT__w_cpu_clk;
        CData/*0:0*/ tb_rv32i_cpu__DOT__w_clk_50Mhz;
        CData/*0:0*/ tb_rv32i_cpu__DOT__w_clk_rst;
        CData/*7:0*/ tb_rv32i_cpu__DOT__virtual_key;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o;
        CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_actual_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_actual_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_actual_taken_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o;
        CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_load_hits_dram_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
        CData/*5:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
        CData/*5:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_nonempty;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx;
    };
    struct {
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_taken_next;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs1_next;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs2_next;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_base_addr_next;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__reg_wen_next;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start;
        CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r;
        CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r;
        CData/*5:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_mul_op;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_overflow;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1;
        CData/*7:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
        CData/*7:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg;
        CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_r;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr;
        CData/*7:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans;
        CData/*6:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4;
        CData/*6:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3;
        CData/*6:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2;
        CData/*6:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1;
        CData/*4:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1;
        CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2;
        CData/*0:0*/ __VdfgTmp_h25675075__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_50Mhz__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_rst__0;
        CData/*0:0*/ __VactContinue;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o;
    };
    struct {
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
        SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next;
        SData/*15:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
        IData/*31:0*/ tb_rv32i_cpu__DOT__seg_write_count;
        IData/*31:0*/ tb_rv32i_cpu__DOT__led_write_count;
        IData/*31:0*/ tb_rv32i_cpu__DOT__same_pc_count;
        IData/*31:0*/ tb_rv32i_cpu__DOT__low_pc_count;
        IData/*31:0*/ tb_rv32i_cpu__DOT__prev_pc;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__pc;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__instruction;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_reg_inst__DOT__next_pc;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next;
    };
    struct {
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r;
        VlWide<3>/*65:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_result_final;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_final;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_final;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__LED;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_rv32i_cpu__DOT__virtual_sw;
        QData/*63:0*/ tb_rv32i_cpu__DOT__cycle_count;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_w;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_w;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_trial_remainder;
        QData/*32:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next;
        QData/*63:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        QData/*63:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2;
        QData/*39:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        QData/*39:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2;
        VlUnpacked<CData/*1:0*/, 512> tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht;
        VlUnpacked<CData/*0:0*/, 512> tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid;
        VlUnpacked<IData/*31:0*/, 32> tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras;
        VlUnpacked<IData/*31:0*/, 32> tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 4096> tb_rv32i_cpu__DOT__dut__DOT__Mem_IROM__DOT__mem;
        VlUnpacked<IData/*31:0*/, 65536> tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_rv32i_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rv32i_cpu___024root(Vtb_rv32i_cpu__Syms* symsp, const char* v__name);
    ~Vtb_rv32i_cpu___024root();
    VL_UNCOPYABLE(Vtb_rv32i_cpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
