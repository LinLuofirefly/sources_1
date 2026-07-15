# ===========================================================================
# sim/Makefile — Verilator 仿真编译 & 运行
#
# 用法 (必须从工程根目录运行):
#   make -f sim/Makefile build                    编译 Verilator 仿真
#   make -f sim/Makefile run                      运行仿真 (默认 200M 周期)
#   make -f sim/Makefile run MAX_CYCLES=50000000  自定义最大周期
#   make -f sim/Makefile wave                     编译带波形输出的仿真并运行
#   make -f sim/Makefile clean                    清理生成文件
#
# 也可以使用脚本:
#   bash sim/run.sh                               (Git Bash / Linux)
#   powershell -File sim\run.ps1                  (Windows PowerShell)
#
# 注意: 所有路径相对于工程根目录，因为 $readmemh 路径需要正确解析。
# ===========================================================================

VERILATOR ?= verilator

# 仿真参数
MAX_CYCLES ?= 100000000
LOG_FILE   ?= sim/logs/sim.log

# 目录 (相对于工程根目录)
OBJ_DIR    := sim/obj_dir
TOP        := sim_wrapper
VTOP       := V$(TOP)

# 源文件列表 (相对于工程根目录)
VERILOG_SRCS := \
    sim/sim_wrapper.sv \
    new/student_top.sv \
    new/perip_bridge.sv \
    new/display_seg.sv \
    new/seg7.sv \
    new/dram_driver.sv \
    new/Mem_RAM.sv \
    new/Mem_IROM.sv \
    new/counter.sv \
    imports/new/myCPU.sv \
    imports/new/open_risc_v.v \
    imports/new/branch_predictor.v \
    imports/new/pc_reg.v \
    imports/new/if_id.v \
    imports/new/reg.v \
    imports/new/id.v \
    imports/new/id_ex.v \
    imports/new/early_forwarding_select.v \
    imports/new/forwarding.v \
    imports/new/Hazard_detection_unit.v \
    imports/new/ex.v \
    imports/new/ctrl.v \
    imports/new/ex_mem1.v \
    imports/new/mem1.v \
    imports/new/mem1_mem2.v \
    imports/new/mem2.v \
    imports/new/mem2_wb.v \
    imports/new/wb.v \
    imports/new/dram_cache.v \
    imports/new/rv32m_iter.v \
    imports/new/dff_set.v

# C++ testbench: 用 ../tb_cpu.cpp 让 Verilator 生成的 Makefile
# (在 sim/obj_dir/ 内运行) 能正确找到 sim/tb_cpu.cpp
TB_CPP_RELATIVE := ../tb_cpu.cpp

# Verilator 编译选项
VFLAGS := \
    --top-module $(TOP) \
    --Mdir $(OBJ_DIR) \
    -o $(VTOP) \
    -Iimports/new \
    -CFLAGS "-std=c++17" \
    -Wno-WIDTH \
    -Wno-CASEINCOMPLETE \
    -Wno-UNUSED \
    -Wno-UNDRIVEN \
    -Wno-PINMISSING \
    -Wno-IMPLICIT

# ===========================================================================
# 目标
# ===========================================================================

.PHONY: all build run wave clean

all: build

# ---- 编译 ----
# 步骤 1: verilator --cc 生成 C++ 模型
# 步骤 2: make -C obj_dir 编译可执行文件
build:
	@echo "=== Verilator: generating C++ model ($(TOP)) ==="
	$(VERILATOR) --cc --exe $(VFLAGS) $(VERILOG_SRCS) $(TB_CPP_RELATIVE)
	@echo "=== Compiling binary ==="
	$(MAKE) -C $(OBJ_DIR) -f $(VTOP).mk
	@echo "=== Build done: $(OBJ_DIR)/$(VTOP) ==="

# ---- 运行仿真 ----
# 从工程根目录运行, 保证 $readmemh("sim/irom.mem") 路径正确
run: build
	@echo "=== Running simulation (max_cycles=$(MAX_CYCLES)) ==="
	@echo "=== Start time: $$(date) ==="
	@mkdir -p sim/logs sim/waves
	./$(OBJ_DIR)/$(VTOP) +max_cycles=$(MAX_CYCLES) +log=$(LOG_FILE)
	@echo "=== End time: $$(date) ==="
	@echo "=== Log: $(LOG_FILE) ==="

# ---- 带波形运行 ----
wave: VFLAGS += --trace
wave: build
	@echo "=== Running simulation with waveform (max_cycles=$(MAX_CYCLES)) ==="
	@mkdir -p sim/logs sim/waves
	./$(OBJ_DIR)/$(VTOP) +max_cycles=$(MAX_CYCLES) +log=$(LOG_FILE)
	@echo "=== Log: $(LOG_FILE) ==="

# ---- 清理 ----
clean:
	rm -rf $(OBJ_DIR)
	rm -f sim/logs/sim.log
	@echo "=== Clean done ==="
