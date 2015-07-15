void start_base_motor_test() {
	LCD.clear();
	LCD.home();
	setBaseMotor(0);
}

void base_motor_test(){
	int menuCounter=0;
	int BASE_POSITION=map(knob(6),0,KNOB_MAX,256,256*3);
	
	if (startbutton()) {
		menuCounter++;
		delay(STANDARD_DELAY_1);
	}
	if (menuCounter>2){
		menuCounter=0;
	}
	switch(menuCounter){
		case 0:
			BASE_POSITION=map(knob(6),0,KNOB_MAX,256,256*3);
			LCD.clear();
			LCD.home();
			LCD.print("New BM: 6: "+String(BASE_POSITION));
			delay(STANDARD_DELAY_2);
			break;
		case 1:
			setBaseMotor(BASE_POSITION); //fairly certain this works, uncomment this out later
			break;
	}
}