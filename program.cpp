#include "program.h"

WashCycle::WashCycle()
{
	Status = 0;
	Time = 0;
	Speed = 0;
}

void WashCycle::SetData(int status, int time, int motorControl)
{
	Status = status;
	Time = time;
	motorControl = motorControl;
}




Program::Program()
{
	Programs[0][0] = WashCycle();
	Programs[0][1] = WashCycle();
	Programs[0][2] = WashCycle();
	Programs[1][0] = WashCycle();
	Programs[1][1] = WashCycle();
	Programs[1][2] = WashCycle();
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
