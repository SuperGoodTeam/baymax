void stateMenu() {
  	delay(STANDARD_DELAY_1);
	LCD.clear();
	LCD.home();

	byte stateMenuChoice=(byte)map(knob(6),0,KNOB_MAX,0,MAIN_MENU); //get the state number by mapping the knob
	LCD.print("STATE: "+byteStateToString(stateMenuChoice));
	if (startbutton()) {
		currentState=(RobotState)stateMenuChoice;
		switchState(currentState);
	}
}
