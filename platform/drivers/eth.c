#include "eth.h"
int eth_init(void){ return 0; }
int eth_send(const void *buf, int len){ (void)buf; (void)len; return 0; }
int eth_recv(void *buf, int maxlen){ (void)buf; (void)maxlen; return 0; }
