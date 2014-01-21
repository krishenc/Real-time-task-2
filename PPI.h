#include "types.h"


// define a pointer to the 8255 structure


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


class comm {

	
	public:
	comm();
	void UpdatePortB(u32);
	u32 GetPortC(u32);
	void UpdateControl(u32);
	
	private: 
	u32 PortA;
	u32 PortB;
	u32 PortC;
	u32 Control;
};

class i8255A
{
private:
  u32 PortA;   // only lowest 8 bits used. Offset 0x00
  u32 PortB;   // only lowest 8 bits used. Offset 0x04
  u32 PortC;   // only lowest 8 bits used. Offset 0x08
  u32 Control; // only lowest 8 bits used. Offset 0x0C
  
public:
	void SetPortB (u32) volatile;
	u32 GetPortC() volatile;
	void SetControl(u32) volatile;
};