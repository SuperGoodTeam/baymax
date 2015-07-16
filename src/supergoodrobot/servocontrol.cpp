#include "servocontrol.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"

namespace servocontrol {

    uint16_t pivotarmreading;
    uint16_t desiredreading;

    void SetForearmServo(uint8_t angle) {

        RCServo0.write(angle);
    }

    void SetBasearmServo(uint8_t angle) {

        RCServo1.write(angle);
    }

    void SetPivotarmServo(uint8_t angle) {
        desiredreading = angle * libconstants::kPivotReadingPerDegree + 256;

        do {
            pivotarmreading = analogRead(libconstants::kMotorBaseSensor);

            if (desiredreading > pivotarmreading)
                motor.speed(libconstants::kPivotarmMotor, libconstants::kPivotarmSpeed);
            else
                motor.speed(libconstants::kPivotarmMotor, -libconstants::kPivotarmSpeed);

        } while ((pivotarmreading - desiredreading) > 1); //Imperfect system

        motor.speed(libconstants::kPivotarmMotor, 0);
    }
}
