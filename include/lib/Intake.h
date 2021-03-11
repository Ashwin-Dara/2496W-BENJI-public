#ifndef INTAKE_H_
#define INTAKE_H_

#include "PID.h"
#include "Config.h"

#define INTAKE_MAX_VOLTAGE 127.0f

namespace Intake{
    bool R1, R2; 
    void opcontrol();
    void ASNI();
    void ASI();
}


#endif