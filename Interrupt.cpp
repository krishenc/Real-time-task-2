#include "Interrupt.h"

void IC_Regs::setICR1(u32 enable)volatile
{
	ICR1 = enable;
}

void IC_Regs::setIRQER(u32 enable)volatile
{
	IRQER = enable;
}


InterruptController::InterruptController()
{
	Interrupt0 = 0;
	Interrupt1 = 0;
	Interrupt = (IC_Regs *) (0xFFFFA800);
	Interrupt->setICR1(0x07);
	Interrupt->setIRQER(0x01C0);
}

void CPMU_Regs::setPCSR() volatile
{
	PCSR = PWM_Clock;
}

PWM_Regs::PWM_Regs(){
	setPWM2(0);
}

void PWM_Regs::setPWM2(u32 speed) volatile
{
	C2_TC = 8;
	C2_DC = speed;
	C2_ENB = 1;
	C2_DIV = 2;
	C2_SYNC = 0;
	C2_INV = 0;
	
	
}

PWMcontrol::PWMcontrol() 
{
	ClockManager = (CPMU_Regs *) (0xFFFFAC00);
	PWMManager = (PWM_Regs *) (0xFFFF1000);
	ClockManager->setPCSR();
}

void PWMcontrol::SetPWM(u32 speed)
{
	if(speed==0) PWMManager->setPWM2(0);
	if(speed==1) PWMManager->setPWM2(3);
	if(speed==2) PWMManager->setPWM2(8);
		

}