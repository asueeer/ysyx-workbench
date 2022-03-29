// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


VL_ATTR_COLD void VALU___024root__trace_init_sub_0(VALU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VALU___024root__trace_init_top(VALU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root__trace_init_top\n"); );
    // Body
    VALU___024root__trace_init_sub_0(vlSelf, tracep);
}

VL_ATTR_COLD void VALU___024root__trace_init_sub_0(VALU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root__trace_init_sub_0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    tracep->declBus(c+1,"sel", false,-1, 2,0);
    tracep->declBus(c+2,"A", false,-1, 3,0);
    tracep->declBus(c+3,"B", false,-1, 3,0);
    tracep->declBus(c+4,"result", false,-1, 3,0);
    tracep->declBit(c+5,"zero", false,-1);
    tracep->declBit(c+6,"carry", false,-1);
    tracep->declBit(c+7,"overflow", false,-1);
    tracep->declBus(c+1,"ALU sel", false,-1, 2,0);
    tracep->declBus(c+2,"ALU A", false,-1, 3,0);
    tracep->declBus(c+3,"ALU B", false,-1, 3,0);
    tracep->declBus(c+4,"ALU result", false,-1, 3,0);
    tracep->declBit(c+5,"ALU zero", false,-1);
    tracep->declBit(c+6,"ALU carry", false,-1);
    tracep->declBit(c+7,"ALU overflow", false,-1);
    tracep->declBus(c+8,"ALU result0", false,-1, 3,0);
    tracep->declBit(c+9,"ALU sub", false,-1);
    tracep->declBus(c+2,"ALU addsub4inst1 A", false,-1, 3,0);
    tracep->declBus(c+3,"ALU addsub4inst1 B", false,-1, 3,0);
    tracep->declBit(c+9,"ALU addsub4inst1 sub", false,-1);
    tracep->declBus(c+8,"ALU addsub4inst1 result", false,-1, 3,0);
    tracep->declBit(c+5,"ALU addsub4inst1 zero", false,-1);
    tracep->declBit(c+6,"ALU addsub4inst1 carry", false,-1);
    tracep->declBit(c+7,"ALU addsub4inst1 overflow", false,-1);
    tracep->declBus(c+10,"ALU addsub4inst1 B1", false,-1, 3,0);
    tracep->declBus(c+2,"ALU addsub4inst1 add4inst1 A", false,-1, 3,0);
    tracep->declBus(c+10,"ALU addsub4inst1 add4inst1 B", false,-1, 3,0);
    tracep->declBit(c+9,"ALU addsub4inst1 add4inst1 cin", false,-1);
    tracep->declBus(c+8,"ALU addsub4inst1 add4inst1 result", false,-1, 3,0);
    tracep->declBit(c+6,"ALU addsub4inst1 add4inst1 carry", false,-1);
    tracep->declBit(c+7,"ALU addsub4inst1 add4inst1 overflow", false,-1);
}

VL_ATTR_COLD void VALU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void VALU___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void VALU___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VALU___024root__trace_register(VALU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VALU___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VALU___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VALU___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VALU___024root__trace_full_sub_0(VALU___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VALU___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root__trace_full_top_0\n"); );
    // Init
    VALU___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VALU___024root*>(voidSelf);
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VALU___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void VALU___024root__trace_full_sub_0(VALU___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root__trace_full_sub_0\n"); );
    // Init
    vluint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullCData(oldp+1,(vlSelf->sel),3);
    tracep->fullCData(oldp+2,(vlSelf->A),4);
    tracep->fullCData(oldp+3,(vlSelf->B),4);
    tracep->fullCData(oldp+4,(vlSelf->result),4);
    tracep->fullBit(oldp+5,(vlSelf->zero));
    tracep->fullBit(oldp+6,(vlSelf->carry));
    tracep->fullBit(oldp+7,(vlSelf->overflow));
    tracep->fullCData(oldp+8,(vlSelf->ALU__DOT__result0),4);
    tracep->fullBit(oldp+9,((1U == (IData)(vlSelf->sel))));
    tracep->fullCData(oldp+10,(vlSelf->ALU__DOT__addsub4inst1__DOT__B1),4);
}
