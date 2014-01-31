#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
#include "Motor.h"
#include "Button.h"
#include <iostream>

void softTimer(int TimeSecs)
{
	int i;
	for(i=1500000*TimeSecs; i>0; i--);
}

int main ()
{
	comm ARMBoard;

	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
	ARMBoard.UpdateControl ((u32) ControlByte);

	Buzzer Buzzer1(&ARMBoard);
	SevenSeg Seg(&ARMBoard);
	Motor Motor1 (&ARMBoard);
	Button Accept(&ARMBoard,AcceptMask);
	Button Cancel(&ARMBoard,CancelMask);
	Button Prog3(&ARMBoard,Prog3Mask);
	Button Prog2(&ARMBoard,Prog2Mask);
	Button Prog1(&ARMBoard,Prog1Mask);
	Button Door(&ARMBoard,DoorMask);
	
	while(true)
	{
		int i;
		
		cout << "+------------------------------+\n";
		cout << "|  Washing Machine Driver Test |\n";
		cout << "+------------------------------+\n";
		
		//Test Prog1 Button
		softTimer(1);
		cout << "\n--------------------------------\n";
		cout << "Press Prog1 Button (right)\n...\n"; 
		bool tested = true;
		while(tested)
		{	
			if(Prog1.GetButtonState()) tested=false;
		}
		cout << "Prog1 Button Test Complete\n";
		cout << "--------------------------------\n";
		
		//Test Prog2 Button
		softTimer(1);
		cout << "Press Prog2 Button (middle)\n...\n";
		tested = true;
		while(tested)
		{
			if(Prog2.GetButtonState()) tested=false;
		}
		cout << "Prog2 Button Test Complete\n";
		cout << "--------------------------------\n";
		
		//Test Prog3 Button
		softTimer(1);
		cout << "Press Prog3 Button (left)\n...\n";		
		tested = true;
		while(tested)
		{
			if(Prog3.GetButtonState()) tested=false;
		}
		cout << "Prog3 Button Test Complete\n";
		cout << "--------------------------------\n";
		
		//Test Cancel Button
		softTimer(1);
		cout << "Press Cancel Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Cancel.GetButtonState()) tested=false;
		}
		cout << "Cancel Button Test Complete\n";
		cout << "--------------------------------\n";
		
		//Test Accept Button
		softTimer(1);
		cout << "Press Accept Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Accept.GetButtonState()) tested=false;
		}
		cout << "Accept Button Test Complete\n";
		cout << "--------------------------------\n";
		
		
		//Test Door Button
		softTimer(1);
		cout << "Open Door\n...\n";
		tested = true;
		while(tested)
		{
			if(Door.GetButtonState()) tested=false;
		}
		cout << "Door Opened\n";
		softTimer(1);
		cout << "Close Door\n...\n";
		tested = true;
		while(tested)
		{
			if(!Door.GetButtonState()) tested=false;
		}
		cout << "Close Closed\n";
		softTimer(1);
		cout << "Door Button Test Complete\n";
		cout << "--------------------------------\n";
		
		//SevenSegTest
		softTimer(1);
		cout << "Testing Seven Segment Display 0-9\n";
		for(i=0; i<10; i++)
		{
			Seg.UpdateDisplay(i);
			cout << "Displaying " << i << "...\n";
			softTimer(1);
		}
		cout << "Seven Segment Display Test Complete\n";
		cout << "--------------------------------\n";
		
		//Buzzer Test
		softTimer(1);
		cout << "Testing Buzzer\n";
		for(i=0; i<2; i++)
		{
			Buzzer1.BuzzSMS();
			softTimer(0.75);
		}
		cout << "Buzzer Test Complete\n";
		cout << "--------------------------------\n";
		
		//Motor Test
		softTimer(1);
		cout << "Testing Motor\n";
		for(i=0; i<2; i++)
		{
			cout << "Motor ON & CW\n";
			Motor1.SetDirection(false);
			Motor1.SetDrive(true);
			softTimer(1);
			
			cout << "Motor OFF\n" ;
			Motor1.SetDrive(false);
			softTimer(1);
			
			cout << "Motor ON & ACW\n";
			Motor1.SetDirection(true);
			Motor1.SetDrive(true);
			softTimer(1);
			
			cout << "Motor OFF\n";
			Motor1.SetDrive(false);
			softTimer(1);
		}
		cout << "Motor Test Complete\n";
		cout << "--------------------------------\n\n";
	}
}