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

		ProgramData* ColourWash; 
		ProgramData* WhiteWash;
		int currentProgram;
		int cuurentStatus;
		
		
	public:
		Program();
		void SetProgram(int);
		int GetNextStage();
		
};

