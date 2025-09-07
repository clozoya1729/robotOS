#ifndef DRIVER_UART_H
#define DRIVER_UART_H
int uart_init(void);
int uart_write(const char *s);
int uart_read(char *buf, int maxlen);
#endif
