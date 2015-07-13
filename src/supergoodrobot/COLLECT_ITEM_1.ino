//starting position
#define FOREARMSERVO_POSITION_1_A 90//some number
#define BASESERVO_POSITION_1_A 90//some number
#define BASE_POSITION_1_A 90//some number

//getting item position
#define FOREARMSERVO_POSITION_1_B 30//some number
#define BASESERVO_POSITION_1_B 30//some number
#define BASE_POSITION_1_B 90//some number

//dropping item position
#define FOREARMSERVO_POSITION_1_C 90//some number
#define BASESERVO_POSITION_1_C 90//some number
#define BASE_POSITION_1_C 90//some number

#define SPEED_CLAW_OPEN 90//some number
#define SPEED_CLAW_CLOSE 90//some number

boolean item_1_collected=false;

void start_collect_item_1() {
	//set to starting position
	setForearmServo(FOREARMSERVO_POSITION_1_A);
	setBasearmServo(BASESERVO_POSITION_1_A);
	setBaseServo(BASE_POSITION_1_A);
	while (!clawOpen) {
		LCD.clear();
		LCD.print("Claw opening");
		delay(STANDARD_DELAY_1); //temp
		motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
	}
}

void collect_item_1() {
	//set to lowering position
	setForearmServo(FOREARMSERVO_POSITION_1_B); //some angle
	setBaseServo(BASE_POSITION_1_B); //some angle
	setBasearmServo(BASESERVO_POSITION_1_B); //some angle
	
	delay(STANDARD_DELAY_1); //pause for a second
	
	while (item_1_collected==false) { //temp, change later
		LCD.clear();
		LCD.print("Claw closing");
		delay(STANDARD_DELAY_1); //temp
		motor.speed(MOTOR_CLAW, SPEED_CLAW_CLOSE);
		checkItemSensor_1();
	}
	
	delay(STANDARD_DELAY_1); //for safety
	
	//now reverse that exactly
	setBasearmServo(BASESERVO_POSITION_1_C); //some angle
	setBaseServo(BASE_POSITION_1_C); //some angle
	setForearmServo(FOREARMSERVO_POSITION_1_C); //some angle
	
	while (!clawOpen) {
		LCD.clear();
		LCD.print("Claw opening 2");
		delay(STANDARD_DELAY_1); //temp
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
