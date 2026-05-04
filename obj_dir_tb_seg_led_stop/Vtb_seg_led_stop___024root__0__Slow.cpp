// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_seg_led_stop.h for the primary calling header

#include "Vtb_seg_led_stop__pch.h"

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_static(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_static\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_cpu_clk__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_50Mhz__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_rst__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_initial__TOP(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial__TOP\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0;
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz = 0U;
    VL_READMEM_N(true, 32, 4096, 0, "sim/irom.mem"s
                 ,  &(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem)
                 , 0, ~0ULL);
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[(0x0000ffffU 
                                                                                & tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)] = 0U;
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i 
            = ((IData)(1U) + tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i);
    }
    VL_READMEM_N(true, 32, 65536, 0, "sim/dram.mem"s
                 ,  &(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_final(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_final\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_led_stop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_seg_led_stop___024root___eval_phase__stl(Vtb_seg_led_stop___024root* vlSelf);

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_settle(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_settle\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_seg_led_stop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("new/tb_seg_led_stop.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_seg_led_stop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_triggers_vec__stl(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_triggers_vec__stl\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_seg_led_stop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_led_stop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_seg_led_stop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_seg_led_stop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0;

VL_ATTR_COLD void Vtb_seg_led_stop___024root___stl_sequent__TOP__0(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___stl_sequent__TOP__0\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__perip_rdata;
    tb_seg_led_stop__DOT__dut__DOT__perip_rdata = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0;
    CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i = 0;
    CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_20;
    __VdfgRegularize_h6e95ff9d_0_20 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_21;
    __VdfgRegularize_h6e95ff9d_0_21 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_22;
    __VdfgRegularize_h6e95ff9d_0_22 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_23;
    __VdfgRegularize_h6e95ff9d_0_23 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_24;
    __VdfgRegularize_h6e95ff9d_0_24 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_25;
    __VdfgRegularize_h6e95ff9d_0_25 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_27;
    __VdfgRegularize_h6e95ff9d_0_27 = 0;
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                        >> 0x0000000fU))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_29 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_30 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x0000000fU)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0U;
    if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0x55U;
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 8U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x10U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x18U));
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0xaaU;
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 4U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x0cU));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x14U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x1cU));
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x00000014U))]));
    __VdfgRegularize_h6e95ff9d_0_27 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                 >> 0x0000000fU))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx 
        = (0x0000001fU & (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r) 
                           - (IData)(1U)) | (- (IData)(
                                                       (0U 
                                                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU))]));
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                                = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                >> 0x1fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                 >> 0x14U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x00000014U))));
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 4U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 4U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    } else if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                    = ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                        ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o
                            : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                                ? (0x0000001fU & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o)
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                    >> 0x0000000cU))) 
                      || (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x0000000cU)))) 
                     || (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x0000000cU))))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x1fU))) 
                            << 0x0000000cU) | ((0x00000fe0U 
                                                & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U)) 
                                               | (0x0000001fU 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                     >> 7U))));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
    } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
        if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o);
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                    = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                        ? (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                               >> 0x00000014U))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                              >> 0x00000014U))
                            : (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U))));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
    } else {
        if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                               >> 0x00000014U));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        }
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx 
        = (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r) 
                          ^ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                             >> 2U)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid 
        = (IData)(((0x00000067U == (0x0000707fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                   & (((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)) 
                       & (~ (((1U == (0x0000001fU & 
                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 7U))) | (5U 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                       >> 7U)))) 
                             & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 7U)) 
                                == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                   >> 0x0000000fU)))))) 
                      & ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x0000000fU))) 
                         | (5U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                  >> 0x0000000fU)))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | (0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint 
        = (IData)((0x00000067U == (0x0000707fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link 
        = ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 7U))) | (5U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                  >> 7U))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
    __VdfgRegularize_h6e95ff9d_0_19 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_22 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x0000000fU)))));
    __VdfgRegularize_h6e95ff9d_0_23 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x0000000fU)))));
    __VdfgRegularize_h6e95ff9d_0_20 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_8 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | (0x23U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)))));
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata 
        = (((0x80200000U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
             ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2)
             : ((0x80200004U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                 ? (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
                            >> 0x00000020U)) : ((0x80200010U 
                                                 == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                 ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2)
                                                 : 
                                                ((0x80200020U 
                                                  == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                  ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                                                  : 0xdeadbeefU)))) 
           & (- (IData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))));
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o 
                        = (0x0000003fU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_ghr__DOT__data_r));
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            if (((((((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU))) 
                       | (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x0000000cU)))) 
                      | (3U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                      >> 0x0000000cU)))) 
                     | (7U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU)))) 
                    | (6U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x0000000cU)))) 
                   | (4U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                   >> 0x0000000cU)))) 
                  | (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x0000000cU)))) 
                 | (5U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                 >> 0x0000000cU))))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                 >> 3U)))) {
                if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000040U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((0x00000080U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)
                            : 0U);
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 7U)) && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx 
        = (0x0000003fU & ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o) 
                          ^ (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                             >> 2U)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x0000003fffffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 6U)))) << 0x00000026U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffcfffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 4U)))) << 0x0000001cU));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffff3ffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 2U)))) << 0x00000012U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffffcffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans)))) 
              << 8U));
    __Vtableidx1 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx1];
    __Vtableidx2 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx2];
    __Vtableidx3 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx3];
    __Vtableidx4 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx4];
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x00000014U))) 
                                                 & ((0x23U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                                                    | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x0000000fU))) 
                                                 & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x0000000fU))) 
                                                 & ((0x13U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                                                    | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                                                       | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | ((0x13U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                 | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
           & (0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint) 
           & ((~ ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
                  & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000fU)) 
                     == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 7U))))) 
              & ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000fU))) 
                 | (5U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000fU))))));
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    __VdfgRegularize_h6e95ff9d_0_24 = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x00000014U)))));
    tb_seg_led_stop__DOT__dut__DOT__perip_rdata = (
                                                   ((0x80200000U 
                                                     == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                     ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                     : 
                                                    ((0x80200004U 
                                                      == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                      ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                      : 
                                                     ((0x80200010U 
                                                       == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                       ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                       : 
                                                      ((0x80200020U 
                                                        == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                        ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                        : 
                                                       ((0x80200050U 
                                                         == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                                                         : 
                                                        (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                         & (- (IData)(
                                                                      ((0x80100000U 
                                                                        <= vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr) 
                                                                       & (0x8013ffffU 
                                                                          > vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)))))))))) 
                                                   & (- (IData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    __VdfgRegularize_h6e95ff9d_0_7 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
    __VdfgRegularize_h6e95ff9d_0_9 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | ((0x13U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                               | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffffffff00ULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | (IData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffc03ffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2)) 
              << 0x0000000aU));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fff00fffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3)) 
              << 0x00000014U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000c03fffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
              << 0x0000001eU));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_31 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                                                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x00000014U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_28 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_27));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_32 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_27));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (8U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) {
        if ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            if ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid
                       [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx]
                        ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                           [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx] 
                           >> 1U) : (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                     >> 0x0000001fU)))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU))) 
                           << 0x0000000cU) | ((0x00000800U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                       >> 7U))))));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                   + (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                   >> 0x0000001fU))) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x00000014U)))));
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
        } else if ((0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras
                    [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx];
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
        }
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)) 
              & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                 | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
        = (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_valid_r) 
               & ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r)) 
                  & ((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r 
                      >> 2U) == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 >> 2U))))) ? ((((0x0000ff00U 
                                                  & (((8U 
                                                       & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                       ? 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                       >> 0x00000018U)
                                                       : 
                                                      (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                       >> 0x00000018U)) 
                                                     << 8U)) 
                                                 | (0x000000ffU 
                                                    & ((4U 
                                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                        ? 
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                        >> 0x00000010U)
                                                        : 
                                                       (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                        >> 0x00000010U)))) 
                                                << 0x00000010U) 
                                               | ((0x0000ff00U 
                                                   & (((2U 
                                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                        ? 
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                        >> 8U)
                                                        : 
                                                       (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                        >> 8U)) 
                                                      << 8U)) 
                                                  | (0x000000ffU 
                                                     & ((1U 
                                                         & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r
                                                         : tb_seg_led_stop__DOT__dut__DOT__perip_rdata))))
            : tb_seg_led_stop__DOT__dut__DOT__perip_rdata);
    __VdfgRegularize_h6e95ff9d_0_21 = ((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_20));
    __VdfgRegularize_h6e95ff9d_0_25 = ((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_20));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o) 
                                                 & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)
            ? ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                ? (((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                     ? (0x0000ffffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                           >> 0x00000010U)
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i))
                     : (0x000000ffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 0x00000018U)
                                            : (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 0x00000010U))
                                        : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 8U)
                                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))) 
                   & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000dU))))))
                : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                    ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                       & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU))))))
                    : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                        ? ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                            >> 0x0000001fU))) 
                                << 0x00000010U) | (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x00000010U))
                            : (((- (IData)((1U & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))
                        : ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                >> 0x0000001fU))) 
                                    << 8U) | (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))))))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = (1U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                 | ((~ ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)) 
                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o))) 
                    | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
              & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
           + (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
               & (IData)(__VdfgRegularize_h6e95ff9d_0_23))
               ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
               : (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                   & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                   ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                   : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                       & (IData)(__VdfgRegularize_h6e95ff9d_0_21))
                       ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                       : ((IData)(__VdfgRegularize_h6e95ff9d_0_21)
                           ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                           : (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                               & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                               ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                               : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_23))
            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                    & (IData)(__VdfgRegularize_h6e95ff9d_0_25))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : ((IData)(__VdfgRegularize_h6e95ff9d_0_25)
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                        : (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                            & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
               & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                  & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                     == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x00000014U))))))
            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                   & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                      & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                         == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                            >> 0x00000014U))))))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                    & (IData)(__VdfgRegularize_h6e95ff9d_0_24))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : ((IData)(__VdfgRegularize_h6e95ff9d_0_24)
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                        : (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                  == (0x0000001fU & 
                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U)))))
                            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           ^ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           | vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           << (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           >> (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed 
        = VL_LTS_III(32, tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           < vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 3U)))) {
                            if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                        = ((IData)(4U) 
                                           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r);
                                }
                            } else if ((0x00000020U 
                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                        = ((IData)(4U) 
                                           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r);
                                }
                            }
                            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                          >> 4U)))) {
                                if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 1U;
                                    }
                                }
                            }
                        }
                        if ((8U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                            if ((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                               << 0x00000018U);
                                    } else {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (0x00ff0000U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                                  << 0x00000010U));
                                    }
                                } else if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ff00U 
                                           & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                              << 8U));
                                } else {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x000000ffU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
                                }
                            } else if ((1U == (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0cU;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                           << 0x00000010U);
                                } else {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ffffU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
                                }
                            } else if ((2U == (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0fU;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o;
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                            }
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                        = (1U & ((0x00000200U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                  ? (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i))
                                  : ((0x00000100U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                      ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i)
                                      : ((0x00000400U 
                                          & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                          ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed)
                                          : ((0x00000800U 
                                              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                              ? (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                                              : ((0x00001000U 
                                                  & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                                  ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                                                  : 
                                                 ((1U 
                                                   & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                      >> 0x0000000dU)) 
                                                  && (1U 
                                                      & (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned))))))))));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                    if (((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                         != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                            = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr
                                : ((IData)(4U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r));
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 3U)))) {
                        if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
                            }
                        } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                = (0xfffffffeU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset);
                            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                if ((1U & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)) 
                                           | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_target__DOT__data_r 
                                              != (0xfffffffeU 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset))))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                   | ((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
        } else if ((2U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                   | ((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                   - vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i))));
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                              >> 3U)))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                        = ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                            : ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((IData)(4U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)
                                : ((0x00000040U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                    ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                    : ((0x00000080U 
                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                        ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o
                                        : 0U))));
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
           | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40) 
              | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                  | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                     | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
                        | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))))) 
              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o));
}

