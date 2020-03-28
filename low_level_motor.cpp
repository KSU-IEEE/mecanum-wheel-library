#include <low_level_motor.h>

namespace engine {
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

}  // namespace engine