CROSS_COMPILE ?= riscv64-unknown-elf-

CC      := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump
SIZE    := $(CROSS_COMPILE)size

RTT_ROOT    := ../third_party/rt-thread-v3.1.5
RTT_INCLUDE := $(RTT_ROOT)/include
RTT_SRC     := $(RTT_ROOT)/src
RTT_PORT    := $(RTT_ROOT)/port-reference

BUILD_DIR ?= build
SIM_DIR   := $(BUILD_DIR)/sim
ELF       := $(BUILD_DIR)/rtthread_nano.elf
IROM_WORDS ?= 8192

# 190 MHz CPU clock / 100 Hz RT-Thread tick.
TIMER_PERIOD_CYCLES ?= 1900000

ARCH_FLAGS := -march=rv32im_zicsr -mabi=ilp32 -mcmodel=medany
COMMON_FLAGS := $(ARCH_FLAGS) -Os -g3 -ffreestanding -fno-builtin \
	-fno-common -fno-pic -fno-pie -ffunction-sections -fdata-sections \
	-fno-asynchronous-unwind-tables -fno-unwind-tables -msmall-data-limit=0 \
	-I. -Ibsp -I$(RTT_INCLUDE) -I$(RTT_PORT) -D__RTTHREAD__ \
	-DBSP_TIMER_PERIOD_CYCLES=$(TIMER_PERIOD_CYCLES) \
	-Wall -Wextra -Wno-unused-parameter
LDFLAGS := $(ARCH_FLAGS) -nostdlib -nostartfiles -static -no-pie \
	-Wl,--gc-sections -Wl,--build-id=none -Wl,-Map=$(BUILD_DIR)/rtthread_nano.map \
	-T linker.ld

RTT_C_NAMES := clock components idle ipc irq kservice object scheduler thread timer
RTT_OBJECTS := $(addprefix $(BUILD_DIR)/rt_,$(addsuffix .o,$(RTT_C_NAMES)))
OBJECTS := $(BUILD_DIR)/startup.o $(BUILD_DIR)/trap.o \
	$(BUILD_DIR)/board.o $(BUILD_DIR)/drv_timer.o $(BUILD_DIR)/drv_uart.o \
	$(BUILD_DIR)/app_main.o $(BUILD_DIR)/cpuport.o \
	$(BUILD_DIR)/context_gcc.o $(RTT_OBJECTS)

.PHONY: all clean

all: $(SIM_DIR)/irom.mem $(SIM_DIR)/dram.mem \
	$(BUILD_DIR)/irom.coe $(BUILD_DIR)/dram.coe \
	$(BUILD_DIR)/rtthread_nano.dis
	$(SIZE) $(ELF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) $(SIM_DIR)

$(BUILD_DIR)/startup.o: bsp/startup.S linker.ld | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/trap.o: bsp/trap.S linker.ld | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/board.o: bsp/board.c bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_timer.o: bsp/drv_timer.c bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/drv_uart.o: bsp/drv_uart.c bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/app_main.o: applications/main.c bsp/board.h rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c11 -c $< -o $@

$(BUILD_DIR)/cpuport.o: $(RTT_PORT)/cpuport.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(BUILD_DIR)/context_gcc.o: $(RTT_PORT)/context_gcc.S rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -c $< -o $@

$(BUILD_DIR)/rt_%.o: $(RTT_SRC)/%.c rtconfig.h | $(BUILD_DIR)
	$(CC) $(COMMON_FLAGS) -std=c99 -c $< -o $@

$(ELF): $(OBJECTS) linker.ld
	$(CC) $(COMMON_FLAGS) $(LDFLAGS) $(OBJECTS) -lgcc -o $@

$(BUILD_DIR)/irom.bin: $(ELF)
	$(OBJCOPY) -O binary --only-section=.text $< $@

$(BUILD_DIR)/dram.bin: $(ELF)
	$(OBJCOPY) -O binary --only-section=.rodata --only-section=.data $< $@

$(SIM_DIR)/irom.mem: $(BUILD_DIR)/irom.bin ../tools/bin_to_mem.py
	python3 ../tools/bin_to_mem.py $< $@ --words $(IROM_WORDS)

$(SIM_DIR)/dram.mem: $(BUILD_DIR)/dram.bin ../tools/bin_to_mem.py
	python3 ../tools/bin_to_mem.py $< $@ --words 65536

$(BUILD_DIR)/irom.coe: $(SIM_DIR)/irom.mem ../tools/mem_to_coe.py
	python3 ../tools/mem_to_coe.py $< $@

$(BUILD_DIR)/dram.coe: $(SIM_DIR)/dram.mem ../tools/mem_to_coe.py
	python3 ../tools/mem_to_coe.py $< $@

$(BUILD_DIR)/rtthread_nano.dis: $(ELF)
	$(OBJDUMP) -d -S $< > $@

clean:
	rm -rf $(BUILD_DIR)
