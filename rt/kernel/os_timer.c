#include "os_timer.h"
void os_timer_init(void){}
int os_timer_start(os_timer_cb_t cb, void *arg, unsigned period_ms, int periodic){ (void)cb; (void)arg; (void)period_ms; (void)periodic; return 0; }
int os_timer_stop(int id){ (void)id; return 0; }
