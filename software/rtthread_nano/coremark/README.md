# RT-Thread Nano + CoreMark FPGA firmware

This target links the RT-Thread v3.1.5 Nano kernel, the maintained step8 BSP, the
upstream CoreMark 1.0 workload and the HC-SR04 command into one FPGA firmware
image. `coremark` and `distance` are independent shell commands; they do not
run concurrently and the FPGA only needs one firmware image.

## Build

From WSL or Linux:

```sh
make -B BUILD_DIR=build/fpga TIMER_PERIOD_CYCLES=2000000 IROM_WORDS=16384 \
  COREMARK_ITERATIONS=10000 RTTHREAD_OPT_FLAGS=-O1 \
  COREMARK_OPT_FLAGS=-O3 \
  COREMARK_FLAGS_LABEL="-O3 + cmcrc16 / RT-Thread 3.1.5" \
  COREMARK_CRC_HW=1
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
32-bit hexadecimal memory files under `build/fpga/mem/`. The IROM image is
16,384 words (64 KiB), matching `student_top.sv` and `Mem_IROM`.

## Board behavior

- the CPU clock and timer period above correspond to 200 MHz and a 100 Hz
  RT-Thread scheduling tick;
- the LED register is nonzero while CoreMark is running and is cleared at end;
- UART output uses 115200 baud, 8 data bits, no parity and one stop bit;
- the UART command shell accepts `help`, `coremark` and `distance` repeatedly;
- CoreMark timing comes from the independent 1 kHz hardware counter at
  `0x80200050`, not from RT-Thread timer-interrupt counts;
- the default 10,000 iterations are long enough for CoreMark's ten-second rule.

For a reportable score, also follow the upstream run/reporting rules and make
sure the final FPGA implementation passes timing. RT-Thread timer interrupts
still run during the benchmark, but elapsed time is sampled exclusively from
the hardware millisecond counter.

## HC-SR04 connection and registers

- `hcsr04_trig`: FPGA G17, J7-1 / Debug_1, output;
- `hcsr04_echo`: FPGA G18, J7-2 / Debug_2, input;
- the sensor uses an external 5 V supply and a common ground;
- ECHO must pass through a 5 V to 3.3 V divider or level shifter before J7-2;
- Bank 17 VADJ1 must be 3.3 V for the supplied LVCMOS33 constraints.

The hardware controller generates the 10 us trigger and measures ECHO without
software timing. Its MMIO registers are `CTRL=0x80200080`,
`STATUS=0x80200084`, `ECHO_US=0x80200088` and
`ECHO_CYCLES=0x8020008c`. A no-echo condition times out after 30 ms.

Example:

```text
msh >distance
[distance] HC-SR04 measurement start
[distance] echo time: 1166 us
[distance] distance: 200 mm
```

To build a bitstream, select this directory's `build/fpga` as `FirmwareDir` in
`fpga/vivado/build_bitstream.ps1`.

## CoreMark CRC instruction

The CPU implements `cmcrc16`, an R-type instruction
in the RISC-V CUSTOM-0 opcode space:

```text
opcode = 0x0b, funct7 = 0, funct3 = 0
cmcrc16 rd, rs1, rs2
rd = zero_extend(crcu16(rs1[15:0], rs2[15:0]))
```

The RTL implements the reflected `0xa001` update as a parallel XOR network.
The upstream CoreMark source is not edited. GCC first emits optimized assembly
for `core_util.c`; `compiler/coremark_crc_pass.py` then verifies the expected
CRC pattern and the official source SHA-256 before replacing `crcu16`, `crc16`
and `crcu32` with CUSTOM-0 instructions. Assembly, linking, ELF and COE
generation then use the normal toolchain.

Build the 100-iteration accelerated image with:

```sh
make -B BUILD_DIR=build/rtthread315_crc100 \
  TIMER_PERIOD_CYCLES=2000000 IROM_WORDS=16384 \
  COREMARK_ITERATIONS=100 COREMARK_ALLOW_SHORT_RUN=1 \
  RTTHREAD_OPT_FLAGS=-O1 COREMARK_OPT_FLAGS=-O3 \
  COREMARK_FLAGS_LABEL="-O3 + cmcrc16 / RT-Thread 3.1.5" COREMARK_CRC_HW=1
```

The generated FPGA files are `build/rtthread315_crc100/irom.coe` and
`build/rtthread315_crc100/dram.coe`. The compiler recognition audit is written
to `build/rtthread315_crc100/coremark_crc_pass.txt`.

At an ideal 200 MHz CPU clock, the Verilator 100-iteration comparison was:

| Build | CPU cycles | Exact time | 1 kHz ticks | Iterations/s |
|---|---:|---:|---:|---:|
| v3.1.5 + GCC `-O3` baseline | 38,327,880 | 0.191639400 s | 191 | 523.560209 |
| v3.1.5 + GCC `-O3` + `cmcrc16` | 34,073,030 | 0.170365150 s | 170 | 588.235294 |

The accelerated run retired 29,200 `cmcrc16` instructions, saved 4,254,850
cycles (11.10% elapsed-cycle reduction, 1.1249x speedup), and produced the
standard `e714/1fd7/8e3a/988c` CRC values. A 100-iteration run is a functional
and comparative test only; it is shorter than CoreMark's reportable duration.
