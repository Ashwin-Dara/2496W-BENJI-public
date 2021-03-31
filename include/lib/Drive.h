#ifndef DRIVE_H_
#define DRIVE_H_

//INCLUDING THE REQUIRED FILES
#include "Config.h"
#include "PID.h"

/**
* LINEAR_P_GAIN -- 
* LINEAR_I_GAIN -- 
* LINEAR_D_GAIN --  
* LINEAR_A_LIMIT --
* STRAIGHTENING_BIAS -- 
* DEADBAND_THRESHOLD --
* DRIVE_STANDARD_DELAY 
* DRIVE_INTEGRAL_BOUND 
* DRIVE_CORRECTION_POWER
* TURN_INTEGRAL_BOUND
*/

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

//NAMESPACE CONTAINS USERCONTROL 
namespace Chassis{
    void opcontrol(); 
}


/**
* Class with the standard movement functions for relative, autonomous movement.  
*/
class Drive : public PID {
    private: 
    
        //DEBUGGING VARIABLES
        int debug_linear_error, debug_turn_error; 
        int debug_linear_power, debug_turn_power; 

    public:  
        
        /**
        * Constructor setting the constants for the closed-loop controller. Default argument 
        * for all of the parameters was defined earlier. 
        * 
        * @param kP: P (linear) constant of the PID controller.  
        * @param kI: I (integral) constant within the PID controller.
        * @param kD: D (delta) constant within the PID controller. 
        * @param acceleration_rate: maximum change in voltage applied to the chassis motors.  
        */
        Drive(float kP = LINEAR_P_GAIN, float kI = LINEAR_I_GAIN, float kD = LINEAR_D_GAIN, float acceleration_rate = LINEAR_A_LIMIT); 
        
    
        /**
        * Init private class variables.
        */
        void init();

    
        /**
        * Moves the chassis relative to current position. 
        */
        void relative_move(int set, int max_velocity, int max_time); 

        void relative_turn(int target, int max_velocity, int max_time);

        void terminal_data_stream();
        
};

#endif
