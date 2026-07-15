// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rv32i_cpu.h for the primary calling header

#include "Vtb_rv32i_cpu__pch.h"
#include "Vtb_rv32i_cpu__Syms.h"
#include "Vtb_rv32i_cpu___024root.h"

void Vtb_rv32i_cpu___024root___ctor_var_reset(Vtb_rv32i_cpu___024root* vlSelf);

Vtb_rv32i_cpu___024root::Vtb_rv32i_cpu___024root(Vtb_rv32i_cpu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_rv32i_cpu___024root___ctor_var_reset(this);
}

void Vtb_rv32i_cpu___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtb_rv32i_cpu___024root::~Vtb_rv32i_cpu___024root() {
}
