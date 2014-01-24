#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include <iostream>

int main (){

comm ARMBoard;

u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
ARMBoard.UpdateControl ((u32) ControlByte);

//cout << "Main# ="<< &ARMBoard << "\n";
Buzzer Buzzer1(&ARMBoard);


while(true)
{
Buzzer1.Buzz();

}


}