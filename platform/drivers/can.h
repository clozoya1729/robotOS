#ifndef DRIVER_CAN_H
#define DRIVER_CAN_H
#include <stdint.h>
typedef struct { uint32_t id; uint8_t dlc; uint8_t data[64]; } can_frame_t;
int can_init(void);
int can_send(const can_frame_t *f);
int can_recv(can_frame_t *f);
#endif
