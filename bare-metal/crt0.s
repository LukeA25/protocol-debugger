.cpu cortex-m0plus
.thumb

.section .vectors, "ax"
.align 2
.global _vectors
_vectors:
    .word 0x20001000      /* Initial SP */
    .word _start          /* Reset handler */

.thumb_func
.global _start
_start:
    ldr r0, =0x20001000
    mov sp, r0

    .extern main
    bl main

hang:
    b hang
.align 4
