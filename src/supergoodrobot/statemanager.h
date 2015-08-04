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
		kDriveStraightUntilSideIr,
        kCollectItemFive,
        kCollectItemSix,
        kGrabZipline,
        kDescendZipline,
		kTurnAroundAndGoHome,
		kDriveStraightUp,
        kRobotStateMax
    };

    extern RobotState currentstate;

    void SwitchState(RobotState nextstate);

    void SetupState(RobotState nextstate);

    String RobotStateToString(RobotState state);
}

#endif
