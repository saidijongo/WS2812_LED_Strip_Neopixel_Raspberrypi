// For Mr.Kwon
#include <Adafruit_NeoPixel.h>

const int STRIP_LENGTH = 150;
const int LED_STRIP_PIN_1 = 6;
const int LED_STRIP_PIN_2 = 7; 
const int GROUP_SIZE = 10; 
const int FIXED_BRIGHTNESS = 200; // 0-255

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(STRIP_LENGTH, LED_STRIP_PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(STRIP_LENGTH, LED_STRIP_PIN_2, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip1.show();
  strip2.show();
}

void loop() {
  moveRainbow(FIXED_BRIGHTNESS);
  delay(5);
}

void moveRainbow(uint8_t brightness) {
  static uint16_t hue = 0;
  static int direction = 1;
  static int offset = 0;

  for (int i = 0; i < strip1.numPixels(); i++) {
    uint8_t sat = 255; // Full saturation
    uint8_t val = brightness;

    //hue based on the current position, offset, and direction
    int hueIndex = hue + i * 65536 / strip1.numPixels() + offset * direction;
    hueIndex %= 65536; //hue stays within bounds

    //color based on HSV (Hue, Saturation, Value) for the first LED strip
    strip1.setPixelColor(i, strip1.ColorHSV(hueIndex, sat, val));
    strip2.setPixelColor(i, strip2.ColorHSV(hueIndex, sat, val));
  }

  strip1.show();
  strip2.show();

  // Move the offset to create the left-right, right-left motion effect
  offset += direction;

  // Changing direction when reaching the edges of the LED strip
  if (offset >= strip1.numPixels() - GROUP_SIZE || offset <= 0) {
    direction *= -1;
  }

  // Increment hue for the next iteration
  hue += 40;
}
