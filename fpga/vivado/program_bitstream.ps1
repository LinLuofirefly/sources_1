param(
    [Parameter(Mandatory = $true)]
    [string]$Bitstream,

    [int]$DeviceIndex = 0,
    [string]$Vivado = "E:\Vivado\Vivado\2023.2\bin\vivado.bat"
)

$ErrorActionPreference = "Stop"
$script = Join-Path $PSScriptRoot "program_bitstream.tcl"
$bit = (Resolve-Path -LiteralPath $Bitstream).Path

if (-not (Test-Path -LiteralPath $Vivado -PathType Leaf)) {
    throw "Vivado launcher not found: $Vivado"
}

& $Vivado -mode batch -source $script -nolog -nojournal -tclargs `
    -bit $bit -device_index $DeviceIndex
exit $LASTEXITCODE
