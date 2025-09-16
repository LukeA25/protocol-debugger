.section .text.boot
.global _start

_start:
    // Set up stack
    ldr r0, =_stack_top
    mov sp, r0

    // Zero out .bss
    ldr r0, =_bss_start
    ldr r1, =_bss_end
    movs r2, #0

bss_clear:
    cmp r0, r1
    bcc store_zero
    b jump_to_main

store_zero:
    str r2, [r0]
    add r0, r0, #4
    b bss_clear

jump_to_main:
    bl main

halt:
    b halt
