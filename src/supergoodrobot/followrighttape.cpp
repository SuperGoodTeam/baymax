#include "followrighttape.h"

#include "drivecontrol.h"
#include "libconstants.h"

namespace followrighttape {

    void FollowRightTapeLoop() {
        drivecontrol::FollowTapeLoop(libconstants::kRightTapeSpeedChange, libconstants::kRightTapeTurnBias);
    }
}
