// Generated program.h file
#define MaxPrograms 4
#define MaxCycles 11


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

#define Off 0
#define Low 1
#define High 2

class WashCycle
{ 
	private:
		int Status;
		int Time;
		int Speed;

	public:
		WashCycle();
		void SetData(int, int, int);
};

class Program
{
	private:
		WashCycle Programs[MaxPrograms][MaxCycles];

		int currentProgram;
		int currentCycle;
		
		
	public:
		Program();

		void SetProgram(int);
		int GetNextStage();	
};












