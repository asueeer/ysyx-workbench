// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux21__Syms.h"


VL_ATTR_COLD void Vmux21___024root__trace_init_sub_0(Vmux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux21___024root__trace_init_top(Vmux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root__trace_init_top\n"); );
    // Body
    Vmux21___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmux21___024root__trace_init_sub_0(Vmux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+3,"s", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->declBit(c+1,"mux21 a", false,-1);
    tracep->declBit(c+2,"mux21 b", false,-1);
    tracep->declBit(c+3,"mux21 s", false,-1);
    tracep->declBit(c+4,"mux21 y", false,-1);
}

VL_ATTR_COLD void Vmux21___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vmux21___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vmux21___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmux21___024root__trace_register(Vmux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vmux21___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vmux21___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vmux21___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmux21___024root__trace_full_sub_0(Vmux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux21___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root__trace_full_top_0\n"); );
    // Init
    Vmux21___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux21___024root*>(voidSelf);
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmux21___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vmux21___024root__trace_full_sub_0(Vmux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullBit(oldp+1,(vlSelf->a));
    tracep->fullBit(oldp+2,(vlSelf->b));
    tracep->fullBit(oldp+3,(vlSelf->s));
    tracep->fullBit(oldp+4,(vlSelf->y));
}
