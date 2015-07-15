#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"

namespace clawarmtest {

    uint8_t forearmposition;
    uint8_t basearmposition;

    bool clawopening;

    bool clawopen;
    bool itemdetect;

    void ClawArmTestLoop() {
        forearmposition = map(knob(6), 0, libconstants::kKnobMax, 0, libconstants::kServoDegreesMax);
        basearmposition = map(knob(7), 0, libconstants::kKnobMax, 0, libconstants::kServoDegreesMax);

        RCServo0.write(forearmposition);
        RCServo1.write(forearmposition);

        LCD.clear();
        LCD.home();
        LCD.print("F: " + String(forearmposition));
        LCD.setCursor(6, 0);
        LCD.print("B: " + String(basearmposition));
        LCD.setCursor(0, 1);
        clawopen = !digitalRead(libconstants::kClawOpenSwitch);
        itemdetect = digitalRead(libconstants::kItemDetectSwitch);
        LCD.print("O: " + String(clawopen));
        LCD.print("P: " + String(itemdetect));
        delay(libconstants::kShortDelay);

        if (startbutton()) {
            clawopening = !clawopening;

            if (clawopening) {
                if (!clawopen) {
                    motor.speed(libconstants::kClawMotor, libconstants::kClawSpeed);
                }
                else
                    motor.speed(libconstants::kClawMotor, 0);

            }
            else
                motor.speed(libconstants::kClawMotor, -libconstants::kClawSpeed);
        }


    }
}
