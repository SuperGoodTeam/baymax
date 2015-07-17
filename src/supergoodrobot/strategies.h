#ifndef STRATEGIES_H_INCLUDED
#define STRATEGIES_H_INCLUDED

namespace strategies {

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
	kCollectItemFive,
	kCollectItemSix,
	kGrabZipline,
	kDescendZipline,
        kStrategyMax
    };

    extern Strategy chosenstrategy;

}

#endif
