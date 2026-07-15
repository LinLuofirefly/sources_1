// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rv32i_cpu.h for the primary calling header

#include "Vtb_rv32i_cpu__pch.h"
#include "Vtb_rv32i_cpu___024root.h"

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_static__TOP(Vtb_rv32i_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_static(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_static\n"); );
    // Body
    Vtb_rv32i_cpu___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_static__TOP(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk = 0U;
    vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz = 0U;
    vlSelf->tb_rv32i_cpu__DOT__w_clk_rst = 1U;
    vlSelf->tb_rv32i_cpu__DOT__virtual_key = 0U;
    vlSelf->tb_rv32i_cpu__DOT__virtual_sw = 0ULL;
}

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_initial__TOP(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial__TOP\n"); );
    // Init
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk = 0U;
    vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i = 0U;
    while (VL_GTS_III(32, 0x200U, tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i)) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[(0x1ffU 
                                                                                & tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i)] = 1U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[(0x1ffU 
                                                                                & tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i)] = 0U;
        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i 
            = ((IData)(1U) + tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i);
    }
    __Vtemp_2[0U] = 0x2e6d656dU;
    __Vtemp_2[1U] = 0x69726f6dU;
    __Vtemp_2[2U] = 0x73696d2fU;
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_2)
                 ,  &(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Mem_IROM__DOT__mem)
                 , 0, ~0ULL);
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x10000U, tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[(0xffffU 
                                                                                & tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)] = 0U;
        tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i 
            = ((IData)(1U) + tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i);
    }
    __Vtemp_4[0U] = 0x2e6d656dU;
    __Vtemp_4[1U] = 0x6472616dU;
    __Vtemp_4[2U] = 0x73696d2fU;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_4)
                 ,  &(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_final(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__stl(Vtb_rv32i_cpu___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_rv32i_cpu___024root___eval_phase__stl(Vtb_rv32i_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_settle(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_rv32i_cpu___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("new/tb_rv32i_cpu.sv", 8, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_rv32i_cpu___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__stl(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_rv32i_cpu__ConstPool__TABLE_h00a967ab_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_rv32i_cpu__ConstPool__TABLE_h26c8a6fe_0;

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___stl_sequent__TOP__0(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i = 0;
    SData/*8:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0 = 0;
    CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel = 0;
    CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel = 0;
    CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel = 0;
    CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel = 0;
    CData/*2:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h90a7d266__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h90a7d266__0 = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0 = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_dep_match;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_dep_match = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0 = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0 = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0 = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h9e2a2024__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h9e2a2024__0 = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract = 0;
    CData/*0:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0 = 0;
    IData/*31:0*/ tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_inst__DOT__mmio_load_data_w;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_inst__DOT__mmio_load_data_w = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = 0;
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*3:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    if ((0x10U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        if ((0x10U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0x55U;
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
                = (0xfU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
                = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                           >> 8U));
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
                = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                           >> 0x10U));
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
                = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                           >> 0x18U));
        } else {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0xffU;
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
                = (0xfU & 0U);
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
                = (0xfU & 0U);
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
                = (0xfU & 0U);
            tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
                = (0xfU & 0U);
        }
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = 0xaaU;
        tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                       >> 4U));
        tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                       >> 0xcU));
        tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                       >> 0x14U));
        tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0xfU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                       >> 0x1cU));
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_nonempty 
        = (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op 
        = ((6U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (7U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx 
        = (0x1ffU & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o 
                      >> 2U) ^ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_result_final 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r))
            ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[0U]
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[1U]);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_trial_remainder 
        = (((QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r)) 
            << 1U) | (QData)((IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
                                      >> 0x1fU))));
    vlSelf->__VdfgTmp_h25675075__0 = ((0x80100000U 
                                       <= vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o) 
                                      & (0x8013ffffU 
                                         >= vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div 
        = ((4U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (6U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (1U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal 
        = (IData)((0xefU == (0xfffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r))
            ? 0x1fU : (0x1fU & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r) 
                                - (IData)(1U))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
           >= (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h9e2a2024__0 
        = ((0U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                         >> 0xcU))) | ((2U == (7U & 
                                               (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0xcU))) 
                                       | ((3U == (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU))) 
                                          | ((7U == 
                                              (7U & 
                                               (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0xcU))) 
                                             | ((6U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU))) 
                                                | ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                        >> 0xcU))) 
                                                   | ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                           >> 0xcU))) 
                                                      | (5U 
                                                         == 
                                                         (7U 
                                                          & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                             >> 0xcU))))))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid 
        = (1U & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
                 & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
                    & (~ ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o) 
                          & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                             == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx 
        = (0x1ffU & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                      >> 2U) ^ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0 
        = (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                        >> 0x1fU))) << 0xcU) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x14U));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o 
           == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed 
        = VL_LTS_III(32, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o 
           < vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr 
        = (0xfffffffeU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o 
                          + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0 
        = ((6U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                         >> 0xcU))) | (7U == (7U & 
                                              (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                               >> 0xcU))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_inst__DOT__mmio_load_data_w 
        = ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)
            ? ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)
                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r
                : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)
                    ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o)
                        ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                           >> 0x10U) : (0xffffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r))
                    : ((0U == (3U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                        ? (0xffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r)
                        : ((1U == (3U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                            ? (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                        >> 8U)) : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                                                    ? 
                                                   (0xffU 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                       >> 0x10U))
                                                    : 
                                                   (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                    >> 0x18U))))))
            : ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)
                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r
                : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)
                    ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o)
                        ? (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                        >> 0x1fU))) 
                            << 0x10U) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                         >> 0x10U))
                        : (((- (IData)((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                              >> 0xfU)))) 
                            << 0x10U) | (0xffffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r)))
                    : ((0U == (3U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                        ? (((- (IData)((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                              >> 7U)))) 
                            << 8U) | (0xffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r))
                        : ((1U == (3U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                            ? (((- (IData)((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                  >> 0xfU)))) 
                                << 8U) | (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                   >> 8U)))
                            : ((2U == (3U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o))
                                ? (((- (IData)((1U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                   >> 0x17U)))) 
                                    << 8U) | (0xffU 
                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                 >> 0x10U)))
                                : (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                                >> 0x1fU))) 
                                    << 8U) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
                                              >> 0x18U))))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint 
        = (IData)((0x67U == (0x707fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r) 
           | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o) 
           & (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start 
        = ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & ((~ ((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r)) 
                  | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r))) 
              & (IData)((0x2000033U == (0xfe00007fU 
                                        & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)))));
    if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
            = ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                ? ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                    ? 0U : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                             ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                 ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                     ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                        >> 0x10U) : 0U)
                                 : (0xffffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata))
                             : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                 ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                     ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                        >> 0x18U) : 
                                    (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                              >> 0x10U)))
                                 : ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                     ? (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                 >> 8U))
                                     : (0xffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata)))))
                : ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                    ? ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                        ? 0U : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata)
                    : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
                        ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                            ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                ? (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                >> 0x1fU))) 
                                    << 0x10U) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                 >> 0x10U))
                                : 0U) : (((- (IData)(
                                                     (1U 
                                                      & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (0xffffU 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata)))
                        : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                            ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                ? (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                >> 0x1fU))) 
                                    << 8U) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                              >> 0x18U))
                                : (((- (IData)((1U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                   >> 0x17U)))) 
                                    << 8U) | (0xffU 
                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                 >> 0x10U))))
                            : ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o)
                                ? (((- (IData)((1U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                   >> 0xfU)))) 
                                    << 8U) | (0xffU 
                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                   >> 7U)))) 
                                    << 8U) | (0xffU 
                                              & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata)))))));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o 
            = (1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o)));
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o = 0U;
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o 
        = ((0x13U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x33U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | ((0x63U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                 | ((3U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                    | ((0x23U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                       | ((0x67U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                          | ((0x73U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                             & ((1U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0xcU))) 
                                | ((2U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0xcU))) 
                                   | (3U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0xcU))))))))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o 
        = ((0x33U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
           | ((0x63U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
              | (0x23U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb 
        = ((IData)(vlSelf->__VdfgTmp_h25675075__0) ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o)
            : 0U);
    __Vtableidx2 = tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0
        [__Vtableidx2];
    __Vtableidx3 = tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0
        [__Vtableidx3];
    __Vtableidx4 = tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0
        [__Vtableidx4];
    __Vtableidx5 = tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0
        [__Vtableidx5];
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs 
        = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
               >> 0x1fU)) ? ((IData)(1U) + (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r))
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs 
        = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
               >> 0x1fU)) ? ((IData)(1U) + (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r))
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_overflow 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
           & ((0x80000000U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r) 
              & (0xffffffffU == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_w 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b)
            ? (((QData)((IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
                                 >> 0x1fU))) << 0x20U) 
               | (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r)))
            : (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b) 
           | (2U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next 
        = ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r 
            << 1U) | (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next 
        = (0x1ffffffffULL & ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract)
                              ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
                                 - (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)))
                              : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)))) {
        if ((0x63U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                   + (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                   >> 0x1fU))) << 0xcU) 
                      | ((0x800U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                    << 4U)) | ((0x7e0U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                                     >> 7U))))));
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o 
                = (1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid
                         [tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx]
                          ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                             [tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx] 
                             >> 1U) : (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                       >> 0x1fU)));
        } else {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = ((0x6fU == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction))
                    ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                       >> 0x1fU))) 
                           << 0x14U) | ((0xff000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction) 
                                        | ((0x800U 
                                            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                                 >> 0x14U))))))
                    : ((0x67U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction))
                        ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras
                       [vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx]
                        : 0U));
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o 
                = (1U & ((0x6fU == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction)) 
                         || ((0x67U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction)) 
                             && (IData)(((0x8067U == 
                                          (0xff07fU 
                                           & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction)) 
                                         & ((~ (IData)(
                                                       ((0x80U 
                                                         == 
                                                         (0xf80U 
                                                          & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction)) 
                                                        & ((0x1fU 
                                                            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                                               >> 7U)) 
                                                           == 
                                                           (0x1fU 
                                                            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
                                                               >> 0xfU)))))) 
                                            & (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r))))))));
        }
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op 
        = ((0x73U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
           & ((1U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                            >> 0xcU))) | ((2U == (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU))) 
                                          | ((3U == 
                                              (7U & 
                                               (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0xcU))) 
                                             | ((5U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU))) 
                                                | (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o 
        = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o) 
            & (3U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)))
            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_inst__DOT__mmio_load_data_w
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint) 
           & (0x80U == (0xf80U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint) 
           & (IData)(((0x8000U == (0xf8000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                      & (~ (IData)(((0x80U == (0xf80U 
                                               & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                    & ((0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                 >> 7U)) 
                                       == (0x1fU & 
                                           (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                            >> 0xfU)))))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start) 
           | (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel 
        = (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0) 
            & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o) 
               & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o)) 
                  & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o) 
                     == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o)))))
            ? 1U : (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0) 
                     & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o) 
                        & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o)) 
                           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                              == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o)))))
                     ? 2U : (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0) 
                              & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o) 
                                 & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o)) 
                                    & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                                       == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o)))))
                              ? 3U : (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0) 
                                       & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                          & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o)) 
                                             & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o) 
                                                == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))))
                                       ? 4U : 0U))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h90a7d266__0 
        = (((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)) 
            & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o) 
               & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o)) 
                  & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o) 
                     == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)))))
            ? 1U : (((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)) 
                     & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o) 
                        & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o)) 
                           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                              == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o)))))
                     ? 2U : (((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)) 
                              & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o) 
                                 & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o)) 
                                    & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                       == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o)))))
                              ? 3U : (((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o)) 
                                       & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                          & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o)) 
                                             & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o) 
                                                == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))))
                                       ? 4U : 0U))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match 
        = ((0U != (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                            >> 7U))) & ((0x23U != (0x7fU 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                        & ((0x63U != 
                                            (0x7fU 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                           & (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o) 
                                               & ((0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 7U)) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                      >> 0xfU)))) 
                                              | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o) 
                                                 & ((0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                        >> 7U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x14U))))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match 
        = ((0U != (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                            >> 7U))) & ((0x23U != (0x7fU 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)) 
                                        & ((0x63U != 
                                            (0x7fU 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)) 
                                           & (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o) 
                                               & ((0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                                                      >> 7U)) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                      >> 0xfU)))) 
                                              | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o) 
                                                 & ((0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
                                                        >> 7U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x14U))))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match 
        = ((0U != (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                            >> 7U))) & ((0x23U != (0x7fU 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)) 
                                        & ((0x63U != 
                                            (0x7fU 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)) 
                                           & (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o) 
                                               & ((0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                                                      >> 7U)) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                      >> 0xfU)))) 
                                              | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o) 
                                                 & ((0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
                                                        >> 7U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x14U))))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_dep_match 
        = ((0U != (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                            >> 7U))) & ((0x23U != (0x7fU 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)) 
                                        & ((0x63U != 
                                            (0x7fU 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)) 
                                           & (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o) 
                                               & ((0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                                      >> 7U)) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                      >> 0xfU)))) 
                                              | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o) 
                                                 & ((0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
                                                        >> 7U)) 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x14U))))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_mul_op 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a) 
           | (3U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_w 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a)
            ? (((QData)((IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                                 >> 0x1fU))) << 0x20U) 
               | (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r)))
            : (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_final 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r)
            ? ((IData)(1U) + (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next))
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_final 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r)
            ? ((IData)(1U) + (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next)))
            : (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op) 
           & ((1U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                            >> 0xcU))) | ((5U == (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU))) 
                                          | ((((2U 
                                                == 
                                                (7U 
                                                 & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                    >> 0xcU))) 
                                               | (3U 
                                                  == 
                                                  (7U 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 0xcU)))) 
                                              | (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0)) 
                                             & (0U 
                                                != 
                                                (0x1fU 
                                                 & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                    >> 0xfU)))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o 
        = ((0U == (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                            >> 0xfU))) ? 0U : (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                                & ((0x1fU 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0xfU)) 
                                                   == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))
                                                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o
                                                : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                                               [(0x1fU 
                                                 & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0xfU))]));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o 
        = ((0U == (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                            >> 0x14U))) ? 0U : (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
                                                 & ((0x1fU 
                                                     & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x14U)) 
                                                    == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))
                                                 ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o
                                                 : 
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                                                [(0x1fU 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                     >> 0x14U))]));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
            ? 0x13U : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o);
    if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o = 0x13U;
    } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
        = ((0x30200073U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
            ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r
            : (0xfffffffcU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o 
        = ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & ((0x73U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
              | (0x30200073U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    if ((4U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        if ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
        } else if ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
        } else {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o;
        }
    } else if ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        if ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
        } else {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o;
        }
    } else if ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel))) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel 
        = ((0x63U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))
            ? 0U : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_alu_sel));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel 
        = (((0x67U != (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
            & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o))
            ? (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h90a7d266__0)
            : 0U);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel 
        = (((0x63U != (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
            & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o))
            ? (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h90a7d266__0)
            : 0U);
    __Vtableidx1 = (((0x63U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                     << 7U) | (((((0x63U == (0x7fU 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                                  | (0x67U == (0x7fU 
                                               & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))) 
                                 & ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match) 
                                    | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match) 
                                       | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match) 
                                          | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_dep_match) 
                                             | ((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                                     >> 7U))) 
                                                & ((0x23U 
                                                    != 
                                                    (0x7fU 
                                                     & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)) 
                                                   & ((0x63U 
                                                       != 
                                                       (0x7fU 
                                                        & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)) 
                                                      & (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o) 
                                                          & ((0x1fU 
                                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                                                 >> 7U)) 
                                                             == 
                                                             (0x1fU 
                                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                                 >> 0xfU)))) 
                                                         | ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o) 
                                                            & ((0x1fU 
                                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
                                                                   >> 7U)) 
                                                               == 
                                                               (0x1fU 
                                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                                   >> 0x14U))))))))))))) 
                                << 6U) | ((((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o) 
                                            & ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)) 
                                               & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2_dep_match))) 
                                           << 5U) | 
                                          (((((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o)) 
                                              & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o)) 
                                             & ((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o)) 
                                                & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem2a_dep_match))) 
                                            << 4U) 
                                           | ((((3U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o)) 
                                                & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__mem1_dep_match)) 
                                               << 3U) 
                                              | ((((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) 
                                                   & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__ex_dep_match)) 
                                                  << 2U) 
                                                 | (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o))))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h00a967ab_0
        [__Vtableidx1];
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o 
        = Vtb_rv32i_cpu__ConstPool__TABLE_h26c8a6fe_0
        [__Vtableidx1];
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o = 0U;
    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                  >> 6U)))) {
        if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((((0U == (7U & 
                                              (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 0xcU))) 
                                      || (1U == (7U 
                                                 & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0xcU)))) 
                                     || (2U == (7U 
                                                & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0xcU))))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = (((- (IData)(
                                                       (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0xfe0U 
                                               & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 7U))));
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 4U)))) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0xdU)))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                                }
                            } else if ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0xcU)))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                                }
                            } else {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                            }
                        }
                    }
                }
            }
        }
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 0U;
    if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o 
                                        = (((- (IData)(
                                                       (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 7U)))));
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                } else if ((1U & (~ 
                                                  (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0xdU)))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o 
                                        = (((- (IData)(
                                                       (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                        >> 0x1fU))) 
                                            << 0xcU) 
                                           | ((0x800U 
                                               & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  << 4U)) 
                                              | ((0x7e0U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 7U)))));
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                                }
                            }
                        }
                    }
                    if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
                if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o 
                                    = (((- (IData)(
                                                   (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                    >> 0x1fU))) 
                                        << 0x14U) | 
                                       ((0xff000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                        | ((0x800U 
                                            & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x14U)))));
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o 
                                = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o = 4U;
                        }
                    }
                }
            }
            if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 2U)))) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    if ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                            = (0x1fU 
                                               & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0xfU));
                                    } else if ((0x1000U 
                                                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                            = (0x1fU 
                                               & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0xfU));
                                    }
                                } else if ((0x2000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                } else if ((0x1000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                        }
                    }
                }
            } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                    }
                }
            } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    } else if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                         >> 0xdU)))) {
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = (0xfffff000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                        }
                    }
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                    }
                }
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o;
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)))) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((((0U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0xcU))) 
                                  || (1U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                   >> 0xcU)))) 
                                 || (2U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                  >> 0xcU))))) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                = (0xfffff000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o);
                        }
                    }
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                            = ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0
                                : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                    ? (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x14U))
                                    : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0));
                    }
                }
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                            } else if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0xcU)))) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0;
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0xdU)))) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            }
                        } else if ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                          >> 0xcU)))) {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                            }
                        } else {
                            tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 1U;
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)))) {
            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                              >> 2U)))) {
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0xdU)))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            } else if ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                              >> 0xcU)))) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                                }
                            } else {
                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                    = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o;
                            }
                        }
                    }
                }
            }
        }
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o 
        = ((4U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
            ? ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o
                : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o))
            : ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                ? ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs2_cmp_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr 
        = (((4U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
             ? ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                 ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o
                 : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                     ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o
                     : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o))
             : ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                 ? ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                     ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                     : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                 : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__base_sel))
                     ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                     : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o))) 
           + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
        = ((4U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
            ? ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o
                : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o))
            : ((2U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                ? ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o)
                : ((1U & (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__rs1_sel))
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o
                    : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
           | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg) 
           & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)) 
              & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid) 
           & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)) 
              & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg)) 
                 & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0 
        = VL_LTS_III(32, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o, tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           < tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           | vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           ^ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           << (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w 
        = ((0x300U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                       >> 0x14U)) ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r
            : ((0x305U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                           >> 0x14U)) ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r
                : ((0x340U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                               >> 0x14U)) ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r
                    : ((0x341U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                   >> 0x14U)) ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r
                        : ((0x342U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                       >> 0x14U)) ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r
                            : 0U)))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r 
        = ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
            ? ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                ? (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w 
                   & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o))
                : (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w 
                   | vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o))
            : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o
                : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           >> (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next = 0U;
    } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next 
            = (0x1fU & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next 
            = (0x1fU & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next 
            = (0x1fU & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_cmp_op2_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_store_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next 
            = (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                        >> 0xfU));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next 
            = (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                        >> 0x14U));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next 
            = (0x1fU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                        >> 7U));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next 
            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_taken_next 
        = ((~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i)) 
           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
               ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o)
               : (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs1_next 
        = ((~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i)) 
           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
               ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o)
               : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs1_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs2_next 
        = ((~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i)) 
           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
               ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o)
               : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_use_rs2_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_base_addr_next 
        = ((~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i)) 
           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
               ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o)
               : ((3U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                  | ((0x23U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) 
                     | (0x67U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__reg_wen_next 
        = ((~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__id_ex_inst__flush_flag_i)) 
           & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
               ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)
               : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect) 
           | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0 
        = ((tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
            & (0xffffffffU >> (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
           | ((~ (0xffffffffU >> (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
              & (- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                            >> 0x1fU)))));
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o)))) {
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
                if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o;
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
                                        }
                                    }
                                }
                                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                            if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                                    = 
                                                    ((IData)(4U) 
                                                     + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                                            }
                                            if ((1U 
                                                 & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o)))) {
                                                tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                                    = 
                                                    (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o 
                                                     + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o);
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr) {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                                = ((IData)(4U) 
                                                   + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                                        }
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                            = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr;
                                        if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                            if ((1U 
                                                 & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o)) 
                                                    | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o 
                                                       != tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr)))) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                            }
                                        } else {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                                        = (1U & ((0x4000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? 
                                                 ((0x2000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? 
                                                  ((0x1000U 
                                                    & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                    ? 
                                                   (~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned))
                                                    : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned))
                                                   : 
                                                  ((0x1000U 
                                                    & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                    ? 
                                                   (~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed))
                                                    : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed)))
                                                  : 
                                                 ((1U 
                                                   & (~ 
                                                      (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 0xdU))) 
                                                  && (1U 
                                                      & ((0x1000U 
                                                          & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                          ? 
                                                         (~ (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq))
                                                          : (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq))))));
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                                    if (((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                                         != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o))) {
                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                        tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                            = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                                ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o 
                                                   + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o)
                                                : ((IData)(4U) 
                                                   + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o));
                                    }
                                }
                            }
                        }
                    }
                }
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                              >> 6U)))) {
                    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 5U)))) {
                        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r;
        } else if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                }
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        }
                    } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                            = ((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 2U)) && ((1U 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 1U)) 
                                                  && ((1U 
                                                       & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                      && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen))));
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                            = ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                        : 0U) : 0U)
                                : 0U);
                    } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                            = ((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 1U)) && ((1U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                  && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                            = ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                    : 0U) : 0U);
                    } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                }
            } else if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                     >> 3U))) && ((4U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? 
                                                  ((1U 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 1U)) 
                                                   && ((1U 
                                                        & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                       && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))
                                                   : 
                                                  ((1U 
                                                    & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                       >> 1U)) 
                                                   && ((1U 
                                                        & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                       && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))));
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                            ? 0U : ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                     ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                             ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                             : 0U) : 0U)
                                     : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                             ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                             : 0U) : 0U)));
                } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                }
            } else if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 1U)) && ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                              && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                            ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                : 0U) : 0U);
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h9e2a2024__0) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                }
            } else {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                 >> 3U))) && ((1U & 
                                               (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                   >> 2U))) 
                                              && ((1U 
                                                   & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 1U)) 
                                                  && ((1U 
                                                       & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                      && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)))));
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                        ? 0U : ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                 ? 0U : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                          ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                              ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                                              : 0U)
                                          : 0U)));
            }
        }
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_reg_inst__DOT__next_pc 
        = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
            | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o))
            ? ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o)
                ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o
                : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect)
                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o
                    : ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_redirect)
                        ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o
                        : 0U))) : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o)
                                    ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc
                                    : ((IData)(4U) 
                                       + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o)))) {
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                              >> 6U)))) {
                    if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if ((0U 
                                                 == 
                                                 (7U 
                                                  & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0xcU)))) {
                                                if (
                                                    (2U 
                                                     & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    if (
                                                        (1U 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                             << 0x18U);
                                                    } else {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (0xff0000U 
                                                             & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                                << 0x10U));
                                                    }
                                                } else if (
                                                           (1U 
                                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xff00U 
                                                         & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                            << 8U));
                                                } else {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xffU 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                }
                                            } else if (
                                                       (1U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                            >> 0xcU)))) {
                                                if (
                                                    (2U 
                                                     & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    if (
                                                        (2U 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0xcU;
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                             << 0x10U);
                                                    } else {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                                                    }
                                                } else {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xffffU 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                }
                                            } else if (
                                                       (2U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                            >> 0xcU)))) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0xfU;
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o;
                                            } else {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                                            }
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 5U)))) {
                        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o 
                                                = (0x2004U 
                                                   == 
                                                   (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr 
                                                    >> 0x12U));
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w;
        } else if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w;
                                }
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                            = ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                        : 0U) : 0U)
                                : 0U);
                    } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                            = ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((IData)(4U) 
                                       + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o)
                                    : 0U) : 0U);
                    } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                        = ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                            ? 0U : ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                     ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                             ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o
                                             : 0U) : 0U)
                                     : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                             ? ((0x4000U 
                                                 & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                 ? 
                                                ((0x2000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                                   : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                                  : 
                                                 ((0x1000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? 
                                                  ((0x40000000U 
                                                    & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                    ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0
                                                    : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                                   : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                                 : 
                                                ((0x2000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? 
                                                 ((0x1000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0
                                                   : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0)
                                                  : 
                                                 ((0x1000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0x19U))
                                                    ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                                    : 
                                                   ((0x20U 
                                                     == 
                                                     (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                      >> 0x19U))
                                                     ? 
                                                    (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                     - vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)
                                                     : 0U)))))
                                             : 0U) : 0U)));
                } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                    = ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                        ? 0U : ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                 ? ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                     ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                         : 0U) : 0U)
                                 : ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                     ? ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                         ? ((0x4000U 
                                             & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                             ? ((0x2000U 
                                                 & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                 ? 
                                                ((0x1000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                                  : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                                 : 
                                                ((0x1000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? 
                                                 ((0x40000000U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                   ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0
                                                   : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                                  : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                             : ((0x2000U 
                                                 & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                 ? 
                                                ((0x1000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0
                                                  : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0)
                                                 : 
                                                ((0x1000U 
                                                  & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                  ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                                  : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)))
                                         : 0U) : 0U)));
            } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
            } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
            } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
            }
        }
    }
}

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_stl(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_triggers__stl(Vtb_rv32i_cpu___024root* vlSelf);

VL_ATTR_COLD bool Vtb_rv32i_cpu___024root___eval_phase__stl(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_rv32i_cpu___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_rv32i_cpu___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__act(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_rv32i_cpu.w_cpu_clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_rv32i_cpu.w_clk_50Mhz)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_rv32i_cpu.w_clk_rst or posedge tb_rv32i_cpu.w_cpu_clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__nba(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_rv32i_cpu.w_cpu_clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_rv32i_cpu.w_clk_50Mhz)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_rv32i_cpu.w_clk_rst or posedge tb_rv32i_cpu.w_cpu_clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___ctor_var_reset(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__w_clk_rst = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__virtual_key = VL_RAND_RESET_I(8);
    vlSelf->tb_rv32i_cpu__DOT__virtual_sw = VL_RAND_RESET_Q(64);
    vlSelf->tb_rv32i_cpu__DOT__cycle_count = 0;
    vlSelf->tb_rv32i_cpu__DOT__seg_write_count = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__led_write_count = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__same_pc_count = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__low_pc_count = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__prev_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = VL_RAND_RESET_I(4);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_actual_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_actual_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_actual_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o = VL_RAND_RESET_I(4);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_load_hits_dram_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 512; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = VL_RAND_RESET_I(6);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r = VL_RAND_RESET_I(6);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_nonempty = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_reg_inst__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_taken_next = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next = VL_RAND_RESET_I(9);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs1_next = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs2_next = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_base_addr_next = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__reg_wen_next = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = VL_RAND_RESET_I(3);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r = VL_RAND_RESET_I(3);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = VL_RAND_RESET_I(6);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r = VL_RAND_RESET_Q(33);
    VL_RAND_RESET_W(66, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_mul_op = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_w = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_w = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_result_final = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_overflow = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_trial_remainder = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next = VL_RAND_RESET_Q(33);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_final = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_final = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Mem_IROM__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__LED = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = VL_RAND_RESET_Q(64);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = VL_RAND_RESET_Q(64);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = VL_RAND_RESET_I(8);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = VL_RAND_RESET_I(8);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb = VL_RAND_RESET_I(4);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_r = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans = VL_RAND_RESET_I(8);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = VL_RAND_RESET_I(7);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = VL_RAND_RESET_I(7);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = VL_RAND_RESET_I(7);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = VL_RAND_RESET_I(7);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = VL_RAND_RESET_Q(40);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = VL_RAND_RESET_Q(40);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count = VL_RAND_RESET_I(5);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 65536; ++__Vi0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = VL_RAND_RESET_I(16);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 = VL_RAND_RESET_I(1);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = VL_RAND_RESET_I(32);
    vlSelf->__VdfgTmp_h25675075__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_50Mhz__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_rst__0 = VL_RAND_RESET_I(1);
}
