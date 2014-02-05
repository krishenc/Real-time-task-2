#include "PPI.h"
#include "Button.h"

// Constructor function requires reference to comm class
// for accessing hardware port
Button::Button(comm * Comms, u32 bitmask)
{
	ARMBoard = Comms;
	ButtonMask = bitmask;
}

// Function to return the state of the button
// by anding the button mask with PortC and
// the this against the button mask
bool Button::GetButtonState()
{
	u32 PortC = ARMBoard->GetPortC();
	return ((PortC & ButtonMask) == ButtonMask);
}