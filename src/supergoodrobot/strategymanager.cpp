#include "strategymanager.h"

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>

#include "strategies.h"
#include "statemanager.h"

namespace strategymanager {
	
	int strategyiterator = 0;
	
	int arrFull[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };

	int lenarrFull=sizeof(arrFull) / sizeof(arrFull[0]);

	int arrStartTwo[] = { statemanager::kTapeBottom, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline }; 
	
	int lenarrStartTwo=sizeof(arrStartTwo) / sizeof(arrStartTwo[0]);
	
	int arrStartThree[] = { statemanager::kTapeBottom, statemanager::kTapeTurnLeft, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrStartThree=sizeof(arrStartThree) / sizeof(arrStartThree[0]);
	
	int arrStartFour[] = { statemanager::kTapeBottom, statemanager::kTapeTurnLeft, statemanager::kTapeHill, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrStartFour=sizeof(arrStartFour) / sizeof(arrStartFour[0]);
	
	int arrStartFive[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrStartFive=sizeof(arrStartFive) / sizeof(arrStartFive[0]);
	
	int arrStartSix[] = { statemanager::kTapeBottom, statemanager::kTapeTurnLeft, statemanager::kTapeHill,  statemanager::kTapeTurnRight, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrStartSix=sizeof(arrStartSix) / sizeof(arrStartSix[0]);
	
	int arrSkipFour[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrSkipFour=sizeof(arrSkipFour) / sizeof(arrSkipFour[0]);
	
	int arrSkipFive[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrSkipFive=sizeof(arrSkipFive) / sizeof(arrSkipFive[0]);
	
	int arrSkipSix[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kCollectItemFive, statemanager::kFollowIr, statemanager::kCollectItemSix, statemanager::kGrabZipline, statemanager::kDescendZipline };
	
	int lenarrSkipSix=sizeof(arrSkipSix) / sizeof(arrSkipSix[0]);
	
	int arrSkipFiveAndSix[] = { statemanager::kTapeBottom, statemanager::kCollectItemOne, statemanager::kTapeTurnLeft, statemanager::kCollectItemTwo, statemanager::kTapeHill, statemanager::kCollectItemThree, statemanager::kTapeTurnRight, statemanager::kCollectItemFour, statemanager::kFollowIr, statemanager::kGrabZipline, statemanager::kDescendZipline };

	int lenarrSkipFiveAndSix=sizeof(arrSkipFiveAndSix) / sizeof(arrSkipFiveAndSix[0]);
	
    void GoToNextState() {
		switch(strategies::chosenstrategy){
			case strategies::kFull: //we could use a map here, but that seems like more effort than it's worth
				if (strategyiterator < lenarrFull){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrFull[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kStartTwo:
				if (strategyiterator < lenarrStartTwo){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrStartTwo[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kStartThree:
				if (strategyiterator < lenarrStartThree){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrStartThree[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kStartFour:
				if (strategyiterator < lenarrStartFour){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrStartFour[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kStartFive:
				if (strategyiterator < lenarrStartFive){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrStartFive[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kStartSix:
				if (strategyiterator < lenarrStartSix){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrStartSix[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kSkipFour:
				if (strategyiterator < lenarrSkipFour){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrSkipFour[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kSkipFive:
				if (strategyiterator < lenarrSkipFive){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrSkipFive[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kSkipSix:
				if (strategyiterator < lenarrSkipSix){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrSkipSix[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
			case strategies::kSkipFiveAndSix:
				if (strategyiterator < lenarrSkipFiveAndSix){
					statemanager::SwitchState(static_cast<statemanager::RobotState>(arrSkipFiveAndSix[strategyiterator]));
				}
				else {
					EndStrategy();
				}
				break;
				
			/*======"States"======*/
			case strategies::kClawTest:
				statemanager::SwitchState(statemanager::kClawTest);
				break;
			case strategies::kTapeTest:
				statemanager::SwitchState(statemanager::kTapeTest);
				break;
			case strategies::kPivotTest:
				statemanager::SwitchState(statemanager::kPivotTest);
				break;
			case strategies::kIrTest:
				statemanager::SwitchState(statemanager::kIrTest);
				break;
			case strategies::kTapeBottomOnly:
				statemanager::SwitchState(statemanager::kTapeBottom);
				break;
			case strategies::kCollectItemOne:
				statemanager::SwitchState(statemanager::kCollectItemOne);
				break;
			case strategies::kTapeTurnLeftOnly:
				statemanager::SwitchState(statemanager::kTapeTurnLeft);
				break;
			case strategies::kCollectItemTwo:
				statemanager::SwitchState(statemanager::kCollectItemTwo);
				break;
			case strategies::kTapeHill:
				statemanager::SwitchState(statemanager::kTapeHill);
				break;
			case strategies::kCollectItemThree:
				statemanager::SwitchState(statemanager::kCollectItemThree);
				break;
			case strategies::kTapeTurnRight:
				statemanager::SwitchState(statemanager::kTapeTurnRight);
				break;
			case strategies::kCollectItemFour:
				statemanager::SwitchState(statemanager::kCollectItemFour);
				break;
			case strategies::kFollowIr:
				statemanager::SwitchState(statemanager::kFollowIr);
				break;
			case strategies::kCollectItemFive:
				statemanager::SwitchState(statemanager::kCollectItemFive);
				break;
			case strategies::kCollectItemSix:
				statemanager::SwitchState(statemanager::kCollectItemSix);
				break;
			case strategies::kGrabZipline:
				statemanager::SwitchState(statemanager::kGrabZipline);
				break;
			case strategies::kDescendZipline:
				statemanager::SwitchState(statemanager::kDescendZipline);
				break;
			default:
				break;
		}
		strategyiterator++;
    }
	
	void EndStrategy(){
		strategyiterator=0;
		statemanager::SwitchState(statemanager::kMenu);
	}
}
