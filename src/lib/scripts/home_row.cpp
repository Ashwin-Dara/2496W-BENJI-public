#include "main.h"
#include "../include/lib/scripts/home_row.h"

Drive drive; 
Odometry drive_odom;
AutoIntake intake; 
Point coordinates(0, 0); 

void tracking_task(){
        drive_odom.begin_tracking(); 
}

void right_blue_homerow(){
    pros::Task odom_task(tracking_task); //beginning the position tracking calculations
    

    //moving forward to intake and then turning towards the corner goal
    intake.index(1);
    drive.relative_move((int) inches_to_ticks(20), 100, 900);
    drive.relative_turn(45, 120, 800);


    //setting the target point to be the coordinates of the corner goal
    intake.sis(); 
    coordinates.set_req_point((int)inches_to_ticks(25), (int)inches_to_ticks(25));
    

    //driving to that point with a max velocity of 105. Waiting 1.3 seconds for the movement to complete.
    drive_to_point(drive_odom, coordinates, 105, 1300);
    intake.auton_ASI(); //shoot the ball and index the next one


    //back away from the goal with a speed of 110 units
    drive.relative_move(-400, 110, 700);
    

    //setting the new desired location of the robot and then moving there
    coordinates.set_req_point((int) inches_to_ticks(-40), (int) inches_to_ticks(25)); 
    drive_to_point(drive_odom, coordinates, 105, 1200);


    //turn to face the goal and then drive forward into the goal and score
    drive.relative_turn(-90, 100, 800);
    drive.relative_move(455, 80, 1000);
    intake.auton_ASNI(); //no indexing the next ball 


    //moving back from the goal
    drive.relative_move(-300, 110, 700);
    

    //begin intaking, intake the ball, and get in position for the corner goal
    intake.index(1);
    coordinates.set_req_point((int inches_to_ticks(-80), (int) inches_to_ticks(24));
    drive_to_point(drive_odom, coordinates, 100, 1600);
    sis(); //stopping all intaking subsystems

    
    //move towards the final corner goal
    coordinates.set_req_point((int) inches_to_ticks(-100), (int) inches_to_ticks(10));
    drive_to_point(drive_odom, coordinates, 110, 1000); 
    intake.auton_ASNI(); //score without intaking

}