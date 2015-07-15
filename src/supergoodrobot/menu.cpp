#include "menu.h"

#include <Arduino.h>
#include <EEPROMex.h>
#include <EEPROMVar.h>
#include <LiquidCrystal.h>


#include <phys253.h>

#include "libconstants.h"
#include "parameters.h"
#include "statemanager.h"
#include "strategies.h"

namespace menu {

    MainMenu currentmainselection = kStrategies;
    StrategyMenu currentstrategyselection = kFull;
    StateMenu currentstateselection = kClawTest;
    ParameterMenu currentparameterselection = kDisplay;

    Menu currentmenu = kMainMenu;

    int16_t loadknob = 500;
    int16_t saveknob = 500;

    void MainMenuLoop() {
        delay(libconstants::kLongDelay);
        LCD.clear();

        currentmainselection = static_cast<MainMenu> (map(knob(6), 0, libconstants::kKnobMax, 0, kMainMenuMax-1));

        LCD.print("Menu: " + MainMenuToString(currentmainselection));
        if (startbutton()) {
            switch (currentmainselection) {
            case kStrategies:
                currentmenu = kStrategyMenu;
                break;
            case kStates:
                currentmenu = kStateMenu;
                break;
            case kParameters:
                currentmenu = kParameterMenu;
                break;
            case kStart:
                currentmenu = kMainMenu;
                statemanager::SwitchState(statemanager::kInitializing);
                break;
            }
        }
    }

    void StrategyMenuLoop() {
        delay(libconstants::kLongDelay);
        LCD.clear();

        strategies::chosenstrategy = static_cast<strategies::Strategy> (map(knob(6), 0, libconstants::kKnobMax, 0, kStrategyMax-1));
        currentstrategyselection = static_cast<StrategyMenu> (map(knob(6), 0, libconstants::kKnobMax, 0, kStrategyMax-1));

        LCD.print("Strategy:");
        LCD.setCursor(0, 1);
        LCD.print(StrategyMenuToString(currentstrategyselection));
    }

    void StateMenuLoop() {
        delay(libconstants::kLongDelay);
        LCD.clear();

        currentstateselection = static_cast<StateMenu> (map(knob(6), 0, libconstants::kKnobMax, 0, kStateMenuMax-1));

        strategies::chosenstrategy = static_cast<strategies::Strategy> (static_cast<int16_t> (currentstateselection) + 10);

        LCD.print("State:");
        LCD.setCursor(0, 1);
        LCD.print(StateMenuToString(currentstateselection));
    }

    //TODO:
    void ParameterMenuLoop() {

        delay(libconstants::kLongDelay);
        LCD.clear();

        if (startbutton()) {
            IncrementParameterSelection();
            if (loadknob == 0) {
                LCD.print("Loading Now!");
                parameters::proportionalgain = EEPROM.read(0);
                parameters::derivativegain = EEPROM.read(1);
                parameters::basespeed = EEPROM.read(2);
                loadknob = -1;
            }
            if (saveknob == 0) {
                LCD.print("Saving Now!");
                EEPROM.write(0, parameters::proportionalgain);
                EEPROM.write(1, parameters::derivativegain);
                EEPROM.write(2, parameters::basespeed);
                saveknob = -1;
            }

        }

        switch (currentparameterselection) {
        case kDisplay:
            LCD.print("L: " + String(analogRead(libconstants::kLeftTapeSensor)));
            LCD.setCursor(8,0);
            LCD.print("R: " + String(analogRead(libconstants::kRightTapeSensor)));
            break;
        case kLoad:
            loadknob = knob(6);
            LCD.print("Load? 6: " + String(knob(6)));
            LCD.setCursor(0,1);
            LCD.print("p:" + String(EEPROM.read(0)));
            LCD.print("d:" + String(EEPROM.read(1)));
            LCD.print("s:" + String(EEPROM.read(2)));
            break;
        case kSave:
            saveknob = knob(6);
            LCD.print("Save? 6: " + String(knob(6)));
            LCD.setCursor(0,1);
            LCD.print("p:" + String(parameters::proportionalgain));
            LCD.print("d:" + String(parameters::derivativegain));
            LCD.print("s:" + String(parameters::basespeed));
            break;
        case kProportionalGain:
            parameters::proportionalgain = knob(6)/10;
            LCD.print("kP: 6: " + String(parameters::proportionalgain));
            break;
        case kDerivativeGain:
            parameters::derivativegain = knob(6)/5;
            LCD.print("kD: 6: " + String(parameters::derivativegain));
            break;
        case kBaseSpeed:
            parameters::basespeed = knob(6)/5;
            LCD.print("bSpeed: 6: " + String(parameters::derivativegain));
            break;
        default:
            break;
        }
    }

    String MainMenuToString(MainMenu menu) {
        switch (menu) {
        case kStrategies:
            return "Strategies";
            break;
        case kParameters:
            return "Parameters";
            break;
        case kStates:
            return "DEB States";
            break;
        case kStart:
            return "Start!";
            break;
        default:
            return "OoBMenu";
            break;
        }
    }

    String StrategyMenuToString(StrategyMenu strategy) {

        switch (strategy) {
        case kFull:
            return "Full";
            break;
        case kStartTwo:
            return "Start Second";
            break;
        case kStartThree:
            return "Start Third";
            break;
        case kStartFour:
            return "Start Fourth";
            break;
        case kStartFive:
            return "Start Fifth";
            break;
        case kStartSix:
            return "Start Sixth";
            break;
        case kSkipFour:
            return "Skip Fourth";
            break;
        case kSkipFive:
            return "Skip Fifth";
            break;
        case kSkipSix:
            return "Skip Sixth";
            break;
        case kSkipFiveAndSix:
            return "Skip Last Two";
            break;
        default:
            return "OoBMenu";
            break;
        }
    }

    String StateMenuToString(StateMenu state) {

        switch (state) {
        case kClawTest:
            return "Claw Test";
            break;
        case kTapeTest:
            return "Tape Test";
            break;
        case kPivotTest:
            return "Pivot Test";
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
            return "OutoBounds State";
            break;
        }
    }

    //TODO? Possibly unneeded:
    String ParameterMenuToString(ParameterMenu menu) {
        switch (menu) {
        case kDisplay:
            return "";
            break;
        case kLoad:
            return "";
            break;
        case kSave:
            return "";
            break;
        case kProportionalGain:
            return "";
            break;
        case kDerivativeGain:
            return "";
            break;
        case kBaseSpeed:
            return "";
            break;
        default:
            return "OoBMenu";
            break;
        }
    }

    String MenuToString(Menu menu) {
        switch (menu) {
        case kMainMenu:
            return "Main Menu";
            break;
        case kStrategyMenu:
            return "Strategy";
            break;
        case kStateMenu:
            return "State";
            break;
        case kParameterMenu:
            return "Parameters";
            break;
        default:
            return "OoBMenu";
            break;
        }
    }

    void IncrementParameterSelection() {
        switch(currentparameterselection) {
        case kDisplay:
            currentparameterselection = kLoad;
            break;
        case kLoad:
            currentparameterselection = kSave;
            break;
        case kSave:
            currentparameterselection = kProportionalGain;
            break;
        case kProportionalGain:
            currentparameterselection = kDerivativeGain;
            break;
        case kDerivativeGain:
            currentparameterselection = kBaseSpeed;
            break;
        case kBaseSpeed:
            currentparameterselection = kSave;
            break;
        default:
            currentparameterselection = kDisplay;
            break;
        }
    }
}
