#ifndef CONFIG_H_
#define CONFIG_H_

//Including all of the libraries that would be used throughout the rest of the code
#include "main.h"
#include <cmath>
#include <string>
#include <memory>
#include <numeric>
#include <iostream>

/**
* Defining the port numbers of the robot's subsystems. 
* 
* Motors for the chassis are indicated by by "DRIVE". The chassis is a four motor drive. 
* The intake will be indicated by "INTAKE". There are 2 intake motors situated on the front of the motor. 
* There are two rotation sensors for each side of the drive and have the keyword "ENC."
* The remaining motors are for the indexer (uptake) and the fly-wheel shooter (outtake). There are is one line sensor for detecting the ball within the robot. 
* Finally, there is an IMU sensor. 
*/

#define RIGHT_DRIVE 1 //Chassis motors
#define RIGHT_DRIVE_2 2

#define LEFT_DRIVE 3 //Chassis motors
#define LEFT_DRIVE_2 4

#define RIGHT_INTAKE 5 //Intakes
#define LEFT_INTAKE 6

#define UPTAKE 7 //Uptake/Flywheel
#define OUTAKE 8

#define RIGHT_ENC 10 //Rotation Sensors 
#define LEFT_ENC 9

#define LINE_SENSOR 12 //Misc. 
#define IMU_SENSOR 13

using namespace pros; 

extern Controller controller; 

extern Imu imu_sensor; 
extern ADIAnalogIn line_sensor; 

extern Motor left_drive, left_drive2; 
extern Motor right_drive, right_drive2; 

extern Motor uptake, outake; 
extern Motor right_intake, left_intake; 

extern Rotation right_encoder, left_encoder; 

void intake_move(float velocity);
void chassis_move(float velocity);
void chassis_move(float right_velocity, float left_velocity);

void reset_encoder(); 
float get_right_position();
float get_left_position();
float inches_to_ticks(int inches); 
 
int sgn(float x);

#endif
