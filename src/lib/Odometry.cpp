#include "../include/lib/Odometry.h"
using namespace std;

shared_ptr<Rotation> odom_right = make_shared<Rotation>(RIGHT_ENC);
shared_ptr<Rotation> odom_left = make_shared<Rotation>(LEFT_ENC);

Odometry::Odometry(){
    x_coord = y_coord = 0; 
    theta = prev_theta = d_theta = 0; 
    s = d_s = 0; 
    run_odom_task = false; 
}

void Odometry::begin_tracking(){
    run_odom_task = true; 
    while(1){
        prev_s = (odom_right->get_position() + odom_left->get_position()) / 2; 
        prev_theta = imu_sensor.get_rotation() * 1/RADIAN_TO_DEG;  

        pros::delay(ODOM_ITERATE_DELAY);

        s = (odom_right->get_position() + odom_left->get_position()) / 2;
        theta = imu_sensor.get_rotation() * 1/RADIAN_TO_DEG;  
        d_s = s - prev_s; 
        d_theta = theta - prev_theta; 

        x_coord += (int) (d_s * cos(theta + (d_theta/2))); 
        y_coord += (int) (d_s * sin(theta + (d_theta/2))); 

        if(run_odom_task){
            break; 
        }
    }
}

void Odometry::stop_tracking(){
    run_odom_task = false; 
}

int Odometry::get_X_pos() const{
    return x_coord; 
}

int Odometry::get_Y_pos() const{
    return y_coord; 
}

void drive_to_point(const Odometry &odom, Point &coord, int max_velocity, int ms){
    coord.set_current_point(odom);
    
    int total_time = 0; 
    
    float heading_target = coord.get_heading(); 
    float point_error = coord.point_distance(); 
    
    MAFilter filtered_imu(4);

    PID heading_pid(HEADING_KP, HEADING_KI, HEADING_KD, HEADING_SR);
    PID linear_pid(ODOM_LIN_KP, ODOM_LIN_KI, ODOM_LIN_KD, ODOM_LIN_SR);

    while(total_time < ms){
        float position = filtered_imu.get_filtered_value(imu_sensor);
        float heading_power = heading_pid.calculate_power(heading_target, position, HEADING_IB);
        heading_power = min( (int) abs(heading_power), abs(max_velocity));
        chassis_move(heading_power, -heading_power);
        
        if(heading_pid.is_settled()){
            break; 
        }
        if(abs(heading_target - position) < PID_SETTLE_THRESHOLD){
            break; 
        }
        
        pros::delay(20);
        total_time += 20; 
    }
    reset_encoder(); 
    while(total_time < ms){
        float heading_error = heading_target - filtered_imu.get_filtered_value(imu_sensor);
        float heading_correction_pwr = ODOM_BIAS * heading_error; 
        int position = (get_left_position() + get_right_position())/2; 
        float linear_speed = linear_pid.calculate_power(point_error, position, 25);
        
        linear_speed = min(abs(linear_speed), (float) abs(max_velocity));
        heading_correction_pwr = min(abs(heading_correction_pwr), ODOM_BIAS_CAP);

        chassis_move(linear_speed + heading_correction_pwr, linear_speed - heading_correction_pwr); 

        if(linear_pid.is_settled()){
            break; 
        }
        if(abs(point_error - position) < PID_SETTLE_THRESHOLD){
            break; 
        }       
        
        pros::delay(20);
        total_time += 20; 
    }
    chassis_move(0, 0);
    coord.set_current_point(odom);
}

//need to make a path following function