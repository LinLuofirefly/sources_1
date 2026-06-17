set project_path "C:/Users/hp/Downloads/digital_twin/digital_twin.xpr"
set freq_mhz "210"

if {[llength $argv] >= 1} {
    set project_path [lindex $argv 0]
}
if {[llength $argv] >= 2} {
    set freq_mhz [lindex $argv 1]
}

set tag [string map {. p} $freq_mhz]
set report_dir "C:/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1/vivado_clk2_sweep"
file mkdir $report_dir

open_project $project_path
set_param general.maxThreads 8

set pll_ips [get_ips pll]
if {[llength $pll_ips] != 1} {
    puts "CLK2_ERROR expected one pll IP, got [llength $pll_ips]"
    close_project
    exit 3
}

set pll_ip [lindex $pll_ips 0]
puts "CLK2_SET freq_mhz=$freq_mhz ip=$pll_ip"
set_property -dict [list CONFIG.CLKOUT2_REQUESTED_OUT_FREQ $freq_mhz] $pll_ip
generate_target all $pll_ip
export_ip_user_files -of_objects $pll_ip -no_script -sync -force
update_compile_order -fileset sources_1

set pll_synth_run [get_runs pll_synth_1]
if {[llength $pll_synth_run] > 0} {
    reset_run pll_synth_1
    launch_runs pll_synth_1 -jobs 8
    wait_on_run pll_synth_1
    set pll_status [get_property STATUS [get_runs pll_synth_1]]
    puts "CLK2_PLL_STATUS freq_mhz=$freq_mhz status=\"$pll_status\""
}

reset_run synth_1
reset_run impl_1
launch_runs impl_1 -to_step route_design -jobs 8
wait_on_run impl_1

set impl_status [get_property STATUS [get_runs impl_1]]
puts "CLK2_IMPL_STATUS freq_mhz=$freq_mhz status=\"$impl_status\""

if {![regexp -nocase {complete} $impl_status]} {
    close_project
    exit 2
}

open_run impl_1

set timing_summary "$report_dir/top_timing_summary_clk2_${tag}.rpt"
report_timing_summary -delay_type min_max -max_paths 80 -nworst 10 -file $timing_summary
report_timing -delay_type max -sort_by group -max_paths 20 -nworst 5 \
    -path_type full_clock_expanded \
    -file "$report_dir/top_timing_max_clk2_${tag}.rpt"
report_timing -delay_type min -sort_by group -max_paths 20 -nworst 5 \
    -path_type full_clock_expanded \
    -file "$report_dir/top_timing_min_clk2_${tag}.rpt"
report_route_status -file "$report_dir/top_route_status_clk2_${tag}.rpt"

set setup_paths [get_timing_paths -delay_type max -max_paths 1]
if {[llength $setup_paths] > 0} {
    set wns [get_property SLACK [lindex $setup_paths 0]]
} else {
    set wns "NA"
}

set hold_paths [get_timing_paths -delay_type min -max_paths 1]
if {[llength $hold_paths] > 0} {
    set whs [get_property SLACK [lindex $hold_paths 0]]
} else {
    set whs "NA"
}

set period_ns "NA"
set actual_mhz "NA"
set clk2 [get_clocks clk_out2_pll]
if {[llength $clk2] > 0} {
    set period_ns [get_property PERIOD [lindex $clk2 0]]
    set actual_mhz [format "%.6f" [expr {1000.0 / $period_ns}]]
}

set timing_met 0
if {$wns ne "NA" && $whs ne "NA"} {
    if {[expr {$wns >= 0.0}] && [expr {$whs >= 0.0}]} {
        set timing_met 1
    }
}

puts "CLK2_RESULT freq_mhz=$freq_mhz actual_mhz=$actual_mhz period_ns=$period_ns status=\"$impl_status\" wns=$wns whs=$whs timing_met=$timing_met report=$timing_summary"

close_project
exit 0
