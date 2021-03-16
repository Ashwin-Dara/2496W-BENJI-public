#include "main.h"
#include "../include/lib/Drive.h"
#include "../include/lib/Config.h"
#include "../include/lib/Intake.h"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);
}

void disabled() {}

void competition_initialize() {
	imu_sensor.reset(); 
}

void opcontrol() {
	while (true) {
		Chassis::opcontrol(); 
		Intake::opcontrol(); 
		pros::delay(20);
	}
}
