#include "initialise.h"

#include "statemanager.h"
#include "strategies.h"

namespace initialise {

    void SetupStrategy() {
        switch (strategies::chosenstrategy) {
        case strategies::kClawTest:
            statemanager::SwitchState(statemanager::kClawTest);
            break;
        case strategies::kTapeTest:
            statemanager::SwitchState(statemanager::kTapeTest);
            break;
        case strategies::kPivotTest:
            statemanager::SwitchState(statemanager::kPivotTest);
            break;
        case strategies::kIrTest:
            statemanager::SwitchState(statemanager::kIrTest);
            break;
        }

    }
}
