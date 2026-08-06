# RT-Thread Nano + CoreMark FPGA firmware

This target links the RT-Thread Nano kernel, the maintained step8 BSP and the
upstream CoreMark 1.0 workload into one FPGA firmware image. It contains no RTL
testbench or simulator target.

## Build

From WSL or Linux:

```sh
make -B BUILD_DIR=build/fpga TIMER_PERIOD_CYCLES=1900000 \
  COREMARK_ITERATIONS=10000 OPT_FLAGS=-O1
```

The generated Vivado initialization files are:

```text
build/fpga/irom.coe
build/fpga/dram.coe
```

The same build also creates `rtthread_coremark.elf`, its map/disassembly, and
32-bit hexadecimal memory files under `build/fpga/mem/`.

## Board behavior

- the CPU clock and timer period above correspond to 190 MHz and a 100 Hz tick;
- the LED register is nonzero while CoreMark is running and is cleared at end;
- UART output uses 115200 baud, 8 data bits, no parity and one stop bit;
- timing comes from the real RT-Thread machine-timer tick; it is not clamped;
- the default 10,000 iterations are long enough for CoreMark's ten-second rule.

For a reportable score, also follow the upstream run/reporting rules and make
sure the final FPGA implementation passes timing. Interrupt-service time is
included in this RT-Thread-hosted measurement.

To build a bitstream, select this directory's `build/fpga` as `FirmwareDir` in
`fpga/vivado/build_bitstream.ps1`.
