#include <Adafruit_NeoPixel.h>

#define LED_PIN     48   // Onboard NeoPixel pin (check your ESP32-S3 docs)
#define NUM_PIXELS  1    // Usually 1 onboard RGB LED
#define BRIGHTNESS  50   // 0–255

Adafruit_NeoPixel strip(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Start off
}

void loop() {
  strip.setPixelColor(0, strip.Color(255, 0, 0)); // Red
  strip.show();
  delay(1000);

  strip.setPixelColor(0, strip.Color(0, 255, 0)); // Green
  strip.show();
  delay(1000);

  strip.setPixelColor(0, strip.Color(0, 0, 255)); // Blue
  strip.show();
  delay(1000);
}
