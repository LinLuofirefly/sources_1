#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

verilator -sv --binary --timing --trace -Wno-fatal \
  -Iimports/new \
  -Inew \
  --top-module tb_seg_long_gap_check \
  --Mdir obj_dir_tb_seg_long_gap_check \
  imports/new/*.v \
  imports/new/myCPU.sv \
  new/counter.sv \
  new/display_seg.sv \
  new/dram_driver.sv \
  new/Mem_IROM.sv \
  new/Mem_RAM.sv \
  new/perip_bridge.sv \
  new/seg7.sv \
  new/student_top.sv \
  new/tb_seg_long_gap_check.sv

"$ROOT_DIR/obj_dir_tb_seg_long_gap_check/Vtb_seg_long_gap_check"
