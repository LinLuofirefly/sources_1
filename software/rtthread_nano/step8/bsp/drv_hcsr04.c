#include <stdint.h>

#include <rtthread.h>

#include "board.h"
#include "drv_hcsr04.h"

#define HCSR04_CTRL_START       (1u << 0)
#define HCSR04_CTRL_CLEAR       (1u << 1)
#define HCSR04_STATUS_DONE      (1u << 1)
#define HCSR04_STATUS_TIMEOUT   (1u << 2)
#define HCSR04_POLL_DELAY_MS    10
#define HCSR04_MAX_POLLS        6u

rt_err_t bsp_hcsr04_measure(uint32_t *echo_us, uint32_t *distance_mm)
{
    uint32_t status = 0u;
    uint32_t pulse_us;
    unsigned int poll;

    if ((echo_us == RT_NULL) || (distance_mm == RT_NULL))
    {
        return -RT_EINVAL;
    }

    BSP_MMIO32(BSP_HCSR04_CTRL_ADDR) = HCSR04_CTRL_CLEAR;
    BSP_MMIO32(BSP_HCSR04_CTRL_ADDR) = HCSR04_CTRL_START;

    for (poll = 0u; poll < HCSR04_MAX_POLLS; poll++)
    {
        status = BSP_MMIO32(BSP_HCSR04_STATUS_ADDR);
        if ((status & HCSR04_STATUS_DONE) != 0u)
        {
            break;
        }
        rt_thread_mdelay(HCSR04_POLL_DELAY_MS);
    }

    if (((status & HCSR04_STATUS_DONE) == 0u) ||
        ((status & HCSR04_STATUS_TIMEOUT) != 0u))
    {
        return -RT_ETIMEOUT;
    }

    pulse_us = BSP_MMIO32(BSP_HCSR04_ECHO_US_ADDR);
    *echo_us = pulse_us;
    *distance_mm = (pulse_us * 343u + 1000u) / 2000u;
    return RT_EOK;
}
