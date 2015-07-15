#include "pivotservotest.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace pivotservotest {

    void PivotServoTestLoop() {
        int pivotservoposition = 90;
        bool moveservo = false;

        if (startbutton())
            moveservo = !moveservo;

        if (moveservo)
            servocontrol::SetPivotarmServo(pivotservoposition);
        else {
            pivotservoposition = map(knob(6), 0, libconstants::kKnobMax, 0, libconstants::kServoDegreesMax);
            LCD.clear();
            LCD.print("Pivot: 6: " + String(pivotservoposition));
            delay(libconstants::kShortDelay);
        }
    }


}
