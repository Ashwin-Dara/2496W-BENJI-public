#include "main.h"
#include "../include/lib/Intake.h"

namespace Intake{
    void opcontrol(){
        if(controller.get_digital(DIGITAL_L1)){
            intake_move(INTAKE_MAX_VOLTAGE);
        }
        else{
            intake_move(0);
        }

        if(controller.get_digital(DIGITAL_L2)){
            intake_move(-INTAKE_MAX_VOLTAGE);
        }
        else{
            intake_move(0);
        }
        
        R1 = controller.get_digital(DIGITAL_R1);
        R2 = controller.get_digital(DIGITAL_R2);
    }

    void ASNI(){
        if(controller.get_digital(DIGITAL_R1) && !R1){
            
        }
    }


}