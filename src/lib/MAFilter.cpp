#include "MAFilter.h"

MAFilter::MAFilter(int window_size) : window_size(window_size){
    std::vector<int> value_windows; 
    value_windows.resize(window_size);
}

MAFilter::~MAFilter() = default; 

float MAFilter::get_filtered_value(const pros::Imu &_imu){
    for(int vector_index = 0; vector_index < value_windows.size(); ++vector_index){
        value_windows.push_back(_imu.get_rotation());
    }
    value_windows.clear(); 
    return (float) ( std::accumulate(value_windows.begin(), value_windows.end(), 0.0) / window_size); 
}