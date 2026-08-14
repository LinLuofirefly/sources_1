# RT-Thread Nano BSP

This directory is the maintained FPGA BSP and application for RT-Thread
v3.1.5 Nano.
It includes machine-timer scheduling and a polling UART console for
`rt_kprintf`.

## Layout

- `bsp/startup.S`: reset entry, stack setup and BSS initialization
- `bsp/trap.S`: machine timer trap entry and interrupt context switching
- `bsp/board.c`: `rt_hw_board_init`, pass/fatal handling
- `bsp/drv_timer.c`: RT-Thread tick driver
- `bsp/drv_uart.c`: `rt_hw_console_output` and UART polling
- `applications/main.c`: application threads only
- `../tools/`: standalone ELF/memory-image conversion tools; the final BSP
  does not depend on any earlier step directory

The reset entry calls `entry()` from RT-Thread `components.c`, which owns the
standard `rtthread_startup()` sequence and creates the static main thread.
Heap, the device framework and FinSH remain disabled.

## UART hardware

The CPU console uses two MMIO registers:

- `0x80200070`: TX data, low byte
- `0x80200074`: TX status, bit 0 is one when ready

`student_top` exposes the serialized output as `cpu_uart_tx`.  The board has a
single constrained TX pin (`D17`, top-level `o_uart_tx`), so `top` contains a
compile-time mux.  `P_CPU_CONSOLE_ON_UART=1` is the default and routes the
RT-Thread console to D17.  Set the parameter to zero to restore the original
digital-twin response channel instead.  CPU console format is 115200 baud,
8 data bits, no parity and one stop bit; the original twin channel is 9600 baud.

## Build the FPGA firmware

```sh
cd /mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1/software/rtthread_nano/step8
make -B BUILD_DIR=build/fpga TIMER_PERIOD_CYCLES=1900000
```

The default timer period is already `1900000`, corresponding to a 190 MHz CPU
clock and a 100 Hz RT-Thread tick. The command generates `rtthread_nano.elf`,
`rtthread_nano.dis`, `irom.coe`, and `dram.coe` under `build/fpga/`.

## Build the FPGA bitstream

The maintained Vivado build and programming flow is documented in
[`../../../fpga/vivado/README.md`](../../../fpga/vivado/README.md). It binds a
specific `build/fpga/irom.coe` and `dram.coe` pair to the BRAM IPs, rebuilds
the IP output products, runs synthesis/implementation, and rejects a build
whose setup or hold timing does not pass.
