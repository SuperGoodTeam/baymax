//============== SET POSITION/CHECK FUNCTIONS ==============
int currentPosition = 0;

//============== SETTING FUNCTIONS ==============
void setForearmServo(int angle) {
	RCServo0.write(angle);
}

void setBasearmServo(int angle) {
	RCServo1.write(angle);
}

/*void setBaseServo(int angle) {
	RCServo2.write(angle);
}*/

void setBaseMotor(int voltagePosition) {
	if (voltagePosition < 256 || voltagePosition > 256*3 || SPEED_BASE_MOTOR > 153.6) {
		LCD.clear();
		LCD.print("Invalid base parameters");
		delay(STANDARD_DELAY_1);
	} //just to be safe
	else{
		currentPosition=readMotorBase();
		while (voltagePosition != currentPosition){
			if (voltagePosition < currentPosition) {
				currentPosition=readMotorBase();
				D(currentPosition=knob(7);)//turn this off later
				motor.speed(MOTOR_BASE, SPEED_BASE_MOTOR); 
				D(LCD.clear();
				LCD.print("BM +: "+String(voltagePosition)+" "+String(currentPosition));
				delay(STANDARD_DELAY_2);)
			}
			else if (voltagePosition > currentPosition) {
				currentPosition=readMotorBase();
				D(currentPosition=knob(7);)//turn this off later
				motor.speed(MOTOR_BASE, -SPEED_BASE_MOTOR); 
				D(LCD.clear();
				LCD.print("BM -: "+String(voltagePosition)+" "+String(currentPosition));
				delay(STANDARD_DELAY_2);)
			}
		}
	}
}

//============== READING FUNCTIONS ==============
int readMotorBase() {
	return analogRead(MOTOR_BASE_SENSOR);
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
