#include "TAPE_FOLLOWING.h"

void start_followtape() {
	//motor_rest();
}

void readFollowTape() {
	readQRDErrCalc();
    motor.speed(MOTOR_LEFT, -baseSpeed - con);
    motor.speed(MOTOR_RIGHT, +baseSpeed - con);
}
