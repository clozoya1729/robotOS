#include "can.h"
int can_init(void){ return 0; }
int can_send(const can_frame_t *f){ (void)f; return 0; }
int can_recv(can_frame_t *f){ (void)f; return 0; }
