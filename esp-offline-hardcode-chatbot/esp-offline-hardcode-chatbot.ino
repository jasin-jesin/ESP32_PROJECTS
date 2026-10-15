// Tiny ESP32 Serial Chatbot
// Open Serial Monitor @ 115200, type messages, get replies.

void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  Serial.println("Hi! I'm ESP-Bot 🤖  Type something:");
}

String replyTo(String s) {
  s.toLowerCase(); s.trim();

  if (s.length() == 0)                 return "Say something!";
  if (s.indexOf("hello") >= 0 ||
      s.indexOf("hi") >= 0)            return "Hello! How can I help?";
  if (s.indexOf("name") >= 0)          return "I'm ESP-Bot. Nice to meet you.";
  if (s.indexOf("time") >= 0)          return String("I don't wear a watch, but millis() = ") + millis();
  if (s.indexOf("joke") >= 0)          return "Why did the LED go to school? To get a little brighter! 😄";
  if (s.indexOf("bye") >= 0)           return "Bye! Have a great day!";
  // default
  return "I don't know that yet. Try 'hello', 'name', 'time', 'joke', or 'bye'.";
}

void loop() {
  if (Serial.available()) {
    String user = Serial.readStringUntil('\n');
    Serial.print("You: ");
    Serial.println(user);
    String bot = replyTo(user);
    Serial.print("ESP-Bot: ");
    Serial.println(bot);
  }
}
