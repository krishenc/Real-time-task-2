#include "SoftTimer.h"

// Timer class to pause execution on the target for TimeSecs
// in secs
void SoftTimer::Wait(u32 TimeSecs)
{
	int i;
	for(i=1500000*TimeSecs; i>0; i--);
}