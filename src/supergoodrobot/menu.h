#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <Arduino.h>

namespace menu {

    enum MainMenu {
	kStrategies,
	kParameters,
	kStart,
	kMainMenuMax
    };
    
    enum Strategy {
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
	kClawTest,
	kTapeTest,
	kIrTest,
	kStrategyMax
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
	kParameterMenu
    };

    extern Menu currentmenu;

    void MainMenuLoop();

    void StrategyMenuLoop();

    void ParameterMenuLoop();

    String MainMenuToString(MainMenu menu);

    String StrategyMenuToString(Strategy strategy);

    String ParameterMenuToString(ParameterMenu menu);

    String MenuToString(Menu menu);

    void IncrementParameterSelection();
}

#endif
