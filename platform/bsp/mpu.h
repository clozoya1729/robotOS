#ifndef MPU_H
#define MPU_H
int mpu_configure_region(unsigned idx, void *base, unsigned size, unsigned attr);
void mpu_enable(int enable);
#endif
