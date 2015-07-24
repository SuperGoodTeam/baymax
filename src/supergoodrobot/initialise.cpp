#include "initialise.h"

#include <phys253.h>
#include "libconstants.h"

#include "statemanager.h"
#include "strategies.h"
#include "strategymanager.h"

namespace initialise {

    void SetupStrategy() {
		while (digitalRead(libconstants::kClawOpenSwitch)) {
				motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
			}
		motor.speed(libconstants::kClawMotor, 0);
		strategymanager::GoToNextState();
        // switch (strategies::chosenstrategy) {
		// default:
			// strategymanager::GoToNextState();
			// break;
		// }
    }
}
