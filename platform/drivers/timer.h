#ifndef DRIVER_TIMER_H
#define DRIVER_TIMER_H
int timer_init(void);
unsigned timer_now_ms(void);
int timer_schedule(unsigned delay_ms);
#endif
