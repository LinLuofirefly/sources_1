# Agent Notes: Vivado / Verilator Workflow

本文记录本项目中用 Codex 操作 Vivado、Verilator 和 WSL 的经验，供后续 agent 接手时直接复用。

## 基本路径

- Vivado 安装目录：`E:\Vivado\Vivado\2023.2`
- Vivado 工程：`C:\Users\hp\Downloads\digital_twin\digital_twin.xpr`
- 当前源码根目录：`C:\Users\hp\Downloads\digital_twin\digital_twin.srcs\sources_1`
- WSL 发行版：`Ubuntu`
- WSL 原生仿真目录：`/home/lingluo/digital_twin_sim`
- 正常长程序镜像目录：`/home/lingluo/digital_twin_sim/sim`
- 不要随便用 `/home/lingluo/digital_twin_runs/sources_1_src0/sim`。那里的 `irom.mem` 和正常镜像不同，曾经导致 LED 首写变成错误值。

## 先仿真，再实现

改 RTL 后先跑小仿真，至少确认第一次 SEG 写入：

```text
SEG_WRITE #1 ... data=37000000
```

长仿真以 LED 第一次写入为准，正常值是：

```text
LED_WRITE #1 ... data=01221c08
```

一次确认过的 221.435 MHz Verilator 结果：

```text
TB_CPU_CLOCK freq_mhz=221.435 half_period_ns=2.258000
SEG_WRITE #1 cyc=1673 pc=80000148 data=37000000
SEG_WRITE #2 cyc=3362539912 pc=800001ac data=37015185
LED_WRITE #1 cyc=3362539995 pc=800001e4 data=01221c08 seg_writes=2
```

`SEG_WRITE #2` 的 data 可能随计数/运行参数变化，不要把它当成唯一功能判据；LED 首写 `01221c08` 更关键。

## Verilator 运行方式

优先在 WSL 原生目录跑，不要在 `/mnt/c` 下跑长仿真。`/mnt/c` 上的 Verilator 二进制和 obj 目录会明显变慢。

典型流程：

```bash
cd /home/lingluo/digital_twin_sim
ROOT=/home/lingluo/digital_twin_sim \
SRC0_SIM=/home/lingluo/digital_twin_sim/sim \
CPU_HALF_PERIOD_NS=2.258 \
bash new/run_verilator_tb_seg_led_stop_src0_fmax.sh
```

如果要从 Windows 后台启动 WSL 长仿真，用 PowerShell `Start-Process -WindowStyle Hidden`，不要依赖 `nohup` 从短命 WSL session 保活。

## 镜像一致性检查

跑长仿真前先确认 `irom.mem/dram.mem`：

```bash
sha256sum /home/lingluo/digital_twin_sim/sim/irom.mem \
          /home/lingluo/digital_twin_sim/sim/dram.mem
```

已知正常镜像哈希：

```text
1fdb9f716fd276392ee61967c48b0ce1b310d84d60654cf21b93264e5ec53ece  sim/irom.mem
b1670abe2a7383deb99ed3d2fbc36b8929390d86bda33a350b8c8fb5b0accf6d  sim/dram.mem
```

曾经误用的镜像：

```text
5ec6d4e2102ebe9008a4e85b2bc229a5a9e3a6ba24c4cb16459da449d08c4cc5  /home/lingluo/digital_twin_runs/sources_1_src0/sim/irom.mem
```

该错误镜像曾跑出：

```text
LED_WRITE #1 ... data=24181824
```

这个结果不是 RTL 功能通过。

## Vivado 批处理习惯

推荐用 Tcl 批处理，不要手动点 GUI：

```powershell
& "E:\Vivado\Vivado\2023.2\bin\vivado.bat" -mode batch -source new/run_impl_clk2.tcl
```

实现前后至少输出：

- `report_timing_summary`
- `report_timing`
- `report_route_status`
- `report_utilization`

频率扫点时，记录请求频率和实际 PLL 输出频率。PLL 可能把请求频率量化成实际频率，例如请求 223 MHz 时实际约为 221.435 MHz。

一次已跑过的结果：

