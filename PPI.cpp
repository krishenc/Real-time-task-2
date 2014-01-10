#include "types.h" //Portable Typedefs


// bit masks to enable mode setting for the Control port
#define ModeSel 0x80
#define AMode2  0x40
#define AMode1  0x20
#define AInp    0x10
#define CHInp   0x08
#define BMode1  0x04
#define BInp    0x02
#define CLInp   0x01


//PPI Class
class i8255A
{
public:
  u32 PortA;   // only lowest 8 bits used. Offset 0x00
  u32 PortB;   // only lowest 8 bits used. Offset 0x04
  u32 PortC;   // only lowest 8 bits used. Offset 0x08
  u32 Control; // only lowest 8 bits used. Offset 0x0C
};

// define a pointer to the 8255 structure
volatile i8255A *PPI = (i8255A *) 0xFFFF1C00;