void start_initialising() {
	LCD.clear();
	LCD.home();
	byte tempPlan=constrain((Plan)map(knob(6),0,KNOB_MAX,0,NUM_PLAN),0,NUM_PLAN-1); //get the plan number by mapping the knob
	LCD.print("INIT: "+bytePlanToString(tempPlan));
	delay(STANDARD_DELAY_1);
	if (startbutton()) {
		currentPlan=(Plan)tempPlan;
		switchPlan(tempPlan);
	}
}
