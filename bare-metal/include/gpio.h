#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct {
    int pin;
    int is_output;
} gpio_config_t;

void gpio_init(const gpio_config_t* configs, int count);
void gpio_toggle(int gpio);
void gpio_wait_for_press(int gpio);

#endif
