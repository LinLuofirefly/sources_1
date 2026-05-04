// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_seg_led_stop.h for the primary calling header

#include "Vtb_seg_led_stop__pch.h"

VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__0(Vtb_seg_led_stop___024root* vlSelf);
VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__1(Vtb_seg_led_stop___024root* vlSelf);
VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__2(Vtb_seg_led_stop___024root* vlSelf);
VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__3(Vtb_seg_led_stop___024root* vlSelf);

void Vtb_seg_led_stop___024root___eval_initial(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i;
    __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0;
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz = 0U;
    VL_READMEM_N(true, 32, 4096, 0, "sim/irom.mem"s
                 ,  &(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem)
                 , 0, ~0ULL);
    __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i = 0U;
    while (VL_GTS_III(32, 0x00010000U, __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[(0x0000ffffU 
                                                                                & __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i)] = 0U;
        __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i 
            = ((IData)(1U) + __Vinline__eval_initial__TOP_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i);
    }
    VL_READMEM_N(true, 32, 65536, 0, "sim/dram.mem"s
                 ,  &(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem)
                 , 0, ~0ULL);
    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__3(vlSelf);
}

VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__0(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__virtual_key = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__virtual_sw = 0ULL;
    vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst = 1U;
    vlSelfRef.tb_seg_led_stop__DOT__cycle_count = 0ULL;
    vlSelfRef.tb_seg_led_stop__DOT__seg_write_count = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__led_write_count = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__same_pc_count = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__prev_pc = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__second_seg_cycle = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x0000000000004e20ULL, 
                                         nullptr, "new/tb_seg_led_stop.sv", 
                                         73);
    vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst = 0U;
    co_return;
}

VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__1(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0xfffffc08eb57e000ULL, 
                                         nullptr, "new/tb_seg_led_stop.sv", 
                                         127);
    VL_WRITEF_NX("SEG_LED_STOP_TIMEOUT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led=%08h seg=%010h second_seg_cycle=%0d same_pc=%0d\n",10, 'T',-9
                 , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                 , '#',64,VL_TIME_UNITED_Q(1000), '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                 , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                 , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                 , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2
                 , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2
                 , '~',32,vlSelfRef.tb_seg_led_stop__DOT__second_seg_cycle
                 , '~',32,vlSelfRef.tb_seg_led_stop__DOT__same_pc_count);
    VL_FINISH_MT("new/tb_seg_led_stop.sv", 46, "");
    co_return;
}

VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__2(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000002710ULL, 
                                             nullptr, 
                                             "new/tb_seg_led_stop.sv", 
                                             39);
        vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz 
            = (1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz)));
    }
    co_return;
}

VlCoroutine Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__3(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_initial__TOP__Vtiming__3\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (VL_LIKELY(!vlSymsp->_vm_contextp__->gotFinish())) {
        co_await vlSelfRef.__VdlySched.delay(0x0000000000000ad9ULL, 
                                             nullptr, 
                                             "new/tb_seg_led_stop.sv", 
                                             36);
        vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk = 
            (1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk)));
    }
    co_return;
}

void Vtb_seg_led_stop___024root___eval_triggers_vec__act(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_triggers_vec__act\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    (((vlSelfRef.__VdlySched.awaitingCurrentTime() 
                                                       << 3U) 
                                                      | (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_rst__0))) 
                                                         << 2U)) 
                                                     | ((((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_50Mhz__0))) 
                                                         << 1U) 
                                                        | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_cpu_clk__0)))))));
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_cpu_clk__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_cpu_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_50Mhz__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_clk_50Mhz;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_seg_led_stop__DOT__w_clk_rst__0 
        = vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst;
}

bool Vtb_seg_led_stop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_seg_led_stop___024root___act_sequent__TOP__0(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___act_sequent__TOP__0\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o = 0;
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = (1U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                 | ((~ ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)) 
                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o))) 
                    | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction;
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)) 
              & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                 | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (8U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
              & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                  | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                     | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
                        | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))))) 
              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o));
}

