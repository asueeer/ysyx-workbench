// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vour__Syms.h"


VL_ATTR_COLD void Vour___024root__trace_init_sub_0(Vour___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vour___024root__trace_init_top(Vour___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root__trace_init_top\n"); );
    // Body
    Vour___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vour___024root__trace_init_sub_0(Vour___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
}

void Vour___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vour___024root__trace_register(Vour___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vour__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vour___024root__trace_register\n"); );
    // Body
    tracep->addCleanupCb(&Vour___024root__trace_cleanup, vlSelf);
}
