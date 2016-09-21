#include "FastLED.h"
#define NUM_LEDS 30
#define DELAY 500
CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS); }

void setColor(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = color;
  }
  delay(DELAY);
  FastLED.show();
}

void loop() {
  static uint8_t hue = 0;
  setColor(CHSV(hue++, 255, 255));
  Serial.println(hue);
}
