
#include "DHT.h"
#include "json.h"
DHT dht(DHTPIN, DHTTYPE);

void tempReading() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  //REMEMBER TO ADD || WATERFLOW
  if (lastHumidity != humidity || lastTemperature != temperature) {
    /*  Serial.print(temperature);
      Serial.println("°C ");
      Serial.print(humidity);
      Serial.println(" %H");
    */
    lastHumidity = humidity;
    lastTemperature = temperature;
    send_json();
  }

}
