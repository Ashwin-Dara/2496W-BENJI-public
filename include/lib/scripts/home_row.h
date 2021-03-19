#ifndef HOME_ROW_H_
#define HOME_ROW_H_

#include "main.h"
#include "../include/lib/Drive.h"
#include "../include/lib/Config.h"
#include "../include/lib/Intake.h"
#include "../include/lib/Point.h"
#include "../include/lib/Odometry.h"
using namespace pros; 

extern Drive drive; 
extern Task odom_task; 
extern AutoIntake intake; 
extern Point coordinates; 
extern Odometry drive_odom; 

void tracking_task(); 
void right_blue_homerow();
void left_red_homerow(); 

#endif