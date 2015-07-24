#include "collectitemfour.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemfour {

    void CollectItemFour() {
        servocontrol::SetBasearmServo(libconstants::kBasearmStartItemFour);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemFour);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemFour);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemFour);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemFour);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemFour);

        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemFour);
		
		delay(libconstants::kWaitBasearmTurn);
		
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemFour);
		
		delay(libconstants::kWaitForearmTurn);
		
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemFour);

        delay(libconstants::kWaitServoUp);
        while (digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }
		motor.speed(libconstants::kClawMotor, 0);
    }
}
