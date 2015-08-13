#ifndef LIBCONSTANTS_H_INCLUDED
#define LIBCONSTANTS_H_INCLUDED

#include <Arduino.h>

namespace libconstants {

    /*============PINOUT============*/
    // Analog In
    const uint8_t kLeftTapeSensor = 0;
    const uint8_t kRightTapeSensor = 1;
    const uint8_t kLeftFrontIr = 2;
    const uint8_t kRightFrontIr = 3;
    const uint8_t kSideIr = 4;
    const uint8_t kSideTapeSensor = 5;
    const uint8_t kSideTapeRightSensor = 7;
	//const uint8_t kMotorBaseSensor = 7;

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
	
	const uint8_t kMotorCorrectionSpeed = 20;
	
	const uint8_t kMotorSlowSpeed = 60;
	
	const uint8_t kMotorTurnSpeed = 150;
	
    /*============GEOMETRIC CONSTANTS============*/

    // Servos
    const uint8_t kServoDegreesMax = 180;

    const uint16_t kForearmStartPosition = 180;
    const uint16_t kBasearmStartPosition = 40;
    const uint16_t kPivotarmStartPosition = 45;

    const uint16_t kForearmStartItemOne = 180;
    const uint16_t kBasearmStartItemOne = 180;
    const uint16_t kPivotarmStartItemOne = 130;

    const uint16_t kForearmGrabItemOne = 150;
    const uint16_t kBasearmGrabItemOne = 40;
    const uint16_t kPivotarmGrabItemOne = 178-45;

    const uint16_t kForearmRetreiveItemOne = 175;
    const uint16_t kBasearmRetreiveItemOne = 180;
    const uint16_t kPivotarmRetreiveItemOne = 130;

    const uint16_t kForearmStartItemTwo = 180;
    const uint16_t kBasearmStartItemTwo = 180;
    const uint16_t kPivotarmStartItemTwo = 130;

    const uint16_t kForearmGrabItemTwo = 140; //110
    const uint16_t kBasearmGrabItemTwo = 20; //30
    const uint16_t kPivotarmGrabItemTwo = 170-30;

    const uint16_t kForearmRetreiveItemTwo = 180;
    const uint16_t kBasearmRetreiveItemTwo = 180;
    const uint16_t kPivotarmRetreiveItemTwo = 40;

    const uint16_t kForearmStartItemThree = 180;
    const uint16_t kBasearmStartItemThree = 180;
    const uint16_t kPivotarmStartItemThree = 130;

    const uint16_t kForearmGrabItemThree = 160;
    const uint16_t kBasearmGrabItemThree = 55;
    const uint16_t kPivotarmGrabItemThree = 120-20;

    const uint16_t kForearmRetreiveItemThree = 180;
    const uint16_t kBasearmRetreiveItemThree = 180;
    const uint16_t kPivotarmRetreiveItemThree = 45;
	
	const uint16_t kForearmStartItemFour = 180;
    const uint16_t kBasearmStartItemFour = 180;
    const uint16_t kPivotarmStartItemFour = 90;

    const uint16_t kForearmGrabItemFour = 140;
    const uint16_t kBasearmGrabItemFour = 0;
    const uint16_t kPivotarmGrabItemFour = 30;

    const uint16_t kForearmRetreiveItemFour = 150;
    const uint16_t kBasearmRetreiveItemFour = 180;
    const uint16_t kPivotarmRetreiveItemFour = 10;

	const uint16_t kForearmStartItemFive = 180;
    const uint16_t kBasearmStartItemFive = 180;
    const uint16_t kPivotarmStartItemFive = 178;

    const uint16_t kForearmGrabItemFive = 160;
    const uint16_t kBasearmGrabItemFive = 130;
    const uint16_t kPivotarmGrabItemFive = 130;

	const uint16_t kPivotGrabItemFiveHalfway = 90;
	const uint16_t kForearmFinishItemFive = 50;
	
    const uint16_t kForearmRetreiveItemFive = 165;
    const uint16_t kBasearmRetreiveItemFive = 160;
    const uint16_t kPivotarmRetreiveItemFive = 10;
	
	const uint16_t kForearmStartItemSix = 180;
    const uint16_t kBasearmStartItemSix = 180;
    const uint16_t kPivotarmStartItemSix = 90;

    const uint16_t kForearmGrabItemSix = 120;
    const uint16_t kBasearmGrabItemSix = 120;
    const uint16_t kPivotarmGrabItemSix = 130;

    const uint16_t kForearmRetreiveItemSix = 0;
    const uint16_t kBasearmRetreiveItemSix = 0;
    const uint16_t kPivotarmRetreiveItemSix = 10;
	
    const int16_t kPivotarmSpeed = 128;

    // Claw
    const int16_t kClawSpeed = 90;

	// Ir
	const int16_t kIrScalingFactor = 1;
	const int16_t kLeftIrOffset = 0;
	const int16_t kRightIrOffset = 0;
	
    // Arduino Board
    const uint16_t kKnobMax = 1023;

    // Custom Servo
    const uint16_t kPivotArmForeward = 768;
    const uint16_t kPivotArmBackward = 256;
    const float kPivotReadingPerDegree = 2.8444444; // degree per analog read

    /*============TIME CONSTANTS============*/
    /*const uint16_t kWaitServoTurn = 1000*0.5; // milliseconds
    const uint16_t kWaitServoDown = 1000*1;  // milliseconds
    const uint16_t kWaitServoUp = 1000*1;   // milliseconds
    const uint16_t kWaitClawGrab = 1000*0.5;  // milliseconds
	const uint16_t kWaitBasearmTurn = 1000*1;
	const uint16_t kWaitForearmTurn = 1000*0.5;*/

	//safe numbers
	
	const uint16_t kWaitServoTurn = 1000*2; // milliseconds
    const uint16_t kWaitServoDown = 1000*2;  // milliseconds
    const uint16_t kWaitServoUp = 1000*2;   // milliseconds
    const uint16_t kWaitClawGrab = 1500;  // milliseconds
	const uint16_t kWaitBasearmTurn = 1000*2;
	const uint16_t kWaitForearmTurn = 1000*2;
	
    const uint16_t kLongDelay = 500;      // milliseconds
    const uint16_t kShortDelay = 200;     // milliseconds
	
	const uint16_t kWaitTurnDelay = 1500; //wait for robot to do 180 degree turn
	const uint16_t kWaitPastFourSideTape = 1000; //wait for the robot to get past the 4th sidetape
	const uint16_t kBrakeDelay = 125; //how long to brake???if necessary???
	const uint16_t kTimeToGetUp = 15*1000; //16*1000
	const uint16_t kTapeTurnLeftImmunityZoneDelay = 1500;
	const uint16_t kTapeHillImmunityZoneDelay = 1500;
	
	const uint16_t kWaitFindFive = 3000;
}

#endif
