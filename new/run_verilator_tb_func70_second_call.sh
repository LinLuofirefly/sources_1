#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

verilator -sv --binary --timing -Wno-fatal \
  -Iimports/new \
  -Inew \
  --top-module tb_func70_second_call \
  --Mdir obj_dir_tb_func70_second_call \
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
  new/tb_func70_second_call.sv

stdbuf -oL -eL "$ROOT_DIR/obj_dir_tb_func70_second_call/Vtb_func70_second_call"
