#include <stdint.h>

#include <rtthread.h>

#include "board.h"

#define COREMARK_LED_RUNNING 0x434d0001u

extern int coremark_entry(void);

int main(void)
{
    int result;

    BSP_MMIO32(BSP_LED_ADDR) = COREMARK_LED_RUNNING;
    rt_kprintf("[coremark] RT-Thread hardware run start\n");
    rt_kprintf("[coremark] timing source: 100 Hz machine-timer tick\n");

    result = coremark_entry();
    if (result != 0)
    {
        bsp_fatal(0x41u, "CoreMark return");
    }

    bsp_timer_stop();
    rt_kprintf("[coremark] run complete\n");
    bsp_uart_flush();
    BSP_MMIO32(BSP_LED_ADDR) = 0u;

    for (;;)
    {
        __asm__ volatile ("" ::: "memory");
    }
}
