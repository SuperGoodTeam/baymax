#include "tapefollowtest.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "drivecontrol.h"
#include "libconstants.h"
#include "parameters.h"

namespace tapefollowtest {

    void TapeFollowTestLoop() {
        drivecontrol::FollowTapeLoop(0, 0);
    }
}
