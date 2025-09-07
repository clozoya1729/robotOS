#ifndef KIN_INVERSE_H
#define KIN_INVERSE_H
int ik_solve(const float *pose_target, int dof, float *joint_angles_out);
#endif
