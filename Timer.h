// Defines

#define Binary       0x00
#define BCD          0x01

#define Mode0        0x00
#define Mode1        0x02
#define Mode2        0x04
#define Mode3        0x06
#define Mode4        0x08

#define CountLatch   0x00
#define LSB          0x10
#define MSB          0x20
#define LSBMSB       0x30

#define SelC0        0x00
#define SelC1        0x40
#define SelC2        0x80
#define Readback     0xC0

// defines for CTC Readback Command

#define SelCnt0      0x02
#define SelCnt1      0x04
#define SelCnt2      0x08
#define NoStat       0x10
#define NoCount      0x20

class CTC_Regs
{
	private: 
		unsigned int Counter0;
		unsigned int Counter1;
		unsigned int Counter2;
		unsigned int ControlWord;
	
	public:
		void SetCounter0(u32);
		void SetCounter1(u32);
		void SetCounter2(u32);
		void SetControlWord(u32); 
		u32 GetCounter0();
		u32 GetCounter1();
		u32 GetCounter2();

}

class Timer
{
	private:
		volatile CTC_Regs *CTC;
	
	public:
		Timer();
		void SetTimer0(u32);
		void SetTimer1(u32);
		void SetTimer2(u32);
		void SetControlWord(u32);
		u32 GetTimer0;
		u32 GetTimer1;
		u32 GetTimer2;
}