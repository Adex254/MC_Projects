#include <ESP32Servo.h>

Servo myServo;
int servoPin = 4; 

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
