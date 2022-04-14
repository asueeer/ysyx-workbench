// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux41v2.h for the primary calling header

#include "verilated.h"

#include "Vmux41v2___024root.h"

VL_ATTR_COLD void Vmux41v2___024root___eval_initial(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___eval_initial\n"); );
}

void Vmux41v2___024root___combo__TOP__1(Vmux41v2___024root* vlSelf);

VL_ATTR_COLD void Vmux41v2___024root___eval_settle(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___eval_settle\n"); );
    // Body
    Vmux41v2___024root___combo__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vmux41v2___024root___final(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___final\n"); );
}

VL_ATTR_COLD void Vmux41v2___024root___ctor_var_reset(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->x0 = VL_RAND_RESET_I(2);
    vlSelf->x1 = VL_RAND_RESET_I(2);
    vlSelf->x2 = VL_RAND_RESET_I(2);
    vlSelf->x3 = VL_RAND_RESET_I(2);
    vlSelf->y = VL_RAND_RESET_I(2);
    vlSelf->f = VL_RAND_RESET_I(2);
}
