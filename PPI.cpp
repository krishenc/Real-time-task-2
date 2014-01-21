#include "PPI.h"

comm::UpdatePortA (u32 bitmap, u32 LocalPortA)
{
	PortA = LocalPortA ^ bitmap;
}

comm::UpdatePortB (u32 bitmap, u32 LocalPortB)
{
	PortB = LocalPortB ^ bitmap;
}

comm::UpdatePortC (u32 bitmap, u32 LocalPortC)
{
	PortA = LocalPortC ^ bitmap;
}

comm::UpdateControl (u32 bitmap)
{
	Control = bitmap;
}