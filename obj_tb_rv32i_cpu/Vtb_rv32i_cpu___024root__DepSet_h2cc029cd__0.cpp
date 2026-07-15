// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rv32i_cpu.h for the primary calling header

#include "Vtb_rv32i_cpu__pch.h"
#include "Vtb_rv32i_cpu__Syms.h"
#include "Vtb_rv32i_cpu___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rv32i_cpu___024root___dump_triggers__act(Vtb_rv32i_cpu___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rv32i_cpu___024root___eval_triggers__act(Vtb_rv32i_cpu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtb_rv32i_cpu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rv32i_cpu___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_50Mhz__0))));
    vlSelf->__VactTriggered.set(2U, (((IData)(vlSelf->tb_rv32i_cpu__DOT__w_clk_rst) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_rst__0))) 
                                     | ((IData)(vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0)))));
    vlSelf->__VactTriggered.set(3U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_cpu_clk__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_cpu_clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_50Mhz__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_clk_50Mhz;
    vlSelf->__Vtrigprevexpr___TOP__tb_rv32i_cpu__DOT__w_clk_rst__0 
        = vlSelf->tb_rv32i_cpu__DOT__w_clk_rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_rv32i_cpu___024root___dump_triggers__act(vlSelf);
    }
#endif
}
