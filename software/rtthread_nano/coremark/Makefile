CROSS_COMPILE ?= riscv64-unknown-elf-

CC      := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump
SIZE    := $(CROSS_COMPILE)size

BSP_ROOT      := ../step8
TOOLS_ROOT    := ../tools
RTT_ROOT      := ../third_party/rt-thread-v4.1.1
RTT_INCLUDE   := $(RTT_ROOT)/include
RTT_SRC       := $(RTT_ROOT)/src
RTT_PORT      := $(RTT_ROOT)/port-reference
COREMARK_ROOT := ../third_party/coremark

BUILD_DIR ?= build
MEM_DIR   := $(BUILD_DIR)/mem
ELF       := $(BUILD_DIR)/rtthread_coremark.elf
IROM_WORDS ?= 8192

# 210 MHz CPU clock / 100 Hz RT-Thread scheduling tick.  CoreMark elapsed time
# itself comes from the independent 1 kHz hardware counter in perip_bridge.
TIMER_PERIOD_CYCLES ?= 2100000
COREMARK_ITERATIONS ?= 10000
COREMARK_ALLOW_SHORT_RUN ?= 0
OPT_FLAGS            ?= -O1

ARCH_FLAGS := -march=rv32im_zicsr -mabi=ilp32 -mcmodel=medany
COMMON_FLAGS := $(ARCH_FLAGS) $(OPT_FLAGS) -g3 -ffreestanding -fno-builtin \
	-fno-common -fno-pic -fno-pie -fno-strict-aliasing \
	-ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables \
	-fno-unwind-tables -msmall-data-limit=0 \
	-I. -Iapplications -I$(BSP_ROOT)/bsp -I$(RTT_INCLUDE) -I$(RTT_PORT) \
	-I$(COREMARK_ROOT) -D__RTTHREAD__ \
	-DCOREMARK_OPT_LEVEL=$(OPT_FLAGS) \
	-DBSP_TIMER_PERIOD_CYCLES=$(TIMER_PERIOD_CYCLES) \
	-DITERATIONS=$(COREMARK_ITERATIONS) -DPERFORMANCE_RUN=1 \
	-DCOREMARK_ALLOW_SHORT_RUN=$(COREMARK_ALLOW_SHORT_RUN) \
	-Wall -Wextra -Wno-unused-parameter
LDFLAGS := $(ARCH_FLAGS) -nostdlib -nostartfiles -static -no-pie \
	-Wl,--gc-sections -Wl,--build-id=none \
	-Wl,-Map=$(BUILD_DIR)/rtthread_coremark.map -T $(BSP_ROOT)/linker.ld

RTT_C_NAMES := clock components idle ipc irq kservice object scheduler thread timer
RTT_OBJECTS := $(addprefix $(BUILD_DIR)/rt_,$(addsuffix .o,$(RTT_C_NAMES)))
COREMARK_C_NAMES := core_list_join core_matrix core_state core_util
COREMARK_OBJECTS := $(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(COREMARK_C_NAMES)))
OBJECTS := $(BUILD_DIR)/startup.o $(BUILD_DIR)/trap.o \
	$(BUILD_DIR)/board.o $(BUILD_DIR)/drv_timer.o $(BUILD_DIR)/drv_uart.o \
	$(BUILD_DIR)/app_main.o $(BUILD_DIR)/core_portme.o \
	$(BUILD_DIR)/core_main.o $(COREMARK_OBJECTS) \
	$(BUILD_DIR)/cpuport.o $(BUILD_DIR)/context_gcc.o $(RTT_OBJECTS)

.PHONY: all clean

all: $(MEM_DIR)/irom.mem $(MEM_DIR)/dram.mem \
	$(BUILD_DIR)/irom.coe $(BUILD_DIR)/dram.coe \
	$(BUILD_DIR)/rtthread_coremark.dis
	$(SIZE) $(ELF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(MEM_DIR)

$(BUILD_DIR)/startup.o: $(BSP_ROOT)/bsp/startup.S $(BSP_ROOT)/linker.ld | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/trap.o: $(BSP_ROOT)/bsp/trap.S $(BSP_ROOT)/linker.ld | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/board.o: $(BSP_ROOT)/bsp/board.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_timer.o: $(BSP_ROOT)/bsp/drv_timer.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_uart.o: $(BSP_ROOT)/bsp/drv_uart.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/app_main.o: applications/main.c $(BSP_ROOT)/bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/core_portme.o: core_portme.c core_portme.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/core_main.o: $(COREMARK_ROOT)/core_main.c core_portme.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -Dmain=coremark_entry -c $< -o $@

$(BUILD_DIR)/core_%.o: $(COREMARK_ROOT)/core_%.c core_portme.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/cpuport.o: $(RTT_PORT)/cpuport.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/context_gcc.o: $(RTT_PORT)/context_gcc.S rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/rt_%.o: $(RTT_SRC)/%.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(ELF): $(OBJECTS) $(BSP_ROOT)/linker.ld
	$(CC) $(COMMON_FLAGS) $(LDFLAGS) $(OBJECTS) -lgcc -o $@

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
