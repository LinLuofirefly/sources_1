set project_path "C:/Users/hp/Downloads/digital_twin/digital_twin.xpr"
set freq_mhz "223"

if {[llength $argv] >= 1} {
    set project_path [lindex $argv 0]
}
if {[llength $argv] >= 2} {
    set freq_mhz [lindex $argv 1]
}

open_project $project_path

set pll_ips [get_ips pll]
if {[llength $pll_ips] != 1} {
    puts "CLK2_SET_ONLY_ERROR expected one pll IP, got [llength $pll_ips]"
    close_project
    exit 3
}

set pll_ip [lindex $pll_ips 0]
puts "CLK2_SET_ONLY freq_mhz=$freq_mhz ip=$pll_ip"
set_property -dict [list CONFIG.CLKOUT2_REQUESTED_OUT_FREQ $freq_mhz] $pll_ip
generate_target all $pll_ip
export_ip_user_files -of_objects $pll_ip -no_script -sync -force
update_compile_order -fileset sources_1
close_project
exit 0
