#include "SoftTimer.h"

// SoftTimer class to pause execution on the target for TimeSecs
// in secs
void SoftTimer::Wait(u32 TimeSecs)
{
	u32 i, j;
	for( j=0; j<TimeSecs; j++){
		for(i=1500000; i>0; i--);
	}
}

void SoftTimer::Wait(float TimeSecs)
{
	float i;
	for(i=(int)(1500000*TimeSecs); i>0; i--);
}