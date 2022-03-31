#define pump_pwm_pin 3
#define fan_pwm_pin 10


void setPWM(char x, int PWM) {
  switch (x) {
    case 'A':
      analogWrite(pump_pwm_pin, PWM);
      pump_speed = PWM;
      break;

    case 'B':
      analogWrite(fan_pwm_pin, PWM);
      fan_speed = PWM;
      break;

    case 'C':
      analogWrite(drain_valve_pwm_pin, PWM);
      valve_level = PWM;
      break;
  }
}
