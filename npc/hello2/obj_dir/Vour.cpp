// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vour.h"
#include "Vour__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vour::Vour(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vour__Syms(_vcontextp__, _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
}

Vour::Vour(const char* _vcname__)
    : Vour(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vour::~Vour() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vour___024root___eval_initial(Vour___024root* vlSelf);
void Vour___024root___eval_settle(Vour___024root* vlSelf);
void Vour___024root___eval(Vour___024root* vlSelf);
#ifdef VL_DEBUG
void Vour___024root___eval_debug_assertions(Vour___024root* vlSelf);
#endif  // VL_DEBUG
void Vour___024root___final(Vour___024root* vlSelf);

static void _eval_initial_loop(Vour__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vour___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vour___024root___eval_settle(&(vlSymsp->TOP));
        Vour___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vour::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vour::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vour___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vour___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vour::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vour::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vour::final() {
    Vour___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vour___024root__trace_init_top(Vour___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vour___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vour___024root*>(voidSelf);
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vour___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vour___024root__trace_register(Vour___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vour::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vour___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
