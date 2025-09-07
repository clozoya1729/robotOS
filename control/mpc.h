#ifndef CONTROL_MPC_H
#define CONTROL_MPC_H
int mpc_init(void);
int mpc_solve(const float *x0, const float *xref, int nx, int nu, float *u_out);
#endif
