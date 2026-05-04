// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_first_seg_debug.h for the primary calling header

#include "Vtb_first_seg_debug__pch.h"

void Vtb_first_seg_debug___024root___timing_ready(Vtb_first_seg_debug___024root* vlSelf);

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_static(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_static\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_cpu_clk__0 
        = vlSelfRef.tb_first_seg_debug__DOT__w_cpu_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_50Mhz__0 
        = vlSelfRef.tb_first_seg_debug__DOT__w_clk_50Mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_rst__0 
        = vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst;
    Vtb_first_seg_debug___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_initial__TOP(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_initial__TOP\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_first_seg_debug__DOT__w_cpu_clk = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__w_clk_50Mhz = 0U;
    VL_READMEM_N(true, 32, 4096, 0, "sim/irom.mem"s
                 ,  &(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Mem_IROM__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[(0x0000ffffU 
                                                                                & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)] = 0U;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i);
    }
    VL_READMEM_N(true, 32, 65536, 0, "sim/dram.mem"s
                 ,  &(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_final(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_final\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_first_seg_debug___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_first_seg_debug___024root___eval_phase__stl(Vtb_first_seg_debug___024root* vlSelf);

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_settle(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_settle\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_first_seg_debug___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("new/tb_first_seg_debug.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_first_seg_debug___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_triggers_vec__stl(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_triggers_vec__stl\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_first_seg_debug___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_first_seg_debug___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_first_seg_debug___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_first_seg_debug___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_first_seg_debug__ConstPool__TABLE_h150c8023_0;

VL_ATTR_COLD void Vtb_first_seg_debug___024root___stl_sequent__TOP__0(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___stl_sequent__TOP__0\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    // Body
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata 
        = (((0x80200000U == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
             ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2)
             : ((0x80200004U == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                 ? (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
                            >> 0x00000020U)) : ((0x80200010U 
                                                 == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                 ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2)
                                                 : 
                                                ((0x80200020U 
                                                  == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                  ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                                                  : 0xdeadbeefU)))) 
           & (- (IData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    if ((0x00000010U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0x55U;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 8U));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x10U));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x18U));
    } else {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0xaaU;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 4U));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x0cU));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x14U));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x1cU));
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i 
        = ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
           & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
           + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r);
    __VdfgRegularize_h6e95ff9d_0_8 = ((0x23U == (0x0000007fU 
                                                 & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)) 
                                      & (0U != (0x0000001fU 
                                                & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                                   >> 0x00000014U))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r) 
           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                        >> 0x0000000fU))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15 = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16 = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17 = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                           >> 0x0000000fU)))));
    __VdfgRegularize_h6e95ff9d_0_13 = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_4 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | (0x23U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)
            ? ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                ? (((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                     ? (0x0000ffffU & ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                           >> 0x00000010U)
                                        : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata))
                     : (0x000000ffU & ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000018U)
                                            : (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000010U))
                                        : ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                               >> 8U)
                                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata)))) 
                   & (- (IData)((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000dU))))))
                : ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                    ? (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                       & (- (IData)((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU))))))
                    : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)
                        ? ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                            >> 0x0000001fU))) 
                                << 0x00000010U) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000010U))
                            : (((- (IData)((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata)))
                        : ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                >> 0x0000001fU))) 
                                    << 8U) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((1U 
                                                & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata)))))))
            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x0000003fffffffffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 6U)))) << 0x00000026U));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffcfffffffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 4U)))) << 0x0000001cU));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffff3ffffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 2U)))) << 0x00000012U));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffffcffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans)))) 
              << 8U));
    __Vtableidx1 = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
        = Vtb_first_seg_debug__ConstPool__TABLE_h150c8023_0
        [__Vtableidx1];
    __Vtableidx2 = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
        = Vtb_first_seg_debug__ConstPool__TABLE_h150c8023_0
        [__Vtableidx2];
    __Vtableidx3 = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
        = Vtb_first_seg_debug__ConstPool__TABLE_h150c8023_0
        [__Vtableidx3];
    __Vtableidx4 = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
        = Vtb_first_seg_debug__ConstPool__TABLE_h150c8023_0
        [__Vtableidx4];
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i) {
        if ((0x63U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction))) {
            if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                 [(0x0000007fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                                  >> 2U))])) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU))) 
                           << 0x0000000cU) | ((0x00000800U 
                                               & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                       >> 7U))))));
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                   + (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                   >> 0x0000001fU))) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                >> 0x00000014U)))));
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
        } else {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
        }
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                 == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x00000014U)))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U))))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2 
        = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
           & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
              & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                 == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x00000014U)))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst) 
           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
    __VdfgRegularize_h6e95ff9d_0_18 = ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                       & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r) 
                                          & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x00000014U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3 = ((0U 
                                                 != 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                     >> 0x0000000fU))) 
                                                & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
    __VdfgRegularize_h6e95ff9d_0_5 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | ((0x13U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr)))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffffffff00ULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | (IData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1)));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffc03ffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2)) 
              << 0x0000000aU));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fff00fffffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3)) 
              << 0x00000014U));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000c03fffffffULL & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
              << 0x0000001eU));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b 
        = ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
           & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2));
    if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction;
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
            & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
               & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                  & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                     == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x00000014U))))))
            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                   & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                      & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                         == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                            >> 0x00000014U))))))
                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                    & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                       & ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                          & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                             == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x00000014U))))))
                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : (((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                        & (IData)(__VdfgRegularize_h6e95ff9d_0_18))
                        ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                        : ((IData)(__VdfgRegularize_h6e95ff9d_0_18)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                            : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                   & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                      == (0x0000001fU 
                                          & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                             >> 0x00000014U)))))
                                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r))))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_13));
    __VdfgRegularize_h6e95ff9d_0_19 = ((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_13));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r = 0U;
    if (((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)) 
         & (0U != (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x00000014U))))) {
        if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r;
        } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i;
        } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        }
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x00000014U))]));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU))]));
    if ((0x00000040U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((0x00000010U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                                = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x1fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x14U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x00000014U))));
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        } else {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else if ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
                if ((1U & (~ vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        } else {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
    } else if ((0x00000020U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
            if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0xfffff000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & (~ vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                }
                if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o
                            : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                ? (0x0000001fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o)
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o));
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else {
            if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((((0U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000cU))) 
                          || (1U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                           >> 0x0000000cU)))) 
                         || (2U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x0000000cU))))) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000fe0U 
                                                    & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x00000014U)) 
                                                   | (0x0000001fU 
                                                      & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                         >> 7U))));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
            if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (8U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                }
            }
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
        }
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
    } else if ((0x00000010U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
        if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                        = (0xfffff000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            }
            if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                    = ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                        ? (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U))
                        : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                            ? (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x00000014U))
                            : (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U))));
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
        }
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
    } else {
        if ((8U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((4U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        } else if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else if ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x00000014U));
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                }
            } else {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
            }
        } else {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = 0U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
        }
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en 
            = ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                 | ((0x13U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                    | ((3U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                       | (0x67U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | (0x63U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
           + (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
               ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
               : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                   ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                   : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                       ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                       : (((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14))
                           ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                           : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
                               ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                               : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                   ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                   : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r)))))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
            & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : (((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                        & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                        ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                        : ((IData)(__VdfgRegularize_h6e95ff9d_0_19)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                            : (((IData)(__VdfgRegularize_h6e95ff9d_0_5) 
                                & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r))))));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        }
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 0U;
    if ((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i) 
               & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i) 
                 & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U)))))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
        }
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           ^ vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           | vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           << (0x0000001fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           >> (0x0000001fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed 
        = VL_LTS_III(32, vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i, vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned 
        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
           < vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst) 
           | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
              | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((4U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((8U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                            if ((0U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                               << 0x00000018U);
                                    } else {
                                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (0x00ff0000U 
                                               & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                                  << 0x00000010U));
                                    }
                                } else if ((1U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ff00U 
                                           & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                              << 8U));
                                } else {
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x000000ffU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
                                }
                            } else if ((1U == (7U & 
                                               (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0cU;
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i 
                                           << 0x00000010U);
                                } else {
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ffffU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i);
                                }
                            } else if ((2U == (7U & 
                                               (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0fU;
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i;
                            } else {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                            }
                        }
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                        = (1U & ((0x00000200U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                  ? (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i))
                                  : ((0x00000100U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                      ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i)
                                      : ((0x00000400U 
                                          & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                          ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed)
                                          : ((0x00000800U 
                                              & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                              ? (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                                              : ((0x00001000U 
                                                  & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                                  ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                                                  : 
                                                 ((1U 
                                                   & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                      >> 0x0000000dU)) 
                                                  && (1U 
                                                      & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned))))))))));
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                    if (((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                         != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r))) {
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                            = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr
                                : ((IData)(4U) + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r));
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 3U)))) {
                        if ((0x00000010U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)))) {
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
                            }
                        } else if ((0x00000020U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                = (0xfffffffeU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset);
                        }
                    }
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            if (((((((((0U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU))) 
                       | (2U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x0000000cU)))) 
                      | (3U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                      >> 0x0000000cU)))) 
                     | (7U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU)))) 
                    | (6U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x0000000cU)))) 
                   | (4U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                   >> 0x0000000cU)))) 
                  | (1U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x0000000cU)))) 
                 | (5U == (7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                 >> 0x0000000cU))))) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            }
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))) 
                                   | ((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)))))
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
        } else if ((2U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))) 
                                   | ((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)))))
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : ((0x00004000U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i 
                                   - vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)
                                : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i))));
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((4U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            } else if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                 >> 3U)))) {
                if ((0x00000010U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000020U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000040U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((0x00000080U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)
                            : 0U);
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 7U)) && (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                              >> 3U)))) {
                    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                        = ((0x00000010U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                            : ((0x00000020U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((IData)(4U) + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)
                                : ((0x00000040U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                    : ((0x00000080U 
                                        & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                        ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i
                                        : 0U))));
                }
            }
        }
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) 
           | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold 
        = ((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)) 
           & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i 
        = ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i) 
                  | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                     | ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                        | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2))))) 
              & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i)));
    vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o 
        = ((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now))) 
           && ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)
                ? (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg)
                : (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i)));
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root____Vm_traceActivitySetAll(Vtb_first_seg_debug___024root* vlSelf);

