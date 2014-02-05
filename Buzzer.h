// Bitmask for the buzzer
#define BuzzerBit 0x80

// Buzzer class provides interface to the buzzer
class Buzzer
{
	private:
		// Reference used to access hardware ports
		comm *ARMBoard;
		
		// Function for turning the buzzer ON
		void On();
		
		// Function for turning the buzzer OFF
		void Off();
	
	public:
		// Constructor function requires reference to comm class
		// for accessing hardware port
		Buzzer(comm*);
		
		// Test function for buzzer
		void BuzzSMS();
};