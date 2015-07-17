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

#include "libconstants.h"
#include "followbottomtape.h"
#include "followlefttape.h"
#include "initialise.h"
#include "menu.h"
#include "pivotservotest.h"
#include "sensorsuite.h"
#include "strategies.h" //temp
#include "strategymanager.h"

#include "statemanager.h"
#include "tapefollowtest.h"

void setup() {

    #include <phys253setup.txt>
    Serial.begin(9600);

    // Set Digital pins 8-15 to input
    DDRB = DDRB | B11111111;
}

void loop() {
    if(stopbutton()) {
        statemanager::SwitchState(statemanager::kMenu);
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
	break;

    case statemanager::kInitialising:
        initialise::SetupStrategy();
        break;

    case statemanager::kTapeBottom:
        while(!sensorsuite::SideTapeDetect()) {
            followbottomtape::FollowBottomTapeLoop();
        }
		strategymanager::GoToNextState();
        break;

    case statemanager::kCollectItemOne:
        collectitemone::CollectItemOne();
        break;

    case statemanager::kTapeTurnLeft:
        followlefttape::FollowLeftTapeLoop(); // where does this end? 2nd sidetape?
        break;

    case statemanager::kCollectItemTwo:
        collectitemtwo::CollectItemTwo();
		break;

    case statemanager::kTapeHill: // where does this start/end? 3rd sidetape? not quite it
        break;

    case statemanager::kCollectItemThree:
    		collectitemthree::CollectItemThree();
        break;

    case statemanager::kTapeTurnRight: // how can we tell when this happens?
        break;

    case statemanager::kCollectItemFour:
        break;

    case statemanager::kFollowIr:
        break;

    case statemanager::kCollectItemFive:
        break;

    case statemanager::kCollectItemSix:
        break;

    case statemanager::kGrabZipline:
        break;

    case statemanager::kDescendZipline:
        break;

    default:
        break;

    }
}
