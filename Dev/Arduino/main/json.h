void send_json() {
  StaticJsonDocument<256> doc;
  JsonObject root = doc.to<JsonObject>();
  //root["Pump"] = "Pump1";
  JsonObject pump = root.createNestedObject("data");
  pump["drainValveState"] = drain_valve_state;
  pump["safetyValveState"] = safety_valve_state;
  pump["fanState"] = fan_state;
  pump["pumpState"] = pump_state;
  pump["fanSpeed"] = fan_speed;
  pump["pumpSpeed"] = pump_speed;
  pump["drainValveLevel"] = valve_level;
  pump["flowSensor1"] = flowSensor_1;
  pump["flowSensor2"] = flowSensor_2;
  pump["flowSensor3"] = flowSensor_3;
  pump["runtime"] = runTimeBuffer;
  pump["serialNumber"] = SN;
  serializeJson(root, Serial);
  Serial.println("\n");
}
