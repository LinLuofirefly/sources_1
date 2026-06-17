#!/usr/bin/env bash
set -euo pipefail

ROOT=${ROOT:-/mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1}

cd "$ROOT"

rm -f seg_led_stop_src0_fmax.log \
      verilator_src0_fmax_stdout.log \
      verilator_src0_fmax_stderr.log \
      verilator_src0_fmax.pid

nohup bash new/run_verilator_tb_seg_led_stop_src0_fmax.sh \
    > verilator_src0_fmax_stdout.log \
    2> verilator_src0_fmax_stderr.log &

pid=$!
echo "$pid" > verilator_src0_fmax.pid
echo "STARTED pid=$pid"
