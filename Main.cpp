#include "types.h"
#include "PPI.h"
#include "Buzzer.h"

int main (){

comm ARMBoard;

u8 ControlByte = (ModeSel | AMode0 | AInp | BMode1 | BOut | CHInp | CLInp);
ARMBoard.UpdateControl ((u32) ControlByte);

Buzzer Buzzer1;

while(true)
{
Buzzer1.Buzz();
}


}