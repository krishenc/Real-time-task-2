#include "types.h" //Portable Typedefs


//PPI Class
class PPInterface
{
public: 
	PPInterface();
	void PortA(u32);
	void PortB(u32);
	void PortC(u32);
	void Control(u32);
};

	
PPInterface::PPInterface (void)
{
	
	PPI->Control = (u32)(ModeSel | AInp);
}

void PPInterface::PortA(u32 PortAData)
{
	PPI->PortA= (u32) PortAData;
}

void PPInterface::PortB(u32 PortBData)
{
	PPI->PortB= (u32) PortBData;
}

void PPInterface::PortC(u32 PortCData)
{
	PPI->PortC= (u32) PortCData;
}

void PPInterface::Control(u32 ControlData)
{
	PPI->Control= (u32) ControlData;
}