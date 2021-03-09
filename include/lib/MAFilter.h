#ifndef MOVING_AVG_H_
#define MOVING_AVG_H_
#include "Config.h"

extern std::vector<int> value_windows; 

class MAFilter{
    private: 
        int window_size; 
        //using an array is more optimal than std::vector 
        //time complexity: ~2n 

    public: 
        //Recommended window size would be < 5 to prevent time from being above 100 mS delayed
        MAFilter(int window_size); 
        ~MAFilter(); 
        float get_filtered_value(const pros::Imu &_imu); 
        //avoiding passing by value to prevent copy constructor 
        //const reference since we are not modifying _imu
};

#endif 