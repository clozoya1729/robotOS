#ifndef DRIVER_IMU_H
#define DRIVER_IMU_H
int imu_init(void);
int imu_read(float *accel3, float *gyro3, float *mag3);
#endif
