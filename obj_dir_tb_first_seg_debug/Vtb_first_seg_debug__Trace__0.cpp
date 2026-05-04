// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_first_seg_debug__Syms.h"


void Vtb_first_seg_debug___024root__trace_chg_0_sub_0(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_first_seg_debug___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root__trace_chg_0\n"); );
    // Body
    Vtb_first_seg_debug___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_first_seg_debug___024root*>(voidSelf);
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_first_seg_debug___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_first_seg_debug___024root__trace_chg_dtype____0(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtb_first_seg_debug___024root__trace_chg_0_sub_0(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root__trace_chg_0_sub_0\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_first_seg_debug__DOT__cycle_count),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_first_seg_debug__DOT__hist_wr_ptr),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_first_seg_debug__DOT__hist_count),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb_first_seg_debug__DOT__j),32);
        bufp->chgIData(oldp+4,(vlSelfRef.tb_first_seg_debug__DOT__slot),32);
        bufp->chgBit(oldp+5,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                              & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o))));
        bufp->chgBit(oldp+6,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                              & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
        bufp->chgIData(oldp+7,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)
                                 ? 0x00000013U : ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                                   ? 0x00000013U
                                                   : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))),32);
        bufp->chgBit(oldp+8,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                              & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o))));
        bufp->chgIData(oldp+9,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                                & (- (IData)((1U & 
                                              (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+10,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+11,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+12,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o))));
        bufp->chgIData(oldp+13,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+14,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+15,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+16,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+17,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+18,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+19,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+20,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+21,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+22,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+23,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+24,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+25,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+26,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+27,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+28,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+29,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+30,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+31,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgCData(oldp+32,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+33,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+34,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity[7U])))) {
        bufp->chgBit(oldp+35,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i));
        bufp->chgBit(oldp+36,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o));
        bufp->chgBit(oldp+37,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o));
        bufp->chgIData(oldp+38,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o),32);
        bufp->chgIData(oldp+39,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o),32);
        bufp->chgBit(oldp+40,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o));
        bufp->chgCData(oldp+41,((0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)),7);
        bufp->chgCData(oldp+42,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+43,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x00000014U))),5);
        bufp->chgBit(oldp+44,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i));
        bufp->chgBit(oldp+45,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i));
        bufp->chgBit(oldp+46,((0x23U == (0x0000007fU 
                                         & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        bufp->chgIData(oldp+47,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o),32);
        bufp->chgIData(oldp+48,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o),32);
        bufp->chgCData(oldp+49,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 7U))),5);
        bufp->chgBit(oldp+50,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen));
        bufp->chgIData(oldp+51,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o),32);
        bufp->chgIData(oldp+52,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o),32);
        bufp->chgBit(oldp+53,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en));
        bufp->chgSData(oldp+54,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o),15);
        bufp->chgIData(oldp+55,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o),32);
        bufp->chgIData(oldp+56,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o),32);
        bufp->chgBit(oldp+57,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i));
        bufp->chgIData(oldp+58,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n),32);
        bufp->chgBit(oldp+59,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush));
        bufp->chgIData(oldp+60,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+61,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgSData(oldp+62,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),15);
        bufp->chgIData(oldp+63,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)
                                  ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)),32);
        bufp->chgIData(oldp+64,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+65,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+66,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgBit(oldp+67,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o));
        bufp->chgBit(oldp+68,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o))));
        bufp->chgCData(oldp+69,((0x0000001fU & ((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 7U) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)))))))),5);
        bufp->chgBit(oldp+70,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen));
        bufp->chgBit(oldp+71,(((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
                               & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen))));
        bufp->chgCData(oldp+72,((7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+73,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                 >> 0x00000019U)),7);
        bufp->chgSData(oldp+74,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                 >> 0x00000014U)),12);
        bufp->chgBit(oldp+75,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now));
        bufp->chgBit(oldp+76,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold));
        bufp->chgBit(oldp+77,((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+78,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__pc),32);
        bufp->chgSData(oldp+79,((0x00000fffU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__pc 
                                                >> 2U))),12);
        bufp->chgIData(oldp+80,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction),32);
        bufp->chgIData(oldp+81,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__perip_rdata),32);
        bufp->chgIData(oldp+82,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+83,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgIData(oldp+84,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1),32);
        bufp->chgBit(oldp+85,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
        bufp->chgBit(oldp+86,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
        bufp->chgBit(oldp+87,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
        bufp->chgBit(oldp+88,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o));
        bufp->chgIData(oldp+89,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o),32);
        bufp->chgBit(oldp+90,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o));
        bufp->chgBit(oldp+91,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r));
        bufp->chgIData(oldp+92,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                  ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1
                                  : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o)),32);
        bufp->chgIData(oldp+93,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r),32);
        bufp->chgBit(oldp+94,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
        bufp->chgBit(oldp+95,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r));
        bufp->chgBit(oldp+96,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg));
        bufp->chgCData(oldp+97,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+98,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+99,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+100,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+101,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r),32);
        bufp->chgIData(oldp+102,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r),32);
        bufp->chgIData(oldp+103,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r),32);
        bufp->chgBit(oldp+104,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r));
        bufp->chgCData(oldp+105,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgBit(oldp+106,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
        bufp->chgIData(oldp+107,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r),32);
        bufp->chgIData(oldp+108,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r),32);
        bufp->chgSData(oldp+109,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r),15);
        bufp->chgCData(oldp+110,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o),5);
        bufp->chgIData(oldp+111,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o),32);
        bufp->chgBit(oldp+112,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
        bufp->chgBit(oldp+113,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
        bufp->chgIData(oldp+114,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                   ? 0x00000013U : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgIData(oldp+115,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o),32);
        bufp->chgIData(oldp+116,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o),32);
        bufp->chgBit(oldp+117,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o));
        bufp->chgIData(oldp+118,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o),32);
        bufp->chgBit(oldp+119,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o));
        bufp->chgIData(oldp+120,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i),32);
        bufp->chgIData(oldp+121,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i),32);
        bufp->chgIData(oldp+122,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
                                   ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
                                   : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                                       ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                                       : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                                           ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                                           : (((~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14))
                                               ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                                               : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
                                                   ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                                                   : 
                                                  (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                                    : vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r))))))),32);
        bufp->chgCData(oldp+123,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+124,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+125,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+126,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgCData(oldp+127,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+128,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+129,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+130,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+131,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+132,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgCData(oldp+133,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+134,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+135,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+136,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+137,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+138,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgCData(oldp+139,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+140,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+141,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+142,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+143,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+144,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgIData(oldp+145,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i),32);
        bufp->chgIData(oldp+146,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgBit(oldp+147,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i));
        bufp->chgBit(oldp+148,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                                | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i))));
        bufp->chgCData(oldp+149,((0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction)),7);
        bufp->chgCData(oldp+150,((0x0000007fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                                                 >> 2U))),7);
        bufp->chgCData(oldp+151,((0x0000007fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                                 >> 2U))),7);
        bufp->chgIData(oldp+152,((((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                               >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | ((0x00000800U & 
                                      (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                       << 4U)) | ((0x000007e0U 
                                                   & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                        >> 7U)))))),32);
        bufp->chgIData(oldp+153,((((- (IData)((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                               >> 0x0000001fU))) 
                                   << 0x00000014U) 
                                  | ((((0x000001feU 
                                        & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                           >> 0x0000000bU)) 
                                       | (1U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                      << 0x0000000bU) 
                                     | (0x000007feU 
                                        & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__instruction 
                                           >> 0x00000014U))))),32);
        bufp->chgIData(oldp+154,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i),32);
        bufp->chgCData(oldp+155,((7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000cU))),3);
        bufp->chgCData(oldp+156,((0x0000001fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)),5);
        bufp->chgBit(oldp+157,((1U & (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))));
        bufp->chgBit(oldp+158,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 1U))));
        bufp->chgBit(oldp+159,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 2U))));
        bufp->chgBit(oldp+160,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 3U))));
        bufp->chgBit(oldp+161,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 4U))));
        bufp->chgBit(oldp+162,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 5U))));
        bufp->chgBit(oldp+163,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 6U))));
        bufp->chgBit(oldp+164,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 7U))));
        bufp->chgBit(oldp+165,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U))));
        bufp->chgBit(oldp+166,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 9U))));
        bufp->chgBit(oldp+167,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+168,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+169,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+170,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+171,((1U & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+172,((0U != (0x0000003fU 
                                       & ((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                          >> 8U)))));
        bufp->chgBit(oldp+173,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i));
        bufp->chgBit(oldp+174,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed));
        bufp->chgBit(oldp+175,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned));
        bufp->chgIData(oldp+176,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i),32);
        bufp->chgIData(oldp+177,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i),32);
        bufp->chgIData(oldp+178,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i),32);
        bufp->chgIData(oldp+179,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i),32);
        bufp->chgIData(oldp+180,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i),32);
        bufp->chgIData(oldp+181,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i),32);
        bufp->chgIData(oldp+182,((0xffffffffU >> (0x0000001fU 
                                                  & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))),32);
        bufp->chgIData(oldp+183,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset),32);
        bufp->chgIData(oldp+184,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr),32);
        bufp->chgIData(oldp+185,(((IData)(4U) + vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)),32);
        bufp->chgBit(oldp+186,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r));
        bufp->chgBit(oldp+187,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
        bufp->chgBit(oldp+188,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+189,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
        bufp->chgBit(oldp+190,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+191,((0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)),7);
        bufp->chgCData(oldp+192,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))),5);
        bufp->chgCData(oldp+193,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))),5);
        bufp->chgBit(oldp+194,(((0x33U == (0x0000007fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                   | ((0x13U == (0x0000007fU 
                                                 & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                      | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr))))));
        bufp->chgBit(oldp+195,(((0x33U == (0x0000007fU 
                                           & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                   | (0x23U == (0x0000007fU 
                                                & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))))));
        bufp->chgBit(oldp+196,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
        bufp->chgBit(oldp+197,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r));
        bufp->chgBit(oldp+198,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
        bufp->chgBit(oldp+199,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
        bufp->chgIData(oldp+200,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg),32);
        bufp->chgIData(oldp+201,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg),32);
        bufp->chgBit(oldp+202,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg));
        bufp->chgBit(oldp+203,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+204,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgBit(oldp+205,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+206,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+207,((7U & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000cU))),3);
        bufp->chgBit(oldp+208,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+209,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+210,((0x0000007fU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)),7);
        bufp->chgCData(oldp+211,((0x0000001fU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))),5);
        bufp->chgBit(oldp+212,((0x23U == (0x0000007fU 
                                          & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r))));
        bufp->chgBit(oldp+213,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2));
        bufp->chgBit(oldp+214,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a));
        bufp->chgBit(oldp+215,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b));
        bufp->chgBit(oldp+216,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2));
        bufp->chgBit(oldp+217,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb));
        bufp->chgIData(oldp+218,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r),32);
        bufp->chgBit(oldp+219,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r));
        bufp->chgBit(oldp+220,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r));
        Vtb_first_seg_debug___024root__trace_chg_dtype____0(vlSelf, bufp, 221, vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs);
        bufp->chgIData(oldp+253,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r),32);
        bufp->chgIData(oldp+254,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr),32);
        bufp->chgQData(oldp+255,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1),64);
        bufp->chgQData(oldp+257,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2),64);
        bufp->chgCData(oldp+259,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1),8);
        bufp->chgCData(oldp+260,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2),8);
        bufp->chgIData(oldp+261,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_wdata),32);
        bufp->chgIData(oldp+262,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d),32);
        bufp->chgIData(oldp+263,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata),32);
        bufp->chgIData(oldp+264,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_rdata),32);
        bufp->chgIData(oldp+265,((((0x80200000U == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                    : ((0x80200004U 
                                        == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                        ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                        : ((0x80200010U 
                                            == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                            ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                            : ((0x80200020U 
                                                == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                : (
                                                   (0x80200050U 
                                                    == vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                    ? vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                                                    : 
                                                   (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                    & (- (IData)(
                                                                 ((0x80100000U 
                                                                   <= vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr) 
                                                                  & (0x8013ffffU 
                                                                     > vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)))))))))) 
                                  & (- (IData)((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))))),32);
        bufp->chgBit(oldp+266,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r));
        bufp->chgBit(oldp+267,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr));
        bufp->chgIData(oldp+268,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1),32);
        bufp->chgIData(oldp+269,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2),32);
        bufp->chgIData(oldp+270,((0x0003ffffU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r)),18);
        bufp->chgIData(oldp+271,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data),32);
        bufp->chgIData(oldp+272,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1),32);
        bufp->chgSData(oldp+273,((0x0000ffffU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                                 >> 2U))),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+274,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2),32);
        bufp->chgQData(oldp+275,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2),40);
        bufp->chgIData(oldp+277,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1),32);
        bufp->chgQData(oldp+278,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1),40);
        bufp->chgSData(oldp+280,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms),16);
        bufp->chgIData(oldp+281,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin),32);
        bufp->chgIData(oldp+282,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
                                  ^ VL_SHIFTR_III(32,32,32, vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin, 1U))),32);
        bufp->chgBit(oldp+283,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
        bufp->chgBit(oldp+284,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[6U]))) {
        bufp->chgCData(oldp+285,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1),7);
        bufp->chgCData(oldp+286,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2),7);
        bufp->chgCData(oldp+287,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3),7);
        bufp->chgCData(oldp+288,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4),7);
        bufp->chgCData(oldp+289,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1),4);
        bufp->chgCData(oldp+290,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2),4);
        bufp->chgCData(oldp+291,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3),4);
        bufp->chgCData(oldp+292,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgIData(oldp+293,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r),32);
        bufp->chgIData(oldp+294,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r),32);
        bufp->chgCData(oldp+295,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r),4);
        bufp->chgCData(oldp+296,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o),4);
        bufp->chgIData(oldp+297,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o),32);
        bufp->chgIData(oldp+298,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o),32);
        bufp->chgIData(oldp+299,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__LED),32);
        bufp->chgBit(oldp+300,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
        bufp->chgBit(oldp+301,((0U != (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))));
        bufp->chgIData(oldp+302,((0x0003ffffU & vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)),18);
        bufp->chgSData(oldp+303,((0x0000ffffU & (vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                                 >> 2U))),16);
    }
    bufp->chgBit(oldp+304,(vlSelfRef.tb_first_seg_debug__DOT__w_cpu_clk));
    bufp->chgBit(oldp+305,(vlSelfRef.tb_first_seg_debug__DOT__w_clk_50Mhz));
    bufp->chgBit(oldp+306,(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst));
    bufp->chgCData(oldp+307,(vlSelfRef.tb_first_seg_debug__DOT__virtual_key),8);
    bufp->chgQData(oldp+308,(vlSelfRef.tb_first_seg_debug__DOT__virtual_sw),64);
    bufp->chgBit(oldp+310,((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst)))));
    bufp->chgBit(oldp+311,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                            | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i))));
    bufp->chgIData(oldp+312,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
    bufp->chgIData(oldp+313,((vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),32);
    bufp->chgCData(oldp+314,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o) 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_first_seg_debug__DOT__w_clk_rst))))))),4);
    bufp->chgBit(oldp+315,(((IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
                            | (IData)(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
    bufp->chgQData(oldp+316,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_output),40);
    bufp->chgIData(oldp+318,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i),32);
    bufp->chgCData(oldp+319,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans),8);
    bufp->chgCData(oldp+320,(vlSelfRef.tb_first_seg_debug__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count),5);
}

void Vtb_first_seg_debug___024root__trace_chg_dtype____0(Vtb_first_seg_debug___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root__trace_chg_dtype____0\n"); );
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[0]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+16,(__VdtypeVar[16]),32);
    bufp->chgIData(oldp+17,(__VdtypeVar[17]),32);
    bufp->chgIData(oldp+18,(__VdtypeVar[18]),32);
    bufp->chgIData(oldp+19,(__VdtypeVar[19]),32);
    bufp->chgIData(oldp+20,(__VdtypeVar[20]),32);
    bufp->chgIData(oldp+21,(__VdtypeVar[21]),32);
    bufp->chgIData(oldp+22,(__VdtypeVar[22]),32);
    bufp->chgIData(oldp+23,(__VdtypeVar[23]),32);
    bufp->chgIData(oldp+24,(__VdtypeVar[24]),32);
    bufp->chgIData(oldp+25,(__VdtypeVar[25]),32);
    bufp->chgIData(oldp+26,(__VdtypeVar[26]),32);
    bufp->chgIData(oldp+27,(__VdtypeVar[27]),32);
    bufp->chgIData(oldp+28,(__VdtypeVar[28]),32);
    bufp->chgIData(oldp+29,(__VdtypeVar[29]),32);
    bufp->chgIData(oldp+30,(__VdtypeVar[30]),32);
    bufp->chgIData(oldp+31,(__VdtypeVar[31]),32);
}

void Vtb_first_seg_debug___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_first_seg_debug___024root__trace_cleanup\n"); );
    // Body
    Vtb_first_seg_debug___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_first_seg_debug___024root*>(voidSelf);
    Vtb_first_seg_debug__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
}
