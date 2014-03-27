#include "PWM.h"

// Motor class provides interface to the motor
class Motor
{
	private:
		PWMcontrol PWM;
		
	public:
		// Set motor function using PWM
		void SetDrive(u32);
		
};