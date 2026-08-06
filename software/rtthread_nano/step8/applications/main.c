#include <stdint.h>
#include <rtthread.h>

#include "board.h"

#define WORKER_STACK_SIZE  1536u
#define WORKER_PRIORITY    2u
#define WORKER_SLICE       5u

static struct rt_thread worker_thread;
static struct rt_semaphore worker_semaphore;
static uint8_t worker_stack[WORKER_STACK_SIZE] __attribute__((aligned(16)));
static const uint32_t worker_parameter = 0x53544550u;

static volatile uint32_t worker_waiting;
static volatile uint32_t worker_done;

static void worker_entry(void *parameter)
{
    if (parameter != (void *)&worker_parameter)
    {
        bsp_fatal(0x10u, "worker parameter");
    }

    rt_kprintf("[thread] worker started\n");
    worker_waiting = 1u;
    if (rt_sem_take(&worker_semaphore, RT_WAITING_FOREVER) != RT_EOK)
    {
        bsp_fatal(0x11u, "semaphore take");
    }

    worker_waiting = 0u;
    rt_kprintf("[thread] semaphore received\n");
    worker_done = 1u;

    for (;;)
    {
        if (rt_thread_mdelay(1000) != RT_EOK)
        {
            bsp_fatal(0x12u, "worker delay");
        }
    }
}

int main(void)
{
    rt_tick_t delay_start;

    rt_kprintf("[app] main thread started\n");

    if (rt_sem_init(&worker_semaphore, "work", 0u,
                    RT_IPC_FLAG_PRIO) != RT_EOK)
    {
        bsp_fatal(0x20u, "semaphore init");
    }
    if (rt_thread_init(&worker_thread, "worker", worker_entry,
                       (void *)&worker_parameter, worker_stack,
                       sizeof(worker_stack), WORKER_PRIORITY,
                       WORKER_SLICE) != RT_EOK)
    {
        bsp_fatal(0x21u, "worker init");
    }
    if (rt_thread_startup(&worker_thread) != RT_EOK)
    {
        bsp_fatal(0x22u, "worker startup");
    }
    if (worker_waiting != 1u)
    {
        bsp_fatal(0x23u, "worker did not block");
    }

    if (rt_sem_release(&worker_semaphore) != RT_EOK)
    {
        bsp_fatal(0x24u, "semaphore release");
    }
    if (worker_done != 1u)
    {
        bsp_fatal(0x25u, "worker did not preempt");
    }

    delay_start = rt_tick_get();
    if (rt_thread_mdelay(10) != RT_EOK)
    {
        bsp_fatal(0x26u, "main delay");
    }
    if (((rt_tick_get() - delay_start) != 1u) ||
        (bsp_timer_interrupt_count == 0u) ||
        (interrupt_switch_count == 0u))
    {
        bsp_fatal(0x27u, "timer scheduling");
    }

    rt_kprintf("[app] tick=%u traps=%u\n", (unsigned int)rt_tick_get(),
               (unsigned int)bsp_timer_interrupt_count);
    rt_kprintf("[app] RT-Thread Nano ready\n");
    bsp_uart_flush();
    bsp_pass();
}
