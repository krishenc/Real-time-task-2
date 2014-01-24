#include "PPI.h"
#include <iostream>

 void i8255A::SetPortB(u32 Bits )volatile {
PortB = Bits;


}

u32 i8255A::GetPortC() volatile{
	return (PortC);
}

void i8255A::SetControl(u32 Bits) volatile{
Control = Bits;
}



comm::comm(){
PortA = 0;
PortB = 0x07;
PortC = 0;
PPI = (i8255A *) (0xFFFF1C00);

}


void comm::UpdatePortB (u32 bitmap)
{
	PortB = PortB ^ bitmap;
	PPI->SetPortB(PortB);

	
}

u32 comm::GetPortC (u32 AccessBit)
{
	PortC = PPI->GetPortC();
	return (PortC);
}

void comm::UpdateControl (u32 bitmap)
{
	PPI->SetControl(bitmap);
}