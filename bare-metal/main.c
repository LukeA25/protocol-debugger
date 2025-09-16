#include <stdint.h>

#define IO_BANK0_BASE 0x40014000
#define GPIO_25_CTRL 0x0cc

#define GPIO25_CTRL_REG  (*(volatile uint32_t*)(IO_BANK0_BASE + GPIO_25_CTRL))

#define SIO_BASE 0xd0000000
#define GPIO_OUT_XOR 0x01c
#define GPIO_OE 0x020

#define GPIO_OUT_XOR_REG (*(volatile uint32_t*)(SIO_BASE + GPIO_OUT_XOR))
#define GPIO_OE_REG (*(volatile uint32_t*)(SIO_BASE + GPIO_OE))

int main() {
    GPIO25_CTRL_REG = 5;
    GPIO_OE_REG |= (1 << 25);

    for (;;) {
        GPIO_OUT_XOR_REG = (1 << 25);
        for (volatile int i = 0; i < 100000; ++i);
    }

    return 0;
}
