#include "Drive.h"
#include "Config.h"

namespace Chassis{
    void opcontrol(){
        int right_power = (abs(controller.get_analog(ANALOG_RIGHT_Y)) > DEADBAND_THRESHOLD) ? controller.get_analog(ANALOG_RIGHT_Y) : 0;   
        int left_power = (abs(controller.get_analog(ANALOG_LEFT_Y)) > DEADBAND_THRESHOLD) ? controller.get_analog(ANALOG_LEFT_Y) : 0;   
        chassis_move(right_power, left_power);
    }
}

Drive::Drive(float kP, float kI, float kD, float acceleration_rate) : PID(kP, kI, kD, acceleration_rate) {}

void Drive::init(){
    debug_linear_error = debug_turn_error = 0; 
    debug_linear_power = debug_turn_power = 0; 
}

void Drive::relative_move(int set, int maxVelocity, int maxTime){
    int time = 0; 
    reset_encoder(); 
    
    while((time * DRIVE_STANDARD_DELAY) < maxTime){
        int position = (get_left_position() + get_right_position())/2; 
        float chassis_power = calculate_power(set, position, DRIVE_INTEGRAL_BOUND);

        if(maxVelocity < PID_MAX_VOLTAGE){
            if(abs(chassis_power) > maxVelocity){
                chassis_power = sgn(chassis_power) * maxVelocity;
            }
        }
        else{
            if(abs(chassis_power) > PID_MAX_VOLTAGE){
                chassis_power = sgn(chassis_power) * PID_MAX_VOLTAGE; 
            }
        }

        float encoder_error = get_right_position() - get_left_position(); 
        float heading_correction_pwr = std::min((float) encoder_error * STRAIGHTENING_BIAS, DRIVE_CORRECTION_POWER);     

        chassis_move(chassis_power + heading_correction_pwr, chassis_power - heading_correction_pwr);

        if(is_settled()){
            break;
        }
        if(abs(set - position) < PID_SETTLE_THRESHOLD){
            break;
        }

        debug_linear_error = (int) (set - position); 
        debug_linear_power = (int) chassis_power; 
        pros::delay(DRIVE_STANDARD_DELAY);
        ++time; 
    }
}

void Drive::relative_turn(int target, int maxVelocity, int maxTime){
    int time = 0; 
    imu_sensor.reset();
    while((time * DRIVE_STANDARD_DELAY) < maxTime){
        float position = imu_sensor.get_rotation();
        float turn_power = calculate_power(target, position, TURN_INTEGRAL_BOUND);
        
        turn_power = std::min((int) abs(turn_power), maxVelocity);

        chassis_move(turn_power, -turn_power);

        if(abs(target-position) < PID_SETTLE_THRESHOLD){
            break; 
        }

        debug_turn_error = (int) (target - position);
        debug_turn_power = (int) turn_power; 
        pros::delay(DRIVE_STANDARD_DELAY);
        ++time; 
    }
}

void Drive::terminal_data_stream(){
    std::cout << "Linear Error: " << debug_linear_error << "Turn Error: " << debug_turn_error << "Right Enc: " <<
                 get_right_position() << "Left Enc: " << get_left_position() << "Linear Power: " << debug_linear_power
                 << "Turn Power: " << debug_turn_power;  
}