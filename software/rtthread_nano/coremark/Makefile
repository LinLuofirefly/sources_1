CROSS_COMPILE ?= riscv64-unknown-elf-

CC      := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump
SIZE    := $(CROSS_COMPILE)size

BSP_ROOT      := ../step8
TOOLS_ROOT    := ../tools
RTT_ROOT      := ../third_party/rt-thread-v3.1.5
RTT_INCLUDE   := $(RTT_ROOT)/include
RTT_SRC       := $(RTT_ROOT)/src
RTT_PORT      := $(RTT_ROOT)/port-reference
COREMARK_ROOT := ../third_party/coremark

BUILD_DIR ?= build
MEM_DIR   := $(BUILD_DIR)/mem
ELF       := $(BUILD_DIR)/rtthread_coremark.elf
IROM_WORDS ?= 16384
LINKER_SCRIPT ?= $(BSP_ROOT)/linker.ld

# 200 MHz CPU clock / 100 Hz RT-Thread scheduling tick.  CoreMark elapsed time
# itself comes from the independent 1 kHz hardware counter in perip_bridge.
TIMER_PERIOD_CYCLES ?= 2000000
COREMARK_ITERATIONS ?= 10000
COREMARK_ALLOW_SHORT_RUN ?= 0
# Keep the RT-Thread/BSP control path conservative while allowing the
# benchmark kernels to use a more aggressive optimization level.  OPT_FLAGS
# remains as a backwards-compatible override that applies to both groups.
OPT_FLAGS            ?=
RTTHREAD_OPT_FLAGS   ?= $(if $(OPT_FLAGS),$(OPT_FLAGS),-O1)
COREMARK_OPT_FLAGS   ?= $(if $(OPT_FLAGS),$(OPT_FLAGS),-O3)
COREMARK_FLAGS_LABEL ?= $(COREMARK_OPT_FLAGS)
# Platform/formatter glue is outside the timed CoreMark kernels and follows
# the RT-Thread optimization level by default.  It remains independently
# overridable for code-size or diagnostic builds.
PORTME_OPT_FLAGS     ?= $(RTTHREAD_OPT_FLAGS)
# Link-time options used by CoreMark-only LTO/PGO builds. Keep these out of
# RTTHREAD_FLAGS so RT-Thread/BSP objects remain independently optimized.
LINK_OPT_FLAGS       ?=
PGO_CAPTURE          ?= 0
PGO_PROFILE_DIR      ?=
COREMARK_CRC_HW      ?= 0
CRC_COMPILER_PASS    := compiler/coremark_crc_pass.py
COREMARK_CORE_UTIL_SHA256 := 166e9bf09afd290adffe2c6681d913c18373f77e457fae258499fbaad10b04fc

ifeq ($(PGO_CAPTURE),1)
PGO_CAPTURE_FLAGS := -DCOREMARK_PGO_CAPTURE=1
PGO_OBJECTS := $(BUILD_DIR)/pgo_dump.o
PGO_LIBS := -lgcov
endif

ARCH_FLAGS := -march=rv32im_zicsr -mabi=ilp32 -mcmodel=medany
BASE_FLAGS := $(ARCH_FLAGS) -g3 -ffreestanding -fno-builtin \
	-fno-common -fno-pic -fno-pie -fno-strict-aliasing \
	-ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables \
	-fno-unwind-tables -msmall-data-limit=0 \
	-I. -Iapplications -I$(BSP_ROOT)/bsp -I$(RTT_INCLUDE) -I$(RTT_PORT) \
	-I$(COREMARK_ROOT) -D__RTTHREAD__ \
	-DCOREMARK_FLAGS_LABEL='"$(COREMARK_FLAGS_LABEL)"' \
	-DBSP_TIMER_PERIOD_CYCLES=$(TIMER_PERIOD_CYCLES) \
	-DITERATIONS=$(COREMARK_ITERATIONS) -DPERFORMANCE_RUN=1 \
	-DCOREMARK_ALLOW_SHORT_RUN=$(COREMARK_ALLOW_SHORT_RUN) \
	-Wall -Wextra -Wno-unused-parameter
RTTHREAD_FLAGS := $(BASE_FLAGS) $(PGO_CAPTURE_FLAGS) $(RTTHREAD_OPT_FLAGS)
COREMARK_FLAGS := $(BASE_FLAGS) $(COREMARK_OPT_FLAGS)
PORTME_FLAGS   := $(BASE_FLAGS) $(PGO_CAPTURE_FLAGS) $(PORTME_OPT_FLAGS)
LDFLAGS := $(ARCH_FLAGS) -nostdlib -nostartfiles -static -no-pie \
	-Wl,--gc-sections -Wl,--build-id=none \
	-Wl,-Map=$(BUILD_DIR)/rtthread_coremark.map -T $(LINKER_SCRIPT)

RTT_C_NAMES := clock components idle ipc irq kservice object scheduler thread timer
RTT_OBJECTS := $(addprefix $(BUILD_DIR)/rt_,$(addsuffix .o,$(RTT_C_NAMES)))
COREMARK_C_NAMES := core_list_join core_matrix core_state core_util
COREMARK_OBJECTS := $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(COREMARK_C_NAMES)))
OBJECTS := $(BUILD_DIR)/startup.o $(BUILD_DIR)/trap.o \
	$(BUILD_DIR)/board.o $(BUILD_DIR)/drv_timer.o $(BUILD_DIR)/drv_uart.o \
	$(BUILD_DIR)/drv_hcsr04.o \
	$(BUILD_DIR)/app_main.o $(BUILD_DIR)/core_portme.o \
	$(BUILD_DIR)/core_main.o $(COREMARK_OBJECTS) \
	$(BUILD_DIR)/cpuport.o $(BUILD_DIR)/context_gcc.o $(RTT_OBJECTS) \
	$(PGO_OBJECTS)

