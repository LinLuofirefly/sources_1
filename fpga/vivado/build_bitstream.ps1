param(
    [Parameter(Mandatory = $true)]
    [string]$FirmwareDir,

    [double]$FrequencyMHz = 190.0,
    [int]$Baud = 115200,
    [int]$Jobs = 8,
    [string]$Name = "",
    [string]$OutputDir = "",
    [string]$Vivado = "E:\Vivado\Vivado\2023.2\bin\vivado.bat",
    [switch]$CheckOnly,
    [switch]$AllowTimingFail
)

$ErrorActionPreference = "Stop"
$script = Join-Path $PSScriptRoot "build_bitstream.tcl"
$project = Join-Path $PSScriptRoot "..\..\..\..\digital_twin.xpr"
$firmware = (Resolve-Path -LiteralPath $FirmwareDir).Path

if (-not (Test-Path -LiteralPath $Vivado -PathType Leaf)) {
    throw "Vivado launcher not found: $Vivado"
}

$vivadoArgs = @(
    "-mode", "batch",
    "-source", $script,
    "-nolog", "-nojournal",
    "-tclargs",
    "-project", $project,
    "-firmware_dir", $firmware,
    "-freq_mhz", $FrequencyMHz,
    "-baud", $Baud,
    "-jobs", $Jobs
)
if ($Name) {
    $vivadoArgs += @("-name", $Name)
}
if ($OutputDir) {
    $vivadoArgs += @("-out_dir", $OutputDir)
}
if ($CheckOnly) {
    $vivadoArgs += "-check_only"
}
if ($AllowTimingFail) {
    $vivadoArgs += "-allow_timing_fail"
}

& $Vivado @vivadoArgs
exit $LASTEXITCODE
