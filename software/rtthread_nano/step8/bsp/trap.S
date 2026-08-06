    .section .text.trap, "ax", @progbits
    .align 2
    .option norvc

    .globl rt_hw_trap_entry
    .type rt_hw_trap_entry, @function
rt_hw_trap_entry:
    /* Match the 32-word stack frame used by the RT-Thread RISC-V port. */
    addi sp, sp, -128

    sw   ra,   4(sp)
    sw   gp,  12(sp)
    sw   tp,  16(sp)
    sw   t0,  20(sp)
    sw   t1,  24(sp)
    sw   t2,  28(sp)
    sw   s0,  32(sp)
    sw   s1,  36(sp)
    sw   a0,  40(sp)
    sw   a1,  44(sp)
    sw   a2,  48(sp)
    sw   a3,  52(sp)
    sw   a4,  56(sp)
    sw   a5,  60(sp)
    sw   a6,  64(sp)
    sw   a7,  68(sp)
    sw   s2,  72(sp)
    sw   s3,  76(sp)
    sw   s4,  80(sp)
    sw   s5,  84(sp)
    sw   s6,  88(sp)
    sw   s7,  92(sp)
    sw   s8,  96(sp)
    sw   s9, 100(sp)
    sw   s10,104(sp)
    sw   s11,108(sp)
    sw   t3, 112(sp)
    sw   t4, 116(sp)
    sw   t5, 120(sp)
    sw   t6, 124(sp)

    csrr t0, mepc
    sw   t0, 0(sp)
    csrr t0, mstatus
    sw   t0, 8(sp)

    call rt_hw_timer_isr

    la   t0, rt_thread_switch_interrupt_flag
    lw   t1, 0(t0)
    beqz t1, .Ltrap_restore
    sw   zero, 0(t0)

    la   t0, rt_interrupt_from_thread
    lw   t1, 0(t0)
    sw   sp, 0(t1)

    la   t0, rt_interrupt_to_thread
    lw   t1, 0(t0)
    lw   sp, 0(t1)

    la   t0, interrupt_switch_count
    lw   t1, 0(t0)
    addi t1, t1, 1
    sw   t1, 0(t0)

.Ltrap_restore:
    lw   t0, 0(sp)
    csrw mepc, t0
    lw   t0, 8(sp)
    csrw mstatus, t0

    lw   ra,   4(sp)
    /* gp is process-global and is not restored from a new thread's frame. */
    lw   tp,  16(sp)
    lw   t1,  24(sp)
    lw   t2,  28(sp)
    lw   s0,  32(sp)
    lw   s1,  36(sp)
    lw   a0,  40(sp)
    lw   a1,  44(sp)
    lw   a2,  48(sp)
    lw   a3,  52(sp)
    lw   a4,  56(sp)
    lw   a5,  60(sp)
    lw   a6,  64(sp)
    lw   a7,  68(sp)
    lw   s2,  72(sp)
    lw   s3,  76(sp)
    lw   s4,  80(sp)
    lw   s5,  84(sp)
    lw   s6,  88(sp)
    lw   s7,  92(sp)
    lw   s8,  96(sp)
    lw   s9, 100(sp)
    lw   s10,104(sp)
    lw   s11,108(sp)
    lw   t3, 112(sp)
    lw   t4, 116(sp)
    lw   t5, 120(sp)
    lw   t6, 124(sp)
    lw   t0,  20(sp)

    addi sp, sp, 128
    mret

    .size rt_hw_trap_entry, . - rt_hw_trap_entry
