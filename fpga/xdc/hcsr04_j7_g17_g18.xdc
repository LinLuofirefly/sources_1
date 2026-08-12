# HC-SR04 on the J7 Debug header.
#   J7-1 / Debug_1 / FPGA G17: TRIG output
#   J7-2 / Debug_2 / FPGA G18: ECHO input through a 5 V -> 3.3 V divider
# Bank 17 VADJ1 must be configured for 3.3 V before using LVCMOS33.

set_property PACKAGE_PIN G17 [get_ports hcsr04_trig]
set_property IOSTANDARD LVCMOS33 [get_ports hcsr04_trig]
set_property DRIVE 8 [get_ports hcsr04_trig]
set_property SLEW SLOW [get_ports hcsr04_trig]

set_property PACKAGE_PIN G18 [get_ports hcsr04_echo]
set_property IOSTANDARD LVCMOS33 [get_ports hcsr04_echo]
