#include "drivecontrol.h"

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>

#include "libconstants.h"
#include "parameters.h"

namespace drivecontrol {

    uint8_t lcdrefreshrate = 0;
    int8_t error, lasterror, lasterrorstate = 0;
    int8_t lasterrorstatetime = 0;
    int8_t errorstatetime = 1;
    int8_t proportionalcorrection = 0;
    int8_t derivativecorrection = 0;
    int8_t totalcorrection = 0;

    uint16_t leftqrd;
    uint16_t rightqrd;

    void FollowTapeLoop(int8_t speedchange, int8_t turnbias) {
        leftqrd = analogRead(libconstants::kLeftTapeSensor);
        rightqrd = analogRead(libconstants::kRightTapeSensor);

        if (leftqrd > parameters::qrdthreshold) {
            if (rightqrd > parameters::qrdthreshold)
                error = 0;
            else
                error = -1;
        }
        else if (rightqrd > parameters::qrdthreshold)
            error = 1;
        else if (lasterror > 0)
            error = 5;
        else
            error = -5;

        if (error != lasterror) {
            lasterrorstate = lasterror;
            lasterrorstatetime = errorstatetime;
            errorstatetime = 1;
        }

        proportionalcorrection = parameters::proportionalgain * error;
        derivativecorrection = parameters::derivativegain * (error - lasterrorstate) / (lasterrorstatetime + errorstatetime);

        totalcorrection = proportionalcorrection + derivativecorrection;

        if (lcdrefreshrate == 30) {
	    LCD.clear();
            LCD.print("L: " + String(leftqrd));
            LCD.print("R: " + String(rightqrd));
            lcdrefreshrate = 0;
        }
        lcdrefreshrate++;

        errorstatetime++;

        lasterror = error;

        motor.speed(libconstants::kLeftMotor, -parameters::basespeed - totalcorrection - speedchange);
        motor.speed(libconstants::kRightMotor,+parameters::basespeed - totalcorrection + speedchange);
    }

    void StopDriveMotors() {
        motor.speed(libconstants::kLeftMotor, 0);
        motor.speed(libconstants::kRightMotor, 0);
    }
}
