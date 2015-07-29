#include <Arduino.h>

namespace parameters {
    int8_t proportionalgain = 12;
    int16_t derivativegain = 60;
	
	int8_t irproportionalgain = 1;
	int16_t irderivativegain = 1;
	
    int16_t basespeed = 60;
    uint8_t qrdthreshold = 200;
	//uint8_t irthreshold = 20; //???
	uint8_t sideqrdthreshold = 100;
	uint8_t sideirthreshold = 20; //???
}
