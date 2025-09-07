#ifndef KIN_DYNAMICS_H
#define KIN_DYNAMICS_H
int dynamics_compute(const float *q, const float *qd, const float *qdd, int dof, float *tau_out);
#endif
