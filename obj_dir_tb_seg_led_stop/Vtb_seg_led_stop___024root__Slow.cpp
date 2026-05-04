// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_seg_led_stop.h for the primary calling header

#include "Vtb_seg_led_stop__pch.h"

void Vtb_seg_led_stop___024root___ctor_var_reset(Vtb_seg_led_stop___024root* vlSelf);

Vtb_seg_led_stop___024root::Vtb_seg_led_stop___024root(Vtb_seg_led_stop__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_seg_led_stop___024root___ctor_var_reset(this);
}

void Vtb_seg_led_stop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_seg_led_stop___024root::~Vtb_seg_led_stop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
