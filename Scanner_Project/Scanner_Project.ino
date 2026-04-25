#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 5;
const int echoPin = 18;
const int buzzerPin = 19;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Standard Ultrasonic Pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE SCANNING");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // --- Dynamic Buzzer Logic ---
  if (distance > 0 && distance < 5) {
    // CRITICAL: Solid Tone
    digitalWrite(buzzerPin, HIGH); 
  } 
  else if (distance >= 5 && distance < 15) {
    // CLOSE: Fast Beeps
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(buzzerPin, LOW);
    delay(50);
  } 
  else if (distance >= 15 && distance < 30) {
    // MEDIUM: Slow Beeps
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  } 
  else {
    // FAR: Quiet
    digitalWrite(buzzerPin, LOW);
  }

  delay(50); // Small delay to keep the system responsive
}
