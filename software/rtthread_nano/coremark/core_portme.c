#include <stdarg.h>

#include <rtthread.h>

#include "board.h"
#include "coremark.h"

volatile ee_s32 seed1_volatile = 0;
volatile ee_s32 seed2_volatile = 0;
volatile ee_s32 seed3_volatile = 0x66;
volatile ee_s32 seed4_volatile = ITERATIONS;
volatile ee_s32 seed5_volatile = 0;

ee_u32 default_num_contexts = 1;

static CORE_TICKS start_ticks;
static CORE_TICKS stop_ticks;

void start_time(void)
{
    start_ticks = (CORE_TICKS)bsp_timer_interrupt_count;
}

void stop_time(void)
{
    stop_ticks = (CORE_TICKS)bsp_timer_interrupt_count;
}

CORE_TICKS get_time(void)
{
    return stop_ticks - start_ticks;
}

secs_ret time_in_secs(CORE_TICKS ticks)
{
    return (secs_ret)(ticks / RT_TICK_PER_SECOND);
}

int ee_printf(const char *format, ...)
{
    char buffer[256];
    va_list arguments;
    int length;

    va_start(arguments, format);
    length = rt_vsnprintf(buffer, sizeof(buffer), format, arguments);
    va_end(arguments);

    rt_kprintf("%s", buffer);
    return length;
}

void portable_init(core_portable *portable, int *argc, char *argv[])
{
    (void)argc;
    (void)argv;

    if ((sizeof(ee_ptr_int) != sizeof(void *)) ||
        (sizeof(ee_u32) != 4u) || (sizeof(ee_s16) != 2u))
    {
        bsp_fatal(0x40u, "CoreMark data types");
    }

    portable->portable_id = 1u;
    rt_kprintf("[coremark] RV32IM single-context performance run\n");
}

void portable_fini(core_portable *portable)
{
    portable->portable_id = 0u;
}
