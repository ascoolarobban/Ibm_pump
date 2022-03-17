

void debounce() {
  if (trigger_A == true) {

    if ((millis() - buttonAStartMillis) > debounceDelay) {
      pumpControllerButton();//Functio in pumpOnOff.h
    }
    buttonAStartMillis = millis();
    trigger_A = false;
  }
  if (trigger_B == true) {
    if ((millis() - buttonBStartMillis) > debounceDelay) {
      fanControllerButton();
    }
    buttonBStartMillis = millis();
    trigger_B = false;
  }
  if (trigger_C == true) {
    if ((millis() - buttonCStartMillis) > debounceDelay) {
      valveControllerButton();
    }
    buttonCStartMillis = millis();
    trigger_C = false;
  }
}
