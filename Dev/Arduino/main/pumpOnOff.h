#define pumpPin 10
#define ledRing 4


bool pump_state = false;

void pumpON() {
  digitalWrite(pumpPin, HIGH);
  digitalWrite(ledRing, HIGH);
  pump_state = true;
  Serial.println("PUMP:ON");
}

void pumpOFF() {
  digitalWrite(pumpPin, LOW);
  digitalWrite(ledRing, LOW);
  pump_state = false;
  Serial.println("PUMP:OFF");

}

void pumpcontroller(char command) {
  if (pump_state == false) {
    pumpON();

  }
  else if (pump_state == true) {
    pumpOFF();
  }
  if (command == 'A') {
    pumpON();

  }
  else if (command == 'B') {
    pumpOFF();
  }


}
