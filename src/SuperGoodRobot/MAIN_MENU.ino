void start_main_menu() {
	delay(STANDARD_DELAY_1);
	LCD.clear();
	LCD.home();
}

void mainMenu() {
	delay(STANDARD_DELAY_1);
	LCD.clear();
	byte menuChoice=constrain((byte)map(knob(6),0,KNOB_MAX,2,NUM_MENU),0,NUM_MENU-1); //exclude no menu and main menu
	LCD.print("MENU: "+byteMenuToString(menuChoice));
	if (startbutton()) {
		currentMenu=(RobotMenu)menuChoice;
		switchMenu(currentMenu);
	}
}