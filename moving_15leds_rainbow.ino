#include <Adafruit_NeoPixel.h>

const int STRIP_LENGTH = 150;
const int LED_STRIP_PIN = 11;
const int GROUP_LENGTH = 15;
const int FIXED_BRIGHTNESS = 100;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LENGTH, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  moveRainbowLeftToRight(FIXED_BRIGHTNESS);
  delay(50);
  moveRainbowRightToLeft(FIXED_BRIGHTNESS);
  delay(50);
}

void moveRainbowLeftToRight(uint8_t brightness) {
  static uint16_t hue = 0;

  for (int i = 0; i < strip.numPixels(); i++) {
    uint8_t sat = 255; // Full saturation
    uint8_t val = brightness;

    if (i < GROUP_LENGTH) {
      // Set color for the group to green
      strip.setPixelColor(i, strip.ColorHSV(9600, sat, val)); // 9600 represents green in HSV
    } else {
      // Set color based on HSV for the moving rainbow
      strip.setPixelColor(i, strip.ColorHSV(hue + (i - GROUP_LENGTH) * 65536 / (strip.numPixels() - GROUP_LENGTH), sat, val));
    }
  }

  strip.show();
  hue += 256; // Increase hue for the next frame
}

void moveRainbowRightToLeft(uint8_t brightness) {
  static uint16_t hue = 0;

  for (int i = 0; i < strip.numPixels(); i++) {
    uint8_t sat = 255; // Full saturation
    uint8_t val = brightness;

    if (i >= strip.numPixels() - GROUP_LENGTH) {
      // Set color for the group to green
      strip.setPixelColor(i, strip.ColorHSV(9600, sat, val)); // 9600 represents green in HSV
    } else {
      // Set color based on HSV for the moving rainbow
      strip.setPixelColor(i, strip.ColorHSV(hue + (i + GROUP_LENGTH) * 65536 / (strip.numPixels() - GROUP_LENGTH), sat, val));
    }
  }

  strip.show();
  hue += 256; // Increase hue for the next frame
}
