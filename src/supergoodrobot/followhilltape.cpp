#include "followhilltape.h"

#include "drivecontrol.h"
#include "libconstants.h"

namespace followhilltape {

    void FollowHillTapeLoop() {

        drivecontrol::FollowTapeLoop(libconstants::kHillTapeSpeedChange, libconstants::kHillTapeTurnBias);
    }
}
