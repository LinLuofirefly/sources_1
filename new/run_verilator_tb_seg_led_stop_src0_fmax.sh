#!/usr/bin/env bash
set -euo pipefail

ROOT=${ROOT:-/mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1}
SRC0_SIM=${SRC0_SIM:-/home/lingluo/digital_twin_sim/sim}
OBJ_DIR=${OBJ_DIR:-obj_dir_tb_seg_led_stop_src0_fmax}
BIN_NAME=${BIN_NAME:-tb_seg_led_stop_src0_fmax}
CPU_HALF_PERIOD_NS=${CPU_HALF_PERIOD_NS:-2.258}

cd "$ROOT"

rm -rf "$OBJ_DIR"
verilator -Wno-fatal --timing --binary \
    -DTB_CPU_HALF_PERIOD_NS="$CPU_HALF_PERIOD_NS" \
    -o "$BIN_NAME" \
    -Mdir "$OBJ_DIR" \
    -Iimports/new \
    -f new/tb_seg_led_stop.f

cd "$OBJ_DIR"
ln -sfn "$SRC0_SIM" sim
stdbuf -oL -eL "./$BIN_NAME" | tee "../seg_led_stop_src0_fmax.log"
