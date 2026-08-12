#ifndef BSP_DRV_HCSR04_H
#define BSP_DRV_HCSR04_H

#include <stdint.h>

#include <rtthread.h>

rt_err_t bsp_hcsr04_measure(uint32_t *echo_us, uint32_t *distance_mm);

#endif
