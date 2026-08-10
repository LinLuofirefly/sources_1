#ifndef STEP8_BOARD_H
#define STEP8_BOARD_H

#include <stdint.h>

#define BSP_MMIO32(addr) (*(volatile uint32_t *)(uintptr_t)(addr))

#define BSP_SEG_ADDR             0x80200020u
#define BSP_LED_ADDR             0x80200040u
#define BSP_COUNTER_ADDR         0x80200050u
#define BSP_COUNTER_START_CMD    0x80000000u
#define BSP_COUNTER_STOP_CMD     0xffffffffu
#define BSP_MTIMER_PERIOD_ADDR   0x80200060u
#define BSP_MTIMER_CTRL_ADDR     0x80200064u
#define BSP_MTIMER_ACK_ADDR      0x80200068u
#define BSP_UART_DATA_ADDR       0x80200070u
#define BSP_UART_STATUS_ADDR     0x80200074u
#define BSP_UART_RX_DATA_ADDR    0x80200078u
#define BSP_UART_RX_STATUS_ADDR  0x8020007cu

#ifndef BSP_TIMER_PERIOD_CYCLES
#define BSP_TIMER_PERIOD_CYCLES  2048u
#endif
#define BSP_MSTATUS_MIE          (1u << 3)
#define BSP_MIE_MTIE             (1u << 7)
#define BSP_MCAUSE_MTIMER        0x80000007u

extern volatile uint32_t bsp_timer_interrupt_count;
extern volatile uint32_t interrupt_switch_count;

void bsp_timer_init(void);
void bsp_timer_stop(void);
void bsp_uart_flush(void);
int bsp_uart_getchar_nonblocking(void);

void bsp_fatal(uint32_t stage, const char *message)
    __attribute__((noreturn));
void bsp_pass(void) __attribute__((noreturn));

#endif