.PHONY: all clean

all: $(MEM_DIR)/irom.mem $(MEM_DIR)/dram.mem \
	$(BUILD_DIR)/irom.coe $(BUILD_DIR)/dram.coe \
	$(BUILD_DIR)/rtthread_coremark.dis
	$(SIZE) $(ELF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(MEM_DIR)

$(BUILD_DIR)/startup.o: $(BSP_ROOT)/bsp/startup.S $(BSP_ROOT)/linker.ld | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -c $< -o $@

$(BUILD_DIR)/trap.o: $(BSP_ROOT)/bsp/trap.S $(BSP_ROOT)/linker.ld | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -c $< -o $@

$(BUILD_DIR)/board.o: $(BSP_ROOT)/bsp/board.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_timer.o: $(BSP_ROOT)/bsp/drv_timer.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_uart.o: $(BSP_ROOT)/bsp/drv_uart.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_hcsr04.o: $(BSP_ROOT)/bsp/drv_hcsr04.c $(BSP_ROOT)/bsp/drv_hcsr04.h $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/app_main.o: applications/main.c $(BSP_ROOT)/bsp/board.h $(BSP_ROOT)/bsp/drv_hcsr04.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/core_portme.o: core_portme.c core_portme.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(PORTME_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/pgo_dump.o: pgo_dump.c | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/core_main.o: $(COREMARK_ROOT)/core_main.c core_portme.h | $(BUILD_DIR)
	$(CC) $(COREMARK_FLAGS) -std=c99 -Dmain=coremark_entry -c $< -o $@

ifeq ($(COREMARK_CRC_HW),1)
# GCC still parses and optimizes the untouched upstream C source.  The small
# backend peephole pass recognizes GCC's expanded CoreMark CRC functions and
# substitutes CUSTOM-0 cmcrc16 instructions before normal assembly/linking.
$(BUILD_DIR)/core_util.o: $(COREMARK_ROOT)/core_util.c core_portme.h $(CRC_COMPILER_PASS) | $(BUILD_DIR)
	$(CC) $(COREMARK_FLAGS) -std=c99 -g0 -S $< -o $(BUILD_DIR)/core_util.gcc.s
	python3 $(CRC_COMPILER_PASS) \
		--input $(BUILD_DIR)/core_util.gcc.s \
		--output $(BUILD_DIR)/core_util.crc.s \
		--source $< --source-sha256 $(COREMARK_CORE_UTIL_SHA256) \
		--report $(BUILD_DIR)/coremark_crc_pass.txt
	$(CC) $(ARCH_FLAGS) -c $(BUILD_DIR)/core_util.crc.s -o $@
endif

$(BUILD_DIR)/core_%.o: $(COREMARK_ROOT)/core_%.c core_portme.h | $(BUILD_DIR)
	$(CC) $(COREMARK_FLAGS) -std=c99 -c $< -o $@

ifneq ($(strip $(PGO_PROFILE_DIR)),)
$(BUILD_DIR)/core_main.o: $(BUILD_DIR)/core_main.gcda
$(BUILD_DIR)/core_list_join.o: $(BUILD_DIR)/core_list_join.gcda
$(BUILD_DIR)/core_matrix.o: $(BUILD_DIR)/core_matrix.gcda
$(BUILD_DIR)/core_state.o: $(BUILD_DIR)/core_state.gcda
$(BUILD_DIR)/core_util.o: $(BUILD_DIR)/core_util.gcda

$(BUILD_DIR)/%.gcda: $(PGO_PROFILE_DIR)/%.gcda | $(BUILD_DIR)
	cp $< $@
endif

$(BUILD_DIR)/cpuport.o: $(RTT_PORT)/cpuport.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/context_gcc.o: $(RTT_PORT)/context_gcc.S rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -c $< -o $@

$(BUILD_DIR)/rt_%.o: $(RTT_SRC)/%.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(RTTHREAD_FLAGS) -std=c99 -c $< -o $@

$(ELF): $(OBJECTS) $(LINKER_SCRIPT)
	$(CC) $(RTTHREAD_FLAGS) $(LINK_OPT_FLAGS) $(LDFLAGS) $(OBJECTS) $(PGO_LIBS) -lgcc -o $@

$(BUILD_DIR)/irom.bin: $(ELF)
	$(OBJCOPY) -O binary --only-section=.text $< $@

$(BUILD_DIR)/dram.bin: $(ELF)
	$(OBJCOPY) -O binary --only-section=.rodata --only-section=.data $< $@

$(MEM_DIR)/irom.mem: $(BUILD_DIR)/irom.bin $(TOOLS_ROOT)/bin_to_mem.py
	python3 $(TOOLS_ROOT)/bin_to_mem.py $< $@ --words $(IROM_WORDS)

$(MEM_DIR)/dram.mem: $(BUILD_DIR)/dram.bin $(TOOLS_ROOT)/bin_to_mem.py
	python3 $(TOOLS_ROOT)/bin_to_mem.py $< $@ --words 65536

$(BUILD_DIR)/irom.coe: $(MEM_DIR)/irom.mem $(TOOLS_ROOT)/mem_to_coe.py
	python3 $(TOOLS_ROOT)/mem_to_coe.py $< $@

$(BUILD_DIR)/dram.coe: $(MEM_DIR)/dram.mem $(TOOLS_ROOT)/mem_to_coe.py
	python3 $(TOOLS_ROOT)/mem_to_coe.py $< $@

$(BUILD_DIR)/rtthread_coremark.dis: $(ELF)
	$(OBJDUMP) -d -S $< > $@

clean:
	rm -rf $(BUILD_DIR)
