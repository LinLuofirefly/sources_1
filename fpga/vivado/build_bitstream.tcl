# Reproducible Vivado project build for the digital_twin FPGA image.
#
# Example:
#   vivado -mode batch -source build_bitstream.tcl -tclargs \
#     -firmware_dir C:/path/to/build/fpga -freq_mhz 200 -name rtthread_hcsr04

proc print_usage {} {
    puts {Usage: build_bitstream.tcl -firmware_dir DIR ?options?}
    puts {  -project FILE            Vivado .xpr (default: repository digital_twin.xpr)}
    puts {  -firmware_dir DIR        directory containing irom.coe and dram.coe}
    puts {  -freq_mhz NUMBER         requested CPU PLL frequency (default: 200)}
    puts {  -baud NUMBER             CPU UART baud rate (default: 115200)}
    puts {  -jobs NUMBER             parallel Vivado jobs (default: 8)}
    puts {  -name TEXT               output name (default: digital_twin_<freq>MHz)}
    puts {  -out_dir DIR             output directory (default: DIR/vivado_<freq>MHz)}
    puts {  -check_only              validate inputs/project without changing it}
    puts {  -allow_timing_fail       return success even when setup/hold timing fails}
}

proc fail_build {message {code 2}} {
    puts stderr "FPGA_BUILD_ERROR: $message"
    catch {close_design}
    catch {close_project}
    exit $code
}

proc require_one {objects description} {
    if {[llength $objects] != 1} {
        fail_build "expected exactly one $description, found [llength $objects]" 3
    }
    return [lindex $objects 0]
}

proc require_file {path description} {
    if {![file isfile $path]} {
        fail_build "missing $description: $path" 2
    }
}

proc run_and_check {run_name jobs label} {
    set run_obj [require_one [get_runs -quiet $run_name] "Vivado run '$run_name'"]
    reset_run $run_obj
    launch_runs $run_obj -jobs $jobs
    wait_on_run $run_obj
    set status [get_property STATUS $run_obj]
    puts "FPGA_BUILD_RUN: $label status='$status'"
    if {![regexp -nocase {complete} $status]} {
        fail_build "$label did not complete (status '$status')" 4
    }
    return $status
}

set script_dir [file dirname [file normalize [info script]]]
set default_project [file normalize [file join $script_dir .. .. .. .. digital_twin.xpr]]
set hcsr04_rtl [file normalize [file join $script_dir .. .. new hcsr04_controller.sv]]
set hcsr04_xdc [file normalize [file join $script_dir .. xdc hcsr04_j7_g17_g18.xdc]]

array set options [list \
    project $default_project \
    firmware_dir {} \
    freq_mhz 200.000 \
    baud 115200 \
    jobs 8 \
    name {} \
    out_dir {} \
    check_only 0 \
    allow_timing_fail 0]

set index 0
while {$index < [llength $argv]} {
    set key [lindex $argv $index]
    switch -- $key {
        -project - -firmware_dir - -freq_mhz - -baud - -jobs - -name - -out_dir {
            incr index
            if {$index >= [llength $argv]} {
                print_usage
                fail_build "missing value after $key" 2
            }
            set option_name [string range $key 1 end]
            set options($option_name) [lindex $argv $index]
        }
        -check_only {
            set options(check_only) 1
        }
        -allow_timing_fail {
            set options(allow_timing_fail) 1
        }
        -help - --help - -h {
            print_usage
            exit 0
        }
        default {
            print_usage
            fail_build "unknown option '$key'" 2
        }
    }
    incr index
}

if {$options(firmware_dir) eq {}} {
    print_usage
    fail_build {-firmware_dir is required; select the firmware image explicitly} 2
}
if {![string is double -strict $options(freq_mhz)] || $options(freq_mhz) <= 0.0} {
    fail_build "invalid -freq_mhz '$options(freq_mhz)'" 2
}
if {![string is integer -strict $options(baud)] || $options(baud) <= 0} {
    fail_build "invalid -baud '$options(baud)'" 2
}
if {![string is integer -strict $options(jobs)] || $options(jobs) <= 0} {
    fail_build "invalid -jobs '$options(jobs)'" 2
}

set project_path [file normalize $options(project)]
set firmware_dir [file normalize $options(firmware_dir)]
set irom_coe [file join $firmware_dir irom.coe]
set dram_coe [file join $firmware_dir dram.coe]
require_file $project_path {Vivado project}
require_file $irom_coe {IROM initialization file}
require_file $dram_coe {DRAM initialization file}
require_file $hcsr04_rtl {HC-SR04 RTL source}
require_file $hcsr04_xdc {HC-SR04 J7 pin constraints}

