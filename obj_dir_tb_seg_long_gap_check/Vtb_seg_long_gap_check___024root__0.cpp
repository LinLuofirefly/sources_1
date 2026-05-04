// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_seg_long_gap_check.h for the primary calling header

#include "Vtb_seg_long_gap_check__pch.h"

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_initial__TOP(Vtb_seg_long_gap_check___024root* vlSelf);
VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__0(Vtb_seg_long_gap_check___024root* vlSelf);
VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__1(Vtb_seg_long_gap_check___024root* vlSelf);
VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__2(Vtb_seg_long_gap_check___024root* vlSelf);

void Vtb_seg_long_gap_check___024root___eval_initial(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_initial\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_seg_long_gap_check___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__0(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__virtual_key = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__virtual_sw = 0ULL;
    vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst = 1U;
    vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time = 0ULL;
    vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time = 0ULL;
    vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "new/tb_seg_long_gap_check.sv", 
                                         58);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst = 0U;
    co_await vlSelfRef.__VdlySched.delay(0xfffffc08eb57e000ULL, 
                                         nullptr, "new/tb_seg_long_gap_check.sv", 
                                         61);
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("SEG_CHECK_TIMEOUT first_data=%08h first_time=%0t second_data=%08h second_time=%0t seg_count=%0d\n",6, 'T',-9
                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data
                 , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time
                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data
                 , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time
                 , '~',32,vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count);
    VL_FINISH_MT("new/tb_seg_long_gap_check.sv", 64, "");
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    co_return;
}

VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__1(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "new/tb_seg_long_gap_check.sv", 
                                             37);
        vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz 
            = (1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz)));
    }
    co_return;
}

VlCoroutine Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__2(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000000d05ULL, 
                                             nullptr, 
                                             "new/tb_seg_long_gap_check.sv", 
                                             34);
        vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk 
            = (1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk)));
    }
    co_return;
}

void Vtb_seg_long_gap_check___024root___eval_triggers_vec__act(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_triggers_vec__act\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_rst__0))) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_50Mhz__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_cpu_clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_cpu_clk__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_50Mhz__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_rst__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst;
}

bool Vtb_seg_long_gap_check___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_seg_long_gap_check___024root___act_sequent__TOP__0(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___act_sequent__TOP__0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x00000014U))]));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU))]));
    if ((0x00000040U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                                = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x1fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x14U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x00000014U))));
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        } else {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
    } else if ((0x00000020U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
            if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0xfffff000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o
                            : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                ? (0x0000001fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o)
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else {
            if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((((0U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000cU))) 
                          || (1U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                           >> 0x0000000cU)))) 
                         || (2U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x0000000cU))))) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000fe0U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x00000014U)) 
                                                   | (0x0000001fU 
                                                      & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                         >> 7U))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (8U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                }
            }
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
    } else if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
        if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = (0xfffff000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            }
            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                    = ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U))
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x00000014U))
                            : (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U))));
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
    } else {
        if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                 | ((0x13U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                    | ((3U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                       | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | (0x63U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
              | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i) 
                  | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                     | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                        | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2))))) 
              & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now))) 
           && ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)
                ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg)
                : (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i)));
}

void Vtb_seg_long_gap_check___024root___eval_act(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_act\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___act_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
}

void Vtb_seg_long_gap_check___024root___nba_sequent__TOP__0(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_sequent__TOP__0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
            ? 0U : (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans 
        = ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))
            ? 0x55U : 0xaaU);
}

