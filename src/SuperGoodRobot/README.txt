# README FOR JAN:

# stop is stop(returns to main menu)
	# tape menu: start to choose value and cycle to next
		# saving/loading: 0+START for YES, else num+START NO
	# state menu: start to choose state
# start is confirm

BOOT
	INIT --> choose state (start) (knob 6) --> switches to state
	
	MAIN MENU (stop) (knob 6)
		PLAN MENU (stop) --> choose plan (start) --> switches to beginning of plan
		TAPE MENU (stop) --> driving params, confirm (start), saving/loading: (0 for YES, else for no)
		STATE MENU (stop) --> choose state (start) --> switches to beginning of state 
		
at any time: return to MAIN MENU (stop) #this still needs to be fully figured out, but 95% of the time for now

def:
	state: robot does actions corresponding to that state, ie, actions corresponding to 'collect item 1' would be moving claw/arm into positions corresponding to retrieving item 1, 'follow tape 1' would be tape-following & searching for positions corresponding to tape segment 1 checkpoints (ie, sidetape)
	plan: sets of states, ie, 'full'='full course' (robot will proceed to attempt to traverse the whole track and retrieve all plushies), may contain debug sets of states for now (ie, test drive and test claw suites)
	driving params: kp, kd, basespeed, etc