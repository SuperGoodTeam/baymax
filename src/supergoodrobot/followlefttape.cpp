#include "followlefttape.h"

#include "drivecontrol.h"

namespace followlefttape {

    void FollowLeftTapeLoop() {
	
	drivecontrol::FollowTapeLoop(0, 0);
    }
}
