#include "PPI.h"
#include "Buzzer.h"
//#include <iostream>

Buzzer::Buzzer(comm *Comms)
{
	ARMBoard = Comms; 
	//cout << "Comms# ="<< Comms << "\n";
	//cout << "Buzzer# ="<< ARMBoard << "\n";
}

void Buzzer::On()
{
	u32 PortB = ARMBoard->GetLocalPortB();
	PortB = PortB | BuzzerBit;
	ARMBoard->SetPortB(PortB);
}

void Buzzer::Off()
{
	u32 PortB = ARMBoard->GetLocalPortB();
	PortB = PortB & ~BuzzerBit;
	ARMBoard->SetPortB(PortB);
}

void Buzzer::Buzz()
{
	int i;
	On();
	for(i=1500000*0.1; i>0; i--);
	Off();
	for(i=1500000*1; i>0; i--);
}