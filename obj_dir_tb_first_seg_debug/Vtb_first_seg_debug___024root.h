// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_first_seg_debug.h for the primary calling header

#ifndef VERILATED_VTB_FIRST_SEG_DEBUG___024ROOT_H_
#define VERILATED_VTB_FIRST_SEG_DEBUG___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_first_seg_debug__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_first_seg_debug___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_first_seg_debug__DOT__w_cpu_clk;
        CData/*0:0*/ tb_first_seg_debug__DOT__w_clk_50Mhz;
        CData/*0:0*/ tb_first_seg_debug__DOT__w_clk_rst;
        CData/*7:0*/ tb_first_seg_debug__DOT__virtual_key;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r;
        CData/*7:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
    };
    struct {
        CData/*7:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr;
        CData/*7:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans;
        CData/*6:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4;
        CData/*6:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3;
        CData/*6:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2;
        CData/*6:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1;
        CData/*4:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
        CData/*3:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1;
        CData/*0:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_12;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_14;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_15;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_16;
        CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_17;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_cpu_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_50Mhz__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_rst__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        SData/*14:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o;
        SData/*14:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r;
        SData/*15:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
        IData/*31:0*/ tb_first_seg_debug__DOT__cycle_count;
        IData/*31:0*/ tb_first_seg_debug__DOT__hist_wr_ptr;
        IData/*31:0*/ tb_first_seg_debug__DOT__hist_count;
        IData/*31:0*/ tb_first_seg_debug__DOT__j;
        IData/*31:0*/ tb_first_seg_debug__DOT__slot;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__pc;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__instruction;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__perip_rdata;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r;
    };
    struct {
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__LED;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_rdata;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        IData/*31:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        QData/*63:0*/ tb_first_seg_debug__DOT__virtual_sw;
        QData/*63:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        QData/*63:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2;
        QData/*39:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output;
        QData/*39:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        QData/*39:0*/ tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_pc;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_inst;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_ifid;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_idex;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_exmem;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_mem1;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_mem12;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_mem2a;
    };
    struct {
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_mem2b;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_mem2;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_hold;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_hflush;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_ifflush;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_idflush;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_fop1;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_fop2;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_wbwen;
        VlUnpacked<CData/*4:0*/, 64> tb_first_seg_debug__DOT__hist_wbaddr;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_wbdata;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_x8;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_x10;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_x14;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_x15;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_seg;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_rd_addr;
        VlUnpacked<CData/*0:0*/, 64> tb_first_seg_debug__DOT__hist_rd_req;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_rd_data;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_wr_addr;
        VlUnpacked<CData/*3:0*/, 64> tb_first_seg_debug__DOT__hist_wr_strb;
        VlUnpacked<IData/*31:0*/, 64> tb_first_seg_debug__DOT__hist_wr_data;
        VlUnpacked<CData/*1:0*/, 128> tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht;
        VlUnpacked<IData/*31:0*/, 32> tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs;
        VlUnpacked<IData/*31:0*/, 4096> tb_first_seg_debug__DOT__dut__DOT__Mem_IROM__DOT__mem;
        VlUnpacked<IData/*31:0*/, 65536> tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 9> __Vm_traceActivity;
    };
    VlNBACommitQueue<VlUnpacked<CData/*1:0*/, 128>, false, CData/*1:0*/, 1> __VdlyCommitQueuetb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h8244fe8f__0;

    // INTERNAL VARIABLES
    Vtb_first_seg_debug__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_first_seg_debug___024root(Vtb_first_seg_debug__Syms* symsp, const char* namep);
    ~Vtb_first_seg_debug___024root();
    VL_UNCOPYABLE(Vtb_first_seg_debug___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
