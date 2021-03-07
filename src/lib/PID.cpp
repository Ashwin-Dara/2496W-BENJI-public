#include "PID.h"
#include "main.h"

PID::PID(float kP, float kI, float kD, float sR) : kP(kP), kI(kI), kD(kD), sR(sR) {
    using_slew = false; 
    movement_settled = false; 
    current_power = 0; 
}

float PID::calculate_power(int set_point, int sensor, int i_bound){
    int error = set_point - sensor; 
    float p_power = error * kP; 


    if(abs(error) < i_bound){
        integral += error; 
    }
    else{
        integral = 0; 
    }

    float i_power = std::min((float) (integral * kI), PID_MAX_INTEGRAL); 


    pros::delay(50); 


    int delta_error = (set_point - sensor) - error; 
    float d_power = delta_error * kD; 
    if(abs(delta_error) < 3){
        movement_settled = true; 
    }
    else{
        movement_settled = false; 
    }


    float pid_power = p_power + i_power + d_power; 
    float delta_power = pid_power - current_power; 

    if(using_slew){
        if(abs(delta_power) > sR){
            current_power += (sgn(pid_power) * sR);
        }
        else{
            current_power = pid_power; 
        }
    }
    else if(!using_slew){
        current_power = pid_power;
    }
    return std::min((float) current_power, PID_MAX_VOLTAGE); 
}

bool PID::is_settled(){
    return movement_settled; 
}