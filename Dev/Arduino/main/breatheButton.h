

int A = 0;
int B = 0;
int C = 0;
int period = 500;
int delay_time = 5;

unsigned long time_now = 0;

void makeHigh(int a, int b, int c ) {
  analogWrite(buttonA_ledRing, a);  //pump led ring
  analogWrite(buttonB_ledRing, b);//fan led ring
  analogWrite(buttonC_ledRing, c); //Valve led ring

}
void makeHighBreathe(int x) {
  analogWrite(buttonA_ledRing, x);  //pump led ring
  analogWrite(buttonB_ledRing, x);//fan led ring
  analogWrite(buttonC_ledRing, x); //Valve led ring

}

void breathingLed() {
  for (int i = 0; i < 3; i++) {
    for (int i = 0; i < 200; i++) {
      A++;
      makeHighBreathe(A);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      A--;
      makeHighBreathe(A);
      delay(delay_time);
    }

  }

}

void ledShow() {
  if (trigger_A == false && trigger_B == false && trigger_C == false) {
    for (int i = 0; i < 200; i++) {
      A++;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      A--;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      B++;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      B--;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      C++;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      C--;
      makeHigh(A, B, C);
      delay(delay_time);
    }
    breathingLed();

  }

}
