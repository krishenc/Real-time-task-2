//This file is created automatically from the programs.txt

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

WashCycle::WashCycle()
{
	Status = 0;
	Time = 0;
	Speed = 0;
}

void WashCycle::SetData(int status, int time, int speed)
{
	Status = status;
	Time = time;
	Speed = speed;
}
  

// CANNOT DO THIS
// we're calling code in the middle of nowhere
// need to create a class that initialises the program array


// if we're still running into trouble during initialisation
// this may be because we need to create new ProgramData objects
// at each element of ColourWash (for example)
// 		"ProgramData * ColourWash = new ProgramData[10];"
// 		not sure but this line of code may not create 10 
// 		ProgramData objects... so might need to loop through array
// 		creating new objects at each element??
/*
//ColourWash is defined below
ProgramData * ColourWash = new WashCycle[10]; 
ColourWash[0].SetData(Fill,	5,	Off); 
ColourWash[1].SetData(Heat,	2,	Off); 
ColourWash[2].SetData(Wash,	3,	Low); 
ColourWash[3].SetData(Empty,	4,	Off); 
ColourWash[4].SetData(Fill,	4,	Off); 
ColourWash[5].SetData(Rinse,	4,	Low); 
ColourWash[6].SetData(Empty,	3,	Off); 
ColourWash[7].SetData(Spin,	6	High); 
ColourWash[8].SetData(Dry,	5,	Off); 
ColourWash[9].SetData(Complete,	0,	Off); 
ProgramArray[0] = &ColourWash; 

//WhiteWash is defined below
ProgramData * WhiteWash = new WashCycle[11]; 
WhiteWash[0].SetData(Fill,	5,	Off); 
WhiteWash[1].SetData(Heat,	6,	Off); 
WhiteWash[2].SetData(Wash,	4,	Low); 
WhiteWash[3].SetData(Empty,	4,	Off); 
WhiteWash[4].SetData(Fill,	4,	Off); 
WhiteWash[5].SetData(Rinse,	5,	Low); 
WhiteWash[6].SetData(Empty,	3,	Off); 
WhiteWash[7].SetData(Spin,	8,	High); 
WhiteWash[8].SetData(Spin,	4,	Low); 
WhiteWash[9].SetData(Dry,	5,	Off); 
WhiteWash[10].SetData(Complete,	0,	Off); 
ProgramArray[1] = &WhiteWash; 
*/
#define NumberofPrograms 2
