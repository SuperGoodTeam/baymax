/* ENPH 253 PRELIMINARY CODE
last updated: 070815
version: 0.2

*/

//============== LIBRARIES ==============
#include <phys253.h>
#include <LiquidCrystal.h>
//#include <Servo253.h>
#include <avr/interrupt.h>

#include <EEPROMex.h>
#include <EEPROMVar.h>

#include "TAPE_FOLLOWING.h"

//============== PINS ==============
//ANALOG IO
#define TAPE_SENSOR_LEFT 0
#define TAPE_SENSOR_RIGHT 1
#define IR_FRONT_1 2
#define IR_FRONT_2 3
#define IR_SIDE 4
#define TAPE_SENSOR_SIDE 5
#define TAPE_SENSOR_FRONT 7

//SERVOS
#define SERVO_FOREARM 0
#define SERVO_BASEARM 1
#define SERVO_BASE 2

//MOTORS
#define MOTOR_LEFT 0
#define MOTOR_RIGHT 1
#define MOTOR_CLAW 2

//DIGITAL IO
//INPUT
#define SWITCH_CLAW_OPEN 4
#define SWITCH_CLAW_CLOSE 5
#define SWITCH_PLUSH_DETECT 6
#define HOOK_ARM_TOUCH_ON 7
#define HOOK_ARM_TOUCH_OFF 8

//OUTPUT
#define HOOK_ARM_RETRACT 15
#define HOOK_ARM_SPRING_UP 14
#define INTAKE_ROLLER_MOTOR 12

//============== DRIVE SETTINGS ==============
//QRD DRIVE
#define QRD_THRESHOLD 200

//IR DRIVE

//ARM CONSTANTS

//SERVO POSITIONS
#define BASESERVO_POSITION_START 90//some number
#define FOREARMSERVO_POSITION_START 90//some number
#define BASE_POSITION_START 90//some number

//FLAGS
boolean upRamp=false;
boolean sideTapePresent=false;
boolean clawOpen=false;
boolean previousSwitchVal=true;

#define KNOB_MAX 1023
#define STANDARD_DELAY_1 500 //ms
#define STANDARD_DELAY_2 200 //ms for faster things
//============== STATES ==============
enum RobotState {
	INITIALISING, PAST_DOOR, FOLLOW_TAPE_1, COLLECT_ITEM_1, FOLLOW_TAPE_2, COLLECT_ITEM_2, COLLECT_ITEM_3, COLLECT_ITEM_4, COLLECT_ITEM_5, COLLECT_ITEM_6, UP_RAMP, PAST_RAMP, IR, ZIPLINE, FINISHED, TEST,DRIVE, CLAW_ARM_TEST, MAIN_MENU, STATE_MENU, TAPE_MENU, NUM_STATES
};
enum Plan { 
	FULL, NOT4, NOT5, TEST_DRIVE, NUM_PLAN //placeholder for lack of len(enum) function, don't delete
};

//SET STATES
RobotState currentState = INITIALISING;
RobotState lastState = INITIALISING;  

Plan currentPlan=FULL;

//============== INTERRUPTS ==============
/*volatile unsigned int INT_0 = 0;
ISR(INT0_vect) {LCD.clear(); LCD.home(); LCD.print("INT0: "); LCD.print(INT_0++);};
ISR(INT0_vect) {
  switchState(MAIN_MENU);
}*/

//============== SETUP ==============
void setup() {
	#include <phys253setup.txt>  
	portMode(0, INPUT) ;
	portMode(1, OUTPUT) ;

	LCD.clear();
	LCD.home();

	RCServo0.attach(RCServo0Output) ;
	RCServo1.attach(RCServo1Output) ;
	RCServo2.attach(RCServo2Output) ;

	//initiate servos
	setForearmServo(FOREARMSERVO_POSITION_START);
	setBasearmServo(BASESERVO_POSITION_START);
	setBaseServo(BASE_POSITION_START);
	//other stuff goes here

	//enableExternalInterrupt(INT0, RISING);  
}

void loop() {
//	if (digitalRead(0)!=previousSwitchVal) {
    if (stopbutton()) {
		switchState(MAIN_MENU);
//		previousSwitchVal=digitalRead(0);
	}

	switch(currentState) {
	//==============
	case INITIALISING:
		start_initialising(); //set plan
		break;
	//==============
	case FOLLOW_TAPE_1:
		while (sideTapePresent!=true) {
			readFollowTape_1();
			checkSideTape();
		}
		motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
		motor.speed(MOTOR_RIGHT,0);
		if (sideTapePresent==true) {
			switchState(COLLECT_ITEM_1);
		}
		break;
	//==============
	case COLLECT_ITEM_1:
		collect_item_1();
		while(sideTapePresent==true) { //go until you can't see sidetape anymore
			LCD.clear();
			LCD.print("Following sidetape");
			delay(STANDARD_DELAY_1);
			readFollowTape_1();
			checkSideTape();
		}
		if (sideTapePresent==false) {
		switchState(FOLLOW_TAPE_2);
		}
		break;
	//==============
	case FOLLOW_TAPE_2:
		while (sideTapePresent!=true) {
			readFollowTape_2();
			checkSideTape();
		}
		motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
		motor.speed(MOTOR_RIGHT,0);
		if (sideTapePresent==true) {
			switchState(COLLECT_ITEM_2);
		}
		break;
	//==============
	case COLLECT_ITEM_2:
		/*collect_item_2();
		while(sideTapePresent==true) { //go until you can't see sidetape anymore
			readFollowTape_2();
			checkSideTape();
		}
		switchState(FOLLOW_TAPE_3);*/
		break;
	//==============
	case COLLECT_ITEM_3:
	break;
	case COLLECT_ITEM_4:
	break;
	case COLLECT_ITEM_5:
	break;
	case COLLECT_ITEM_6:
	break;
	case UP_RAMP:
	break;
	case PAST_RAMP:
	break;
	case IR:
	break;
	case ZIPLINE:
	break;
	case FINISHED:
	break;
	case CLAW_ARM_TEST:
		claw_arm_test();
	break;
	case DRIVE:
	readFollowTape();
	break;
	case MAIN_MENU:
	mainMenu();
	break;
	case STATE_MENU:
	stateMenu();
	break;
	case TAPE_MENU:
	tapeMenu();
	break;
  }
}

