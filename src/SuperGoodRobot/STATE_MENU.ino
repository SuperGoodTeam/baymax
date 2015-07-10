void start_state_menu() {
   delay(STANDARD_DELAY_1);
   LCD.clear();
   LCD.home();
}

void stateMenu() {
  	delay(STANDARD_DELAY_1);
	LCD.clear();
	byte menuChoice=constrain((byte)map(knob(6),0,KNOB_MAX,0,MAIN_MENU),0,MAIN_MENU-1); //get the plan number by mapping the knob
	LCD.print("STATE: "+byteStateToString(menuChoice));
	if (startbutton()) {
		currentState=(RobotState)menuChoice;
		switchState(currentState);
	}
}
