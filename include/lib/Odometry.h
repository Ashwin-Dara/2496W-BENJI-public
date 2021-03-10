#ifndef ODOM_H_
#define ODOM_H_

#include "main.h"
#include "../include/lib/Config.h"

#define ODOM_ITERATE_DELAY 20
#define RADIAN_TO_DEG 57.295780f

extern std::shared_ptr<Rotation> odom_right; 
extern std::shared_ptr<Rotation> odom_left;

class Odometry{
    private: 
        int x_coord, y_coord;
        float prev_theta, theta, d_theta; 
        float prev_s, s, d_s; 
        bool run_odom_task; 

    public: 
        Odometry();
        void begin_tracking(); 
        void stop_tracking(); 
        int get_X_pos(); 
        int get_Y_pos();  

};


#endif
