#include <4_motor_bot.h>

namespace engine {
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