#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Try 0x27 first, if blank change to 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize I2C (important for ESP32)
  Wire.begin(21, 22);  // SDA = 21, SCL = 22

  lcd.init();          // Initialize LCD
  lcd.backlight();     // Turn on backlight

  lcd.setCursor(0, 0);
  lcd.print("ADEOYE");

  lcd.setCursor(0, 1);
  lcd.print("ESP32 TEST");
}

void loop() {
}
