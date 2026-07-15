// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rv32i_cpu.h for the primary calling header

#include "Vtb_rv32i_cpu__pch.h"
#include "Vtb_rv32i_cpu___024root.h"

VL_ATTR_COLD void Vtb_rv32i_cpu___024root___eval_initial__TOP(Vtb_rv32i_cpu___024root* vlSelf);
VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_rv32i_cpu___024root* vlSelf);
VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_rv32i_cpu___024root* vlSelf);
VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__2(Vtb_rv32i_cpu___024root* vlSelf);
VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__3(Vtb_rv32i_cpu___024root* vlSelf);

void Vtb_rv32i_cpu___024root___eval_initial(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial\n"); );
    // Body
    Vtb_rv32i_cpu___024root___eval_initial__TOP(vlSelf);
    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__3(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_50Mhz__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz;
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_rst__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_clk_rst;
}

VL_INLINE_OPT VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__0(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    VL_WRITEF("=== RV32I CPU Simulation ===\nTB_CPU_CLOCK freq_mhz=200.000 half_period_ns=2.500000\nLoading memory from rv32i-cpu directory...\n");
    vlSelf->tb_rv32i_cpu__DOT__virtual_key = 0U;
    vlSelf->tb_rv32i_cpu__DOT__virtual_sw = 0ULL;
    vlSelf->tb_rv32i_cpu__DOT__w_clk_rst = 1U;
    vlSelf->tb_rv32i_cpu__DOT__cycle_count = 0ULL;
    vlSelf->tb_rv32i_cpu__DOT__seg_write_count = 0U;
    vlSelf->tb_rv32i_cpu__DOT__led_write_count = 0U;
    vlSelf->tb_rv32i_cpu__DOT__same_pc_count = 0U;
    vlSelf->tb_rv32i_cpu__DOT__low_pc_count = 0U;
    vlSelf->tb_rv32i_cpu__DOT__prev_pc = 0U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "new/tb_rv32i_cpu.sv", 
                                       53);
    vlSelf->tb_rv32i_cpu__DOT__w_clk_rst = 0U;
    VL_WRITEF("Reset released at time %0t\n",64,VL_TIME_UNITED_Q(1000),
              -9);
}

VL_INLINE_OPT VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__1(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xe8d4a51000ULL, 
                                       nullptr, "new/tb_rv32i_cpu.sv", 
                                       111);
    VL_WRITEF("=== TIMEOUT ===\nSimulation timed out at %0t\n",
              64,VL_TIME_UNITED_Q(1000),-9);
    VL_WRITEF("\n=== SIMULATION SUMMARY ===\nTotal cycles: %0d\nTotal SEG writes: %0d\nTotal LED writes: %0d\nFinal LED value: %08x\nFinal SEG value: %010x\n========================\n",
              64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
              32,vlSelf->tb_rv32i_cpu__DOT__seg_write_count,
              32,vlSelf->tb_rv32i_cpu__DOT__led_write_count,
              32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2,
              40,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2);
    VL_FINISH_MT("new/tb_rv32i_cpu.sv", 115, "");
}

VL_INLINE_OPT VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__2(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x2710ULL, 
                                           nullptr, 
                                           "new/tb_rv32i_cpu.sv", 
                                           43);
        vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz = (1U 
                                                  & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz)));
    }
}

VL_INLINE_OPT VlCoroutine Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__3(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_initial__TOP__Vtiming__3\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x9c4ULL, 
                                           nullptr, 
                                           "new/tb_rv32i_cpu.sv", 
                                           41);
        vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk = (1U 
                                                & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk)));
    }
}

void Vtb_rv32i_cpu___024root___eval_act(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_sequent__TOP__0(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst)
            ? 0U : (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))));
}

