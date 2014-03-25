class IC_Regs 
{
	private:
		u32 ICR0;
		u32 ICR1;
		u32 ICLR;
		u32 IRQER;
		u32 FIQER;
		u32 IRQSR;
		u32 FIQSR;
		u32 IPR;		
	public;
		void setICR1(u32);
		void setIRQER(u32);
}

class InterruptController
{
	private:
		u32 Interrupt0;
		u32 Interrupt1;
		volatile IC_Regs * Interrupt;
	
	public:
		InterruptController();
		
}


#define PWM_DISABLE 0x00
#define PWM_ENABLE  0x01
#define PWM_TRUE    0x00
#define PWM_INVERT  0x01
#define NOT_SYNCH   0x00

#define DIV_1MIC  45
#define DIV_100HZ 9999


class PWM_Regs{

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
}


#define PWM_Clock 0x80

class CPMU_Regs{

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
	void setPCSR();
}

#define Off 0
#define Low 1
#define High 2

class PWMcontrol{
private:
	volatile CPMU_Regs * ClockManager;
	volatile PWM_Regs * PWMManager;
	
public:
	PWMcontrol();	
	void SetPWM(u32);
}