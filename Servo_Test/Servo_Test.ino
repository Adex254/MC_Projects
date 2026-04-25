#include <ESP32Servo.h>

Servo myServo;
int servoPin = 4; 

void setup() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  
  myServo.setPeriodHertz(50);           
  myServo.attach(servoPin, 500, 2400);  
}

void loop() {
  myServo.write(90);
  delay(3000); 
  myServo.write(0);
  delay(3000); 
}
