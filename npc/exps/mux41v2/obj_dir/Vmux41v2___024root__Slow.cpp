// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux41v2.h for the primary calling header

#include "verilated.h"

#include "Vmux41v2__Syms.h"
#include "Vmux41v2___024root.h"

void Vmux41v2___024root___ctor_var_reset(Vmux41v2___024root* vlSelf);

Vmux41v2___024root::Vmux41v2___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vmux41v2___024root___ctor_var_reset(this);
}

void Vmux41v2___024root::__Vconfigure(Vmux41v2__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vmux41v2___024root::~Vmux41v2___024root() {
}
