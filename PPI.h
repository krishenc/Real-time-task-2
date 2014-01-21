#include "types.h"

struct i8255A
{
  u32 PortA;   // only lowest 8 bits used. Offset 0x00
  u32 PortB;   // only lowest 8 bits used. Offset 0x04
  u32 PortC;   // only lowest 8 bits used. Offset 0x08
  u32 Control; // only lowest 8 bits used. Offset 0x0C
};
// define a pointer to the 8255 structure
//volatile i8255A *PPI = (i8255A *) 0xFFFF1C00;

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
	private: 
	u32 PortA;
	u32 PortB;
	u32 PortC;
	u32 Control;
	
	public:
	int UpdatePortA();
	int UpdatePortB();
	int UpdatePortC();
	int UpdateControl();

};