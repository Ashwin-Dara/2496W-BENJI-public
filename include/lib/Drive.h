#ifndef DRIVE_H_
#define DRIVE_H_

//INCLUDING THE REQUIRED FILES
//MAIN IS INCLUDED WITHIN CONFIG
#include "Config.h"
#include "PID.h"

/**
* LINEAR_P_GAIN -- proportional gain for the drive's linear movements
* LINEAR_I_GAIN -- integral gain for the drive's linear movements
* LINEAR_D_GAIN -- deriv. gain for linear movements
* LINEAR_A_LIMIT -- maximum acceleration of the drive
* STRAIGHTENING_BIAS -- constant that will be multiplied by the difference in R and L enc.  
* DEADBAND_THRESHOLD -- equal to 2
* DRIVE_STANDARD_DELAY -- to save resources, each loop delays ~25 seconds
* DRIVE_INTEGRAL_BOUND -- anti-windup for the integral controller
* DRIVE_CORRECTION_POWER -- maximum straightening power
* TURN_INTEGRAL_BOUND -- anti-windup bound for turns
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
* Class with the standard movement functions for relative, autonomous movement (turns and forward). 
*/
class Drive : public PID { //inherits PID
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
        * 
        * @param set: amount of encoder ticks that the chassis will move forward by
        * @param max_velocity: maximum voltage applied to the chassis motors
        * @param max_time: maximum time given to the chassis to settle 
        */
        void relative_move(int set, int max_velocity, int max_time); 

    
        /**
        * Moves the chassis relative to current position. 
        * 
        * @param target: how many degrees the chassis should turn. Positive is right. 
        * @param max_velocity: maximum voltage applied to the chassis motors
        * @param max_time: maximum time given to the chassis to settle 
        */
        void relative_turn(int target, int max_velocity, int max_time);

    
        /**
        * Prints useful data. 
        */
        void terminal_data_stream();
        
};

#endif
