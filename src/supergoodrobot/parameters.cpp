#include <Arduino.h>

namespace parameters {
    int8_t proportionalgain = 24; //32
    int16_t derivativegain = 120; //160
	
	//int8_t irproportionalgain = 1;
	float irproportionalgain = 1;
	int16_t irderivativegain = 1;
	
    int16_t basespeed = 120; //160
    uint16_t qrdthreshold = 150;
	//uint8_t irthreshold = 20; //???
	uint16_t sideqrdthreshold = 400;
	uint16_t sideirthreshold = 400; //???
}
