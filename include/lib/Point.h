#ifndef POINT_H_
#define POINT_H_

#include "main.h"
#include "../include/lib/Odometry.h"

class Odometry; 

class Point{
    private: 
        int desired_x, desired_y, current_x, current_y; 

    public: 
        Point(int current_x = 0, int current_y = 0);
        void set_current_point(const Odometry &odom); 
        void set_req_point(int x, int y);
        float point_distance(); 
        int get_heading(); 
};

#endif