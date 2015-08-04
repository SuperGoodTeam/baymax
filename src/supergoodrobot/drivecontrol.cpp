#include "drivecontrol.h"

#include <Arduino.h>
#include <LiquidCrystal.h>
#include <phys253.h>

#include "statemanager.h"
#include "libconstants.h"
#include "sensorsuite.h"
#include "parameters.h"

namespace drivecontrol {

    uint16_t lcdrefreshrate = 0;
    int16_t error, lasterror, lasterrorstate = 0;
    int16_t lasterrorstatetime = 0;
    int16_t errorstatetime = 1;
    int16_t proportionalcorrection = 0;
    int16_t derivativecorrection = 0;
    int16_t totalcorrection = 0;
	uint8_t errorcount = 0;
	

    uint16_t leftqrd;
    uint16_t rightqrd;

	uint16_t leftir;
	uint16_t rightir;
	
	uint32_t oldtime;
	
	void FollowIrLoop(int8_t speedchange, int8_t turnbias) { 
		leftir = analogRead(libconstants::kLeftFrontIr);
		rightir = analogRead(libconstants::kRightFrontIr);
		
		error = - ((leftir - libconstants::kLeftIrOffset)-(rightir - libconstants::kRightIrOffset))*(libconstants::kIrScalingFactor);
		
		//working params calc
		//parameters::irproportionalgain = abs(1.5*500.f/(leftir+rightir));
		
		parameters::irproportionalgain = abs(1.75*500.f/(leftir+rightir));
		
        if (error != lasterror) { //might have to constrain the errors?
            lasterrorstate = lasterror;
            lasterrorstatetime = errorstatetime;
            errorstatetime = 1;
        }

        proportionalcorrection = parameters::irproportionalgain * error;
        derivativecorrection = parameters::irderivativegain * (error - lasterrorstate) / (lasterrorstatetime + errorstatetime);

        totalcorrection = proportionalcorrection + derivativecorrection;

        if (lcdrefreshrate == 30) {
			LCD.clear();
			LCD.setCursor(0,0);
            LCD.print("LIR: " + String(leftir) + "KP: " + String(parameters::irproportionalgain));
            LCD.setCursor(0,1);
			LCD.print("RIR: " + String(rightir));
			LCD.print("S: " + String(analogRead(libconstants::kSideIr)));
            lcdrefreshrate = 0;
        }
        lcdrefreshrate++;

        errorstatetime++;

        lasterror = error;

        motor.speed(libconstants::kLeftMotor, -parameters::basespeed - totalcorrection - speedchange);
        motor.speed(libconstants::kRightMotor,+parameters::basespeed - totalcorrection + speedchange);
	}
	
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
			
		/*if (error == lasterror){
			errorcount++;
		}

		if (errorcount==3 || (statemanager::currentstate!=statemanager::kTapeTurnRight && statemanager::currentstate!=statemanager::kTapeHill)){*/
			if (error != lasterror) {
				lasterrorstate = lasterror;
				lasterrorstatetime = errorstatetime;
				errorstatetime = 1;
			}
			
			proportionalcorrection = parameters::proportionalgain * error;
			derivativecorrection = parameters::derivativegain * (error - lasterrorstate) / (lasterrorstatetime + errorstatetime);

			totalcorrection = proportionalcorrection + derivativecorrection;
			
			errorstatetime++;

			lasterror = error;

		/*}
		errorcount=0;*/
         if (lcdrefreshrate == 30) {
	     LCD.clear();
			 LCD.setCursor(0,0);
			 //LCD.print(String(analogRead(libconstants::kSideTapeSensor)));
             LCD.print("L: " + String(leftqrd));
             LCD.print("R: " + String(rightqrd));
			 LCD.setCursor(0,1);
			 LCD.print("S: " + String(analogRead(libconstants::kSideTapeSensor)) + " " + String(analogRead(libconstants::kSideTapeRightSensor)));
             lcdrefreshrate = 0;
         }
         lcdrefreshrate++;
	
        motor.speed(libconstants::kLeftMotor, (-parameters::basespeed - totalcorrection - speedchange));
        motor.speed(libconstants::kRightMotor, (+parameters::basespeed - totalcorrection + speedchange));
    }
	
	void ResistantFollowTapeLoop(int8_t speedchange, int8_t turnbias) {
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
			
		if (error != lasterror){
			errorcount++;
		}

		if (errorcount==3){
			if (error != lasterror) {
				lasterrorstate = lasterror;
				lasterrorstatetime = errorstatetime;
				errorstatetime = 1;
			}
			
			proportionalcorrection = parameters::proportionalgain * error;
			derivativecorrection = parameters::derivativegain * (error - lasterrorstate) / (lasterrorstatetime + errorstatetime);

			totalcorrection = proportionalcorrection + derivativecorrection;
			
			errorstatetime++;

			lasterror = error;

		}
		errorcount=0;
         /*if (lcdrefreshrate == 30) {
	     LCD.clear();
			 LCD.setCursor(0,0);
			 //LCD.print(String(analogRead(libconstants::kSideTapeSensor)));
             LCD.print("L: " + String(leftqrd));
             LCD.print("R: " + String(rightqrd));
			 LCD.setCursor(0,1);
			 LCD.print("S: " + String(analogRead(libconstants::kSideTapeSensor)) + " " + String(analogRead(libconstants::kSideTapeRightSensor)));
             lcdrefreshrate = 0;
         }
         lcdrefreshrate++;*/
	
        motor.speed(libconstants::kLeftMotor, (-parameters::basespeed - totalcorrection - speedchange));
        motor.speed(libconstants::kRightMotor, (+parameters::basespeed - totalcorrection + speedchange));
    }


    void StopDriveMotors() {
        motor.speed(libconstants::kLeftMotor, 0);
        motor.speed(libconstants::kRightMotor, 0);
    }
	
	void BrakeDriveMotors() {
		motor.speed(libconstants::kRightMotor, libconstants::kMotorSlowSpeed);
		motor.speed(libconstants::kLeftMotor, -libconstants::kMotorSlowSpeed);
		delay(libconstants::kBrakeDelay);
		StopDriveMotors();
	}
	
	void BrakeAndStopDriveMotors() {
		BrakeDriveMotors();
		StopDriveMotors();
	}
	
	void StraightDriveMotors(int16_t speed) {
		motor.speed(libconstants::kLeftMotor, -speed);
		motor.speed(libconstants::kRightMotor, speed);
	}
	
	void LeftTurnDriveMotors(int16_t speed) {
		motor.speed(libconstants::kRightMotor, speed);
		motor.speed(libconstants::kLeftMotor, speed);
		
	}
	
	void RightTurnDriveMotors(int16_t speed) {
		motor.speed(libconstants::kRightMotor, -speed);
		motor.speed(libconstants::kLeftMotor, -speed);
		
	}
	
	bool LocateTapeTrack(int16_t speed, int16_t correctiontime = 400) {
		RightTurnDriveMotors(speed);
		oldtime = millis();
		while (millis() - oldtime < correctiontime) {
			if (sensorsuite::QRDTapeDetect()) {
				StopDriveMotors();
				return true;
			}
		}
		LeftTurnDriveMotors(speed);
		oldtime = millis();
		while (millis() - oldtime < 2 * correctiontime + 100) {
			if (sensorsuite::QRDTapeDetect()) {
				StopDriveMotors();
				return true;
			}
		}
		StopDriveMotors();
		return false;
	}
	
}
