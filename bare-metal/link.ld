ENTRY(_start)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x10000000, LENGTH = 2M
  RAM   (rwx): ORIGIN = 0x20000000, LENGTH = 256K
}

SECTIONS
{
  .text : {
    *(.text.boot)   /* startup code */
    *(.text*)       /* all other code */
  } > FLASH

  .rodata : {
    *(.rodata*)
  } > FLASH

  .data : {
    _data_start = .;
    *(.data*)
    _data_end = .;
  } > RAM AT > FLASH

  .bss : {
    _bss_start = .;
    *(.bss*)
    *(COMMON)
    _bss_end = .;
  } > RAM

  .stack (NOLOAD) : {
    . = ALIGN(8);
    _stack_top = . + 0x1000;
  } > RAM
}
