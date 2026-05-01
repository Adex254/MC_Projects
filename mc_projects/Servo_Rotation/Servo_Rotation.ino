#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
int servoPin = 13;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Servo Debugger");
  delay(1000);

  // Essential ESP32 Servo setup
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myServo.setPeriodHertz(50);
  myServo.attach(servoPin, 500, 2400);
}

void loop() {
  lcd.clear();
  lcd.print("Pos: 0 deg");
  myServo.write(0);
  delay(2000);

  lcd.clear();
  lcd.print("Pos: 90 deg");
  myServo.write(90);
  delay(2000);

  lcd.clear();
  lcd.print("Pos: 180 deg");
  myServo.write(180);
  delay(2000);
}
