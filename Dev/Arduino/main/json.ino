

void send_json() {
  StaticJsonDocument<256> doc;
  JsonObject root = doc.to<JsonObject>();
  root["city"] = city;
  JsonObject pump = root.createNestedObject("Pump");
  pump["id"] = pump_id;
  pump["temp"] = temp;
  pump["waterflow"] = flow;
  serializeJson(root, Serial);
  lastTemp = temp;
  lastFlow = flow;
  

}
