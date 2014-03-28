// Generated program.h file
#define MaxPrograms 5
#define MaxCycles 11

// statuses
#define Empty 1
#define Fill 2
#define Heat 3
#define Wash 4
#define Rinse 5
#define Spin 6
#define Dry 7
#define Complete 8

// motor control 
#define Off 0
#define Low 1
#define High 2

class WashCycle
{ 
	private:
		u32 Status;
		u32 Time;
		u32 motorControl;

	public:
		WashCycle();
		WashCycle(u32, u32, u32);
		u32 GetStatus();
		u32 GetTime();
		u32 GetMotorControl();
};

class Program
{
	private:
		WashCycle Programs[MaxPrograms][MaxCycles];

		u32 currentProgram;
		u32 currentCycle;
		
		
	public:
		Program();

		void SetProgram(u32);
		WashCycle * GetNextCycle();	
		u32 GetCurrentCycleIndex();
};












