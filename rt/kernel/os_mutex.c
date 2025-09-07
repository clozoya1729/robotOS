#include "os_mutex.h"
void os_mutex_init(os_mutex_t *m){ if(m) m->locked = 0; }
void os_mutex_lock(os_mutex_t *m){ (void)m; }
void os_mutex_unlock(os_mutex_t *m){ (void)m; }
