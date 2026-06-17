param(
    [Parameter(Mandatory = $true)]
    [double]$FreqMHz,
    [string]$ProjectPath = "C:\Users\hp\Downloads\digital_twin\digital_twin.xpr",
    [string]$VivadoBat = "E:\Vivado\Vivado\2023.2\bin\vivado.bat"
)

$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent (Split-Path -Parent $PSCommandPath)
$TclScript = Join-Path $Root "new\run_impl_clk2.tcl"
$tag = ("{0:0.###}" -f $FreqMHz).Replace(".", "p")
$stdout = Join-Path $Root ("vivado_clk2_{0}_stdout.log" -f $tag)
$stderr = Join-Path $Root ("vivado_clk2_{0}_stderr.log" -f $tag)
$pidFile = Join-Path $Root ("vivado_clk2_{0}.pid" -f $tag)

if (-not (Test-Path $VivadoBat)) {
    throw "Vivado not found: $VivadoBat"
}
if (-not (Test-Path $ProjectPath)) {
    throw "Project not found: $ProjectPath"
}
if (-not (Test-Path $TclScript)) {
    throw "Tcl script not found: $TclScript"
}

Remove-Item -LiteralPath $stdout, $stderr, $pidFile -Force -ErrorAction SilentlyContinue

$freqText = "{0:0.###}" -f $FreqMHz
$argsList = @(
    "-mode", "batch",
    "-source", $TclScript,
    "-tclargs", $ProjectPath, $freqText
)

$proc = Start-Process -FilePath $VivadoBat `
    -ArgumentList $argsList `
    -WorkingDirectory $Root `
    -RedirectStandardOutput $stdout `
    -RedirectStandardError $stderr `
    -WindowStyle Hidden `
    -PassThru

Set-Content -LiteralPath $pidFile -Value $proc.Id
Write-Output ("STARTED freq_mhz={0} pid={1} stdout={2} stderr={3}" -f $freqText, $proc.Id, $stdout, $stderr)
