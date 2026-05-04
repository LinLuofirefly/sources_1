#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

verilator -sv --binary --timing -Wno-fatal \
  -Iimports/new \
  -Inew \
  --top-module tb_issue_tight_loop \
  --Mdir obj_dir_tb_issue_tight_loop \
  imports/new/*.v \
  new/tb_issue_tight_loop.sv

stdbuf -oL -eL "$ROOT_DIR/obj_dir_tb_issue_tight_loop/Vtb_issue_tight_loop"
