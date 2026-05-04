// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_seg_long_gap_check.h for the primary calling header

#include "Vtb_seg_long_gap_check__pch.h"

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_static(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_static\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_cpu_clk__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_50Mhz__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_rst__0 
        = vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_initial__TOP(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_initial__TOP\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz = 0U;
    VL_READMEM_N(true, 32, 4096, 0, "sim/irom.mem"s
                 ,  &(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Mem_IROM__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[(0x0000ffffU 
                                                                                & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)] = 0U;
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i);
    }
    VL_READMEM_N(true, 32, 65536, 0, "sim/dram.mem"s
                 ,  &(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_final(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_final\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_seg_long_gap_check___024root___eval_phase__stl(Vtb_seg_long_gap_check___024root* vlSelf);

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_settle(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_settle\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_seg_long_gap_check___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("new/tb_seg_long_gap_check.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_seg_long_gap_check___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_triggers_vec__stl(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_triggers_vec__stl\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_seg_long_gap_check___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_seg_long_gap_check___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_seg_long_gap_check___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_seg_long_gap_check__ConstPool__TABLE_h150c8023_0;

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___stl_sequent__TOP__0(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___stl_sequent__TOP__0\n"); );
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
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
    if ((0x00000010U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0x55U;
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
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0xaaU;
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr 
        = (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
           + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r);
    __VdfgRegularize_h6e95ff9d_0_8 = ((0x23U == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)) 
                                      & (0U != (0x0000001fU 
                                                & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                                   >> 0x00000014U))));
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))));
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b 
        = ((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
           & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2));
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) 
           | ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
              | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)));
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
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((8U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
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
                        }
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
    vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
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

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root____Vm_traceActivitySetAll(Vtb_seg_long_gap_check___024root* vlSelf);

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___eval_stl(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_stl\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_seg_long_gap_check___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_seg_long_gap_check___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_seg_long_gap_check___024root___eval_phase__stl(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___eval_phase__stl\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_seg_long_gap_check___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_seg_long_gap_check___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_seg_long_gap_check___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_seg_long_gap_check___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_seg_long_gap_check___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_seg_long_gap_check___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_seg_long_gap_check.w_cpu_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_seg_long_gap_check.w_clk_50Mhz)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_seg_long_gap_check.w_clk_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root____Vm_traceActivitySetAll(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root____Vm_traceActivitySetAll\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

VL_ATTR_COLD void Vtb_seg_long_gap_check___024root___ctor_var_reset(Vtb_seg_long_gap_check___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root___ctor_var_reset\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_seg_long_gap_check__DOT__w_cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 684807886255432360ull);
    vlSelf->tb_seg_long_gap_check__DOT__w_clk_50Mhz = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12242785625155467996ull);
    vlSelf->tb_seg_long_gap_check__DOT__w_clk_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3363978300797403623ull);
    vlSelf->tb_seg_long_gap_check__DOT__virtual_key = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14720738537689855405ull);
    vlSelf->tb_seg_long_gap_check__DOT__virtual_sw = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14356222002707717647ull);
    vlSelf->tb_seg_long_gap_check__DOT__seg_write_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1657946417808951708ull);
    vlSelf->tb_seg_long_gap_check__DOT__first_seg_time = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15061900993354729343ull);
    vlSelf->tb_seg_long_gap_check__DOT__second_seg_time = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1344572947521293084ull);
    vlSelf->tb_seg_long_gap_check__DOT__first_seg_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4518074001678095326ull);
    vlSelf->tb_seg_long_gap_check__DOT__second_seg_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9638947642338436361ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 143499412752015039ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2509281919804458338ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3542132601279278427ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11478349387592962448ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15178415238987367277ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16008905445341389848ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14605621368117082721ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2232021632225370786ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1030327686940359987ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17765706210447249895ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16190790776696383247ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10402966360862204459ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 783671111251852298ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 375660290692141301ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 565451340815284025ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8521934557356154240ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16577133336944144793ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2154889526182015758ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16139288729223913519ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4380091670163602270ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10220517789067245130ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 13807964060046133749ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13145985783622657203ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12524388904846458136ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2794289862492465573ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9377401308029992300ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18271484547609467681ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3606952506148978434ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4518409696478038263ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10399993267369290660ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11388097038519703372ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11309054639564914359ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17638965498498269509ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2922771939004403658ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13053856468787379649ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5439880110105425087ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15965513096083908534ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7506316565342786589ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12625176289162196163ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 27373309083167615ull);
    }
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 256527557861788294ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10292778699221927973ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4545404121898108712ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11146600817078878794ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18188476869132873113ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6995664928893824049ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5740626033372673286ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5627780615455520816ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8848818808742046092ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11084348853819362683ull);
    }
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8602134453035591154ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15420574285678244195ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13012742654801242525ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10452904402764703284ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15539859206352488231ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 9282410924637782865ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3758884130353705517ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6267130894344971831ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14590703829737044272ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15697320392268815271ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 9806458201073203731ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7105157367811028135ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9537442714333786840ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3153795452311708340ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5699017196715360899ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2928912987683014151ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10462398632154572395ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2686278178986433919ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15591625844971171479ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4316398041929580704ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4423948287488156663ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18404606983096133093ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18034336734219053440ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12205979315645294713ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7477935050390736468ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2647375751783122985ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6525408057966187362ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7899749457095945829ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16173918056412034877ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11243748210260370943ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2321297995034952999ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6851221857303770893ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8511566358526720227ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16145507248458547948ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4943506288417649438ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2761466205694371406ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6063207953210914082ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4090576141525504170ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15011462191670985592ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14567504491735146716ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12334029556170046183ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11872194206146656633ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14722023248910508838ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8343313985989575829ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10119005846250906711ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11927634474971935900ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1808947988967316315ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 68036711144716196ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12732999966488402348ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3041510284401625370ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12124073130096525563ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12490527538226698623ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7404779426958640192ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17112532720149177565ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12912699745226213629ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8384953895100539054ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4485088133162357605ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15953779572554979323ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6304322633075636884ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3624740210836499441ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14392119756095779665ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17373598853810700408ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1443200097206827419ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16813437045531668324ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14998565574545531734ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6455301638400699968ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4178392631583354982ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2353662381508337859ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9388482174493110898ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11059497054894761978ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6727939368407693818ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__Mem_IROM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2169085467366798681ull);
    }
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__LED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10388506083227333803ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2634528971149936746ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1163323120571858227ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8192073449324968053ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4060695412864555547ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4617126370635901843ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14140356604764402661ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5599047027882629338ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13713334275261573960ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5438305225003402498ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 3170897550831268531ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6700757703522930588ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6202286860982423082ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5832811002230604986ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0;
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = 0;
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = 0;
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = 0;
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = 0;
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14253386255288092929ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3464006556938682615ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 9292366512104486390ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 6726395705350827513ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8739687077123988107ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12230927398306467624ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15600812895660097585ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13381609106143645711ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14000559407347125056ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5225018905628345964ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9601267987985022709ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6323678599799213416ull);
    }
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 24161003284145732ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2018917102793456085ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16165741547220887565ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 348858402935165769ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1611487466108280528ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7252896732250093995ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8167911480717449184ull);
    vlSelf->tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12394136435300450010ull);
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
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_cpu_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_50Mhz__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_long_gap_check__DOT__w_clk_rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
