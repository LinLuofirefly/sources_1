// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_seg_led_stop__pch.h"

//============================================================
// Constructors

Vtb_seg_led_stop::Vtb_seg_led_stop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_seg_led_stop__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_seg_led_stop::Vtb_seg_led_stop(const char* _vcname__)
    : Vtb_seg_led_stop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_seg_led_stop::~Vtb_seg_led_stop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_seg_led_stop___024root___eval_debug_assertions(Vtb_seg_led_stop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_seg_led_stop___024root___eval_static(Vtb_seg_led_stop___024root* vlSelf);
void Vtb_seg_led_stop___024root___eval_initial(Vtb_seg_led_stop___024root* vlSelf);
void Vtb_seg_led_stop___024root___eval_settle(Vtb_seg_led_stop___024root* vlSelf);
void Vtb_seg_led_stop___024root___eval(Vtb_seg_led_stop___024root* vlSelf);

void Vtb_seg_led_stop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_seg_led_stop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_seg_led_stop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_seg_led_stop___024root___eval_static(&(vlSymsp->TOP));
        Vtb_seg_led_stop___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_seg_led_stop___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_seg_led_stop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_seg_led_stop::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_seg_led_stop::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_seg_led_stop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_seg_led_stop___024root___eval_final(Vtb_seg_led_stop___024root* vlSelf);

VL_ATTR_COLD void Vtb_seg_led_stop::final() {
    contextp()->executingFinal(true);
    Vtb_seg_led_stop___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_seg_led_stop::hierName() const { return vlSymsp->name(); }
const char* Vtb_seg_led_stop::modelName() const { return "Vtb_seg_led_stop"; }
unsigned Vtb_seg_led_stop::threads() const { return 1; }
void Vtb_seg_led_stop::prepareClone() const { contextp()->prepareClone(); }
void Vtb_seg_led_stop::atClone() const {
    contextp()->threadPoolpOnClone();
}