void Vtb_seg_led_stop___024root___eval_act(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_act\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_seg_led_stop___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_seg_led_stop___024root___nba_sequent__TOP__0(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_sequent__TOP__0\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__perip_rdata;
    tb_seg_led_stop__DOT__dut__DOT__perip_rdata = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0;
    CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i = 0;
    CData/*5:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr = 0;
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0;
    IData/*31:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata = 0;
    IData/*31:0*/ __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
    __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray;
    __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_7;
    __VdfgRegularize_h6e95ff9d_0_7 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_8;
    __VdfgRegularize_h6e95ff9d_0_8 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_9;
    __VdfgRegularize_h6e95ff9d_0_9 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_19;
    __VdfgRegularize_h6e95ff9d_0_19 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_20;
    __VdfgRegularize_h6e95ff9d_0_20 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_21;
    __VdfgRegularize_h6e95ff9d_0_21 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_22;
    __VdfgRegularize_h6e95ff9d_0_22 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_23;
    __VdfgRegularize_h6e95ff9d_0_23 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_24;
    __VdfgRegularize_h6e95ff9d_0_24 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_25;
    __VdfgRegularize_h6e95ff9d_0_25 = 0;
    CData/*0:0*/ __VdfgRegularize_h6e95ff9d_0_27;
    __VdfgRegularize_h6e95ff9d_0_27 = 0;
    CData/*4:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = 0;
    CData/*5:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = 0;
    CData/*5:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = 0;
    IData/*31:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__pc;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__pc = 0;
    CData/*0:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0;
    CData/*5:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0;
    IData/*31:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    SData/*15:0*/ __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0;
    // Body
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 0U;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 0U;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 0U;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 0U;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 0U;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 0U;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 0U;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__pc = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)))) {
        vlSelfRef.tb_seg_led_stop__DOT__cycle_count 
            = (1ULL + vlSelfRef.tb_seg_led_stop__DOT__cycle_count);
        if ((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc 
             == vlSelfRef.tb_seg_led_stop__DOT__prev_pc)) {
            vlSelfRef.tb_seg_led_stop__DOT__same_pc_count 
                = ((IData)(1U) + vlSelfRef.tb_seg_led_stop__DOT__same_pc_count);
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__same_pc_count = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__prev_pc 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc;
        }
        if (VL_UNLIKELY(((VL_LTS_IQQ(64, 0x0000000000000064ULL, vlSelfRef.tb_seg_led_stop__DOT__cycle_count) 
                          & (0x80000000U > vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc))))) {
            VL_WRITEF_NX("SEG_LED_STOP_FAIL reason=RUNAWAY_LOW_PC cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h second_seg_cycle=%0d same_pc=%0d\n",11, 'T',-9
                         , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__led_write_count
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__second_seg_cycle
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__same_pc_count);
            VL_FINISH_MT("new/tb_seg_led_stop.sv", 58, "");
        }
        if (VL_UNLIKELY((VL_LTES_III(32, 0x00030d40U, vlSelfRef.tb_seg_led_stop__DOT__same_pc_count)))) {
            VL_WRITEF_NX("SEG_LED_STOP_FAIL reason=STUCK_SAME_PC cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h second_seg_cycle=%0d same_pc=%0d\n",11, 'T',-9
                         , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__led_write_count
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__second_seg_cycle
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__same_pc_count);
            VL_FINISH_MT("new/tb_seg_led_stop.sv", 58, "");
        }
        if (VL_UNLIKELY(((0ULL == VL_MODDIVS_QQQ(64, vlSelfRef.tb_seg_led_stop__DOT__cycle_count, 0x00000000000f4240ULL))))) {
            VL_WRITEF_NX("SEG_LED_HEARTBEAT cyc=%0d time=%0t pc=%08h inst=%08h seg_writes=%0d led_writes=%0d led=%08h seg=%010h\n",9, 'T',-9
                         , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__led_write_count
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2);
        }
        if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)) 
                          & (0x80200020U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r))))) {
            vlSelfRef.tb_seg_led_stop__DOT__seg_write_count 
                = ((IData)(1U) + vlSelfRef.tb_seg_led_stop__DOT__seg_write_count);
            VL_WRITEF_NX("SEG_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b vseg=%010h\n",9, 'T',-9
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r
                         , '#',4,(IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2);
            if ((2U == vlSelfRef.tb_seg_led_stop__DOT__seg_write_count)) {
                vlSelfRef.tb_seg_led_stop__DOT__second_seg_cycle 
                    = (IData)(vlSelfRef.tb_seg_led_stop__DOT__cycle_count);
            }
        }
        if (VL_UNLIKELY((((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)) 
                          & (0x80200040U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r))))) {
            vlSelfRef.tb_seg_led_stop__DOT__led_write_count 
                = ((IData)(1U) + vlSelfRef.tb_seg_led_stop__DOT__led_write_count);
            VL_WRITEF_NX("LED_WRITE #%0d cyc=%0d time=%0t pc=%08h inst=%08h data=%08h wstrb=%b seg_writes=%0d vseg=%010h\nSEG_LED_STOP_DONE led=%08h seg=%010h seg_wdata=%08h seg_writes=%0d led_writes=%0d\n",15, 'T',-9
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__led_write_count
                         , '~',64,vlSelfRef.tb_seg_led_stop__DOT__cycle_count
                         , '#',64,VL_TIME_UNITED_Q(1000)
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r
                         , '#',4,(IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2
                         , '#',40,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2
                         , '#',32,vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__seg_write_count
                         , '~',32,vlSelfRef.tb_seg_led_stop__DOT__led_write_count);
            VL_FINISH_MT("new/tb_seg_led_stop.sv", 120, "");
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)))) {
        if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o) {
            __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
            __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0 = 1U;
        }
    }
    if ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
        if ((1U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0x000000ffU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r);
            __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 
                = (0x0000ffffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0 = 1U;
        }
        if ((2U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0x000000ffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                                  >> 8U));
            __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 
                = (0x0000ffffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1 = 1U;
        }
        if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0x000000ffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                                  >> 0x10U));
            __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 
                = (0x0000ffffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2 = 1U;
        }
        if ((8U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
                   >> 0x18U);
            __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 
                = (0x0000ffffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                  >> 2U));
            __VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3 = 1U;
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (1U & (((~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
                          | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i) 
                             | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o)))) 
                      & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o))
                      ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r)
                      : ((~ (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r) 
                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc 
                                 == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r)) 
                             | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o))) 
                         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o)))));
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r;
        __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r;
        __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0 = 1U;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_valid_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_ghr__DOT__data_r 
        = (0x0000003fU & ((- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))) 
                          & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_target__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r 
        = ((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
             & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_30))
             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
             : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_29))
                 ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                 : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_28))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                     : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_28)
                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                         : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
                             & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26))
                             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                             : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o))))) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r 
        = ((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12) 
             & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_30))
             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
             : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12) 
                 & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_29))
                 ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                 : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_32))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                     : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_32)
                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                         : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12) 
                             & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26))
                             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                             : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o))))) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r 
        = ((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
             & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                   & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                      == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                         >> 0x00000014U))))))
             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
             : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                    & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                          == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                             >> 0x00000014U))))))
                 ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                 : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                     & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_31))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                     : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_31)
                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                         : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                             & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                   == (0x0000001fU 
                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                          >> 0x00000014U)))))
                             ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                             : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o))))) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))));
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r = 0U;
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r = 0U;
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r = 0U;
    } else {
        if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
             | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
            if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
                 & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
                    = (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r) 
                                      - (IData)(1U)));
            }
            if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o) {
                if ((0x20U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r 
                        = (0x0000003fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r)));
                }
            }
            __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_next_r;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
            if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o) 
                 & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx;
            }
            if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o) {
                __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o;
                __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
                __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0 = 1U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r)));
            }
            __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_next_r;
        }
        if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o) {
            __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
                = ((0x0000003eU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r) 
                                   << 1U)) | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o));
        }
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0] 
            = __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras__v0;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r 
        = __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r 
        = __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r;
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[0U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[0U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[1U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[1U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[2U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[2U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[3U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[3U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[4U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[4U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[5U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[5U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[6U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[6U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[7U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[7U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[8U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[8U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[9U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[9U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[10U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[10U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[11U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[11U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[12U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[12U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[13U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[13U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[14U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[14U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[15U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[15U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[16U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[16U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[17U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[17U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[18U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[18U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[19U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[19U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[20U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[20U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[21U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[21U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[22U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[22U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[23U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[23U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[24U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[24U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[25U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[25U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[26U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[26U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[27U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[27U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[28U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[28U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[29U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[29U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[30U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[30U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[31U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[31U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[32U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[32U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[33U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[33U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[34U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[34U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[35U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[35U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[36U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[36U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[37U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[37U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[38U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[38U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[39U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[39U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[40U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[40U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[41U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[41U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[42U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[42U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[43U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[43U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[44U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[44U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[45U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[45U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[46U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[46U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[47U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[47U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[48U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[48U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[49U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[49U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[50U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[50U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[51U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[51U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[52U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[52U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[53U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[53U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[54U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[54U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[55U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[55U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[56U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[56U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[57U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[57U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[58U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[58U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[59U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[59U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[60U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[60U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[61U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[61U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[62U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[62U] = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[63U] = 1U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[63U] = 0U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o) {
        __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 
            = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid
               [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx]
                ? ((0U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                    [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                    ? ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                        ? 1U : 0U) : ((1U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                                       [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                                       ? ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                           ? 2U : 0U)
                                       : ((2U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                                           [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx])
                                           ? ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                               ? 3U
                                               : 1U)
                                           : ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                                               ? 3U
                                               : 2U))))
                : ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o)
                    ? 3U : 0U));
        __VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx;
        __VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0 = 1U;
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid__v0] = 1U;
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0] 
            = __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht__v0;
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0] 
            = __VdlyVal__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs__v0;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx 
        = (0x0000001fU & (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r) 
                           - (IData)(1U)) | (- (IData)(
                                                       (0U 
                                                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_sp_r))))));
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__pc = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)
                                                   ? 0x80000000U
                                                   : 
                                                  ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o)
                                                    ? 
                                                   ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1
                                                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o)
                                                    : 
                                                   ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o)
                                                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc
                                                     : 
                                                    ((IData)(4U) 
                                                     + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r 
           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
            [(0x0000ffffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                             >> 2U))];
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0] 
            = ((0xffffff00U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0]) 
               | (IData)(__VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v0));
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1] 
            = ((0xffff00ffU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1]) 
               | ((IData)(__VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v1) 
                  << 8U));
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2] 
            = ((0xff00ffffU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2]) 
               | ((IData)(__VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v2) 
                  << 0x00000010U));
    }
    if (__VdlySet__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem[__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3] 
            = ((0x00ffffffU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem
                [__VdlyDim0__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3]) 
               | ((IData)(__VdlyVal__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__mem__v3) 
                  << 0x00000018U));
    }
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 = 0ULL;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata = 0U;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1;
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2;
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout = 0;
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0x7fffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x80000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xbfffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x40000000U & ((0x40000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xc0000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xdfffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x20000000U & ((0x60000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xe0000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xefffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x10000000U & ((0x70000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xf0000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xf7ffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x08000000U & ((0x78000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xf8000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfbffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x04000000U & ((0x7c000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfc000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfdffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x02000000U & ((0x7e000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfe000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfeffffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x01000000U & ((0x7f000000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xff000000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xff7fffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00800000U & ((0x7f800000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xff800000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffbfffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00400000U & ((0x7fc00000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffc00000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffdfffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00200000U & ((0x7fe00000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffe00000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffefffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00100000U & ((0x7ff00000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfff00000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfff7ffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00080000U & ((0x7ff80000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfff80000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffbffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00040000U & ((0x7ffc0000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffc0000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffdffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00020000U & ((0x7ffe0000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffe0000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffeffffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00010000U & ((0x7fff0000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffff0000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffff7fffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00008000U & ((0x7fff8000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffff8000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffbfffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00004000U & ((0x7fffc000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffc000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffdfffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00002000U & ((0x7fffe000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffe000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffefffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00001000U & ((0x7ffff000U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffff000U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffff7ffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000800U & ((0x7ffff800U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffff800U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffbffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000400U & ((0x7ffffc00U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffc00U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffdffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000200U & ((0x7ffffe00U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffe00U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffeffU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000100U & ((0x7fffff00U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffff00U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffff7fU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000080U & ((0x7fffff80U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffff80U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffbfU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000040U & ((0x7fffffc0U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffffc0U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffdfU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000020U & ((0x7fffffe0U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xffffffe0U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xffffffefU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (0x00000010U & ((0x7ffffff0U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                                 >> 1U)) 
                                 ^ (0xfffffff0U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffff7U & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (8U & ((0x7ffffff8U & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffff8U 
                                                   & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffbU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (4U & ((0x7ffffffcU & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffcU 
                                                   & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffdU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (2U & ((0x7ffffffeU & (__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                                        >> 1U)) ^ (0xfffffffeU 
                                                   & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray))));
        __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
            = ((0xfffffffeU & __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout) 
               | (1U & ((__Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout 
                         >> 1U) ^ __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__gray)));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d 
            = __Vfunc_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__gray_to_bin__3__Vfuncout;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r;
        if ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
            if ((0x80200040U != vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                if ((0x80200020U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
                }
            }
        }
    }
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata 
        = (((0x80200000U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
             ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2)
             : ((0x80200004U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                 ? (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2 
                            >> 0x00000020U)) : ((0x80200010U 
                                                 == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                 ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2)
                                                 : 
                                                ((0x80200020U 
                                                  == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                  ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata
                                                  : 0xdeadbeefU)))) 
           & (- (IData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)))) {
        if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o = 1U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o 
                = (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                  >> 7U));
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o;
            if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                 | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o = 0U;
            } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o 
                    = (0x0000003fU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg;
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o 
                    = (0x0000003fU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
            }
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o 
                = (1U & ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                                   | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)))) 
                         && ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg)
                              ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg)
                              : (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o))));
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_reg_wen_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_rd_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_ctrl_flags_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellout__id_pipe_inst__pred_ghr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_target_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_pred_taken_o = 0U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg = 0U;
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i) {
            if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
                __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 1U;
            } else {
                __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 0U;
            }
        }
    } else if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) 
                & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i)))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_target_reg 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_ghr_reg 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg = 1U;
    }
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 = 0ULL;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r = 0x00000013U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r = 0x80000000U;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1 
            = vlSelfRef.tb_seg_led_stop__DOT__virtual_sw;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1 
            = vlSelfRef.tb_seg_led_stop__DOT__virtual_key;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1 
            = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
               ^ VL_SHIFTR_III(32,32,32, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin, 1U));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
            = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                ? 0x00000013U : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r);
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    tb_seg_led_stop__DOT__dut__DOT__perip_rdata = (
                                                   ((0x80200000U 
                                                     == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                     ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                     : 
                                                    ((0x80200004U 
                                                      == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                      ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                      : 
                                                     ((0x80200010U 
                                                       == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                       ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                       : 
                                                      ((0x80200020U 
                                                        == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                        ? tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                        : 
                                                       ((0x80200050U 
                                                         == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                                                         : 
                                                        (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                         & (- (IData)(
                                                                      ((0x80100000U 
                                                                        <= vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr) 
                                                                       & (0x8013ffffU 
                                                                          > vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)))))))))) 
                                                   & (- (IData)((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r 
        = __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg 
        = __Vdly__tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
        = (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_valid_r) 
               & ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r)) 
                  & ((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_addr_r 
                      >> 2U) == (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 >> 2U))))) ? ((((0x0000ff00U 
                                                  & (((8U 
                                                       & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                       ? 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                       >> 0x00000018U)
                                                       : 
                                                      (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                       >> 0x00000018U)) 
                                                     << 8U)) 
                                                 | (0x000000ffU 
                                                    & ((4U 
                                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                        ? 
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                        >> 0x00000010U)
                                                        : 
                                                       (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                        >> 0x00000010U)))) 
                                                << 0x00000010U) 
                                               | ((0x0000ff00U 
                                                   & (((2U 
                                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                        ? 
                                                       (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r 
                                                        >> 8U)
                                                        : 
                                                       (tb_seg_led_stop__DOT__dut__DOT__perip_rdata 
                                                        >> 8U)) 
                                                      << 8U)) 
                                                  | (0x000000ffU 
                                                     & ((1U 
                                                         & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_strb_r))
                                                         ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__recent_store_data_r
                                                         : tb_seg_led_stop__DOT__dut__DOT__perip_rdata))))
            : tb_seg_led_stop__DOT__dut__DOT__perip_rdata);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Mem_IROM__DOT__mem
        [(0x00000fffU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc 
                         >> 2U))];
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)
            ? ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                ? (((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                     ? (0x0000ffffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                           >> 0x00000010U)
                                        : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i))
                     : (0x000000ffU & ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                        ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 0x00000018U)
                                            : (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 0x00000010U))
                                        : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                            ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                               >> 8U)
                                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))) 
                   & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000dU))))))
                : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                    ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                       & (- (IData)((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU))))))
                    : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)
                        ? ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                            >> 0x0000001fU))) 
                                << 0x00000010U) | (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x00000010U))
                            : (((- (IData)((1U & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (0x0000ffffU 
                                                   & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))
                        : ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                            ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                >> 0x0000001fU))) 
                                    << 8U) | (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                              >> 0x00000018U))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x00000017U)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                 >> 0x00000010U))))
                            : ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r)
                                ? (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 0x0000000fU)))) 
                                    << 8U) | (0x000000ffU 
                                              & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                 >> 8U)))
                                : (((- (IData)((1U 
                                                & (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i 
                                                   >> 7U)))) 
                                    << 8U) | (0x000000ffU 
                                              & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__mem2_inst__mem_rd_data_i)))))))
            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r);
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)
            ? 0x00000013U : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o);
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o = 0x00000013U;
    } else if ((1U & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
            = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i)
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o
                : 0x00000013U);
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__pc = __Vdly__tb_seg_led_stop__DOT__dut__DOT__pc;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid 
        = (IData)(((0x00000067U == (0x0000707fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction)) 
                   & (((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_count_r)) 
                       & (~ (((1U == (0x0000001fU & 
                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 7U))) | (5U 
                                                   == 
                                                   (0x0000001fU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                       >> 7U)))) 
                             & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 7U)) 
                                == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                   >> 0x0000000fU)))))) 
                      & ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x0000000fU))) 
                         | (5U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                  >> 0x0000000fU)))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx 
        = (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ghr_r) 
                          ^ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                             >> 2U)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint 
        = (IData)((0x00000067U == (0x0000707fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link 
        = ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 7U))) | (5U == 
                                              (0x0000001fU 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                  >> 7U))));
    __VdfgRegularize_h6e95ff9d_0_19 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_20 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))));
    __VdfgRegularize_h6e95ff9d_0_8 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | (0x23U 
                                               == (0x0000007fU 
                                                   & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
    __VdfgRegularize_h6e95ff9d_0_22 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x0000000fU)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
    if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid) {
        if ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            if ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht_valid
                       [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx]
                        ? (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__bht
                           [tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__pred_idx] 
                           >> 1U) : (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                     >> 0x0000001fU)))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                       + (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                       >> 0x0000001fU))) 
                           << 0x0000000cU) | ((0x00000800U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                  << 4U)) 
                                              | ((0x000007e0U 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                     >> 0x00000014U)) 
                                                 | (0x0000001eU 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                       >> 7U))))));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else if ((0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                   + (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                   >> 0x0000001fU))) 
                       << 0x00000014U) | ((((0x000001feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x0000000bU)) 
                                            | (1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                           << 0x0000000bU) 
                                          | (0x000007feU 
                                             & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction 
                                                >> 0x00000014U)))));
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
        } else if ((0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction))) {
            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_pred_valid) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras
                    [vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__ras_top_idx];
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 1U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o = 0U;
        }
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
           & (0x6fU == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_jalr_hint) 
           & ((~ ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__rd_is_link) 
                  & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000fU)) 
                     == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 7U))))) 
              & ((1U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000fU))) 
                 | (5U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                          >> 0x0000000fU))))));
    __VdfgRegularize_h6e95ff9d_0_24 = ((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x00000014U)))));
    __VdfgRegularize_h6e95ff9d_0_7 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
    __VdfgRegularize_h6e95ff9d_0_9 = ((0U != (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))) 
                                      & ((0x33U == 
                                          (0x0000007fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                         | ((0x63U 
                                             == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                            | ((0x13U 
                                                == 
                                                (0x0000007fU 
                                                 & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                               | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_26 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                        >> 0x0000000fU))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_29 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x0000000fU)))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                  >> 0x00000014U)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x00000014U)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x00000014U))]));
    __VdfgRegularize_h6e95ff9d_0_27 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                          == (0x0000001fU 
                                              & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                 >> 0x0000000fU))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o 
        = ((0U == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                  >> 0x0000000fU)))
            ? 0U : (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                     & ((0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000000fU)) 
                        == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r)))
                     ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                     : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs
                    [(0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU))]));
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                                = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                >> 0x1fU))) 
                                    << 0x00000014U) 
                                   | ((((0x000001feU 
                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000000bU)) 
                                        | (1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                 >> 0x14U))) 
                                       << 0x0000000bU) 
                                      | (0x000007feU 
                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x00000014U))));
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 4U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        } else {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                        }
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 4U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    } else if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x1fU))) 
                                << 0x0000000cU) | (
                                                   (0x00000800U 
                                                    & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                       << 4U)) 
                                                   | ((0x000007e0U 
                                                       & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                          >> 0x00000014U)) 
                                                      | (0x0000001eU 
                                                         & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                            >> 7U)))));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                    = ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                        ? ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            : 0U) : 0U);
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o
                            : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                                ? (0x0000001fU & tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o)
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                    >> 0x0000000cU))) 
                      || (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x0000000cU)))) 
                     || (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x0000000cU))))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x1fU))) 
                            << 0x0000000cU) | ((0x00000fe0U 
                                                & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U)) 
                                               | (0x0000001fU 
                                                  & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                     >> 7U))));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs2_rdata_o;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
    } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
        if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                        = (0xfffff000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o);
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_addr_o;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o 
                    = ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                        ? (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                               >> 0x00000014U))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)
                            ? (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                              >> 0x00000014U))
                            : (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U))));
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o 
                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
        }
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
    } else {
        if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else if ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                    if ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
                    } else {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                            = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                            >> 0x0000001fU))) 
                                << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                   >> 0x00000014U));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                            = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                    }
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o 
                        = (((- (IData)((vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                        >> 0x0000001fU))) 
                            << 0x0000000cU) | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                               >> 0x00000014U));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_regs_rs1_rdata_o;
                }
            } else {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
            }
        } else {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_addr_offset_o = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_base_addr_o = 0U;
        }
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op2_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_live_op1_o = 0U;
    }
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | (0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr 
        = ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | ((3U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
              | (0x67U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
    __VdfgRegularize_h6e95ff9d_0_21 = ((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_20));
    __VdfgRegularize_h6e95ff9d_0_25 = ((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_20));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_30 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                 & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x0000000fU)))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
               & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                  & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                     == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x00000014U))))))
            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r) 
                   & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r)) 
                      & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                         == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                            >> 0x00000014U))))))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                    & (IData)(__VdfgRegularize_h6e95ff9d_0_24))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : ((IData)(__VdfgRegularize_h6e95ff9d_0_24)
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                        : (((IData)(__VdfgRegularize_h6e95ff9d_0_8) 
                            & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r) 
                               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r) 
                                  == (0x0000001fU & 
                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x00000014U)))))
                            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r)))));
    __VdfgRegularize_h6e95ff9d_0_23 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r) 
                                       & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r)) 
                                          & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                             == (0x0000001fU 
                                                 & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                    >> 0x0000000fU)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x00000014U))) 
                                                 & ((0x23U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                                                    | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex)));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x0000000fU))) 
                                                 & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12 = ((0U 
                                                  != 
                                                  (0x0000001fU 
                                                   & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                      >> 0x0000000fU))) 
                                                 & ((0x13U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                                                    | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                                                       | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex 
        = ((0x33U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
           | ((0x13U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
              | ((0x63U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                 | (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_emit_forwarding_inst__DOT__use_base_addr))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r 
           + (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
               & (IData)(__VdfgRegularize_h6e95ff9d_0_23))
               ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
               : (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                   & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                   ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                   : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                       & (IData)(__VdfgRegularize_h6e95ff9d_0_21))
                       ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                       : ((IData)(__VdfgRegularize_h6e95ff9d_0_21)
                           ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                           : (((IData)(__VdfgRegularize_h6e95ff9d_0_7) 
                               & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                               ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                               : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r))))));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
        = (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
            & (IData)(__VdfgRegularize_h6e95ff9d_0_23))
            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
            : (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                & (IData)(__VdfgRegularize_h6e95ff9d_0_22))
                ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                : (((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r)) 
                    & (IData)(__VdfgRegularize_h6e95ff9d_0_25))
                    ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                    : ((IData)(__VdfgRegularize_h6e95ff9d_0_25)
                        ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_rd_data_o
                        : (((IData)(__VdfgRegularize_h6e95ff9d_0_9) 
                            & (IData)(__VdfgRegularize_h6e95ff9d_0_19))
                            ? vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                            : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_31 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_11) 
                                                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r) 
                                                    & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                                           >> 0x00000014U)))));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_28 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_10) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_27));
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_32 = ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12) 
                                                 & (IData)(__VdfgRegularize_h6e95ff9d_0_27));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 0U;
    if ((((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
          >> 2U) & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r) 
         & (0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r)))) {
        if (((((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs1_ex) 
               & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                  == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                     >> 0x0000000fU)))) 
              | ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_id_use_rs2_ex) 
                 & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                    == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                       >> 0x00000014U))))) 
             | ((0x23U == (0x0000007fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o)) 
                & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                   == (0x0000001fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_pipe_inst_o 
                                      >> 0x00000014U)))))) {
            tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o = 1U;
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           ^ vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           | vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           << (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           >> (0x0000001fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o));
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed 
        = VL_LTS_III(32, tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o, vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned 
        = (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
           < vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
    vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40 = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o) 
                                                 & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_req_o));
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o = 1U;
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                          >> 4U)))) {
                                if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                    if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_pop_en_o = 1U;
                                    }
                                }
                            }
                            if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__is_call_jal) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                        = ((IData)(4U) 
                                           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r);
                                }
                            } else if ((0x00000020U 
                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                                if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_push_jalr) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_en_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_ras_push_addr_o 
                                        = ((IData)(4U) 
                                           + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r);
                                }
                            }
                        }
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o = 1U;
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r;
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o 
                        = (0x0000003fU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_ghr__DOT__data_r));
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            if (((((((((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU))) 
                       | (2U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                       >> 0x0000000cU)))) 
                      | (3U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                      >> 0x0000000cU)))) 
                     | (7U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                     >> 0x0000000cU)))) 
                    | (6U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                    >> 0x0000000cU)))) 
                   | (4U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                   >> 0x0000000cU)))) 
                  | (1U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                  >> 0x0000000cU)))) 
                 | (5U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                 >> 0x0000000cU))))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            }
        } else if ((2U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
            } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                 >> 3U)))) {
                if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else if ((0x00000040U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r;
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r;
                } else {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o 
                        = ((0x00000080U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r)
                            : 0U);
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o 
                        = ((1U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 7U)) && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__update_idx 
        = (0x0000003fU & ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_ghr_o) 
                          ^ (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                             >> 2U)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o = 0U;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((4U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                    }
                }
                if ((0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                           >> 8U)))) {
                    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r 
                        = (1U & ((0x00000200U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                  ? (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i))
                                  : ((0x00000100U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                      ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i)
                                      : ((0x00000400U 
                                          & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                          ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed)
                                          : ((0x00000800U 
                                              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                              ? (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                                              : ((0x00001000U 
                                                  & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                                  ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                                                  : 
                                                 ((1U 
                                                   & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                      >> 0x0000000dU)) 
                                                  && (1U 
                                                      & (~ (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned))))))))));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o 
                        = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r;
                    if (((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r) 
                         != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r))) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                            = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r)
                                ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr
                                : ((IData)(4U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r));
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 3U)))) {
                        if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                    = tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr;
                            }
                        } else if ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o 
                                = (0xfffffffeU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset);
                            if (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__ras_should_pop_jalr) {
                                if ((1U & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r)) 
                                           | (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_target__DOT__data_r 
                                              != (0xfffffffeU 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset))))) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                                }
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                   | ((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i)));
        } else if ((2U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                = ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                    ? ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i)
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i 
                                    & (0xffffffffU 
                                       >> (0x0000001fU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o))) 
                                   | ((- (IData)((tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                                  >> 0x1fU))) 
                                      & (~ (0xffffffffU 
                                            >> (0x0000001fU 
                                                & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)))))
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i)
                            : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i))
                    : ((0x00002000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                        ? ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned)
                            : (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed))
                        : ((0x00001000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i
                            : ((0x00004000U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? (tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o 
                                   - vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o)
                                : tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i))));
        } else if ((1U & (~ (0U != (0x0000003fU & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                                   >> 8U)))))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                              >> 3U)))) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                        = ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                            ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                            : ((0x00000020U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                ? ((IData)(4U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)
                                : ((0x00000040U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                    ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i
                                    : ((0x00000080U 
                                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))
                                        ? tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op1_o
                                        : 0U))));
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__front_hold_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
           | ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40) 
              | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT____Vcellinp__branch_predictor_inst__flush_flag_i)));
}

