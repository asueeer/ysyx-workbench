// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "verilated.h"

#include "VALU___024root.h"

VL_ATTR_COLD void VALU___024root___eval_initial(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_initial\n"); );
}

void VALU___024root___combo__TOP__1(VALU___024root* vlSelf);

VL_ATTR_COLD void VALU___024root___eval_settle(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_settle\n"); );
    // Body
    VALU___024root___combo__TOP__1(vlSelf);
}

VL_ATTR_COLD void VALU___024root___final(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___final\n"); );
}

VL_ATTR_COLD void VALU___024root___ctor_var_reset(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sel = VL_RAND_RESET_I(3);
    vlSelf->A = VL_RAND_RESET_I(4);
    vlSelf->B = VL_RAND_RESET_I(4);
    vlSelf->result = VL_RAND_RESET_I(4);
    vlSelf->zero = VL_RAND_RESET_I(1);
    vlSelf->carry = VL_RAND_RESET_I(1);
    vlSelf->overflow = VL_RAND_RESET_I(1);
    vlSelf->ALU__DOT__result0 = VL_RAND_RESET_I(4);
    vlSelf->ALU__DOT__addsub4inst1__DOT__B1 = VL_RAND_RESET_I(4);
}
