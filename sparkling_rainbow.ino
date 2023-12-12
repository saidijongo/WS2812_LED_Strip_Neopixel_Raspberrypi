//Green wire is a data wire (GPIO connected)
//White-green and Green wires are ground GND (Choose any one)
//Red-green and Red are +5V (Choose any one)

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
  moveRainbow(FIXED_BRIGHTNESS);
  delay(50);
}

void moveRainbow(uint8_t brightness) {
  static uint16_t hue = 0;

  for (int i = 0; i < strip.numPixels(); i++) {
    uint8_t sat = 255; // Full saturation
    uint8_t val = brightness;

    // Set color based on HSV (Hue, Saturation, Value)
    strip.setPixelColor(i, strip.ColorHSV(hue + i * 65536 / strip.numPixels(), sat, val));
  }

  strip.show();
  hue += 
}
