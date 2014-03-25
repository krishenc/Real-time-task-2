#include "Interrupt.h"

void IC_Regs::setICR1(u32 enable){
	ICR1 = enable;
}

void IC_Regs::setIRQER(u32 enable){
	IRQER = enable;
}


InterruptController::InterruptController(){
	Interrupt0 = 0;
	Interrupt1 = 0;
	Interrupt = (IC_Regs *) (0xFFFFA800);
	Interrupt->setICR1(0x07);
	Interrupt->setIRQER(0x01C0);
}

void CPMU_Regs::setPCSR(){
	PSCR = PWM_Clock;
}

PWMcontrol::PWMcontrol{
	ClockManager = (CPMU_Regs *) (0xFFFFAC00);
	PWMMangager = (PWM_Regs *) (0xFFFF1000);
	ClockManager->setPCSR();
	PWMManager->C2_TC = 8;
	PWMManager->C2_DC = 0;
	PWMManager->C2_DIV = 2;
	PWMManager->C2_SYNC = 0;
	PWMManager->C2_INV = 0;
}

void PWMManager::setPWM(u32 speed){
	if(speed==0) PWMManager->C2_DC = 0;
	if(speed==1) PWMManager->C2_DC = 4;
	if(speed==2) PWMManager->C2_DC = 8;
		

}