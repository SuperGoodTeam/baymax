#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>
#include "followir.h"

#include "drivecontrol.h"
#include "libconstants.h"

namespace followir {

    void FollowIrLoop() {
		drivecontrol::FollowIrLoop(libconstants::kFollowIrSpeedChange, libconstants::kFollowIrTurnBias);
    }
}
