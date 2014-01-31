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

u32 Motor::GetSpeed(){

	int i;
	int rawSpeed[5000];
	int SpeedTotal = 0;
	int avSpeed;
	u32 PortC;
	for(i=0; i<5000; i++)
	{
		PortC = ARMBoard->GetPortC();
		if((PortC & MotorSpeedMask) == MotorSpeedMask )	rawSpeed[i] = 1;
		else rawSpeed[i]=0;
	}
	for(i=0; i<5000; i++)
	{
		SpeedTotal = SpeedTotal + rawSpeed[i];
	}
	
	avSpeed = SpeedTotal / 5000;
	
	return (avSpeed);
}