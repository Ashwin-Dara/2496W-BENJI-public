#include "../include/lib/Point.h"

using namespace std; 

Point::Point(int current_x, int current_y) : current_x(current_x), current_y(current_y) {
    desired_x = desired_y = 0; 
}

void Point::set_current_point(const Odometry &odom){
    current_x = odom.get_X_pos(); 
    current_y = odom.get_Y_pos(); 
}

void Point::set_req_point(int x, int y){
    desired_x = x; 
    desired_y = y; 
}

float Point::point_distance(){
    return (float) hypot((desired_x - current_x), (desired_y - current_y));
}

int Point::get_heading(){
    int x_error = desired_x - current_x; 
    int y_error = desired_y - current_y; 

    return (int) (RADIAN_TO_DEG * atan(x_error / y_error)); 
}