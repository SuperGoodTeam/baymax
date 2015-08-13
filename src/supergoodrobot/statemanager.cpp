#include "statemanager.h"

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>

#include "drivecontrol.h"
#include "menu.h"

namespace statemanager {

    RobotState currentstate = kMenu;

    void SwitchState(RobotState nextstate) {

        SetupState(nextstate);
		LCD.clear();
		LCD.print("SWITCH:");
		LCD.setCursor(0, 1);
		LCD.print(RobotStateToString(nextstate));
		delay(500); //temp
        currentstate = nextstate;

        /*Update as more changes need to be made
          i.e setup/takedown procedures*/
    }

    void SetupState(RobotState nextstate) {

        switch (nextstate) {

        case kMenu:
	    drivecontrol::StopDriveMotors();
            menu::currentmenu = menu::kMainMenu;
            break;

        default:
            break;
        }
    }

    String RobotStateToString(RobotState state) {

        switch (state) {
        case kMenu:
            return "Menu";
            break;
        case kClawTest:
            return "Claw Test";
            break;
        case kTapeTest:
            return "Tape Test";
            break;
        case kPivotTest:
            return "Pivot Test";
            break;
        case kIrTest:
            return "IR Test";
            break;
        case kInitialising:
            return "Initialising";
            break;
        case kTapeBottom:
            return "Tape Bottom";
            break;
        case kCollectItemOne:
            return "Collect Item 1";
            break;
        case kTapeTurnLeft:
            return "Tape Left Turn";
            break;
        case kCollectItemTwo:
            return "Collect Item 2";
            break;
        case kTapeHill:
            return "Tape Hill";
            break;
        case kCollectItemThree:
            return "Collect Item 3";
            break;
        case kTapeTurnRight:
            return "Tape Right Turn";
            break;
        case kCollectItemFour:
            return "Collect Item 4";
            break;
        case kFollowIr:
            return "Follow IR";
            break;
		case kDriveStraightUntilSideIr:
			return "Drive until side IR";
			break;
        case kCollectItemFive:
            return "Collect Item 5";
            break;
        case kCollectItemSix:
            return "Collect Item 6";
            break;
        case kGrabZipline:
            return "Grabbing Zipline";
            break;
        case kDescendZipline:
            return "Exiting Course";
            break;
		case kTurnAroundAndGoHome:
			return "Turning around and going home";
			break;
		case kDriveStraightUp:
			return "Driving straight up";
			break;
		case kReturnHome:
			return "Returning home";
			break;
        default:
            return "Unknown State";
            break;
        }
    }
}
