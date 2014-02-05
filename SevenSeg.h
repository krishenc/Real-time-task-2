// Bitmask for clearing the display
#define SevenSegOFF 0x0F 

// Buzzer class provides interface to the buzzer
class SevenSeg 
{
	private:
		// Reference used to access hardware ports
		comm *ARMBoard;
		
	public:
		// Constructor function requires reference to comm class
		// for accessing hardware port
		SevenSeg(comm*);
		
		// Function to turn off the display
		void ClearDisplay();
		
		// Function for updating the sevenseg display with an integer
		void UpdateDisplay(u32);
};