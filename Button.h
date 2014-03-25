

// Bitmasks for each of the buttons
#define AcceptMask 0x20
#define CancelMask 0x10
#define Prog3Mask 0x08
#define Prog2Mask 0x04
#define Prog1Mask 0x02
#define DoorMask 0x01

// Motor class provides interface to the buttons
class Button
{
	private:
		// Reference used to access hardware ports
		comm *ARMBoard;
		
		// Button mask set for each individual button
		u32 ButtonMask;

	public:
		// default constructor
		Button();
		
		// Constructor function requires reference to comm class
		// for accessing hardware port
		Button(comm*, u32);
		
		// Function to return the state of the button
		bool GetButtonState();
};

