#ifndef COMMS_SERIAL_PROTO_H
#define COMMS_SERIAL_PROTO_H
int serial_proto_init(void);
int serial_proto_send(const void *buf, int len);
int serial_proto_recv(void *buf, int maxlen);
#endif
