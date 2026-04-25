#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo ventServo;

const int sensorPin = 34; // LM35 Middle Pin
const int servoPin = 4;   // Servo Signal Pin
const float threshold = 30.0; // Temperature to open vent

void setup() {
  analogReadResolution(12);
  lcd.init();
  lcd.backlight();
  
  ventServo.setPeriodHertz(50);
  ventServo.attach(servoPin, 500, 2400);
  
  lcd.print("Greenhouse Init");
  ventServo.write(0); // Start closed
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(sensorPin);
  float voltage = rawValue * (3300.0 / 4095.0);
  float tempC = voltage / 10.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C  ");

  lcd.setCursor(0, 1);
  if (tempC >= threshold) {
    lcd.print("VENT: OPENING   ");
    ventServo.write(90); // Open window
  } else {
    lcd.print("VENT: CLOSED    ");
    ventServo.write(0);  // Close window
  }

  delay(1000);
}
