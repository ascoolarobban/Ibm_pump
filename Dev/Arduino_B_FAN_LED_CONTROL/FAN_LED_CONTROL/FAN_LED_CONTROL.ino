#include <FastLED.h>

#define LED_PIN     2
#define NUM_LEDS    20
// FOR ARDUINO B. FAN LED CONTROL

CRGB leds[NUM_LEDS];
int delayTime = 40;
char buf[25];

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}

void loop() {
  if (Serial.available() > 0) {

    int inByte = Serial.read();
    switch (inByte) {

      case 1:

        leds[1] = CRGB ( 0, 0, 255);
        delay(delayTime);
        FastLED.show();

        leds[5] = CRGB ( 100, 0, 255);
        delay(delayTime);
        FastLED.show();

        leds[19] = CRGB ( 100, 100, 100);
        delay(delayTime);
        FastLED.show();

        break;

      case 2:

        for (int i = 0; i <= 20; i++) {
          leds[i] = CRGB ( 0, 0, 255);
          delay(delayTime);
          FastLED.show();

        }
        for (int i = 0; i <= 20; i++) {
          leds[i] = CRGB ( 100, 100, 255);
          delay(delayTime);
          FastLED.show();

        }

        break;

      case 3:

        for (int i = 0; i <= 20; i++) {
          leds[i] = CRGB ( 255, 0, 0);
          delay(10);
          FastLED.show();

        }
        for (int i = 0; i <= 20; i++) {
          leds[i] = CRGB ( 0, 0, 0);
          delay(20);
          FastLED.show();

        }

        break;
    }

  }

}
