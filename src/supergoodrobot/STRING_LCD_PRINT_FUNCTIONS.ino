//============== nice print/string functions ==============
String byteStateToString(byte byteRobotState) {
	RobotState stringRobotState = (RobotState)byteRobotState;
	switch(stringRobotState) {
	case INITIALISING:
		return("INITIALISING");
	case PAST_DOOR:
		return("PAST DOOR");
	case FOLLOW_TAPE_1:
		return("TAPE 1");
	case COLLECT_ITEM_1:
		return("ITEM 1");
	case FOLLOW_TAPE_2:
		return("TAPE 2");
	case COLLECT_ITEM_2:
		return("ITEM 2");
	case COLLECT_ITEM_3:
		return("ITEM 3");
	case COLLECT_ITEM_4:
		return("ITEM 4");
	case COLLECT_ITEM_5:
		return("ITEM 5");
	case COLLECT_ITEM_6:
		return("ITEM 6");
	case UP_RAMP:
		return("UP RAMP");
	case PAST_RAMP:
		return("PAST RAMP");
	case IR:
		return("IR");
	case ZIPLINE:
		return("ZIPLINE");
	case FINISHED:
		return("FINISHED");
	case TEST:
		return("TESTING");
	case CLAW_ARM_TEST:
		return("CLAW ARM TEST");
	case BASE_MOTOR_TEST:
		return("BASE MOTOR TEST");
	case DRIVE:
		return("TEST DRIVE");
	case MAIN_MENU:
		return("MAIN MENU");
	}
}

void LCDStateChangePrint(byte byteRobotState) {
	String stringRobotState=byteStateToString(byteRobotState);
	LCD.clear();
	LCD.home();
	LCD.setCursor(0,0);
	LCD.print("SWITCH:");
	LCD.setCursor(0,1);
	LCD.print(stringRobotState);
}

String bytePlanToString(byte byte_Plan){
	Plan stringPlan = (Plan)byte_Plan;
	switch(stringPlan) {
	case FULL:
		return("FULL");
	case NOT4:
		return("ALL BUT 4");
	case NOT5:
		return("ALL BUT 5");
	case TEST_DRIVE:
		return("TEST DRIVE");
	case TEST_CLAW:
		return("TEST CLAW");
	case TEST_BASE_MOTOR:
		return("TEST BASE MOTOR");
  }
}

String byteSubMenuToString(byte byte_subMenu){
	subMenu stringSubMenu = (subMenu)byte_subMenu;
	switch(stringSubMenu) {
		case PLAN_MENU:
			return("PLAN MENU");
		case STATE_MENU:
			return("STATE MENU");
		case TAPE_MENU:
			return("TAPE MENU");
		case NO_SUBMENU:
			return("NO SUBMENU");
	}
}
