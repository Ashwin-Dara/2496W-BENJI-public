#ifndef INTAKE_H_
#define INTAKE_H_

#include "PID.h"
#include "Config.h"

#define INTAKE_MAX_VOLTAGE 127.0f
#define DETECT_BALL_CONSTANT 2300

namespace Intake{
    extern int ball_shoot_queue; 
    bool R1, R2; 
    void opcontrol();
    void index(int dir); 
    void sis(); 
    void ASM();
}

#endif