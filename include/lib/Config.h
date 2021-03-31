#ifndef CONFIG_H_
#define CONFIG_H_

/**
* Including all of the libraries that would be used throughout the rest of the code. 
* 
* "main.h" -- required to be included for this file to be considered a part of the 
*             the PROS project. This will be a part of all files
* <cmath> -- this contains all of the trig functions used in odometry/pathfollowing
* <string> -- includes string datatype
* <memory> -- needed to use smart pointers
* <numeric> -- vector mathematics (e.g., dot product)
* <iostream> -- using std::cout to print
*/

#include "main.h" 
#include <cmath> 
#include <string> 
#include <memory> 
#include <numeric> 
#include <iostream> 
using namespace pros; 


/**
* Defining the port numbers of the robot's subsystems. 
* 
* Motors for the chassis are indicated by by "DRIVE". The chassis is a four motor drive. 
* 
* The intake will be indicated by "INTAKE". There are 2 intake motors situated on the 
* front of the motor. 
*
* There are two rotation sensors for each side of the drive and have the keyword "ENC."
* 
* The remaining motors are for the indexer (uptake) and the fly-wheel shooter (outtake). 
*
* There are is one line sensor for detecting the ball within the robot. Finally, there is 
* an IMU sensor. 
*/

//RIGHT CHASSIS MOTOR PORTS
#define RIGHT_DRIVE 1 
#define RIGHT_DRIVE_2 2

//LEFT CHASSIS MOTOR PORTS
#define LEFT_DRIVE 3 
#define LEFT_DRIVE_2 4

//INTAKE PORTS
#define RIGHT_INTAKE 5 
#define LEFT_INTAKE 6

//SHOOTER PORTS
#define UPTAKE 7 
#define OUTAKE 8

//TRACKING WHEELS PORTS
#define RIGHT_ENC 10 
#define LEFT_ENC 9

//IMU AND LIGHT-LINE SENSOR PORT
#define LINE_SENSOR 12 
#define IMU_SENSOR 13


/**
* Setting up the electronics by creating extern class for each electronic. 
*/
extern Imu imu_sensor; 

extern Controller controller; 

extern ADIAnalogIn line_sensor; 

extern Motor uptake, outake, right_intake, left_intake; 
extern Motor right_drive, right_drive2, left_drive, left_drive2; 

extern Rotation right_encoder, left_encoder; 


/**
* Applies specified voltage (-127 to 127) to the intakes.
*/
void intake_move(float velocity);


/**
* Moves the chassis at a specified velocity. 
*/
void chassis_move(float velocity);


/**
* Moves the individual sides of the drive. 
*/
void chassis_move(float right_velocity, float left_velocity);


/**
* Resets the tracking wheels position
*/
void reset_encoder(); 

/**
* Returns right tracking wheel's position. 
*/
float get_right_position();


/**
* Returns left tracking wheel's position. 
*/
float get_left_position();


/**
* Converts inches to sensor ticks. 
*/
float inches_to_ticks(int inches); 
 

/**
* Returns the sign of the number. 
* Returns Either 1, or -1.
*/
int sgn(float x);

#endif
