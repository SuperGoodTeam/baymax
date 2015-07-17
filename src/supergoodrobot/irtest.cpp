#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>
#include "irtest.h"

#include "drivecontrol.h"

#include "libconstants.h"

namespace irtest {

    void IrTestLoop() {
		drivecontrol::FollowIrLoop(libconstants::kFollowIrSpeedChange, libconstants::kFollowIrTurnBias);
    }
}
