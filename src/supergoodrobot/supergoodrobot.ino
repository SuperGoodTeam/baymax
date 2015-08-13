
/* ENPH 253 PRELIMINARY CODE
   last updated: 14/07/15
   version 0.3
*/
/*============DEBUG============*/
#define DEBUG

#ifdef DEBUG
#define D(x) x
#else
#define D(x)
#endif

/*============LIBRARIES============*/

#include <phys253.h>
#include <LiquidCrystal.h>
#include <avr/interrupt.h>

#include <EEPROMex.h>
#include <EEPROMVar.h>

#include "clawarmtest.h"

#include "collectitemone.h"
#include "collectitemtwo.h"
#include "collectitemthree.h"
#include "collectitemfour.h"
#include "collectitemfive.h"
#include "collectitemsix.h"
#include "drivecontrol.h"

#include "libconstants.h"
#include "followbottomtape.h"
#include "followlefttape.h"
#include "followhilltape.h"
#include "followrighttape.h"
#include "followir.h"
#include "initialise.h"
#include "irtest.h"
#include "menu.h"
#include "parameters.h"
#include "pivotservotest.h"
#include "sensorsuite.h"
#include "servocontrol.h"
#include "strategies.h" //temp
#include "strategymanager.h"

#include "statemanager.h"
#include "tapefollowtest.h"

uint32_t oldtime = 0;
uint8_t motordirection = +1;
uint32_t motorswitchtime = 0;
uint8_t count = 0;
		
void setup() {

    #include <phys253setup.txt>
    Serial.begin(9600);

    // Set Digital pins 8-15 to input
    DDRB = DDRB | B11111111;
	
	servocontrol::SetBasearmServo(libconstants::kBasearmStartPosition);
    servocontrol::SetForearmServo(libconstants::kForearmStartPosition);
    servocontrol::SetPivotarmServo(libconstants::kPivotarmStartPosition);
	
}

