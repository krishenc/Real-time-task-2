#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
#include "Motor.h"
#include "Button.h"
#include "SoftTimer.h"
#include "program.h"

class Manager
{	
	public:
		Manager();
		void Start();
		void PauseProgram();
		void ResumeProgram();
		void ResetProgram();
		void AdvanceStage();
	private:
		comm ARMBoard;		// An instance of comm class
		Buzzer Buzzer1;
		SevenSeg Seg;
		Motor Motor1;
		Button Accept;
		Button Cancel;
		Button Prog3;
		Button Prog2;
		Button Prog1;
		Button Door;
		SoftTimer Timer1;
		Program program;
		
		u32 getSelectedProgram();
};