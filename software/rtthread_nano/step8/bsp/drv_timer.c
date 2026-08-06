#include <stdint.h>
#include <rtthread.h>

#include "board.h"

volatile uint32_t bsp_timer_interrupt_count;
volatile uint32_t interrupt_switch_count;

void bsp_timer_init(void)
{
    uintptr_t mtie = BSP_MIE_MTIE;

    __asm__ volatile ("csrs mie, %0" :: "r"(mtie) : "memory");
    BSP_MMIO32(BSP_MTIMER_PERIOD_ADDR) = BSP_TIMER_PERIOD_CYCLES;
    BSP_MMIO32(BSP_MTIMER_ACK_ADDR) = 1u;
    BSP_MMIO32(BSP_MTIMER_CTRL_ADDR) = 1u;
}
void bsp_timer_stop(void)
{
    BSP_MMIO32(BSP_MTIMER_CTRL_ADDR) = 0u;
}

void rt_hw_timer_isr(void)
{
    uint32_t mcause;

    __asm__ volatile ("csrr %0, mcause" : "=r"(mcause));
    if (mcause != BSP_MCAUSE_MTIMER)
    {
        bsp_fatal(0x30u, "unexpected trap");
    }

    BSP_MMIO32(BSP_MTIMER_ACK_ADDR) = 1u;
    bsp_timer_interrupt_count++;
    rt_interrupt_enter();
    rt_tick_increase();
    rt_interrupt_leave();
}
