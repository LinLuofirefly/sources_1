OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
    IROM (rx)  : ORIGIN = 0x80000000, LENGTH = 16K
    DRAM (rwx) : ORIGIN = 0x80100000, LENGTH = 256K
}

SECTIONS
{
    .text : ALIGN(4)
    {
        KEEP(*(.text.start))
        KEEP(*(.text.trap))
        *(.text .text.*)
    } > IROM

    .rodata : ALIGN(4)
    {
        __rodata_start = .;
        *(.srodata .srodata.*)
        *(.rodata .rodata.*)
        __rodata_end = ALIGN(4);
        . = __rodata_end;
    } > DRAM

    .data : ALIGN(4)
    {
        __data_start = .;
        *(.sdata .sdata.*)
        *(.data .data.*)
        __data_end = ALIGN(4);
        . = __data_end;
    } > DRAM

    .bss (NOLOAD) : ALIGN(4)
    {
        __bss_start = .;
        *(.sbss .sbss.*)
        *(.bss .bss.*)
        *(COMMON)
        __bss_end = ALIGN(4);
        . = __bss_end;
    } > DRAM

    __heap_start = ALIGN(16);
    __stack_top = ORIGIN(DRAM) + LENGTH(DRAM) - 16;
    PROVIDE(__global_pointer$ = ORIGIN(DRAM) + 0x800);

    /DISCARD/ :
    {
        *(.comment)
        *(.note .note.*)
        *(.eh_frame .eh_frame.*)
        *(.riscv.attributes)
    }
}

ASSERT(SIZEOF(.text) <= LENGTH(IROM), "RT-Thread Nano IROM overflow")
ASSERT(__heap_start < __stack_top, "RT-Thread Nano DRAM overflow")
