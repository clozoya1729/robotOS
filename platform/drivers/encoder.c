#include "encoder.h"
int encoder_init(void){ return 0; }
int encoder_read(int channel, int *ticks){ (void)channel; if(ticks) *ticks=0; return 0; }
