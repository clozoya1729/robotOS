#ifndef OS_QUEUE_H
#define OS_QUEUE_H
#include <stddef.h>
typedef struct os_queue os_queue_t;
int os_queue_init(os_queue_t **q, size_t elem_size, size_t capacity);
int os_queue_send(os_queue_t *q, const void *item, unsigned timeout_ms);
int os_queue_recv(os_queue_t *q, void *item, unsigned timeout_ms);
#endif
