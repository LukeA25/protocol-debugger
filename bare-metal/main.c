#include "include/gpio.h"

int main(void) {
    gpio_config_t configs[] = {
        {25, 1},
        {15, 0}
    };

    gpio_init(configs, 2);

    while (1) {
        for (int j = 0; j < 2; j++) {
            for (volatile uint32_t i = 0; i < 100000; ++i);
            gpio_toggle(25);
        }

        gpio_wait_for_press(16);
    }

    return 0;
}