void Vtb_seg_led_stop___024root___nba_sequent__TOP__1(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_sequent__TOP__1\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)
            ? 0U : (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans 
        = ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))
            ? 0x55U : 0xaaU);
}

void Vtb_seg_led_stop___024root___nba_sequent__TOP__2(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_sequent__TOP__2\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0;
    // Body
    __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = 0ULL;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = 0ULL;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = 0U;
    } else {
        __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
            = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2)
                ? ((0xc34fU == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))
                    ? 0U : (0x0000ffffU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))))
                : 0U);
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
            = (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2) 
                & (0xc34fU == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms)))
                ? ((IData)(1U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin)
                : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin);
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
        = __Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 
        = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
           && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
}

void Vtb_seg_led_stop___024root___nba_comb__TOP__0(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_comb__TOP__0\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o;
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o = 0;
    // Body
    tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now)) 
              & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                 | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_if_valid))));
    if (((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
         | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o = 0x00000013U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg;
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__instruction;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush 
        = (1U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) 
                 | ((~ ((~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40)) 
                        & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__issue_valid_o))) 
                    | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
        = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1;
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n = 0U;
    } else if (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o;
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_issue_valid_i 
        = ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
           & (IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i 
        = ((IData)(tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_valid_o) 
           & ((~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)) 
              & (~ (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_40))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o = 0U;
    if ((0x00000040U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 5U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 4U))) 
                                  && ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 2U)) 
                                          && ((1U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 1U)) 
                                              && (1U 
                                                  & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))))));
        if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = (0x00000010U 
                                       | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000020U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x0000000dU)))) {
                            if ((0x00004000U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00002000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00002000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00001000U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)))
                                        : ((0x00001000U 
                                            & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                            ? (0x00000800U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                            : (0x00000400U 
                                               | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))));
                            } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x0000000dU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                    = ((0x00001000U 
                                        & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                        ? (0x00000200U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o))
                                        : (0x00000100U 
                                           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)));
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 4U)) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                            >> 3U))) 
                                  && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)))));
        if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                                = (0x00000080U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        }
                    }
                } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (2U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                               | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 0x00000010U)));
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (8U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    } else if ((0x00000010U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                       ? ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))
                                       : ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && (1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (0x00000040U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            } else if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = (1U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                        = ((0x3fffU & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o)) 
                           | (0x00004000U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                             >> 0x00000010U)));
                }
            }
        }
    } else {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen 
            = ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                         >> 3U))) && ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 2U))) 
                                      && ((1U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 1U)) 
                                          && ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o) 
                                              && (1U 
                                                  & ((0x00004000U 
                                                      & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)
                                                      ? 
                                                     (~ 
                                                      (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                       >> 0x0000000dU))
                                                      : 
                                                     ((1U 
                                                       & (~ 
                                                          (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                           >> 0x0000000dU))) 
                                                      || (1U 
                                                          & (~ 
                                                             (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                              >> 0x0000000cU))))))))));
        if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                      >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o 
                            = (4U | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o));
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o) 
           & ((~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                  | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg) 
                     | ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o) 
                        | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ifid_flush_now))))) 
              & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_consume_i)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__pc_jump_en_o 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
           | (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_accepted_o));
}

