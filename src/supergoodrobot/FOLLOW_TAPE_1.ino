#include "TAPE_FOLLOWING.h"

void start_followtape_1() {
	//motor_rest();
}

void readFollowTape_1() {
	readQRDErrCalc();
    motor.speed(MOTOR_LEFT, -baseSpeed - con);
    motor.speed(MOTOR_RIGHT, +baseSpeed - con);
}
