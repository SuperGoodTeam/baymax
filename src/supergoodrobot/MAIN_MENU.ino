void start_main_menu() {
	motor_rest();
	delay(STANDARD_DELAY_1);
	LCD.clear();
	LCD.home();
}

void mainMenu() {
	delay(STANDARD_DELAY_1);
	LCD.clear();
	byte subMenuChoice=(byte)map(knob(6),0,KNOB_MAX,0,NUM_SUBMENU); //exclude no menu and main menu
	LCD.print("MENU: "+byteSubMenuToString(subMenuChoice));
	if (startbutton()) {
		if (subMenuChoice==STATE_MENU){
			currentSubMenu=STATE_MENU;
			stateMenu();
		}
		if (subMenuChoice==PLAN_MENU){
			currentSubMenu=PLAN_MENU;
			planMenu();
		}
		if (subMenuChoice==TAPE_MENU){
			currentSubMenu=TAPE_MENU;
			tapeMenu();
		}
	}
}
