void start_initialising() {
	LCD.clear();
	LCD.home();
	byte tempPlan=constrain((Plan)map(knob(6),0,KNOB_MAX,0,NUM_PLAN),0,NUM_PLAN-1); //get the plan number by mapping the knob
	LCD.print("INIT: "+bytePlanToString(tempPlan));
	delay(100);
	if (startbutton()) {
		currentPlan=(Plan)tempPlan;
		
		//delete this later
		if (currentPlan==TEST_DRIVE){
			switchState(DRIVE);
		}
		else {
			switchState(FOLLOW_TAPE_1);
		}
	}
}
