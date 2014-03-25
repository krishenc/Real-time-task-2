// Bitmasks for the motor information
#define MotorBit 0x10
#define MotorDirBit 0x20
#define MotorSpeedMask 0x40

// Motor class provides interface to the motor
class Motor
{
	private:
		// Reference used to access hardware ports
		comm *ARMBoard;
		bool pwmMode;
		
	public:
		// default constructor
		Motor();
		
		// Constructor function requires reference to comm class
		// for accessing hardware port
		Motor(comm*);
		
		// Function set the motor ON or OFF
		void SetDrive(bool);
		
		// Set motor function using PWM
		void SetDrive(u32);
		
		// Function to set the direction of the Motor
		void SetDirection(bool);
};