#include <ESP32Servo.h>
Servo s;
void setup() {
  s.attach(4);
}
void loop() {
  s.write(90);
  delay(3000);
  s.write(0);
  delay(3000);
}
