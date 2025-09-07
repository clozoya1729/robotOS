#include "encoder_driver.h"
int encoder_driver_init(void){ return 0; }
int encoder_driver_read(int channel, int *ticks){ (void)channel; if(ticks) *ticks=0; return 0; }
