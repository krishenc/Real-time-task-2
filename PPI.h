#include "types.h"

// bit masks to enable mode setting for the Control port
#define ModeSel 0x80
#define AMode2  0x40
#define AMode1  0x20
#define AInp    0x10
#define CHInp   0x08
#define BMode1  0x04
#define BInp    0x02
#define CLInp   0x01 
#define AMode0 	0x00   
#define AOut	0x00 
#define BMode0 	0x00  
#define BOut 	0x00  
#define CHOut 	0x00  
#define CLOut	0x00
#define SwitchBit	0x80 

//------------------------------------------
// i8255A class
// This class is declared by comm at the correct hardware address
// for port control (as specified in the documentation).
class i8255A
{
	private:
		u32 PortA;   // only lowest 8 bits used. Offset 0x00
		u32 PortB;   // only lowest 8 bits used. Offset 0x04
		u32 PortC;   // only lowest 8 bits used. Offset 0x08
		u32 Control; // only lowest 8 bits used. Offset 0x0C
  
	public:
		// sets the output bits on PortB
		void SetPortB (u32) volatile;
		
		// returns the bits on PortC
		u32 GetPortC() volatile;
		
		// set the Control bits
		void SetControl(u32) volatile;
};

//------------------------------------------
// comm class
// This class has reference to a i8255A object declared at the
// specific hardware address for accessing I/O ports at that address.
class comm
{
	private: 
		// These 8 bit numbers are a copy of the data
		// going out on the port addresses in PPI
		u32 PortA;
		u32 PortB;
		u32 PortC;
		u32 Control;
		
		// This is the reference to i8255A ports (address defined in
		// comm constructor)
		volatile i8255A *PPI;
	
	public:
		
		// class constructor initialises private members
		comm();
		
		// the 32 bit argument is stored in local copy and then 
		// written to the port via PPI
		void SetPortB(u32);
		
		// returns the private member PortB
		u32 GetLocalPortB();
		
		// returns the 32bit value on PortC (via PPI)
		u32 GetPortC();
		
		// sets the Control bits (via PPI)
		void UpdateControl(u32);
};





