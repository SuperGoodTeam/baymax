//starting position
#define FOREARMSERVO_POSITION_2_A 90//some number
#define BASESERVO_POSITION_2_A 90//some number
#define BASE_POSITION_2_A 90//some number

//getting item position
#define FOREARMSERVO_POSITION_2_B 90//some number
#define BASESERVO_POSITION_2_B 90//some number
#define BASE_POSITION_2_B 90//some number

//dropping item position
#define FOREARMSERVO_POSITION_2_C 90//some number
#define BASESERVO_POSITION_2_C 90//some number
#define BASE_POSITION_2_C 90//some number

#define SPEED_CLAW_OPEN 90//some number
#define SPEED_CLAW_CLOSE 90//some number

boolean item_2_collected=false;

void start_collect_item_2() {
	//set to starting position
	setForearmServo(FOREARMSERVO_POSITION_2_A);
	setBasearmServo(BASESERVO_POSITION_2_A);
	setBaseServo(BASE_POSITION_2_A);
	while (!SWITCH_CLAW_OPEN) {
		motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
	}
}

void collect_item_2() {
	//set to lowering position
	setForearmServo(FOREARMSERVO_POSITION_2_B); //some angle
	setBaseServo(BASE_POSITION_2_B); //some angle
	setBasearmServo(BASESERVO_POSITION_2_B); //some angle
	
	delay(STANDARD_DELAY_1); //pause for a second
	
	while (item_2_collected==false) {
		motor.speed(MOTOR_CLAW, SPEED_CLAW_CLOSE);
                checkItemSensor_2();
	}
	
	delay(STANDARD_DELAY_1); //for safety
	
	//now reverse that exactly
	setBasearmServo(BASESERVO_POSITION_2_C); //some angle
	setBaseServo(BASE_POSITION_2_C); //some angle
	setForearmServo(FOREARMSERVO_POSITION_2_C); //some angle
	
	while (SWITCH_CLAW_OPEN==false) {
		motor.speed(MOTOR_CLAW, SPEED_CLAW_OPEN);
                checkClawOpen();
	}	
}

void checkItemSensor_2() {
   if (digitalRead(SWITCH_PLUSH_DETECT)){
    item_2_collected=false;
   } 
   else {
    item_2_collected=true; 
   }
}
