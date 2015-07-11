void start_plan_menu() {
   delay(STANDARD_DELAY_1);
   LCD.clear();
   LCD.home();
}

void planMenu() {
  	delay(STANDARD_DELAY_1);
	LCD.clear();
	byte planChoice=constrain((byte)map(knob(6),0,KNOB_MAX,0,NUM_PLAN),0,NUM_PLAN-1); //get the plan number by mapping the knob
	LCD.print("PLAN: "+bytePlanToString(planChoice));
	if (startbutton()) {
		currentPlan=(Plan)planChoice;
		switchMenu(NO_MENU);
		switchPlan(planChoice);
	}
}


