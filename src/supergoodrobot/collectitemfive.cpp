#include "collectitemfive.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemfive {

    void CollectItemFive() {
                servocontrol::SetBasearmServo(libconstants::kBasearmStartItemFive);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemFive);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemFive);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemFive);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemFive);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemFive);

        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemFive);
		
		delay(libconstants::kWaitBasearmTurn);
		
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemFive);
		
		delay(libconstants::kWaitForearmTurn);
		
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemFive);

        delay(libconstants::kWaitServoUp);

        while (digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }
		motor.speed(libconstants::kClawMotor, 0);

    }
}
