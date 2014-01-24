#include "types.h"
#include "PPI.h"
#include "Buzzer.h"
#include "SevenSeg.h"
//#include <iostream>

int main (){

comm ARMBoard;

u8 ControlByte = (ModeSel | AMode0 | AInp | BMode0 | BOut | CHInp | CLInp);
ARMBoard.UpdateControl ((u32) ControlByte);

//cout << "Main# ="<< &ARMBoard << "\n";
Buzzer Buzzer1(&ARMBoard);
SevenSeg Seg(&ARMBoard);


while(true)
{
int i;
for(i=0; i<10 ; i++){

Buzzer1.Buzz();
Seg.UpdateDisplay(i);
}

}


}