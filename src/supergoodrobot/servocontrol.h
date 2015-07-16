#ifndef SERVOCONTROL_H_INCLUDED
#define SERVOCONTROL_H_INCLUDED

#include <Arduino.h>

namespace servocontrol {

    void SetForearmServo(uint8_t angle);

    void SetBasearmServo(uint8_t angle);

    void SetPivotarmServo(uint8_t angle);
}

#endif
