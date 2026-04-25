#include <ESP32Servo.h>

Servo myServo;
int servoPin = 4; // Signal wire (Orange) to GPIO 4

void setup() {
  // Allow the ESP32 to manage the PWM timers correctly
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  myServo.setPeriodHertz(50);           // Standard 50Hz servo frequency
  myServo.attach(servoPin, 500, 2400);  // Min and max pulse width
}

void loop() {
  myServo.write(90);  // Rotate to 90 degrees
  delay(2000);        // Wait 2 seconds
  
  myServo.write(0);   // Rotate back to 0 degrees
  delay(2000);        // Wait 2 seconds
}
