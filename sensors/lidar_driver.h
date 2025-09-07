#ifndef SENSORS_LIDAR_DRIVER_H
#define SENSORS_LIDAR_DRIVER_H
int lidar_driver_init(void);
int lidar_driver_scan(float *ranges, int max_beams);
#endif
