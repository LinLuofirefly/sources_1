# Vivado 生成与下载 bit 流

这套流程固定使用工程顶层 `top`、器件 `xc7k325tffg900-2`，并要求在构建时明确指定一份同时包含 `irom.coe` 和 `dram.coe` 的固件目录。脚本会先把固件绑定到两个 Block Memory IP，再重新生成 IP、综合、实现、bit 流和时序报告，避免 Vivado 沿用工程中某个历史 COE 文件。

## 目录职责

- `new/top.sv`：板级物理顶层、PLL、UART 引脚通道和 CPU 子系统
- `new/student_top.sv`：CPU、IROM 和外设桥
- `imports/new/`：CPU 流水线、CSR、定时器等可综合 RTL
- `new/perip_bridge.sv`、`new/dram_driver.sv`：UART、LED、数码管和 DRAM 外设
- `ip/`：PLL、IROM、DRAM 的 Vivado IP 配置
- `software/rtthread_nano/step8/`：RT-Thread Nano BSP 和普通线程应用
- `fpga/vivado/`：正式 bit 流构建、报告和下载脚本

仿真 testbench、`.mem`、Verilator/XSim 输出不会参与 bit 流综合。真正进入 FPGA 的是可综合 RTL、三个 IP、XDC 约束，以及写进 IROM/DRAM BRAM 初始化内容的固件。

## 1. 先生成 FPGA 固件

交叉编译工具目前位于 WSL，因此先在 PowerShell 中执行：

```powershell
wsl bash -lc "cd /mnt/c/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1/software/rtthread_nano/step8 && make -B BUILD_DIR=build/fpga TIMER_PERIOD_CYCLES=1900000"
```

这里 `1900000 = 190 MHz / 100 Hz`，对应 RT-Thread 的 100 Hz tick。成功后应有：

```text
software/rtthread_nano/step8/build/fpga/irom.coe
software/rtthread_nano/step8/build/fpga/dram.coe
software/rtthread_nano/step8/build/fpga/rtthread_nano.elf
software/rtthread_nano/step8/build/fpga/rtthread_nano.dis
```

## 2. 先做快速配置检查

在 `sources_1` 目录的 PowerShell 中执行：

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass `
  -File .\fpga\vivado\build_bitstream.ps1 `
  -FirmwareDir .\software\rtthread_nano\step8\build\fpga `
  -FrequencyMHz 190 `
  -CheckOnly
```

检查会打开 `digital_twin.xpr`，确认器件、顶层、PLL/IROM/DRAM IP 和两份 COE 文件，不运行综合和布局布线。

## 3. 完整生成 bit 流

RT-Thread Nano：

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass `
  -File .\fpga\vivado\build_bitstream.ps1 `
  -FirmwareDir .\software\rtthread_nano\step8\build\fpga `
  -FrequencyMHz 190 `
  -Name digital_twin_rtthread_nano_190MHz
```

输出默认在固件目录的 `vivado_190_000MHz/` 下：

```text
<name>.bit
build_summary.txt
reports/timing_summary.rpt
reports/timing_setup_paths.rpt
reports/timing_hold_paths.rpt
reports/drc.rpt
reports/utilization.rpt
```

必须检查 `build_summary.txt` 中：

```text
timing_met=1
wns_ns >= 0
whs_ns >= 0
```

脚本即使遇到时序失败也会保留 bit 流和报告用于定位，但默认返回错误码 8，不能把它当作可靠发布版本。只有用于临时实验时才可加 `-AllowTimingFail`。

以前保存的 `digital_twin_step8_190MHz.bit` 对应报告为 `WNS=-0.253 ns`、`WHS=0.063 ns`、`timing_met=0`，因此应由这套流程重新构建并重新检查，而不是直接作为正式下载文件。

如果重新实现后 190 MHz 仍不收敛，可以先用 180 MHz 验证板级功能。此时要同时把固件参数改为 `TIMER_PERIOD_CYCLES=1800000`，再把 bit 流命令改为 `-FrequencyMHz 180`；构建脚本会同步修改 PLL 请求频率、CPU 顶层频率参数和 UART 分频参数。降低频率后仍必须以新报告中的 `timing_met=1` 为准。

## 4. 下载到 FPGA

连接并上电开发板，接好 JTAG，然后执行：

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass `
  -File .\fpga\vivado\program_bitstream.ps1 `
  -Bitstream .\software\rtthread_nano\step8\build\fpga\vivado_190_000MHz\digital_twin_rtthread_nano_190MHz.bit
```

如果 JTAG 链上有多个同型号器件，可用 `-DeviceIndex 1` 选择第二个。bit 流只写入 FPGA SRAM，断电后消失；若要上电自动启动，还需根据板卡 Flash 型号生成并烧写 `.bin`/`.mcs`，不能在不知道配置 Flash 型号时直接操作。

下载后用串口工具打开板上 TX 对应串口：

```text
115200 baud, 8 data bits, no parity, 1 stop bit
```

RT-Thread 固件应通过 UART 输出启动 banner、主线程、工作线程和 tick 信息。

## Vivado GUI 中的等价操作

脚本方式更不容易选错固件。如果需要在 GUI 中查看过程：

1. 打开 `C:\Users\hp\Downloads\digital_twin\digital_twin.xpr`。
2. 在 Sources 中确认 Design Sources 顶层是 `top`，器件是 `xc7k325tffg900-2`。
3. 打开 `Mem_IROM`，把初始化文件设为本次固件的 `irom.coe`；打开 `Mem_RAM`，设为同一固件目录的 `dram.coe`。
4. 打开 `pll`，确认第二路输出请求频率为 190 MHz，然后重新 Generate Output Products。
5. 在 Settings 的 Synthesis/More Options 中确认顶层参数与脚本一致：`P_CPU_CLK_HZ=190000000`、`P_CPU_UART_BAUD_RATE=115200`、`P_CPU_CONSOLE_ON_UART=1`。
6. 依次运行 Generate Bitstream。Vivado 会自动执行 Synthesis、Implementation 和 Write Bitstream。
7. 打开 Implemented Design，查看 Report Timing Summary，只有 setup/hold 均通过才继续下载。
8. 打开 Hardware Manager，Open Target -> Auto Connect，选择器件后 Program Device，指定刚生成并通过时序检查的 `.bit`。

每次修改 CPU/外设 RTL，都要重新综合和实现；每次修改 C/汇编程序，都要重新生成 COE，并至少重新生成 BRAM IP 输出产品和 bit 流。不能只替换磁盘上的 COE 后继续使用旧 bit 流。

`new/run_impl_*.tcl`、`new/set_clk2_only.tcl` 和 `step8/vivado_recover_190.tcl` 是以前的单次调试/恢复脚本，保留用于追溯，不作为当前正式构建入口。正式入口只有本目录的 `build_bitstream.ps1`/`build_bitstream.tcl`。
