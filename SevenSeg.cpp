#include "types.h"
#include "PPI.h"
#include "SevenSeg.h"

// default constructor
SevenSeg::SevenSeg()
{
	ARMBoard = new comm;
}

// Constructor function requires reference to comm class
// for accessing hardware port
SevenSeg::SevenSeg(comm* Comms)
{
	ARMBoard = Comms;
	ClearDisplay();
}

// Function to clear the Seven Segment Display (15 = clear)
void SevenSeg::ClearDisplay()
{
	UpdateDisplay((u32)15);
}

// Function to set the Seven Segment Display (0-9)
void SevenSeg::UpdateDisplay (u32 Number)
{
	// Clamp the input number to the displayable range
	// (0-9) with the exception of 15 for clearing
	if (Number == 15);
	else if (Number > 9) Number = 9;
	
	u32 PortB = ARMBoard->GetLocalPortB();
	// Modify PortB to set the Seven Segment Display
	PortB = PortB & 0xF0;    // Clear the bottom 4 bits
	PortB = PortB | Number;  // Populate the botton 4 bits
	ARMBoard->SetPortB(PortB);
}