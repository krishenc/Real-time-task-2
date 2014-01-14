#include "PPI.h"
#include "LEDs.h"

LEDs::LEDs(unsigned char bitMapping)
{
	u8 ControlByte = (ModeSel | AInp);  // normal mode, port A input, B, C output
	PPI->Control = (int) ControlByte;
	bitMap = bitMapping;
	PortCData = 0;
	reset();
}
	
void LEDs::set()
{
	PortCData = (u32)PPI->PortC;
	PortCData = PortCData | bitMap;
	PPI->PortC = (u32)PortCData;
}
	
void LEDs::set(int seconds)
{
	set();
	int i;
	for(i=1500000*seconds; i>0; i--);
	reset();
}
	
void LEDs::reset()
{
	//PortCData = (u32)PPI->PortC;
	PortCData = PortCData & ~bitMap;
	PPI->PortC = (u32)PortCData;
}
	
bool LEDs::get()
{
	if (PortCData & bitMap)
	{
		return true;
	}
	else
	{
		return false;
	}
}


