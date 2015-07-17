#ifndef DRIVECONTROL_H_INCLUDED
#define DRIVECONTROL_H_INCLUDED

#include <Arduino.h>

namespace drivecontrol {

    void FollowTapeLoop(int8_t speedchange, int8_t turnbias);
	
    void FollowIrLoop(int8_t speedchange, int8_t turnbias);

    void StopDriveMotors();
}

#endif