extern const VlUnpacked<CData/*6:0*/, 16> Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0;

void Vtb_seg_led_stop___024root___nba_comb__TOP__1(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_comb__TOP__1\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = 0;
    CData/*6:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = 0;
    CData/*3:0*/ tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = 0;
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*3:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 8U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x10U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x18U));
    } else {
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 4U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x0cU));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x14U));
        tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
            = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                              >> 0x1cU));
    }
    __Vtableidx1 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx1];
    __Vtableidx2 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx2];
    __Vtableidx3 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx3];
    __Vtableidx4 = tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
        = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
        [__Vtableidx4];
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffffffff00ULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | (IData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1)));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffc03ffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2)) 
              << 0x0000000aU));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fff00fffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3)) 
              << 0x00000014U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000c03fffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)(tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
              << 0x0000001eU));
}

void Vtb_seg_led_stop___024root___nba_sequent__TOP__3(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_sequent__TOP__3\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x0000003fffffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 6U)))) << 0x00000026U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000ffcfffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 4U)))) << 0x0000001cU));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffff3ffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                     >> 2U)))) << 0x00000012U));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
        = ((0x000000fffffffcffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
           | ((QData)((IData)((3U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans)))) 
              << 8U));
}

void Vtb_seg_led_stop___024root___nba_sequent__TOP__4(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___nba_sequent__TOP__4\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED = 0U;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
    } else if ((0U != (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))) {
        if ((0x80200040U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r;
        }
        if ((0x80200040U != vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
            if ((0x80200020U != vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                if ((0x80200050U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)) {
                    if ((0x80000000U == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 1U;
                    } else if ((0xffffffffU == vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r)) {
                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg = 0U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r 
        = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o) 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r 
        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
           & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))))));
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)))) {
        if ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r)))) {
            if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                          >> 1U)))) {
                if ((1U & (~ (0U != (0x0000003fU & 
                                     ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U)))))) {
                    if ((1U & (~ ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                  >> 2U)))) {
                        if ((8U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))) {
                            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset;
                            if ((0U == (7U & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                              >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 8U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                               << 0x00000018U);
                                    } else {
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 4U;
                                        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                            = (0x00ff0000U 
                                               & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                                  << 0x00000010U));
                                    }
                                } else if ((1U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 2U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ff00U 
                                           & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                              << 8U));
                                } else {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 1U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x000000ffU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
                                }
                            } else if ((1U == (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                if ((2U & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset)) {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0cU;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o 
                                           << 0x00000010U);
                                } else {
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 3U;
                                    vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                        = (0x0000ffffU 
                                           & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o);
                                }
                            } else if ((2U == (7U & 
                                               (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                >> 0x0000000cU)))) {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0x0fU;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                                    = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__fwd_op2_o;
                            } else {
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o = 0U;
                                vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Vtb_seg_led_stop___024root___eval_nba(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_nba\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
    __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0;
    CData/*6:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 = 0;
    CData/*6:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 = 0;
    CData/*6:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 = 0;
    CData/*6:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
    __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1___Vtableidx1;
    __Vinline__nba_comb__TOP__1___Vtableidx1 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1___Vtableidx2;
    __Vinline__nba_comb__TOP__1___Vtableidx2 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1___Vtableidx3;
    __Vinline__nba_comb__TOP__1___Vtableidx3 = 0;
    CData/*3:0*/ __Vinline__nba_comb__TOP__1___Vtableidx4;
    __Vinline__nba_comb__TOP__1___Vtableidx4 = 0;
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_led_stop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count 
            = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst)
                ? 0U : (0x0000001fU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans 
            = ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))
                ? 0x55U : 0xaaU);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
            = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
        if (vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst) {
            __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 = 0ULL;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 = 0U;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 = 0ULL;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 = 0U;
        } else {
            __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
                = ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2)
                    ? ((0xc34fU == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))
                        ? 0U : (0x0000ffffU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms))))
                    : 0U);
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
                = (((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2) 
                    & (0xc34fU == (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms)))
                    ? ((IData)(1U) + vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin)
                    : vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin);
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output;
            vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1 
                = vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__LED;
        }
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms 
            = __Vinline__nba_sequent__TOP__2___Vdly__tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms;
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2 
            = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
               && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1 
            = ((1U & (~ (IData)(vlSelfRef.tb_seg_led_stop__DOT__w_clk_rst))) 
               && (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_led_stop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        if ((0x00000010U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count))) {
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
                = (0x0000000fU & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata);
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 8U));
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 0x10U));
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 0x18U));
        } else {
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 4U));
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 0x0cU));
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 0x14U));
            __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4 
                = (0x0000000fU & (vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_wdata 
                                  >> 0x1cU));
        }
        __Vinline__nba_comb__TOP__1___Vtableidx1 = __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1;
        __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1 
            = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
            [__Vinline__nba_comb__TOP__1___Vtableidx1];
        __Vinline__nba_comb__TOP__1___Vtableidx2 = __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2;
        __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2 
            = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
            [__Vinline__nba_comb__TOP__1___Vtableidx2];
        __Vinline__nba_comb__TOP__1___Vtableidx3 = __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3;
        __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3 
            = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
            [__Vinline__nba_comb__TOP__1___Vtableidx3];
        __Vinline__nba_comb__TOP__1___Vtableidx4 = __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4;
        __Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4 
            = Vtb_seg_led_stop__ConstPool__TABLE_h150c8023_0
            [__Vinline__nba_comb__TOP__1___Vtableidx4];
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000ffffffff00ULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | (IData)((IData)(__Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1)));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000fffffc03ffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)(__Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2)) 
                  << 0x0000000aU));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000fff00fffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)(__Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3)) 
                  << 0x00000014U));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000c03fffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)(__Vinline__nba_comb__TOP__1_tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4)) 
                  << 0x0000001eU));
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x0000003fffffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                         >> 6U)))) 
                  << 0x00000026U));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000ffcfffffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                         >> 4U)))) 
                  << 0x0000001cU));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000fffff3ffffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)((3U & ((IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans) 
                                         >> 2U)))) 
                  << 0x00000012U));
        vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output 
            = ((0x000000fffffffcffULL & vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT__seg_output) 
               | ((QData)((IData)((3U & (IData)(vlSelfRef.tb_seg_led_stop__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans)))) 
                  << 8U));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_seg_led_stop___024root___nba_sequent__TOP__4(vlSelf);
    }
}

