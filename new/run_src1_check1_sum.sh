#!/usr/bin/env bash
set -euo pipefail

SRC=/mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1
RUN=/home/lingluo/digital_twin_runs/src1_check1_$(date +%Y%m%d_%H%M%S)

mkdir -p "$RUN/imports" "$RUN/sim"
cp -r "$SRC/new" "$RUN/"
mkdir -p "$RUN/imports/test_src"
cp -r "$SRC/imports/new" "$RUN/imports/"
cp -r "$SRC/imports/test_src/src1" "$RUN/imports/test_src/"

cp "$SRC/imports/test_src/src1/irom.mem" "$RUN/sim/irom.mem"
awk '
    BEGIN { start = 0 }
    /memory_initialization_vector/ { start = 1; next }
    start {
        gsub(/[,:;\r]/, "")
        if ($0 != "") print $0
    }
' "$SRC/imports/test_src/src1/dram.coe" > "$RUN/sim/dram.mem"

echo "RUN_DIR=$RUN"
cd "$RUN"
verilator -Wno-fatal --timing --binary \
    -o tb_src1_check1_sum \
    -Mdir obj_dir_tb_src1_check1_sum \
    -Iimports/new \
    -f new/tb_src1_check1_sum.f \
    2>&1 | tee build_check1_sum.log | tail -20

cd obj_dir_tb_src1_check1_sum
ln -s ../sim sim
stdbuf -oL -eL ./tb_src1_check1_sum 2>&1 | tee ../check1_sum.log
