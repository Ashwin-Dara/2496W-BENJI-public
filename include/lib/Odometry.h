#ifndef ODOM_H_
#define ODOM_H_

#include "main.h"
#include "../include/lib/Config.h"
#include "../include/lib/PID.h"
#include "../include/lib/MAFilter.h"
#include "../include/lib/Point.h"

#define ODOM_ITERATE_DELAY 20
#define RADIAN_TO_DEG 57.295780f
#define HEADING_KP 1.3f
#define HEADING_KI 0.12f
#define HEADING_KD 0.0f
#define HEADING_SR 1.4f
#define HEADING_IB 25
#define ODOM_LIN_KP 2.8f
#define ODOM_LIN_KI 0.4f
#define ODOM_LIN_KD 0.01f
#define ODOM_LIN_SR 2.0f 
#define ODOM_BIAS 0.3f
#define ODOM_BIAS_CAP 3.8f 

extern std::shared_ptr<Rotation> odom_right; 
extern std::shared_ptr<Rotation> odom_left; 

class Point; 

class Odometry {
    private: 
        int x_coord, y_coord;
        float prev_theta, theta, d_theta; 
        float prev_s, s, d_s; 
        bool run_odom_task; 

    public: 
        Odometry();
        void begin_tracking(); 
        void stop_tracking(); 
        int get_X_pos() const; 
        int get_Y_pos() const;  

};

void drive_to_point(const Odometry &odom, Point &coord, int max_velocity = 110, int ms = 7000); 


#endif
