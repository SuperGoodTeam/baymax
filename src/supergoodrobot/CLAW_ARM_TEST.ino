void start_claw_arm_test() {
	LCD.clear();
	LCD.home();
	setForearmServo(0);
	setBasearmServo(0);
}

void claw_arm_test() {
	int forearm_position=(byte)map(knob(6),0,KNOB_MAX,0,180); //get the position by mapping the knob
	int basearm_position=(byte)map(knob(7),0,KNOB_MAX,0,180); //get the position by mapping the knob
	//int base_position=(byte)map(knob(6),0,KNOB_MAX,0,MAIN_MENU); //get the position by mapping the knob

	setForearmServo(forearm_position);
	setBasearmServo(basearm_position);
	//setBaseServo(base_position);
		
	LCD.clear();
	LCD.setCursor(0,0);
	LCD.print("F: "+String(forearm_position)+" B: "+basearm_position);
	LCD.setCursor(0,1);
	LCD.print("O: "+String(digitalRead(SWITCH_CLAW_OPEN))+" P: "+String(digitalRead(SWITCH_PLUSH_DETECT)));
	delay(STANDARD_DELAY_2);
	
	if (startbutton()){
		if (clawOpen!=true){
			while (!clawOpen && !startbutton()){
				motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
			}
		}
		
		else{
			while (clawOpen && !startbutton()){
				motor.speed(MOTOR_CLAW, SPEED_CLAW_CLOSE);
			}
		}
	}
}
