#include "TAPE_FOLLOWING.h"

void start_followtape() {
	//motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
	//motor.speed(MOTOR_RIGHT,0);
}

void readFollowTape() {
    readQRDErrCalc();
    motor.speed(MOTOR_LEFT, -baseSpeed - con);
    motor.speed(MOTOR_RIGHT, +baseSpeed - con);
}
