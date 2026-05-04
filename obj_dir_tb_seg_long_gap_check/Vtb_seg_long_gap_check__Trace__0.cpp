// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtb_seg_long_gap_check__Syms.h"


void Vtb_seg_long_gap_check___024root__trace_chg_0_sub_0(Vtb_seg_long_gap_check___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_seg_long_gap_check___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root__trace_chg_0\n"); );
    // Body
    Vtb_seg_long_gap_check___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_seg_long_gap_check___024root*>(voidSelf);
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtb_seg_long_gap_check___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_seg_long_gap_check___024root__trace_chg_dtype____0(Vtb_seg_long_gap_check___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar);

void Vtb_seg_long_gap_check___024root__trace_chg_0_sub_0(Vtb_seg_long_gap_check___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root__trace_chg_0_sub_0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((((vlSelfRef.__Vm_traceActivity[1U] 
                       | vlSelfRef.__Vm_traceActivity[2U]) 
                      | vlSelfRef.__Vm_traceActivity[4U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_seg_long_gap_check__DOT__seg_write_count),32);
        bufp->chgQData(oldp+1,(vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_time),64);
        bufp->chgQData(oldp+3,(vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_time),64);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_seg_long_gap_check__DOT__first_seg_data),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_seg_long_gap_check__DOT__second_seg_data),32);
        bufp->chgBit(oldp+7,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                              & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o))));
        bufp->chgBit(oldp+8,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                              & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
        bufp->chgIData(oldp+9,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
                                 ? 0x00000013U : ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                                   ? 0x00000013U
                                                   : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))),32);
        bufp->chgBit(oldp+10,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o))));
        bufp->chgIData(oldp+11,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+12,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+13,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+14,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o))));
        bufp->chgIData(oldp+15,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+16,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+17,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+18,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+19,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+20,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+21,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+22,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+23,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+24,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+25,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+26,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+27,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgBit(oldp+28,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r))));
        bufp->chgIData(oldp+29,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgCData(oldp+30,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+31,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+32,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r))));
        bufp->chgIData(oldp+33,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)
                                  ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgCData(oldp+34,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),5);
        bufp->chgIData(oldp+35,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
        bufp->chgBit(oldp+36,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r))));
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[3U] 
                      | vlSelfRef.__Vm_traceActivity[6U])))) {
        bufp->chgBit(oldp+37,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i));
        bufp->chgBit(oldp+38,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_hold_flag_o));
        bufp->chgBit(oldp+39,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o));
        bufp->chgIData(oldp+40,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o),32);
        bufp->chgIData(oldp+41,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o),32);
        bufp->chgBit(oldp+42,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o));
        bufp->chgCData(oldp+43,((0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)),7);
        bufp->chgCData(oldp+44,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+45,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 0x00000014U))),5);
        bufp->chgBit(oldp+46,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs1_ex_i));
        bufp->chgBit(oldp+47,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_inst__DOT__id_use_rs2_ex_i));
        bufp->chgBit(oldp+48,((0x23U == (0x0000007fU 
                                         & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o))));
        bufp->chgIData(oldp+49,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o),32);
        bufp->chgIData(oldp+50,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o),32);
        bufp->chgCData(oldp+51,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                >> 7U))),5);
        bufp->chgBit(oldp+52,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen));
        bufp->chgIData(oldp+53,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o),32);
        bufp->chgIData(oldp+54,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o),32);
        bufp->chgBit(oldp+55,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__data_read_en));
        bufp->chgSData(oldp+56,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o),15);
        bufp->chgIData(oldp+57,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg1_rdata_o),32);
        bufp->chgIData(oldp+58,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_reg2_rdata_o),32);
        bufp->chgBit(oldp+59,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i));
        bufp->chgIData(oldp+60,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1_n),32);
        bufp->chgBit(oldp+61,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush));
        bufp->chgIData(oldp+62,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_addr_offset_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+63,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_base_addr_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgSData(oldp+64,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ctrl_flags_o) 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),15);
        bufp->chgIData(oldp+65,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)
                                  ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o)),32);
        bufp->chgIData(oldp+66,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_addr_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+67,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op1_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgIData(oldp+68,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_op2_o 
                                 & (- (IData)((1U & 
                                               (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush))))))),32);
        bufp->chgBit(oldp+69,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o));
        bufp->chgBit(oldp+70,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_pred_taken_o))));
        bufp->chgCData(oldp+71,((0x0000001fU & ((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                                 >> 7U) 
                                                & (- (IData)(
                                                             (1U 
                                                              & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)))))))),5);
        bufp->chgBit(oldp+72,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen));
        bufp->chgBit(oldp+73,(((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__internal_flush)) 
                               & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_reg_wen))));
        bufp->chgCData(oldp+74,((7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+75,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                 >> 0x00000019U)),7);
        bufp->chgSData(oldp+76,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst_o 
                                 >> 0x00000014U)),12);
        bufp->chgBit(oldp+77,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_now));
        bufp->chgBit(oldp+78,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__start_hold));
        bufp->chgBit(oldp+79,((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__hold_flag_i)))));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[4U]))) {
        bufp->chgIData(oldp+80,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc),32);
        bufp->chgSData(oldp+81,((0x00000fffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__pc 
                                                >> 2U))),12);
        bufp->chgIData(oldp+82,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction),32);
        bufp->chgIData(oldp+83,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__perip_rdata),32);
        bufp->chgIData(oldp+84,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+85,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgIData(oldp+86,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1),32);
        bufp->chgBit(oldp+87,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1));
        bufp->chgBit(oldp+88,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_en_o));
        bufp->chgBit(oldp+89,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d2));
        bufp->chgBit(oldp+90,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_taken_o));
        bufp->chgIData(oldp+91,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o),32);
        bufp->chgBit(oldp+92,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_o));
        bufp->chgBit(oldp+93,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_flush_d1_r));
        bufp->chgIData(oldp+94,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                  ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_addr_d1
                                  : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_pred_target_o)),32);
        bufp->chgIData(oldp+95,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r),32);
        bufp->chgBit(oldp+96,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_r));
        bufp->chgBit(oldp+97,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_valid_pending_r));
        bufp->chgBit(oldp+98,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__is_holding_reg));
        bufp->chgCData(oldp+99,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+100,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+101,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+102,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+103,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r),32);
        bufp->chgIData(oldp+104,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op1__DOT__data_r),32);
        bufp->chgIData(oldp+105,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_op2__DOT__data_r),32);
        bufp->chgBit(oldp+106,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r));
        bufp->chgCData(oldp+107,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgBit(oldp+108,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
        bufp->chgIData(oldp+109,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r),32);
        bufp->chgIData(oldp+110,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_addr_offset__DOT__data_r),32);
        bufp->chgSData(oldp+111,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r),15);
        bufp->chgCData(oldp+112,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_addr_o),5);
        bufp->chgIData(oldp+113,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_data_o),32);
        bufp->chgBit(oldp+114,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
        bufp->chgBit(oldp+115,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
        bufp->chgIData(oldp+116,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1)
                                   ? 0x00000013U : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)),32);
        bufp->chgIData(oldp+117,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_jump_addr_o),32);
        bufp->chgIData(oldp+118,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_mem_addr_o),32);
        bufp->chgBit(oldp+119,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_en_o));
        bufp->chgIData(oldp+120,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o),32);
        bufp->chgBit(oldp+121,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_actual_taken_o));
        bufp->chgIData(oldp+122,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i),32);
        bufp->chgIData(oldp+123,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i),32);
        bufp->chgIData(oldp+124,((((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                   & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_17))
                                   ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r
                                   : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_16))
                                       ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r
                                       : (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                           & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_15))
                                           ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r
                                           : (((~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r)) 
                                               & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14))
                                               ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r
                                               : ((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_14)
                                                   ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i
                                                   : 
                                                  (((IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_3) 
                                                    & (IData)(vlSelfRef.__VdfgRegularize_h6e95ff9d_0_12))
                                                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_r
                                                    : vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_base_addr__DOT__data_r))))))),32);
        bufp->chgCData(oldp+125,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+126,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+127,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+128,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgCData(oldp+129,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+130,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+131,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+132,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+133,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+134,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgCData(oldp+135,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+136,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+137,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+138,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+139,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+140,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgCData(oldp+141,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_addr__DOT__data_r),5);
        bufp->chgIData(oldp+142,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_data__DOT__data_r),32);
        bufp->chgBit(oldp+143,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgIData(oldp+144,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgIData(oldp+145,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_mem_rd_addr__DOT__data_r),32);
        bufp->chgBit(oldp+146,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgIData(oldp+147,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_data__DOT__data_i),32);
        bufp->chgIData(oldp+148,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_inst__DOT__data_r),32);
        bufp->chgBit(oldp+149,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__if_valid_i));
        bufp->chgBit(oldp+150,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                                | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i))));
        bufp->chgCData(oldp+151,((0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction)),7);
        bufp->chgCData(oldp+152,((0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_fetch_pc_r 
                                                 >> 2U))),7);
        bufp->chgCData(oldp+153,((0x0000007fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__bp_update_pc_o 
                                                 >> 2U))),7);
        bufp->chgIData(oldp+154,((((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                               >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | ((0x00000800U & 
                                      (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                       << 4U)) | ((0x000007e0U 
                                                   & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001eU 
                                                     & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                        >> 7U)))))),32);
        bufp->chgIData(oldp+155,((((- (IData)((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                               >> 0x0000001fU))) 
                                   << 0x00000014U) 
                                  | ((((0x000001feU 
                                        & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                           >> 0x0000000bU)) 
                                       | (1U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                                >> 0x00000014U))) 
                                      << 0x0000000bU) 
                                     | (0x000007feU 
                                        & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__instruction 
                                           >> 0x00000014U))))),32);
        bufp->chgIData(oldp+156,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__branch_predictor_inst__DOT__i),32);
        bufp->chgCData(oldp+157,((7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000cU))),3);
        bufp->chgCData(oldp+158,((0x0000001fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i)),5);
        bufp->chgBit(oldp+159,((1U & (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r))));
        bufp->chgBit(oldp+160,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 1U))));
        bufp->chgBit(oldp+161,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 2U))));
        bufp->chgBit(oldp+162,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 3U))));
        bufp->chgBit(oldp+163,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 4U))));
        bufp->chgBit(oldp+164,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 5U))));
        bufp->chgBit(oldp+165,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 6U))));
        bufp->chgBit(oldp+166,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 7U))));
        bufp->chgBit(oldp+167,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 8U))));
        bufp->chgBit(oldp+168,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 9U))));
        bufp->chgBit(oldp+169,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000aU))));
        bufp->chgBit(oldp+170,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000bU))));
        bufp->chgBit(oldp+171,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000cU))));
        bufp->chgBit(oldp+172,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000dU))));
        bufp->chgBit(oldp+173,((1U & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                      >> 0x0000000eU))));
        bufp->chgBit(oldp+174,((0U != (0x0000003fU 
                                       & ((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_ctrl_flags__DOT__data_r) 
                                          >> 8U)))));
        bufp->chgBit(oldp+175,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_equal_op2_i));
        bufp->chgBit(oldp+176,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_signed));
        bufp->chgBit(oldp+177,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_less_op2_i_unsigned));
        bufp->chgIData(oldp+178,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_add_op2_i),32);
        bufp->chgIData(oldp+179,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_and_op2_i),32);
        bufp->chgIData(oldp+180,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_xor_op2_i),32);
        bufp->chgIData(oldp+181,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_or_op2_i),32);
        bufp->chgIData(oldp+182,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_left_op2_i),32);
        bufp->chgIData(oldp+183,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op1_i_shift_right_op2_i),32);
        bufp->chgIData(oldp+184,((0xffffffffU >> (0x0000001fU 
                                                  & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__op2_i))),32);
        bufp->chgIData(oldp+185,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__base_addr_add_addr_offset),32);
        bufp->chgIData(oldp+186,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__pc_relative_jump_addr),32);
        bufp->chgIData(oldp+187,(((IData)(4U) + vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst_addr__DOT__data_r)),32);
        bufp->chgBit(oldp+188,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_inst__DOT__branch_taken_r));
        bufp->chgBit(oldp+189,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_is_load_o));
        bufp->chgBit(oldp+190,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+191,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_rd_wen_o));
        bufp->chgBit(oldp+192,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+193,((0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)),7);
        bufp->chgCData(oldp+194,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x0000000fU))),5);
        bufp->chgCData(oldp+195,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))),5);
        bufp->chgBit(oldp+196,(((0x33U == (0x0000007fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                   | ((0x13U == (0x0000007fU 
                                                 & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                      | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr))))));
        bufp->chgBit(oldp+197,(((0x33U == (0x0000007fU 
                                           & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                | ((0x63U == (0x0000007fU 
                                              & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r)) 
                                   | (0x23U == (0x0000007fU 
                                                & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_inst__DOT__data_r))))));
        bufp->chgBit(oldp+198,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__forwarding_inst__DOT__use_base_addr));
        bufp->chgBit(oldp+199,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_pred_taken__DOT__data_r));
        bufp->chgBit(oldp+200,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__id_ex_inst__DOT__dff_reg_wen__DOT__data_r));
        bufp->chgBit(oldp+201,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__flush_flag_i));
        bufp->chgIData(oldp+202,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_reg),32);
        bufp->chgIData(oldp+203,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_inst_addr_reg),32);
        bufp->chgBit(oldp+204,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__hold_pred_taken_reg));
        bufp->chgBit(oldp+205,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+206,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem1_mem2_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgBit(oldp+207,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+208,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_align_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+209,((7U & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_inst__DOT__data_r 
                                        >> 0x0000000cU))),3);
        bufp->chgBit(oldp+210,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_is_load__DOT__data_r));
        bufp->chgBit(oldp+211,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem2_pre_inst__DOT__dff_rd_wen__DOT__data_r));
        bufp->chgCData(oldp+212,((0x0000007fU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r)),7);
        bufp->chgCData(oldp+213,((0x0000001fU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r 
                                                 >> 0x00000014U))),5);
        bufp->chgBit(oldp+214,((0x23U == (0x0000007fU 
                                          & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_inst__DOT__data_r))));
        bufp->chgBit(oldp+215,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem1_mem2));
        bufp->chgBit(oldp+216,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2a));
        bufp->chgBit(oldp+217,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2b));
        bufp->chgBit(oldp+218,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem2));
        bufp->chgBit(oldp+219,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_fwd_from_mem_wb));
        bufp->chgIData(oldp+220,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_raw_r),32);
        bufp->chgBit(oldp+221,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_inst__DOT__store_data_forwarded_r));
        bufp->chgBit(oldp+222,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__mem_wb_inst__DOT__dff_rd_wen__DOT__data_r));
        Vtb_seg_long_gap_check___024root__trace_chg_dtype____0(vlSelf, bufp, 223, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__regs_inst__DOT__regs);
        bufp->chgIData(oldp+255,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_r),32);
        bufp->chgIData(oldp+256,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr),32);
        bufp->chgQData(oldp+257,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d1),64);
        bufp->chgQData(oldp+259,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__sw_sync_d2),64);
        bufp->chgCData(oldp+261,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d1),8);
        bufp->chgCData(oldp+262,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__key_sync_d2),8);
        bufp->chgIData(oldp+263,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_wdata),32);
        bufp->chgIData(oldp+264,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d),32);
        bufp->chgIData(oldp+265,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata),32);
        bufp->chgIData(oldp+266,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_rdata),32);
        bufp->chgIData(oldp+267,((((0x80200000U == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                    : ((0x80200004U 
                                        == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                        ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                        : ((0x80200010U 
                                            == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                            ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                            : ((0x80200020U 
                                                == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__mmio_rdata
                                                : (
                                                   (0x80200050U 
                                                    == vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)
                                                    ? vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_bin_cpu_d
                                                    : 
                                                   (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_rdata 
                                                    & (- (IData)(
                                                                 ((0x80100000U 
                                                                   <= vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr) 
                                                                  & (0x8013ffffU 
                                                                     > vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_addr_rr)))))))))) 
                                  & (- (IData)((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr))))),32);
        bufp->chgBit(oldp+268,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_r));
        bufp->chgBit(oldp+269,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__perip_rd_en_rr));
        bufp->chgIData(oldp+270,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d1),32);
        bufp->chgIData(oldp+271,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_gray_cpu_d2),32);
        bufp->chgIData(oldp+272,((0x0003ffffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r)),18);
        bufp->chgIData(oldp+273,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_data),32);
        bufp->chgIData(oldp+274,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__dram_rdata_q1),32);
        bufp->chgSData(oldp+275,((0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_rd_addr__DOT__data_r 
                                                 >> 2U))),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[5U]))) {
        bufp->chgIData(oldp+276,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d2),32);
        bufp->chgQData(oldp+277,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d2),40);
        bufp->chgIData(oldp+279,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__led_sync_d1),32);
        bufp->chgQData(oldp+280,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_sync_d1),40);
        bufp->chgSData(oldp+282,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_1ms),16);
        bufp->chgIData(oldp+283,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin),32);
        bufp->chgIData(oldp+284,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin 
                                  ^ VL_SHIFTR_III(32,32,32, vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_ms_bin, 1U))),32);
        bufp->chgBit(oldp+285,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d1));
        bufp->chgBit(oldp+286,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__counter_inst__DOT__cnt_enable_cnt_d2));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U]))) {
        bufp->chgCData(oldp+287,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg1),7);
        bufp->chgCData(oldp+288,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg2),7);
        bufp->chgCData(oldp+289,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg3),7);
        bufp->chgCData(oldp+290,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__seg4),7);
        bufp->chgCData(oldp+291,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit1),4);
        bufp->chgCData(oldp+292,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit2),4);
        bufp->chgCData(oldp+293,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit3),4);
        bufp->chgCData(oldp+294,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__digit4),4);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U]))) {
        bufp->chgIData(oldp+295,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r),32);
        bufp->chgIData(oldp+296,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_data__DOT__data_r),32);
        bufp->chgCData(oldp+297,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r),4);
        bufp->chgCData(oldp+298,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o),4);
        bufp->chgIData(oldp+299,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o),32);
        bufp->chgIData(oldp+300,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o),32);
        bufp->chgIData(oldp+301,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__LED),32);
        bufp->chgBit(oldp+302,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__cnt_enable_cfg));
        bufp->chgBit(oldp+303,((0U != (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_reg__DOT__data_r))));
        bufp->chgIData(oldp+304,((0x0003ffffU & vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r)),18);
        bufp->chgSData(oldp+305,((0x0000ffffU & (vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_mem_inst__DOT__dff_mem_wd_addr__DOT__data_r 
                                                 >> 2U))),16);
    }
    bufp->chgBit(oldp+306,(vlSelfRef.tb_seg_long_gap_check__DOT__w_cpu_clk));
    bufp->chgBit(oldp+307,(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_50Mhz));
    bufp->chgBit(oldp+308,(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst));
    bufp->chgCData(oldp+309,(vlSelfRef.tb_seg_long_gap_check__DOT__virtual_key),8);
    bufp->chgQData(oldp+310,(vlSelfRef.tb_seg_long_gap_check__DOT__virtual_sw),64);
    bufp->chgBit(oldp+312,((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst)))));
    bufp->chgBit(oldp+313,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1) 
                            | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__if_id_inst__DOT__pred_taken_i))));
    bufp->chgIData(oldp+314,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_addr_o 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
    bufp->chgIData(oldp+315,((vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_data_o 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),32);
    bufp->chgCData(oldp+316,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ex_wd_reg_o) 
                              & (- (IData)((1U & (~ (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__w_clk_rst))))))),4);
    bufp->chgBit(oldp+317,(((IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__hdu_flush_flag_o) 
                            | (IData)(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__Core_cpu__DOT__cpu_core__DOT__ctrl_inst__DOT__jump_en_d1))));
    bufp->chgQData(oldp+318,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_output),40);
    bufp->chgIData(oldp+320,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__dram_driver_inst__DOT__Mem_DRAM__DOT__i),32);
    bufp->chgCData(oldp+321,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT____Vcellout__seg_driver__ans),8);
    bufp->chgCData(oldp+322,(vlSelfRef.tb_seg_long_gap_check__DOT__dut__DOT__bridge_inst__DOT__seg_driver__DOT__count),5);
}

void Vtb_seg_long_gap_check___024root__trace_chg_dtype____0(Vtb_seg_long_gap_check___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 32>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root__trace_chg_dtype____0\n"); );
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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

void Vtb_seg_long_gap_check___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_seg_long_gap_check___024root__trace_cleanup\n"); );
    // Body
    Vtb_seg_long_gap_check___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_seg_long_gap_check___024root*>(voidSelf);
    Vtb_seg_long_gap_check__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
