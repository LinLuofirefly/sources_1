// ===========================================================================
// verilator.f — Verilator 编译文件列表 (参考用)
//
// 实际编译请使用 Makefile:
//   make -C sim build
//
// 如需手动编译:
//   verilator --top-module sim_wrapper --Mdir sim/obj_dir -o Vsim_wrapper \
//     --exe --build -CFLAGS "-std=c++17" \
//     -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-UNUSED -Wno-UNDRIVEN \
//     -Wno-PINMISSING -Wno-IMPLICIT \
//     sim/sim_wrapper.sv \
//     new/student_top.sv new/perip_bridge.sv new/display_seg.sv \
//     new/seg7.sv new/dram_driver.sv new/Mem_RAM.sv new/Mem_IROM.sv \
//     new/counter.sv \
//     imports/new/myCPU.sv imports/new/open_risc_v.v \
//     imports/new/branch_predictor.v imports/new/pc_reg.v \
//     imports/new/if_id.v imports/new/reg.v imports/new/id.v \
//     imports/new/id_ex.v imports/new/early_forwarding_select.v imports/new/forwarding.v \
//     imports/new/Hazard_detection_unit.v imports/new/ex.v \
//     imports/new/ctrl.v imports/new/ex_mem1.v imports/new/mem1.v \
//     imports/new/mem1_mem2.v imports/new/mem2.v imports/new/mem2_wb.v \
//     imports/new/wb.v imports/new/dram_cache.v \
//     imports/new/rv32m_iter.v imports/new/dff_set.v \
//     sim/tb_cpu.cpp
// ===========================================================================
