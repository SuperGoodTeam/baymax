#include "followhilltape.h"

#include "drivecontrol.h"

namespace followhilltape {

    void FollowHillTapeLoop() {

        drivecontrol::FollowTapeLoop(0, 0);
    }
}
