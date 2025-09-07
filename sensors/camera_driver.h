#ifndef SENSORS_CAMERA_DRIVER_H
#define SENSORS_CAMERA_DRIVER_H
int camera_driver_init(void);
int camera_driver_capture(void *frame, int maxlen);
#endif