void Vtb_seg_long_gap_check___024root___nba_sequent__TOP__1(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_sequent__TOP__1\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
    __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray;
    __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_5;
    __VdfgRegularize_h6e95ff9d_0_5 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    __VdfgRegularize_h6e95ff9d_0_18 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
    IData/*31:0*/ __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc;
    __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc = 0;
    CData/*6:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1 = 0;
    CData/*6:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1 = 0;
    IData/*31:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    // Body
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0U;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0U;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0U;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0U;
    __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc;
    __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0U;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i)) {
            __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 
                = (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i);
            vlSelfRef.__VdlyCommitQueuetb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht.enqueue(1U, (IData)(__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0));
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i);
        }
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o) {
        __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1 
            = ((0U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                [(0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                 >> 2U))]) ? ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                               ? 1U
                                               : 0U)
                : ((1U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                    [(0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                     >> 2U))]) ? ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                                   ? 2U
                                                   : 0U)
                    : ((2U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                        [(0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                         >> 2U))]) ? 
                       ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                         ? 3U : 1U) : ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                        ? 3U : 2U))));
        __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1 
            = (0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                              >> 2U));
        vlSelfRef.__VdlyCommitQueuetb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht.enqueue(__VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1, (IData)(__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v1));
    }
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)))) {
        if ((((0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)) 
              & (0x80200020U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) 
             & (0U != vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count 
                = ((IData)(1U) + vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count);
            if (VL_UNLIKELY(((1U == vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count)))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time 
                    = VL_TIME_UNITED_Q(1000);
                vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
                VL_WRITEF_NX("SEG_CHECK_FIRST time=%0t pc=%08h inst=%08h data=%08h\n",5, 'T',-9
                             , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data);
                if (VL_UNLIKELY(((0x37000000U != vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data)))) {
                    VL_WRITEF_NX("SEG_CHECK_FAIL reason=FIRST_SEG_MISMATCH time=%0t pc=%08h inst=%08h seg_wdata=%08h\n",5, 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
                    VL_FINISH_MT("new/tb_seg_long_gap_check.sv", 44, "");
                }
            } else if (VL_UNLIKELY(((2U == vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count)))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time 
                    = VL_TIME_UNITED_Q(1000);
                vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
                VL_WRITEF_NX("SEG_CHECK_SECOND time=%0t pc=%08h inst=%08h data=%08h delta=%0t\n",6, 'T',-9
                             , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data
                             , '#',64,(vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time 
                                       - vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time));
                if (VL_UNLIKELY(((0xffffffff7e11d600ULL 
                                  > (vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time 
                                     - vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time))))) {
                    VL_WRITEF_NX("SEG_CHECK_FAIL reason=SECOND_SEG_TOO_EARLY time=%0t pc=%08h inst=%08h seg_wdata=%08h\n",5, 'T',-9
                                 , '#',64,VL_TIME_UNITED_Q(1000)
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction
                                 , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
                    VL_FINISH_MT("new/tb_seg_long_gap_check.sv", 44, "");
                }
                VL_WRITEF_NX("SEG_CHECK_PASS first_data=%08h first_time=%0t second_data=%08h second_time=%0t delta=%0t\n",6, 'T',-9
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data
                             , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time
                             , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data
                             , '#',64,vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time
                             , '#',64,(vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time 
                                       - vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time));
                VL_FINISH_MT("new/tb_seg_long_gap_check.sv", 94, "");
            }
        }
        if (VL_UNLIKELY(((0x00000100U > vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc)))) {
            VL_WRITEF_NX("SEG_CHECK_FAIL reason=RUNAWAY_LOW_PC time=%0t pc=%08h inst=%08h seg_wdata=%08h\n",5, 'T',-9
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction
                         , '#',32,vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
            VL_FINISH_MT("new/tb_seg_long_gap_check.sv", 44, "");
        }
    }
    if ((0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
        if ((1U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0x000000ffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r);
            __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0x000000ffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                                  >> 8U));
            __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0x000000ffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                                  >> 0x10U));
            __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                   >> 0x18U);
            __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        __VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r;
        __VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 1U;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
        [(0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                         >> 2U))];
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc = 0x80000000U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = 0ULL;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = 0U;
    } else {
        __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc 
            = (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i))
                ? ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1
                    : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o)
                : ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i)
                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc
                    : ((IData)(4U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc)));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
    }
    vlSelfRef.__VdlyCommitQueuetb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht.commit(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = 0U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
    }
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = 0ULL;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = 0x80000000U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
    } else {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
            = (((0x80200000U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                 ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                 : ((0x80200004U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                     ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                     : ((0x80200010U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                         ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                         : ((0x80200020U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                             ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                             : ((0x80200050U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                 ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                                 : (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                    & (- (IData)(((0x80100000U 
                                                   <= vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr) 
                                                  & (0x8013ffffU 
                                                     > vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)))))))))) 
               & (- (IData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r;
        if ((0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            if ((0x80200040U != vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                if ((0x80200020U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
                }
            }
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 
            = vlSelfRef.tb_seg_long_gap_check__DOT__virtual_sw;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 
            = vlSelfRef.tb_seg_long_gap_check__DOT__virtual_key;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc;
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout = 0;
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0x7fffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x80000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xbfffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x40000000U & ((0x40000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xc0000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xdfffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x20000000U & ((0x60000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xe0000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xefffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x10000000U & ((0x70000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xf0000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xf7ffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x08000000U & ((0x78000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xf8000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfbffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x04000000U & ((0x7c000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfc000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfdffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x02000000U & ((0x7e000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfe000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfeffffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x01000000U & ((0x7f000000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xff000000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xff7fffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00800000U & ((0x7f800000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xff800000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffbfffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00400000U & ((0x7fc00000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffc00000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffdfffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00200000U & ((0x7fe00000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffe00000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffefffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00100000U & ((0x7ff00000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfff00000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfff7ffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00080000U & ((0x7ff80000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfff80000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffbffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00040000U & ((0x7ffc0000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffc0000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffdffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00020000U & ((0x7ffe0000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffe0000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffeffffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00010000U & ((0x7fff0000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffff0000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffff7fffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00008000U & ((0x7fff8000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffff8000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffbfffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00004000U & ((0x7fffc000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffc000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffdfffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00002000U & ((0x7fffe000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffe000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffefffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00001000U & ((0x7ffff000U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffff000U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffff7ffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000800U & ((0x7ffff800U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffff800U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffbffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000400U & ((0x7ffffc00U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffc00U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffdffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000200U & ((0x7ffffe00U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffe00U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffeffU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000100U & ((0x7fffff00U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffff00U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffff7fU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000080U & ((0x7fffff80U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffff80U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffbfU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000040U & ((0x7fffffc0U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffffc0U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffdfU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000020U & ((0x7fffffe0U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffffe0U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffefU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000010U & ((0x7ffffff0U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffff0U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffff7U & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (8U & ((0x7ffffff8U & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffff8U 
                                                   & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffbU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (4U & ((0x7ffffffcU & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffcU 
                                                   & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffdU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (2U & ((0x7ffffffeU & (__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffeU 
                                                   & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffeU & __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (1U & ((__Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                         >> 1U) ^ __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray)));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d 
            = __Vfunc_tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 
            = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin, 1U));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
            = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r);
    }
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = 0U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 1U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i)))) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r 
        = (0x0000001fU & ((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                           >> 7U) & (- (IData)((1U 
                                                & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                         | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i)))) 
               && (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i) 
                    & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o)) 
                   & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i)))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r));
    if (__VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0] 
            = __VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
           + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r 
        = (1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Mem_IROM__DOT__mem
        [(0x00000fffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc 
                         >> 2U))];
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc 
        = __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__pc;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i) {
        if ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction))) {
            if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                 [(0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                                  >> 2U))])) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU))) 
                           << 0x0000000cU) | ((0x00000800U 
                                               & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                       >> 7U))))));
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                   + (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                   >> 0x0000001fU))) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                >> 0x00000014U)))));
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
            [(0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                             >> 2U))];
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata 
        = (((0x80200000U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
             ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2)
             : ((0x80200004U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                 ? (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
                            >> 0x00000020U)) : ((0x80200010U 
                                                 == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                 ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2)
                                                 : 
                                                ((0x80200020U 
                                                  == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                  ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                                                  : 0xdeadbeefU)))) 
           & (- (IData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)
            ? ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                ? (((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                     ? (0x0000ffffU & ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                           >> 0x00000010U)
                                        : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata))
                     : (0x000000ffU & ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000018U)
                                            : (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000010U))
                                        : ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                               >> 8U)
                                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata)))) 
                   & (- (IData)((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000dU))))))
                : ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                    ? (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                       & (- (IData)((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU))))))
                    : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                        ? ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                            >> 0x0000001fU))) 
                                << 0x00000010U) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000010U))
                            : (((- (IData)((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata)))
                        : ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                >> 0x0000001fU))) 
                                    << 8U) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata)))))))
            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r);
    if (__VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0]) 
               | (IData)(__VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0));
    }
    if (__VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) 
                  << 0x00000018U));
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    __VdfgRegularize_h6e95ff9d_0_8 = ((0x23U == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)) 
                                      & (0U != (0x0000001fU 
                                                & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                                   >> 0x00000014U))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)
            ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                 == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x00000014U)))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                 == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x00000014U)))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                        >> 0x0000000fU))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15 = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16 = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17 = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    __VdfgRegularize_h6e95ff9d_0_13 = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_4 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | (0x23U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r = 0U;
    if (((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)) 
         & (0U != (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x00000014U))))) {
        if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i;
        } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        }
    }
    __VdfgRegularize_h6e95ff9d_0_18 = ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                       & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
                                          & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x00000014U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((0U 
                                                 != 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                     >> 0x0000000fU))) 
                                                & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
    __VdfgRegularize_h6e95ff9d_0_5 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | ((0x13U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr)))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
            & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
               & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                  & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                     == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x00000014U))))))
            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                   & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                      & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                         == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                            >> 0x00000014U))))))
                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                    & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                       & ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                          & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                             == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x00000014U))))))
                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : (((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                        & (IData)(__VdfgRegularize_h6e95ff9d_0_18))
                        ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                        : ((IData)(__VdfgRegularize_h6e95ff9d_0_18)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                            : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                   & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                      == (0x0000001fU 
                                          & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                             >> 0x00000014U)))))
                                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_13));
    __VdfgRegularize_h6e95ff9d_0_19 = ((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_13));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
           + (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
               ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
               : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                   ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                   : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                       ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                       : (((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14))
                           ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                           : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
                               ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                               : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                   ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                   : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r)))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
            & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : (((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                        & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                        ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                        : ((IData)(__VdfgRegularize_h6e95ff9d_0_19)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                            : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           ^ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           | vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           << (0x0000001fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           >> (0x0000001fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed 
        = VL_LTS_III(32, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           < vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((4U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                        = (1U & ((0x00000200U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                  ? (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i))
                                  : ((0x00000100U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                      ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i)
                                      : ((0x00000400U 
                                          & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                          ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed)
                                          : ((0x00000800U 
                                              & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                              ? (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                                              : ((0x00001000U 
                                                  & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                                  ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                                                  : 
                                                 ((1U 
                                                   & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                      >> 0x0000000dU)) 
                                                  && (1U 
                                                      & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned))))))))));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                         != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r))) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                            = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr
                                : ((IData)(4U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r));
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 3U)))) {
                        if ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
                            }
                        } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                = (0xfffffffeU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset);
                        }
                    }
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            if (((((((((0U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU))) 
                       | (2U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x0000000cU)))) 
                      | (3U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                      >> 0x0000000cU)))) 
                     | (7U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU)))) 
                    | (6U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x0000000cU)))) 
                   | (4U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                   >> 0x0000000cU)))) 
                  | (1U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x0000000cU)))) 
                 | (5U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                 >> 0x0000000cU))))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            }
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))) 
                                   | ((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)))))
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
        } else if ((2U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))) 
                                   | ((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)))))
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : ((0x00004000U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                   - vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i))));
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((4U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                 >> 3U)))) {
                if ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000040U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((0x00000080U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)
                            : 0U);
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 7U)) && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                              >> 3U)))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                        = ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                            : ((0x00000020U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((IData)(4U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)
                                : ((0x00000040U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                    : ((0x00000080U 
                                        & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                        ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i
                                        : 0U))));
                }
            }
        }
    }
}

void Vtb_seg_long_gap_check___024root___nba_sequent__TOP__2(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_sequent__TOP__2\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0;
    // Body
    __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = 0ULL;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = 0ULL;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = 0U;
    } else {
        __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
            = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2)
                ? ((0xc34fU == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))
                    ? 0U : (0x0000ffffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))))
                : 0U);
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
            = (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2) 
                & (0xc34fU == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms)))
                ? ((IData)(1U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin)
                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin);
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__LED;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = __Vdly__tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
}

void Vtb_seg_long_gap_check___024root___nba_comb__TOP__0(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_comb__TOP__0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x00000014U))]));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU))]));
    if ((0x00000040U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                                = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x1fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x14U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x00000014U))));
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        } else {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
    } else if ((0x00000020U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
            if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0xfffff000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o
                            : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                ? (0x0000001fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o)
                                : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else {
            if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((((0U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000cU))) 
                          || (1U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                           >> 0x0000000cU)))) 
                         || (2U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x0000000cU))))) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000fe0U 
                                                    & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x00000014U)) 
                                                   | (0x0000001fU 
                                                      & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                         >> 7U))));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (8U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                }
            }
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
    } else if ((0x00000010U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
        if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = (0xfffff000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            }
            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                    = ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U))
                        : ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x00000014U))
                            : (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U))));
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
    } else {
        if ((8U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((0x00004000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else if ((0x00002000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00001000U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U));
                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                }
            } else {
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en 
            = ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                 | ((0x13U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                    | ((3U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                       | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | (0x63U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
              | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i) 
                  | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                     | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                        | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2))))) 
              & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now))) 
           && ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)
                ? (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg)
                : (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i)));
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0;

void Vtb_seg_long_gap_check___024root___nba_comb__TOP__1(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_comb__TOP__1\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    if ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 8U));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x10U));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x18U));
    } else {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 4U));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x0cU));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x14U));
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x1cU));
    }
    __Vtableidx1 = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
        = Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
        = Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0
        [__Vtableidx2];
    __Vtableidx3 = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
        = Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0
        [__Vtableidx3];
    __Vtableidx4 = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
        = Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0
        [__Vtableidx4];
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffffffff00ULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | (IData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1)));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffc03ffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2)) 
              << 0x0000000aU));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fff00fffffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3)) 
              << 0x00000014U));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000c03fffffffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
              << 0x0000001eU));
}

void Vtb_seg_long_gap_check___024root___nba_sequent__TOP__3(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_sequent__TOP__3\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x0000003fffffffffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 6U)))) << 0x00000026U));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffcfffffffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 4U)))) << 0x0000001cU));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffff3ffffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 2U)))) << 0x00000012U));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffffcffULL & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans)))) 
              << 8U));
}

void Vtb_seg_long_gap_check___024root___nba_sequent__TOP__4(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___nba_sequent__TOP__4\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__LED = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
    } else if ((0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
        if ((0x80200040U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__LED 
                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
        }
        if ((0x80200040U != vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
            if ((0x80200020U != vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                if ((0x80200050U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                    if ((0x80000000U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 1U;
                    } else if ((0xffffffffU == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r)) {
                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((8U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            if ((0U == (7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                               << 0x00000018U);
                                    } else {
                                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (0x00ff0000U 
                                               & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                                  << 0x00000010U));
                                    }
                                } else if ((1U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ff00U 
                                           & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                              << 8U));
                                } else {
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x000000ffU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
                                }
                            } else if ((1U == (7U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0cU;
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                           << 0x00000010U);
                                } else {
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ffffU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
                                }
                            } else if ((2U == (7U & 
                                               (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0fU;
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                    = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i;
                            } else {
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                            }
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                        }
                    }
                }
            }
        }
    }
}

void Vtb_seg_long_gap_check___024root___eval_nba(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_nba\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_comb__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___nba_sequent__TOP__4(vlSelf);
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
    }
}

void Vtb_seg_long_gap_check___024root___timing_resume(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___timing_resume\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_seg_long_gap_check___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_seg_long_gap_check___024root___eval_phase__act(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_phase__act\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_seg_long_gap_check___024root___eval_triggers_vec__act(vlSelf);
    Vtb_seg_long_gap_check___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_seg_long_gap_check___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_seg_long_gap_check___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_seg_long_gap_check___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_seg_long_gap_check___024root___timing_resume(vlSelf);
        Vtb_seg_long_gap_check___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_seg_long_gap_check___024root___eval_phase__inact(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_phase__inact\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("new/tb_seg_long_gap_check.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_seg_long_gap_check___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_seg_long_gap_check___024root___eval_phase__nba(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_phase__nba\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_seg_long_gap_check___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_seg_long_gap_check___024root___eval_nba(vlSelf);
        Vtb_seg_long_gap_check___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_seg_long_gap_check___024root___eval(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_seg_long_gap_check___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("new/tb_seg_long_gap_check.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("new/tb_seg_long_gap_check.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_seg_long_gap_check___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("new/tb_seg_long_gap_check.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_seg_long_gap_check___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_seg_long_gap_check___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_seg_long_gap_check___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_seg_long_gap_check___024root___eval_debug_assertions(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_debug_assertions\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
