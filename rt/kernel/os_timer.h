#ifndef OS_TIMER_H
#define OS_TIMER_H
typedef void (*os_timer_cb_t)(void*);
void os_timer_init(void);
int os_timer_start(os_timer_cb_t cb, void *arg, unsigned period_ms, int periodic);
int os_timer_stop(int id);
#endif
