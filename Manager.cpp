#include "Manager.h"
#include <iostream>

Manager::Manager()
{
	// Control port addresses are defined in PPI.h
	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
	ARMBoard.UpdateControl ((u32) ControlByte);
	// Create objects for each part
	Buzzer1 = Buzzer(&ARMBoard);
	Seg = SevenSeg(&ARMBoard);
	Motor1 = Motor(&ARMBoard);
	Accept = Button(&ARMBoard, AcceptMask);
	Cancel = Button(&ARMBoard, CancelMask);
	Prog3 = Button(&ARMBoard, Prog3Mask);
	Prog2 = Button(&ARMBoard, Prog2Mask);
	Prog1 = Button(&ARMBoard, Prog1Mask);
	Door = Button(&ARMBoard, DoorMask);
	Seg.ClearDisplay(); // Clear the display
}


void Manager::Start()
{
	// Get selected program from buttons
	u32 selectedProgram = getSelectedProgram();		// Wait for input
	
	// If the door is open
	while (!Door.GetButtonState())
	{
		Buzzer1.BuzzSMS();							// Sound the buzzer
		while ( !Accept.GetButtonState() ) {}		// Wait for accept button
	}
	
	// Set program selection in program class
	program.SetProgram(selectedProgram);
	currentCycle = program.GetNextCycle();
	Seg.UpdateDisplay(currentCycle->GetStatus());	// Display the wash cycle status index
	float waitTime = 0.05; // Seconds
	
	while ( currentCycle->GetStatus() != Complete )
	{
		//cout << currentCycle->GetStatus() << " time length is " << currentCycle->GetTime() << endl;
		// Run stage
		Motor1.SetDrive(currentCycle->GetMotorControl());	// Set stage motor setting
		
		float imax = currentCycle->GetTime() * ((1/waitTime)-1);
		cout << imax << " Seconds: " << currentCycle->GetTime() <<  endl;
		for (u32 i = 0; i < imax; i++)
		{
			Timer.Wait(waitTime);
			// Poll door
			if (!Door.GetButtonState())		// door is open
			{
				// Pause execution until door is closed again
				PauseProgram();
				Buzzer1.BuzzSMS();
				while( !Door.GetButtonState() ) 
				{
					Seg.ClearDisplay();
					Timer.Wait((float)0.1);
					Seg.UpdateDisplay(currentCycle->GetStatus());
					Timer.Wait((float)0.1);
				}
				ResumeProgram();
			}
			// Poll accept button
			if (Accept.GetButtonState())	// button is pressed
			{
				// Go to the next wash cycle
				i = imax; // exit wash cycle loop
				Timer.Wait((float)0.5);
			}
			// Poll cancel button
			if (Cancel.GetButtonState())	// button is pressed
			{
				PauseProgram();
				Timer.Wait((float)0.5);
				bool input = false;
				while (input == false)
				{
					if (Cancel.GetButtonState())
					{
						input = true;
						// Stop what you're doin
						ResetProgram();
						Seg.UpdateDisplay(currentCycle->GetStatus());
						return;
					}
					if (Accept.GetButtonState())
					{
						input = true;
						ResumeProgram();
					}
					Seg.ClearDisplay();
					Timer.Wait((float)0.1);
					Seg.UpdateDisplay(currentCycle->GetStatus());
					Timer.Wait((float)0.1);
				}
			}
		}
		AdvanceStage();
		Seg.UpdateDisplay(currentCycle->GetStatus());	// display the wash cycle status index
	}
	
}

void Manager::PauseProgram()
{
	Motor1.SetDrive(0);
}

void Manager::ResumeProgram()
{
	Motor1.SetDrive(currentCycle->GetMotorControl());
}

void Manager::ResetProgram()
{
	while ( currentCycle->GetStatus() != Complete )
	{
		AdvanceStage();
	}
}

void Manager::AdvanceStage()
{
	currentCycle = program.GetNextCycle(); 
}

u32 Manager::getSelectedProgram()
{
	u32 selectedProgram = 0;
   	bool validProgramSelection = false; // Make sure the selected program is valid
   	
   	// Get the program selected by the user
	while (!validProgramSelection)
	{
		selectedProgram = 0; // Reset selectedProgram incase validProgramSelction was false
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
			if (selectedProgram < MaxPrograms)
			{
				validProgramSelection = true;
			}
			
		}
	}
	
	return selectedProgram;
}