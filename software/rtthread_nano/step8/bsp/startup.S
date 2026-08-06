    .section .text.start, "ax", @progbits
    .globl _start
    .type _start, @function
    .option norvc

_start:
    .option push
    .option norelax
    la      gp, __global_pointer$
    .option pop

    la      sp, __stack_top

    /* The RTL simulation preloads .data/.rodata directly into DRAM. */
    la      t0, __bss_start
    la      t1, __bss_end
.Lbss_clear:
    bgeu    t0, t1, .Lbss_done
    sw      zero, 0(t0)
    addi    t0, t0, 4
    j       .Lbss_clear

.Lbss_done:
    /* components.c owns the formal RT-Thread startup sequence. */
    call    entry

.Lhalt:
    j       .Lhalt

    .size _start, . - _start
