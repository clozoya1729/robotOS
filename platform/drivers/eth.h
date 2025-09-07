#ifndef DRIVER_ETH_H
#define DRIVER_ETH_H
int eth_init(void);
int eth_send(const void *buf, int len);
int eth_recv(void *buf, int maxlen);
#endif
