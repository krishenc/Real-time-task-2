#include "PPI.h"
#include "Buzzer.h"
#include <iostream>




Buzzer::Buzzer(comm *Comms){

ARMBoard = Comms; 
//cout << "Comms# ="<< Comms << "\n";
//cout << "Buzzer# ="<< ARMBoard << "\n";
}

void Buzzer::Buzz(){

int i;

ARMBoard->UpdatePortB(BuzzerBit);
for(i=1500000*0.5; i>0; i--);
ARMBoard->UpdatePortB(BuzzerBit);
for(i=1500000*5; i>0; i--);

}
void Buzzer::Buzz2(){

int i;

ARMBoard->UpdatePortB(BuzzerBit);
for(i=1500000*0.25; i>0; i--);
ARMBoard->UpdatePortB(BuzzerBit);
for(i=1500000*2.5; i>0; i--);

}

void Buzzer::Toggle(){

int i;
ARMBoard->UpdatePortB(BuzzerBit);
for(i=1500000*0.5; i>0; i--);

}

