#ifndef SENSORS_ENCODER_DRIVER_H
#define SENSORS_ENCODER_DRIVER_H
int encoder_driver_init(void);
int encoder_driver_read(int channel, int *ticks);
#endif
