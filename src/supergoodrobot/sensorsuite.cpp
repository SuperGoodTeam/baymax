#include "sensorsuite.h"

#include <Arduino.h>

#include "libconstants.h"
#include "parameters.h"

namespace sensorsuite {

    bool SideTapeDetect() {
        if (analogRead(libconstants::kSideTapeSensor) > parameters::qrdthreshold)
            return true;
        else
            return false;
    }
	
	bool SideIrDetect() {
		if (analogRead(libconstants::kSideIr) > parameters::sideirthreshold)
			return true;
		else
			return false;
	}
	
	bool FrontSensorDetect() {
		if (!digitalRead(libconstants::kItemDetectSwitch))
			return true;
		else
			return false;
	}
	
}
