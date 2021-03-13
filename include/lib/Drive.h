#ifndef DRIVE_H_
#define DRIVE_H_

#include "Config.h"
#include "PID.h"

#define LINEAR_P_GAIN 0.35f
#define LINEAR_I_GAIN 0.1f
#define LINEAR_D_GAIN 0.08f
#define LINEAR_A_LIMIT 2.0f
#define STRAIGHTENING_BIAS 1.24f

#define DEADBAND_THRESHOLD 2 
#define DRIVE_STANDARD_DELAY 25 
#define DRIVE_INTEGRAL_BOUND 23
#define DRIVE_CORRECTION_POWER 4.0f
#define TURN_INTEGRAL_BOUND 30

namespace Chassis{
    void opcontrol(); 
}

class Drive : public PID {
    private: 
        int debug_linear_error, debug_turn_error; 
        int debug_linear_power, debug_turn_power; 

    public:  
        Drive(float kP = LINEAR_P_GAIN, float kI = LINEAR_I_GAIN, float kD = LINEAR_D_GAIN, float acceleration_rate = LINEAR_A_LIMIT); 
        
        void init();

        void relative_move(int set, int max_velocity, int max_time); 

        void relative_turn(int target, int max_velocity, int max_time);

        void terminal_data_stream();
        
};

#endif