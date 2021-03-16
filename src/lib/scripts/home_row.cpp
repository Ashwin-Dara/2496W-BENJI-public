#include "main.h"
#include "../include/lib/scripts/home_row.h"

Drive drive; 
Odometry drive_odom;
AutoIntake intake; 
Point coordinates(0, 0); 

void tracking_task(){
    while(1){
        drive_odom.begin_tracking(); 
    }
}

void right_blue_homerow(){
    pros::Task odom_task(tracking_task);

    //making the first movement forward and then turn towards the corner goal
}