#include "Manager.h"

Manager::StartSelectedProgram(int selectedProgram)
{
	// If the door is open sound buzzer
	if(!Door.GetButtonState()
	{
		Buzzer1.BuzzSMS();
	}
	// If door is closed continue...
	else
	{
		// Update display
		Seg.UpdateDisplay(Programs[selectedProgram].status)
		// Update motor control
		Motor1.SetDirection(false); // Initialise direction
		Motor1.SetDrive(Programs(selectedProgram.motorControl);
		// Start timer
	}
}

Manager::PauseProgram()
{
}

Manager::ResumeProgram()
{
}

Manager::ResetProgram()
{
}

Manager::AdvanceStage()
{
}
