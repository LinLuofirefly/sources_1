// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_first_seg_debug__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtb_first_seg_debug::Vtb_first_seg_debug(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_first_seg_debug__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtb_first_seg_debug::Vtb_first_seg_debug(const char* _vcname__)
    : Vtb_first_seg_debug(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_first_seg_debug::~Vtb_first_seg_debug() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_first_seg_debug___024root___eval_debug_assertions(Vtb_first_seg_debug___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_first_seg_debug___024root___eval_static(Vtb_first_seg_debug___024root* vlSelf);
void Vtb_first_seg_debug___024root___eval_initial(Vtb_first_seg_debug___024root* vlSelf);
void Vtb_first_seg_debug___024root___eval_settle(Vtb_first_seg_debug___024root* vlSelf);
void Vtb_first_seg_debug___024root___eval(Vtb_first_seg_debug___024root* vlSelf);

void Vtb_first_seg_debug::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_first_seg_debug::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_first_seg_debug___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_first_seg_debug___024root___eval_static(&(vlSymsp->TOP));
        Vtb_first_seg_debug___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_first_seg_debug___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_first_seg_debug___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_first_seg_debug::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_first_seg_debug::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_first_seg_debug::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_first_seg_debug___024root___eval_final(Vtb_first_seg_debug___024root* vlSelf);

VL_ATTR_COLD void Vtb_first_seg_debug::final() {
    contextp()->executingFinal(true);
    Vtb_first_seg_debug___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_first_seg_debug::hierName() const { return vlSymsp->name(); }
const char* Vtb_first_seg_debug::modelName() const { return "Vtb_first_seg_debug"; }
unsigned Vtb_first_seg_debug::threads() const { return 1; }
void Vtb_first_seg_debug::prepareClone() const { contextp()->prepareClone(); }
void Vtb_first_seg_debug::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtb_first_seg_debug::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtb_first_seg_debug___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtb_first_seg_debug___024root__trace_init_top(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtb_first_seg_debug___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_first_seg_debug___024root*>(voidSelf);
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtb_first_seg_debug___024root__trace_decl_types(tracep);
    Vtb_first_seg_debug___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_first_seg_debug___024root__trace_register(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtb_first_seg_debug::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtb_first_seg_debug::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 354);
    Vtb_first_seg_debug___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
