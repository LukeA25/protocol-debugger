.section .text.boot
.global _start
_start:
    // Set the stack pointer to top of RAM (for core 0)
    ldr sp, =_stack_top

    // Zero .bss section
    ldr r0, =_bss_start
    ldr r1, =_bss_end
    mov r2, #0
loop:
    cmp r0, r1
    ittt lt
    strlt r2, [r0], #4
    blt loop

    // Call main()
    bl main

    // If main returns, loop forever
hang:
    b hang
