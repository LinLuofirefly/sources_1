// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_rv32i_cpu__pch.h"

//============================================================
// Constructors

Vtb_rv32i_cpu::Vtb_rv32i_cpu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_rv32i_cpu__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_rv32i_cpu::Vtb_rv32i_cpu(const char* _vcname__)
    : Vtb_rv32i_cpu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_rv32i_cpu::~Vtb_rv32i_cpu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_rv32i_cpu___024root___eval_debug_assertions(Vtb_rv32i_cpu___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_rv32i_cpu___024root___eval_static(Vtb_rv32i_cpu___024root* vlSelf);
void Vtb_rv32i_cpu___024root___eval_initial(Vtb_rv32i_cpu___024root* vlSelf);
void Vtb_rv32i_cpu___024root___eval_settle(Vtb_rv32i_cpu___024root* vlSelf);
void Vtb_rv32i_cpu___024root___eval(Vtb_rv32i_cpu___024root* vlSelf);

void Vtb_rv32i_cpu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_rv32i_cpu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_rv32i_cpu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_rv32i_cpu___024root___eval_static(&(vlSymsp->TOP));
        Vtb_rv32i_cpu___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_rv32i_cpu___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_rv32i_cpu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_rv32i_cpu::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_rv32i_cpu::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_rv32i_cpu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_rv32i_cpu___024root___eval_final(Vtb_rv32i_cpu___024root* vlSelf);

VL_ATTR_COLD void Vtb_rv32i_cpu::final() {
    Vtb_rv32i_cpu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_rv32i_cpu::hierName() const { return vlSymsp->name(); }
const char* Vtb_rv32i_cpu::modelName() const { return "Vtb_rv32i_cpu"; }
unsigned Vtb_rv32i_cpu::threads() const { return 1; }
void Vtb_rv32i_cpu::prepareClone() const { contextp()->prepareClone(); }
void Vtb_rv32i_cpu::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vtb_rv32i_cpu::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_rv32i_cpu::trace()' called on model that was Verilated without --trace option");
}
