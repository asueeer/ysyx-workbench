// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux41v2.h for the primary calling header

#include "verilated.h"

#include "Vmux41v2___024root.h"

VL_INLINE_OPT void Vmux41v2___024root___combo__TOP__1(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___combo__TOP__1\n"); );
    // Body
    if ((0U == (IData)(vlSelf->y))) {
        vlSelf->f = vlSelf->x0;
    } else if ((1U == (IData)(vlSelf->y))) {
        vlSelf->f = vlSelf->x1;
    } else if ((2U == (IData)(vlSelf->y))) {
        vlSelf->f = vlSelf->x2;
    } else if ((3U == (IData)(vlSelf->y))) {
        vlSelf->f = vlSelf->x3;
    }
}

void Vmux41v2___024root___eval(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___eval\n"); );
    // Body
    Vmux41v2___024root___combo__TOP__1(vlSelf);
}

#ifdef VL_DEBUG
void Vmux41v2___024root___eval_debug_assertions(Vmux41v2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux41v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux41v2___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->x0 & 0xfcU))) {
        Verilated::overWidthError("x0");}
    if (VL_UNLIKELY((vlSelf->x1 & 0xfcU))) {
        Verilated::overWidthError("x1");}
    if (VL_UNLIKELY((vlSelf->x2 & 0xfcU))) {
        Verilated::overWidthError("x2");}
    if (VL_UNLIKELY((vlSelf->x3 & 0xfcU))) {
        Verilated::overWidthError("x3");}
    if (VL_UNLIKELY((vlSelf->y & 0xfcU))) {
        Verilated::overWidthError("y");}
}
#endif  // VL_DEBUG
