#include "PPI.h"
#include "Button.h"
//#include <iostream>

Button::Button(comm * Comms, u32 bitmask)
{
	ARMBoard = Comms;
	ButtonMask = bitmask;
}

bool Button::GetButtonState()
{
	u32 PortC = ARMBoard->GetPortC();
	return ((PortC & ButtonMask) == ButtonMask);
}