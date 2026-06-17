set project_path "C:/Users/hp/Downloads/digital_twin/digital_twin.xpr"
if {[llength $argv] >= 1} {
    set project_path [lindex $argv 0]
}

set report_dir "C:/Users/hp/Downloads/digital_twin/digital_twin.srcs/sources_1/vivado_timing"
file mkdir $report_dir

open_project $project_path
set_param general.maxThreads 8

reset_run synth_1
reset_run impl_1
launch_runs impl_1 -to_step route_design -jobs 8
wait_on_run impl_1

set impl_status [get_property STATUS [get_runs impl_1]]
puts "IMPL_STATUS=$impl_status"

if {![regexp -nocase {complete} $impl_status]} {
    close_project
    exit 2
}

open_run impl_1

report_timing_summary -delay_type min_max -max_paths 80 -nworst 10 \
    -file "$report_dir/top_timing_summary_routed.rpt"
report_timing -delay_type max -sort_by group -max_paths 40 -nworst 5 \
    -path_type full_clock_expanded \
    -file "$report_dir/top_timing_max_paths.rpt"
report_timing -delay_type min -sort_by group -max_paths 20 -nworst 5 \
    -path_type full_clock_expanded \
    -file "$report_dir/top_timing_min_paths.rpt"
report_utilization -hierarchical -file "$report_dir/top_utilization_hier.rpt"
report_methodology -file "$report_dir/top_methodology.rpt"
report_route_status -file "$report_dir/top_route_status.rpt"

close_project
exit 0