//============== STATE FUNCTIONS ==============
void switchState(byte byteRobotState){
	RobotState newState=(RobotState)byteRobotState;
	exitState(currentState);
	LCDStateChangePrint(byteRobotState);
	setupState(newState); //simple for now
	currentState=newState;
}

void setupState(byte byteRobotState)
{
	RobotState state = (RobotState)byteRobotState;
	switch (state)
	{
	case PAST_DOOR:
		break;
	case FOLLOW_TAPE_1:
		start_followtape_1();
		break;
	case COLLECT_ITEM_1:
		start_collect_item_1();
		break;
	case FOLLOW_TAPE_2:
		start_followtape_2();
		break;
	case COLLECT_ITEM_2:
		start_collect_item_2();
		break;
	case COLLECT_ITEM_3:
		break;
	case COLLECT_ITEM_4:
		break;
	case COLLECT_ITEM_5:
		break;
	case COLLECT_ITEM_6:
		break;
	case UP_RAMP:
		break;
	case PAST_RAMP:
		break;
	case IR:
		break;
	case ZIPLINE:
		break;
	case FINISHED:
		break;
	case TEST:
		break;
	case CLAW_ARM_TEST:
		start_claw_arm_test();
		break;
	case MAIN_MENU:
		start_main_menu();
		break;
	case STATE_MENU:
		start_state_menu();
		break;
	case TAPE_MENU:
		start_tape_menu();
		break;
	case DRIVE:
		start_followtape();
		break;
  }
}

void exitState(byte byteRobotState)
{
	RobotState state = (RobotState)byteRobotState;
	switch (state)
	{
	case INITIALISING:
		break;
	case PAST_DOOR:
		break;
	case FOLLOW_TAPE_1: //nothing, really
		break;
	case COLLECT_ITEM_1:
		break;
	case FOLLOW_TAPE_2: //nothing, really
		break;
	case COLLECT_ITEM_2:
		break;
	case COLLECT_ITEM_3:
		break;
	case COLLECT_ITEM_4:
		break;
	case COLLECT_ITEM_5:
		break;
	case COLLECT_ITEM_6:
		break;
	case UP_RAMP:
		break;
	case PAST_RAMP:
		break;
	case IR:
		break;
	case ZIPLINE:
		break;
	case FINISHED:
		break;
	case TEST:
		break;
	case CLAW_ARM_TEST:
		break;
	case DRIVE:
		break;
	case MAIN_MENU:
		break;
	case STATE_MENU:
		break;
	case TAPE_MENU:
		break;
  }
}

//============== nice print/string functions ==============
String byteStateToString(byte byteRobotState) {
	RobotState stringRobotState = (RobotState)byteRobotState;
	switch(stringRobotState) {
	case INITIALISING:
		return("INITIALISING");
	case PAST_DOOR:
		return("PAST DOOR");
	case FOLLOW_TAPE_1:
		return("TAPE 1");
	case COLLECT_ITEM_1:
		return("ITEM 1");
	case FOLLOW_TAPE_2:
		return("TAPE 2");
	case COLLECT_ITEM_2:
		return("ITEM 2");
	case COLLECT_ITEM_3:
		return("ITEM 3");
	case COLLECT_ITEM_4:
		return("ITEM 4");
	case COLLECT_ITEM_5:
		return("ITEM 5");
	case COLLECT_ITEM_6:
		return("ITEM 6");
	case UP_RAMP:
		return("UP RAMP");
	case PAST_RAMP:
		return("PAST RAMP");
	case IR:
		return("IR");
	case ZIPLINE:
		return("ZIPLINE");
	case FINISHED:
		return("FINISHED");
	case TEST:
		return("TESTING");
	case CLAW_ARM_TEST:
		return("CLAW ARM TEST");
	case DRIVE:
		return("TEST DRIVE");
	case MAIN_MENU:
		return("MAIN_MENU");
	case STATE_MENU:
		return("STATE MENU");
	case TAPE_MENU:
		return("TAPE MENU");
	}
}

void LCDStateChangePrint(byte byteRobotState) {
	String stringRobotState=byteStateToString(byteRobotState);
	LCD.clear();
	LCD.home();
	LCD.setCursor(0,0);
	LCD.print("SWITCH:");
	LCD.setCursor(0,1);
	LCD.print(stringRobotState);
}

String bytePlanToString(byte byte_Plan){
	Plan stringPlan = (Plan)byte_Plan;
	switch(stringPlan) {
	case FULL:
		return("FULL");
	case NOT4:
		return("ALL BUT 4");
	case NOT5:
		return("ALL BUT 5");
	case TEST_DRIVE:
		return("TEST DRIVE");
  }
}

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
