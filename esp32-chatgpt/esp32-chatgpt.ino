#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoHttpClient.h>

const char* WIFI_SSID = "YOUR_WIFI";
const char* WIFI_PASS = "YOUR_PASS";
const char* OPENAI_KEY = "sk-REPLACE_ME"; // your API key

WiFiClientSecure client;
HttpClient http(client, "api.openai.com", 443);

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(300); Serial.print("."); }
  Serial.println("\nWiFi OK. Type a question:");
  client.setInsecure(); // skip TLS cert check (demo)
}

void loop() {
  if (!Serial.available()) return;
  String q = Serial.readStringUntil('\n');
  q.trim();
  if (q.length() == 0) return;

  String body = "{\"model\":\"gpt-4o-mini\",\"input\":\"" + q + "\"}";

  http.beginRequest();
  http.post("/v1/responses");
  http.sendHeader("Content-Type", "application/json");
  http.sendHeader("Authorization", "Bearer " + String(OPENAI_KEY));
  http.sendHeader("Content-Length", body.length());
  http.beginBody();
  http.print(body);
  http.endRequest();

  int status = http.responseStatusCode();
  String resp = http.responseBody();

  Serial.println("\nStatus: " + String(status));
  Serial.println("Raw Response:\n" + resp);
  Serial.println("\nAsk more:");
}
