

String transformPumpState(){
  if (pump_state == 1){
  return "ON";
  }
  else{
    return "OFF";
  }
  
}


void send_json() {
  StaticJsonDocument<256> doc;
  JsonObject root = doc.to<JsonObject>();
  root["city"] = city;
  JsonObject pump = root.createNestedObject("Pump");
  pump["id"] = pump_id;
  pump["temp"] = lastTemperature;
  pump["hum"] = lastHumidity;
  pump["waterflow"] = flow;
  pump["pumpstatus"] = transformPumpState();
  serializeJson(root, Serial);
  lastTemp = temp;
  lastFlow = flow;
  

}
