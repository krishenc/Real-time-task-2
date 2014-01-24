#define SevenSegOFF 0x0F 



class SevenSeg 
{
public:
	SevenSeg(comm*);
	void UpdateDisplay (int);
private:
	comm *ARMBoard;

};