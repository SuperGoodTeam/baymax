byte motorSwitchVal=1;

void start_claw_arm_test() {
	LCD.clear();
	LCD.home();
	setForearmServo(0);
	setBasearmServo(0);
}

void claw_arm_test() {
	int FOREARM_POSITION=(byte)map(knob(6),0,KNOB_MAX,0,180); //get the position by mapping the knob
	int BASEARM_POSITION=(byte)map(knob(7),0,KNOB_MAX,0,180); //get the position by mapping the knob
	
	setForearmServo(FOREARM_POSITION);
	setBasearmServo(BASEARM_POSITION);
	
	LCD.clear();
	LCD.setCursor(0,0);
	LCD.print("F:"+String(FOREARM_POSITION));
	LCD.setCursor(6,0);
	LCD.print("B:"+String(BASEARM_POSITION));
	LCD.setCursor(0,1);
	checkClawOpen();
	LCD.print("O: "+String(clawOpen)+" P: "+String(digitalRead(SWITCH_PLUSH_DETECT)));
	delay(STANDARD_DELAY_2);
			
	if (startbutton()){
		if (!clawOpen){
			while (!clawOpen && startbutton()){
				motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
				checkClawOpen();
				D(LCD.setCursor(0,1);
				LCD.print("Claw opening test");
				delay(STANDARD_DELAY_1);)
			}
		}
		
		else{
			while (clawOpen && startbutton()){
				motor.speed(MOTOR_CLAW, SPEED_CLAW_CLOSE);
				checkClawOpen();
				D(LCD.setCursor(0,1);
				LCD.print("Claw closing test");
				delay(STANDARD_DELAY_1);)
			}
		}
	}
}
