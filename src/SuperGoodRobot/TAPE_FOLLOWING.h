#ifndef TAPE_MENU_H
#define TAPE_MENU_H


//============== DRIVE PARAMS ==============

#include <phys253.h>
#include <LiquidCrystal.h>

//#include <EEPROMex.h>
//#include <EEPROMVar.h>

//DRIVE PARAMS
#define TAPE_SENSOR_LEFT 0
#define TAPE_SENSOR_RIGHT 1

//QRD DRIVE
#define QRD_THRESHOLD 200

#define NUM_PRINTSTATES 6

  short saveFlag=500;
  short loadFlag=500;
  
  short error, lerr, recerr = 0;
  short kp = 20;
  short kd = 100;
  short q = 0;
  short m = 1;
  short d = 0;
  short con = 0;
  short p = 0;
  short c = 0;
  short baseSpeed = 150;
  short printstate=0;
  //these get changed by the menu/states later


void saveEE() {
  LCD.print("Saving now");
  EEPROM.write(0,kp);
  EEPROM.write(1,kd);
  EEPROM.write(2,baseSpeed);
}

void loadEE() {
  LCD.print("Loading now");
  kp=EEPROM.read(0);
  kd=EEPROM.read(1);
  baseSpeed=EEPROM.read(2);
}

void printLR() {
  LCD.print("L: "+String(analogRead(TAPE_SENSOR_LEFT)));
  LCD.print(" R: "+String(analogRead(TAPE_SENSOR_RIGHT)));
  
}


void TapeMenu() { //activates the tape menu
    delay(1000);
    LCD.clear();
    
    if (stopbutton()){
      printstate++;
    }
    
    if (printstate>NUM_PRINTSTATES){
      printstate=0;
    }
        
    if (printstate==0){
      printLR();
    }
    else if (printstate==1){
      kp=knob(6)/10;
      LCD.print("kp: 6:  "+String(kp));
    }
    else if (printstate==2){
      kd=knob(7)/10;
      LCD.print("kd: 7: "+String(kd));
    }
    else if (printstate==3){
      baseSpeed=knob(6)/4;
      LCD.print("baseSpeed: 6: "+String(baseSpeed));
    }
    else if(printstate==4){
      loadFlag=knob(6);
      LCD.clear();LCD.home();
      LCD.setCursor(0,0); LCD.print("Load? 6: "+String(knob(6)));
      LCD.setCursor(0,1); LCD.print("p:"+String(EEPROM.read(0))+"d:"+String(EEPROM.read(1))+"s:"+String(EEPROM.read(2)));
      }
    else if(printstate==5){
      saveFlag=knob(7);
      LCD.print("Save? 7: "+String(knob(7)));
    }
    else if (printstate==6){
      if (saveFlag==0){
        saveEE();
      }
      if (loadFlag==0){
        loadEE();
      }
      printstate++;
    }
}

void readQRDErrCalc() {
	//QRD reads
	short left = analogRead(TAPE_SENSOR_LEFT);
    short right = analogRead(TAPE_SENSOR_RIGHT);
    if (left > QRD_THRESHOLD)
		if (right > QRD_THRESHOLD)
			error = 0;
		else
			error = -1;
	else if (right > QRD_THRESHOLD)
		error = 1;
	else if (lerr > 0)
		error = 5;
	else
		error = -5;

    if (error != lerr) {
      recerr = lerr;
      q = m;
      m = 1;
    }

    p = kp * error;

    d = kd * (error - recerr) / (q + m);
    con = p + d;

    if (c == 30) {
      printf("%d %d %d %d %d %d\n", right, left, kp, kd, p, d);
      c = 0;
    }

    c++;
    m++;
    lerr = error;

}

#endif
