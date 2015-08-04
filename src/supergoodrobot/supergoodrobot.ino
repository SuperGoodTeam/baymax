
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
	
	servocontrol::SetBasearmServo(libconstants::kForearmStartPosition);
    servocontrol::SetForearmServo(libconstants::kBasearmStartPosition);
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
        while(!sensorsuite::SideTapeDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }
		
		if (strategies::chosenstrategy != strategies::kTapeBottomOnly){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		break;

    case statemanager::kCollectItemOne:
		
        collectitemone::CollectItemOne();
		
		while(sensorsuite::SideTapeDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }
		
		if (strategies::chosenstrategy != strategies::kCollectItemOne){
			strategymanager::GoToNextState();
        }
        break;

    case statemanager::kTapeTurnLeft:
		oldtime=millis();
        while(!sensorsuite::SideTapeDetect() || millis() - oldtime < libconstants::kTapeTurnLeftImmunityZoneDelay) {
            followlefttape::FollowLeftTapeLoop(); // ends at 2nd side tape
		}
		
		if (strategies::chosenstrategy != strategies::kTapeTurnLeftOnly){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
        break;

    case statemanager::kCollectItemTwo:
        collectitemtwo::CollectItemTwo();
				
		while(sensorsuite::SideTapeRightDetect()) {
            followlefttape::FollowLeftTapeLoop();
        }
		if (strategies::chosenstrategy != strategies::kCollectItemTwo){	
			strategymanager::GoToNextState();
        }

		break;

    case statemanager::kTapeHill: // ends at 3rd sidetape
		oldtime=millis();
		while(!sensorsuite::SideTapeDetect() || millis() - oldtime < libconstants::kTapeHillImmunityZoneDelay) {
		    followhilltape::FollowHillTapeLoop();
		}
		if (strategies::chosenstrategy != strategies::kTapeHill){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		break;

    case statemanager::kCollectItemThree:
    	collectitemthree::CollectItemThree();
				
		while(sensorsuite::SideTapeDetect()) {
            followhilltape::FollowHillTapeLoop();
        }
		if (strategies::chosenstrategy != strategies::kCollectItemThree){
			strategymanager::GoToNextState();
        }

        break;

    case statemanager::kTapeTurnRight:
		while(!sensorsuite::SideTapeDetect()) {
            followrighttape::FollowRightTapeLoop();
		}
		if (strategies::chosenstrategy != strategies::kTapeTurnRight){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
        break;

    case statemanager::kCollectItemFour:
        //collectitemfour::CollectItemFour();
		
		while(!sensorsuite::SideTapeRightDetect()) {
			drivecontrol::FollowTapeLoop(0,0);		
		}
		
		drivecontrol::StopDriveMotors();
		
		while (!sensorsuite::SideTapeDetect()) {
			//drivecontrol::RightTurnDriveMotors(libconstants::kMotorSlowSpeed);
			motor.speed(libconstants::kLeftMotor, -libconstants::kMotorSlowSpeed);
			motor.speed(libconstants::kRightMotor, 0);
		}
		/*
		count=0;
		while(count<=5){
			drivecontrol::FollowTapeLoop(0,0);
			if (sensorsuite::QRDTapeDetect()){
				count++;
			}
			else{
				count=0;
			}
			count=0;
		}*/
		
		/*oldtime=millis();
		
		while (millis() - oldtime < 2000) {
			drivecontrol::FollowTapeLoop(0,0);
		}*/
		
		if (strategies::chosenstrategy != strategies::kCollectItemFour){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }

		break;
		
	case statemanager::kDriveStraightUntilSideIr:
		//while (!sensorsuite::SideIrDetect() || !sensorsuite::FrontSensorDetect()){
		while (!sensorsuite::SideIrDetect()){
			//drivecontrol::StraightDriveMotors(parameters::basespeed);
			followir::FollowIrLoop();
		}
		if (strategies::chosenstrategy != strategies::kFollowIr){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
		break;

    case statemanager::kFollowIr:
		//while (!sensorsuite::SideIrDetect() || !sensorsuite::FrontSensorDetect()){
		oldtime = millis();
		//while (!sensorsuite::SideIrDetect()){
		while(millis() - oldtime < 2300) {
			//followir::FollowIrLoop();
			drivecontrol::StraightDriveMotors(150);
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
		//drive backwards
		/*oldtime=millis();
		while (millis() - oldtime < libconstants::kWaitTurnDelay){
			motor.speed(libconstants::kRightMotor, -libconstants::kMotorSlowSpeed);
			motor.speed(libconstants::kLeftMotor, libconstants::kMotorSlowSpeed);
		}*/
		
		//turn around (time needs to be adjusted?)
		
		//while we don't detect tape in the front QRDs...drive forwards slowly (should we be twitching while we do this?)
		//alternatively, we follow the 10 kHz beacon
		
		drivecontrol::StraightDriveMotors(60);
		delay(500);
		
		while (!sensorsuite::SideTapeRightDetect() && !sensorsuite::SideTapeDetect()){
			drivecontrol::FollowIrLoop(libconstants::kFollowIrSpeedChange, libconstants::kFollowIrTurnBias);	
		}
		
		while(!drivecontrol::LocateTapeTrack(50, 800)){
		
		}
		
		/*
		while((sensorsuite::QRDTapeDetect() && !sensorsuite::SideTapeDetect()) || (sensorsuite::QRDTapeDetect() && !sensorsuite::SideTapeRightDetect())){
			drivecontrol::FollowIrLoop(libconstants::kFollowIrSpeedChange, libconstants::kFollowIrTurnBias);
		}*/

		//wait for the robot to get past the 4th sidetape
		/*oldtime = millis();
		while(millis() - oldtime < libconstants::kWaitPastFourSideTape){
			followrighttape::FollowRightTapeLoop();
		}*/
		
		if (strategies::chosenstrategy != strategies::kTurnAroundAndGoHome){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
		}
		break;
    default:
        break;

    }
}
