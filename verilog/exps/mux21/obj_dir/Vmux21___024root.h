// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmux21.h for the primary calling header

#ifndef VERILATED_VMUX21___024ROOT_H_
#define VERILATED_VMUX21___024ROOT_H_  // guard

#include "verilated.h"

class Vmux21__Syms;
VL_MODULE(Vmux21___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,0,0);
    VL_IN8(b,0,0);
    VL_IN8(s,0,0);
    VL_OUT8(y,0,0);

    // INTERNAL VARIABLES
    Vmux21__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vmux21___024root(const char* name);
    ~Vmux21___024root();
    VL_UNCOPYABLE(Vmux21___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vmux21__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
