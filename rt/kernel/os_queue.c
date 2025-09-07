#include "os_queue.h"
struct os_queue { int dummy; };
int os_queue_init(os_queue_t **q, size_t elem_size, size_t capacity){ (void)q; (void)elem_size; (void)capacity; return 0; }
int os_queue_send(os_queue_t *q, const void *item, unsigned timeout_ms){ (void)q; (void)item; (void)timeout_ms; return 0; }
int os_queue_recv(os_queue_t *q, void *item, unsigned timeout_ms){ (void)q; (void)item; (void)timeout_ms; return 0; }
