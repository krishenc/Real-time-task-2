#include "PPI.h"
#include "types.h"


int main(){

comm ARMBoard;
u8 ControlByte = (ModeSel | AMode0 | AInp | BMode1 | BOut | CHInp | CLInp);
ARMBoard.UpdateControl((u32) ControlByte);





}