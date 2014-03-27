#include "PWM.h"

void CPMU_Regs::setPCSR() volatile
{
	PCSR = PWM_Clock;
}

// class constructor initialises private members
// initialises the pwm control information
PWM_Regs::PWM_Regs(){
	setPWM2(0);
	C2_TC = 8;
	C2_ENB = 1;
	C2_DIV = 2;
	C2_SYNC = 0;
	C2_INV = 0;
}

// set the control information for the PWM line connected to the motor
void PWM_Regs::setPWM2(u32 speed) volatile
{
	C2_DC = speed;
}


// class constructor initialises private members
PWMcontrol::PWMcontrol() 
{
	ClockManager = (CPMU_Regs *) (0xFFFFAC00);
	PWMManager = (PWM_Regs *) (0xFFFF1000);
	ClockManager->setPCSR();
}

// sets the speed of the motor based on the input
void PWMcontrol::SetPWM(u32 speed)
{
	if(speed==0) PWMManager->setPWM2(0);
	if(speed==1) PWMManager->setPWM2(3);
	if(speed==2) PWMManager->setPWM2(8);
}