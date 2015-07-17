#include "followlefttape.h"

#include "drivecontrol.h"
#include "libconstants.h"

namespace followlefttape {

    void FollowLeftTapeLoop() {

        drivecontrol::FollowTapeLoop(libconstants::kLeftTapeSpeedChange, libconstants::kLeftTapeTurnBias);
    }
}
