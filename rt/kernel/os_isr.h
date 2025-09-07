#ifndef OS_ISR_H
#define OS_ISR_H
typedef void (*isr_fn_t)(void);
void os_isr_init(void);
int os_isr_attach(int irq, isr_fn_t fn);
int os_isr_detach(int irq);
#endif
