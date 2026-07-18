# ===========================================================================
# sim/run.ps1 — Verilator 仿真运行脚本 (Windows PowerShell → WSL)
#
# 用法 (从工程根目录运行):
#   powershell -File sim\run.ps1                      # 默认 200M 周期
#   powershell -File sim\run.ps1 -MaxCycles 50000000  # 自定义周期数
#   powershell -File sim\run.ps1 -Wave                # 带波形输出
#   powershell -File sim\run.ps1 -Clean               # 清理构建文件
#
# 此脚本通过 WSL 调用 Verilator 编译和运行仿真。
# ===========================================================================

param(
    [string]$MaxCycles = "",
    [switch]$Wave,
    [switch]$Clean
)

$ErrorActionPreference = "Stop"
$ProjectRoot = Split-Path -Parent $PSScriptRoot
if (-not $ProjectRoot) { $ProjectRoot = Get-Location }
Set-Location $ProjectRoot

if ($Clean) {
    Write-Host "=== Cleaning ==="
    wsl -- bash -c "rm -rf /mnt/c/Users/ACER/Desktop/Linluofirefly/sources_1/sim/obj_dir"
    Remove-Item -Force "sim\logs\sim.log" -ErrorAction SilentlyContinue
    Write-Host "=== Clean done ==="
    exit 0
}

# 编译 & 运行通过 WSL
$WslProject = "/mnt/c/Users/ACER/Desktop/Linluofirefly/sources_1"
$WaveFlag = if ($Wave) { "--wave" } else { "" }

if ($MaxCycles) {
    $MaxCyclesArg = "--max-cycles $MaxCycles"
    $RunLabel = "max_cycles=$MaxCycles"
} else {
    $MaxCyclesArg = ""
    $RunLabel = "LED>=1 SEG>=2"
}

Write-Host "=== Building and running via WSL ($RunLabel) ==="
$WslCmd = "cd $WslProject && bash sim/run.sh $MaxCyclesArg $WaveFlag"
wsl -- bash -c "$WslCmd"

Write-Host "=== Log file: sim\logs\sim.log ==="
