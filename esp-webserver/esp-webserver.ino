// Simple ESP32 WebServer LED control
#include <WiFi.h>
#include <WebServer.h>

const char* WIFI_SSID     = "YOUR_SSID";
const char* WIFI_PASSWORD = "YOUR_PASSWORD";

// Change this to your LED pin. Many ESP32 dev boards use GPIO 2 for the onboard LED.
const int LED_PIN = 2;

WebServer server(80);

String html() {
  int val = digitalRead(LED_PIN);
  String state = val ? "ON" : "OFF";
  return String(
    "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1'/>"
    "<style>body{font-family:sans-serif;text-align:center;margin-top:40px}"
    "a{display:inline-block;margin:8px;padding:10px 18px;border:1px solid #aaa;border-radius:8px;text-decoration:none}</style>"
    "</head><body>"
    "<h2>ESP32 LED Control</h2>"
    "<p>LED is <b>") + state + "</b></p>"
    "<a href='/on'>Turn ON</a>"
    "<a href='/off'>Turn OFF</a>"
    "<a href='/toggle'>Toggle</a>"
    "</body></html>";
}

void handleRoot()   { server.send(200, "text/html", html()); }
void handleOn()     { digitalWrite(LED_PIN, HIGH); server.sendHeader("Location", "/"); server.send(303); }
void handleOff()    { digitalWrite(LED_PIN, LOW);  server.sendHeader("Location", "/"); server.send(303); }
void handleToggle() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { delay(400); Serial.print("."); }
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.on("/toggle", handleToggle);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
