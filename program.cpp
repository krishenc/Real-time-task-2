#include "program.h"

#define Empty 1
#define Fill 2
#define Heat 3
#define Wash 4
#define Rinse 5
#define Spin 6
#define Dry 7
#define Complete 8

#define MotorSpeedHigh 2
#define MotorSpeedLow 1
#define MotorSpeedOff 0






void Program::SetProgram(int ChosenProgram)
{
	currentProgram = ChosenProgram;
	currentCycle = -1;	
}

int Program::GetNextStage()
{
	currentCycle++;
}
