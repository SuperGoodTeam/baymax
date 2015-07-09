/* ENPH 253 PRELIMINARY CODE
last updated: 070815
version: 0.1

*/

//============== LIBRARIES ==============
#include <phys253.h>
#include <LiquidCrystal.h>
//#include <Servo253.h> 

#include <EEPROMex.h>
#include <EEPROMVar.h>

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
#define CLAW_STATE 2

//DIGITAL IO
//INPUT
#define CLAW_OPEN 4
#define CLAW_CLOSE 5
#define HOOK_ARM_TOUCH_ON 7
#define HOOK_ARM_TOUCH_OFF 8

//OUTPUT
#define HOOK_ARM_RETRACT 15
#define HOOK_ARM_SPRING_UP 14
#define INTAKE_ROLLER_MOTOR 12

//============== DRIVE SETTINGS ==============
//QRD DRIVE

//IR DRIVE

//ARM CONSTANTS

//SERVO POSITIONS
#define BASESERVO_POSITION_1 90//some number
#define FOREARMSERVO_POSITION_1 90//some number
#define BASE_POSITION_1 90//some number
//FLAGS
boolean upRamp=false;

#define KNOB_MAX 1023

//============== STATES ==============
enum RobotState {
  INITIALISING, PAST_DOOR, FOLLOW_TAPE, COLLECT_ITEM, UP_RAMP, PAST_RAMP, IR, ZIPLINE, FINISHED, TEST, SETTINGS, STATE_MENU
};
enum Plan { 
	FULL, NOT4, NOT5, NUM_PLAN //placeholder for lack of len(enum) function, don't delete
};

//SET STATES
RobotState currentState = INITIALISING;
RobotState lastState = INITIALISING;  

Plan currentPlan=FULL;

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
  setForearmServo(FOREARMSERVO_POSITION_1);
  setBasearmServo(BASESERVO_POSITION_1);
  setBaseServo(BASE_POSITION_1);
  //other stuff goes here
}

void loop() {
	switch(currentState) {
	case INITIALISING:
		start_initialising(); //set plan
		break;
	case FOLLOW_TAPE:
		motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
		motor.speed(MOTOR_RIGHT,0);
		while(!startbutton()){
			TapeMenu();
		}
		while (!stopbutton()) {
			readFollowTape();
		}
		break;
   case COLLECT_ITEM:
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
  }
}

//============== SET POSITION FUNCTIONS ==============
void setForearmServo(int angle) {
	RCServo0.write(angle);
}

void setBasearmServo(int angle) {
	RCServo1.write(angle);
}

void setBaseServo(int angle) {
	RCServo2.write(angle);
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
  case FOLLOW_TAPE:
	start_followtape();
	break;
  case COLLECT_ITEM:
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
  case SETTINGS:
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
  case FOLLOW_TAPE: //nothing, really
    break;
  case COLLECT_ITEM:
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
  case SETTINGS:
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
	case FOLLOW_TAPE:
		return("FOLLOW TAPE");
	case COLLECT_ITEM:
		return("COLLECT ITEM");
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
	case SETTINGS:
		return("SETTINGS");
	case STATE_MENU:
		return("STATE MENU");
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
  }
}
