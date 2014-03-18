

class Program
{
	private:

		WashCycle** Programs;
		int currentProgram;
		int cuurentCycle;
		int MaxCycles;
		
		
	public:
		Program();
		void SetProgram(int);
		int GetNextStage();
		
};

