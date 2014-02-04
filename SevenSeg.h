#define SevenSegOFF 0x0F 

// Buzzer class provides interface to the buzzer
class SevenSeg 
{
	public:
		// Constructor function requires reference to comm class
		// for accessing hardware port
		SevenSeg(comm*);
		
		// Function for updating the sevenseg display with an integer
		void UpdateDisplay (int);
		
	private:
		// Reference used to access hardware ports
		comm *ARMBoard;
};