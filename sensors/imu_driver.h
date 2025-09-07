#ifndef SENSORS_IMU_DRIVER_H
#define SENSORS_IMU_DRIVER_H
int imu_driver_init(void);
int imu_driver_read(float *accel3, float *gyro3, float *mag3);
#endif
