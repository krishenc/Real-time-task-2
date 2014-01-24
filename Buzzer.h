#define BuzzerBit 0x80

class Buzzer
{
public:
	Buzzer(comm*);
	void Buzz ();

private:
	int BuzzerStatus;
	comm *ARMBoard;	
	void On();
	void Off();

};