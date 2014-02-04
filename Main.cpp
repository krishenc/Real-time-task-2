#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
#include "Motor.h"
#include "Button.h"
#include <iostream>

// A timing function for use in the demo
void softTimer(int TimeSecs)
{
	int i;
	for(i=1500000*TimeSecs; i>0; i--);
}

int main ()
{
	// An object called ARMBoard used 
	comm ARMBoard;

	// Control port addresses are defined in PPI.h
	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
	ARMBoard.UpdateControl ((u32) ControlByte);

	Buzzer Buzzer1(&ARMBoard);
	SevenSeg Seg(&ARMBoard);
	Motor Motor1 (&ARMBoard);
	// The button mask offset addresses are defined in Button.h
	Button Accept(&ARMBoard,AcceptMask);
	Button Cancel(&ARMBoard,CancelMask);
	Button Prog3(&ARMBoard,Prog3Mask);
	Button Prog2(&ARMBoard,Prog2Mask);
	Button Prog1(&ARMBoard,Prog1Mask);
	Button Door(&ARMBoard,DoorMask);
	
	while(true)
	{
		int i; // loop variable
		
		cout << "+---------------------------------------+\n";
		cout << "|  Washing Machine Driver Test          |\n";
		cout << "+---------------------------------------+\n\n";
		
		// Test Prog1 Button
		softTimer(1);
		cout << "-----------------------------------------\n";
		cout << "Press Prog1 Button (right)\n...\n"; 
		bool tested = true;
		while(tested)
		{	
			if(Prog1.GetButtonState()) tested=false;
		}
		cout << "Prog1 Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Prog2 Button
		softTimer(1);
		cout << "Press Prog2 Button (middle)\n...\n";
		tested = true;
		while(tested)
		{
			if(Prog2.GetButtonState()) tested=false;
		}
		cout << "Prog2 Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Prog3 Button
		softTimer(1);
		cout << "Press Prog3 Button (left)\n...\n";		
		tested = true;
		while(tested)
		{
			if(Prog3.GetButtonState()) tested=false;
		}
		cout << "Prog3 Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Cancel Button
		softTimer(1);
		cout << "Press Cancel Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Cancel.GetButtonState()) tested=false;
		}
		cout << "Cancel Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Accept Button
		softTimer(1);
		cout << "Press Accept Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Accept.GetButtonState()) tested=false;
		}
		cout << "Accept Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		
		// Test Door Button
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
		cout << "-----------------------------------------\n";
		
		// SevenSegTest
		softTimer(1);
		cout << "Testing Seven Segment Display 0-9\n";
		for(i=0; i<10; i++)
		{
			Seg.UpdateDisplay(i);
			cout << "Displaying " << i << "...\n";
			softTimer(1);
		}
		cout << "Seven Segment Display Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Buzzer Test
		softTimer(1);
		cout << "Testing Buzzer\n";
		for(i=0; i<2; i++)
		{
			Buzzer1.BuzzSMS();
			softTimer(0.75);
		}
		cout << "Buzzer Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Motor Test
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
		cout << "-----------------------------------------\n\n";
		
		// Test complete, ask user to repeat the test
		softTimer(1);
		cout << "+---------------------------------------+\n";
		cout << "|  Washing Machine Driver Test Complete |\n";
		cout << "|  > Press Accept to repeat the test,   |\n";
		cout << "|  > Press Cancel to exit               |\n";
		cout << "|  ...                                  |\n";
		
		softTimer(1);
		tested = true;
		while(tested)
		{
			if(Cancel.GetButtonState())
			{
				cout << "|  Exiting Washing Machine Driver Test  |\n";
				cout << "+---------------------------------------+\n";
				return(0);
			}
			else if(Accept.GetButtonState())
			{
				cout << "|  Repeating Washing Machine Driver Test|\n";
				cout << "+---------------------------------------+\n";
				tested=false;
			}
		}

	}
}