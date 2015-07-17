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
