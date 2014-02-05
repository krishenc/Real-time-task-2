#include "PPI.h"
#include "Motor.h"
#include <iostream>

// Constructor function requires reference to comm class
// for accessing hardware port
Motor::Motor(comm* Comms)
{
	ARMBoard = Comms;
}

// Function set the motor ON or OFF
void Motor::SetDrive(bool drive)
{
	u32 PortB = ARMBoard->GetLocalPortB();
	if (drive == true)
	{
		PortB = PortB | MotorBit;
		ARMBoard->SetPortB(PortB);
	}
	else
	{
		PortB = PortB & (~MotorBit);
		ARMBoard->SetPortB(PortB);
	}
} 

// Function to set the direction of the Motor
// FALSE = CW, TRUE = ACW
void Motor::SetDirection(bool direction)
{
	u32 PortB = ARMBoard->GetLocalPortB();
	
	if (direction == true)
	{
		PortB = PortB | MotorDirBit;
		ARMBoard->SetPortB(PortB);
	}
	else
	{
		PortB = PortB & (~MotorDirBit);
		ARMBoard->SetPortB(PortB);
	}
}