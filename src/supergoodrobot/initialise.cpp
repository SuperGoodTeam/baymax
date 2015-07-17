#include "initialise.h"

#include "statemanager.h"
#include "strategies.h"
#include "strategymanager.h"

namespace initialise {

    void SetupStrategy() {
		strategymanager::GoToNextState();
        // switch (strategies::chosenstrategy) {
		// default:
			// strategymanager::GoToNextState();
			// break;
		// }
    }
}
