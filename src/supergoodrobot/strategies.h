#ifndef STRATEGIES_H_INCLUDED
#define STRATEGIES_H_INCLUDED

namespace strategies {

    enum Strategy {
        kFull,
		kAlternateFull,
        kStartTwo,
        kStartThree,
        kStartFour,
        kStartFive,
        kStartSix,
        kSkipFour,
        kSkipFive,
        kSkipSix,
        kSkipFiveAndSix,
	/*======"States"======*/
        kClawTest,
        kTapeTest,
	kPivotTest,
        kIrTest,
	kTapeBottomOnly,
	kCollectItemOne,
	kTapeTurnLeftOnly,
	kCollectItemTwo,
	kTapeHill,
	kCollectItemThree,
	kTapeTurnRight,
	kCollectItemFour,
	kFollowIr,
	kDriveStraightUntilSideIr,
	kCollectItemFive,
	kCollectItemSix,
	kGrabZipline,
	kDescendZipline,
	kTurnAroundAndGoHome,
	kDriveStraightUp,
    kStrategyMax
    };

    extern Strategy chosenstrategy;

}

#endif
