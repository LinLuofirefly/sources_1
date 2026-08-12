#include <stdint.h>

#include <rtthread.h>

#include "board.h"
#include "drv_hcsr04.h"

#define COREMARK_LED_RUNNING 0x434d0001u
#define SHELL_LINE_SIZE       32u

extern int coremark_entry(void);

static int string_equal(const char *left, const char *right)
{
    while ((*left != '\0') && (*left == *right))
    {
        left++;
        right++;
    }

    return *left == *right;
}

static void print_help(void)
{
    rt_kprintf("RT-Thread shell commands:\n");
    rt_kprintf("coremark         - Run CoreMark and print CRC results.\n");
    rt_kprintf("distance         - Measure once with the HC-SR04 sensor.\n");
    rt_kprintf("help             - RT-Thread shell help.\n");
}

static void run_coremark(void)
{
    int result;

    BSP_MMIO32(BSP_LED_ADDR) = COREMARK_LED_RUNNING;
    rt_kprintf("[coremark] RT-Thread hardware run start\n");
    rt_kprintf("[coremark] timing source: independent hardware millisecond counter\n");

    result = coremark_entry();
    if (result != 0)
    {
        rt_kprintf("[coremark] entry returned %d\n", result);
    }

    BSP_MMIO32(BSP_LED_ADDR) = 0u;
    rt_kprintf("[coremark] run complete; LED off\n");
}

static void run_distance(void)
{
    uint32_t echo_us;
    uint32_t distance_mm;
    rt_err_t result;

    rt_kprintf("[distance] HC-SR04 measurement start\n");
    result = bsp_hcsr04_measure(&echo_us, &distance_mm);
    if (result != RT_EOK)
    {
        rt_kprintf("[distance] timeout or no echo\n");
        return;
    }

    rt_kprintf("[distance] echo time: %u us\n", echo_us);
    rt_kprintf("[distance] distance: %u mm\n", distance_mm);
}

static unsigned int read_command(char *line, unsigned int capacity)
{
    unsigned int length = 0u;

    for (;;)
    {
        int value = bsp_uart_getchar_nonblocking();

        if (value < 0)
        {
            __asm__ volatile ("" ::: "memory");
            continue;
        }

        if ((value == '\r') || (value == '\n'))
        {
            rt_kprintf("\n");
            line[length] = '\0';
            return length;
        }

        if ((value == 8) || (value == 127))
        {
            if (length != 0u)
            {
                length--;
                rt_kprintf("\b \b");
            }
            continue;
        }

        if ((value >= 32) && (value <= 126) &&
            (length + 1u < capacity))
        {
            line[length++] = (char)value;
            rt_kprintf("%c", value);
        }
    }
}

int main(void)
{
    char command[SHELL_LINE_SIZE];

    rt_kprintf("[app] RT-Thread Nano ready\n");
    rt_kprintf("[app] CoreMark and HC-SR04 shell ready\n");

    for (;;)
    {
        rt_kprintf("msh >");
        if (read_command(command, sizeof(command)) == 0u)
        {
            continue;
        }

        if (string_equal(command, "help"))
        {
            print_help();
        }
        else if (string_equal(command, "coremark"))
        {
            run_coremark();
        }
        else if (string_equal(command, "distance"))
        {
            run_distance();
        }
        else
        {
            rt_kprintf("Unknown command: %s\n", command);
            rt_kprintf("Type 'help' for commands.\n");
        }
    }
}
