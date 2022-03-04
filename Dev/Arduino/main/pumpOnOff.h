#define pumpPin 10

bool pump_state = false;

void pumpcontroller(char command){
  if(pump_state == false){
    digitalWrite(pumpPin, HIGH);
    pump_state = true;
    Serial.println("PUMP:ON");
    
  }
  else if(pump_state == true){
    digitalWrite(pumpPin, LOW);
    pump_state = false;
    Serial.println("PUMP:OFF");
  }
    if(command == 'A'){
    digitalWrite(pumpPin, HIGH);
    pump_state = true;
    Serial.println("PUMP:ON");
    
  }
  else if(command == 'B'){
    digitalWrite(pumpPin, LOW);
    pump_state = false;
    Serial.println("PUMP:OFF");
  }
  
  
}
