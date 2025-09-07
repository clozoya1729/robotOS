#ifndef OS_EVENT_H
#define OS_EVENT_H
#include <stdint.h>
typedef struct { volatile uint32_t flags; } os_event_t;
void os_event_init(os_event_t *e);
void os_event_set(os_event_t *e, uint32_t mask);
void os_event_clear(os_event_t *e, uint32_t mask);
uint32_t os_event_wait(os_event_t *e, uint32_t mask, uint32_t timeout_ms);
#endif
