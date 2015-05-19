#include <phys253.h>
#include <LiquidCrystal.h>

int counter=0;
long lastTime;
int COUNTER_MAX=10000;
boolean wasLow = false;

void setup()
{ 
	#include <phys253setup.txt>
	while(!startbutton())
	{
		 LCD.clear();
		 LCD.home();
		 LCD.print("Hello goof!");
		 delay(1000);
	}
	LCD.clear(); LCD.home();
	LCD.print("Starting now");
}

void loop()
{

	while (!stopbutton())
	{
		lastTime=millis();
		while (counter < COUNTER_MAX){
			 if (digitalRead(0)){
					if(wasLow){
						counter++;
						wasLow = false;
					}
			 } else {
				 wasLow = true;
			 }
		}
		updateFrequency();
	}
	while (!startbutton())
	{
		LCD.clear(); LCD.home();
		if (digitalRead(0))
		{ LCD.print("object NOT detected."); }
		else
		{ LCD.print("object detected"); }
		delay(100) ;
	}
}

void updateFrequency()
{
	long frq = 1.0/(((millis() - lastTime)/1000.0) / COUNTER_MAX);
	LCD.clear(); LCD.home();
	LCD.print(frq); 
	counter=0;
	lastTime=millis();
}

