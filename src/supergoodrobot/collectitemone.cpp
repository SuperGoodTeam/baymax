#include "collectitemone.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemone {

    void CollectItemOne() {
        servocontrol::SetBasearmServo(libconstants::kBasearmStartItemOne);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemOne);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemOne);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemOne);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemOne);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemOne);

        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemOne);
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemOne);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemOne);
        delay(libconstants::kWaitServoUp);

        while (!digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);
        }

    }
}
