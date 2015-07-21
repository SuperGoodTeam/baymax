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
    const uint8_t kBasearmServo = 0;
    const uint8_t kForearmServo = 1;

    // Motors
    const uint8_t kLeftMotor = 0;
    const uint8_t kRightMotor = 1;
    const uint8_t kPivotarmMotor = 2;
    const uint8_t kClawMotor = 3;
	//const uint8_t kHookarmMotor = 2; 

    // Digital IO
    // IN
    const uint8_t kClawOpenSwitch = 4;
    const uint8_t kItemDetectSwitch = 5;
	const uint8_t kFrontDetectSwitch = 6;
    const uint8_t kHookarmAttachSwitch = 7;
	const uint8_t kHookarmBaseTouchSwitch = 8;

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
	
	const uint8_t kHookarmMotorSpeed = 0;
	
    /*============GEOMETRIC CONSTANTS============*/

    // Servos
    const uint8_t kServoDegreesMax = 180;

    const uint16_t kForearmStartPosition = 123;
    const uint16_t kBasearmStartPosition = 91;
    const uint16_t kPivotarmStartPosition = 0;

    const uint16_t kForearmStartItemOne = 180;
    const uint16_t kBasearmStartItemOne = 180;
    const uint16_t kPivotarmStartItemOne = 0;

    const uint16_t kForearmGrabItemOne = 120;
    const uint16_t kBasearmGrabItemOne = 0;
    const uint16_t kPivotarmGrabItemOne = 105;

    const uint16_t kForearmRetreiveItemOne = 0;
    const uint16_t kBasearmRetreiveItemOne = 0;
    const uint16_t kPivotarmRetreiveItemOne = 180;

    const uint16_t kForearmStartItemTwo = 180;
    const uint16_t kBasearmStartItemTwo = 180;
    const uint16_t kPivotarmStartItemTwo = 0;

    const uint16_t kForearmGrabItemTwo = 85;
    const uint16_t kBasearmGrabItemTwo = 0;
    const uint16_t kPivotarmGrabItemTwo = 90;

    const uint16_t kForearmRetreiveItemTwo = 0;
    const uint16_t kBasearmRetreiveItemTwo = 0;
    const uint16_t kPivotarmRetreiveItemTwo = 180;

    const uint16_t kForearmStartItemThree = 0;
    const uint16_t kBasearmStartItemThree = 0;
    const uint16_t kPivotarmStartItemThree = 0;

    const uint16_t kForearmGrabItemThree = 16;
    const uint16_t kBasearmGrabItemThree = 140;
    const uint16_t kPivotarmGrabItemThree = 105;

    const uint16_t kForearmRetreiveItemThree = 0;
    const uint16_t kBasearmRetreiveItemThree = 0;
    const uint16_t kPivotarmRetreiveItemThree = 0;
	
	const uint16_t kForearmStartItemFour = 0;
    const uint16_t kBasearmStartItemFour = 0;
    const uint16_t kPivotarmStartItemFour = 0;

    const uint16_t kForearmGrabItemFour = 0;
    const uint16_t kBasearmGrabItemFour = 0;
    const uint16_t kPivotarmGrabItemFour = 0;

    const uint16_t kForearmRetreiveItemFour = 0;
    const uint16_t kBasearmRetreiveItemFour = 0;
    const uint16_t kPivotarmRetreiveItemFour = 0;

	const uint16_t kForearmStartItemFive = 0;
    const uint16_t kBasearmStartItemFive = 0;
    const uint16_t kPivotarmStartItemFive = 0;

    const uint16_t kForearmGrabItemFive = 0;
    const uint16_t kBasearmGrabItemFive = 0;
    const uint16_t kPivotarmGrabItemFive = 0;

    const uint16_t kForearmRetreiveItemFive = 0;
    const uint16_t kBasearmRetreiveItemFive = 0;
    const uint16_t kPivotarmRetreiveItemFive = 0;
	
	const uint16_t kForearmStartItemSix = 0;
    const uint16_t kBasearmStartItemSix = 0;
    const uint16_t kPivotarmStartItemSix = 0;

    const uint16_t kForearmGrabItemSix = 0;
    const uint16_t kBasearmGrabItemSix = 0;
    const uint16_t kPivotarmGrabItemSix = 0;

    const uint16_t kForearmRetreiveItemSix = 0;
    const uint16_t kBasearmRetreiveItemSix = 0;
    const uint16_t kPivotarmRetreiveItemSix = 0;
	
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

    const uint16_t kWaitServoTurn = 1000*5; // milliseconds
    const uint16_t kWaitServoDown = 1000*5;  // milliseconds
    const uint16_t kWaitServoUp = 5000*2;   // milliseconds
    const uint16_t kWaitClawGrab = 1500;  // milliseconds
    const uint16_t kLongDelay = 500;      // milliseconds
    const uint16_t kShortDelay = 200;     // milliseconds
}

#endif
