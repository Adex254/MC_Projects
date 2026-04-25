#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address is usually 0x27
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
  
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE SCANNER");
  lcd.setCursor(0, 1);
  lcd.print("Online...");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  int distance;

  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the bounce back time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("ADEOYE SCANNING");
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // Buzzer Logic: Beep if object is closer than 20cm
  if (distance > 0 && distance < 20) {
    digitalWrite(buzzerPin, HIGH);
    delay(100); 
    digitalWrite(buzzerPin, LOW);
  }

  delay(300); 
}
