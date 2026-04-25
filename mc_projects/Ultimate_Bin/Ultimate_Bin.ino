#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
#include <IRremote.h>

// Pins
const int TRIG_PIN = 5; 
const int ECHO_PIN = 18;
const int SERVO_PIN = 4;
const int BUZZER_PIN = 13;
const int TEMP_PIN = 34;
const int IR_PIN = 15;

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo lidServo;
bool manualOverride = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  IrReceiver.begin(IR_PIN);
  
  ESP32PWM::allocateTimer(0);
  lidServo.setPeriodHertz(50);
  lidServo.attach(SERVO_PIN, 500, 2400);
  lidServo.write(0); 

  lcd.init(); lcd.backlight();
  lcd.print("System Online");
}

void loop() {
  // 1. Check Temperature (Safety First)
  int rawT = analogRead(TEMP_PIN);
  float tempC = (rawT * (3300.0 / 4095.0)) / 10.0;

  // 2. Check Remote Control (Manual Override)
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedLibMenuItem == 1) { // Remote Button 1
      manualOverride = true;
      lidServo.write(90);
      tone(BUZZER_PIN, 1500, 100);
    } 
    if (IrReceiver.decodedLibMenuItem == 2) { // Remote Button 2
      manualOverride = false;
      lidServo.write(0);
      tone(BUZZER_PIN, 500, 100);
    }
    IrReceiver.resume();
  }

  // 3. Automatic Logic (Only if not in manual mode)
  if (!manualOverride) {
    digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    long dist = pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;

    lcd.setCursor(0, 0);
    lcd.print("T:"); lcd.print(tempC); lcd.print("C Dist:"); lcd.print(dist);

    if (dist > 0 && dist < 15) { // Hand detected
      lcd.setCursor(0,1); lcd.print("OPENING...     ");
      tone(BUZZER_PIN, 2000, 150);
      lidServo.write(90);
      delay(4000);
      lidServo.write(0);
      tone(BUZZER_PIN, 800, 300);
      lcd.setCursor(0,1); lcd.print("READY          ");
    }
  } else {
    lcd.setCursor(0, 1);
    lcd.print("MANUAL MODE [2]");
  }
  delay(200);
}
