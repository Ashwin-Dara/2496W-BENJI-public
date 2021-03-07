#ifndef CONFIG_H_
#define CONFIG_H_

#include "main.h"
#include <cmath>
#include <string>
#include <memory>
#include <numeric>
#include <iostream>

#define RIGHT_DRIVE 1
#define RIGHT_DRIVE_2 2

#define LEFT_DRIVE 3
#define LEFT_DRIVE_2 4

#define RIGHT_INTAKE 5
#define LEFT_INTAKE 6

#define UPTAKE 7
#define OUTAKE 8

#define RIGHT_ENC 10
#define LEFT_ENC 9

#define LINE_SENSOR 12
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
 
int sgn(float x);

#endif
