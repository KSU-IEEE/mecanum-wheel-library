#include <stdint.h>

namespace engine {
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
}  // namespace engine