void Vtb_seg_led_stop___024root___timing_resume(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___timing_resume\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((8ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_seg_led_stop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_seg_led_stop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_seg_led_stop___024root___eval_phase__act(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_phase__act\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_seg_led_stop___024root___eval_triggers_vec__act(vlSelf);
    Vtb_seg_led_stop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_seg_led_stop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_seg_led_stop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_seg_led_stop___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_seg_led_stop___024root___timing_resume(vlSelf);
        Vtb_seg_led_stop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_seg_led_stop___024root___eval_phase__inact(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_phase__inact\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("new/tb_seg_led_stop.sv", 3, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_seg_led_stop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_seg_led_stop___024root___eval_phase__nba(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_phase__nba\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_seg_led_stop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_seg_led_stop___024root___eval_nba(vlSelf);
        Vtb_seg_led_stop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_seg_led_stop___024root___eval(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_seg_led_stop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("new/tb_seg_led_stop.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("new/tb_seg_led_stop.sv", 3, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_seg_led_stop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("new/tb_seg_led_stop.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_seg_led_stop___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_seg_led_stop___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_seg_led_stop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_seg_led_stop___024root___eval_debug_assertions(Vtb_seg_led_stop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_led_stop___024root___eval_debug_assertions\n"); );
    Vtb_seg_led_stop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
