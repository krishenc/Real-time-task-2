

// PortC LED mappings
#define D1 0x80
#define D2 0x40
#define D3 0x20
#define D4 0x10


class LEDs
{
	private:
	unsigned char bitMap;
	char PortCData;
	
	public:
	LEDs(unsigned char bitMapping);
	void set();
	void set(int seconds);
	void reset();
	bool get();
};

