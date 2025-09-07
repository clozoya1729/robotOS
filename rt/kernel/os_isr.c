#include "os_isr.h"
void os_isr_init(void){}
int os_isr_attach(int irq, isr_fn_t fn){ (void)irq; (void)fn; return 0; }
int os_isr_detach(int irq){ (void)irq; return 0; }
