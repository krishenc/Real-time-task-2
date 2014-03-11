

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

