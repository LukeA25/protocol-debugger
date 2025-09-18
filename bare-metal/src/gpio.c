#include "../include/gpio.h"
#include <stdint.h>

#define RESETS_RESET         (*(volatile uint32_t *) (0x4000c000))
#define RESETS_RESET_DONE    (*(volatile uint32_t *) (0x4000c008))
#define IO_BANK0_BASE        ((volatile uint32_t *)0x40014000)
#define SIO_GPIO_OE_SET      (*(volatile uint32_t *) (0xd0000024))
#define SIO_GPIO_OUT_XOR     (*(volatile uint32_t *) (0xd000001c))
#define SIO_GPIO_IN          (*(volatile uint32_t *) (0xd0000004))

void gpio_init(const gpio_config_t* configs, int count) {
    // Bring IO_BANK0 out of reset state
    RESETS_RESET &= ~(1 << 5);
    while (!(RESETS_RESET_DONE & (1 << 5)));

    for (int i = 0; i < count; i++) {
        IO_BANK0_BASE[1 + (2 * configs[i].pin)] = 5;
        
        if (configs[i].is_output) {
            SIO_GPIO_OE_SET |= 1 << configs[i].pin;
        }
    }
}

void gpio_toggle(int gpio) {
    SIO_GPIO_OUT_XOR = (1 << gpio);
}

void gpio_wait_for_press(int gpio) {
    int found = 0;
    while (!found) {
        found = SIO_GPIO_IN & (1 << gpio);
    }
}
