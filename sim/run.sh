#!/usr/bin/env bash
# ===========================================================================
# sim/run.sh — Verilator 仿真运行脚本 (WSL / Git Bash / Linux)
#
# 用法 (从工程根目录运行):
#   bash sim/run.sh                          # 默认 200M 周期
#   bash sim/run.sh --max-cycles 50000000    # 自定义周期数
#   bash sim/run.sh --wave                   # 带波形输出
#   bash sim/run.sh --clean                  # 清理构建文件
#
# 在 Windows WSL 中使用:
#   wsl -- bash -c "cd /mnt/c/Users/ACER/Desktop/Linluofirefly/sources_1 && bash sim/run.sh"
# ===========================================================================

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
cd "$PROJECT_ROOT"

MAX_CYCLES=100000000
WAVE=0
CLEAN=0

while [[ $# -gt 0 ]]; do
    case "$1" in
        --max-cycles) MAX_CYCLES="$2"; shift 2 ;;
        --wave)       WAVE=1; shift ;;
        --clean)      CLEAN=1; shift ;;
        *)            echo "Unknown option: $1"; exit 1 ;;
    esac
done

if [[ $CLEAN -eq 1 ]]; then
    echo "=== Cleaning ==="
    rm -rf sim/obj_dir
    rm -f sim/logs/sim.log
    echo "=== Clean done ==="
    exit 0
fi

# ---- 编译 ----
echo "=== Building Verilator simulation ==="

VFLAGS=(
    --top-module sim_wrapper
    --Mdir sim/obj_dir
    -o Vsim_wrapper
    -Iimports/new
    -CFLAGS "-std=c++17"
    -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-UNUSED
    -Wno-UNDRIVEN -Wno-PINMISSING -Wno-IMPLICIT
)

if [[ $WAVE -eq 1 ]]; then
    VFLAGS+=(--trace)
fi

SRCS=(
    sim/sim_wrapper.sv
    new/student_top.sv new/perip_bridge.sv new/display_seg.sv
    new/seg7.sv new/dram_driver.sv new/Mem_RAM.sv new/Mem_IROM.sv
    new/counter.sv
    imports/new/myCPU.sv imports/new/open_risc_v.v
    imports/new/branch_predictor.v imports/new/pc_reg.v
    imports/new/if_id.v imports/new/reg.v imports/new/id.v
    imports/new/id_ex.v imports/new/forwarding.v
    imports/new/Hazard_detection_unit.v imports/new/ex.v
    imports/new/ctrl.v imports/new/ex_mem1.v imports/new/mem1.v
    imports/new/mem1_mem2.v imports/new/mem2.v imports/new/mem2_wb.v
    imports/new/wb.v imports/new/dram_cache.v
    imports/new/rv32m_iter.v imports/new/dff_set.v
)

# 步骤 1: 生成 C++ 模型 (用 ../tb_cpu.cpp 让生成的 Makefile 能找到源文件)
verilator --cc --exe "${VFLAGS[@]}" "${SRCS[@]}" ../tb_cpu.cpp

# 步骤 2: 编译可执行文件
make -C sim/obj_dir -f Vsim_wrapper.mk -j"$(nproc)"

echo "=== Build done ==="

# ---- 运行 ----
mkdir -p sim/logs sim/waves

echo "=== Running simulation (max_cycles=$MAX_CYCLES) ==="
echo "=== Start time: $(date) ==="

./sim/obj_dir/Vsim_wrapper +max_cycles="$MAX_CYCLES" +log=sim/logs/sim.log

echo "=== End time: $(date) ==="
echo "=== Log file: sim/logs/sim.log ==="
