#include "tapefollowtest.h"

#include <LiquidCrystal.h>
#include <phys253.h>

#include "drivecontrol.h"
#include "libconstants.h"
#include "parameters.h"

namespace tapefollowtest {
	void TapeFollowTestLoop() {
		//LCD.clear();
        drivecontrol::FollowTapeLoop(0, 0);
		/*if (drivecontrol::LocateTapeTrack(40, 500) == true){
			LCD.print("True");
		}
		else{
			LCD.print("False");
		}*/
    }
}
