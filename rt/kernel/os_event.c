#include "os_event.h"
void os_event_init(os_event_t *e){ if(e) e->flags = 0u; }
void os_event_set(os_event_t *e, uint32_t mask){ if(e) e->flags |= mask; }
void os_event_clear(os_event_t *e, uint32_t mask){ if(e) e->flags &= ~mask; }
uint32_t os_event_wait(os_event_t *e, uint32_t mask, uint32_t timeout_ms){ (void)e; (void)mask; (void)timeout_ms; return 0u; }
