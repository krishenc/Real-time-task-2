


#include "lab.cpp"
// simple LED example using direct port access
int main()
{
	u32 i; // used for the timer
	// define LED objects, all in their initial off state
	LEDs LED1(D1);
	LEDs LED2(D2);
	LEDs LED3(D3);
	LEDs LED4(D4);
	
	// set up the control port
	u8 ControlByte =(ModeSel | AInp);
	PPI->Control = (u32) ControlByte;
	
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
