#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverAddress[] = {0x24, 0x6F, 0x28, 0xAB, 0xCD, 0xEF}; // Change this

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW init failed");
    return;
  }
  esp_now_add_peer(receiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  uint8_t msg = 1; // 1 = ON
  esp_now_send(receiverAddress, &msg, sizeof(msg));
  delay(1000);

  msg = 0; // 0 = OFF
  esp_now_send(receiverAddress, &msg, sizeof(msg));
  delay(1000);
}
