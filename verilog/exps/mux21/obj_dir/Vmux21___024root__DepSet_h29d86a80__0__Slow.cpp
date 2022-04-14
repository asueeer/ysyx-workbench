// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux21.h for the primary calling header

#include "verilated.h"

#include "Vmux21___024root.h"

VL_ATTR_COLD void Vmux21___024root___eval_initial(Vmux21___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root___eval_initial\n"); );
}

void Vmux21___024root___combo__TOP__1(Vmux21___024root* vlSelf);

VL_ATTR_COLD void Vmux21___024root___eval_settle(Vmux21___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root___eval_settle\n"); );
    // Body
    Vmux21___024root___combo__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vmux21___024root___final(Vmux21___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root___final\n"); );
}

VL_ATTR_COLD void Vmux21___024root___ctor_var_reset(Vmux21___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->s = VL_RAND_RESET_I(1);
    vlSelf->y = VL_RAND_RESET_I(1);
}
