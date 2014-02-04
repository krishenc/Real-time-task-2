#include "PPI.h"
#include "Buzzer.h"
//#include <iostream>

//------------------------------------------

// Buzzer class functions

// Constructor function requires reference to comm class
// for accessing hardware port
Buzzer::Buzzer(comm *Comms)
{
	ARMBoard = Comms; 
	//cout << "Comms# ="<< Comms << "\n";
	//cout << "Buzzer# ="<< ARMBoard << "\n";
}

// Function for turning the buzzer ON
void Buzzer::On()
{
	u32 PortB = ARMBoard->GetLocalPortB();
	PortB = PortB | BuzzerBit;
	ARMBoard->SetPortB(PortB);
}

// Function for turning the buzzer OFF
void Buzzer::Off()
{
	u32 PortB = ARMBoard->GetLocalPortB();
	PortB = PortB & ~BuzzerBit;
	ARMBoard->SetPortB(PortB);
}

// Test function for buzzer
void Buzzer::BuzzSMS()
{
	int i;
	//Morse Code (SMS)
	//S
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	//M
	On();
	for(i=1500000*0.15; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	On();
	for(i=1500000*0.15; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	//S
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
	
	On();
	for(i=1500000*0.05; i>0; i--);
	Off();
	for(i=1500000*0.05; i>0; i--);
}