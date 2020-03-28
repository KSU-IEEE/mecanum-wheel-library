#include <stdint.h>

namespace robot {
class motor {
public:
motor(int pinA, int pinB, int pwmPin);
void move_clockwise(uint8_t pwm);
void move_cclockwise(uint8_t pwm);
void halt();

int get_pinA() {return pinA_;}
int get_pinB() {return pinB_;}
int get_pwmPin() {return pwmPin_;}

void set_pinA(int pin);
void set_pinB(int pin);
void set_pwmPin(int pin);
private:
int pinA_;
int pinB_;
int pwmPin_;
};  // class motor

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
motor fRight;
motor fLeft;
motor bRight;
motor bLeft;
};  // class 4_motor_bot
}  // namespace robot