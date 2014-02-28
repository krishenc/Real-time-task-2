class ProgramData
{
	private: 
		int Status;
		int Time;
		int Speed;
		
	public:
		ProgramData();
		void SetData(int, int, int);
};

class Program
{
	private:

		ProgramData* Cycles;
		int* Programs;
		int currentProgram;
		int cuurentCycle;
		int MaxPrograms;
		int MaxCycles;
		
		
	public:
		Program();
		void SetProgram(int);
		int GetNextStage();
		
};

