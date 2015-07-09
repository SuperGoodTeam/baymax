void start_state_menu() {
   delay(500);
   LCD.clear();
   LCD.home();
}

void stateMenu() {
  	delay(100);
	LCD.clear();
	byte menuChoice=constrain((byte)map(knob(6),0,KNOB_MAX,0,NUM_STATES),0,NUM_STATES-1); //get the plan number by mapping the knob
	LCD.print("STATE: "+byteStateToString(menuChoice));
	if (startbutton()) {
		currentState=(RobotState)menuChoice;
		switchState(currentState);
	}
}
