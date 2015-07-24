#include "collectitemthree.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemthree {

    void CollectItemThree() {
        servocontrol::SetBasearmServo(libconstants::kBasearmStartItemThree);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemThree);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemThree);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemThree);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemThree);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemThree);

        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemThree);
		
		delay(libconstants::kWaitBasearmTurn);
		
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemThree);
		
		delay(libconstants::kWaitForearmTurn);
		
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemThree);

        delay(libconstants::kWaitServoUp);
        while (digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }
		motor.speed(libconstants::kClawMotor, 0);
    }
}
