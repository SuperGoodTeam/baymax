#ifndef STATEMANAGER_H_INCLUDED
#define STATEMANAGER_H_INCLUDED

#include <Arduino.h>

namespace statemanager {

    enum RobotState {
        kMenu,
        kClawTest,
        kTapeTest,
        kPivotTest,
        kIrTest,
        kInitialising,
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
        kRobotStateMax
    };

    extern RobotState currentstate;

    void SwitchState(RobotState nextstate);

    void SetupState(RobotState nextstate);

    String RobotStateToString(RobotState state);
}

#endif
