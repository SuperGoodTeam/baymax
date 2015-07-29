#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <Arduino.h>

namespace menu {

    enum MainMenu {
        kStrategies,
        kParameters,
        kStates,
        kStart,
        kMainMenuMax
    };

    enum StrategyMenu {
        kFull,
        kStartTwo,
        kStartThree,
        kStartFour,
        kStartFive,
        kStartSix,
        kSkipFour,
        kSkipFive,
        kSkipSix,
        kSkipFiveAndSix,
        kStrategyMax
    };

    enum StateMenu {
        kClawTest,
        kTapeTest,
        kPivotTest,
        kIrTest,
		kTapeBottom,
        kCollectItemOne,
        kTapeTurnLeft,
        kCollectItemTwo,
        kTapeHill,
        kCollectItemThree,
        kTapeTurnRight,
        kCollectItemFour,
        kFollowIr,
        kCollectItemFive,
        kCollectItemSix,
        kGrabZipline,
        kDescendZipline,
		kTurnAroundAndGoHome,
        kStateMenuMax
    };

    enum ParameterMenu {
        kDisplay,
        kLoad,
        kSave,
        kProportionalGain,
        kDerivativeGain,
        kBaseSpeed,
        kParameterMenuMax
    };

    enum Menu {
        kMainMenu,
        kStrategyMenu,
        kStateMenu,
        kParameterMenu
    };

    extern Menu currentmenu;

    //extern Strategy currentstrategy;

    void MainMenuLoop();

    void StrategyMenuLoop();

    void StateMenuLoop();

    void ParameterMenuLoop();

    String MainMenuToString(MainMenu menu);

    String StrategyMenuToString(StrategyMenu strategy);

    String StateMenuToString(StateMenu menu);

    String ParameterMenuToString(ParameterMenu menu);

    String MenuToString(Menu menu);

    void IncrementParameterSelection();
}

#endif
