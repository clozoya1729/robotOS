#include "can_stack.h"
int can_stack_init(void){ return can_init(); }
int can_stack_send(const can_frame_t *f){ return can_send(f); }
int can_stack_recv(can_frame_t *f){ return can_recv(f); }
