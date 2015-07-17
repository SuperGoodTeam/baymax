#include "followrighttape.h"

#include "drivecontrol.h"

namespace followrighttape {

    void FollowRightTapeLoop() {

        drivecontrol::FollowTapeLoop(0, 0);
    }
}
