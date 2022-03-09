

String warning(int x) {
  switch (x) {
    case 1:
      return "CHECK VALVE";
      break;
    case 2:
      // code block
      break;
  }
}

void send_warning(String warning) {
  StaticJsonDocument<256> doc;
  JsonObject root = doc.to<JsonObject>();
  JsonObject pump = root.createNestedObject("warning");
  pump["warning"] = warning;
  serializeJson(root, Serial);
  Serial.println("\n");
}
