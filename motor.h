#define MotorBit 0x10
#define MotorDirBit 0x20

class Motor
{

public:
	Motor(comm*);
	void SetDrive(bool);
	void SetDirection(bool);
	void SetSpeed(int);

private:
	comm *ARMBoard;
	int speed;
	bool direction; //0=reverse | 1=forward
	bool drive;
	
};