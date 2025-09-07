#ifndef DRIVER_ENCODER_H
#define DRIVER_ENCODER_H
int encoder_init(void);
int encoder_read(int channel, int *ticks);
#endif
