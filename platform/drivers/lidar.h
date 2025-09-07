#ifndef DRIVER_LIDAR_H
#define DRIVER_LIDAR_H
int lidar_init(void);
int lidar_read(float *ranges, int max_beams);
#endif
