#define BuzzerBit 0x80

class Buzzer
{
public:
	Buzzer(comm*);
	void Buzz ();
	void Buzz2 ();
private:
	int BuzzerStatus;
	comm *ARMBoard;

};