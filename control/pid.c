#include "pid.h"
void pid_init(pid_t *p, float kp, float ki, float kd){ if(p){ p->kp=kp; p->ki=ki; p->kd=kd; p->integral=0.f; p->prev_err=0.f; } }
float pid_step(pid_t *p, float err, float dt){ (void)p; (void)err; (void)dt; return 0.f; }
