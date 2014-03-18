#include "program.h"

WashCycle::WashCycle()
{
	Status = 0;
	Time = 0;
	motorControl = 0;
}

void WashCycle::SetData(int status, int time, int motorControl)
{
	Status = status;
	Time = time;
	motorControl = motorControl;
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

Program::Program()
{
	Programs[1][0] = WashCycle(Fill,	5,	Off); 
	Programs[1][1] = WashCycle(Heat,	2,	Off); 
	Programs[1][2] = WashCycle(Wash,	3,	Low); 
	Programs[1][3] = WashCycle(Empty,	4,	Off); 
	Programs[1][4] = WashCycle(Fill,	4,	Off); 
	Programs[1][5] = WashCycle(Rinse,	4,	Low); 
	Programs[1][6] = WashCycle(Empty,	3,	Off); 
	Programs[1][7] = WashCycle(Spin,	6	High); 
	Programs[1][8] = WashCycle(Dry,	5,	Off); 
	Programs[1][9] = WashCycle(Complete,	0,	Off); 
	Programs[2][0] = WashCycle(Fill,	5,	Off); 
	Programs[2][1] = WashCycle(Heat,	6,	Off); 
	Programs[2][2] = WashCycle(Wash,	4,	Low); 
	Programs[2][3] = WashCycle(Empty,	4,	Off); 
	Programs[2][4] = WashCycle(Fill,	4,	Off); 
	Programs[2][5] = WashCycle(Rinse,	5,	Low); 
	Programs[2][6] = WashCycle(Empty,	3,	Off); 
	Programs[2][7] = WashCycle(Spin,	8,	High); 
	Programs[2][8] = WashCycle(Spin,	4,	Low); 
	Programs[2][9] = WashCycle(Dry,	5,	Off); 
	Programs[2][10] = WashCycle(Complete,	0,	Off); 
	Programs[3][0] = WashCycle(Fill,	5,	Off); 
	Programs[3][1] = WashCycle(Heat,	6,	Off); 
	Programs[3][2] = WashCycle(Wash,	4,	Low); 
	Programs[3][3] = WashCycle(Empty,	4,	Off); 
	Programs[3][4] = WashCycle(Fill,	4,	Off); 
	Programs[3][5] = WashCycle(Rinse,	5,	Low); 
	Programs[3][6] = WashCycle(Empty,	3,	Off); 
	Programs[3][7] = WashCycle(Spin,	8,	High); 
	Programs[3][8] = WashCycle(Spin,	4,	Low); 
	Programs[3][9] = WashCycle(Dry,	5,	Off); 
	Programs[3][10] = WashCycle(Complete,	0,	Off); 
}