VL_ATTR_COLD void Vtb_first_seg_debug___024root___eval_stl(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_stl\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_first_seg_debug___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_first_seg_debug___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_first_seg_debug___024root___eval_phase__stl(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___eval_phase__stl\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_first_seg_debug___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_first_seg_debug___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_first_seg_debug___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_first_seg_debug___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_first_seg_debug___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_first_seg_debug___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_first_seg_debug___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_first_seg_debug.w_cpu_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_first_seg_debug.w_clk_50Mhz)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_first_seg_debug.w_clk_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_first_seg_debug___024root____Vm_traceActivitySetAll(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root____Vm_traceActivitySetAll\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
    vlSelfRef.__Vm_traceActivity[5U] = 1U;
    vlSelfRef.__Vm_traceActivity[6U] = 1U;
    vlSelfRef.__Vm_traceActivity[7U] = 1U;
    vlSelfRef.__Vm_traceActivity[8U] = 1U;
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root___ctor_var_reset(Vtb_first_seg_debug___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root___ctor_var_reset\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_first_seg_debug__DOT__w_cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2096685516769942965ull);
    vlSelf->tb_first_seg_debug__DOT__w_clk_50Mhz = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14696743181613534990ull);
    vlSelf->tb_first_seg_debug__DOT__w_clk_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2861698120984497666ull);
    vlSelf->tb_first_seg_debug__DOT__virtual_key = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2754381244986831313ull);
    vlSelf->tb_first_seg_debug__DOT__virtual_sw = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6262507094081350924ull);
    vlSelf->tb_first_seg_debug__DOT__cycle_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17324247868484086324ull);
    vlSelf->tb_first_seg_debug__DOT__hist_wr_ptr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6248216501405555031ull);
    vlSelf->tb_first_seg_debug__DOT__hist_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2911751314001733190ull);
    vlSelf->tb_first_seg_debug__DOT__j = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10927031361299084028ull);
    vlSelf->tb_first_seg_debug__DOT__slot = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4541551039949383679ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_pc[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 836299391755438671ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_inst[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10809493590976192698ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_ifid[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8609942506085134253ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_idex[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17191383131561714130ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_exmem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6393713190640493740ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_mem1[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17423047235724105338ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_mem12[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11530460697037565783ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_mem2a[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 44787769119242806ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_mem2b[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13006096698594510761ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_mem2[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10834289525667680399ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_hold[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3230928108345442742ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_hflush[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14835809099394104021ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_ifflush[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8741145664869611621ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_idflush[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10798493649781517493ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_fop1[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1687653329143114652ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_fop2[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14663570632759542800ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wbwen[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15529520111119243238ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wbaddr[__Vi0] = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 18422368735443172303ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wbdata[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18104567331127318551ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_x8[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9686694315436700117ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_x10[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7565277481166720941ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_x14[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16593480512488488031ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_x15[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5549933962992262537ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_seg[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9215243623102724266ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_rd_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9418359595377777567ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_rd_req[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 916430831685096173ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_rd_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2919364042885070133ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wr_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15697508081620158327ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wr_strb[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11220684944021542250ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__hist_wr_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3510931928378553311ull);
    }
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14268990475826284431ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7520055563905396541ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__perip_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11001455707219034574ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8531734365357313794ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4324706661664575222ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 826615954760260296ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9002707140236326831ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5031310080681167460ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7078380530799799720ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6624868390982592191ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2310384214051878941ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8525127675814018667ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6264765013271669664ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4785292866865599712ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10865634517041620375ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9176802582272550123ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7956932963718372595ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1867172978103132691ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3896542428104053212ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9679910813930102543ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6858953311022472807ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 15229213104421440365ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12052028091588141495ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5302242144025291285ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16487312398826698279ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17880184200274276484ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1414693967580274857ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13294763021342283317ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6894844718655358113ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 457197824728912272ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9124656809381460350ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9250643842405798982ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14114792305727216539ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10309855674929383119ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12459864511370859914ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4794271740504203082ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4660719150097333592ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16206982102205574339ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8633437712885453145ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6162091143444173256ull);
    }
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14279902334725300912ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10027086642956405205ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10687188488673445901ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11678631401673453417ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2064602171491748421ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9877427372664415781ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8563117879445543080ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7155857633245185708ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10889654969605720548ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17140545039698560389ull);
    }
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16134929388872240159ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8659317409892474883ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1391705309328880480ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2297188286729826511ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 872854699406764485ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14707786171573308361ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4805258291116748613ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9243155248794109968ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2061597186694714224ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5521138107452631521ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 13764403526637352041ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10418244910459814237ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17494270859023653144ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14287158068349400140ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8817284127812430100ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8030892302526868397ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18180288045211675797ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9972513464657488809ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15769910562452688996ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3433021250794662257ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15511978196476375329ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17751072990907322482ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6040933113963585072ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17531917316618154788ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2095186014420804875ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1384622744062418885ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11232925012564058408ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17957639006861689033ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2328040608852104284ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 434397042888946310ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7053964862641045198ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17272813480581687296ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11280525302206617014ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2588030333197207523ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 705073470358617264ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 917868356583658797ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2649884490450086401ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7305916502661376278ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 201762443394073293ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6062799969825028676ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5426891139125790419ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2581719127391617100ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15096183055023577002ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 701451818517605539ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1155758054514447325ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2838407900144023680ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3269131698879900232ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12665658452131377898ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10410302435786557774ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16139072739567419905ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8762164172219682380ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14641749588845106886ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13126521455811974179ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16170787134167431805ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1182873590287129665ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11518254709486176147ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17316487069866911393ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9734139904104080814ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1384837407701626822ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2987082999893496933ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4227875301409495327ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2699472836191343302ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5572095237686499799ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13098724660496954249ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9045076548756105461ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2232986796312544902ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10355570133881037125ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3102677011416190264ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12829218052341655754ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10459549788068589785ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4822211837092846391ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__dut__DOT__Mem_IROM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14029918833858536408ull);
    }
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__LED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2130046713721879282ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16338594808083778938ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8428198478135418343ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4112727608701564686ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4912140096448866506ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14733955876730580900ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2359089494558939775ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6889640308235776535ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3178232473840754051ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7763495684686538077ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 3507980513888317774ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6531000595002815497ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1191514916792187195ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15216096589530897186ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0;
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = 0;
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = 0;
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = 0;
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = 0;
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15813708296482343406ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 794843726092239053ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 8813725743914204928ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 17580494274459222364ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10428057010456901375ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12836401123230623894ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13055277871251897888ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6750297438819118360ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3556608194568081366ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2803006862758386522ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11333580278644713628ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12500664349048457936ull);
    }
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3607310169689682711ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8589318175271457380ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10337312952109721048ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15788404794787327474ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16064620846081707485ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2664077461722741659ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6977811348301555044ull);
    vlSelf->tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2904313687787413850ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_3 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_12 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_14 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_15 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_16 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_17 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_cpu_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_50Mhz__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_first_seg_debug__DOT__w_clk_rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
