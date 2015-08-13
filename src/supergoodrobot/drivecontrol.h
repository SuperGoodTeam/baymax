#ifndef DRIVECONTROL_H_INCLUDED
#define DRIVECONTROL_H_INCLUDED

#include <Arduino.h>

namespace drivecontrol {

    void FollowTapeLoop(int8_t speedchange, int8_t turnbias);
	
    void FollowIrLoop(int8_t speedchange, int8_t turnbias);
	
	void ResistantFollowTapeLoop(int8_t speedchange,int8_t turnbias);

    void StopDriveMotors();
	
	void BrakeDriveMotors();
	
	void BrakeAndStopDriveMotors();
	
	void StraightDriveMotors(int16_t speed);
	
	void LeftTurnDriveMotors(int16_t speed);
	
	void RightTurnDriveMotors(int16_t speed);
	
	bool LocateTapeLeftTrack(int16_t speed, int16_t correctiontime);
	
	bool LocateTapeRightTrack(int16_t speed, int16_t correctiontime);

	void OrientIrBeacon();
}

#endif
