#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

#define RT_NAME_MAX                 8
#define RT_ALIGN_SIZE               4
#define RT_THREAD_PRIORITY_MAX      8
#define RT_TICK_PER_SECOND          100

#define RT_KSERVICE_USING_TINY_SIZE
#define RT_USING_TINY_FFS
#define RT_USING_USER_MAIN
#define RT_USING_CONSOLE
#define RT_USING_SEMAPHORE

#define RT_CONSOLEBUF_SIZE          128
#define RT_MAIN_THREAD_STACK_SIZE   2048
#define RT_MAIN_THREAD_PRIORITY     3
#define IDLE_THREAD_STACK_SIZE      2048

/* Heap, device framework and FinSH remain disabled in the Nano BSP. */

#endif
