// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___settle__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__1\n"); );
    // Body
    vlSelf->VGA_R = (0xffU & (vlSelf->top__DOT__vga_data 
                              >> 0x10U));
    vlSelf->VGA_G = (0xffU & (vlSelf->top__DOT__vga_data 
                              >> 8U));
    vlSelf->VGA_B = (0xffU & vlSelf->top__DOT__vga_data);
    vlSelf->top__DOT__mu_seg__DOT__segs[0U] = 0xfdU;
    vlSelf->top__DOT__mu_seg__DOT__segs[1U] = 0x60U;
    vlSelf->top__DOT__mu_seg__DOT__segs[2U] = 0xdaU;
    vlSelf->top__DOT__mu_seg__DOT__segs[3U] = 0xf2U;
    vlSelf->top__DOT__mu_seg__DOT__segs[4U] = 0x66U;
    vlSelf->top__DOT__mu_seg__DOT__segs[5U] = 0xb6U;
    vlSelf->top__DOT__mu_seg__DOT__segs[6U] = 0xbeU;
    vlSelf->top__DOT__mu_seg__DOT__segs[7U] = 0xe0U;
    vlSelf->VGA_CLK = vlSelf->clk;
    vlSelf->ledr = ((0xfffeU & (IData)(vlSelf->ledr)) 
                    | (1U & ((IData)(vlSelf->sw) ^ 
                             ((IData)(vlSelf->sw) >> 1U))));
    vlSelf->VGA_HSYNC = (0x60U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt));
    vlSelf->VGA_VSYNC = (2U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt));
    vlSelf->VGA_BLANK_N = (((0x90U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt)) 
                            & (0x310U >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt))) 
                           & ((0x23U < (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt)) 
                              & (0x203U >= (IData)(vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt))));
    vlSelf->seg0 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [vlSelf->top__DOT__mu_seg__DOT__offset]));
    vlSelf->seg1 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg2 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(2U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg3 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(3U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg4 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(4U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg5 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(5U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg6 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(6U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
    vlSelf->seg7 = (0xffU & (~ vlSelf->top__DOT__mu_seg__DOT__segs
                             [(7U & ((IData)(7U) + (IData)(vlSelf->top__DOT__mu_seg__DOT__offset)))]));
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__1(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->sw = 0;
    vlSelf->ps2_clk = 0;
    vlSelf->ps2_data = 0;
    vlSelf->ledr = 0;
    vlSelf->VGA_CLK = 0;
    vlSelf->VGA_HSYNC = 0;
    vlSelf->VGA_VSYNC = 0;
    vlSelf->VGA_BLANK_N = 0;
    vlSelf->VGA_R = 0;
    vlSelf->VGA_G = 0;
    vlSelf->VGA_B = 0;
    vlSelf->seg0 = 0;
    vlSelf->seg1 = 0;
    vlSelf->seg2 = 0;
    vlSelf->seg3 = 0;
    vlSelf->seg4 = 0;
    vlSelf->seg5 = 0;
    vlSelf->seg6 = 0;
    vlSelf->seg7 = 0;
    vlSelf->top__DOT__vga_data = 0;
    vlSelf->top__DOT__my_vga_ctrl__DOT__x_cnt = 0;
    vlSelf->top__DOT__my_vga_ctrl__DOT__y_cnt = 0;
    vlSelf->top__DOT__my_keyboard__DOT__buffer = 0;
    vlSelf->top__DOT__my_keyboard__DOT__count = 0;
    vlSelf->top__DOT__my_keyboard__DOT__ps2_clk_sync = 0;
    vlSelf->top__DOT__my_keyboard__DOT____Vlvbound_h04945a15__0 = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->top__DOT__mu_seg__DOT__segs[__Vi0] = 0;
    }
    vlSelf->top__DOT__mu_seg__DOT__count = 0;
    vlSelf->top__DOT__mu_seg__DOT__offset = 0;
}
