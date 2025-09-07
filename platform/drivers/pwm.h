#ifndef DRIVER_PWM_H
#define DRIVER_PWM_H
int pwm_init(void);
int pwm_set_duty(int channel, float duty);
#endif
