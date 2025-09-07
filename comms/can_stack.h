#ifndef COMMS_CAN_STACK_H
#define COMMS_CAN_STACK_H
#include "platform/drivers/can.h"
int can_stack_init(void);
int can_stack_send(const can_frame_t *f);
int can_stack_recv(can_frame_t *f);
#endif
