#include "PPI.h"
#include "SevenSeg.h"
//#include <iostream>

// Constructor function requires reference to comm class
// for accessing hardware port
SevenSeg::SevenSeg(comm* Comms)
{
	ARMBoard = Comms;
}

void SevenSeg::UpdateDisplay (int Number)
{
	u32 PortB = ARMBoard->GetLocalPortB();
	PortB = PortB & 0xF0;
	PortB = PortB | Number;
	//cout << "PortB = " << PortB << "\n";
	ARMBoard->SetPortB(PortB);
}