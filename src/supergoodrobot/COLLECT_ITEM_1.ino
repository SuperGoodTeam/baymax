//starting position
const int FOREARMSERVO_POSITION_1_A = 90;//some number
const int BASEARMSERVO_POSITION_1_A = 90;//some number
const int BASE_POSITION_1_A = 512;//some number

//getting item position
const int FOREARMSERVO_POSITION_1_B = 30;//some number
const int BASEARMSERVO_POSITION_1_B = 30;//some number
const int BASE_POSITION_1_B = 512;//some number

//dropping item position
const int FOREARMSERVO_POSITION_1_C = 90;//some number
const int BASEARMSERVO_POSITION_1_C = 90;//some number
const int BASE_POSITION_1_C = 512;//some number

boolean item_1_collected=false;

void start_collect_item_1() {
	//set to starting position
	setForearmServo(FOREARMSERVO_POSITION_1_A);
	setBasearmServo(BASEARMSERVO_POSITION_1_A);
	setBaseMotor(BASE_POSITION_1_A);
	while (!clawOpen) {
		
		D(LCD.clear();
		LCD.print("Claw opening init 1");)
		
		motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
	}
}

void collect_item_1() {
	//set to lowering position
	setForearmServo(FOREARMSERVO_POSITION_1_B); //some angle
	setBaseMotor(BASE_POSITION_1_B); //some angle
	setBasearmServo(BASEARMSERVO_POSITION_1_B); //some angle
	
	delay(STANDARD_DELAY_1); //pause for a second
	
	while (item_1_collected==false) { //temp, change later
		
		D(LCD.clear();
		LCD.print("Claw closing 1");)
		
		motor.speed(MOTOR_CLAW, SPEED_CLAW_CLOSE);
		checkItemSensor_1();
	}
	
	delay(STANDARD_DELAY_1); //for safety
	
	//now reverse that exactly
	setBasearmServo(BASEARMSERVO_POSITION_1_C); //some angle
	setBaseMotor(BASE_POSITION_1_C); //some angle
	setForearmServo(FOREARMSERVO_POSITION_1_C); //some angle
	
	while (!clawOpen) {
		D(LCD.clear();
		LCD.print("Claw opening 2");
		delay(STANDARD_DELAY_1);)
		motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
		checkClawOpen();
	}
}

void checkItemSensor_1() {
	if (digitalRead(SWITCH_PLUSH_DETECT)){
		item_1_collected=false;
	} 
	else {//switch press is low
		item_1_collected=true; 
	}
}
