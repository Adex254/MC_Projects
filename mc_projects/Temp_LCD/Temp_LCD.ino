#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set LCD address to 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorPin = 34; // Middle pin of LM35

void setup() {
  analogReadResolution(12); 
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Temp System");
  delay(2000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(sensorPin);
  
  // ESP32 ADC: 3.3V / 4095 units. LM35: 10mV per degree.
  float voltage = rawValue * (3300.0 / 4095.0);
  float tempC = voltage / 10.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C  "); // Spaces prevent ghost numbers

  lcd.setCursor(0, 1);
  if(tempC > 30) lcd.print("Status: Warm ");
  else lcd.print("Status: Normal");

  delay(1000);
}
