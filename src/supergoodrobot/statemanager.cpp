#include <Arduino.h>

#include "menu.h"
#include "statemanager.h"

namespace statemanager {

    RobotState currentstate = kMenu;

    void SwitchState(RobotState nextstate) {

        SetupState(nextstate);

        currentstate = nextstate;

        /*Update as more changes need to be made
          i.e setup/takedown procedures*/
    }

    void SetupState(RobotState nextstate) {

        switch (nextstate) {

        case kMenu:
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
        case kInitializing:
            return "Initializing";
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
        default:
            return "Unknown State";
            break;
        }
    }
}
