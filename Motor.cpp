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
/*
float Motor::GetSpeed(){

	int i;
	int rawSpeed[5000];
	double SpeedTotal = 0;
	double avSpeed;
	int tempSpeed;
	for(i=0; i<5000; i++)
	{
		rawSpeed[i] = ARMBoard->GetPortC();
		//if((PortC & MotorSpeedMask) == MotorSpeedMask )	rawSpeed[i] = 1;
		//else rawSpeed[i]=0;
	}
	for(i=0; i<5000; i++)
	{
		if((rawSpeed[i] & MotorSpeedMask) == MotorSpeedMask )	SpeedTotal = SpeedTotal + 1;
		//SpeedTotal = SpeedTotal + rawSpeed[i];
	}
	
	avSpeed = SpeedTotal / 50;
	cout << SpeedTotal << " ";
	cout << "Motor Speed= "<< (avSpeed) << "% \n";
	
	return (avSpeed);
}*/