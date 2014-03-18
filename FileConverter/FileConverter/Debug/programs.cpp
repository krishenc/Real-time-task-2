#include "program.h"WashCycle::WashCycle(){	Status = 0;	Time = 0;	motorControl = 0;}void WashCycle::SetData(int status, int time, int motorControl){	Status = status;	Time = time;	motorControl = motorControl;}void Program::SetProgram(int ChosenProgram){	currentProgram = ChosenProgram;	currentCycle = -1;	}int Program::GetNextStage(){	currentCycle++;}{
}

