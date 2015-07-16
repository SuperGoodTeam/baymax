void start_tape_menu() {
   delay(STANDARD_DELAY_1);
   LCD.clear();
   LCD.home();
}

void tapeMenu() { //activates the tape menu
   delay(STANDARD_DELAY_1);
   LCD.clear();
    if (startbutton()){
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
      kd=knob(7)/5;
      LCD.print("kd: 7: "+String(kd));
    }
    else if (printstate==3){
      baseSpeed=knob(6)/4;
      LCD.print("bSpeed: 6: "+String(baseSpeed));
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

void exit_tape_menu() {
   delay(STANDARD_DELAY_1);
   LCD.clear();
   LCD.home();
}
