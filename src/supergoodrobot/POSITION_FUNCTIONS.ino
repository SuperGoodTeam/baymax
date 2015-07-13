//============== SET POSITION/CHECK FUNCTIONS ==============
void setForearmServo(int angle) {
	RCServo0.write(angle);
}

void setBasearmServo(int angle) {
	RCServo1.write(angle);
}

void setBaseServo(int angle) {
	RCServo2.write(angle);
}

void checkSideTape() {
	if (analogRead(TAPE_SENSOR_SIDE) > QRD_THRESHOLD) {
		sideTapePresent=true;
	}
	else {
		sideTapePresent=false;
	}
}

void checkClawOpen(){
 if (digitalRead(SWITCH_CLAW_OPEN)){
    clawOpen=false;
   } 
   else {
    clawOpen=true; 
   } 
}

//============== INTERRUPT FUNCTIONS ==============
/*void enableExternalInterrupt(unsigned int INTX, unsigned int mode) {
	if (INTX > 3 || mode > 3 || mode == 1) return;
	cli();
	EIMSK |= (1 << INTX);
	EICRA &= ~(1 << (INTX*2+0));
	EICRA &= ~(1 << (INTX*2+1));
	EICRA |= (mode & (1 << 1)) << (INTX*2+0);
	EICRA |= (mode & (1 << 0)) << (INTX*2+1);
	sei();
}

void disableExternalInterrupt(unsigned int INTX) {
	if (INTX > 3) return;
	EIMSK &= ~(1 << INTX);
}*/


void motor_rest(){ //put this somewhere else later
	motor.speed(MOTOR_LEFT,0);
	motor.speed(MOTOR_RIGHT,0);
}
