#ifndef OS_TASK_H
#define OS_TASK_H
typedef void (*os_task_fn_t)(void*);
int os_task_create(os_task_fn_t fn, void *arg, unsigned prio, unsigned period_ms);
int os_task_delete(int id);
#endif
