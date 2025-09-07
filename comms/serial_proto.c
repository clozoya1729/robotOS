#include "serial_proto.h"
int serial_proto_init(void){ return 0; }
int serial_proto_send(const void *buf, int len){ (void)buf; (void)len; return 0; }
int serial_proto_recv(void *buf, int maxlen){ (void)buf; (void)maxlen; return 0; }
