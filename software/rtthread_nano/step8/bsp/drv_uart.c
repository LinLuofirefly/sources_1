#include <stdint.h>
#include <rthw.h>

#include "board.h"

static void uart_putc(char value)
{
    while ((BSP_MMIO32(BSP_UART_STATUS_ADDR) & 1u) == 0u)
    {
        __asm__ volatile ("" ::: "memory");
    }
    BSP_MMIO32(BSP_UART_DATA_ADDR) = (uint32_t)(uint8_t)value;
}
void rt_hw_console_output(const char *str)
{
    if (str == RT_NULL)
    {
        return;
    }

    while (*str != '\0')
    {
        if (*str == '\n')
        {
            uart_putc('\r');
        }
        uart_putc(*str++);
    }
}

void bsp_uart_flush(void)
{
    while ((BSP_MMIO32(BSP_UART_STATUS_ADDR) & 1u) == 0u)
    {
        __asm__ volatile ("" ::: "memory");
    }
}
