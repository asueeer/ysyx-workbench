// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux41v2.h for the primary calling header

#ifndef VERILATED_VMUX41V2___024ROOT_H_
#define VERILATED_VMUX41V2___024ROOT_H_  // guard

#include "verilated.h"

class Vmux41v2__Syms;
VL_MODULE(Vmux41v2___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(x0,1,0);
    VL_IN8(x1,1,0);
    VL_IN8(x2,1,0);
    VL_IN8(x3,1,0);
    VL_IN8(y,1,0);
    VL_OUT8(f,1,0);

    // INTERNAL VARIABLES
    Vmux41v2__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vmux41v2___024root(const char* name);
    ~Vmux41v2___024root();
    VL_UNCOPYABLE(Vmux41v2___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vmux41v2__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
