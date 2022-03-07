float lastHumidity;
float lastTemperature;

float humidity;
float temperature;
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

void tempReading() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (lastHumidity != humidity || lastTemperature != temperature) {
    Serial.print(temperature);
    Serial.println("°C ");
    Serial.print(humidity);
    Serial.println(" %H");

    lastHumidity = humidity;
    lastTemperature = temperature;

  }

}
