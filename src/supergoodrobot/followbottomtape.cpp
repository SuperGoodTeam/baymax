#include "followbottomtape.h"

#include "drivecontrol.h"
#include "libconstants.h"

namespace followbottomtape {

    void FollowBottomTapeLoop() {
        drivecontrol::FollowTapeLoop(libconstants::kBottomTapeSpeedChange, libconstants::kBottomTapeTurnBias);
    }
}
