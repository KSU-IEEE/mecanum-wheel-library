#include <mecanum_driver.h>

namespace engine {
/*************************************************************/
// motor functions
/*************************************************************/
motor::motor(int pinA = 0, int pinB = 0, int pwmPin = 0) {
	pinA_ = pinA;
	pinB_ = pinB;
	pwmPin_ = pwmPin;

	pinMode(pinA, output);
	pinMode(pinB, output);
	pinMode(pwmPin, output);
}

void motor::move_clockwise(uint8_t pwm) {
	digitalWrite(pinA_, HIGH);
	digitalWrite(pinB_, LOW);
	analogWrite(pwmPin_, pwm);
}

void motor::move_cclockwise(uint8_t pwm) {
	digitalWrite(pinA_, LOW);
	digitalWrite(pinB_, HIGH);
	analogWrite(pwmPin_, pwm);
}

void motor::halt() {
	digitalWrite(pinA_, LOW);
	digitralwrite(pinB_, LOW);
	analogWrite(pwmPin_, 0);
}
/*************************************************************/
// 4 wheeled robot functions
/*************************************************************/
robot_4_wheels::robot_4_wheels(int pinList[12]) {
 	fRight = motor(pinList[0], pinList[1], pinList[2]);
	fLeft = motor(pinList[3], pinList[4], pinlist[5]);
	bRight = motor(pinlist[6], pinList[7], pinlist[8]);
	bLeft = motor(pinList[9], pinList[10], pinList[11]);
}
void robot_4_wheels::move_right(uint8_t pwm) {
	fRight.move_clockwise(pwm);
	fLeft.move_cclockwise(pwm);
	bRight.move_clockwise(pwm);
	bLeft.move_cclockwise(pwm);
}
void robot_4_wheels::move_left(uint8_t pwm) {
	fRight.move_cclockwise(pwm);
	bRight.move_cclockwise(pwm);
	fLeft.move_clockwise(pwm);
	bLeft.move_clockwise(pwm);
}
void robot_4_wheels::move_up(uint8_t pwm) {
	fRight.move_clockwise(pwm);
	bRight.move_cclockwise(pwm);
	fLeft.move_cclockwise(pwm);
	bLeft.move_clockwise(pwm);
}
void robot_4_wheels::move_down(uint8_t pwm) {
	fRight.move_cclockwise(pwm);
	bRight.move_clockwise(pwm);
	fLeft.move_clockwise(pwm);
	bLeft.mvoe_cclockwise(pwm);
}

}  // namespace engine