void loop() {
    if(stopbutton()) {
        statemanager::SwitchState(statemanager::kMenu);
		strategymanager::strategyiterator=0;
    }
    
    D(Serial.println((int) strategies::chosenstrategy);)

    switch (statemanager::currentstate) {

    case statemanager::kMenu:
        switch (menu::currentmenu) {

        case menu::kMainMenu:
            menu::MainMenuLoop();
            break;

        case menu::kStrategyMenu:
            menu::StrategyMenuLoop();
            break;

		case menu::kStateMenu:
			menu::StateMenuLoop();
			break;

        case menu::kParameterMenu:
            menu::ParameterMenuLoop();
            break;
        }

        break;

    case statemanager::kClawTest:
        clawarmtest::ClawArmTestLoop();
        break;

    case statemanager::kTapeTest:
        tapefollowtest::TapeFollowTestLoop();
        break;

    case statemanager::kPivotTest:
        pivotservotest::PivotServoTestLoop();
        break;
		
    case statemanager::kIrTest:
		irtest::IrTestLoop();
		break;

    case statemanager::kInitialising:
        initialise::SetupStrategy();
        break;

    case statemanager::kTapeBottom:
        while(!sensorsuite::SideTapeRightDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }
		
		if (strategies::chosenstrategy != strategies::kTapeBottomOnly){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		break;

    case statemanager::kCollectItemOne:
        collectitemone::CollectItemOne();
		
		while(!drivecontrol::LocateTapeLeftTrack(50, 800)){
		
		}
		
		while(sensorsuite::SideTapeRightDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }
		
		if (strategies::chosenstrategy != strategies::kCollectItemOne){
			strategymanager::GoToNextState();
        }
        break;

    case statemanager::kTapeTurnLeft:
		oldtime=millis();
        while(!sensorsuite::SideTapeRightDetect() || millis() - oldtime < libconstants::kTapeTurnLeftImmunityZoneDelay) {
            followlefttape::FollowLeftTapeLoop(); // ends at 2nd side tape
		}
		
		if (strategies::chosenstrategy != strategies::kTapeTurnLeftOnly){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
        break;

    case statemanager::kCollectItemTwo:
        collectitemtwo::CollectItemTwo();
		
		while(!drivecontrol::LocateTapeRightTrack(50, 800)){
		
		}

		while(sensorsuite::SideTapeRightDetect()) {
            followlefttape::FollowLeftTapeLoop();
        }
		
		if (strategies::chosenstrategy != strategies::kCollectItemTwo){	
			strategymanager::GoToNextState();
        }

		break;

    case statemanager::kTapeHill: // ends at 3rd sidetape
		oldtime=millis();
		while(!sensorsuite::SideTapeRightDetect() || millis() - oldtime < libconstants::kTapeHillImmunityZoneDelay) {
		    followhilltape::FollowHillTapeLoop();
		}
		if (strategies::chosenstrategy != strategies::kTapeHill){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		break;

    case statemanager::kCollectItemThree:
    	collectitemthree::CollectItemThree();

		while(!drivecontrol::LocateTapeRightTrack(50, 800)){
		
		}

		while(sensorsuite::SideTapeRightDetect()) {
            followhilltape::FollowHillTapeLoop();
        }

		if (strategies::chosenstrategy != strategies::kCollectItemThree){
			strategymanager::GoToNextState();
        }

        break;

    case statemanager::kTapeTurnRight:
		motor.speed(libconstants::kRightMotor, 140);
		motor.speed(libconstants::kLeftMotor, -75);
		delay(4500);
		
		while(!drivecontrol::LocateTapeLeftTrack(50, 800)){
		
		}

		while(!sensorsuite::SideTapeRightDetect()) {
            followrighttape::FollowRightTapeLoop();
		}
		if (strategies::chosenstrategy != strategies::kTapeTurnRight){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
        break;

    case statemanager::kCollectItemFour:
		
		parameters::proportionalgain = 20;
		parameters::derivativegain = 100;
		parameters::basespeed = 100;
				
		while(!sensorsuite::SideTapeRightDetect()) {
			drivecontrol::FollowTapeLoop(0,0);		
		}
		
		drivecontrol::StopDriveMotors();
		
		while (!sensorsuite::SideTapeDetect()) {
			motor.speed(libconstants::kLeftMotor, -libconstants::kMotorSlowSpeed);
			motor.speed(libconstants::kRightMotor, 0);
		}
		
		motor.speed(libconstants::kRightMotor, parameters::basespeed+10);
		motor.speed(libconstants::kLeftMotor, -parameters::basespeed);

		delay(2500);
		drivecontrol::StopDriveMotors();
				
		if (strategies::chosenstrategy != strategies::kCollectItemFour){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }

		break;
		
	case statemanager::kDriveStraightUntilSideIr:
		oldtime = millis();
		while (!sensorsuite::SideIrDetect() && millis() - oldtime < libconstants::kWaitFindFive){
			drivecontrol::FollowIrLoop(0,0);
		}
		
		if (strategies::chosenstrategy != strategies::kFollowIr){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
		break;

    case statemanager::kFollowIr:
		oldtime = millis();
		while(millis() - oldtime < 4000) { //2300
			followir::FollowIrLoop();
		}
		drivecontrol::StopDriveMotors();
		
		drivecontrol::LeftTurnDriveMotors(libconstants::kMotorTurnSpeed);
		delay(libconstants::kWaitTurnDelay);
		drivecontrol::StopDriveMotors(); //stop turning
		
		if (strategies::chosenstrategy != strategies::kFollowIr){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
        break;

    case statemanager::kCollectItemFive:
        collectitemfive::CollectItemFive();
		
		if (strategies::chosenstrategy != strategies::kCollectItemFive){
			strategymanager::GoToNextState();
        }

        break;

    case statemanager::kCollectItemSix:
        collectitemsix::CollectItemSix();
		
		if (strategies::chosenstrategy != strategies::kCollectItemSix){
			strategymanager::GoToNextState();
        }
		
        break;

    case statemanager::kGrabZipline: //to pull up zipline
		/*while (!sensorsuite::HookarmAttachDetect){
			LCD.clear();
			LCD.print("Haven't grabbed zipline!");
		}
		LCD.clear();
		LCD.print("Grabbed zipline!");
		if (strategies::chosenstrategy != strategies::kGrabZipline){
			strategymanager::GoToNextState();
		}*/
        break;

    case statemanager::kDescendZipline:
		/*while (!sensorsuite::HookarmBaseTouchDetect){
				//pull motor up
				LCD.clear();
				LCD.print("Pulling up zipline");
				motor.speed(libconstants::kHookarmMotor, libconstants::kHookarmMotorSpeed);
			}
		LCD.clear();
		LCD.print("Ziplining down");
		motor.speed(libconstants::kHookarmMotor, 0);
		
		if (strategies::chosenstrategy != strategies::kGrabZipline){
			strategymanager::GoToNextState();
		}*/
        break;
		
	case statemanager::kDriveStraightUp:
		oldtime = millis();
		while (millis() - oldtime < libconstants::kTimeToGetUp){
			drivecontrol::FollowTapeLoop(0,0); //??
		}
		
		if (strategies::chosenstrategy != strategies::kDriveStraightUp){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		break;

	case statemanager::kTurnAroundAndGoHome:
		oldtime = millis();
		while (millis() - oldtime < 2000){
			drivecontrol::StraightDriveMotors(parameters::basespeed);
		}
		
		while(!drivecontrol::LocateTapeLeftTrack(50, 800)){
		
		}
		
		if (strategies::chosenstrategy != strategies::kTurnAroundAndGoHome){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
		}
		break;
		
	case statemanager::kReturnHome:
		drivecontrol::LeftTurnDriveMotors(libconstants::kMotorTurnSpeed);
		delay(libconstants::kWaitTurnDelay);
		drivecontrol::StopDriveMotors(); //stop turning
		
		while(!drivecontrol::LocateTapeLeftTrack(50, 800)){
		
		}

		while(!stopbutton) {
			drivecontrol::FollowTapeLoop(0,0);
		}
		if (strategies::chosenstrategy != strategies::kReturnHome){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
		}
		break;
    default:
        break;

    }
}
