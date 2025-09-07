#include <stdint.h>
#include "i2c.h"
int i2c_init(void){ return 0; }
int i2c_read(uint8_t addr, void *buf, int len){ (void)addr; (void)buf; (void)len; return 0; }
int i2c_write(uint8_t addr, const void *buf, int len){ (void)addr; (void)buf; (void)len; return 0; }
