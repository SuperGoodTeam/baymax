Kevin Chow - 14/07/15

The code in this repository requires the custom library provided in the folder "customlibrary".  These files can be copied over those already located at <Arduinohome>/libraries/phys253TINAHArduino/. The alterations made are an externalization of the Servo and Motor objects and moving the function definitions to their appropriate source file.  This is to prevent inclusion conflicts.  Without these changes, compilation will result in a "multiple definitions" error.

#stop is stop (returns to the main menu)
      # Parameters menu: start to cycle through menu.
      		  #For load and save menus, 0 is defined as "YES", and otherwise for "NO"
      # Strategy Menu: knob to cycle through menu.  Last selection is selected selection.

BOOT
	INIT --> Choose strategy or change parameters

	MAIN MENU (stop) (knob6)
	     STRATEGY MENU (stop) --> choose plan(knob6) --> Selects strategy
	     PARAMETERS MENU (stop) --> choose thing to alter (start) -->  Alter thing (knob6)
	     START (start)

at any time press stop to return to main menu