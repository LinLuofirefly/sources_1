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
    VL_READMEM_N(true, 32, 4096, 0, "C:/Users/hp/Downloads/demo1/withMext/demo/irom-new.mem"s
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
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_idex;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_idex = 0;
    SData/*8:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx = 0;
    CData/*2:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel = 0;
    CData/*2:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel = 0;
    CData/*2:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel = 0;
    CData/*2:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_dep_match;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_dep_match = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_load_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_load_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_load_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_load_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_load_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_load_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_slow_load_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_slow_load_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_slow_load_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_slow_load_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__control_late_dep;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__control_late_dep = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_signed;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_signed = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_unsigned;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_unsigned = 0;
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
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr = 0;
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
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract = 0;
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
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_2;
    __VdfgRegularize_h6e95ff9d_0_2 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_3;
    __VdfgRegularize_h6e95ff9d_0_3 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_4;
    __VdfgRegularize_h6e95ff9d_0_4 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_12;
    __VdfgRegularize_h6e95ff9d_0_12 = 0;
    IData/*31:0*/ __VdfgRegularize_h6e95ff9d_0_13;
    __VdfgRegularize_h6e95ff9d_0_13 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_14;
    __VdfgRegularize_h6e95ff9d_0_14 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_15;
    __VdfgRegularize_h6e95ff9d_0_15 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_16;
    __VdfgRegularize_h6e95ff9d_0_16 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_17;
    __VdfgRegularize_h6e95ff9d_0_17 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_18;
    __VdfgRegularize_h6e95ff9d_0_18 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_20;
    __VdfgRegularize_h6e95ff9d_0_20 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_21;
    __VdfgRegularize_h6e95ff9d_0_21 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_22;
    __VdfgRegularize_h6e95ff9d_0_22 = 0;
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op 
        = ((6U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (7U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx 
        = (0x000001ffU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o) 
                          ^ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o 
                             >> 2U)));
    if ((1U & (~ VL_ONEHOT_I(((((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr) 
                                << 4U) | (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr) 
                                           << 3U) | 
                                          ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr) 
                                           << 2U))) 
                              | (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr) 
                                  << 1U) | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr))))))) {
        if ((0U != ((((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr) 
                      << 4U) | (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr) 
                                 << 3U) | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr) 
                                           << 2U))) 
                    | (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr) 
                        << 1U) | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr))))) {
            if (VL_UNLIKELY((vlSymsp->_vm_contextp__->assertOn()))) {
                VL_WRITEF_NX("[%0t] %%Error: perip_bridge.sv:151: Assertion failed in %m: unique case, but multiple matches found for '1'h1'\n",3, 'M',vlSymsp->name(),"tb_seg_led_stop.dut.bridge_inst", 'T',-9
                             , '#',64,VL_TIME_UNITED_Q(1000));
                VL_STOP_MT("new/perip_bridge.sv", 151, "");
            }
        }
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_idex 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_next 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_r 
           + (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_multiplicand_r 
              & (- (QData)((IData)((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_multiplier_r))))));
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
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx 
        = (0x0000001fU & (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r) 
                           - (IData)(1U)) | (- (IData)(
                                                       (0U 
                                                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div 
        = ((4U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (6U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
           >= (QData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x0000000fU))]));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_pop 
        = (IData)(((0x00008067U == (0x000ff07fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                   & (~ (IData)(((0x00000080U == (0x00000f80U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                                 & ((0x0000001fU & 
                                     (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                      >> 7U)) == (0x0000001fU 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                     >> 0x0000000fU))))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                     >> 0x00000014U))]));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx 
        = (0x000001ffU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r) 
                          ^ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                             >> 2U)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal 
        = (IData)((0x000000efU == (0x00000fffU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b 
        = ((0U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (1U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o 
           == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed 
        = VL_LTS_III(32, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o 
           < vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr 
        = (0xfffffffeU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o 
                          + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w 
        = ((0x0300U == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                        >> 0x00000014U)) ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r
            : ((0x0305U == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                            >> 0x00000014U)) ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r
                : ((0x0340U == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                >> 0x00000014U)) ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r
                    : ((0x0341U == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                    >> 0x00000014U))
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r
                        : (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r 
                           & (- (IData)((0x0342U == 
                                         (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 0x00000014U)))))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    __VdfgRegularize_h6e95ff9d_0_14 = ((2U == (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x0000000cU))) 
                                       | ((3U == (7U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0x0000000cU))) 
                                          | ((6U == 
                                              (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x0000000cU))) 
                                             | (7U 
                                                == 
                                                (7U 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                    >> 0x0000000cU))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint 
        = (IData)((0x00000067U == (0x0000707fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    __VdfgRegularize_h6e95ff9d_0_3 = ((~ ((0x67U == 
                                           (0x0000007fU 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                          | (0U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)))) 
                                      & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start 
        = (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
            & (0x02000033U == (0xfe00007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) 
           & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) 
                 | (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r)))));
    __VdfgRegularize_h6e95ff9d_0_16 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                             == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o))));
    __VdfgRegularize_h6e95ff9d_0_19 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                             == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o))));
    __VdfgRegularize_h6e95ff9d_0_20 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                             == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o))));
    __VdfgRegularize_h6e95ff9d_0_17 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                          == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                 | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                    | ((0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                       | (((0x73U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                           & ((1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 0x0000000cU))) 
                              | ((2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x0000000cU))) 
                                 | (3U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000cU)))))) 
                          | (0x13U == (0x0000007fU 
                                       & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | (0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
    __VdfgRegularize_h6e95ff9d_0_4 = ((~ ((0x63U == 
                                           (0x0000007fU 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                          | (0U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)))) 
                                      & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o));
    tb_seg_led_stop__DOT__dut__DOT__perip_rdata = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_dram_rr)
                                                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata
                                                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o));
    __VdfgRegularize_h6e95ff9d_0_2 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o) 
                                      & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_final 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_negate_r)
            ? (1ULL + (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_next))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_next);
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
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs 
        = (((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
             >> 0x0000001fU) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div))
            ? ((IData)(1U) + (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs 
        = (((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
             >> 0x0000001fU) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div))
            ? ((IData)(1U) + (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next 
        = ((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r 
            << 1U) | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next 
        = (0x00000001ffffffffULL & ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract)
                                     ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
                                        - (QData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)))
                                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
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
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o = 0U;
    if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                  >> 6U)))) {
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((((0U == (7U & 
                                              (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0x0000000cU))) 
                                      || (1U == (7U 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x0000000cU)))) 
                                     || (2U == (7U 
                                                & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x0000000cU))))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = (((- (IData)(
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0x0000000cU) 
                                           | ((0x00000fe0U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0x00000014U)) 
                                              | (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 7U))));
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 4U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x0000000dU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = (((- (IData)(
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x0000001fU))) 
                                            << 0x0000000cU) 
                                           | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x00000014U));
                                }
                            } else if ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x0000000cU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = (((- (IData)(
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x0000001fU))) 
                                            << 0x0000000cU) 
                                           | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x00000014U));
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                    = (((- (IData)(
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x0000001fU))) 
                                        << 0x0000000cU) 
                                       | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x00000014U));
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o 
                                    = (((- (IData)(
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x1fU))) 
                                        << 0x00000014U) 
                                       | ((((0x000001feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x14U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x00000014U))));
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o 
                                = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000001fU))) 
                                    << 0x0000000cU) 
                                   | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U));
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o 
                                        = (((- (IData)(
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0x0000000cU) 
                                           | ((0x00000800U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 7U)))));
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                } else if ((1U & (~ 
                                                  (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x0000000dU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o 
                                        = (((- (IData)(
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0x0000000cU) 
                                           | ((0x00000800U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 7U)))));
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                }
                            }
                        }
                    }
                    if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
            }
            if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    if ((0x00002000U 
                                         & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                            = (0x0000001fU 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0x0000000fU));
                                    } else if ((0x00001000U 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                            = (0x0000001fU 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0x0000000fU));
                                    }
                                } else if ((0x00002000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                } else if ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        }
                    }
                }
            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                         >> 0x0000000dU)))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                            } else {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x0000000cU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                }
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x0000001fU 
                                           & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o)
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o);
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000000cU))) 
                                  || (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0x0000000cU)))) 
                                 || (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0x0000000cU))))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                = (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                ? (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000001fU))) 
                                    << 0x0000000cU) 
                                   | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                      >> 0x00000014U))
                                : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                    ? (0x0000001fU 
                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x00000014U))
                                    : (((- (IData)(
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x0000001fU))) 
                                        << 0x0000000cU) 
                                       | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x00000014U))));
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                    = (((- (IData)(
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x0000001fU))) 
                                        << 0x0000000cU) 
                                       | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x00000014U));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000cU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                    = (((- (IData)(
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x0000001fU))) 
                                        << 0x0000000cU) 
                                       | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x00000014U));
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            }
                        } else if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0x0000000cU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            }
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x0000000dU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            } else if ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0x0000000cU)))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24 = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b) 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
                                                    >> 0x0000001fU));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a 
        = ((2U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid 
        = ((2U == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fetch_warmup_r)) 
           & ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) 
              & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
                 & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) {
        if ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
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
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o 
                = (1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid
                         [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx]
                          ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                             [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx] 
                             >> 1U) : (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU)));
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = ((0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))
                    ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU))) 
                           << 0x00000014U) | ((((0x000001feU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                    >> 0x0000000bU)) 
                                                | (1U 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                      >> 0x00000014U))) 
                                               << 0x0000000bU) 
                                              | (0x000007feU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                    >> 0x00000014U)))))
                    : ((0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras
                       [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx]
                        : 0U));
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o 
                = (1U & ((0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                         || ((0x67U == (0x0000007fU 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                             && ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)) 
                                 & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_pop)))));
        }
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op 
        = ((0x73U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
           & ((1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                            >> 0x0000000cU))) | ((5U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 0x0000000cU))) 
                                                 | (IData)(__VdfgRegularize_h6e95ff9d_0_14))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr 
        = (IData)(((0x00000080U == (0x00000f80U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                   & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr 
        = (((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint) 
            & (0x00008000U == (0x000f8000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) 
           & (~ (IData)(((0x00000080U == (0x00000f80U 
                                          & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                         & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                            >> 7U)) 
                            == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                               >> 0x0000000fU)))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o 
        = ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r)) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start));
    __VdfgRegularize_h6e95ff9d_0_18 = ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_17));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match 
        = (((((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 0x00000014U)) == (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 7U))) 
             & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)) 
            | (((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                >> 0x0000000fU)) == 
                (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                >> 7U))) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o))) 
           & ((0U != (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                     >> 7U))) & ((0x23U 
                                                  != 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                                 & (0x63U 
                                                    != 
                                                    (0x0000007fU 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match 
        = (((((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 0x00000014U)) == (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                                                      >> 7U))) 
             & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)) 
            | (((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                >> 0x0000000fU)) == 
                (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                                >> 7U))) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o))) 
           & ((0U != (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                                     >> 7U))) & ((0x23U 
                                                  != 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)) 
                                                 & (0x63U 
                                                    != 
                                                    (0x0000007fU 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_dep_match 
        = (((((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 0x00000014U)) == (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                                                      >> 7U))) 
             & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)) 
            | (((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                >> 0x0000000fU)) == 
                (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                                >> 7U))) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o))) 
           & ((0U != (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                                     >> 7U))) & ((0x23U 
                                                  != 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)) 
                                                 & (0x63U 
                                                    != 
                                                    (0x0000007fU 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match 
        = (((((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 0x00000014U)) == (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                                      >> 7U))) 
             & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)) 
            | (((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                >> 0x0000000fU)) == 
                (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                >> 7U))) & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o))) 
           & ((0U != (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                     >> 7U))) & ((0x23U 
                                                  != 
                                                  (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)) 
                                                 & (0x63U 
                                                    != 
                                                    (0x0000007fU 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)))));
    __VdfgRegularize_h6e95ff9d_0_22 = ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_17));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o)
            ? ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                ? (((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                     ? (0x0000ffffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                        ? (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                           >> 0x00000010U)
                                        : tb_seg_led_stop__DOT__dut__DOT__perip_rdata))
                     : (0x000000ffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                        ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000018U)
                                            : (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                               >> 0x00000010U))
                                        : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                               >> 8U)
                                            : tb_seg_led_stop__DOT__dut__DOT__perip_rdata)))) 
                   & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                          >> 0x0000000dU))))))
                : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                    ? (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                       & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                              >> 0x0000000cU))))))
                    : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                        ? ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                            ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                            >> 0x0000001fU))) 
                                << 0x00000010U) | (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000010U))
                            : (((- (IData)((1U & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & tb_seg_led_stop__DOT__dut__DOT__perip_rdata)))
                        : ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                            ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                >> 0x0000001fU))) 
                                    << 8U) | (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                ? (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & tb_seg_led_stop__DOT__dut__DOT__perip_rdata)))))))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o);
    __VdfgRegularize_h6e95ff9d_0_21 = ((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                                             == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o))));
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
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_abs 
        = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_24)
            ? ((IData)(1U) + (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26 = ((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                                                  >> 0x0000001fU) 
                                                 & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
            ? 0x00000013U : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
        = ((0x30200073U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r
            : (0xfffffffcU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & ((0x00000073U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
              | (0x30200073U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_20))
            ? 1U : (((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
                     & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                     ? 2U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o)) 
                              & (IData)(__VdfgRegularize_h6e95ff9d_0_18))
                              ? 3U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_18))
                                       ? 4U : (5U & 
                                               (- (IData)(
                                                          ((IData)(__VdfgRegularize_h6e95ff9d_0_3) 
                                                           & (IData)(__VdfgRegularize_h6e95ff9d_0_16)))))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_load_dep 
        = ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_load_dep 
        = ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_load_dep 
        = ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_dep_match));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__control_late_dep 
        = (((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match) 
            | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match) 
               | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_dep_match) 
                  | ((((((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                         >> 0x00000014U)) 
                         == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                            >> 7U))) 
                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)) 
                       | (((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                           >> 0x0000000fU)) 
                           == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                              >> 7U))) 
                          & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o))) 
                      & ((0U != (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                                >> 7U))) 
                         & ((0x23U != (0x0000007fU 
                                       & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)) 
                            & (0x63U != (0x0000007fU 
                                         & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o))))) 
                     | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match))))) 
           & ((0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | (0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
    __VdfgRegularize_h6e95ff9d_0_15 = ((3U == (0x0000007fU 
                                               & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)) 
                                       & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_20))
            ? 1U : (((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                     & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                     ? 2U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o)) 
                              & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                              ? 3U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                                       ? 4U : (5U & 
                                               (- (IData)(
                                                          ((IData)(__VdfgRegularize_h6e95ff9d_0_4) 
                                                           & (IData)(__VdfgRegularize_h6e95ff9d_0_16)))))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o) 
               & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o)) 
                  & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                     == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o)))))
            ? 1U : (((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                     & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o) 
                        & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o)) 
                           & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                              == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o)))))
                     ? 2U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o)) 
                              & (IData)(__VdfgRegularize_h6e95ff9d_0_21))
                              ? 3U : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o)) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_21))
                                       ? 4U : (5U & 
                                               (- (IData)(
                                                          ((IData)(__VdfgRegularize_h6e95ff9d_0_2) 
                                                           & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                                              & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o)) 
                                                                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                                                                    == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o))))))))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_abs 
        = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26)
            ? ((IData)(1U) + (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o 
           + ((4U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
               ? ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                   ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o
                   : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                       ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o
                       : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o))
               : ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                   ? ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                       ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o
                       : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                   : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                       ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                       : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_slow_load_dep 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_15));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_slow_load_dep 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o) 
           & (IData)(__VdfgRegularize_h6e95ff9d_0_15));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
        = ((4U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
            ? ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o
                : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o))
            : ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                ? ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel) 
           & (- (IData)((0x63U != (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)))));
    if ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        __VdfgRegularize_h6e95ff9d_0_12 = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o;
        __VdfgRegularize_h6e95ff9d_0_13 = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o;
    } else {
        __VdfgRegularize_h6e95ff9d_0_12 = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
        __VdfgRegularize_h6e95ff9d_0_13 = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0U;
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_load_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_load_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_load_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_slow_load_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_slow_load_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 0U;
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o = 0x00000013U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r;
    }
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_load_dep) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_load_dep) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_mem2_load_dep) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_slow_load_dep) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_slow_load_dep) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__control_late_dep) {
        tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = 1U;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r 
        = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
            ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                ? ((~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o) 
                   & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w)
                : (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                   | tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w))
            : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o
                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en 
        = (((1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                          >> 0x0000000cU))) | ((5U 
                                                == 
                                                (7U 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                    >> 0x0000000cU))) 
                                               | ((0U 
                                                   != vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o) 
                                                  & (IData)(__VdfgRegularize_h6e95ff9d_0_14)))) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o 
        = ((4U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
            ? ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o
                : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o))
            : ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                ? ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                : ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o)));
    if ((4U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        if ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = __VdfgRegularize_h6e95ff9d_0_12;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = __VdfgRegularize_h6e95ff9d_0_12;
        }
    } else if ((2U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
            = __VdfgRegularize_h6e95ff9d_0_13;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
            = __VdfgRegularize_h6e95ff9d_0_13;
    } else if ((1U & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
           | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_idex));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) 
                  | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg))) 
              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_signed 
        = VL_LTS_III(32, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o, tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_unsigned 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           < tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           ^ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           | vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           << (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           >> (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r)))) {
            if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
                if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o 
                                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o;
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
                                        }
                                    }
                                }
                                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                            if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal) {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                                    = 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                                            }
                                            if ((1U 
                                                 & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o)))) {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                                    = 
                                                    (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o 
                                                     + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o);
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr) {
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                                = ((IData)(4U) 
                                                   + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                                        }
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr;
                                        if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                            if ((1U 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o)) 
                                                    | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o 
                                                       != tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr)))) {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                            }
                                        } else {
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                                        = (1U & ((0x00004000U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? 
                                                 ((0x00002000U 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? 
                                                  ((0x00001000U 
                                                    & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                    ? 
                                                   (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned))
                                                    : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned))
                                                   : 
                                                  ((0x00001000U 
                                                    & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                    ? 
                                                   (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed))
                                                    : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed)))
                                                  : 
                                                 ((1U 
                                                   & (~ 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 0x0000000dU))) 
                                                  && (1U 
                                                      & ((0x00001000U 
                                                          & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                          ? 
                                                         (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq))
                                                          : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq))))));
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                                    if (((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                                         != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o))) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                            = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                                ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o 
                                                   + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o)
                                                : ((IData)(4U) 
                                                   + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o));
                                    }
                                }
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                              >> 6U)))) {
                    if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 5U)))) {
                        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o 
                                                = (0x2004U 
                                                   == 
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr 
                                                    >> 0x12U));
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if ((0U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0x0000000cU)))) {
                                                if (
                                                    (2U 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    if (
                                                        (1U 
                                                         & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                             << 0x00000018U);
                                                    } else {
                                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (0x00ff0000U 
                                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                                << 0x00000010U));
                                                    }
                                                } else if (
                                                           (1U 
                                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0x0000ff00U 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                            << 8U));
                                                } else {
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0x000000ffU 
                                                         & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                }
                                            } else if (
                                                       (1U 
                                                        == 
                                                        (7U 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                            >> 0x0000000cU)))) {
                                                if (
                                                    (2U 
                                                     & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0cU;
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                         << 0x00000010U);
                                                } else {
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0x0000ffffU 
                                                         & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                }
                                            } else if (
                                                       (2U 
                                                        == 
                                                        (7U 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                            >> 0x0000000cU)))) {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0fU;
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o;
                                            } else {
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                                            }
                                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w;
        } else if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w;
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 2U)) && ((1U 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 1U)) 
                                                  && ((1U 
                                                       & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                      && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen))));
                        if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
                                } else {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 1U)) && ((1U 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                  && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                    = ((IData)(4U) 
                                       + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                     >> 3U))) && ((4U 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? 
                                                  ((1U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 1U)) 
                                                   && ((1U 
                                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                       && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))
                                                   : 
                                                  ((1U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 1U)) 
                                                   && ((1U 
                                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                       && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))));
                    if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? ((0x40000000U 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                ? (
                                                   (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                                    & (0xffffffffU 
                                                       >> 
                                                       (0x0000001fU 
                                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                                   | ((- (IData)(
                                                                 (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                                  >> 0x1fU))) 
                                                      & (~ 
                                                         (0xffffffffU 
                                                          >> 
                                                          (0x0000001fU 
                                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                    : ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_unsigned)
                                            : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_signed))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                            : ((0U 
                                                == 
                                                (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                 >> 0x00000019U))
                                                ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                                : (
                                                   (0x20U 
                                                    == 
                                                    (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0x00000019U))
                                                    ? 
                                                   (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                    - vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)
                                                    : 0U)))));
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 1U)) && ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                              && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if (((((((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                 >> 0x0000000cU))) 
                                   | (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                   >> 0x0000000cU)))) 
                                  | (3U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                  >> 0x0000000cU)))) 
                                 | (7U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                 >> 0x0000000cU)))) 
                                | (6U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x0000000cU)))) 
                               | (4U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                               >> 0x0000000cU)))) 
                              | (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 0x0000000cU)))) 
                             | (5U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                             >> 0x0000000cU))))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                        }
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                            = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                    : ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x40000000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? ((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                                & (0xffffffffU 
                                                   >> 
                                                   (0x0000001fU 
                                                    & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                               | ((- (IData)(
                                                             (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                              >> 0x1fU))) 
                                                  & (~ 
                                                     (0xffffffffU 
                                                      >> 
                                                      (0x0000001fU 
                                                       & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_unsigned)
                                        : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__alu_less_signed))
                                    : ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                 >> 3U))) && ((1U & 
                                               (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                   >> 2U))) 
                                              && ((1U 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 1U)) 
                                                  && ((1U 
                                                       & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                      && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))));
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                            ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                            : 0U);
                    if ((1U & (~ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            }
        }
    }
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
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 948686903873698010ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10869817739270191688ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2976307909496553097ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5185928688947435002ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3111738740278296080ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10495267192879456192ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5052563256944605730ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3867366153237480781ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6288127080420791650ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6154037922091923004ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12296998301080579498ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7652482593801684202ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8482596563151738301ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10457528535279057236ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3825605203575187684ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14171132543316874123ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11472067611522454157ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11959470555200488509ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9377452443703627413ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14066660093808321416ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6028894417253524482ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17337825208755647809ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12953496392101580586ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2533341241082433994ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2911885577111992805ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1125500512546167345ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7387017039086651439ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7529663074691585726ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9449640309679487751ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10773397057069080292ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1037626342010035529ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 5030746772201141635ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4317367118812301358ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11752080337017503914ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18078886961641381715ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17164935628413816089ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8198406663044954359ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17010509968452672333ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16198275189042362728ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9053116875181490497ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16635360816564724363ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10096394620102304987ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12257773501611915154ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8339168196096576382ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7977242442600398659ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 974111761018371100ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16895438162476654963ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2668966555184242919ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4876442756620786773ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11922162389658461530ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6346107562882242824ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13762275924520088851ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9758966467627452959ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4951456430792755480ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9909791046236054901ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3497873293012016956ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18240461548606671269ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 6722914342521623452ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18115074767981161114ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4256956871652085362ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2146115715330917578ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10303832338807718122ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11982723695569812450ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 878080286234734096ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12409089133040673753ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11977474876914478600ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1690095051766473067ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4018188720027018620ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17885179222658966646ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 764648218571109497ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9230220977465871628ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7956789513506477478ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12389074560711425031ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 9755797355157165445ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10209673406592875393ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15950696342147119958ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 354517796751937267ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 2441604593207448394ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12216378558024605307ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5202276833962486226ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17211651097612929823ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 298192757187219290ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13008305942700514758ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1372047231402138334ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16894729960175747486ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15260202454413528327ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5426947736752884722ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6654914850157752266ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7055303275731484399ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_load_hits_dram_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7027975792838920180ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1619414051978466800ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14563026913460560126ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15342592360703520970ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 607732348633905102ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1105846461176900887ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17244056984787473794ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3221720098401186427ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1301798070900550058ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14773260293777528142ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8626752087575886383ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2915749112515465834ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4866702029151081806ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16455534720905083977ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18314198529161919676ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14598244519537533908ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12467067990139886198ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1649237972347719668ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13625063008900949540ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12657795897968132924ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6780200263529685718ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14115385046211907148ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15744715767216488182ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13702052515341355819ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fetch_warmup_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4060138862158314308ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14508467108083666622ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17071943344017967899ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 705290602725565307ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i = 0;
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9550915633978747996ull);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2957178069351308095ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 16893400197375899967ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5646279738573997669ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12149679177970947761ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10583382702675581032ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16876175251765805296ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 612301454546434147ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 18241261620918769320ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5038517763427473552ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4442836898952312779ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6102384936597861061ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12126466536756405394ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12562489915392661451ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17981984378601124058ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15614041637089324455ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 15887118205425793081ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3043858197233742394ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1727209909703822814ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9868664591454899994ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5518265068145296716ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3063471802749992812ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15605939600899105119ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17289876247815325616ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8979359998883265331ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2329192941160258569ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15790309302896154234ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16298655305979179711ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14968274538567680715ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7008376782575479795ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9873687245183755965ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16671283463210875218ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2681992819932349125ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_r = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1466490403539563343ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_multiplicand_r = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12906287505159163956ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_multiplier_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4393220253630641730ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_negate_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10467403712038969884ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 14548614039233745279ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 1043862058523739522ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13739397771940841256ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8914250321776241288ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2282092759496521476ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17769711986869988024ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10115887486548073993ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 554210974257990062ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8464477219203607498ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18105846800436482266ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17644129141950896578ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_abs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14062055827703777671ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_abs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15424501668370935841ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2007670998530495016ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14556924583710479315ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10310820120188343172ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5659021890329685751ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_accum_next = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14993369800594142109ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_final = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4435286389810386721ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next = VL_SCOPED_RAND_RESET_Q(33, __VscopeHash, 12542216298142109727ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11251059673662692002ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 766042032199781211ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11908888425989604919ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8714911324186863197ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7724018973713017129ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11409224941603673127ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1475536835971653436ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14471531976112147314ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15761580245691952077ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4219194306195208527ull);
    }
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7097346170959150808ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7218541441738389245ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11326547403443602945ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8185899325550301606ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8307950485393962086ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12987636489371292051ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10570593319362075174ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16633500160127652802ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output = VL_SCOPED_RAND_RESET_Q(40, __VscopeHash, 11270329945646578547ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10473207328143519706ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_dram_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11972412979430132045ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_dram_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6083313898029036622ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15977324658728725506ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12923970875581823107ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11521485675812683435ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2340519013118108049ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 529473546632690743ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3225670679965674962ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9674415625596368554ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9991382012632339158ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1799294687713590931ull);
    vlSelf->tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17158329120510826348ull);
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
    vlSelf->__VdfgRegularize_h6e95ff9d_0_24 = 0;
    vlSelf->__VdfgRegularize_h6e95ff9d_0_26 = 0;
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
