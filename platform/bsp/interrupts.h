#ifndef INTERRUPTS_H
#define INTERRUPTS_H
void interrupts_init(void);
void enable_irq(int irq);
void disable_irq(int irq);
#endif
