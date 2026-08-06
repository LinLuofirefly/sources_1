#include <stdint.h>
#include <rtthread.h>

#include "board.h"

#define STEP8_PASS_SEG   0x38000000u
#define STEP8_PASS_LED   0x4e414e38u
#define STEP8_FAIL_LED   0xe8000000u

extern void rt_hw_trap_entry(void);

static void disable_interrupts(void)
{
    uintptr_t mask = BSP_MSTATUS_MIE;

    __asm__ volatile ("csrc mstatus, %0" :: "r"(mask) : "memory");
}
void rt_hw_board_init(void)
{
    uintptr_t trap = (uintptr_t)&rt_hw_trap_entry;

    __asm__ volatile ("csrw mtvec, %0" :: "r"(trap) : "memory");
    bsp_timer_init();
    rt_kprintf("[bsp] board initialized\n");
}

void bsp_fatal(uint32_t stage, const char *message)
{
    uint32_t code = STEP8_FAIL_LED | (stage & 0xffu);

    disable_interrupts();
    bsp_timer_stop();
    rt_kprintf("[fatal] stage=%x: %s\n", stage, message);
    bsp_uart_flush();
    BSP_MMIO32(BSP_SEG_ADDR) = code;
    BSP_MMIO32(BSP_LED_ADDR) = code;

    for (;;)
    {
        __asm__ volatile ("" ::: "memory");
    }
}

void bsp_pass(void)
{
    disable_interrupts();
    bsp_timer_stop();
    bsp_uart_flush();
    BSP_MMIO32(BSP_SEG_ADDR) = STEP8_PASS_SEG;
    BSP_MMIO32(BSP_LED_ADDR) = STEP8_PASS_LED;

    for (;;)
    {
        __asm__ volatile ("" ::: "memory");
    }
}
