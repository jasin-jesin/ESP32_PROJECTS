#include <ESP32_Skainet.h>

ESP32_Skainet voiceRecognition;

void setup() {
  Serial.begin(115200);
  voiceRecognition.begin();
}

void loop() {
  if (voiceRecognition.available()) {
    String command = voiceRecognition.getCommand();
    Serial.println(command);
    
    if (command == "TURN_ON") {
      // Add code to turn on an LED or any other action
      Serial.println("Turning ON LED");
    }
    else if (command == "TURN_OFF") {
      // Add code to turn off an LED or any other action
      Serial.println("Turning OFF LED");
    }
  }
}
