#include "TAPE_FOLLOWING.h"
short speed_2=baseSpeed+0;

void start_followtape_2() {
	motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
	motor.speed(MOTOR_RIGHT,0);
	while(!startbutton()){
		TapeMenu();
	}
}

void readFollowTape_2() {
	readQRDErrCalc();
    motor.speed(MOTOR_LEFT, -speed_2 - con);
    motor.speed(MOTOR_RIGHT, +speed_2 - con);
}