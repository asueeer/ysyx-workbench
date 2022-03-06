// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux41v2__Syms.h"


void Vmux41v2___024root__trace_chg_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep);

void Vmux41v2___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_chg_top_0\n"); );
    // Init
    Vmux41v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux41v2___024root*>(voidSelf);
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vmux41v2___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vmux41v2___024root__trace_chg_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_chg_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    tracep->chgCData(oldp+0,(vlSelf->x0),2);
    tracep->chgCData(oldp+1,(vlSelf->x1),2);
    tracep->chgCData(oldp+2,(vlSelf->x2),2);
    tracep->chgCData(oldp+3,(vlSelf->x3),2);
    tracep->chgCData(oldp+4,(vlSelf->y),2);
    tracep->chgCData(oldp+5,(vlSelf->f),2);
}

void Vmux41v2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_cleanup\n"); );
    // Init
    Vmux41v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux41v2___024root*>(voidSelf);
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
