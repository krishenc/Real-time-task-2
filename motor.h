#define MotorBit 0x10
#define MotorDirBit 0x20
#define MotorSpeedMask 0x40

class Motor
{
	public:
		Motor(comm*);
		void SetDrive(bool);
		void SetDirection(bool);
		void SetSpeed(int);
		u32 GetSpeed();

	private:
		comm *ARMBoard;
		int speed;
		bool direction; //0=reverse | 1=forward
		bool drive;
};