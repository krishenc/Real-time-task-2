#define BuzzerBit 0x80

class Buzzer
{
public:
	Buzzer(comm*);
	void Buzz ();
	void Buzz2 ();
	void Toggle ();
private:
	int BuzzerStatus;
	comm *ARMBoard;

};