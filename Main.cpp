#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
#include "Motor.h"
#include "Button.h"
#include <iostream>

void softTimer(int TimeSecs){
int i;
for(i=1500000*TimeSecs; i>0; i--);
}

int main (){

	comm ARMBoard;

	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
	ARMBoard.UpdateControl ((u32) ControlByte);

	//cout << "Main# ="<< &ARMBoard << "\n";
	Buzzer Buzzer1(&ARMBoard);
	SevenSeg Seg(&ARMBoard);
	Motor Motor1 (&ARMBoard);
	Button Accept(&ARMBoard,AcceptMask);
	Button Cancel(&ARMBoard,CancelMask);
	Button Prog3(&ARMBoard,Prog3Mask);
	Button Prog2(&ARMBoard,Prog2Mask);
	Button Prog1(&ARMBoard,Prog1Mask);
	Button Door(&ARMBoard,DoorMask);
	
	//Set Switch to Latch
	//u32 PortB = ARMBoard.GetLocalPortB();
	//PortB = PortB & 0x80;
	//ARMBoard.SetPortB(PortB);
	//End of Set Swicth to Lacth

	while(true)
	{
		/*int i;
		for(i=0; i<10 ; i++){
			Motor1.SetDrive(true);
			Buzzer1.Buzz();
			Motor1.SetDirection(true);
			Seg.UpdateDisplay(i);
			softTimer(1);
			Motor1.SetDrive(false);
			softTimer(1);
			Motor1.SetDirection(false);
		}*/
		
		//Test Buttons
		if(Accept.GetButtonState()) cout << "Appect Button Pressed \n";
		if(Cancel.GetButtonState()) cout << "Cancel Button Pressed \n";
		if(Prog3.GetButtonState()) cout << "Prog3 Button Pressed \n";
		if(Prog2.GetButtonState()) cout << "Prog2 Button Pressed \n";
		if(Prog1.GetButtonState()) cout << "Prog1 Button Pressed \n";
		if(Door.GetButtonState()) cout << "Door Button Pressed \n";



	}


}