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
#include "libconstants.h"
#include "followbottomtape.h"
#include "followlefttape.h"
#include "menu.h"
#include "pivotservotest.h"
#include "sensorsuite.h"
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

    switch (statemanager::currentstate) {
	
    case statemanager::kMenu:
	switch (menu::currentmenu) {
	    
	case menu::kMainMenu:
	    menu::MainMenuLoop();
	    break;
	    
	case menu::kStrategyMenu:
	    menu::StrategyMenuLoop();
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

    case statemanager::kInitializing:
	break;

    case statemanager::kTapeBottom:
	while (!sensorsuite::SideTapeDetect()) {
	    followbottomtape::FollowBottomTapeLoop();
	}
	
	break;

    case statemanager::kCollectItemOne:
	collectitemone::CollectItemOne();
	break;

    case statemanager::kTapeTurnLeft:
	followlefttape::FollowLeftTapeLoop();
	break;

    case statemanager::kCollectItemTwo:
	break;

    case statemanager::kTapeHill:
	break;

    case statemanager::kCollectItemThree:
	break;

    case statemanager::kTapeTurnRight:
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
