

void debounce() {
  if (trigger_A == true) {
    
    if ((millis() - buttonAStartMillis) > debounceDelay) {
      pumpcontroller('x');//Functio in pumpOnOff.h
    }
    buttonAStartMillis = millis();
    trigger_A = false;
  }
}
