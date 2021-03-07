#include "main.h"
#include "Config.h"

using namespace pros; 

Controller controller(CONTROLLER_MASTER);

Imu imu_sensor(IMU_SENSOR);
ADIAnalogIn line_sensor(LINE_SENSOR);

Rotation right_encoder(RIGHT_ENC);
Rotation left_encoder(LEFT_ENC);

Motor left_drive(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor left_drive2(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

Motor right_drive(LEFT_DRIVE, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor right_drive2(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

Motor right_intake(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor left_intake(LEFT_DRIVE, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);

Motor uptake(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor outake(LEFT_DRIVE, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);

void intake_move(float velocity){
    right_intake.move(velocity);
    left_intake.move(velocity);
}

void chassis_move(float velocity){
    left_drive.move(velocity);
    left_drive2.move(velocity);
    
    right_drive.move(velocity);
    right_drive2.move(velocity);
}

void chassis_move(float right_velocity, float left_velocity){
    left_drive.move(left_velocity);
    left_drive2.move(left_velocity);
    
    right_drive.move(right_velocity);
    right_drive2.move(right_velocity);
}

int sgn(float x){
    if(x >= 0) return 1;
    else return -1; 
}

void reset_encoder(){
    right_encoder.reset_position();
    left_encoder.reset_position(); 
}

float get_right_position(){
    return right_encoder.get_position(); 
}

float get_left_position(){
    return -left_encoder.get_position(); 
}