#ifndef COMMS_ETH_STACK_H
#define COMMS_ETH_STACK_H
int eth_stack_init(void);
int eth_stack_send(const void *buf, int len);
int eth_stack_recv(void *buf, int maxlen);
#endif
