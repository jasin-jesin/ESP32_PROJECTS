#include <WiFi.h>
#include <esp_now.h>

#define LED_PIN 2

void onReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
  digitalWrite(LED_PIN, incomingData[0] ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }
  esp_now_register_recv_cb(onReceive);
}

void loop() {
  // Nothing needed here
}
