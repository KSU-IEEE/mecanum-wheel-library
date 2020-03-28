#include <low_level_motor.h>

namespace engine {
class robot_4_wheels {
public:
/*
initializes the fours motors
pinList indexs should follow format:
index 	To Set
0: 		fRight.pinA
1:  	fRight.pinB
2: 		fRight.pwmPin
3: 		fLeft.pinA
4: 		fLeft.pinB
5:		fLeft.pwmPin
6: 		bRight.pinA
7: 		bRight.pinB
8: 		bRight.pwmPin
9: 		bLeft.pinA
10:  	bLeft.pinB
11: 	bLeft.pwmPin
*/
robot_4_wheels(int pinList[12]);

void move_right(uint8_t pwm);
void move_left(uint8_t pwm);
void move_up(uint8_t pwm);
void move_down(uint8_t pwm);

private:
// four motors
motor fRight = motor();
motor fLeft = motor();
motor bRight = motor();
motor bLeft = motor();
};  // class 4_motor_bot
}  // namespace engine