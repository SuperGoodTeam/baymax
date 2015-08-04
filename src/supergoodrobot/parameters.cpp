#include <Arduino.h>

namespace parameters {
    int8_t proportionalgain = 36;
    int16_t derivativegain = 86;
	
	//int8_t irproportionalgain = 1;
	float irproportionalgain = 1;
	int16_t irderivativegain = 1;
	
    int16_t basespeed = 135;
    uint8_t qrdthreshold = 150;
	//uint8_t irthreshold = 20; //???
	uint8_t sideqrdthreshold = 200;
	uint8_t sideirthreshold = 800; //???
}
