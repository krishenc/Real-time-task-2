#include "LEDs.h"
#include "types.h"
#include "PPI.h"


// simple LED example using direct port access
int main()
{

	u32 LocalPortA;
	u32 LocalPortB;
	u32 LocalPortC;
	comm *PPI = (comm *) 0xFFFF1C00;
	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode1 | BOut | CHInp | CLInp);
	PPI->UpdateControl ((u32) ControlByte);
	u32 i; // used for the timer
	// define LED objects, all in their initial off state
	LEDs LED1(D1);
	LEDs LED2(D2);
	LEDs LED3(D3);
	LEDs LED4(D4);
	

	// wait for a second
	for(i=3000000; i>0; i--);
	
	while(true)
	{
	
		// light the first LED
		LED4.set(1);

		// light the second LED;
		LED3.set(1);

		// light the second LED;
		LED2.set(1);
		
		LED1.set(1);
		
	}
}
