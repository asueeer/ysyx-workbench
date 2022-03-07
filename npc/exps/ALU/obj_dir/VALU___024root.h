// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU.h for the primary calling header

#ifndef VERILATED_VALU___024ROOT_H_
#define VERILATED_VALU___024ROOT_H_  // guard

#include "verilated.h"

class VALU__Syms;
VL_MODULE(VALU___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sel,2,0);
    VL_IN8(A,3,0);
    VL_IN8(B,3,0);
    VL_OUT8(result,3,0);
    VL_OUT8(zero,0,0);
    VL_OUT8(carry,0,0);
    VL_OUT8(overflow,0,0);
    CData/*3:0*/ ALU__DOT__result0;
    CData/*3:0*/ ALU__DOT__addsub4inst1__DOT__B1;

    // INTERNAL VARIABLES
    VALU__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    VALU___024root(const char* name);
    ~VALU___024root();
    VL_UNCOPYABLE(VALU___024root);

    // INTERNAL METHODS
    void __Vconfigure(VALU__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
