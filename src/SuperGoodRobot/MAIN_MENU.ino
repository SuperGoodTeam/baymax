void start_main_menu() {
        motor.speed(MOTOR_LEFT,0); //set motors to 0 at first
        motor.speed(MOTOR_RIGHT,0);
	delay(500);
	LCD.clear();
	LCD.home();

}

void mainMenu() {
	delay(100);
	LCD.clear();
	byte menuChoice=constrain((byte)map(knob(6),0,KNOB_MAX,0,2),0,1);
	LCD.print("MENU: "+byteMenuChoiceToString(menuChoice));
	if (startbutton()) {
		if (menuChoice==0){
			switchState(TAPE_MENU);
		}
		if (menuChoice==1){
			switchState(STATE_MENU);
		}
	}
}

String byteMenuChoiceToString(byte byteMenuChoice){
	if (byteMenuChoice==0){
		return("TAPE MENU");
	}
	if (byteMenuChoice==1){
		return("STATE MENU");
	}
}
