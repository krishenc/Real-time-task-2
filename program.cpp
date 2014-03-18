#include "program.h"

#define MaxPrograms = 10

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


Program::Program()
{
	Programs = new WashCycle*[MaxPrograms];
	
	Programs[0] = new WashCycle[MaxCycles] {
		WashCycle(Fill,	5,	Off),
		WashCycle(Fill,	5,	Off),
		WashCycle(Complete, 0, Off)
	}
	
	Programs[1] = new WashCycle[MaxCycles] {
		WashCycle(Spin, 6, High),
		WashCycle(Rinse, 8, Low),
		WashCycle(Complete, 0, Off)
	}
	
}



void Program::SetProgram(int ChosenProgram)
{
	currentProgram = ChosenProgram;
	currentCycle = -1;	
}

int Program::GetNextStage()
{
	currentCycle++;
}
