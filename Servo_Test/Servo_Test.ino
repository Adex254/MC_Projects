#include <ESP32Servo.h>

Servo myServo;
int servoPin = 4; // Signal wire (Orange) goes here

void setup() {
  // Use ESP32 specific timers to avoid crashes
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  
  myServo.setPeriodHertz(50);           // Standard 50Hz servo
  myServo.attach(servoPin, 500, 2400);  // Attach to Pin 4
}

void loop() {
  myServo.write(90);    // Move to 90 degrees
  delay(3000);         // Wait 3 seconds
  myServo.write(0);     // Move back to 0 degrees
  delay(3000);         // Wait 3 seconds
}
