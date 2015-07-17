#ifndef LIBCONSTANTS_H_INCLUDED
#define LIBCONSTANTS_H_INCLUDED

#include <Arduino.h>

namespace libconstants {

    /*============PINOUT============*/
    // Analog In
    const uint8_t kLeftTapeSensor= 0;
    const uint8_t kRightTapeSensor = 1;
    const uint8_t kLeftFrontIr = 2;
    const uint8_t kRightFrontIr = 3;
    const uint8_t kSideIr = 4;
    const uint8_t kSideTapeSensor = 5;
    const uint8_t kMotorBaseSensor = 7;

    // Servos
    const uint8_t kForearmServo = 0;
    const uint8_t kBasearmServo = 1;

    // Motors
    const uint8_t kLeftMotor = 0;
    const uint8_t kRightMotor = 1;
    const uint8_t kPivotarmMotor = 2;
    const uint8_t kClawMotor = 3;

    // Digital IO
    // IN
    const uint8_t kClawOpenSwitch = 4;
    const uint8_t kItemDetectSwitch = 5;
    const uint8_t kHookarmTouchSwitch = 7;

    //OUT
    const uint8_t kHookarmRelease = 14;
    const uint8_t kHookarmRaiseToggle = 15;

    /*============SPEED & TURNBIAS CONSTANTS============*/

	const uint8_t kBottomTapeSpeedChange = 0;
	const uint8_t kBottomTapeTurnBias = 0;
	
	const uint8_t kLeftTapeSpeedChange = 0;
	const uint8_t kLeftTapeTurnBias = 0;
	
	const uint8_t kHillTapeSpeedChange = 0;
	const uint8_t kHillTapeTurnBias = 0;
	
	const uint8_t kFollowIrSpeedChange = 0;
	const uint8_t kFollowIrTurnBias = 0;
	
	const uint8_t kRightTapeSpeedChange = 0;
	const uint8_t kRightTapeTurnBias = 0;
	
    /*============GEOMETRIC CONSTANTS============*/

    // Servos
    const uint8_t kServoDegreesMax = 180;

    const uint16_t kBasearmStartPosition = 90;
    const uint16_t kForearmStartPosition = 90;
    const uint16_t kPivotarmStartPosition = 90;

    const uint16_t kBasearmStartItemOne = 90;
    const uint16_t kForearmStartItemOne = 90;
    const uint16_t kPivotarmStartItemOne = 90;

    const uint16_t kBasearmGrabItemOne = 40;
    const uint16_t kForearmGrabItemOne = 155;
    const uint16_t kPivotarmGrabItemOne = 90;

    const uint16_t kBasearmRetreiveItemOne = 90;
    const uint16_t kForearmRetreiveItemOne = 90;
    const uint16_t kPivotarmRetreiveItemOne = 90;

    const uint16_t kBasearmStartItemTwo = 90;
    const uint16_t kForearmStartItemTwo = 90;
    const uint16_t kPivotarmStartItemTwo = 90;

    const uint16_t kBasearmGrabItemTwo = 85;
    const uint16_t kForearmGrabItemTwo = 180;
    const uint16_t kPivotarmGrabItemTwo = 90;

    const uint16_t kBasearmRetreiveItemTwo = 90;
    const uint16_t kForearmRetreiveItemTwo = 90;
    const uint16_t kPivotarmRetreiveItemTwo = 90;

    const uint16_t kBasearmStartItemThree = 90;
    const uint16_t kForearmStartItemThree = 90;
    const uint16_t kPivotarmStartItemThree = 90;

    const uint16_t kBasearmGrabItemThree = 16;
    const uint16_t kForearmGrabItemThree = 140;
    const uint16_t kPivotarmGrabItemThree = 90;

    const uint16_t kBasearmRetreiveItemThree = 90;
    const uint16_t kForearmRetreiveItemThree = 90;
    const uint16_t kPivotarmRetreiveItemThree = 90;
	
	const uint16_t kBasearmStartItemFour = 90;
    const uint16_t kForearmStartItemFour = 90;
    const uint16_t kPivotarmStartItemFour = 90;

    const uint16_t kBasearmGrabItemFour = 90;
    const uint16_t kForearmGrabItemFour = 90;
    const uint16_t kPivotarmGrabItemFour = 90;

    const uint16_t kBasearmRetreiveItemFour = 90;
    const uint16_t kForearmRetreiveItemFour = 90;
    const uint16_t kPivotarmRetreiveItemFour = 90;

	const uint16_t kBasearmStartItemFive = 90;
    const uint16_t kForearmStartItemFive = 90;
    const uint16_t kPivotarmStartItemFive = 90;

    const uint16_t kBasearmGrabItemFive = 90;
    const uint16_t kForearmGrabItemFive = 90;
    const uint16_t kPivotarmGrabItemFive = 90;

    const uint16_t kBasearmRetreiveItemFive = 90;
    const uint16_t kForearmRetreiveItemFive = 90;
    const uint16_t kPivotarmRetreiveItemFive = 90;
	
	const uint16_t kBasearmStartItemSix = 90;
    const uint16_t kForearmStartItemSix = 90;
    const uint16_t kPivotarmStartItemSix = 90;

    const uint16_t kBasearmGrabItemSix = 90;
    const uint16_t kForearmGrabItemSix = 90;
    const uint16_t kPivotarmGrabItemSix = 90;

    const uint16_t kBasearmRetreiveItemSix = 90;
    const uint16_t kForearmRetreiveItemSix = 90;
    const uint16_t kPivotarmRetreiveItemSix = 90;
	
    const int16_t kPivotarmSpeed = 128;

    // Claw
    const int16_t kClawSpeed = 90;

	// Ir
	const int16_t kIrScalingFactor = 0.5;
	
    // Arduino Board
    const uint16_t kKnobMax = 1023;

    // Custom Servo
    const uint16_t kPivotArmForeward = 768;
    const uint16_t kPivotArmBackward = 256;
    const float kPivotReadingPerDegree = 2.8444444; // degree per analog read

    /*============TIME CONSTANTS============*/

    const uint16_t kWaitServoTurn = 1000; // milliseconds
    const uint16_t kWaitServoDown = 500;  // milliseconds
    const uint16_t kWaitServoUp = 5000;   // milliseconds
    const uint16_t kWaitClawGrab = 1500;  // milliseconds
    const uint16_t kLongDelay = 500;      // milliseconds
    const uint16_t kShortDelay = 200;     // milliseconds
}

#endif
