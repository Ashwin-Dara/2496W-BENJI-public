#ifndef ODOM_H_
#define ODOM_H_
#include "main.h"
#include "../include/lib/Config.h"

extern std::shared_ptr<Imu> odom_imu; 
extern std::shared_ptr<Rotation> odom_right; 
extern std::shared_ptr<Rotation> odom_left;

class Odometry{
    private: 
        int x_coord, y_coord;

    public: 
        Odometry();
        void begin_tracking(); 
        void stop_tracking(); 
        int get_x_position(); 
        int get_y_position();  
    
};


#endif
