#define AcceptMask 0x20
#define CancelMask 0x10
#define Prog3Mask 0x08
#define Prog2Mask 0x04
#define Prog1Mask 0x02
#define DoorMask 0x01


class Button {

private:
	comm *ARMBoard;
	u32 ButtonMask;

public:
	Button(comm*, u32);
	bool GetButtonState();

};