```text
request 223 MHz -> actual 221.434898 MHz, period 4.516 ns, WNS 0.031, WHS 0.086, timing met
request 224 MHz -> actual 225.022502 MHz, period 4.444 ns, WNS -0.069, timing failed
```

注意：这些结果只对当时 RTL 有效。恢复 RAS/forwarding 后需要重新跑 implementation 才能重新确认最高收敛频率。

## PLL / IP 修改

可以通过 Tcl 修改 PLL IP 的 `CLKOUT2_REQUESTED_OUT_FREQ`，然后重新 generate target / implementation。

当前 `ip/pll_1/pll.xci` 中曾设置：

```text
CLKOUT2_REQUESTED_OUT_FREQ = 223
C_CLKOUT2_OUT_FREQ ~= 221.42857
```

改 PLL 后必须重新实现，不能只看 xci。

## 时序分析经验

不要只看某一条 path 的 `logic delay + net delay` 是否小于 4.8 ns。Vivado setup 违例还会受这些因素影响：

- clock uncertainty
- setup requirement
- clock skew
- CPR
- generated clock 实际周期
- routing 阶段 hold/setup 同时收敛约束

遇到 `tight setup and hold constraints` 的 pin，优先看：

- 是否是同一批高扇出控制信号
- 是否同时连到 BRAM data/control pin
- 是否跨很远区域
- 是否属于 IF/ID 的 `pred_target`、flush/hold、MMIO/DRAM 写数据路径

先做低风险 RTL 优化：

- 降低高扇出控制信号扇出，必要时复制组合控制局部使用
- 拆开控制条件，避免一个大条件直接驱动多个模块
- 对不会影响 PC 的数据 forwarding 和会影响 PC 的 branch/jalr path 分开分析
- 不要为了时序随便关掉 RAS/JALR 预测或完整 forwarding；这会让长程序 cycle 数暴涨，甚至 TB timeout

## 本次踩坑

### 1. 关掉 RAS/JALR 预测会让长程序跑不完

`branch_predictor.v` 中如果：

```verilog
parameter ENABLE_JALR_RAS_PRED = 1'b0
```

会导致：

```text
jalr_pred_taken=0
return_coverage=0.00%
```

长仿真曾在 30s 仿真时间上限 timeout：

```text
TIMEOUT cyc=6643046940 seg_writes=1 led_writes=0
```

正常应保持：

```verilog
parameter ENABLE_JALR_RAS_PRED = 1'b1
```

正常统计接近：

```text
jalr_accuracy=96.92%
return_accuracy=99.87%
return_coverage=100.00%
```

### 2. 只保留 EX/MEM forwarding、其它靠 stall 补偿不可取

曾尝试把 `forwarding.v` 拆到只保留 EX/MEM forwarding，并在 HDU 中对 MEM1/MEM2/MEM2A/MEM2 相关全部 stall。结果第一条 SEG cycle 从 1673 变成 1994/2082，长程序无法在 TB 限时内完成。

结论：完整 forwarding 是这个程序性能正确性的一部分。后续时序优化不要用大面积 stall 替代 forwarding。

### 3. WSL 命令里的 `$` 会被 PowerShell 吃掉

从 PowerShell 直接写：

```powershell
wsl -d Ubuntu bash -lc 'x=abc; echo $x'
```

在本环境中 `$x` 可能被提前展开为空。复杂 WSL 命令建议写成 `.sh` 文件后调用，或者避免在 PowerShell 命令串里直接放 Bash `$变量`。

### 4. 后台长仿真不要用短命 WSL session 的 nohup

曾用 `nohup ... &` 启动，进程立刻没了且日志为空。更可靠的方法是在 Windows 侧用：

```powershell
Start-Process -WindowStyle Hidden -FilePath wsl.exe -ArgumentList ...
```

## 接手建议

1. 改 RTL 后先跑短 SEG smoke。
2. 长仿真必须使用 `/home/lingluo/digital_twin_sim/sim` 镜像。
3. LED 首写不是 `01221c08` 时，不要继续拿这个 RTL 做 Vivado 频率结论。
4. 恢复或修改 timing 优化后，重新跑 Vivado implementation；旧 WNS 只对旧 RTL 有效。
5. 对于 branch predictor，保持 RAS/JALR 预测开启，再考虑低扇出和布局友好的实现方式。