set freq_tag [string map {. _} [format %.3f $options(freq_mhz)]]
if {$options(name) eq {}} {
    set options(name) "digital_twin_${freq_tag}MHz"
}
if {$options(out_dir) eq {}} {
    set options(out_dir) [file join $firmware_dir "vivado_${freq_tag}MHz"]
}
set output_dir [file normalize $options(out_dir)]
set report_dir [file join $output_dir reports]
set bit_output [file join $output_dir "$options(name).bit"]
set summary_path [file join $output_dir build_summary.txt]
set cpu_clk_hz [expr {round($options(freq_mhz) * 1000000.0)}]

puts "FPGA_BUILD_INPUT: project=$project_path"
puts "FPGA_BUILD_INPUT: firmware=$firmware_dir"
puts "FPGA_BUILD_INPUT: irom=$irom_coe ([file size $irom_coe] bytes)"
puts "FPGA_BUILD_INPUT: dram=$dram_coe ([file size $dram_coe] bytes)"
puts "FPGA_BUILD_INPUT: requested_cpu_mhz=$options(freq_mhz) uart_baud=$options(baud)"

open_project $project_path
set_param general.maxThreads $options(jobs)

set source_set [require_one [get_filesets -quiet sources_1] {source fileset 'sources_1'}]
set constraint_set [require_one [get_filesets -quiet constrs_1] {constraint fileset 'constrs_1'}]
if {[llength [get_files -quiet [file tail $hcsr04_rtl]]] == 0} {
    add_files -fileset $source_set -norecurse $hcsr04_rtl
}
if {[llength [get_files -quiet [file tail $hcsr04_xdc]]] == 0} {
    add_files -fileset $constraint_set -norecurse $hcsr04_xdc
}
set project_top [get_property TOP $source_set]
set project_part [get_property PART [current_project]]
if {$project_top ne {top}} {
    fail_build "project top must be 'top', got '$project_top'" 3
}
if {$project_part ne {xc7k325tffg900-2}} {
    fail_build "project part must be xc7k325tffg900-2, got '$project_part'" 3
}

set pll_ip [require_one [get_ips -quiet pll] {IP 'pll'}]
set irom_ip [require_one [get_ips -quiet Mem_IROM] {IP 'Mem_IROM'}]
set dram_ip [require_one [get_ips -quiet Mem_RAM] {IP 'Mem_RAM'}]

if {$options(check_only)} {
    puts "FPGA_BUILD_CHECK: top=$project_top part=$project_part"
    puts "FPGA_BUILD_CHECK: current_pll_mhz=[get_property CONFIG.CLKOUT2_REQUESTED_OUT_FREQ $pll_ip]"
    set current_irom_depth [get_property CONFIG.Write_Depth_A $irom_ip]
    puts "FPGA_BUILD_CHECK: irom_words=$current_irom_depth"
    if {$current_irom_depth != 16384} {
        fail_build "Mem_IROM must be 16384 words (64 KiB), got $current_irom_depth" 3
    }
    puts "FPGA_BUILD_CHECK: would bind Mem_IROM to $irom_coe"
    puts "FPGA_BUILD_CHECK: would bind Mem_RAM to $dram_coe"
    puts {FPGA_BUILD_CHECK: PASS (project and firmware inputs are usable)}
    close_project
    exit 0
}

file mkdir $report_dir

# Keep PLL, software timing constants and the UART divider on one frequency.
set_property CONFIG.CLKOUT2_REQUESTED_OUT_FREQ $options(freq_mhz) $pll_ip
set_property generic [list \
    P_CPU_CONSOLE_ON_UART=1 \
    P_CPU_CLK_HZ=$cpu_clk_hz \
    P_CPU_UART_BAUD_RATE=$options(baud)] $source_set

# Bind the requested software image before regenerating the BRAM output products.
set_property CONFIG.Write_Depth_A 16384 $irom_ip
set_property CONFIG.Load_Init_File true $irom_ip
set_property CONFIG.Coe_File $irom_coe $irom_ip
set_property CONFIG.Load_Init_File true $dram_ip
set_property CONFIG.Coe_File $dram_coe $dram_ip

foreach ip [list $pll_ip $irom_ip $dram_ip] {
    reset_target all $ip
    generate_target all $ip
    export_ip_user_files -of_objects $ip -no_script -sync -force
}
update_compile_order -fileset $source_set

