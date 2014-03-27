#include "types.h"

#define PWM_Clock 0x80

#define Off 0
#define Low 1
#define High 2

//------------------------------------------
// PWM_Regs class
// This class is declared by PWMcontrol at the correct hardware address
// for control of enabling PWM
class CPMU_Regs
{
	private:
		u32 unused0;  //Offset 00
		u32 PCSR;     //Offset 04
		u32 U0CCR;    //Offset 08
		u32 U1CCR;    //Offset 0C
		u32 U2CCR;    //Offset 10
		u32 unused1;  //Offset 14
		u32 CT0CCR;   //Offset 18
		u32 CT1CCR;   //Offset 1C
		u32 CT2CCR;   //Offset 20
		u32 unused2;  //Offset 24
		u32 CCCR;     //Offset 28
	
	public:
		void setPCSR() volatile;
};

//------------------------------------------
// PWM_Regs class
// This class is declared by PWMcontrol at the correct hardware address
// for control of enabling the correct PWM line
class PWM_Regs
{
	private:
		u32 C0_TC;    //Only lowest 8 bits used. Offset 0x00
		u32 C0_DC;    //Only lowest 8 bits used. Offset 0x04
		u32 C0_ENB;   //Only lowest 8 bits used. Offset 0x08
		u32 C0_DIV;   //Only lowest 8 bits used. Offset 0x0C
		u32 C0_SYNC;  //Only lowest 8 bits used. Offset 0x10
		u32 C0_INV;   //Only lowest 8 bits used. Offset 0x14
		u32 unused00; //Only lowest 8 bits used. Offset 0x18
		u32 unused01; //Only lowest 8 bits used. Offset 0x1C
		u32 C1_TC;    //Only lowest 8 bits used. Offset 0x20
		u32 C1_DC;    //Only lowest 8 bits used. Offset 0x24
		u32 C1_ENB;   //Only lowest 8 bits used. Offset 0x28
		u32 C1_DIV;   //Only lowest 8 bits used. Offset 0x2C
		u32 C1_SYNC;  //Only lowest 8 bits used. Offset 0x30
		u32 C1_INV;   //Only lowest 8 bits used. Offset 0x34
		u32 unused10; //Only lowest 8 bits used. Offset 0x38
		u32 unused11; //Only lowest 8 bits used. Offset 0x3C
		u32 C2_TC;    //Only lowest 16 bits used. Offset 0x40
		u32 C2_DC;    //Only lowest 16 bits used. Offset 0x44
		u32 C2_ENB;   //Only lowest 8 bits used. Offset 0x48
		u32 C2_DIV;   //Only lowest 8 bits used. Offset 0x4C
		u32 C2_SYNC;  //Only lowest 8 bits used. Offset 0x50
		u32 C2_INV;   //Only lowest 8 bits used. Offset 0x54
		u32 unused20; //Only lowest 8 bits used. Offset 0x58
		u32 unused21; //Only lowest 8 bits used. Offset 0x5C
		u32 CA_TC;    //Only lowest 16 bits used. Offset 0x60
		u32 CA_DC;    //Only lowest 16 bits used. Offset 0x64
		u32 CA_ENB;   //Only lowest 8 bits used. Offset 0x68
		u32 CA_DIV;   //Only lowest 8 bits used. Offset 0x6C
		u32 CA_SYNC;  //Only lowest 8 bits used. Offset 0x70
		u32 CA_INV;   //Only lowest 8 bits used. Offset 0x74
  
	public:
		// class constructor initialises private members
		PWM_Regs();
		void setPWM2(u32) volatile;  
};

// Control class for motor speed
class PWMcontrol
{
	private:
		volatile CPMU_Regs * ClockManager;
		volatile PWM_Regs * PWMManager;
	
	public:
		// class constructor initialises private members
		PWMcontrol();
		// set the control information for the PWM line connected to the motor	
		void SetPWM(u32);
};