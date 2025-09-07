#ifndef DRIVER_GPIO_H
#define DRIVER_GPIO_H
typedef enum { GPIO_INPUT, GPIO_OUTPUT } gpio_mode_t;
int gpio_mode(int pin, gpio_mode_t mode);
int gpio_write(int pin, int value);
int gpio_read(int pin);
#endif
