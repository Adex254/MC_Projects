#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
#include <IRremote.h>

// Pins
const int TEMP_PIN = 34;
const int SERVO_PIN = 4;
const int BUZZER_PIN = 13;
const int IR_PIN = 15;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo lockServo;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
  IrReceiver.begin(IR_PIN);
  
  lockServo.setPeriodHertz(50);
  lockServo.attach(SERVO_PIN, 500, 2400);
  lockServo.write(0); // Locked position
  
  lcd.print("SafeGuard Active");
  delay(2000);
  lcd.clear();
}

void loop() {
  // 1. Temperature Logic
  int rawValue = analogRead(TEMP_PIN);
  float tempC = (rawValue * (3300.0 / 4095.0)) / 10.0;

  if (tempC > 45.0) {
    digitalWrite(BUZZER_PIN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("!! FIRE ALERT !!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print("C      ");
  }

  // 2. IR Logic for Servo Lock
  if (IrReceiver.decode()) {
    // You can replace '0xFF30CF' with your specific remote button code
    lcd.setCursor(0, 1);
    lcd.print("ACCESS GRANTED ");
    lockServo.write(90); // Unlock
    delay(3000);         // Keep open for 3 seconds
    lockServo.write(0);  // Re-lock
    lcd.setCursor(0, 1);
    lcd.print("LOCKED         ");
    IrReceiver.resume();
  }
}
