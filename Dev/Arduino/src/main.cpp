#include <Arduino.h>
#include <ArduinoJson.h>

void setup() {
    Serial.begin(9600);



}

void loop() {
    int temp = random(5,32);
    int flow = random(5,200);
    StaticJsonDocument<200> doc;
    doc["temp"] = temp;
    serializeJsonPretty(doc, Serial);

    Serial.print("temp=");
    Serial.println(temp);

    Serial.print("waterflow=");
    Serial.println(flow);
    delay(1000);

}