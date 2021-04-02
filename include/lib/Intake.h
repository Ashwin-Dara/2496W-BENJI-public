#ifndef INTAKE_H_
#define INTAKE_H_

//INCLUDING FILES
//CONFIG INCLUDES MAIN
#include "Config.h"
#include "PID.h"

#define INTAKE_MAX_VOLTAGE 127.0f
#define DETECT_BALL_CONSTANT 2300 //value of the light sensor when a ball is detected

extern pros::Task ASM_task; //Autoshoot task

namespace Intake{
    extern int ball_shoot_queue; //balls requested to be shot
    
    //used for the rising edge to increase ball queue count
    extern bool start_task; 
    extern bool R1, R2; 
    
    void opcontrol();
    void index(int dir); 
    void sis(); 
    void ASM(void* param);
}

class AutoIntake {
    public: 
        void index(); 
        void sis(); 
        void auton_ASNI(); 
        void auton_ASI(); 
};

#endif
