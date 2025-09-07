#ifndef OS_MUTEX_H
#define OS_MUTEX_H
typedef struct { volatile int locked; } os_mutex_t;
void os_mutex_init(os_mutex_t *m);
void os_mutex_lock(os_mutex_t *m);
void os_mutex_unlock(os_mutex_t *m);
#endif
