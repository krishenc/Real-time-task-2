#include "Manager.h"

Manager::Manager()
{
	// Control port addresses are defined in PPI.h
	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
	ARMBoard.UpdateControl ((u32) ControlByte);
	Buzzer1 = Buzzer(&ARMBoard);
	Seg = SevenSeg(&ARMBoard);
	Motor1 = Motor(&ARMBoard);
	Accept = Button(&ARMBoard, AcceptMask);
	Cancel = Button(&ARMBoard, CancelMask);
	Prog3 = Button(&ARMBoard, Prog3Mask);
	Prog2 = Button(&ARMBoard, Prog2Mask);
	Prog1 = Button(&ARMBoard, Prog1Mask);
	Door = Button(&ARMBoard, DoorMask);
}


void Manager::Start()
{
	// get selected program from buttons
	u32 selectedProgram = getSelectedProgram();		// wait for input
	
	// if the door is open
	while (!Door.GetButtonState())
	{
		Buzzer1.BuzzSMS();							// sound the buzzer
		while ( !Accept.GetButtonState() ) {}		// wait for accept button
	}
	
	program.SetProgram(selectedProgram);
	WashCycle currentCycle = program.GetNextCycle();
	
	Seg.UpdateDisplay(currentCycle.GetStatus());	// display the wash cycle status index
	// run stage
	Motor1.SetDrive(currentCycle.GetMotorControl());
	

	
	
	// status, time, motor control
	
		// Update display
		//Seg.UpdateDisplay(program[selectedProgram].status);
		// Update motor control
		//Motor1.SetDirection(false); // Initialise direction
		//Motor1.SetDrive(program[selectedProgram].motorControl);
		// Start timer
	
}

void Manager::PauseProgram()
{
}

void Manager::ResumeProgram()
{
}

void Manager::ResetProgram()
{
}

void Manager::AdvanceStage()
{
	
}

u32 Manager::getSelectedProgram()
{
	u32 selectedProgram = 0;
   	bool validProgramSelection = false; // Make sure the selected program is valid
   	
   	// Get the program selected by the user
	while (!validProgramSelection)
	{
		selectedProgram = 0; // Reset selectedProgram incase validProgramSeection was false
		if (Accept.GetButtonState())
		{
			if (Prog1.GetButtonState())
			{
				selectedProgram = selectedProgram | 1; // Populate the first bit in selectedProgram
			}
			if (Prog2.GetButtonState())
			{
				selectedProgram = selectedProgram | 2; // Populate the seccond bit in selectedProgram
			}
			if (Prog3.GetButtonState())
			{
				selectedProgram = selectedProgram | 4; // Populate the third bit in selectedProgram
			}
			
			// Make sure the user cant select a program that does not exist
			if (selectedProgram <= MaxPrograms)
			{
				validProgramSelection = true;
			}
			
		}
	}
	
	return selectedProgram;
}