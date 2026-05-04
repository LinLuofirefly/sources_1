// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_seg_led_stop.h for the primary calling header

#ifndef VERILATED_VTB_SEG_LED_STOP___024ROOT_H_
#define VERILATED_VTB_SEG_LED_STOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_seg_led_stop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_seg_led_stop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_seg_led_stop__DOT__w_cpu_clk;
        CData/*0:0*/ tb_seg_led_stop__DOT__w_clk_50Mhz;
        CData/*0:0*/ tb_seg_led_stop__DOT__w_clk_rst;
        CData/*7:0*/ tb_seg_led_stop__DOT__virtual_key;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o;
        CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_valid_r;
        CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i;
        CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
        CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
        CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r;
        CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*7:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
        CData/*7:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr;
        CData/*7:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans;
    };
    struct {
        CData/*4:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1;
        CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_10;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_11;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_12;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_26;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_28;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_29;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_30;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_31;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_32;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_40;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_cpu_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_50Mhz__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*14:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o;
        SData/*14:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o;
        SData/*8:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o;
        SData/*8:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
        SData/*8:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_ghr__DOT__data_r;
        SData/*14:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r;
        SData/*15:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
        IData/*31:0*/ tb_seg_led_stop__DOT__seg_write_count;
        IData/*31:0*/ tb_seg_led_stop__DOT__led_write_count;
        IData/*31:0*/ tb_seg_led_stop__DOT__same_pc_count;
        IData/*31:0*/ tb_seg_led_stop__DOT__prev_pc;
        IData/*31:0*/ tb_seg_led_stop__DOT__second_seg_cycle;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__pc;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__instruction;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_target__DOT__data_r;
    };
    struct {
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        QData/*63:0*/ tb_seg_led_stop__DOT__virtual_sw;
        QData/*63:0*/ tb_seg_led_stop__DOT__cycle_count;
        QData/*63:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        QData/*63:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2;
        QData/*39:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output;
        QData/*39:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        QData/*39:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2;
        VlUnpacked<CData/*1:0*/, 64> tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht;
        VlUnpacked<CData/*0:0*/, 64> tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid;
        VlUnpacked<IData/*31:0*/, 32> tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras;
        VlUnpacked<IData/*31:0*/, 32> tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 4096> tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem;
        VlUnpacked<IData/*31:0*/, 65536> tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_seg_led_stop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_seg_led_stop___024root(Vtb_seg_led_stop__Syms* symsp, const char* namep);
    ~Vtb_seg_led_stop___024root();
    VL_UNCOPYABLE(Vtb_seg_led_stop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
