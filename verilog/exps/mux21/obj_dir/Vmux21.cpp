// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmux21.h"
#include "Vmux21__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmux21::Vmux21(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vmux21__Syms(_vcontextp__, _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
}

Vmux21::Vmux21(const char* _vcname__)
    : Vmux21(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vmux21::~Vmux21() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vmux21___024root___eval_initial(Vmux21___024root* vlSelf);
void Vmux21___024root___eval_settle(Vmux21___024root* vlSelf);
void Vmux21___024root___eval(Vmux21___024root* vlSelf);
#ifdef VL_DEBUG
void Vmux21___024root___eval_debug_assertions(Vmux21___024root* vlSelf);
#endif  // VL_DEBUG
void Vmux21___024root___final(Vmux21___024root* vlSelf);

static void _eval_initial_loop(Vmux21__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vmux21___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vmux21___024root___eval_settle(&(vlSymsp->TOP));
        Vmux21___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vmux21::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmux21::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmux21___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vmux21___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vmux21::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vmux21::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmux21::final() {
    Vmux21___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Trace configuration

void Vmux21___024root__trace_init_top(Vmux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmux21___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux21___024root*>(voidSelf);
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vmux21___024root__trace_init_top(vlSelf, tracep);
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vmux21___024root__trace_register(Vmux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux21::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmux21___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
