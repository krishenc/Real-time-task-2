#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
#include "Motor.h"
#include "Button.h"
#include "SoftTimer.h"
//#include "programlist.h"
#include <iostream>


// Program that tests the driver functionality
int main ()
{
	int i; // loop variable for testing
	
	// An instance of Manager class
	//Manager Manager1;
	
	// An instance of comm class
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
	SoftTimer  Timer1;
	
   	int selectedProgram = 0; // This is used to get the program selection from the user
   	bool validProgramSelection = false; // Make sure the selected program is valid
   	/*
	while (!validProgramSelection)
	{
		if (Accept.GetButtonState())
		{
			if (Prog1.GetButtonState())
			{
				selectedProgram = selectedProgram | 1; // Populate the least significant bit in selectedProgram
			}
			if (Prog2.GetButtonState())
			{
				selectedProgram = selectedProgram | 2; // Populate the middle bit in selectedProgram
			}
			if (Prog3.GetButtonState())
			{
				selectedProgram = selectedProgram | 4; // Populate the most significant bit in selectedProgram
			}
			
			// Make sure the user cant select a program that does not exist
			if (selectedProgram <= NumberofPrograms)
			{
				validProgramSelection = true;
			}
			
		}
	}*/
	cout << "Valid program selected : " << selectedProgram;
	
	/*
	// Loop until the test is complete and the user wishes to exit
	while(true)
	{
		
		
		cout << "+---------------------------------------+\n";
		cout << "|  Washing Machine Driver Test          |\n";
		cout << "+---------------------------------------+\n\n";
		
		// Test Prog1 Button
		Timer1.Wait(1);
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
		Timer1.Wait(1);
		cout << "Press Prog2 Button (middle)\n...\n";
		tested = true;
		while(tested)
		{
			if(Prog2.GetButtonState()) tested=false;
		}
		cout << "Prog2 Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Prog3 Button
		Timer1.Wait(1);
		cout << "Press Prog3 Button (left)\n...\n";		
		tested = true;
		while(tested)
		{
			if(Prog3.GetButtonState()) tested=false;
		}
		cout << "Prog3 Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Cancel Button
		Timer1.Wait(1);
		cout << "Press Cancel Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Cancel.GetButtonState()) tested=false;
		}
		cout << "Cancel Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Test Accept Button
		Timer1.Wait(1);
		cout << "Press Accept Button\n...\n";
		tested = true;
		while(tested)
		{
			if(Accept.GetButtonState()) tested=false;
		}
		cout << "Accept Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		
		// Test Door Button
		Timer1.Wait(1);
		cout << "Open Door\n...\n";
		tested = true;
		while(tested)
		{
			if(Door.GetButtonState()) tested=false;
		}
		cout << "Door Opened\n";
		Timer1.Wait(1);
		cout << "Close Door\n...\n";
		tested = true;
		while(tested)
		{
			if(!Door.GetButtonState()) tested=false;
		}
		cout << "Close Closed\n";
		Timer1.Wait(1);
		cout << "Door Button Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// SevenSegTest
		Timer1.Wait(1);
		cout << "Testing Seven Segment Display 0-9\n";
		for(i=0; i<10; i++)
		{
			Seg.UpdateDisplay(i);
			cout << "Displaying " << i << "...\n";
			Timer1.Wait(1);
		}
		Seg.ClearDisplay();
		cout << "Clearing Dispaly " << "...\n";
		Timer1.Wait(1);
		cout << "Seven Segment Display Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Buzzer Test
		Timer1.Wait(1);
		cout << "Testing Buzzer\n";
		Buzzer1.BuzzSMS();
		Timer1.Wait(1);
		cout << "Buzzer Test Complete\n";
		cout << "-----------------------------------------\n";
		
		// Motor Test
		Timer1.Wait(1);
		cout << "Testing Motor\n";
		cout << "Motor ON & CW\n";
		Motor1.SetDirection(false);
		Motor1.SetDrive(true);
		Timer1.Wait(1);
			
		cout << "Motor OFF\n" ;
		Motor1.SetDrive(false);
		Timer1.Wait(1);
			
		cout << "Motor ON & ACW\n";
		Motor1.SetDirection(true);
		Motor1.SetDrive(true);
		Timer1.Wait(1);
			
		cout << "Motor OFF\n";
		Motor1.SetDrive(false);
		Timer1.Wait(1);

		cout << "Motor Test Complete\n";
		cout << "-----------------------------------------\n\n";
		
		// Test complete, ask user if they wish to repeat the test
		Timer1.Wait(1);
		cout << "+---------------------------------------+\n";
		cout << "|  Washing Machine Driver Test Complete |\n";
		cout << "|  > Press Accept to repeat the test,   |\n";
		cout << "|  > Press Cancel to exit               |\n";
		cout << "|  ...                                  |\n";
		
		Timer1.Wait(1);
		tested = true;
		while(tested)
		{
			if(Cancel.GetButtonState())
			{
				// Exit the program if the Cancel button is pressed
				cout << "|  Exiting Washing Machine Driver Test  |\n";
				cout << "+---------------------------------------+\n";
				return(0);
			}
			else if(Accept.GetButtonState())
			{
				// Repeat the program if the Accept button is pressed
				cout << "|  Repeating Washing Machine Driver Test|\n";
				cout << "+---------------------------------------+\n";
				tested=false;
			}
		}

	}*/
}