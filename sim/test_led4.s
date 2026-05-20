    .section .text
    .globl _start

_start:
    lui   sp, 0x80120
    addi  sp, sp, 0x700

    li    a0, 0x37800000
    jal   ra, write_seg

    li    a0, 0x00020101
    jal   ra, write_led

    jal   ra, write_stop_value_pass

    jal   ra, read_stop_value

    li    t0, 0xffffffff
    bne   a0, t0, fail_read_80200050

    jal   ra, append_seg_bcd

    li    a0, 0x048A7121
    jal   ra, write_led

pass_loop:
    jal   zero, pass_loop

fail:
    jal   ra, write_led
fail_loop:
    jal   zero, fail_loop

write_stop_value_pass:
    addi  sp, sp, -16
    sw    ra, 12(sp)
    lui   t0, 0x80200
    addi  t0, t0, 0x50
    li    t1, 0xffffffff
    sw    t1, 0(t0)
    lw    ra, 12(sp)
    addi  sp, sp, 16
    jalr  zero, 0(ra)

read_stop_value:
    addi  sp, sp, -16
    sw    ra, 12(sp)
    lui   t0, 0x80200
    addi  t0, t0, 0x50
    lw    a0, 0(t0)
    lw    ra, 12(sp)
    addi  sp, sp, 16
    jalr  zero, 0(ra)

append_seg_bcd:
    addi  sp, sp, -16
    sw    ra, 12(sp)
    jal   ra, bcd_convert_u32
    li    t0, 0x000fffff
    and   t1, a0, t0
    li    t2, 0x00067295
    bne   t1, t2, fail_bcd_value
    lui   t3, 0x80200
    addi  t3, t3, 0x20
    lw    t4, 0(t3)
    li    t5, 0x37800000
    bne   t4, t5, fail_read_old_seg
    or    t4, t4, t1
    li    t5, 0x37867295
    bne   t4, t5, fail_or_seg
    sw    t4, 0(t3)
    lw    ra, 12(sp)
    addi  sp, sp, 16
    jalr  zero, 0(ra)

bcd_convert_u32:
    addi  sp, sp, -32
    sw    ra, 28(sp)
    sw    s0, 24(sp)
    sw    s1, 20(sp)
    sw    s2, 16(sp)
    mv    s0, a0
    li    s1, 0
    li    s2, 0
bcd_loop:
    beqz  s0, bcd_done
    li    t0, 0xcccccccd
    mulhu t1, s0, t0
    srli  t1, t1, 3
    slli  t2, t1, 2
    add   t2, t2, t1
    slli  t2, t2, 1
    sub   t3, s0, t2
    sll   t3, t3, s2
    or    s1, s1, t3
    mv    s0, t1
    addi  s2, s2, 4
    jal   zero, bcd_loop
bcd_done:
    mv    a0, s1
    lw    ra, 28(sp)
    lw    s0, 24(sp)
    lw    s1, 20(sp)
    lw    s2, 16(sp)
    addi  sp, sp, 32
    jalr  zero, 0(ra)

write_led:
    lui   t0, 0x80200
    addi  t0, t0, 0x40
    sw    a0, 0(t0)
    jalr  zero, 0(ra)

write_seg:
    lui   t0, 0x80200
    addi  t0, t0, 0x20
    sw    a0, 0(t0)
    jalr  zero, 0(ra)

fail_read_80200050:
    li    a0, 0xE2000050
    jal   zero, fail

fail_bcd_value:
    li    a0, 0xE3006729
    jal   zero, fail

fail_read_old_seg:
    li    a0, 0xE4000020
    jal   zero, fail

fail_or_seg:
    li    a0, 0xE5000005
    jal   zero, fail
