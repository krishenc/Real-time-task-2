
#include "Buzzer.h"

Buzzer::Buzzer()
{
	u8 ControlByte = (ModeSel | AMode0 | AInp | BMode1 | BOut | CHInp | CLInp);
  (*PPI).Control = (u32) ControlByte;

}
