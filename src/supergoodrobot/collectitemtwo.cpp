#include "collectitemTwo.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "servocontrol.h"

namespace collectitemtwo {

    void CollectItemTwo() {
        servocontrol::SetBasearmServo(libconstants::kBasearmStartItemTwo);
        servocontrol::SetForearmServo(libconstants::kForearmStartItemTwo);
        servocontrol::SetPivotarmServo(libconstants::kPivotarmStartItemTwo);

        delay(libconstants::kWaitServoTurn);

        servocontrol::SetPivotarmServo(libconstants::kPivotarmGrabItemTwo);

        delay(libconstants::kWaitServoTurn);
		
        servocontrol::SetBasearmServo(libconstants::kBasearmGrabItemTwo);
        servocontrol::SetForearmServo(libconstants::kForearmGrabItemTwo);
		
        delay(libconstants::kWaitServoDown);

        motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);

        delay(libconstants::kWaitClawGrab);

        servocontrol::SetBasearmServo(libconstants::kBasearmRetreiveItemTwo);
		
		delay(libconstants::kWaitBasearmTurn);
		
        servocontrol::SetPivotarmServo(libconstants::kPivotarmRetreiveItemTwo);
		
		delay(libconstants::kWaitForearmTurn);
		
        servocontrol::SetForearmServo(libconstants::kForearmRetreiveItemTwo);

        /*delay(libconstants::kWaitServoUp);
        while (digitalRead(libconstants::kClawOpenSwitch)) {
            motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }
		motor.speed(libconstants::kClawMotor, 0);*/

		servocontrol::SetPivotarmServo(libconstants::kPivotarmStartPosition);

    }
}
