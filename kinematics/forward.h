#ifndef KIN_FORWARD_H
#define KIN_FORWARD_H
int fk_solve(const float *joint_angles, int dof, float *pose_out);
#endif
