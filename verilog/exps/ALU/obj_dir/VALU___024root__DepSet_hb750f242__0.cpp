// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "verilated.h"

#include "VALU___024root.h"

VL_INLINE_OPT void VALU___024root___combo__TOP__1(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->ALU__DOT__addsub4inst1__DOT__B1 = (0xfU 
                                               & ((IData)(vlSelf->B) 
                                                  ^ 
                                                  (- (IData)(
                                                             (1U 
                                                              == (IData)(vlSelf->sel))))));
    vlSelf->carry = (1U & ((((IData)(vlSelf->A) + (IData)(vlSelf->ALU__DOT__addsub4inst1__DOT__B1)) 
                            + (1U == (IData)(vlSelf->sel))) 
                           >> 4U));
    vlSelf->ALU__DOT__result0 = (0xfU & (((IData)(vlSelf->A) 
                                          + (IData)(vlSelf->ALU__DOT__addsub4inst1__DOT__B1)) 
                                         + (1U == (IData)(vlSelf->sel))));
    vlSelf->zero = (0U == (IData)(vlSelf->ALU__DOT__result0));
    vlSelf->overflow = (((1U & ((IData)(vlSelf->A) 
                                >> 3U)) == (1U & ((IData)(vlSelf->ALU__DOT__addsub4inst1__DOT__B1) 
                                                  >> 3U))) 
                        & ((1U & ((IData)(vlSelf->ALU__DOT__result0) 
                                  >> 3U)) != (1U & 
                                              ((IData)(vlSelf->A) 
                                               >> 3U))));
    vlSelf->result = (((((((((0U == (IData)(vlSelf->sel)) 
                             | (1U == (IData)(vlSelf->sel))) 
                            | (2U == (IData)(vlSelf->sel))) 
                           | (3U == (IData)(vlSelf->sel))) 
                          | (4U == (IData)(vlSelf->sel))) 
                         | (5U == (IData)(vlSelf->sel))) 
                        | (6U == (IData)(vlSelf->sel))) 
                       | (7U == (IData)(vlSelf->sel)))
                       ? (0xfU & ((0U == (IData)(vlSelf->sel))
                                   ? (IData)(vlSelf->ALU__DOT__result0)
                                   : ((1U == (IData)(vlSelf->sel))
                                       ? (IData)(vlSelf->ALU__DOT__result0)
                                       : ((2U == (IData)(vlSelf->sel))
                                           ? (~ (IData)(vlSelf->A))
                                           : ((3U == (IData)(vlSelf->sel))
                                               ? ((IData)(vlSelf->A) 
                                                  & (IData)(vlSelf->B))
                                               : ((4U 
                                                   == (IData)(vlSelf->sel))
                                                   ? 
                                                  ((IData)(vlSelf->A) 
                                                   | (IData)(vlSelf->B))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->sel))
                                                    ? 
                                                   ((IData)(vlSelf->A) 
                                                    ^ (IData)(vlSelf->B))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->sel))
                                                     ? 
                                                    ((IData)(vlSelf->A) 
                                                     < (IData)(vlSelf->B))
                                                     : 
                                                    ((IData)(vlSelf->A) 
                                                     == (IData)(vlSelf->B))))))))))
                       : 0U);
}

void VALU___024root___eval(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval\n"); );
    // Body
    VALU___024root___combo__TOP__1(vlSelf);
}

#ifdef VL_DEBUG
void VALU___024root___eval_debug_assertions(VALU___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((vlSelf->A & 0xf0U))) {
        Verilated::overWidthError("A");}
    if (VL_UNLIKELY((vlSelf->B & 0xf0U))) {
        Verilated::overWidthError("B");}
}
#endif  // VL_DEBUG
