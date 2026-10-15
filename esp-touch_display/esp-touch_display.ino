#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_NeoPixel.h>

Adafruit_ILI9341 tft(15, 2, 4);                  // CS, DC, RST
XPT2046_Touchscreen touch(5, 27);                // T_CS, T_IRQ
Adafruit_NeoPixel strip(1, 48, NEO_GRB + NEO_KHZ800); // 1 NeoPixel on GPIO48

#define RAW_X_MIN  200
#define RAW_X_MAX  3900
#define RAW_Y_MIN  200
#define RAW_Y_MAX  3900

void setup() {
  SPI.begin(); tft.begin(); touch.begin();
  tft.setRotation(1); tft.fillScreen(ILI9341_BLACK);
  strip.begin(); strip.setBrightness(80); strip.show();

  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
  tft.setCursor(10, 10); tft.print("Tap a color button:");

  // Draw 3 buttons directly with coordinates
  tft.fillRoundRect(20, 100, 90, 60, 10, ILI9341_RED);
  tft.drawRoundRect(20, 100, 90, 60, 10, ILI9341_WHITE);
  tft.setCursor(45, 125); tft.print("RED");

  tft.fillRoundRect(115, 100, 90, 60, 10, ILI9341_GREEN);
  tft.drawRoundRect(115, 100, 90, 60, 10, ILI9341_WHITE);
  tft.setCursor(125, 125); tft.print("GREEN");

  tft.fillRoundRect(210, 100, 90, 60, 10, ILI9341_BLUE);
  tft.drawRoundRect(210, 100, 90, 60, 10, ILI9341_WHITE);
  tft.setCursor(225, 125); tft.print("BLUE");
}

void loop() {
  if (touch.touched()) {
    TS_Point p = touch.getPoint();
    int x = map(p.y, RAW_Y_MIN, RAW_Y_MAX, 0, 320);
    int y = map(p.x, RAW_X_MIN, RAW_X_MAX, 0, 240);

    // RED button
    if (x >= 20 && x <= 110 && y >= 100 && y <= 160) {
      strip.setPixelColor(0, strip.Color(255, 0, 0)); strip.show();
    }
    // GREEN button
    else if (x >= 115 && x <= 205 && y >= 100 && y <= 160) {
      strip.setPixelColor(0, strip.Color(0, 255, 0)); strip.show();
    }
    // BLUE button
    else if (x >= 210 && x <= 300 && y >= 100 && y <= 160) {
      strip.setPixelColor(0, strip.Color(0, 0, 255)); strip.show();
    }
    delay(180); // debounce
  }
}
