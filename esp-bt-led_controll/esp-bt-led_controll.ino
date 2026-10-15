#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define LED_PIN 48 // Change to your board's LED pin

BLECharacteristic *ledChar;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  BLEDevice::init("ESP32S3-LED");
  BLEServer *server = BLEDevice::createServer();
  BLEService *service = server->createService("FFE0");
  ledChar = service->createCharacteristic("FFE1", BLECharacteristic::PROPERTY_WRITE);
  service->start();
  server->getAdvertising()->start();
}

void loop() {
  std::string value = ledChar->getValue();
  if (value == "1") {
    digitalWrite(LED_PIN, HIGH);
  } else if (value == "0") {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100); // small delay to avoid busy loop
}
