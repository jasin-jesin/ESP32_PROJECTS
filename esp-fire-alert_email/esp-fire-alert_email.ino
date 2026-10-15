#include <WiFi.h>
#include <ESP_Mail_Client.h>

#define FLAME_PIN 14 // flame sensor DO pin

SMTPSession smtp;
Session_Config cfg;
SMTP_Message msg;

void setup() {
  pinMode(FLAME_PIN, INPUT_PULLUP);

  WiFi.begin("YOUR_WIFI", "YOUR_PASS");
  while (WiFi.status() != WL_CONNECTED) delay(100);

  cfg.server.host_name = "smtp.gmail.com";
  cfg.server.port = 465;
  cfg.login.email = "your@gmail.com";       // sender email
  cfg.login.password = "YOUR_APP_PASSWORD"; // Gmail App Password

  msg.sender.name = "ESP32";
  msg.sender.email = "your@gmail.com";
  msg.subject = "FIRE ALERT!";
  msg.addRecipient("You", "to_address@example.com");
  msg.text.content = "Your home is on fire!";
}

void loop() {
  if (digitalRead(FLAME_PIN) == LOW) { // LOW = fire
    smtp.connect(&cfg);
    MailClient.sendMail(&smtp, &msg);
    smtp.closeSession();
    delay(30000); // wait 30s before sending again
  }
}
