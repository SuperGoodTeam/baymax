void start_state_menu() {
   delay(STANDARD_DELAY_1);
   LCD.clear();
   LCD.home();
}

void stateMenu() {
  	delay(STANDARD_DELAY_1);
	LCD.clear();
	byte stateMenuChoice=constrain((byte)map(knob(6),0,KNOB_MAX,0,MAIN_MENU),0,MAIN_MENU-1); //get the plan number by mapping the knob
	LCD.print("STATE: "+byteStateToString(stateMenuChoice));
	if (startbutton()) {
		currentState=(RobotState)stateMenuChoice;
		switchMenu(NO_MENU);
		switchState(currentState);
	}
}