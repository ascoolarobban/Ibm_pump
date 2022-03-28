
/*
String transformPumpState() {
  String result = (pump_state == 1) ? "ON" : "OFF";
  return result;
}*/


void send_json() {
  StaticJsonDocument<256> doc;
  JsonObject root = doc.to<JsonObject>();
  //root["Pump"] = "Pump1";
  JsonObject pump = root.createNestedObject("data");
  pump["pumpstate"] = pump_state;
  pump["drain valve state"] = drain_valve_state;
  pump["safety valve state"] = safety_valve_state;
  pump["fan state"] = fan_state;
  pump["fan speed"] = fan_speed;
  pump["pump_speed"] = pump_speed;
  pump["flowSensor_1"] = flowSensor_1;
  pump["flowSensor_2"] = flowSensor_2;
  pump["flowSensor_3"] = flowSensor_3;
  pump["runtime"] = runTimeBuffer;
  pump["Serial number"] = SN;
  serializeJson(root, Serial);
  Serial.println("\n");
}