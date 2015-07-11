//============== STATE FUNCTIONS ==============
void switchState(byte byteRobotState){
	RobotState newState=(RobotState)byteRobotState;
	exitState(currentState);
	LCDStateChangePrint(byteRobotState);
	setupState(newState); //simple for now
	currentState=newState;
}

void switchPlan(byte byte_Plan){
	Plan newPlan = (Plan)byte_Plan;
	//ok
	if (newPlan==TEST_DRIVE){
		switchState(DRIVE);
	}
	else if (newPlan==TEST_CLAW){
		switchState(CLAW_ARM_TEST);
	}
	else {
		switchState(FOLLOW_TAPE_1);
	}
}

void switchMenu(byte byteRobotMenu){ //only when you switch to an actual menu
	//setup? set all motors to 0
	//switch to no state, leave plan in place
	RobotMenu newMenu=(RobotMenu)byteRobotMenu;
	exitMenu(currentMenu);
	LCDMenuChangePrint(byteRobotMenu);
	if (newMenu!=NO_MENU) {
		switchState(REST); //put the robot at rest
		setupMenu(newMenu); //simple for now
	}
	currentMenu=newMenu;
}

void setupState(byte byteRobotState)
{
	RobotState state = (RobotState)byteRobotState;
	switch (state)
	{
	case PAST_DOOR:
		break;
	case FOLLOW_TAPE_1:
		start_followtape_1();
		break;
	case COLLECT_ITEM_1:
		start_collect_item_1();
		break;
	case FOLLOW_TAPE_2:
		start_followtape_2();
		break;
	case COLLECT_ITEM_2:
		start_collect_item_2();
		break;
	case COLLECT_ITEM_3:
		break;
	case COLLECT_ITEM_4:
		break;
	case COLLECT_ITEM_5:
		break;
	case COLLECT_ITEM_6:
		break;
	case UP_RAMP:
		break;
	case PAST_RAMP:
		break;
	case IR:
		break;
	case ZIPLINE:
		break;
	case FINISHED:
		break;
	case TEST:
		break;
	case CLAW_ARM_TEST:
		start_claw_arm_test();
		break;
	case DRIVE:
		start_followtape();
		break;
  }
}

void setupMenu(byte byteRobotMenu)
{
    RobotMenu menu = (RobotMenu)byteRobotMenu;
	switch(menu)
	{
	case MAIN_MENU:
		start_main_menu();
		break;
	case PLAN_MENU:
		start_plan_menu();
		break;
	case STATE_MENU:
		start_state_menu();
		break;
	case TAPE_MENU:
		start_tape_menu();
		break;
	}
}

void exitState(byte byteRobotState)
{
	RobotState state = (RobotState)byteRobotState;
	switch (state)
	{
	case REST:
		break;
	case INITIALISING:
		break;
	case PAST_DOOR:
		break;
	case FOLLOW_TAPE_1:
		break;
	case COLLECT_ITEM_1:
		break;
	case FOLLOW_TAPE_2:
		break;
	case COLLECT_ITEM_2:
		break;
	case COLLECT_ITEM_3:
		break;
	case COLLECT_ITEM_4:
		break;
	case COLLECT_ITEM_5:
		break;
	case COLLECT_ITEM_6:
		break;
	case UP_RAMP:
		break;
	case PAST_RAMP:
		break;
	case IR:
		break;
	case ZIPLINE:
		break;
	case FINISHED:
		break;
	case TEST:
		break;
	case CLAW_ARM_TEST:
		break;
	case DRIVE:
		break;
  }
}

void exitMenu(byte byteRobotMenu){
	RobotMenu menu = (RobotMenu)byteRobotMenu;
	switch(menu)
	{
	case NO_MENU:
		break;
	case MAIN_MENU:
		break;
	case PLAN_MENU:
		break;
	case STATE_MENU:
		break;
	case TAPE_MENU:
		break;
	}
}
