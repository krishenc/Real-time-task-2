#include "PPI.h"
#include "Motor.h"
#include <iostream>

// statuses
#define Empty 1
#define Fill 2
#define Heat 3
#define Wash 4
#define Rinse 5
#define Spin 6
#define Dry 7
#define Complete 8

// motor control 
#define Off 0
#define Low 1
#define High 2

// default constructor
Motor::Motor()
{
	ARMBoard = new comm;
}

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

void Motor::SetDrive(u32 drive)
{
	if (drive == Off)
	{
	
	}
	else if (drive == Low)
	{
	
	}
	else if (drive == High)
	{
	
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