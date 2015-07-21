#include <Arduino.h>

namespace parameters {
    int8_t proportionalgain = 16*1.5;
    int16_t derivativegain = 80*1.5;
    int16_t basespeed = 120;
    uint8_t qrdthreshold = 200;
	//uint8_t irthreshold = 20; //???
	uint8_t sideirthreshold = 20; //???
}
