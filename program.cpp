// Generated program.cpp file
#include "types.h"
#include "program.h"

// WashCycle class definitions

WashCycle::WashCycle()
{
	Status = 0;
	Time = 0;
	motorControl = 0;
}

WashCycle::WashCycle(u32 status, u32 time, u32 MotorControl)
{
	Status = status;
	Time = time;
	motorControl = MotorControl;
}

u32 WashCycle::GetStatus()
{
	return Status;
}

u32 WashCycle::GetTime()
{
	return Time;
}

u32 WashCycle::GetMotorControl()
{
	return motorControl;
}

// Program class definitions

void Program::SetProgram(u32 ChosenProgram)
{
	currentProgram = ChosenProgram;	// Set ChosenProgram based on user input
	currentCycle = -1;				// Initialise the currentCycle
}

WashCycle* Program::GetNextCycle()
{
	return &Programs[currentProgram][++currentCycle];
}

u32 Program::GetCurrentCycleIndex()
{
	return currentCycle;
}

Program::Program()
{
	Programs[0][0] = WashCycle(Fill,	5,	Off); 
	Programs[0][1] = WashCycle(Heat,	2,	Off); 
	Programs[0][2] = WashCycle(Wash,	3,	Low); 
	Programs[0][3] = WashCycle(Empty,	4,	Off); 
	Programs[0][4] = WashCycle(Fill,	4,	Off); 
	Programs[0][5] = WashCycle(Rinse,	4,	Low); 
	Programs[0][6] = WashCycle(Empty,	3,	Off); 
	Programs[0][7] = WashCycle(Spin,	6,	High); 
	Programs[0][8] = WashCycle(Dry,	5,	Off); 
	Programs[0][9] = WashCycle(Complete,	0,	Off); 
	Programs[1][0] = WashCycle(Fill,	5,	Off); 
	Programs[1][1] = WashCycle(Heat,	6,	Off); 
	Programs[1][2] = WashCycle(Wash,	4,	Low); 
	Programs[1][3] = WashCycle(Empty,	4,	Off); 
	Programs[1][4] = WashCycle(Fill,	4,	Off); 
	Programs[1][5] = WashCycle(Rinse,	5,	Low); 
	Programs[1][6] = WashCycle(Empty,	3,	Off); 
	Programs[1][7] = WashCycle(Spin,	8,	High); 
	Programs[1][8] = WashCycle(Spin,	4,	Low); 
	Programs[1][9] = WashCycle(Dry,	5,	Off); 
	Programs[1][10] = WashCycle(Complete,	0,	Off); 
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
	Programs[3][1] = WashCycle(Heat,	2,	Off); 
	Programs[3][2] = WashCycle(Wash,	3,	Low); 
	Programs[3][3] = WashCycle(Empty,	4,	Off); 
	Programs[3][4] = WashCycle(Fill,	4,	Off); 
	Programs[3][5] = WashCycle(Rinse,	4,	Low); 
	Programs[3][6] = WashCycle(Empty,	3,	Off); 
	Programs[3][7] = WashCycle(Spin,	6,	High); 
	Programs[3][8] = WashCycle(Dry,	5,	Off); 
	Programs[3][9] = WashCycle(Complete,	0,	Off); 
}

