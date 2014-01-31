#define BuzzerBit 0x80

class Buzzer
{
	public:
		Buzzer(comm*);
		void BuzzSMS ();

	private:
		int BuzzerStatus;
		comm *ARMBoard;	
		void On();
		void Off();
};