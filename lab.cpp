#include "types.h" //Portable Typedefs
#include "PPI.cpp" //Port Control


// PortC LED mappings
#define D1 0x80
#define D2 0x40
#define D3 0x20
#define D4 0x10

class LEDs
{
	private:
	unsigned char bitMap;
	u8 PortCData;
	
	public:
	LEDs(unsigned char bitMapping)
	{
		bitMap = bitMapping;
		PortCData = 0;
		reset();
	};
	
	void set()
	{
		PortCData = (u32)PPI->PortC;
		PortCData = PortCData | bitMap;
		PPI->PortC = (u32)PortCData;
	}
	
	void set(int seconds)
	{
		set();
		u32 i;
		for(i=1500000*seconds; i>0; i--);
		reset();
	}
	
	void reset()
	{
		PortCData = (u32)PPI->PortC;
		PortCData = PortCData & ~bitMap;
		PPI->PortC = (u32)PortCData;
	}
	
	bool get()
	{
		if (PPI->PortC & bitMap)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

