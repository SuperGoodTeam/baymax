void planMenu() {
  	delay(STANDARD_DELAY_1);
	LCD.clear();
	LCD.home();

	byte planChoice=(byte)map(knob(6),0,KNOB_MAX,0,NUM_PLAN); //get the plan number by mapping the knob
	LCD.print("PLAN: "+bytePlanToString(planChoice));
	if (startbutton()) {
		currentPlan=(Plan)planChoice;
		switchPlan(planChoice);
	}
}