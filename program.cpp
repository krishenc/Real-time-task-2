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

#define MaxPrograms 2
#define MaxCycles 11

ProgramData::ProgramData()
{
	Status = 0;
	Time = 0;
	Speed = 0;
}

void ProgramData::SetData(int status, int time, int speed)
{
	Status = status;
	Time = time;
	Speed = speed;
}


Program::Program()
{
	ColourWash = new ProgramData[MaxCycles];
	WhiteWash = new ProgramData[MaxCycles];
	
	ColourWash[0].SetData(Fill,		5, MotorSpeedOff);
	ColourWash[1].SetData(Heat,		2, MotorSpeedOff);
	ColourWash[2].SetData(Wash,		3, MotorSpeedLow);
	ColourWash[3].SetData(Empty,	4, MotorSpeedOff);
	ColourWash[4].SetData(Fill,		4, MotorSpeedOff);
	ColourWash[5].SetData(Rinse,	4, MotorSpeedLow);
	ColourWash[6].SetData(Empty,	3, MotorSpeedOff);
	ColourWash[7].SetData(Spin,		6, MotorSpeedHigh);
	ColourWash[8].SetData(Dry,		5, MotorSpeedOff);
	ColourWash[9].SetData(Complete,	0, MotorSpeedOff);
	
	WhiteWash[ 0].SetData(Fill,		5, MotorSpeedOff);
	WhiteWash[ 1].SetData(Heat,		6, MotorSpeedOff);
	WhiteWash[ 2].SetData(Wash,		4, MotorSpeedLow);
	WhiteWash[ 3].SetData(Empty,	4, MotorSpeedOff);
	WhiteWash[ 4].SetData(Fill,		4, MotorSpeedOff);
	WhiteWash[ 5].SetData(Rinse,	5, MotorSpeedLow);
	WhiteWash[ 6].SetData(Empty,	3, MotorSpeedOff);
	WhiteWash[ 7].SetData(Spin,		8, MotorSpeedHigh);
	WhiteWash[ 8].SetData(Spin,		4, MotorSpeedLow);
	WhiteWash[ 9].SetData(Dry,		5, MotorSpeedOff);
	WhiteWash[10].SetData(Complete,	0, MotorSpeedOff);
	


		
	
}