
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

#include <LiquidCrystal.h>
#include <phys253.h>
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
uint32_t motorswitchtime = millis();
		
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
		motordirection = +1;
		motorswitchtime = millis();
		while(!sensorsuite::QRDTapeDetect()){
			motor.speed(libconstants::kRightMotor, +motordirection*libconstants::kMotorCorrectionSpeed);
			motor.speed(libconstants::kLeftMotor, +motordirection*libconstants::kMotorCorrectionSpeed);
			if (motorswitchtime - millis() > 1000){
				motordirection *= (-1);
				motorswitchtime = millis() - 1000;
			}
		}
		drivecontrol::StopDriveMotors();
		
		oldtime=millis();
        while(!sensorsuite::SideTapeDetect() || millis() - oldtime < 1500) {
            followlefttape::FollowLeftTapeLoop(); // ends at 2nd side tape
		}
		
		if (strategies::chosenstrategy != strategies::kTapeTurnLeftOnly){
			drivecontrol::StopDriveMotors();
			strategymanager::GoToNextState();
        }
		
        break;

    case statemanager::kCollectItemTwo:
        collectitemtwo::CollectItemTwo();
				
		while(sensorsuite::SideTapeDetect()) {
            followlefttape::FollowLeftTapeLoop();
        }
		while(analogRead(libconstants::kRightTapeSensor) < parameters::qrdthreshold && analogRead(libconstants::kLeftTapeSensor) < parameters::qrdthreshold){
			motor.speed(libconstants::kRightMotor, -libconstants::kMotorCorrectionSpeed);
			motor.speed(libconstants::kLeftMotor, +libconstants::kMotorCorrectionSpeed);
		}
		if (strategies::chosenstrategy != strategies::kCollectItemTwo){	
			strategymanager::GoToNextState();
        }

		break;

    case statemanager::kTapeHill: // ends at 3rd sidetape
		oldtime=millis();
		while(!sensorsuite::SideTapeDetect() || millis() - oldtime < 1500) {
		//while(!sensorsuite::SideTapeDetect()) {

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
		
		while(analogRead(libconstants::kRightTapeSensor) < parameters::qrdthreshold && analogRead(libconstants::kLeftTapeSensor) < parameters::qrdthreshold){
			motor.speed(libconstants::kRightMotor, -libconstants::kMotorCorrectionSpeed);
			motor.speed(libconstants::kLeftMotor, +libconstants::kMotorCorrectionSpeed);
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
        collectitemfour::CollectItemFour();
				
		while(sensorsuite::SideTapeDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }

		//extend hook arm up
		
		oldtime=millis();
		while (millis() - oldtime < 3000){
			motor.speed(libconstants::kLeftMotor, -100);
			motor.speed(libconstants::kRightMotor, 80);
		}
		
		if (strategies::chosenstrategy != strategies::kCollectItemFour){
			strategymanager::GoToNextState();
        }

		break;

    case statemanager::kFollowIr:
		while (!sensorsuite::SideIrDetect() || !sensorsuite::FrontSensorDetect){
			followir::FollowIrLoop();
		}
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

    default:
        break;

    }
}
