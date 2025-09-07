#ifndef DRIVER_CAMERA_H
#define DRIVER_CAMERA_H
int camera_init(void);
int camera_capture(void *frame, int maxlen);
#endif
