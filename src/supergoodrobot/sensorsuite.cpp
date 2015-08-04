#include "sensorsuite.h"

#include <Arduino.h>

#include "libconstants.h"
#include "parameters.h"

namespace sensorsuite {

    bool SideTapeDetect() {
        if (analogRead(libconstants::kSideTapeSensor) > parameters::sideqrdthreshold)
            return true;
        else
            return false;
    }
	
	bool SideTapeRightDetect() {
		if (analogRead(libconstants::kSideTapeRightSensor) > parameters::sideqrdthreshold)
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
		if (!digitalRead(libconstants::kFrontDetectSwitch))
			return true;
		else
			return false;
	}
	
	bool HookarmAttachDetect() {
		if (!digitalRead(libconstants::kHookarmAttachSwitch))
			return true;
		else
			return false;
	}
	
	bool HookarmBaseTouchDetect() {
		if (!digitalRead(libconstants::kHookarmBaseTouchSwitch))
			return true;
		else
			return false;
	}
	
	bool QRDTapeDetect() {
		if ((analogRead(libconstants::kRightTapeSensor) > parameters::qrdthreshold) || (analogRead(libconstants::kLeftTapeSensor) > parameters::qrdthreshold)){
			return true;
		}
		else{
			return false;
		}
	}
	
}