foreach run_name {pll_synth_1 Mem_IROM_synth_1 Mem_RAM_synth_1} {
    if {[llength [get_runs -quiet $run_name]] == 1} {
        run_and_check $run_name $options(jobs) "IP $run_name"
    }
}

set impl_run [require_one [get_runs -quiet impl_1] {implementation run 'impl_1'}]
set synth_run [require_one [get_runs -quiet synth_1] {synthesis run 'synth_1'}]
reset_run $impl_run
set synth_status [run_and_check synth_1 $options(jobs) {top-level synthesis}]

# Vivado 2023.2 previously crashed in this project's optional post-route Explore
# pass.  Route timing cleanup is retained; only that unstable optional pass is off.
set_property STEPS.POST_ROUTE_PHYS_OPT_DESIGN.IS_ENABLED false $impl_run
launch_runs $impl_run -to_step write_bitstream -jobs $options(jobs)
wait_on_run $impl_run
set impl_status [get_property STATUS $impl_run]
puts "FPGA_BUILD_RUN: implementation status='$impl_status'"
if {![regexp -nocase {complete} $impl_status]} {
    fail_build "implementation did not complete (status '$impl_status')" 5
}

open_run $impl_run
report_timing_summary -delay_type min_max -max_paths 80 -nworst 10 \
    -file [file join $report_dir timing_summary.rpt]
report_timing -delay_type max -sort_by group -max_paths 30 -nworst 5 \
    -path_type full_clock_expanded -file [file join $report_dir timing_setup_paths.rpt]
report_timing -delay_type min -sort_by group -max_paths 30 -nworst 5 \
    -path_type full_clock_expanded -file [file join $report_dir timing_hold_paths.rpt]
report_route_status -file [file join $report_dir route_status.rpt]
report_drc -file [file join $report_dir drc.rpt]
report_utilization -file [file join $report_dir utilization.rpt]
check_timing -verbose -file [file join $report_dir check_timing.rpt]

set setup_paths [get_timing_paths -delay_type max -max_paths 1]
set hold_paths [get_timing_paths -delay_type min -max_paths 1]
set wns NA
set whs NA
if {[llength $setup_paths] > 0} {
    set wns [get_property SLACK [lindex $setup_paths 0]]
}
if {[llength $hold_paths] > 0} {
    set whs [get_property SLACK [lindex $hold_paths 0]]
}

set period_ns NA
set actual_mhz NA
set cpu_clock [get_clocks -quiet clk_out2_pll]
if {[llength $cpu_clock] == 1} {
    set period_ns [get_property PERIOD [lindex $cpu_clock 0]]
    set actual_mhz [format %.6f [expr {1000.0 / $period_ns}]]
}

set timing_met 0
if {$wns ne {NA} && $whs ne {NA} && $wns >= 0.0 && $whs >= 0.0} {
    set timing_met 1
}

set run_directory [get_property DIRECTORY $impl_run]
set bit_candidates [glob -nocomplain [file join $run_directory *.bit]]
if {[llength $bit_candidates] != 1} {
    fail_build "expected one generated bitstream in $run_directory, found [llength $bit_candidates]" 6
}
file copy -force [lindex $bit_candidates 0] $bit_output

set summary [open $summary_path w]
puts $summary "project=$project_path"
puts $summary "part=$project_part"
puts $summary "top=$project_top"
puts $summary "firmware_dir=$firmware_dir"
puts $summary "irom_coe=$irom_coe"
puts $summary "dram_coe=$dram_coe"
puts $summary "requested_mhz=$options(freq_mhz)"
puts $summary "actual_mhz=$actual_mhz"
puts $summary "period_ns=$period_ns"
puts $summary "uart_baud=$options(baud)"
puts $summary "synth_status=$synth_status"
puts $summary "impl_status=$impl_status"
puts $summary "wns_ns=$wns"
puts $summary "whs_ns=$whs"
puts $summary "timing_met=$timing_met"
puts $summary "bitstream=$bit_output"
close $summary

puts "FPGA_BUILD_RESULT: actual_mhz=$actual_mhz wns=$wns whs=$whs timing_met=$timing_met"
puts "FPGA_BUILD_RESULT: bitstream=$bit_output"
puts "FPGA_BUILD_RESULT: reports=$report_dir"
close_design
close_project

if {!$timing_met && !$options(allow_timing_fail)} {
    puts stderr {FPGA_BUILD_ERROR: bitstream was generated, but timing did not pass; do not treat it as a release image}
    exit 8
}
exit 0
