#ifndef CONTROL_PID_H
#define CONTROL_PID_H
typedef struct { float kp, ki, kd; float integral; float prev_err; } pid_t;
void pid_init(pid_t *p, float kp, float ki, float kd);
float pid_step(pid_t *p, float err, float dt);
#endif
