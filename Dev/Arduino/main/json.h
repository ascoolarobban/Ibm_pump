

String transformPumpState() {
  String result = (pump_state == 1) ? "ON" : "OFF";
  return result;
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
  pump["valve"] = valve_state;
  serializeJson(root, Serial);
  Serial.println("\n");
}
