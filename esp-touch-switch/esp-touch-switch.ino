// ESP32 Multi-Touch → Multi-LED (no arrays, no for-loops)
#define TOUCH_A   T0     // GPIO4
#define TOUCH_B   T3     // GPIO15
#define TOUCH_C   T4     // GPIO13

#define LED_A     2      // change if your board has a different LED pin
#define LED_B     5
#define LED_C     18

int threshA = 30;        // tweak these per board
int threshB = 30;
int threshC = 30;

bool stateA = false;
bool stateB = false;
bool stateC = false;

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
  Serial.begin(115200);
}

void loop() {
  int a = touchRead(TOUCH_A);
  int b = touchRead(TOUCH_B);
  int c = touchRead(TOUCH_C);

  if (a < threshA) {                  // Touch A
    stateA = !stateA;
    digitalWrite(LED_A, stateA);
    delay(400);                       // simple debounce
  }

  if (b < threshB) {                  // Touch B
    stateB = !stateB;
    digitalWrite(LED_B, stateB);
    delay(400);
  }

  if (c < threshC) {                  // Touch C
    stateC = !stateC;
    digitalWrite(LED_C, stateC);
    delay(400);
  }

  // optional: see raw values
  // Serial.printf("A:%d  B:%d  C:%d\n", a, b, c);
  delay(40);
}
