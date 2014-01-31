#include "PPI.h"
#include "Motor.h"
#include <iostream>

Motor::Motor(comm* Comms)
{
	ARMBoard = Comms;
}

void Motor::SetDrive(bool on_off)
{
	drive = on_off;
	u32 PortB = ARMBoard->GetLocalPortB();
	if (drive == true)
	{
		PortB = PortB | MotorBit;
		ARMBoard->SetPortB(PortB);
	}
	if (drive == false)
	{
		PortB = PortB & (~MotorBit);
		ARMBoard->SetPortB(PortB);
	}
} 

void Motor::SetDirection(bool dir)
{
	direction = dir;
	u32 PortB = ARMBoard->GetLocalPortB();
	if (direction == true)
	{
		PortB = PortB | MotorDirBit;
		ARMBoard->SetPortB(PortB);
	}
	if (direction == false)
	{
		PortB = PortB & (~MotorDirBit);
		ARMBoard->SetPortB(PortB);
	}
}