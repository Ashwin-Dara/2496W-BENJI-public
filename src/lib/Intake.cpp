#include "main.h"
#include "../include/lib/Intake.h"


namespace Intake{
    int ball_shoot_queue = 0; 
    bool start_task = false; 
    bool R1 = false;
    bool R2 = false;  

    void opcontrol(){
        
        if(!start_task){
            pros::Task ASM_task(Intake::ASM);
            start_task = true; 
        }

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

    void ASM(void* param){ 
        while(1){
            if(controller.get_digital(DIGITAL_R1) && !R1){
                Intake::ball_shoot_queue++; 
            }
            if(controller.get_digital(DIGITAL_R2) && !R2 && ball_shoot_queue > 0){
                for(int i = 0; i < ball_shoot_queue; ++i){
                 if(i + 1 == ball_shoot_queue){
                        outake.move(127);
                        pros::delay(650); //time was tuned
                        outake.move(0);
                        index(1);
                        pros::delay(400); 
                        sis(); 
                    }
                 else{
                        outake.move(127); 
                        pros::delay(650);
                        outake.move(0);
                        while(line_sensor.get_value() < DETECT_BALL_CONSTANT){
                            index(1); 
                        }
                    }
                }
                ball_shoot_queue = 0; 
                sis(); 
            }
        }
    }
}