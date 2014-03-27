#include "PPI.h"
#include "Motor.h"

// statuses
#define Empty 1
#define Fill 2
#define Heat 3
#define Wash 4
#define Rinse 5
#define Spin 6
#define Dry 7
#define Complete 8

// motor control 
#define Off 0
#define Low 1
#define High 2

// Set motor function using PWM
void Motor::SetDrive(u32 drive)
{
	PWM.SetPWM(drive);
}