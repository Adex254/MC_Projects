#include <ESP32Servo.h>

Servo myServo;
const int SERVO_PIN = 4;
const int BUZZER_PIN = 2;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  
  delay(5000);
  
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  
  myServo.write(180);
}

void loop() {}
