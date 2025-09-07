#ifndef DRIVER_I2C_H
#define DRIVER_I2C_H
#include <stdint.h>
int i2c_init(void);
int i2c_read(uint8_t addr, void *buf, int len);
int i2c_write(uint8_t addr, const void *buf, int len);
#endif
