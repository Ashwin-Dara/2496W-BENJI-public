#ifndef PID_H_
#define PID_H_
#define PID_MAX_VOLTAGE 110.0f
#define PID_MAX_INTEGRAL 17.0f
#define PID_SETTLE_THRESHOLD 3

#include "Config.h"


class PID{
    public:
        int integral; 
        bool using_slew, movement_settled; 
        float kP, kI, kD, sR, current_power; 

        PID(float kP, float kI, float kD, float sR);

        float calculate_power(int set_point, int sensor, int i_bound);

        bool is_settled(); 

};

#endif