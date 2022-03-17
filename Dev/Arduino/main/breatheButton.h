

int A = 0;
int B = 0;
int C = 0;
int period = 500;
int delay_time = 5;
unsigned long time_now = 0;

void readButtons();
void pumpSerial();

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
      readButtons();
      pumpSerial();
      A++;
      makeHighBreathe(A);
      delay(delay_time);
    }
    for (int i = 0; i < 200; i++) {
      readButtons();
      pumpSerial();
      A--;
      makeHighBreathe(A);
      delay(delay_time);
    }

  }

}

bool idleState();
void ledShow() {
  while (idleState() == true) {
    makeHigh(0,0,0);
    {
      for (int i = 0; i < 200; i++) {
        readButtons();
        pumpSerial();
        A++;
        makeHigh(A, B, C);
        delay(delay_time);
        if (idleState() != true) {
          makeHigh(0,0,0);
          break;
        }
      }
      for (int i = 0; i < 200; i++) {
        readButtons();
        pumpSerial();
        A--;
        makeHigh(A, B, C);
        delay(delay_time);
        if (idleState() != true) {
          makeHigh(0,0,0);
          break;
        }
      }
      for (int i = 0; i < 200; i++) {
        readButtons();
        pumpSerial();
        B++;
        makeHigh(A, B, C);
        delay(delay_time);
        if (idleState() != true) {
          makeHigh(0,0,0);
          break;
        }
      }
      for (int i = 0; i < 200; i++) {
        readButtons();
        pumpSerial();
        B--;
        makeHigh(A, B, C);
        if (idleState() != true) {
          makeHigh(0,0,0);
          break;
        }
        delay(delay_time);
      }
      for (int i = 0; i < 200; i++) {
        readButtons();
        pumpSerial();
        C++;
        makeHigh(A, B, C);

        delay(delay_time);
        if (idleState() != true) {
          makeHigh(0,0,0);
          break;
        }

      }
    }
    for (int i = 0; i < 200; i++) {
      readButtons();
      pumpSerial();
      C--;
      makeHigh(A, B, C);
      delay(delay_time);
      if (idleState() != true) {
        makeHigh(0,0,0);
        break;
      }
    }
    if (idleState() != true) {
      makeHigh(0,0,0);
      break;
    }


    //breathingLed();

  }

}








bool idleState() {
  if (trigger_A == false && trigger_B == false && trigger_C == false && pump_state == false && fan_state == false && valve_state == false) {
    return true;
  }
  else {
    return false;
  }
}
