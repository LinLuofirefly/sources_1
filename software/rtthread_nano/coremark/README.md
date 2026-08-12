# RT-Thread Nano + CoreMark FPGA firmware

This target links the RT-Thread Nano kernel, the maintained step8 BSP and the
upstream CoreMark 1.0 workload into one FPGA firmware image. It contains no RTL
testbench or simulator target.

## Build

From WSL or Linux:

```sh
make -B BUILD_DIR=build/fpga TIMER_PERIOD_CYCLES=2100000 \
  COREMARK_ITERATIONS=10000 \
  RTTHREAD_OPT_FLAGS=-O2 COREMARK_OPT_FLAGS=-O3
```

`RTTHREAD_OPT_FLAGS` applies to the RT-Thread kernel, BSP, port and shell.
`COREMARK_OPT_FLAGS` applies only to the timed CoreMark workload and its four
kernels. The non-measured `core_portme.c` platform/formatter layer follows
`RTTHREAD_OPT_FLAGS` by default and can be overridden with
`PORTME_OPT_FLAGS`.
For compatibility, setting the former `OPT_FLAGS` variable still applies one
optimization level to both groups.

The generated Vivado initialization files are:

```text
build/fpga/irom.coe
build/fpga/dram.coe
```

The same build also creates `rtthread_coremark.elf`, its map/disassembly, and
32-bit hexadecimal memory files under `build/fpga/mem/`.

## Board behavior

- the CPU clock and timer period above correspond to 210 MHz and a 100 Hz
  RT-Thread scheduling tick;
- the LED register is nonzero while CoreMark is running and is cleared at end;
- UART output uses 115200 baud, 8 data bits, no parity and one stop bit;
- the UART command shell accepts `help` and `coremark` repeatedly;
- CoreMark timing comes from the independent 1 kHz hardware counter at
  `0x80200050`, not from RT-Thread timer-interrupt counts;
- the default 10,000 iterations are long enough for CoreMark's ten-second rule.

For a reportable score, also follow the upstream run/reporting rules and make
sure the final FPGA implementation passes timing. RT-Thread timer interrupts
still run during the benchmark, but elapsed time is sampled exclusively from
the hardware millisecond counter.

To build a bitstream, select this directory's `build/fpga` as `FirmwareDir` in
`fpga/vivado/build_bitstream.ps1`.
