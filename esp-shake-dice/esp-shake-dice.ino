#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found");
    while (1);
  }
  Serial.println("Shake to roll dice");
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float mag = sqrt(a.acceleration.x*a.acceleration.x +
                   a.acceleration.y*a.acceleration.y +
                   a.acceleration.z*a.acceleration.z) / 9.81;

  if (fabs(mag - 1.0) > 2.5) { // 2.5g threshold
    Serial.print("Dice: ");
    Serial.println(random(1, 7)); // 1 to 6
    delay(800); // simple cooldown
  }
}
