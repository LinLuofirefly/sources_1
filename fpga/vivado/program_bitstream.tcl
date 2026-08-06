# Program one connected xc7k325t device with a generated .bit file.

proc program_fail {message {code 2}} {
    puts stderr "FPGA_PROGRAM_ERROR: $message"
    catch {close_hw_target}
    catch {disconnect_hw_server}
    catch {close_hw_manager}
    exit $code
}

set bit_file {}
set device_index 0
set index 0
while {$index < [llength $argv]} {
    set key [lindex $argv $index]
    switch -- $key {
        -bit - -device_index {
            incr index
            if {$index >= [llength $argv]} {
                program_fail "missing value after $key"
            }
            if {$key eq {-bit}} {
                set bit_file [lindex $argv $index]
            } else {
                set device_index [lindex $argv $index]
            }
        }
        default {
            program_fail "unknown option '$key'"
        }
    }
    incr index
}

if {$bit_file eq {}} {
    program_fail {usage: program_bitstream.tcl -bit FILE ?-device_index N?}
}
set bit_file [file normalize $bit_file]
if {![file isfile $bit_file]} {
    program_fail "bitstream not found: $bit_file"
}
if {![string is integer -strict $device_index] || $device_index < 0} {
    program_fail "invalid device index '$device_index'"
}

open_hw_manager
connect_hw_server -allow_non_jtag
open_hw_target
set devices [get_hw_devices -quiet -filter {PART =~ "xc7k325t*"}]
if {$device_index >= [llength $devices]} {
    program_fail "requested device index $device_index, but found [llength $devices] xc7k325t device(s)"
}
set device [lindex $devices $device_index]
current_hw_device $device
refresh_hw_device $device
set_property PROGRAM.FILE $bit_file $device
program_hw_devices $device
puts "FPGA_PROGRAM_RESULT: programmed [get_property PART $device] with $bit_file"
close_hw_target
disconnect_hw_server
close_hw_manager
exit 0
