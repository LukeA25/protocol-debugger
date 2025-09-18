MEMORY {
    FLASH(rx) : ORIGIN = 0x10000000, LENGTH = 2M
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

SECTIONS {
    .text : {
        *(.vectors)
        *(.text*)
        *(.rodata*)
    } > FLASH

    .data : {
        *(.data*)
    } > SRAM AT > FLASH

    .bss : {
        *(.bss*)
        *(COMMON)
    } > SRAM
}