VL_ATTR_COLD void Vtb_seg_led_stop___024root___eval_stl(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_stl\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_seg_led_stop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_seg_led_stop___024root___eval_phase__stl(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_phase__stl\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_seg_led_stop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_seg_led_stop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_seg_led_stop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_seg_led_stop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_seg_led_stop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_led_stop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_seg_led_stop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_seg_led_stop.w_cpu_clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tb_seg_led_stop.w_clk_50Mhz)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge tb_seg_led_stop.w_clk_rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_seg_led_stop___024root___ctor_var_reset(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___ctor_var_reset\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_seg_led_stop__DOT__w_cpu_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8176671035332608653ull);
    vlSelf->tb_seg_led_stop__DOT__w_clk_50Mhz = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9483109462717398319ull);
    vlSelf->tb_seg_led_stop__DOT__w_clk_rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13397577949722692208ull);
    vlSelf->tb_seg_led_stop__DOT__virtual_key = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4873129540731749878ull);
    vlSelf->tb_seg_led_stop__DOT__virtual_sw = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13683870531445366838ull);
    vlSelf->tb_seg_led_stop__DOT__cycle_count = 0;
    vlSelf->tb_seg_led_stop__DOT__seg_write_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15017090613960990560ull);
    vlSelf->tb_seg_led_stop__DOT__led_write_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5414827184066155012ull);
    vlSelf->tb_seg_led_stop__DOT__same_pc_count = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12609444767516393795ull);
    vlSelf->tb_seg_led_stop__DOT__prev_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10921961571402474808ull);
    vlSelf->tb_seg_led_stop__DOT__second_seg_cycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4675671880958195871ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14179022581456756298ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13724958502840241795ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7221316966976452619ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6529874506821681317ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 948686903873698010ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10869817739270191688ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5529743341654717304ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5185928688947435002ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3111738740278296080ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3867366153237480781ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6288127080420791650ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11472067611522454157ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 5036910716368899101ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6244738715004512327ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13749584824095812160ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16666316173664856495ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5731439145235365239ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1624262563087252652ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3261807324032754333ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 7189554018235649509ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9431111924637021057ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10159472477725313558ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14045317214214076316ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3381920463577814500ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1149332926919830544ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8339168196096576382ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7977242442600398659ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 974111761018371100ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16895438162476654963ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2668966555184242919ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4876442756620786773ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11922162389658461530ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13762275924520088851ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9758966467627452959ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4951456430792755480ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3497873293012016956ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18115074767981161114ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4256956871652085362ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2146115715330917578ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10303832338807718122ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17211651097612929823ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1649237972347719668ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6727897001020877490ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4240713820444243804ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9828685064129232937ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 555348674231645601ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12511129930237908524ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i = 0;
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18121401061437840018ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5766645085115803276ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7207562809532905676ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16710457904274712685ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o = 0;
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9550915633978747996ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2957178069351308095ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 16893400197375899967ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5646279738573997669ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12149679177970947761ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10583382702675581032ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16876175251765805296ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 612301454546434147ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 18241261620918769320ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5038517763427473552ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12126466536756405394ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12562489915392661451ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17981984378601124058ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15614041637089324455ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15887118205425793081ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3043858197233742394ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5518265068145296716ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16045980072286235995ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8589992130499822752ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1384089002189702492ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10010371181117160983ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13622706281927279044ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_target__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7679183178653711264ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_ghr__DOT__data_r = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6153054936226557227ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5160676890947616422ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16791236990325498061ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 62948753202879398ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3046814723070847176ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14887998937094023863ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r = VL_SCOPED_RAND_RESET_I(15, __VscopeHash, 12978039204597280920ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17486415817332424004ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15761580245691952077ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11759317462496235431ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3856559112753841666ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7089902680048601502ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 453950953509201074ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18411618944350874422ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5370476905097663039ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12227461780566648380ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13520594031428421659ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2961118412156434971ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17995553406886002359ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8058053350395739683ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9454305913285295800ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3181604615331785806ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17667880751955965064ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17060738753938805055ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6983147894595889840ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10196739922193004061ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4527552786799042009ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1471804856298116828ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10009051570663842700ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4664256887565270957ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1394056144597248954ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6747425258539009254ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1914117875846123767ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1454132999076385377ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9297947862135316075ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7752973167221059292ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4219194306195208527ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7097346170959150808ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1666475572525437016ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14767285776326073287ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7218541441738389245ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11326547403443602945ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8185899325550301606ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8307950485393962086ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12987636489371292051ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10570593319362075174ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 11270329945646578547ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10473207328143519706ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15196821035006782544ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5826593130283306550ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0;
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10022549625086802246ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10624134226578694088ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 12996559060982348013ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 5414838344012094271ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6843708787335418384ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10000678768995069884ull);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 748789524594126755ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9654412028473257297ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13799009674619580260ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6493518769172426386ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12126518395718246118ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16114983742858971465ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15087892575159708467ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4323033356288733463ull);
    vlSelf->__VdfgRegularize_h6e95ff9d_0_10 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_11 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_12 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_26 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_28 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_29 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_30 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_31 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_32 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_40 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_cpu_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_50Mhz__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
