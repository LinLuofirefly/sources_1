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

static CORE_TICKS hardware_counter_read(void)
{
    return (CORE_TICKS)BSP_MMIO32(BSP_COUNTER_ADDR);
}

void start_time(void)
{
    /* The counter retains its value while stopped.  Snapshot that stable
     * baseline before enabling the independent hardware timer. */
    start_ticks = hardware_counter_read();
    BSP_MMIO32(BSP_COUNTER_ADDR) = BSP_COUNTER_START_CMD;
}

void stop_time(void)
{
    unsigned int index;

    BSP_MMIO32(BSP_COUNTER_ADDR) = BSP_COUNTER_STOP_CMD;

    /* Let the stop request and Gray-coded count cross both clock domains.
     * These reads happen after the stop command and are not part of the
     * measured interval. */
    for (index = 0u; index < 32u; index++)
    {
        stop_ticks = hardware_counter_read();
    }
}

CORE_TICKS get_time(void)
{
    return stop_ticks - start_ticks;
}

secs_ret time_in_secs(CORE_TICKS ticks)
{
    return (secs_ret)ticks / (secs_ret)COREMARK_COUNTER_HZ;
}

static void append_character(char *buffer, unsigned int capacity,
                             unsigned int *length, char value)
{
    if (*length + 1u < capacity)
    {
        buffer[*length] = value;
    }
    (*length)++;
}

static void append_string(char *buffer, unsigned int capacity,
                          unsigned int *length, const char *value)
{
    if (value == NULL)
    {
        value = "(NULL)";
    }
    while (*value != '\0')
    {
        append_character(buffer, capacity, length, *value++);
    }
}

static void append_unsigned(char *buffer, unsigned int capacity,
                            unsigned int *length, ee_u32 value,
                            unsigned int base, unsigned int width,
                            char padding)
{
    static const char digits[] = "0123456789abcdef";
    char reverse[16];
    unsigned int count = 0u;

    do
    {
        reverse[count++] = digits[value % base];
        value /= base;
    } while (value != 0u);

    while (count < width)
    {
        append_character(buffer, capacity, length, padding);
        width--;
    }
    while (count != 0u)
    {
        append_character(buffer, capacity, length, reverse[--count]);
    }
}

static void append_fixed6(char *buffer, unsigned int capacity,
                          unsigned int *length, double value)
{
    ee_u32 whole;
    ee_u32 fraction;

    if (value < 0.0)
    {
        append_character(buffer, capacity, length, '-');
        value = -value;
    }

    whole = (ee_u32)value;
    fraction = (ee_u32)(((value - (double)whole) * 1000000.0) + 0.5);
    if (fraction >= 1000000u)
    {
        whole++;
        fraction -= 1000000u;
    }

    append_unsigned(buffer, capacity, length, whole, 10u, 0u, ' ');
    append_character(buffer, capacity, length, '.');
    append_unsigned(buffer, capacity, length, fraction, 10u, 6u, '0');
}

int ee_printf(const char *format, ...)
{
    char buffer[256];
    va_list arguments;
    unsigned int length = 0u;

    va_start(arguments, format);
    while (*format != '\0')
    {
        unsigned int width = 0u;
        char padding = ' ';
        int long_argument = 0;

        if (*format != '%')
        {
            append_character(buffer, sizeof(buffer), &length, *format++);
            continue;
        }

        format++;
        if (*format == '%')
        {
            append_character(buffer, sizeof(buffer), &length, *format++);
            continue;
        }
        if (*format == '0')
        {
            padding = '0';
            format++;
        }
        while ((*format >= '0') && (*format <= '9'))
        {
            width = width * 10u + (unsigned int)(*format++ - '0');
        }
        if (*format == 'l')
        {
            long_argument = 1;
            format++;
        }

        switch (*format)
        {
            case 's':
                append_string(buffer, sizeof(buffer), &length,
                              va_arg(arguments, const char *));
                break;
            case 'c':
                append_character(buffer, sizeof(buffer), &length,
                                 (char)va_arg(arguments, int));
                break;
            case 'd':
            case 'i':
            {
                long signed_value = long_argument ?
                    va_arg(arguments, long) : (long)va_arg(arguments, int);
                ee_u32 magnitude;

                if (signed_value < 0)
                {
                    append_character(buffer, sizeof(buffer), &length, '-');
                    magnitude = (ee_u32)(-(signed_value + 1L)) + 1u;
                }
                else
                {
                    magnitude = (ee_u32)signed_value;
                }
                append_unsigned(buffer, sizeof(buffer), &length, magnitude,
                                10u, width, padding);
                break;
            }
            case 'u':
            {
                ee_u32 value = long_argument ?
                    (ee_u32)va_arg(arguments, unsigned long) :
                    va_arg(arguments, ee_u32);
                append_unsigned(buffer, sizeof(buffer), &length, value,
                                10u, width, padding);
                break;
            }
            case 'x':
            case 'X':
            {
                ee_u32 value = long_argument ?
                    (ee_u32)va_arg(arguments, unsigned long) :
                    va_arg(arguments, ee_u32);
                append_unsigned(buffer, sizeof(buffer), &length, value,
                                16u, width, padding);
                break;
            }
            case 'f':
                append_fixed6(buffer, sizeof(buffer), &length,
                              va_arg(arguments, double));
                break;
            default:
                append_character(buffer, sizeof(buffer), &length, '%');
                append_character(buffer, sizeof(buffer), &length, *format);
                break;
        }
        if (*format != '\0')
        {
            format++;
        }
    }
    va_end(arguments);

    if (length >= sizeof(buffer))
    {
        length = sizeof(buffer) - 1u;
    }
    buffer[length] = '\0';
    rt_kprintf("%s", buffer);
    return (int)length;
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
