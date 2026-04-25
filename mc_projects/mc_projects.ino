#include <ESP32Servo.h>

Servo myServo;

void setup() {
  myServo.setPeriodHertz(50);
  myServo.attach(4, 500, 2400);
}

void loop() {
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);
}
