#include "collectitemsix.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemsix {

    void CollectItemSix() {
        servocontrol::SetBasearmServo(libconstants::kBasearmStartItemSix);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemSix);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemSix);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemSix);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemSix);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemSix);

        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemSix);
		
		delay(libconstants::kWaitBasearmTurn);
		
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemSix);
		
		delay(libconstants::kWaitForearmTurn);
		
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemSix);

        delay(libconstants::kWaitServoUp);

        while (digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }
		motor.speed(libconstants::kClawMotor, 0);

    }
}
