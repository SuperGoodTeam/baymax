#include "TAPE_FOLLOWING.h"

void start_followtape_1() {
	motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
	motor.speed(MOTOR_RIGHT,0);
	while(!startbutton()){
		TapeMenu();
	}
}

void readFollowTape_1() {
	readQRDErrCalc();
    motor.speed(MOTOR_LEFT, -baseSpeed - con);
    motor.speed(MOTOR_RIGHT, +baseSpeed - con);
}
