//============== STATE FUNCTIONS ==============
void switchState(byte byteRobotState){
	RobotState newState=(RobotState)byteRobotState;
	exitState(currentState);
	LCDStateChangePrint(byteRobotState);
	setupState(newState); //simple for now
	currentState=newState;
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
	case MAIN_MENU:
		start_main_menu();
		break;
	case DRIVE:
		start_followtape();
		break;
  }
}

void exitState(byte byteRobotState)
{
	RobotState state = (RobotState)byteRobotState;
	switch (state)
	{
	case INITIALISING:
		break;
	case PAST_DOOR:
		break;
	case FOLLOW_TAPE_1: //nothing, really
		break;
	case COLLECT_ITEM_1:
		break;
	case FOLLOW_TAPE_2: //nothing, really
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
	case MAIN_MENU:
		break;
  }
}

void switchPlan(byte byte_Plan){
	Plan newPlan = (Plan)byte_Plan;
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
