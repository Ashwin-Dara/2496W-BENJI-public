#include "main.h"
#include "../include/lib/Intake.h"

namespace Intake{
    ball_shoot_queue = 0; 

    void opcontrol(){
        if(controller.get_digital(DIGITAL_L1)){
            intake_move(INTAKE_MAX_VOLTAGE);
            index(1);
        }
        else{
            sis(); 
            intake_move(0);
            
        }

        if(controller.get_digital(DIGITAL_L2)){
            intake_move(-INTAKE_MAX_VOLTAGE);
            index(-1);
        }
        else{
            sis(); 
            intake_move(0);
        }

        R1 = controller.get_digital(DIGITAL_R1);
        R2 = controller.get_digital(DIGITAL_R2);
    }

    void index(int dir){
        uptake.move(120 * dir);
        outake.move(-120 * dir);
    }

    void sis(){
        uptake.move(0);
        outake.move(0);
    }

    void ASM(){ //needs to be put into a seperate thread
        
        if(controller.get_digital(DIGITAL_R1) && !R1){
            ball_shoot_queue++; 
        }

        if(controller.get_digital(DIGITAL_R1) && !R1){ 
            while(line_sensor.get_value() > DETECT_BALL_CONSTANT){ //balls needs to be indexed already

            }    
        }
        
    }


}