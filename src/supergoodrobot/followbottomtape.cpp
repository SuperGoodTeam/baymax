#include "followbottomtape.h"

#include "drivecontrol.h"

namespace followbottomtape {

    void FollowBottomTapeLoop() {
        drivecontrol::FollowTapeLoop(0, 0);
    }
}