extern const VlUnpacked<CData/*0:0*/, 256> Vtb_rv32i_cpu__ConstPool__TABLE_h00a967ab_0;
extern const VlUnpacked<CData/*0:0*/, 256> Vtb_rv32i_cpu__ConstPool__TABLE_h26c8a6fe_0;

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_sequent__TOP__1(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_sequent__TOP__1\n"); );
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
    IData/*31:0*/ __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
    __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray;
    __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray = 0;
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0;
    SData/*8:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*1:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*5:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = 0;
    SData/*8:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = 0;
    CData/*4:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = 0;
    SData/*8:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = 0;
    CData/*4:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    IData/*31:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*2:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 0;
    CData/*5:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r = 0;
    QData/*32:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r = 0;
    QData/*32:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r = 0;
    CData/*0:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r = 0;
    IData/*31:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r = 0;
    SData/*15:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    SData/*15:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    SData/*15:0*/ __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    CData/*4:0*/ __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    CData/*7:0*/ __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    // Body
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0U;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0U;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0U;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0U;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0U;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0U;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0U;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r;
    __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst)))) {
        vlSelf->tb_rv32i_cpu__DOT__cycle_count = (1ULL 
                                                  + vlSelf->tb_rv32i_cpu__DOT__cycle_count);
        if ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc 
             == vlSelf->tb_rv32i_cpu__DOT__prev_pc)) {
            vlSelf->tb_rv32i_cpu__DOT__same_pc_count 
                = ((IData)(1U) + vlSelf->tb_rv32i_cpu__DOT__same_pc_count);
        } else {
            vlSelf->tb_rv32i_cpu__DOT__same_pc_count = 0U;
            vlSelf->tb_rv32i_cpu__DOT__prev_pc = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc;
        }
        vlSelf->tb_rv32i_cpu__DOT__low_pc_count = (
                                                   (VL_LTS_IQQ(64, 0x64ULL, vlSelf->tb_rv32i_cpu__DOT__cycle_count) 
                                                    & (0x80000000U 
                                                       > vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc))
                                                    ? 
                                                   ((IData)(1U) 
                                                    + vlSelf->tb_rv32i_cpu__DOT__low_pc_count)
                                                    : 0U);
        if (VL_UNLIKELY(VL_LTES_III(32, 0x20U, vlSelf->tb_rv32i_cpu__DOT__low_pc_count))) {
            VL_WRITEF("=== FAIL: RUNAWAY_LOW_PC ===\nCycle: %0d, PC: %08x\n\n=== SIMULATION SUMMARY ===\nTotal cycles: %0d\nTotal SEG writes: %0d\nTotal LED writes: %0d\nFinal LED value: %08x\nFinal SEG value: %010x\n========================\n",
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc,
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__seg_write_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__led_write_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2,
                      40,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2);
            VL_FINISH_MT("new/tb_rv32i_cpu.sv", 74, "");
        }
        if (VL_UNLIKELY(VL_LTES_III(32, 0xc350U, vlSelf->tb_rv32i_cpu__DOT__same_pc_count))) {
            VL_WRITEF("=== FAIL: STUCK_SAME_PC ===\nCycle: %0d, PC: %08x\n\n=== SIMULATION SUMMARY ===\nTotal cycles: %0d\nTotal SEG writes: %0d\nTotal LED writes: %0d\nFinal LED value: %08x\nFinal SEG value: %010x\n========================\n",
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc,
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__seg_write_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__led_write_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2,
                      40,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2);
            VL_FINISH_MT("new/tb_rv32i_cpu.sv", 80, "");
        }
        if (VL_UNLIKELY(((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o)) 
                         & (0x80200020U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)))) {
            vlSelf->tb_rv32i_cpu__DOT__seg_write_count 
                = ((IData)(1U) + vlSelf->tb_rv32i_cpu__DOT__seg_write_count);
            VL_WRITEF("SEG_WRITE #%0d at cycle %0d: PC=%08x, data=%08x, time=%0t\n",
                      32,vlSelf->tb_rv32i_cpu__DOT__seg_write_count,
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o,
                      64,VL_TIME_UNITED_Q(1000),-9);
        }
        if (VL_UNLIKELY(((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o)) 
                         & (0x80200040U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)))) {
            vlSelf->tb_rv32i_cpu__DOT__led_write_count 
                = ((IData)(1U) + vlSelf->tb_rv32i_cpu__DOT__led_write_count);
            VL_WRITEF("LED_WRITE #%0d at cycle %0d: PC=%08x, data=%08x, time=%0t\n",
                      32,vlSelf->tb_rv32i_cpu__DOT__led_write_count,
                      64,vlSelf->tb_rv32i_cpu__DOT__cycle_count,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc,
                      32,vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o,
                      64,VL_TIME_UNITED_Q(1000),-9);
        }
    }
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst)))) {
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o) {
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 1U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 
                = ((0U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                    [vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                    ? ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o)
                        ? 1U : 0U) : ((1U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                                       [vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                                       ? ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o)
                                           ? 2U : 0U)
                                       : ((2U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                                           [vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                                           ? ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o)
                                               ? 3U
                                               : 1U)
                                           : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o)
                                               ? 3U
                                               : 2U))));
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 1U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
        }
    }
    if (((IData)(vlSelf->__VdfgTmp_h25675075__0) & 
         (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o)))) {
        if ((1U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb))) {
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0xffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o);
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 1U;
            __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0xffffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o 
                              >> 2U));
        }
        if ((2U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb))) {
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o 
                            >> 8U));
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 1U;
            __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 8U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0xffffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o 
                              >> 2U));
        }
        if ((4U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb))) {
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0xffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o 
                            >> 0x10U));
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 1U;
            __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0xffffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o 
                              >> 2U));
        }
        if ((8U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb))) {
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o 
                   >> 0x18U);
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 1U;
            __Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (0xffffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o 
                              >> 2U));
        }
    }
    if (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o) 
         & (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o)))) {
        __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o;
        __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 1U;
        __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_taken_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_taken_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_base_addr_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_base_addr_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_redirect));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs1_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs1_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__use_rs2_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o));
    if (((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) 
         | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid))) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = 0U;
    } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o) {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = 0U;
        if (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid) 
             & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)))) {
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 1U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = 1U;
        }
    } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = 1U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = 1U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = 0U;
    } else {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replay_pending_reg = 0U;
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = 1U;
        } else {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x13U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o = 0U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_target_o = 0U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_ghr_o = 0U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o = 0U;
        }
    }
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = 0U;
    } else if (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
                | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o))) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
        if (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
             & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_nonempty))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
                = (0x3fU & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r) 
                            - (IData)(1U)));
        }
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o) {
            if ((0x20U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r))) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
                    = (0x3fU & ((IData)(1U) + (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r)));
            }
        }
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
        if (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
             & (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)))) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx;
        }
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o) {
            __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o;
            __Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 1U;
            __Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r)));
        }
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
    }
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0] 
            = __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0] = 1U;
    }
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0] 
            = __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    }
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r = 0U;
    } else {
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o) {
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
                = ((0x1feU & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r) 
                              << 1U)) | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o));
        }
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x73U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                    = ((0xffffff7fU & __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r) 
                       | (0x80U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                                   << 4U)));
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                    = (0xfffffff7U & __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r);
            } else if ((0x30200073U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                    = ((0xfffffff7U & __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r) 
                       | (8U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                                >> 4U)));
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                    = (0x80U | __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r);
            } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en) {
                if ((0x300U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                >> 0x14U))) {
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
                }
            }
        }
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mstatus_r;
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0] 
            = __Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    }
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r = 0ULL;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[0U] = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[1U] = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[2U] = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r = 0ULL;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = 0U;
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w = 0U;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_ghr_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_store_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__store_data_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_mem_offset_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__mem_offset_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_branch_offset_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__branch_offset_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_target_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__pred_target_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__base_addr_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__jump_offset_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__cmp_op2_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op2_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op2_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs1_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs1_addr_next;
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o;
        }
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__op1_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rs2_addr_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_mem_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o;
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x73U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x30200073U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en) {
                        if ((0x300U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                        >> 0x14U))) {
                            if ((0x305U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                            >> 0x14U))) {
                                if ((0x340U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x14U))) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mscratch_r 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
                                }
                            }
                            if ((0x305U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                            >> 0x14U))) {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mtvec_r 
                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
                            }
                        }
                    }
                }
            }
            if ((0x73U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r = 0xbU;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
            } else if ((0x30200073U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_write_en) {
                    if ((0x300U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                    >> 0x14U))) {
                        if ((0x305U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                        >> 0x14U))) {
                            if ((0x340U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                            >> 0x14U))) {
                                if ((0x341U != (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x14U))) {
                                    if ((0x342U == 
                                         (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 0x14U))) {
                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mcause_r 
                                            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
                                    }
                                }
                                if ((0x341U == (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                >> 0x14U))) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__mepc_r 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT__csr_wdata_r;
                                }
                            }
                        }
                    }
                }
            }
        }
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o;
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 0U;
        }
        if ((4U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
            if ((2U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
            } else if ((1U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r;
            } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = 0U;
                if ((1U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r))) {
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 5U;
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r 
                        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r)
                            ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_final
                            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_final);
                }
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r 
                    = (0x3fU & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r) 
                                - (IData)(1U)));
            } else {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
                    = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
                       << 1U);
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_trial_remainder;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = 1U;
            }
        } else if ((2U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
            if ((1U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_result_final;
            } else {
                VL_EXTENDS_WQ(66,33, __Vtemp_10, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r);
                __Vtemp_11[0U] = __Vtemp_10[0U];
                __Vtemp_11[1U] = __Vtemp_10[1U];
                __Vtemp_11[2U] = (3U & __Vtemp_10[2U]);
                VL_EXTENDS_WQ(66,33, __Vtemp_13, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r);
                __Vtemp_14[0U] = __Vtemp_13[0U];
                __Vtemp_14[1U] = __Vtemp_13[1U];
                __Vtemp_14[2U] = (3U & __Vtemp_13[2U]);
                VL_MULS_WWW(66, __Vtemp_15, __Vtemp_11, __Vtemp_14);
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[0U] 
                    = __Vtemp_15[0U];
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[1U] 
                    = __Vtemp_15[1U];
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[2U] 
                    = (3U & __Vtemp_15[2U]);
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 3U;
            }
        } else if ((1U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r))) {
            if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_mul_op) {
                if (((0U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r) 
                     | (0U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r))) {
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w = 0U;
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
                } else {
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 2U;
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r 
                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_w;
                    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r 
                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_w;
                }
            } else if ((0U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op)
                        ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r
                        : 0xffffffffU);
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
            } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_overflow) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op)
                        ? 0U : 0x80000000U);
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
            } else if ((0U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w = 0U;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
            } else if ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs 
                        < vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op)
                        ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r
                        : 0U);
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
            } else if ((1U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs)) {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op)
                        ? 0U : (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
                                 & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                                     ^ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r) 
                                    >> 0x1fU)) ? ((IData)(1U) 
                                                  + 
                                                  (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs))
                                 : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs));
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r = 1U;
            } else {
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 4U;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = 0x20U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r = 0ULL;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r = 0ULL;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op1_abs;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_op2_abs;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
                       & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                           ^ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r) 
                          >> 0x1fU));
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r = 0U;
                __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r = 0U;
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r 
                    = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div) 
                       & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                          >> 0x1fU));
            }
        } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start) {
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r = 1U;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r 
                = (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                         >> 0xcU));
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o;
            __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r = 0U;
        }
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__iter_count_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op2_ext_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_return_remainder_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_phase_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_result_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op2_raw_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__replaying_reg;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r))
            ? 0x1fU : (0x1fU & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r) 
                                - (IData)(1U))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_nonempty 
        = (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_en_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_en_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_actual_taken_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_actual_taken_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_wen_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__jalr_target_addr 
        = (0xfffffffeU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_base_addr_o 
                          + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_jump_offset_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx 
        = (0x1ffU & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_pc_o 
                      >> 2U) ^ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_bp_update_ghr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__reg_wen_next));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_eq 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o 
           == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_signed 
        = VL_LTS_III(32, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__br_less_unsigned 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_op1_o 
           < vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_cmp_op2_o);
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT____VdfgTmp_h84ae0744__0 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_use_rs2_o) 
           & (0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rs2_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_load_hits_dram_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_load_hits_dram_o));
    if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
            [(0xffffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o 
                         >> 2U))];
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_is_slow_load_o 
        = ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_load_hits_dram_o)) 
           & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_is_load_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_trial_remainder 
        = (((QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_r)) 
            << 1U) | (QData)((IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_dividend_r 
                                      >> 0x1fU))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract 
        = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
           >= (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_rem_op 
        = ((6U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (7U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_result_final 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r))
            ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[0U]
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_product_r[1U]);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_div 
        = ((4U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (6U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_b 
        = ((0U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)) 
           | (1U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__instruction 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Mem_IROM__DOT__mem
        [(0xfffU & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc 
                    >> 2U))];
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_branch_offset_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_inst__DOT____VdfgExtracted_h30f5db70__0 
        = (((- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                        >> 0x1fU))) << 0xcU) | (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x14U));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata_r 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst)
            ? 0U : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr)
                     ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                     : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr)
                         ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2)
                         : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr)
                             ? (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
                                        >> 0x20U)) : 
                            ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr)
                              ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2)
                              : ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr)
                                  ? vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                                  : 0U))))));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_rr 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_rr 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_rr 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_rr 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_r));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_rr 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_r));
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0))) 
                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0) 
                                   << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0))));
    }
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1))) 
                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) 
                                   << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1))));
    }
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2))) 
                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) 
                                   << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2))));
    }
    if (__Vdlyvset__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3))) 
                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__Vdlyvdim0__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) 
                                   << (IData)(__Vdlyvlsb__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3))));
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next 
        = ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_r 
            << 1U) | (IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next 
        = (0x1ffffffffULL & ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_can_subtract)
                              ? (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r 
                                 - (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_divisor_r)))
                              : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_shift_r));
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
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_jump_offset_o = 0U;
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_mem_offset_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_rd_data_o 
        = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_is_slow_load_o) 
            & (3U == (0x7fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst_o)))
            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__wb_inst__DOT__mmio_load_data_w
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_data_o);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_en_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_en_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_actual_taken_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_actual_taken_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_wen_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_load_hits_dram_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o));
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o = 0x13U;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_bp_update_pc_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__rd_addr_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_mem_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o;
    }
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_is_load_o)
            ? ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst_o)
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
                                              & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_rdata)))))))
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_data_o);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__frontend_flush_ifid 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_replay_flush_d1_r) 
           | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_final 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_negate_r)
            ? ((IData)(1U) + (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next))
            : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_quotient_accum_next);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_final 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_negate_r)
            ? ((IData)(1U) + (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next)))
            : (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__div_remainder_next));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_mul_op 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a) 
           | (3U == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__func3_r)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__mul_op1_ext_w 
        = ((IData)(tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__is_signed_mul_a)
            ? (((QData)((IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r 
                                 >> 0x1fU))) << 0x20U) 
               | (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r)))
            : (QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__op1_raw_r)));
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o = 0x13U;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_addr_next;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__inst_next;
    }
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal 
        = (IData)((0xefU == (0xfffU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
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
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_inst__DOT____VdfgTmp_hfe7d81d1__0 
        = ((6U == (7U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                         >> 0xcU))) | (7U == (7U & 
                                              (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                               >> 0xcU))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint 
        = (IData)((0x67U == (0x707fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_start 
        = ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & ((~ ((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__state_r)) 
                  | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r))) 
              & (IData)((0x2000033U == (0xfe00007fU 
                                        & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst)
            ? 0x80000000U : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc);
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_fetch_valid 
        = (1U & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
                 & ((~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r)) 
                    & (~ ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_load_valid_o) 
                          & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                             == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o))))));
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx 
        = (0x1ffU & ((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                      >> 2U) ^ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r)));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_cnt_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) 
               & (0x80200050U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw0_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) 
               & (0x80200000U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_sw1_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) 
               & (0x80200004U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_key_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) 
               & (0x80200010U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o)));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__rd_is_seg_r 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o) 
               & (0x80200020U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o)));
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc = 0x80000000U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o = 0x13U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o = 0U;
    } else {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0x7fffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x80000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xbfffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x40000000U & ((0x40000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xc0000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xdfffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x20000000U & ((0x60000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xe0000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xefffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x10000000U & ((0x70000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xf0000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xf7ffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x8000000U & ((0x78000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                >> 1U)) 
                                ^ (0xf8000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfbffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x4000000U & ((0x7c000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                >> 1U)) 
                                ^ (0xfc000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfdffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x2000000U & ((0x7e000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                >> 1U)) 
                                ^ (0xfe000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfeffffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x1000000U & ((0x7f000000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                >> 1U)) 
                                ^ (0xff000000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xff7fffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x800000U & ((0x7f800000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                               >> 1U)) 
                               ^ (0xff800000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffbfffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x400000U & ((0x7fc00000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                               >> 1U)) 
                               ^ (0xffc00000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffdfffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x200000U & ((0x7fe00000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                               >> 1U)) 
                               ^ (0xffe00000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffefffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x100000U & ((0x7ff00000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                               >> 1U)) 
                               ^ (0xfff00000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfff7ffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x80000U & ((0x7ff80000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                              >> 1U)) 
                              ^ (0xfff80000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffbffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x40000U & ((0x7ffc0000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                              >> 1U)) 
                              ^ (0xfffc0000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffdffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x20000U & ((0x7ffe0000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                              >> 1U)) 
                              ^ (0xfffe0000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffeffffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x10000U & ((0x7fff0000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                              >> 1U)) 
                              ^ (0xffff0000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffff7fffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x8000U & ((0x7fff8000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                             >> 1U)) 
                             ^ (0xffff8000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffbfffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x4000U & ((0x7fffc000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                             >> 1U)) 
                             ^ (0xffffc000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffdfffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x2000U & ((0x7fffe000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                             >> 1U)) 
                             ^ (0xffffe000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffefffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x1000U & ((0x7ffff000U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                             >> 1U)) 
                             ^ (0xfffff000U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffff7ffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x800U & ((0x7ffff800U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                            >> 1U)) 
                            ^ (0xfffff800U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffbffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x400U & ((0x7ffffc00U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                            >> 1U)) 
                            ^ (0xfffffc00U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffdffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x200U & ((0x7ffffe00U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                            >> 1U)) 
                            ^ (0xfffffe00U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffeffU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x100U & ((0x7fffff00U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                            >> 1U)) 
                            ^ (0xffffff00U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffff7fU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x80U & ((0x7fffff80U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                           >> 1U)) 
                           ^ (0xffffff80U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffbfU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x40U & ((0x7fffffc0U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                           >> 1U)) 
                           ^ (0xffffffc0U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffdfU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x20U & ((0x7fffffe0U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                           >> 1U)) 
                           ^ (0xffffffe0U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffefU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x10U & ((0x7ffffff0U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                           >> 1U)) 
                           ^ (0xfffffff0U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffff7U & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (8U & ((0x7ffffff8U & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffff8U 
                                                   & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffbU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (4U & ((0x7ffffffcU & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffcU 
                                                   & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffdU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (2U & ((0x7ffffffeU & (__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffeU 
                                                   & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffeU & __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (1U & ((__Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                         >> 1U) ^ __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray)));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d 
            = __Vfunc_tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
        if ((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o))) {
            if ((0x80200040U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                if ((0x80200020U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o;
                }
            }
        }
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_pc_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_mem_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__pc = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_reg_inst__DOT__next_pc;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 
            = vlSelf->tb_rv32i_cpu__DOT__virtual_sw;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 
            = vlSelf->tb_rv32i_cpu__DOT__virtual_key;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_ghr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_pc_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 
            = (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
               ^ VL_SHIFTR_III(32,32,32, vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin, 1U));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_mem_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_pipe_rd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o;
    }
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_update_en_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_en_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_bp_actual_taken_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_actual_taken_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_rd_wen_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_is_load_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
        = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
            ? 0x13U : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o);
    if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o = 0x13U;
    } else if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_inst_r;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_update_en_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_bp_actual_taken_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_rd_wen_o 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
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
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o)))) {
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
                if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 4U)))) {
                            if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                          >> 3U)))) {
                                if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 1U;
                                            }
                                        }
                                    }
                                }
                                if ((1U & (~ (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                              >> 2U)))) {
                                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_pred_ghr_o;
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o;
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
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
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_load_hits_dram_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
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
    tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0 
        = ((tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
            & (0xffffffffU >> (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
           | ((~ (0xffffffffU >> (0x1fU & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
              & (- (IData)((vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                            >> 0x1fU)))));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rv32m_busy_o)))) {
        if (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r) {
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_wen_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_rd_addr_r;
            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_result_w;
        } else if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
            if ((0x40U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((0x20U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_csr_op) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__csr_rdata_w;
                                }
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
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
                        if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                        = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
                                } else {
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                                }
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                            = ((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                      >> 1U)) && ((1U 
                                                   & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                                  && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                    = ((IData)(4U) 
                                       + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_addr_o);
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
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
                    if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
                            } else {
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                            }
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                = ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x1000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                            : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                        : ((0x1000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? ((0x40000000U 
                                                & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                                ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0
                                                : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                            : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                    : ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x1000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0
                                            : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0)
                                        : ((0x1000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                            : ((0U 
                                                == 
                                                (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                 >> 0x19U))
                                                ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                                : (
                                                   (0x20U 
                                                    == 
                                                    (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                     >> 0x19U))
                                                    ? 
                                                   (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                    - vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)
                                                    : 0U)))));
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            } else if ((0x10U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                  >> 1U)) && ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o) 
                                              && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen)));
                    if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                = tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
                        } else {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                        }
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    if ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                        if (tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h9e2a2024__0) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_reg_wen;
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                                = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o;
                        }
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                            = ((0x4000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                ? ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                                        : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                                    : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? ((0x40000000U 
                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                            ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h7dd69679__0
                                            : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                                        : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                                : ((0x2000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                    ? ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_h2d5321c8__0
                                        : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT____VdfgExtracted_he135d4c1__0)
                                    : ((0x1000U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                                        ? tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                                        : tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
                    } else {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
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
                if ((8U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((4U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                } else if ((2U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)) {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((1U & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o)
                            ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_rd_addr_o)
                            : 0U);
                    if ((1U & (~ vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o))) {
                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                    }
                } else {
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
                }
            }
        }
        if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rv32m_iter_inst__DOT__done_r)))) {
            if ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
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
    }
}

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_sequent__TOP__2(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_sequent__TOP__2\n"); );
    // Init
    SData/*15:0*/ __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0;
    // Body
    __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = 0ULL;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = 0U;
    } else {
        __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
            = ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2)
                ? ((0xc34fU == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))
                    ? 0U : (0xffffU & ((IData)(1U) 
                                       + (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))))
                : 0U);
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
            = (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2) 
                & (0xc34fU == (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms)))
                ? ((IData)(1U) + vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin)
                : vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin);
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 
            = (((QData)((IData)((3U & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                       >> 6U)))) << 0x26U) 
               | (((QData)((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
                   << 0x1eU) | (QData)((IData)(((0x30000000U 
                                                 & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                                    << 0x18U)) 
                                                | (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3) 
                                                    << 0x14U) 
                                                   | ((0xc0000U 
                                                       & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                                          << 0x10U)) 
                                                      | (((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2) 
                                                          << 0xaU) 
                                                         | ((0x300U 
                                                             & ((IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                                                << 8U)) 
                                                            | (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1))))))))));
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__LED;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = __Vdly__tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 
        = ((1U & (~ (IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst))) 
           && (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_rv32i_cpu__ConstPool__TABLE_h271698c0_0;

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_comb__TOP__0(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = 0;
    CData/*3:0*/ tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = 0;
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
}

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_sequent__TOP__3(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans 
        = ((0x10U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))
            ? ((0x10U & (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))
                ? 0x55U : 0xffU) : 0xaaU);
}

VL_INLINE_OPT void Vtb_rv32i_cpu___024root___nba_sequent__TOP__4(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___nba_sequent__TOP__4\n"); );
    // Body
    if (vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) {
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__LED = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o = 0U;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o = 0U;
    } else {
        if ((0U != (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o))) {
            if ((0x80200040U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__LED 
                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o;
            }
            if ((0x80200040U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                if ((0x80200020U != vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                    if ((0x80200050U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o)) {
                        if ((0x80000000U == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 1U;
                        } else if ((0xffffffffU == vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o)) {
                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
                        }
                    }
                }
            }
        }
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_data_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o;
        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o 
            = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o;
    }
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
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
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                             << 0x18U);
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                                    } else {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (0xff0000U 
                                                             & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                                << 0x10U));
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                                    }
                                                } else if (
                                                           (1U 
                                                            & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__mem_addr)) {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xff00U 
                                                         & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                            << 8U));
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                                } else {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xffU 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
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
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                            = 
                                                            (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o 
                                                             << 0x10U);
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0xcU;
                                                    } else {
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                                                        vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                                    }
                                                } else {
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                        = 
                                                        (0xffffU 
                                                         & vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o);
                                                    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                                }
                                            } else if (
                                                       (2U 
                                                        == 
                                                        (7U 
                                                         & (vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst_o 
                                                            >> 0xcU)))) {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                                    = vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_store_data_o;
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0xfU;
                                            } else {
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                                                vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                            }
                                            vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
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
    }
    vlSelf->__VdfgTmp_h25675075__0 = ((0x80100000U 
                                       <= vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o) 
                                      & (0x8013ffffU 
                                         >= vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_addr_o));
    vlSelf->tb_rv32i_cpu__DOT__dut__DOT__bridge_inst__DOT__dram_wstrb 
        = ((IData)(vlSelf->__VdfgTmp_h25675075__0) ? (IData)(vlSelf->tb_rv32i_cpu__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_wd_reg_o)
            : 0U);
}

void Vtb_rv32i_cpu___024root___eval_nba(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((5ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rv32i_cpu___024root___nba_sequent__TOP__4(vlSelf);
    }
}

void Vtb_rv32i_cpu___024root___timing_resume(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___timing_resume\n"); );
    // Body
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_rv32i_cpu___024root___eval_triggers__act(Vtb_rv32i_cpu___024root* vlSelf);

bool Vtb_rv32i_cpu___024root___eval_phase__act(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_rv32i_cpu___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_rv32i_cpu___024root___timing_resume(vlSelf);
        Vtb_rv32i_cpu___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_rv32i_cpu___024root___eval_phase__nba(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_rv32i_cpu___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__nba(Vtb_rv32i_cpu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__act(Vtb_rv32i_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rv32i_cpu___024root___eval(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_rv32i_cpu___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("new/tb_rv32i_cpu.sv", 8, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_rv32i_cpu___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("new/tb_rv32i_cpu.sv", 8, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_rv32i_cpu___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_rv32i_cpu___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_rv32i_cpu___024root___eval_debug_assertions(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
