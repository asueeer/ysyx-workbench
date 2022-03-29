// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vmux41v2__Syms.h"


VL_ATTR_COLD void Vmux41v2___024root__trace_init_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux41v2___024root__trace_init_top(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_init_top\n"); );
    // Body
    Vmux41v2___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmux41v2___024root__trace_init_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBus(c+1,"x0", false,-1, 1,0);
    tracep->declBus(c+2,"x1", false,-1, 1,0);
    tracep->declBus(c+3,"x2", false,-1, 1,0);
    tracep->declBus(c+4,"x3", false,-1, 1,0);
    tracep->declBus(c+5,"y", false,-1, 1,0);
    tracep->declBus(c+6,"f", false,-1, 1,0);
    tracep->declBus(c+1,"mux41v2 x0", false,-1, 1,0);
    tracep->declBus(c+2,"mux41v2 x1", false,-1, 1,0);
    tracep->declBus(c+3,"mux41v2 x2", false,-1, 1,0);
    tracep->declBus(c+4,"mux41v2 x3", false,-1, 1,0);
    tracep->declBus(c+5,"mux41v2 y", false,-1, 1,0);
    tracep->declBus(c+6,"mux41v2 f", false,-1, 1,0);
}

VL_ATTR_COLD void Vmux41v2___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vmux41v2___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vmux41v2___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmux41v2___024root__trace_register(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vmux41v2___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vmux41v2___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vmux41v2___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmux41v2___024root__trace_full_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmux41v2___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_full_top_0\n"); );
    // Init
    Vmux41v2___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmux41v2___024root*>(voidSelf);
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vmux41v2___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vmux41v2___024root__trace_full_sub_0(Vmux41v2___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+1,(vlSelf->x0),2);
    tracep->fullCData(oldp+2,(vlSelf->x1),2);
    tracep->fullCData(oldp+3,(vlSelf->x2),2);
    tracep->fullCData(oldp+4,(vlSelf->x3),2);
    tracep->fullCData(oldp+5,(vlSelf->y),2);
    tracep->fullCData(oldp+6,(vlSelf->f),2);
}
