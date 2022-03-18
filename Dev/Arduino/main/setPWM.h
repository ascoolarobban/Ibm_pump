

void setPWM(char x, int PWM) {
  switch (x) {
    case 'A':
      analogWrite(pump_speed, PWM);
      break;

    case 'B':
      analogWrite(fan_speed, PWM);
      break;

      case 'C':
      analogWrite(drain_valve, PWM);
      break;
  }



}
