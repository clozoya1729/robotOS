#ifndef PERCEPTION_OCCUPANCY_H
#define PERCEPTION_OCCUPANCY_H
int occupancy_init(int width, int height, float resolution);
int occupancy_update_from_lidar(const float *ranges, int beams);
#endif
