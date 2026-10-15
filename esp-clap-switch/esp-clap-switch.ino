#define MIC_PIN 34
#define LED_PIN 2
int THRESH = 2800;
unsigned long lastClap = 0;
bool gotFirst = false;

void setup(){ pinMode(LED_PIN, OUTPUT); }

void loop(){
  int v = analogRead(MIC_PIN);
  if (v > THRESH) {
    unsigned long now = millis();
    if (gotFirst && (now - lastClap) < 500) {     // 2nd clap within 0.5s
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      gotFirst = false;
      delay(400);                                  // debounce
    } else {
      gotFirst = true;
      lastClap = now;
      delay(120);                                  // ignore echo
    }
  }
  delay(5);
}
