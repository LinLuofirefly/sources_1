#!/usr/bin/env bash
set -euo pipefail

cd "$(dirname "$0")/.."
rm -rf obj_dir_tb_issue_load_loop

verilator --binary --timing --trace --top-module tb_issue_load_loop \
  -Wno-fatal \
  -Iimports/new \
  new/tb_issue_load_loop.sv \
  imports/new/defines.v \
  imports/new/open_risc_v.v \
  imports/new/pc_reg.v \
  imports/new/if_id.v \
  imports/new/id.v \
  imports/new/reg.v \
  imports/new/id_ex.v \
  imports/new/ex.v \
  imports/new/ex_mem1.v \
  imports/new/mem1.v \
  imports/new/mem1_mem2.v \
  imports/new/mem2.v \
  imports/new/mem2_wb.v \
  imports/new/wb.v \
  imports/new/forwarding.v \
  imports/new/Hazard_detection_unit.v \
  imports/new/ctrl.v \
  imports/new/branch_predictor.v \
  imports/new/issue_stage.v \
  --Mdir obj_dir_tb_issue_load_loop

./obj_dir_tb_issue_load_loop/Vtb_issue_load_loop
