#include "PPI.h"
#include <iostream>
#include <bitset>

//------------------------------------------

// sets the output bits on PortB
void i8255A::SetPortB(u32 Bits )volatile
{
	PortB = Bits;
}

// returns the bits on PortC
u32 i8255A::GetPortC() volatile
{
	return (PortC);
}

// set the Control bits
void i8255A::SetControl(u32 Bits) volatile
{
	Control = Bits;
}

//------------------------------------------
// class constructor initialises private members
comm::comm()
{
	PortA = 0;
	PortB = 0;
	PortC = 0;
	PPI = (i8255A *) (0xFFFF1C00);
}

// the 32 bit argument is stored in local copy and then 
// written to the port via PPI
void comm::SetPortB (u32 bitmap)
{
	PortB = bitmap;
	PPI->SetPortB(PortB);
}

// returns the private member PortB (the latest PortB output)
u32 comm::GetLocalPortB ()
{
	return (PortB);
}

// returns the 32bit value on PortC (via PPI)
u32 comm::GetPortC ()
{
	PortC = PPI->GetPortC();
	return (PortC);
}

// sets the Control bits (via PPI)
void comm::UpdateControl (u32 bitmap)
{
	PPI->SetControl(bitmap);
}

