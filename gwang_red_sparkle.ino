#include <Adafruit_NeoPixel.h>

const int STRIP_LENGTH = 150;
const int LED_STRIP_PIN = 11;
const int FIXED_BRIGHTNESS = 100;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  changeColor(255, 0, 0);
  delay(50);
}

void changeColor(int red, int green, int blue) {
  int i;
  for (i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, red, green, blue);
  }
  strip.setBrightness(FIXED_BRIGHTNESS);
  strip.show();
}
