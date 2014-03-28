#include "SoftTimer.h"

// SoftTimer class to pause execution on the target for TimeSecs
// in secs
void SoftTimer::Wait(u32 TimeSecs)
{
	u32 i, j;
	for( j=0; j<TimeSecs; j++){
		for(i=3000000; i>0; i--);
	}
}

void SoftTimer::Wait(float TimeSecs)
{
	float i;
	for(i=(int)(3000000*TimeSecs); i>0; i--);
}